#ifndef BACTERIE_A_H_
#define BACTERIE_A_H_

#include "Bacterie.h"

class BacterieA : public Bacterie {
	public:
		BacterieA();
		BacterieA(double a, double b, double c);
		
		virtual ~BacterieA();
		
		double metabolisme(map<char,double> ext);
		
		void set_fitness();
		
		Bacterie* reproduire();
};

#endif
