#include <iostream>
#include <map>

#include "Case.h"
#include "Bacterie.h"
#include "BacterieA.h"
#include "BacterieB.h"

using namespace std;

//Constructeurs :

Case::Case(){
	metabolites_['A']=0.;
	metabolites_['B']=0.;
	metabolites_['C']=0.;
	bacterie_=nullptr;
}

Case::Case(map<char,double> metabolites, char c){
	if (c=='A'){
		bacterie_=new BacterieA();
	}
	if (c=='B'){
		bacterie_=new BacterieB();
	}
	metabolites_['A']=metabolites['A'];
	metabolites_['B']=metabolites['B'];
	metabolites_['C']=metabolites['C'];
}


//Destructeur :

Case::~Case(){
	if(bacterie_!=nullptr){
		delete bacterie_;
	}
}


//Getters :

map<char,double> Case::metabolites(){
	return metabolites_;
}


//Setters :

void Case::set_bacterie(char c){
	if (c=='A'){
		bacterie_=new BacterieA();
	}
	if (c=='B'){
		bacterie_=new BacterieB();
	}
}

void Case::set_metabolites(map<char,double> metabolites){
	metabolites_['A']=metabolites['A'];
	metabolites_['B']=metabolites['B'];
	metabolites_['C']=metabolites['C'];
}

//Méthodes publiques :

double Case::fitness(){
	return bacterie_->fitness();
}

void Case::metabolisme(){
	//metabolisme_=bacterie_->metabolisme(map<char,double> metabolisme_);
}

void Case::mort(){
	phenotype=bacterie_->phenotype();
	metabolites_['A']=metabolites_['A']+phenotype['A'];
	metabolites_['B']=metabolites_['B']+phenotype['B'];
	metabolites_['C']=metabolites_['C']+phenotype['C'];
	delete bacterie_;
}

void Case::division(Bacterie bacterie){
	bacterie_=bacterie->reproduire();
}





