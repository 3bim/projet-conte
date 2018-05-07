#include "BacterieB.h"

BacterieB::BacterieB() = default;
BacterieB::BacterieB(double a, double b, double c) = default;

BacterieB::~BacterieB() = default;

double metabolisme(double B_ext) {
	phenotype_['B']=phenotype_['B']+B_ext*R_BB-phenotype_['B']*R_BC;
	phenotype_['C']=phenotype_['C']+phenotype_['B']*R_BC;
	set_fitness();
	return B_ext-B_ext*R_BB;
}

void set_fitness() {
	fitness_=phenotype_['C'];
	if (fitness_<W_min) fitness_=0;
}

Bacterie* BacterieB::reproduire() {
	double alea=(double) rand()/RAND_MAX;
	if (alea<=P_mut) Bacterie* nv = new BacterieA(henotype_['A']/2, phenotype_['B']/2, phenotype_['C']/2);
	else Bacterie* nv = new BacterieB(phenotype_['A']/2, phenotype_['B']/2, phenotype_['C']/2);
	
	phenotype_['A']=phenotype_['A']/2;
	phenotype_['B']=phenotype_['B']/2;
	phenotype_['C']=phenotype_['C']/2;
	
	set_fitness();
	
	return nv;
}
