#ifndef BACTERIE_B_H_
#define BACTERIE_B_H_

#include "Bacterie.h"

class BacterieB : public Bacterie {
	public:
		BacterieB();
		BacterieB(double a, double b, double c);
		
		virtual ~BacterieB();
		
		double metabolisme(map<char,double> ext);
		
		void set_fitness();
		
		Bacterie* reproduire();
};

#endif
