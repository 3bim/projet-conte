#include "Environnement.h"
#include "Case.h"
#include "Bacterie.h"
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

//Constructor

Environnement::Environnement(){
	Ainit_ = 5;
	W_ = 4; 
	H_ = 4; 
	T_ = 700;
	D_ = 0.1;
	P_mut_ = 0;
  P_death_ = 0.02;
	grille  = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille[i] = new Case[W_];
	}
	reset();	
	filling();
}

Environnement::Environnement(double Ainit,int T,float D, float P_mut, float P_death){
	Ainit_ = Ainit;
	W_ = 32; 
	H_ = 32; 
	T_ = T;
	D_ = D;
	P_mut_=P_mut;
  P_death_ =P_death;
	grille = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille[i] = new Case[W_];
	}
	reset();	
	filling();
}

//Destructor

Environnement::~Environnement(){
	for(int i=0; i<H_;i++){
		if(grille[i]!=nullptr){
			delete[] grille[i];
		}
	}
	delete[] grille;
}

//Getters

void Environnement::montre_moi(){
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
      cout << "La case [" << i << "][" << j << "] contient une bactérie de type " << grille[i][j].bacterie_->type() << "\n" << grille[i][j].metabolites()['A'] << " mol du métabolites A." << "\n" << grille[i][j].metabolites()['B'] << " du métabolites B." << "\n"<< grille[i][j].metabolites()['C'] << " du métabolites C." << endl;
		}
	}
}

//Public method

void Environnement::reset(){
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			grille[i][j].initialiser(Ainit_);
		}
	}
}

void Environnement::filling(){
  float compA=(H_*W_)/2;
	float compB=(H_*W_)/2;
	char remaining = ' ';
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			if(compA>0 && compB>0){
				float random = float (rand()) / float (RAND_MAX);
				if(random<=compA/(compA+compB)){
					grille[i][j].set_bacterie('A');
					compA--;
				}
				else{
					grille[i][j].set_bacterie('B');
					compB--;
				}
				if(compA==0){
					remaining = 'B';
				}
				if(compB==0){
					remaining = 'A';
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
          metab['A']= metab['A'] + D_*(grille[x][y].metabolites()['A']);
          metab['B']= metab['B'] + D_*(grille[x][y].metabolites()['B']);
          metab['C']= metab['C'] + D_*(grille[x][y].metabolites()['C']);
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

vector<vector<int>> Environnement::death(){
  vector<int> vec;
  vector<vector<int>> liste;
  for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
		  float random = float (rand()) / float (RAND_MAX);
		  if(random<=P_death_){
        grille[i][j].mort();
        vec[1]=i;
        vec[2]=j;
        liste.push_back(vec);
      }
    }
  }
  return liste;
}

void Environnement::division(vector<vector<int>> vec){
  int a;
  int b;
  random_shuffle(vec.begin(),vec.end());
  for (int i=0;i<vec.size();i++){
    a = vec[i][1];
    b = vec[i][2];
    double fitness_max=0;
    int x_max=0;
    int y_max=0;
    for (int k=-1; k<2; k++){
		  for(int l=-1; l<2; l++){
				if( k!=0 && l!=0 ) {
          int x=0;
          int y=0;
          if(a+k>H_-1){
				    x=0;
					}
					else if(a+k<0){
  			    x=H_-1;
			    }
			    else{
				    x=a+k;
  		    }
			    if(b+l>W_-1){
				    y=0;
			    }
			    else if(b+l<0){
				    y=W_-1;
			    }
			    else{
				    y=b+l;
			    }
					if(grille[x][y].fitness()>fitness_max){
					  fitness_max=grille[x][y].fitness();
						x_max=x;
						y_max=y; 
          }         
        }
      }
    }
    grille[a][b].division(grille[x_max][y_max].bacterie_);
  }
}

void Environnement::metabolism(){
  for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
      grille[i][j].metabolisme();
    }  
  }
}

void Environnement::run(int t){
  vector<vector<int>> vec;
	for (int i=0; i<t; i++){
	  if(i%(T_) == 0){
			reset();
		}
		diffusion();
		vec=death();
		division(vec);
		metabolism();
  }
}
