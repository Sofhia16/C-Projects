#include<iostream>
using namespace std;
int main(){
	string nombre;
	int salario,tiempo,utilidad;
	cout<<"\nDigite su nombre"<<endl;cin>>nombre;
	cout<<"Cuantos es tu salario base"<<endl; cin>>salario;
	cout<<"Cuanto tiempo has trabajado en la empresa"<<endl;cin>>tiempo;
	
	if (tiempo<=1){
		utilidad=salario*0.05+salario;
		cout<<nombre<<" Su salario neto es de "<<utilidad;
	}
	else{
		if(tiempo>1){
			if(tiempo<=2){
				utilidad=salario*0.07+salario;
				cout<<nombre<<" Su salario neto es de "<<utilidad;
			}
			else{
				if (tiempo<=5){
				
				utilidad=salario*0.10+salario;
				cout<<nombre<<" Su salario neto es de "<<utilidad;
				}
				else{
					if(tiempo<=10){
						utilidad=salario*0.15+salario;
			        	cout<<nombre<<" Su salario neto es de "<<utilidad;
						
					}
					else{
						if (tiempo>10){
						  utilidad=salario*0.20+salario;
				          cout<<nombre<<" Su salario neto es de "<<utilidad;
						}
					}
				}
				
			}
		}
	}
	return 0;
}
