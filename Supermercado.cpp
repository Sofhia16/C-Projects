/*Sofhia Alejandra Prasca Teheran  0222220014
Descuento segun un numero que se escoja al azar si el numero es <74 descuento del 15 del total
>=64 20 de total
*/

#include<iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;
int main () {
	
	int numazar, compra, por, descuento;
	cout<<"Cuanto es el valor total de tu compra"<<endl;cin>>compra;
	cout<<"Hola, digita un numero del 1 al 100 "<<endl;cin>>numazar;
	if(numazar>=74){
	por=20;
		descuento=compra*0.8;
	}
	else{
	  if(numazar<64){
		por=15;
		descuento=compra*0.85;
		}
	}
	
	cout<<"Su descuento fue de "<<por<<endl;
	cout<<"El total de su compra fue de "<<descuento;
	
	return 0;
}
