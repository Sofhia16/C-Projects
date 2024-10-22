#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int e,l,p,sec,tic,salariot; float salario;
	string n,cursos,pro, master;
	cout<<"Usted esta aspirando para trabajar en la alcaldia de Cartagena"<<endl;
	cout<<"Digite su nombre"<<endl;cin>>n;
	cout<<"Cual es su edad"<<endl;cin>>e;
	cout<<"Para esta vacante debe contar con los siguientes requisitos:(digite si o no)"<<endl;;
	cout<<"Ha realizado los cursos de: Transparencia, lenguaje claro y anticorrupcion?"<<endl;cin>>cursos;
	cout<<"Digite sus años de experiencia laboral "<<endl;cin>>l;
	cout<<"Digite sus años de experiencia profesional "<<endl;cin>>p;
	if (cursos=="si"&& l>=2 && p>=1){
		cout<<"cumple con los prerequisitos"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<"En que secretaria le gustaria aplicar"<<endl;
		cout<<"1. Secretaria de planeacion"<<endl;
		cout<<"2. Secretaria de cultura"<<endl;
		cout<<"3. Secretaria de salud"<<endl;
		cout<<"4. Secretaria de TIC"<<endl;
		cout<<"5. Secretaria de Deportes"<<endl;cin>>sec;
		switch (sec){
			case 1: 
			cout<<"Es usted un ingeniero industrial"<<endl;cin>>pro;
			cout<<"Cuenta con una maestria?"<<endl;cin>>master;
			if (pro=="si"&& master =="si"&& e>=25){
				cout<<"usted esta contratado"<<endl;
				salario=1500000; salariot=salario+(salario*0.3);
				cout<<"Su salario total es "<<salariot<<endl;
			}
			else{
				cout<<"No cumple con todos los requisitos para esta secretaria por lo tanto no puede aplicar a esta vacante"<<endl;
			}
			break;
			case 2: 
			cout<<"Es usted un historiador"<<endl;cin>>pro;
			cout<<"Cuenta con una especializacion?"<<endl;cin>>master;
			if (pro=="si"&& master =="si"&& e>=25){
				cout<<"usted esta contratado"<<endl;
				salario=1500000; salariot=salario+(salario*0.2);
				cout<<"Su salario total es "<<salariot<<endl;
			}
			else{
				cout<<"No cumple con todos los requisitos para esta secretaria por lo tanto no puede aplicar a esta vacante"<<endl;
			}
			break;
			case 3: 
			cout<<"Es usted medico"<<endl;cin>>pro;
			cout<<"Cuenta con una especializacion?"<<endl;cin>>master;
			if (pro=="si"&& master =="si"&& e>=30){
				cout<<"usted esta contratado"<<endl;
				salario=1500000; salariot=salario+(salario*0.2);
				cout<<"Su salario total es "<<salariot<<endl;
			}
			else{
				cout<<"No cumple con todos los requisitos para esta secretaria por lo tanto no puede aplicar a esta vacante"<<endl;
			}
			break;
			case 4: 
			cout<<"Es usted un ingeniero de sistemas"<<endl;cin>>pro;
			cout<<"Cuenta con una especializacion?"<<endl;cin>>master;
			
			if (pro=="si"&& master =="si"&& e>=25){
				cout<<"usted esta contratado"<<endl;
				cout<<"Su especializacion es en:"<<endl;
			    cout<<"1.Software, 2. Redes o 3. ambas"<<endl;cin>>tic;
				switch(tic){
					case 1: 
				 	 salario=1500000; salariot=2*(salario+(salario*0.2));
				     cout<<"Su salario total es "<<salariot<<endl;
				    break;
				    case 2:
				     salario=1500000; salariot=salario+(salario*0.2);
				     cout<<"Su salario total es "<<salariot<<endl;
				    break;
				    case 3:
				     salario=1500000+1500000*0.2; salariot=salario+salario*2;
				     cout<<"Su salario total es "<<salariot<<endl;
				    break;
				    
				    default: cout<<"no puede aplicar a la vacante"<<endl;
				}
			}
			else{
				cout<<"No cumple con todos los requisitos para esta secretaria por lo tanto no puede aplicar a esta vacante"<<endl;
			}
			break;
			case 5: 
			cout<<"Es usted profesional en educacion fisica"<<endl;cin>>pro;
			if (pro=="si"&& e>=20){
				cout<<"usted esta contratado"<<endl;
				salario=1500000;salariot=salario;
				cout<<"Su salario total es "<<salariot<<endl;
			}
			else{
				cout<<"No cumple con todos los requisitos para esta secretaria por lo tanto no puede aplicar a esta vacante"<<endl;
			}
			break;
		}
	}
	else{
		cout<<"no puede aplicar a esta vacante";
	}
	getch();
	return 0;
}
