#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H 

#include "Case.h"
#include <vector>

class Environnement {

public :

//Constructors 

Environnement();
Environnement(double Ainit,int T,float D,float P_mut,float P_death);

//Destructors

~Environnement();

//Getters

void montre_moi();

//Public methods

void reset();
void filling();
void diffusion();
vector<vector<int>> death();
void division(vector<vector<int>>);
void metabolism();
void run(int t);

//Attributes
protected :

double Ainit_;
int W_;
int H_;
int T_ ;
float D_;
float P_mut_;
float P_death_;
Case** grille;
};

#endif 
