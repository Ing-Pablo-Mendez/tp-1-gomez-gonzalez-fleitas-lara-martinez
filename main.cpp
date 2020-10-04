#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#define NOMBREARCHIVO "Clientes.bin"
#define NOMBRE "Procesados.bin"

using namespace std;

struct cliente
{
    char UsuarioID [10];
    char email[40];
    int dia;
    int mes;
    int anio;
    bool borrado = true;
};

struct compra
{
    char CompraID [10];
    char UsuarioIDD [10];
    int diaa;
    int mess;
    int anioo;
    int horass;
    int minutoss;
    int monto;
    int NroArticulo;
};



int importeTotal (char UsuarioIDD[])
{
    FILE *f;
    struct compra p;
    if (f=fopen(NOMBRE,"rb"))
    {
        int montoTemp;
    	fread(&p,sizeof(struct compra),1,f);
		while(!feof(f))
        {
            if (strcmp(UsuarioIDD, p.UsuarioIDD)==0)
            {
				montoTemp += p.monto;
            }
            fread(&p,sizeof(struct compra),1,f);
        }
        fclose(f);
        return montoTemp;
    }
    return 0;
}



bool guardarregistro()
{
    FILE *f;
    cliente p;
    if (f=fopen(NOMBREARCHIVO,"ab"))
    {
        cout << "Ingrese UsuarioID:" << endl;
        cin >>  p.UsuarioID;
        cout << "Ingrese Email:" << endl;
        cin >> p.email;
        time_t tiempoahora;
		time(&tiempoahora);
		struct tm *mitiempo =localtime (&tiempoahora);
        int anio;
        int mes;
        int dia;

        dia = mitiempo -> tm_mday;
        mes = mitiempo -> tm_mon+1;
        anio = mitiempo-> tm_year+1900;
        p.anio = anio;
        p.mes = mes;
        p.dia = dia;

        fwrite(&p, sizeof(cliente),1,f);
        fclose(f);
        return true;
    }
    return false;
}

int mostrartodo()
{
    FILE *f;
    cliente p;
    if (f=fopen(NOMBREARCHIVO,"rb"))
    {
        fread(&p,sizeof(cliente),1,f);
        while(!feof(f))
        {
            cout << "****** Datos del cliente *******" << endl;
            cout << "UsuarioID: " << p.UsuarioID << endl;
            cout << "Fecha de creacion: " << p.anio << "/" << p.mes << "/" <<p.dia << endl;
            if(p.borrado == 1) {  cout << "Activo: True " << endl;}
            if(p.borrado == 0) {  cout << "Activo: False " << endl;}
            cout << "Email: " << p.email << endl;
            cout << "Total de importe de compras: " << importeTotal (p.UsuarioID) << endl;

            fread(&p,sizeof(struct cliente),1,f);
        }
        fclose(f);
        return 1;
    }
    return 0;
}

int buscar(char UsuarioID[])
{
    FILE *f;
    int encontrado =0;
    struct cliente p;
    if (f=fopen(NOMBREARCHIVO,"rb"))
    {
        while(fread(&p,sizeof(struct cliente),1,f) && !encontrado)
        {
            if (strcmp(UsuarioID, p.UsuarioID)==0)
            {
                encontrado = 1;
                cout << "****** Datos del cliente *******" << endl;
                cout << "UsuarioID " << p.UsuarioID << endl;
                cout << "Fecha de creacion: " << p.anio << "/" << p.mes << "/" <<p.dia << endl;
                if(p.borrado == 1) {  cout << "Activo:  True " << endl;}
                if(p.borrado == 0) {  cout << "Activo: False " << endl;}
                cout << "Email: " << p.email << endl;
                cout << "Total de importe de compras: " << importeTotal (p.UsuarioID) << endl;
            }
            if (strcmp(UsuarioID, p.UsuarioID)==1)
            {
                cout << "No se encontro el cliente buscado" << endl;
            }
        }
        fclose(f);
        return 1;
    }
    return 0;
}

