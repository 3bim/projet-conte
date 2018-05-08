#ifndef BACTERIE_H_
#define BACTERIE_H_

#include <map>

using namespace std;

class Bacterie {
	public:
		const double R_AA=0.1;
		const double R_AB=0.1;
		const double R_BB=0.1;
		const double R_BC=0.1;
		const double P_mut=0.;
		const double W_min=0.02;

		Bacterie();
		Bacterie(double a, double b, double c);
		virtual ~Bacterie();

/*		inline double A() const;
		inline double B() const;
		inline double C() const; */

		inline map<char,double> phenotype() const;
		inline double fitness() const;

		virtual double metabolisme(map<char,double> ext) = 0;

		virtual void set_fitness() = 0;

		virtual Bacterie* reproduire() = 0;


	protected:
		map<char,double> phenotype_;
		double fitness_;
};

inline map<char,double> Bacterie::phenotype() const {
	return phenotype_;
}

inline double Bacterie::fitness() const {
    return fitness_;
}
/*inline double Bacterie::A() const {
	return phenotype_['A'];
}

inline double Bacterie::B() const {
	return phenotype_['B'];
}

inline double Bacterie::C() const {
	return phenotype_['C'];
}	*/

#endif
