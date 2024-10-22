#include<iostream>
#include<conio.h>
#include<string.h>
#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"

using namespace std;
//Funciones principales
void crearpersona(int,int);
void tiposdecuenta(int,int);
void crearcuenta(int,int,long []);
void crearproducto(int,int);
void actualizar(int);
int Transacciones(int,int,int,int);
int cosignar(int,int,long[]);
int retirar(int,int,int);
int transferir(int,int);
int Menu(int);
//funciones punto 9
int ntransacciones(int[],int,int);
void sobreg(float,int,int,int);
void salcuenta(int,int,int);
void tc_cupo(int,int,int,long []);
//definicion de structs
struct nacimiento {
    int year;
    int day;
    int month;
};
struct direccion {
    string calle;
    string carrera;
    string numero;
    string diagonal;
    string transversal;
    string referencia;
};
struct Datos_base{
    string name;
    string apellido;
    string identificacion;
    string email;
    int edad;
    char sexo[6];
    string estatura;
    string celular;
    direccion adress;
    nacimiento date;
    int estrato;
};
struct tipocuenta{
	int codigo;
	string descripcion;
};
struct cuenta{
string codigo_cuenta;
long numero_cuenta;
long saldo_cuenta;
};
struct producto{
    string identificacion_p;
};
struct cliente{
    Datos_base datos;
    tipocuenta tipo[5];
    cuenta  cta[5];
    producto pro;
};
struct punto9{
    string transclme;
    string transclma;
    float pcon;
    float preti;
    float pferi;
    long ctamayor;
    long ctamenor;
    string clctamenor;
    string clctamayor;
    long somayor;
    long somenor;
    long tcupo[];
    long tcmayor;
    long tcmenor;
};
punto9 imp;
cliente citizan[100];
//escritura de funciones
void crearpersona(int i){
    cout<<"---------------------------------------"<<endl;
     cout<<"Datos personales"<<endl;
      cout<<"ingrese su identificacion"<<endl;
     cin>>citizan[i].datos.identificacion;  
      cout<<"ingrese su nombre"<<endl;
     cin>>citizan[i].datos.name;  
     cout<<"ingrese su apellido"<<endl;
     cin>>citizan[i].datos.apellido;  
 }
