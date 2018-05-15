#include "Bacterie.h"

Bacterie::Bacterie() : phenotype_ {{'A',0.},{'B',0.},{'C',0.}}, fitness_(0.) {}
Bacterie::Bacterie(map<char,double> phen) : phenotype_(phen) {}

Bacterie::~Bacterie() = default;
