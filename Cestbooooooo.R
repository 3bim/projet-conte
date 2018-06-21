rm(list=ls())

#Lecture de la table
d=read.table("data.tab")
d2=read.table("data2.tab")

#Création du vecteur x
x=0:100
x=x*50

#Premier test
dtest=d[1:101,]
par(mfrow=c(1,1))
plot(x,dtest$V1,ylim=c(0,1000),xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,dtest$V2,col="green")

#Création des test pour différentes valeurs de a et T
#Première boucle
d000010=d[102:202,]
d000310=d[203:303,]
d000610=d[304:404,]
d000910=d[405:505,]
d001210=d[506:606,]
d001510=d[607:707,]
d001810=d2[102:202,]
d002110=d2[203:303,]
#Deuxième boucle
d100010=d[708:808,]
d100310=d[809:909,]
d100610=d[910:1010,]
d100910=d[1011:1111,]
d101210=d[1112:1212,]
d101510=d[1213:1313,]
d101810=d2[304:404,]
d102110=d2[405:505,]
#Troisième boucle
d200010=d[1314:1414,]
d200310=d[1415:1515,]
d200610=d[1516:1616,]
d200910=d[1617:1717,]
d201210=d[1718:1818,]
d201510=d[1819:1919,]
d201810=d2[506:606,]
d202110=d2[607:707,]
#Quatrième boucle
d300010=d[1920:2020,]
d300310=d[2021:2121,]
d300610=d[2122:2222,]
d300910=d[2223:2323,]
d301210=d[2324:2424,]
d301510=d[2425:2525,]
d301810=d2[708:808,]
d302110=d2[809:909,]
#Cinquième boucle
d400010=d[2526:2626,]
d400310=d[2627:2727,]
d400610=d[2728:2828,]
d400910=d[2829:2929,]
d401210=d[2930:3030,]
d401510=d[3031:3131,]
d401810=d2[910:1010,]
d402110=d2[1011:1111,]
#Sixième boucle
d500010=d[3132:3232,]
d500310=d[3233:3333,]
d500610=d[3334:3434,]
d500910=d[3435:3535,]
d501210=d[3536:3636,]
d501510=d[3637:3737,]
d501810=d2[1112:1212,]
d502110=d2[1213:1313,]

