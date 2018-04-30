#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;



int main(){
double L=100.0;
double rho=10;
double T=40;	
double c=sqrt(T/rho);

int N=300;
double dx=L/N;

double y[N];
double x[N];
double ypast[N];
double yfut[N];
double dt=0.7*dx/c;
double cp=dx/dt;

cout<<"c= "<<c<<endl;
cout<<"cp= "<<cp<<endl;
cout<<"dx= "<<dx<<endl;
cout<<"dt= "<<dt<<endl;
for(int i=0;i<N;i++){
	x[i]=i*dx;
	if(x[i]<=0.8*L){
		y[i]=1.25*x[i]/L;
	}
	else{
		y[i]=5-5*x[i]/L;
	}
}
yfut[0]=0;
yfut[101]=0;
for(int i=1;i<N-1;i++){
	yfut[i]=y[i]+((c*c)/(2*cp*cp))*(y[i+1]+y[i-1]-2*y[i]);
}
ofstream datos("datos.txt");

for(double t=0;t<200;t+=dt){
	for(int i=0;i<N;i++){
		datos<<y[i]<<",";
	}
	datos<<endl;
	for(int i=0;i<N;i++){
		ypast[i]=y[i];
		y[i]=yfut[i];
	}
	for(int i=1;i<N-1;i++){
		yfut[i]=2*y[i]-ypast[i]+((c*c)/(cp*cp))*(y[i+1]+y[i-1]-2*y[i]);
	}
	
	
}

datos.close();





return 0;
}
