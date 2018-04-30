#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;


static double t0=0;
static double tf=3000;
static double h=0.006;
static int  N=(tf-t0)/h;

double a=1/(2*sqrt(2));
double e=1e-3;

double funcionDeP1(double q1){
	double x=-2*q1;
	double y=pow(4*q1*q1+e*e,1.5);
	return x/y;
}

double funcionDeP2(double q1,double q2){
	double x=q1-q2;
	double y=pow(x*x+0.25*e*e,1.5);
	double z=q1+q2;
	double w=pow(z*z+0.25*e*e,1.5);
	return (x/y)-(z/w);
}




int main(){
double k1,k2,k3,k4;
double l1,l2,l3,l4;
double m1,m2,m3,m4;
double n1,n2,n3,n4;

double *p1;
double *q1;
double *p2;
double *q2;
double *t;

p1=new double[N];
q1=new double[N];
p2=new double[N];
q2=new double[N];
t=new double[N];

p1[0]=0;
q1[0]=a;
p2[0]=0;
q2[0]=-a;
t[0]=0;

for(int i=1;i<N;i++){
	k1=h*p1[i-1];
	l1=h*funcionDeP1(q1[i-1]);
	m1=h*p2[i-1];
	n1=h*funcionDeP2(q1[i-1],q2[i-1]);
	
	
	k2=h*(p1[i-1]+l1/2);
	l2=h*funcionDeP1(q1[i-1]+k1/2);
	m2=h*(p2[i-1]+n1/2);
	n2=h*funcionDeP2(q1[i-1]+k1/2, q2[i-1]+m1/2);

	k3=h*(p1[i-1]+l2/2);
	l3=h*funcionDeP1(q1[i-1]+k2/2);
	m3=h*(p2[i-1]+n2/2);
	n3=h*funcionDeP2(q1[i-1]+k2/2, q2[i-1]+m2/2);

	k4=h*(p1[i-1]+l3);
	l4=h*funcionDeP1(q1[i-1]+k3);
	m4=h*(p2[i-1]+n3);
	n4=h*funcionDeP2(q1[i-1]+k3, q2[i-1]+m3);
	
	q1[i]=(k1+2*k2+2*k3+k4)/6;
	p1[i]=(l1+2*l2+2*l3+l4)/6;
	q2[i]=(m1+2*m2+2*m3+m4)/6;
	p2[i]=(n1+2*n2+2*n3+n4)/6;
	t[i]=t[i-1]+h;


}
ofstream dat("caos.txt");
for(int i=1;i<N;i++){
	if((q1[i]>0 && q1[i-1]<0) || (q1[i]<0 && q1[i-1]>0)){
		dat<<q2[i]<<","<<p2[i]<<endl;
	}
	
	
}
dat.close();




return 0;
}
