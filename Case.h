#ifndef CASE_H
#define CASE_H

#include <iostream>
#include <map>
#include "Bacterie.h"
#include "BacterieA.h"
#include "BacterieB.h"

class Case {
	
	public :
	
	//Constructeurs :
	Case();
	Case(map<char,double> metabolites, char c);
	
	//Destructeur :
	~Case();
	
	//Getters :
	map<char,double> metabolites();
	
	//Setters :
	void set_bacterie(char c);
	void set_metabolites(map<char,double> metabolites);
	
	//Méthodes publiques :
	double fitness();
	void mort();
	void metabolisme();
	void division();
	void initialiser(double Init);
	
	//Attribut :
	Bacterie * bacterie_;
	 
	 protected :
	 
	 //Attribut :
	 map<char,double> metabolites_;
	 
};

#endif
