#include<iostream>
#include<fstream>
using namespace std;
int main(){
	
	float L=5.0;
	float l=2.0;
	float d=1.0;
	float h=5.0/512;
	float V0=200.0;
	float w=1.5;
	int tam=L/h;
	int N=2*tam*tam;
	cout<<N<<endl;
	
	float potencial[tam][tam];
	float potencialpast[tam][tam];
	
	
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			potencial[i][j]=0;
			
		}
	}
	int y0=((L-d)/2)/h;
	int y1=(((L-d)/2)+d)/h;
	int f=(((L-l)/2)+l)/h;
	cout<<f<<endl;
	for(int i=((L-l)/2)/h;i<f;i++){
		potencial[i][y0]=-1*V0/2;
		potencial[i][y1]=V0/2;
	}
	
	for(int k=0;k<1000;k++){
		cout<<k<<endl;
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
		
		for(int i=((L-l)/2)/h;i<f;i++){
			potencial[i][y0]=-1*V0/2;
			potencial[i][y1]=V0/2;
		}
		
	}
	cout<<"calculadas"<<endl;
	ofstream pot("potencial.txt");
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			//pot<<xy[i][j][0]<<","<<xy[i][j][1]<<","<<potencial[i][j]<<endl;
			pot<<potencial[i][j]<<endl;
		}
	}
	cout<<"calculadas"<<endl;
	pot.close();
	
	float Ex[tam][tam];
	float Ey[tam][tam];
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			Ex[i][j]=0;
			Ey[i][j]=0;
		}
	}
	
	for(int i=1;i<tam-1;i++){
		for(int j=1;j<tam-1;j++){
			Ex[i][j]=-1*((potencial[i+1][j]-potencial[i-1][j])/(2*h));
			Ey[i][j]=-1*((potencial[i][j+1]-potencial[i][j-1])/(2*h));
		}
	}
	cout<<"calculando campo"<<endl;
	ofstream cam("campo.txt");
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			cam<<Ex[i][j]<<","<<Ey[i][j]<<endl;
		}
	}
	cam.close();
	
return 0;
}
