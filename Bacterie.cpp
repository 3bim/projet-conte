#include "Bacterie.h"

Bacterie::Bacterie() : phenotype_ {{'A',0.},{'B',0.},{'C',0.}}, fitness_(0.) {};
Bacterie::Bacterie(double a, double b, double c) : phenotype_ {{'A',a},{'B',b},{'C',c}} {
	//set_fitness();
}

Bacterie::~Bacterie() = default;
