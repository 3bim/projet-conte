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

Case get_case(int i, int j);

//Public methods

void reset();
void filling();
void diffusion();
vector<vector<int>> death();
void competition(vector<vector<int>>);
void metabolism();
//int run(int t);

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
int nA;
int nB;
};

#endif 
