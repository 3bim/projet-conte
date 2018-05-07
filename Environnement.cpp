#include "Environnement.h"
//#include "Case.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

//Constructor

Environnement::Environnement(){
	Ainit_ = 5;
	W_ = 32; 
	H_ = 32; 
	T_ = 700;
	D_ = 0.001;
	P_mut_ = 0;
	grille  = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille[i] = new Case[W_];
	}
	reset();	
	filling();
	nA = W_*H_/2;
	nB = W_*H_/2;
}

Environnement::Environnement(double Ainit,int T,float D, float P_mut){
	Ainit_ = Ainit;
	W_ = 32; 
	H_ = 32; 
	T_ = T;
	D_ = D;
	P_mut_=P_mut;
	grille  = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille[i] = new Case[W_];
	}
	reset();	
	filling();
	nA = W_*H_/2;
	nB = W_*H_/2;
}

//Destructor

Environnement::~Environnement(){
	for(int i=0; i<H_;i++){
		if(grille[i]!=nullptr){
			delete[] grille[i];
		}
	}
	delete[] grille;

//Getters

Case Environnement::get_case(int i, int j){
	return grille[i][j];
}

//Public method

void Environnement::reset(){
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			grille[i][j].reset(Ainit_);
		}
	}
}

void Environnement::filling(){
	int compA=0;
	int compB=0;
	char remaining = ' ';
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			if(compA<W_*H_/2 && compB<W_*H_/2){
				int random = rand() % 2;
				if(random==0){
					grille[i][j].set_bacterie('a');
					compA++;
				}
				else{
					grille[i][j].set_bacterie('b');
					compB++;
				}
				if(compA==W_*H_/2){
					remaining = 'b';
				}
				if(compB==W_*H_/2){
					remaining = 'a';
				}
				
			}
			else{
				grille[i][j].set_bacterie(remaining);
			}
		}
	}
}

void Environnement::diffusion(){
  //Création de la grille à t+1
  Case** grille_t1;
  grille_t1  = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille_t1[i] = new Case[W_];
	}
  //Remplissage de la grille à t+1
  for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
      map <char,double> metab = grille[i][j].metabolites();
      for (int k=-1; k<2; k++){
				for(int l=-1; l<2; l++){
          int x=0;
          int y=0;
          if(i+k>H_-1){
						x=0;
					}
					else if(i+k<0){
						x=H_-1;
					}
					else{
						x=i+k;
					}
					if(j+l>W_-1){
						y=0;
					}
					else if(j+l<0){
						y=W_-1;
					}
					else{
						y=j+l;
					}
					/*for(int m=0; m<3; m++){
					  metab[m] = metab[m] + D_*(grille[v][h].metabolites()[m]);
					}*/
          metab['A']= metab['A'] + D_*(grille[v][h].metabolites()['A']);
          metab['B']= metab['B'] + D_*(grille[v][h].metabolites()['B']);
          metab['C']= metab['C'] + D_*(grille[v][h].metabolites()['C']);
        } 
      }
			/*for(int m=0; m<3; m++){
				metab[m] = metab[m] - 9*D_*(grille[i][j].metabolites()[m]);
			}*/
      metab['A'] = metab['A'] -9*D_*(grille[i][j].metabolites()['A']);
      metab['B'] = metab['B'] -9*D_*(grille[i][j].metabolites()['B']);
      metab['C'] = metab['C'] -9*D_*(grille[i][j].metabolites()['C']);
			grille_t1[i][j].set_metabolites(metab);
    }
  }
  //On change grille
  for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
      grille[i][j].set_metabolites(grille_t1[i][j].metabolites());
    }
  }
  //On supprime grille_t1
  	for(int i=0; i<H_;i++){
		delete[] grille_t1[i];
	}
	delete[] grille_t1;
}
