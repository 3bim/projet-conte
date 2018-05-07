#include <cstdlib>
#include "BacterieA.h"

BacterieA::BacterieA() = default;
BacterieA::BacterieA(double a, double b, double c) = default;

BacterieA::~BacterieA() = default;


double metabolisme(double A_ext) {
	phenotype_['A']=phenotype_['A']+A_ext*R_AA-phenotype['A']*R_AB;
	phenotype_['B']=phenotype_['B']+phenotype['A']*R_AB;
	set_fitness();
	return A_ext-A_ext*R-AA;
}

void set_fitness() {
	fitness_=phenotype_['B'];
	if (fitness_<W_min) fitness_=0;
}


Bacterie* BacterieA::reproduire() {
	double alea=(double) rand()/RAND_MAX;
	if (alea<=P_mut) Bacterie* nv = new BacterieB(phenotype_['A']/2, phenotype_['B']/2, phenotype_['C']/2);
	else Bacterie* nv = new BacterieA(phenotype_['A']/2, phenotype_['B']/2, phenotype_['C']/2);
	
	phenotype_['A']=phenotype_['A']/2;
	phenotype_['B']=phenotype_['B']/2;
	phenotype_['C']=phenotype_['C']/2;
	
	set_fitness();
	
	return nv;
}
