#include "Environnement.h"
//#include "Case.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
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
	cA = W_*H_/2;
	cB = W_*H_/2;
}

Environnement::Environnement(float Ainit,int T,float D, float P_mut){
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
	cA = W_*H_/2;
	cB = W_*H_/2;
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
	int cptA=0;
	int cptB=0;
	char remaining = ' ';
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			if(cptA<W_*H_/2 && cptB<W_*H_/2){
				int random = rand() % 2;
				if(random==0){
					grille[i][j].set_cell('a');
					cptA++;
				}
				else{
					grille[i][j].set_cell('b');
					cptB++;
				}
				if(cptA==W_*H_/2){
					remaining = 'b';
				}
				if(cptB==W_*H_/2){
					remaining = 'a';
				}
				
			}
			else{
				grille[i][j].set_cell(remaining);
			}
		}
	}
}
