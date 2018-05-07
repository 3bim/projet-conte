#ifndef BACTERIE_H_
#define BACTERIE_H_

#include <vector>

using namespace std;

class Bacterie {
	public:
		static const double R_AA=0.1;
		static const double R_AB=0.1;
		static const double R_BB=0.1;
		static const double R_BC=0.1;
		static const double P_mut=0.;
		
		Bacterie();
		Bacterie(double a, double b, double c);
		virtual ~Bacterie();
		
		inline double A() const;
		inline double B() const;
		inline double C() const;
		
		virtual double metabolisme() = 0;
		
		virtual void set_fitness() = 0;
		
		virtual Bacterie* reproduire() = 0;
	protected:
		map<char,double> phenotype_;
		double fitness_;
};

inline double A() const {
	return phenotype_['A'];
}

inline double B() const {
	return phenotype_['B'];
}

inline double C() const {
	return phenotype_['C'];
}	

#endif BACTERIE_H_