#Visualisation de ces tests
par(mfrow=c(4,2))
#Première boucle
plot(x,d000010$V1,ylim=c(0,1000),main="a = 0 T = 10",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d000010$V2,col="green")
plot(x,d000310$V1,ylim=c(0,1000),main="a = 0 T = 310",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d000310$V2,col="green")
plot(x,d000610$V1,ylim=c(0,1000),main="a = 0 T = 610",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d000610$V2,col="green")
plot(x,d000910$V1,ylim=c(0,1000),main="a = 0 T = 910",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d000910$V2,col="green")
plot(x,d001210$V1,ylim=c(0,1000),main="a = 0 T = 1210",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d001210$V2,col="green")
plot(x,d001510$V1,ylim=c(0,1000),main="a = 0 T = 1510",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d001510$V2,col="green")
plot(x,d001810$V1,ylim=c(0,1000),main="a = 0 T = 1810",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d001810$V2,col="green")
plot(x,d002110$V1,ylim=c(0,1000),main="a = 0 T = 2110",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d002110$V2,col="green")
#Deuxième boucle
plot(x,d100010$V1,ylim=c(0,1000),main="a = 10 T = 10",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d100010$V2,col="green")
plot(x,d100310$V1,ylim=c(0,1000),main="a = 10 T = 310",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d100310$V2,col="green")
plot(x,d100610$V1,ylim=c(0,1000),main="a = 10 T = 610",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d100610$V2,col="green")
plot(x,d100910$V1,ylim=c(0,1000),main="a = 10 T = 910",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d100910$V2,col="green")
plot(x,d101210$V1,ylim=c(0,1000),main="a = 10 T = 1210",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d101210$V2,col="green")
plot(x,d101510$V1,ylim=c(0,1000),main="a = 10 T = 1510",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d101510$V2,col="green")
plot(x,d101810$V1,ylim=c(0,1000),main="a = 10 T = 1810",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d101810$V2,col="green")
plot(x,d102110$V1,ylim=c(0,1000),main="a = 10 T = 2110",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d102110$V2,col="green")
#Troisème boucle
plot(x,d200010$V1,ylim=c(0,1000),main="a = 20 T = 10",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d200010$V2,col="green")
plot(x,d200310$V1,ylim=c(0,1000),main="a = 20 T = 310",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d200310$V2,col="green")
plot(x,d200610$V1,ylim=c(0,1000),main="a = 20 T = 610",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d200610$V2,col="green")
plot(x,d200910$V1,ylim=c(0,1000),main="a = 20 T = 910",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d200910$V2,col="green")
plot(x,d201210$V1,ylim=c(0,1000),main="a = 20 T = 1210",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d201210$V2,col="green")
plot(x,d201510$V1,ylim=c(0,1000),main="a = 20 T = 1510",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d201510$V2,col="green")
plot(x,d201810$V1,ylim=c(0,1000),main="a = 20 T = 1810",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d201810$V2,col="green")
plot(x,d202110$V1,ylim=c(0,1000),main="a = 20 T = 2110",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d202110$V2,col="green")
#Quatrième boucle
plot(x,d300010$V1,ylim=c(0,1000),main="a = 30 T = 10",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d300010$V2,col="green")
plot(x,d300310$V1,ylim=c(0,1000),main="a = 30 T = 310",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d300310$V2,col="green")
plot(x,d300610$V1,ylim=c(0,1000),main="a = 30 T = 610",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d300610$V2,col="green")
plot(x,d300910$V1,ylim=c(0,1000),main="a = 30 T = 910",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d300910$V2,col="green")
plot(x,d301210$V1,ylim=c(0,1000),main="a = 30 T = 1210",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d301210$V2,col="green")
plot(x,d301510$V1,ylim=c(0,1000),main="a = 30 T = 1510",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d301510$V2,col="green")
plot(x,d301810$V1,ylim=c(0,1000),main="a = 30 T = 1810",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d301810$V2,col="green")
plot(x,d302110$V1,ylim=c(0,1000),main="a = 30 T = 2110",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d302110$V2,col="green")
#Cinquième boucle
plot(x,d400010$V1,ylim=c(0,1000),main="a = 40 T = 10",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d400010$V2,col="green")
plot(x,d400310$V1,ylim=c(0,1000),main="a = 40 T = 310",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d400310$V2,col="green")
plot(x,d400610$V1,ylim=c(0,1000),main="a = 40 T = 610",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d400610$V2,col="green")
plot(x,d400910$V1,ylim=c(0,1000),main="a = 40 T = 910",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d400910$V2,col="green")
plot(x,d401210$V1,ylim=c(0,1000),main="a = 40 T = 1210",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d401210$V2,col="green")
plot(x,d401510$V1,ylim=c(0,1000),main="a = 40 T = 1510",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d401510$V2,col="green")
plot(x,d401810$V1,ylim=c(0,1000),main="a = 40 T = 1810",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d401810$V2,col="green")
plot(x,d402110$V1,ylim=c(0,1000),main="a = 40 T = 2110",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d402110$V2,col="green")
#Sixième boucle
plot(x,d500010$V1,ylim=c(0,1000),main="a = 50 T = 10",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d500010$V2,col="green")
plot(x,d500310$V1,ylim=c(0,1000),main="a = 50 T = 310",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d500310$V2,col="green")
plot(x,d500610$V1,ylim=c(0,1000),main="a = 50 T = 610",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d500610$V2,col="green")
plot(x,d500910$V1,ylim=c(0,1000),main="a = 50 T = 910",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d500910$V2,col="green")
plot(x,d501210$V1,ylim=c(0,1000),main="a = 50 T = 1210",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d501210$V2,col="green")
plot(x,d501510$V1,ylim=c(0,1000),main="a = 50 T = 1510",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d501510$V2,col="green")
plot(x,d501810$V1,ylim=c(0,1000),main="a = 50 T = 1810",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d501810$V2,col="green")
plot(x,d502110$V1,ylim=c(0,1000),main="a = 50 T = 2110",xlab="temps",ylab="Nombre de bactéries",type="l",col="red")
lines(x,d502110$V2,col="green")

#Analyse de ces tests
