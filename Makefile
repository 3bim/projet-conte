CXXFLAGS = -Wall 

TP7:TP7.o String.o
	$(CXX) $(CXXFLAGS) -o TP7 TP7.o String.o
  
TP7.o: TP7.cpp String.h
	$(CXX) $(CXXFLAGS) -o TP7.o -c TP7.cpp
  
String.o:String.cpp String.h
	$(CXX) $(CXXFLAGS) -o String.o -c String.cpp
  
.PHONY:clean
clean:
	-$(RM) TP7 String.o TP7.o
