CXXFLAGS = -Wall 

Projet_Comte:Bacterie.o BacterieA.o BacterieB.o Case.o Environnement.o main.o
	$(CXX) $(CXXFLAGS) Bacterie.o BacterieA.o BacterieB.o Case.o Environnement.o main.o -o Projet_comte -std=c++11
  
TP7.o: TP7.cpp String.h
	$(CXX) $(CXXFLAGS) -o TP7.o -c TP7.cpp
  
String.o:String.cpp String.h
	$(CXX) $(CXXFLAGS) -o String.o -c String.cpp
  
.PHONY:clean
clean:
	-$(RM) TP7 String.o TP7.o
