#include <cstdlib>
#include "BacterieB.h"
#include "BacterieA.h"

BacterieB::BacterieB() = default;
BacterieB::BacterieB(double a, double b, double c) : Bacterie::Bacterie(a, b, c) {
	set_fitness();
}

BacterieB::~BacterieB() = default;

void BacterieB::metabolisme(map<char,double>* ext) {
	phenotype_['B']=phenotype_['B']+(*ext)['B']*R_BB-phenotype_['B']*R_BC;
	phenotype_['C']=phenotype_['C']+phenotype_['B']*R_BC;
	set_fitness();
	(*ext)['B']=(*ext)['B']-(*ext)['B']*R_BB;
}

void BacterieB::set_fitness() {
	fitness_=phenotype_['C'];
	if (fitness_<W_min) fitness_=0.;
}

Bacterie* BacterieB::reproduire() {
	double alea=(double) rand()/RAND_MAX;
	Bacterie* nv;
	if (alea<=P_mut) nv = new BacterieA(phenotype_['A']/2, phenotype_['B']/2, phenotype_['C']/2);
	else nv = new BacterieB(phenotype_['A']/2, phenotype_['B']/2, phenotype_['C']/2);

	phenotype_['A']=phenotype_['A']/2;
	phenotype_['B']=phenotype_['B']/2;
	phenotype_['C']=phenotype_['C']/2;

	set_fitness();

	return nv;
}
