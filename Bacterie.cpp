#include "Bacterie.h"

Bacterie::Bacterie() : phenotype_(0.,0.,0.), fitness_(0.) {};

Bacterie::Bacterie(double a, double b, double c) : phenotype_(a,b,c) {
	set_fitness();
}

Bacterie::~Bacterie() = default;
}
