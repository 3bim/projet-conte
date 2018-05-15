#ifndef BACTERIE_A_H_
#define BACTERIE_A_H_

#include "Bacterie.h"

class BacterieA : public Bacterie {
	public:
		BacterieA();
		BacterieA(map<char,double> phen);
		
		virtual ~BacterieA();
		
		void metabolisme(map<char,double>* ext);
		
		void set_fitness();
		
		Bacterie* reproduire();
		
		inline char type();
};

inline char BacterieA::type() {return 'A';}
#endif
