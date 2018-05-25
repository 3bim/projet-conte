#include <iostream>
#include "Bacterie.h"
#include "BacterieA.h"
#include "BacterieB.h"
#include "Case.h"
#include "Environnement.h"
#include <vector>

using namespace std;

int main(){
    /*Bacterie* bac=new BacterieA();

    Bacterie* bac2=new BacterieB(1.0,2.0,3.0);
 
    map<char,double> phen=bac->phenotype();
    for(map<char,double>::iterator it=phen.begin();it!=phen.end();++it) cout << it->first << " ; " << it->second << endl;
    cout << bac->fitness() << endl;

    phen=bac2->phenotype();
    for(map<char,double>::iterator it=phen.begin();it!=phen.end();++it) cout << it->first << " ; " << it->second << endl;
    cout << bac2->fitness() << endl;

    map<char,double> meta = {{'A',1.},{'B',2.},{'C',3.}};
    bac2->metabolisme(&meta);
    for(map<char,double>::iterator it=meta.begin();it!=meta.end();++it) cout << it->first << " ; " << it->second << endl;

    phen=bac2->phenotype();
    for(map<char,double>::iterator it=phen.begin();it!=phen.end();++it) cout << it->first << " ; " << it->second << endl;
    cout << bac2->fitness() << endl;


    Bacterie* bac3 = bac2->reproduire();
    phen=bac3->phenotype();
    for(map<char,double>::iterator it=phen.begin();it!=phen.end();++it) cout << it->first << " ; " << it->second << endl;
    cout << bac3->fitness() << endl;

    for(int i=0;i<10;++i) {
        bac3 = bac2->reproduire();
        cout << bac3->fitness() << endl;
        delete bac3;
    }

		cout << bac->type() << endl << bac2->type() <<endl ;
		delete bac;
		delete bac2;*/
		//delete bac3;

    Environnement monde = Environnement();

    monde.run(3);

    return 0;
  
    
}

