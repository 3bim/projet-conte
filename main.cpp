#include <iostream>
#include "Bacterie.h"
#include "BacterieA.h"
#include "BacterieB.h"
#include "Case.h"
#include "Environnement.h"
#include <vector>

using namespace std;

int main(){

    //Environnement monde = Environnement();

    //monde.run(5000);


    for(double a=1.0;a<52;a=a+10.0){
      for(int t=10;t<311;t=t+50){
        Environnement univers(a,t,0.1,0.02);
        univers.run(5000);
      }
    }

    return 0;
  
    
}