int buscarr(char email[])
{
    FILE *f;
    int encontradoo =0;
    struct cliente p;
    if (f=fopen(NOMBREARCHIVO,"rb"))
    {
        while(fread(&p,sizeof(struct cliente),1,f) && !encontradoo)
        {
            if (strcmp(email, p.email)==0)
            {
                encontradoo = 1;
                cout << "****** Datos del cliente *******" << endl;
                cout << "UsuarioID " << p.UsuarioID << endl;
                cout << "Fecha de creacion: " << p.anio << "/" << p.mes << "/" <<p.dia << endl;
                if(p.borrado == 1) {  cout << "Activo: True " << endl;}
                if(p.borrado == 0) {  cout << "Activo: False " << endl;}
                cout << "Email: " << p.email << endl;
                cout << "Total de importe de compras: " << importeTotal (p.UsuarioID) << endl;
            }
            if (strcmp(email, p.email)==1)
            {
                cout << "No se encontro el cliente buscado" << endl;
            }
        }
        fclose(f);
        return 1;
    }
    return 0;
}

int borrar (char UsuarioID[])
{
    FILE *f;
    int encontrado =0;
    cliente p;
    if (f=fopen(NOMBREARCHIVO,"rb+"))
    {
        while(!encontrado && fread(&p,sizeof(cliente),1,f))
        {
            if (strcmp(UsuarioID, p.UsuarioID)==0)
            {
                encontrado = 1;
                p.borrado = 0;
                fseek(f,(-1)*sizeof(cliente), SEEK_CUR);
                fwrite(&p,sizeof(cliente),1,f);
                cout << "El cliente ha sido desactivado satisfactoriamente" << endl;
            }
        }
        if (!encontrado)
            cout << "No se encontro el cliente a desactivar" << endl;
        fclose(f);
        return 1;
    }
    return 0;
}

bool guardarregistrodecompra ()
{
    FILE *f;
    compra p;
    if (f=fopen(NOMBRE,"ab"))
    {
        cout << "Ingrese UsuarioID:" << endl;
        cin >>  p.UsuarioIDD;
        cout << "Ingrese CompraID:" << endl;
        cin >> p.CompraID;
        cout << "Ingrese Monto:" << endl;
        cin >> p.monto;
        cout << "Ingrese NroArticulo:" << endl;
        cin >> p.NroArticulo;


        time_t tiempoahora;
		time(&tiempoahora);
		struct tm *mitiempoo =localtime (&tiempoahora);
        int anioo;
        int mess;
        int diaa;
        int minutoss;
        int horass;

        diaa = mitiempoo -> tm_mday;
        mess = mitiempoo -> tm_mon+1;
        anioo = mitiempoo-> tm_year+1900;
        horass= mitiempoo -> tm_hour;
        minutoss= mitiempoo -> tm_min;

        p.anioo = anioo;
        p.mess = mess;
        p.diaa = diaa;
        p.horass = horass;
        p.minutoss = minutoss;

        fwrite(&p, sizeof(compra),1,f);

        fclose(f);
        return true;
    }
    return false;
}

int buscarlo (char UsuarioIDD[])
{
    FILE *f;
    int encontrador =0;
    struct compra p;
    if (f=fopen(NOMBRE,"rb"))
    {
        while(fread(&p,sizeof(struct compra),1,f),!feof(f))
        {
            if (strcmp(UsuarioIDD, p.UsuarioIDD)==0)
            {
            encontrador = 1;
            cout << "****** Datos compra *******" << endl;
            cout << "UsuarioID: " << p.UsuarioIDD << endl;
            cout << "Fecha de creacion: " << p.anioo << "/" << p.mess << "/"  << p.diaa << " " << p.horass << ":" << p.minutoss << endl;
            cout << "CompraID: " << p.CompraID << endl;
            cout << "Monto: " << p.monto<< endl;
            cout << "Nro Articulo: " << p.NroArticulo<< endl;
            }
        }
        if (!encontrador)
            printf("El UsuarioID no tiene ninguna compra realizada.\n");
        fclose(f);
        return 1;
    }
    return 0;
}


