#include <cstdlib>
#include "BacterieA.h"
#include "BacterieB.h"

BacterieA::BacterieA() = default;
BacterieA::BacterieA(map<char,double> phen) : Bacterie::Bacterie(phen) {
	set_fitness();
}

BacterieA::~BacterieA() = default;

void BacterieA::metabolisme(map<char,double>* ext) {
	phenotype_['A']=phenotype_['A']+(*ext)['A']*R_AA-phenotype_['A']*R_AB;
	phenotype_['B']=phenotype_['B']+phenotype_['A']*R_AB;
	set_fitness();
	(*ext)['A']=(*ext)['A']-(*ext)['A']*R_AA;
}

void BacterieA::set_fitness() {
	fitness_=phenotype_['B'];
	if (fitness_<W_min) fitness_=0.;
}

Bacterie* BacterieA::reproduire() {
	double alea=(double) rand()/RAND_MAX;
	Bacterie* nv;
	
	phenotype_['A']/=2;
	phenotype_['B']/=2;
	phenotype_['C']/=2;
	set_fitness();
	
	if (alea<=P_mut) nv = new BacterieB(phenotype_);
	else nv = new BacterieA(phenotype_);

	return nv;
}