void tiposdecuenta(int i,int t){
    cout<<"---------------------------------------"<<endl;
    cout<<"Tipos de Cuentas "<<endl;
for(int j=0;j<t;j++){
    int d;
    cout<<"---------------------------------------"<<endl;
    cout<<"Cuentas disponibles"<<endl;
    cout<<"101.Ahorros\n102.Corriente\n103.Tarjeta de credito\n104.Prestamo\n105.Nequi\nIngrese el codigo de la cuenta que quieres crear"<<endl;
    cout<<"--"<<endl;cin>>d;
    switch (d){
        case 101:
            citizan[i].tipo[j].codigo=101;
            citizan[i].tipo[j].descripcion="Ahorros";
            break;
             case 102:
            citizan[i].tipo[j].codigo=102;
            citizan[i].tipo[j].descripcion="Corriente";
            break;
             case 103:
            citizan[i].tipo[j].codigo=103;
            citizan[i].tipo[j].descripcion="Tarjeta de credito";
            break;
             case 104:
            citizan[i].tipo[j].codigo= 104;
            citizan[i].tipo[j].descripcion= "Prestamo";
            break;
             case 105:
            citizan[i].tipo[j].codigo=105;
            citizan[i].tipo[j].descripcion="Nequi";
            break;
    }
    cout<<"\nSu cuenta has sido creada exitosamente\n"<<endl;
    }
}
void crearcuenta(int i,int t,long tcu[]){
cout<<"---------------------------------------"<<endl;
cout<<"Tipos de Cuentas disponibles"<<endl;
for(int j=0;j<t;j++){
cout<<citizan[i].tipo[j].descripcion<<"\nNumero de cuenta"<<endl;
cin>>citizan[i].cta[j].numero_cuenta;
if(citizan[i].tipo[j].codigo ==103){
cout<<"De cuanto es tu cupo "<<endl;cin>>citizan[i].cta[j].saldo_cuenta;
imp.tcupo[i]=citizan[i].cta[j].saldo_cuenta;
tcu[i]=citizan[i].cta[j].numero_cuenta;
}
else{
    if(citizan[i].tipo[j].codigo ==104){
cout<<"De cuanto es tu prestamo"<<endl;cin>>citizan[i].cta[j].saldo_cuenta;
}
else{
cout<<"Saldo para tu cuenta"<<endl;
cin>>citizan[i].cta[j].saldo_cuenta;
}
}
}
cout<<"Proceso exitoso\n";
}
void tc_cupo(int n,int j,int t,long tcu[]){
int mayor=-99;
for(int i=0;i<n;i++){  
if(imp.tcupo[i]>mayor){
mayor=imp.tcupo[i];
imp.tcmayor=tcu[i];
}
}
int menor=mayor;
for(int i=0;i<n;i++){
if(imp.tcupo[i]<menor){
menor=imp.tcupo[i];
imp.tcmenor=tcu[i];
}
}
}
void crearproducto(int i,int t){
    cout<<"Listado de sus productos"<<endl;
    citizan[i].datos.identificacion=citizan[i].pro.identificacion_p;
    cout<<"Usuario: "<<citizan[i].pro.identificacion_p<<endl;
    for(int j=0;j<t;j++){
     cout<<""<<citizan[i].cta[j].numero_cuenta<<"-"<<citizan[i].tipo[j].descripcion<<""<<endl;
    }   
}
int transferir(int i,int t){
    cout<<"---------------------------------------"<<endl;
    cout<<"\tTransferencias\t"<<endl;
int de,ori;long valortransferencia=0, total=0;
cout<<"Usuario"<<citizan[i].datos.name<<" "<<citizan[i].datos.apellido<<"\n Identificacion:"<<citizan[i].datos.identificacion<<endl;
cout<<"\nDesde que cuenta desea transferir: "<<endl;//MUESTRA TODAS LAS CUENTAS
for(int j=0;j<t;j++){
cout<<j+1<<"."<<citizan[i].tipo[j].descripcion<<" - "<<citizan[i].cta[j].numero_cuenta<<""<<endl;
}cin>>ori;
cout<<"\nA que cuenta desea transferir: "<<endl;//MUESTRA TODAS LAS CUENTAS
for(int j=0;j<t;j++){
cout<<j+1<<"."<<citizan[i].tipo[j].descripcion<<" - "<<citizan[i].cta[j].numero_cuenta<<""<<endl;
}cin>>de;
cout<<"Valor de la transferencia: ";cin>>valortransferencia;
for(int j=ori-1;j<ori;j++){//asignamos cuenta origen
if (citizan[i].tipo[j].codigo==101 || citizan[i].tipo[j].codigo==105){
cout<<"cuenta origen: "<<citizan[i].cta[j].numero_cuenta<<"-"<<citizan[i].tipo[j].descripcion<<endl;;
cout<<"saldo disponible: "<<citizan[i].cta[j].saldo_cuenta<<endl;
long total=citizan[i].cta[j].saldo_cuenta-valortransferencia;
cout<<"Saldo actual: "<<total;
citizan[i].cta[j].saldo_cuenta=total;
}
else{
cout<<"\ndesde estas cuentas no se puede transferir"<<endl;
}
}
for(int j=de-1;j<de;j++){//asignamos cuenta destino
if (citizan[i].tipo[j].codigo==101 || citizan[i].tipo[j].codigo==105){
cout<<"\ncuenta destino: "<<citizan[i].cta[j].numero_cuenta<<"-"<<citizan[i].tipo[j].descripcion<<endl;
cout<<"saldo disponible: "<<citizan[i].cta[j].saldo_cuenta<<endl;
long total=citizan[i].cta[j].saldo_cuenta+valortransferencia;
cout<<"Saldo actual: "<<total;
citizan[i].cta[j].saldo_cuenta=total;
}
else{
cout<<"\ndesde estas cuentas no se puede transferir"<<endl;
}
}
return 0;
}
int consignar(int i,int t){
cout<<"---------------------------------------"<<endl;
cout<<"\tConsignaciones\t"<<endl;
cout<<"Usuario"<<citizan[i].datos.name<<" "<<citizan[i].datos.apellido<<"\n Identificacion:"<<citizan[i].datos.identificacion<<endl;
cout<<"Elige la cuenta a consignar: "<<endl;long consignacion=0,total=0;int con;
for(int j=0;j<t;j++){
 cout<<j+1<<" "<<citizan[i].tipo[j].descripcion<<" - "<<citizan[i].cta[j].numero_cuenta<<endl;
}
cin>>con;
for(int j=con-1;j<con;j++){
if (citizan[i].tipo[j].codigo ==102 || citizan[i].tipo[j].codigo ==104){
cout<<"desde estas cuentas no se puede consignar"<<endl; 
}
else{
cout<<"Numero de producto: "<<citizan[i].cta[j].numero_cuenta<<endl;
 cout<<"Saldo disponible "<<citizan[i].cta[j].saldo_cuenta<<endl;
 if(citizan[i].tipo[j].codigo !=103){
 cout<<"\nCuanto quieres consignar?"<<endl;cin>>consignacion;
 total=citizan[i].cta[j].saldo_cuenta+consignacion;cout<<"Saldo actualizado: "<<total<<endl;
 citizan[i].cta[j].saldo_cuenta=total;cout<<"Valor consignado: "<<consignacion<<endl;
}
}
}
}
int retirar(int i,int t,int n){
    cout<<"---------------------------------------"<<endl;
    cout<<"\tRetiros\t"<<endl;
    cout<<"Usuario"<<citizan[i].datos.name<<" "<<citizan[i].datos.apellido<<"\n Identificacion:"<<citizan[i].datos.identificacion<<endl;
cout<<"Elige la cuenta a retirar: "<<endl;
float retiro=0,saldo=0;long total;int ret;
for(int j=0;j<t;j++){
 cout<<j+1<<" "<<citizan[i].tipo[j].descripcion<<" - "<<citizan[i].cta[j].numero_cuenta<<endl;
}
cin>>ret;
for(int j=ret-1;j<ret;j++){
  cout<<"Saldo disponible: "<<citizan[i].cta[j].saldo_cuenta<<endl;
  saldo=citizan[i].cta[j].saldo_cuenta;
  cout<<"\nCuanto quieres retirar?"<<endl;cin>>retiro;
if (citizan[i].tipo[j].codigo==102) {
  float cupo=1000000;
  float total=saldo-retiro;
  float sobregiro=cupo+total;
  if(saldo<retiro){
  citizan[i].cta[j].saldo_cuenta=total;
  cout<<RED<<"\nSaldo insuficiente"<<RESET<<endl;
  if(sobregiro<cupo){
 cout<<"\nHa usado nuestro servicio de sobregiro,por lo tanto debe cancelar el valor de  "<<-total<< " por hacer este retiro \nSaldo disponible para sobregiro: "<<sobregiro<<endl;
sobreg(sobregiro,j,t,n);
}
 }
     citizan[i].cta[j].saldo_cuenta=total;
    cout<<"Saldo actual "<<citizan[i].cta[j].saldo_cuenta;
}
 else{
     if(citizan[i].tipo[j].codigo==104 || citizan[i].tipo[j].codigo==103){
     cout<<"\nDesde esta cuenta no se puede retirar"<<endl;
     }
     else{
        if(saldo<retiro){
        cout<<RED<<"saldo insuficiente"<<RESET<<endl;
    }
    else{
total=saldo-retiro;
citizan[i].cta[j].saldo_cuenta=total;
cout<<"\nSaldo total "<<total<<endl;
    }
}
 }
}
}
void sobreg(float sobregiro,int j,int t,int n){
   float smayor=-99;
        for(int i=0;i<n;i++){
        for(int j=0;j<t;j++){
        if(sobregiro>smayor){
            smayor=sobregiro;
            imp.somayor=citizan[i].cta[j].numero_cuenta;
        }
    }
    
}
  float smenor=smayor;
  
  for(int i=0;i<n;i++){
        for(int j=0;j<t;j++){
            if(sobregiro<smenor){
                smenor=sobregiro;
                imp.somenor=citizan[i].cta[j].numero_cuenta;
            }
        }
        }
}
int Transacciones(int n,int i,int t,int trans,int vectrans[]){
    cout<<"---------------------------------------"<<endl;
    cout<<"\tTransacciones\t"<<endl;
    int m;float cons=0,reti=0,feri=0;
    do{
    cout<<"\nQue operacion desea realizar\n1.Consignar\n2.Retirar\n3.Transferir\n4.Salir"<<endl;cin>>m;
    switch (m){
        case 1:
            trans++;
            cons++;
            consignar(i,t);
            
            break;
        case 2:
            trans++;
            reti++;
            retirar(i,t,n);
            
            break;
        case 3:
            trans++;
            feri++;
            transferir(i,t);
            break;
    }
    }while(m<=3);
    vectrans[i]=trans;
    imp.pcon+=cons;
    imp.preti+=reti;
    imp.pferi+=feri;
}
void actualizar(int i){
    int ac;
cout<<"---Actualizacion de datos---"<<endl;
cout<<"cedula: "<<citizan[i].datos.identificacion<<"\nnombre: "<<citizan[i].datos.name<<"\nedad: "<<citizan[i].datos.edad<<"\nsexo: "<<citizan[i].datos.sexo<<endl;
cout<<"\nFecha de Nacimiento: "<<citizan[i].datos.date.day<<"/ "<<citizan[i].datos.date.month<<"/"<<citizan[i].datos.date.year<<endl;
cout<<"\ncelular: "<<citizan[i].datos.celular<<"\nEstrato: "<<citizan[i].datos.estrato<<"\nDireccion:"<<citizan[i].datos.adress.calle<<" - Cra "<<citizan[i].datos.adress.carrera<<endl;
     do{
     cout<<"Que dato desea actualizar"<<endl;
     cout<<"1.celular  2.estrato  3.direccion 4. ninguno"<<endl;cin>>ac;
     if (ac==1){
         cout<<"celular: "<<endl;cin>>citizan[i].datos.celular;
     }
     else{
         if(ac==2){
              cout<<"Estrato: ";cin>>citizan[i].datos.estrato;
         }
         else{
             if(ac==3){
                 cout<<"Direccion: calle: ";cin>>citizan[i].datos.adress.calle;
                 cout<<"carrera: ";cin>>citizan[i].datos.adress.carrera;
                 cout<<"numero: ";cin>>citizan[i].datos.adress.numero;
                 cout<<"diagonal: ";cin>>citizan[i].datos.adress.diagonal;
                 cout<<"transversal: ";cin>>citizan[i].datos.adress.transversal;
                 cout<<"referencia: ";cin>>citizan[i].datos.adress.referencia;
             }
         }
     }
 }while(ac<4);
     cout<<"cedula: "<<citizan[i].datos.identificacion<<endl;
     cout<<"nombre: "<<citizan[i].datos.name<<endl;
     cout<<"edad: "<<citizan[i].datos.edad<<endl;
     cout<<"sexo: "<<citizan[i].datos.sexo<<endl;
     cout<<"Fecha de Nacimiento: "<<citizan[i].datos.date.day<<"/ "<<citizan[i].datos.date.month<<"/"<<citizan[i].datos.date.year<<endl;
     cout<<"celular: "<<citizan[i].datos.celular<<endl;
     cout<<"Estrato: "<<citizan[i].datos.estrato<<endl;
     cout<<"Direccion:"<<citizan[i].datos.adress.calle<<" - Cra "<<citizan[i].datos.adress.carrera<<" - # "<<citizan[i].datos.adress.numero<<" - dig "<<citizan[i].datos.adress.diagonal<<" - Tv "<<citizan[i].datos.adress.transversal<<" - ref "<<citizan[i].datos.adress.referencia<<endl;
}
int ntransacciones(int n ,int vectrans[]){
int menor=100,mayor=-99;
for(int i=0;i<n;i++){  
if(vectrans[i]>mayor){
mayor=vectrans[i];
imp.transclma=citizan[i].datos.apellido;
}
}
for(int i=0;i<n;i++){
if(vectrans[i]<menor){
menor=vectrans[i];
imp.transclme=citizan[i].datos.apellido;
}
}
}
void salcuenta(int j,int t,int n){
int sacumayor=-99;
for(int i=0;i<n;i++){
        for(int j=0;j<t;j++){
        if(citizan[i].cta[j].saldo_cuenta>sacumayor){
            sacumayor=citizan[i].cta[j].saldo_cuenta;
            imp.ctamayor=citizan[i].cta[j].numero_cuenta;
            imp.clctamayor=citizan[i].datos.apellido;
        }
    }
}
int sacumenor=sacumayor; 
for(int i=0;i<n;i++){
    for(int j=0;j<t;j++){
        if(citizan[i].cta[j].saldo_cuenta<sacumenor){
            sacumenor=citizan[i].cta[j].saldo_cuenta;
        imp.ctamenor=citizan[i].cta[j].numero_cuenta;
            imp.clctamenor=citizan[i].datos.apellido;
        }
    }
}
}
int Menu (int n){
    int vectrans[n];long tcu[n];
    for(int i=0;i<n;i++){
    int option;int t=0,j;int trans=0;
    cout<<"Persona "<<i+1<<endl;
    cout<<"Digita el numero de cuentas que deseas tener?"<<endl;cout<<"--"<<endl;cin>>t;
    if(t>0 and t<5){
    do{
        cout<<"\n ~~~~~MENU PRINCIPAL~~~~~ \n"<<"Digite una opcion"<<endl;
        cout<<"1.Crear tipo de cuenta\n"<<"2.Crear persona\n"<<"3.Crear cuenta\n"<<"4.Mostrar producto\n"<<"5.Transacciones\n"<<"6.Actualizar\n"<<"7. Salir"<<endl;
        cout<<"--"<<endl;cin>>option;
        switch(option){
            case 1:
                tiposdecuenta(i,t);
                break;
            case 2:
                crearpersona(i);
                break;
           case 3:
               crearcuenta(i,t,tcu);
               break;
            case 4:
                crearproducto(i,t);
                break;
            case 5:
                Transacciones(n,i,t,trans,vectrans);
                break;
            case 6:
                actualizar(i);
                break;    
            //en 7 se sale;
        }
    }while(option<=6);
}
salcuenta(j,n,t);
tc_cupo(n,t,j,tcu);
}
ntransacciones(n ,vectrans);
 
}
void imprimir(int n){
    cout<<"Resultados:"<<endl;
    cout<<"Cliente con mas transacciones "<<imp.transclma<<endl;
    cout<<"Cliente con menos transacciones "<<imp.transclme<<endl;
    cout<<"#Cuenta con mayor saldo "<<imp.ctamayor<<" del cliente "<<imp.clctamayor<<endl;
    cout<<"#Cuenta con menor saldo "<<imp.ctamenor<<" del cliente "<<imp.clctamenor<<endl;
    cout<<"#Cuenta con mayor sobregiro "<<imp.somayor<<endl;
    cout<<"Promedio de consignaciones realizadas "<<imp.pcon/n<<endl;
    cout<<"Promedio de retiros realizados "<<imp.preti/n<<endl;
    cout<<"Promedio de transferencias realizadas "<<imp.pferi/n<<endl;
    cout<<"Tarjeta de credito con menos cupo "<<imp.tcmayor<<endl;
    cout<<"Tarjeta de credito con mas cupo "<<imp.tcmenor<<endl;
}
int main(){
 cout<<"Bienvenido al banco *MI CASITA ROJA* \n"<<endl;
 int n=0;
 cout<<"Cuantas personas deseas registrar en nuestro sistema?"<<endl;cin>>n;
 Menu(n);
 imprimir(n);
cout<<"Esperamos que hayas disfrutado usar nuestros servicios, Vuelve pronto :) \n \t*MiCasita roja*\t"<<endl;
getch ();
}
