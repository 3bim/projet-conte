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
	else if (c=='B'){
		bacterie_=new BacterieB();
	}
	metabolites_['A']=metabolites['A'];
	metabolites_['B']=metabolites['B'];
	metabolites_['C']=metabolites['C'];
}


//Destructeur :
Case::~Case(){
	if(bacterie_){
		delete bacterie_;
	}
}


//Getters : une seule ligne donc dans Case.h inline

//map<char,double> Case::metabolites(){
	//return metabolites_;
//}


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

//Renvoie la fitness associée à la bactérie présente dans la case.
double Case::fitness(){
	if (bacterie_==nullptr){
		return -1;
	}
	else {
		return bacterie_->fitness();
	}
}

//Associe la bonne valeur de métabolisme à la bactérie de la case (quand elle métabolise)
void Case::metabolisme(){
	bacterie_->metabolisme(&(metabolites_));
}

//Rajoute les valeurs de phénotype à métabolismes quand la bactérie meurt 
//Détruit la bactérie
void Case::mort(){
	map<char,double> phenotype=bacterie_->phenotype();
	metabolites_['A']=metabolites_['A']+phenotype['A'];
	metabolites_['B']=metabolites_['B']+phenotype['B'];
	metabolites_['C']=metabolites_['C']+phenotype['C'];
	if (bacterie_){
		delete bacterie_;
		bacterie_=nullptr;
	}
}

//(que retourne bacterie->reproduire() ????)
void Case::division(Bacterie * bacterie){
  bacterie_=bacterie->reproduire();
}
	
//Réinitialise les métabolites de la case tous les T pas de temps
void Case::initialiser(double Init){
	metabolites_['A']=Init;
	metabolites_['B']=0.;
	metabolites_['C']=0.;
}