int listarclientes()
{
    FILE *f;
    cliente p;
    if (f=fopen(NOMBREARCHIVO,"rb"))
    {
        while(fread(&p,sizeof(struct cliente),1,f))
        {
            if (p.borrado == 1)
            {
                cout << "**********Datos del cliente**********" << endl;
                cout << "Usuario ID: " << p.UsuarioID << endl;
                cout << "Fecha de creacion: " << p.anio << "/" << p.mes << "/" <<p.dia << endl;
                if(p.borrado == 1) {  cout << "Activo: True " << endl;}
                if(p.borrado == 0) {  cout << "Activo: False " << endl;}
                cout << "Email: " << p.email << endl;
                cout << "Total de importe de compras: " << importeTotal (p.UsuarioID) << endl;
            }
            if (p.borrado == 0)
            {
                cout << "No se encontro el cliente buscado" << endl;
            }
        }
        fclose(f);
        return 1;
    }
    return 0;
}


int finalizarjornada()
{
    FILE *f;
    cliente p;
    if (f=fopen(NOMBREARCHIVO,"rb"))
    {
        while(fread(&p,sizeof(struct cliente),1,f))
        {
            if (p.borrado == 1)
            {
                importeTotal (p.UsuarioID);
            }
        }
        fclose(f);
        return 1;
    }
    return 0;
}

char menu()
{
    char opcion;
    int a;
    cout << "                    " << endl;
    cout << "Seleccione una opcion:" << endl;
    cout << "1 - Levantar los clientes del archivo" << endl;
    cout << "2 - Cargar un nuevo cliente"<< endl;
    cout << "3 - Desactivar un cliente existente"<< endl;
    cout << "4 - Buscar un cliente por ID o por mail"<< endl;
    cout << "5 - Listar todos los clientes activos ordenados por total del importe"<< endl;
    cout << "6 - Procesar un lote de compras"<< endl;
    cout << "7 - Mostrar todas las compras realizadas de un usuario dado"<< endl;
    cout << "8 - Finalizar jornada"<< endl;
    cout << "                    " << endl;
    cout << "                    " << endl;

    do
        opcion = getch();
    while (!(opcion > '0' && opcion < '10') && (opcion != 27));
    char UsuarioIDbuscado[10];
    char emailbuscado[40];
    char UsuarioIDbuscador[10];
    switch (opcion)
    {
        case '1':
            if (!mostrartodo())
                printf("Error al intentar abrir el archivo.\n");

        break;

        case '2':
            if (guardarregistro())
            {
                printf("El registro se ha guardado con exito.\n");
            }
            else
                printf("Error al intentar abrir el archivo.\n");
        break;

        case '3':
            cout << "Ingrese el UsuarioID del cliente a desactivar:" << endl;
            cin >> UsuarioIDbuscado;
            borrar(UsuarioIDbuscado);

        break;

        case '4':

            cout << "Seleccionar metodo de busqueda:\n" <<endl;
            cout << "1-Busqueda por UsuarioID.\n"<< endl;
            cout << "2-Busqueda por email.\n"<< endl;
            cin >> a;

            if (a==1)
            {
                printf ("Escriba el UsuarioID que desea encontrar: ");
                scanf("%s", UsuarioIDbuscado);
            }
            if (a==2)
            {
                printf ("Escriba el Email que desea encontrar: ");
                scanf("%s",emailbuscado);
            }
            if ( a>2 || a<1 )
            {
               cout << "Valor ingresado incorrecto. Vuelve a seleccionar una opcion" << endl;
            }

            if ((!buscar(UsuarioIDbuscado)) ||  (!buscarr(emailbuscado)))
                printf("Error al intentar abrir el archivo, no hay ningun cliente cargado.\n");

        break;


        case '5':
			if (!listarclientes())
            {
                cout << "No hay clientes cargados en el archivo" << endl;
            }
        break;


        case '6':
            if (guardarregistrodecompra())
                printf("El lote de compra de ha procesado exitosamente.\n");
            else
                printf("Error al intentar abrir el archivo.\n");
        break;

        case '7':
            printf("Ingrese el UsuarioID buscado.\n");
            scanf("%s", UsuarioIDbuscador);
            if (!buscarlo(UsuarioIDbuscador))
                printf("Error al intentar abrir el archivo.\n");
        break;

        case '8':
            finalizarjornada();
            cout << "Se actualizaron los saldos de las cuentas exitosamente" << endl;
            exit(1);
        break;

    }
    return opcion;
}

int main()
{
    char out;
    do
        out = menu();
    while (out != 27);
  return 0;
}

