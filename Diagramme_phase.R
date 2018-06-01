rm(list=ls())
dev.off()

#Lecture de la table
d=read.table("data3.tab")
A=d$V1
B=d$V2

x=c(0,1,11,21,31,41,51)
y=c(0,10,310,610,910,1210,1510)
par(mfrow=c(1,1))
plot(y,x,xlab="T",ylab="a")
polygon(c(y[1],y[1],y[2],y[2]),c(x[1],x[2],x[2],x[1]),col="red")

for (j in 1:(length(x)-1)){
  for (i in 1:(length(y)-1)){
    if ((i==1 | j==1) & i!=2){
      if (B[(j-1)*6+i]==0){
        polygon(c(y[i],y[i],y[i+1],y[i+1]),c(x[j],x[j+1],x[j+1],x[j]),col="red")
      }
      if (A[(j-1)*6+i]!=0 & B[(j-1)*6+i]!=0){
        polygon(c(y[i],y[i],y[i+1],y[i+1]),c(x[j],x[j+1],x[j+1],x[j]),col="green")
      }
      if (A[(j-1)*6+i]==0){
        polygon(c(y[i],y[i],y[i+1],y[i+1]),c(x[j],x[j+1],x[j+1],x[j]),col="black")
      }
    }
    else {
      if (B[(j-1)*6+i-1]==0 & B[(j-1)*6+i]==0){
        polygon(c(y[i],y[i],y[i+1],y[i+1]),c(x[j],x[j+1],x[j+1],x[j]),col="red")
      }
      if (B[(j-1)*6+i-1]!=0 & B[(j-1)*6+i]!=0){
        polygon(c(y[i],y[i],y[i+1],y[i+1]),c(x[j],x[j+1],x[j+1],x[j]),col="green")
      }
      if (A[(j-1)*6+i-1]==0 & A[(j-1)*6+i]==0){
        polygon(c(y[i],y[i],y[i+1],y[i+1]),c(x[j],x[j+1],x[j+1],x[j]),col="black")
      }
      if (B[(j-1)*6+i-1]==0 & B[(j-1)*6+i]!=0){
        polygon(c(y[i],y[i],y[i+1],y[i+1]),c(x[j],x[j+1],x[j+1],x[j]),col="purple")
      }
    }
  }
}
