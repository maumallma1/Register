#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class registro{

	public:
		string usuario;
		string clave;
		string dni;
		string telefono;
		string direccion;

		void registroPrincipal();
		void registrarse();
		void hacerpedido();
};

void error();
void pausa();

void registro::registroPrincipal()
{
	system("cls");
    int opcion;
    do
    {
        cout<<"\t\t\t\t***Registro de clientes***\t\t\t\t\n\n";
        cout<<"1. Presiona 1 para registrarse\n\n";
		cout<<"2. Presiona 2 para hacer un pedido\n\n";
		cout<<"3. Presiona 3 para salir\n\n";
        cout<<"Opci\242n: \n\n";
        cin>>opcion;
        switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            registrarse();
            break;
		case 2:
            hacerpedido();
            break;
        case 3:
            break;
        }
    }
    while(opcion!=3);
}
void registro::registrarse()
{
    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("clientes.txt",ios::in);
    escritura.open("clientes.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\t***Registrar a un cliente***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa la clave del cliente: ";
        getline(cin,auxCodigo);
        if(auxCodigo=="")
            do
            {
                cout<<"Clave de cliente no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,clave);
            while(!verificador.eof())
            {
                getline(verificador,usuario);
                getline(verificador,direccion);
                getline(verificador,telefono);
                getline(verificador,dni);

                if(clave==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un cliente con esa clave!\n\n";
                    cout<<"El cliente con esa clave es: "<<usuario<<"\n\n";
                    cout<<"Ingresa una clave v\240lido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo=="")
                        do
                        {
                            cout<<"\nC de cliente no v\240lido!, intentalo nuevamente: ";
                            getline(cin,auxCodigo);
                        }
                        while(auxCodigo=="");

                    break;
                }

                getline(verificador,clave);
            }

            if(verificador.eof()&&auxCodigo!=clave)
                coincidencia=false;

        }
        while(coincidencia==true);
        system("cls");
        clave=auxCodigo;
        cout<<"\t\t\t\t***Registrar a un cliente***\t\t\t\t\n\n";
        cout<<"Ingresa la clave del cliente: ";
        cout<<clave;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el nombre del cliente: ";
        getline(cin,usuario);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la direccion del cliente: ";
        getline(cin,direccion);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el n\243mero de telefono del cliente: ";
        getline(cin,telefono);
        cout<<"\n\n";
        fflush(stdin);
		cout<<"Ingresa el DNI del cliente: ";
        getline(cin,dni);
        cout<<"\n\n";

        escritura<<clave<<"\n"<<usuario<<"\n"<<direccion<<"\n"<<telefono<<"\n"<<dni<<"\n";

        cout<<"El registro se ha completado correctamente.\n\n";
    }

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
	pausa();
}

void registro::hacerpedido()
{
    string auxCodigo;
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("clientes.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"\t\t\t\t***Consultar codigo de un cliente para hacer pedido***\t\t\t\t\n\n";
        cout<<"Ingresa la clave del cliente para proseguir con el pedido: ";
        getline(cin,auxCodigo);
        getline(mostrar,clave);
        while(!mostrar.eof())
        {
            getline(mostrar,usuario);
            getline(mostrar,direccion);
            getline(mostrar,telefono);
            getline(mostrar,dni);

            if(auxCodigo==clave)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"C\242digo: "<<clave<<endl;
                cout<<"Nombre: "<<usuario<<endl;
                cout<<"Domicilio: "<<direccion<<endl;
                cout<<"Celular: "<<telefono<<endl;
                cout<<"DNI: "<<dni<<endl;
                cout<<"\n\n";
            }

            getline(mostrar,clave);
        }

        if(encontrado==false)
        {
            cout<<"\n\nNo se encontro el registro: "<<auxCodigo<<"\n\n";
        }
    }

    else
    {
        error();
    }

    mostrar.close();
	pausa();
}


int main(){
  system ("color f0");
	system ("cls");
	int cliente_o_admin;
	cout<<"\nSi es administrador ingrese el numero 1\n";
	cout<<"\nSi es cliente ingrese el numero 2\n";
	cout<<"\nNumero: "; cin>>cliente_o_admin;
	while(true){
		if (cliente_o_admin==1){
			cout<<"\nEres el admin\n";
			break;
		}
		else if (cliente_o_admin==2){
			registro inicio;
			inicio.registroPrincipal();
			break;
		}
		else {
			cout<<"El numero es invalido, ingrese de nuevo: ";
		}
	}
    return 0;
}


void error()
{
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

void pausa()
{
    cout<<"Presiona Enter para continuar...";
    getch();
    system("cls");
}
