#include<iostream>
#include<fstream>
using namespace std;
int main(){
	
	float L=5.0;
	float l=2.0;
	float d=1.0;
	float h=5.0/512;
	float V0=100.0;
	float w=1.2;
	int tam=L/h;
	int N=2*tam*tam;
	cout<<tam<<endl;
	
	float potencial[tam][tam];
	cout<<"a"<<endl;
	float potencialpast[tam][tam];
	cout<<"a"<<endl;
	float xy[tam][tam][2];
	cout<<"a"<<endl;
	
	
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			cout<<i<<","<<j<<endl;
			xy[i][j][0]=i*h;
			xy[i][j][1]=(tam-1-j)*h;
			potencial[i][j]=0;
			
		}
	}
	int y0=(L-d)/2;
	int y1=((L-d)/2)+d;
	int f=((L-l)/2)+l;
	cout<<f<<endl;
	for(int i=(L-l)/2;i<f;i++){
		potencial[i][y0]=-V0/2;
		potencial[i][y1]=V0/2;
	}
	
	for(int k=0;k<N;k++){
		
		for(int i=0;i<tam;i++){
			for(int j=0;j<tam;j++){
				potencialpast[i][j]=potencial[i][j];
			}
		}
		
		for(int i=1;i<tam-1;i++){
			for(int j=1;j<tam-1;j++){
				
				double r=0.25*(potencialpast[i+1][j]+potencial[i-1][j]+potencialpast[i][j+1]+potencial[i][j-1])-potencialpast[i][j];
				potencial[i][j]=potencialpast[i][j]+w*r;
			}
		}
		
		for(int i=(L-l)/2;i<f;i++){
			potencial[i][y0]=-V0/2;
			potencial[i][y1]=V0/2;
		}	
		
	}
	cout<<"calculadas"<<endl;
	ofstream pot("potencial.txt");
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			pot<<xy[i][j][0]<<","<<xy[i][j][1]<<","<<potencial[i][j]<<endl;
		}
	}
	cout<<"calculadas"<<endl;
	pot.close();
return 0;
}
