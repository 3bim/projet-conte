#ifndef BACTERIE_B_H_
#define BACTERIE_B_H_

#include "Bacterie.h"

class BacterieB : public Bacterie {
	public:
		BacterieB();
		BacterieB(double a, double b, double c);
		
		virtual ~BacterieB();
		
		void metabolisme(map<char,double>* ext);
		
		void set_fitness();
		
		Bacterie* reproduire();
		
		inline char type();
};

inline char BacterieB::type() {return 'B';}

#endif
