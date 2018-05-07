#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H 

//#include "Case.h"

class Environnement {

public :

//Constructors 

Environnement();
Environnement(double Ainit,int T,float D,float P_mut);

//Destructors

~Environnement();

//Getters

Case get_case(int i, int j);

//Public methods

void reset();
void filling();
void diffusion();
void death();
void competition();
void metabolism();
int run(int t);

//Attributes
protected :

double Ainit_;
int W_;
int H_;
int T_ ;
float D_;
float P_mut_;
Case** grille;
int nA;
int nB;
};

#endif 
