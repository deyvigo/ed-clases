#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void rellenarVector();
void eliminarVector();
int parPositivo();
int imparNegativo();
void mostrarVectorA();
void mostrarVectorB();
void mostrarVectorC();


	int A[5]={0,0,0,0,0};
	int B[5]={0,0,0,0,0};
	
	int C[5]={0,0,0,0,0};

void rellenarVector(){
	

	if( A[0]==0){
		A[0]=parPositivo();	
		
	}else{
		
		for(int i=0;i<5;i++){
			if(A[i]==0){
				for(int j=i;j>=0;j--){
					A[j]=A[j-1];	
				}
							
				
			}
			break;
		}
		A[0]=parPositivo();	
	}
	
}






void eliminarVector(){
	int aleatorio=rand();
	imparNegativo();
	
}


int parPositivo()
{
	srand(time(NULL));
	 int aleatorio=0;
	while(aleatorio<=0 || aleatorio %2 != 0){
		aleatorio= -100 + rand () % 201 ;	
	}
	
	return aleatorio;
}	

int imparNegativo()
{
	srand(time(NULL));
	int aleatorio=0;
	while(aleatorio>=0 || aleatorio %2 == 0 ){
		aleatorio= -100 + rand () % 201 ;
	}
	
	return aleatorio;
	
}

void mostrarVectorA(){
	for(int i=0;i<5;i++){
	 cout<<"\t"<< A[i];
	 	
	}
	cout<<endl;
}

void mostrarVectorB(){
	for(int i=0;i<5;i++){
	 cout<<"\t"<< B[i];
	 	
	}
	cout<<endl;
}

void mostrarVectorC(){
	for(int i=0;i<5;i++){
	 cout<<"\t"<< C[i];
	 	
	}
	cout<<endl;
}



int main(){

	
	int opcion;
	




	
	
	do{
		cout<<"---------------MENU-----------------"<<endl;
		cout<<"INGRESE OPCION"<<endl;
		cin>>opcion;
		
		

		switch(opcion){
			
			case 1:
				cout<<"INGRESO"<<endl;
				
				rellenarVector();
				mostrarVectorA();
				mostrarVectorB();
				break;
				
			
			case 2:
				cout<<"ELIMINAR"<<endl;
				eliminarVector();
				mostrarVectorA();
				mostrarVectorB();
				mostrarVectorC();
				break;
			
			case 3:
				cout<<"MOSTRAR"<<endl;
				mostrarVectorA();
				mostrarVectorB();
				mostrarVectorC();
				break;	
				
			case 4:
				cout<<"SALIR"<<endl;
				break;
				
			default:
					cout<<"VALOR NO ADMITIDO"<<endl;
		}
	}while(opcion !=4);
		
	
	return 0;
}

	
