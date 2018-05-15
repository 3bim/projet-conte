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
		Bacterie(map<char,double> phen);
		
		virtual ~Bacterie();

		inline map<char,double> phenotype() const;
		inline double fitness() const;

		virtual void metabolisme(map<char,double>* ext) = 0;

		virtual void set_fitness() = 0;

		virtual Bacterie* reproduire() = 0;

		virtual char type() = 0;
		
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

#endif
