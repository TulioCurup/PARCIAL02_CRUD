// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include "Estudiante.h"  
using namespace std;
int q_estado;

int main()
{
    string carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento;
    Estudiante c = Estudiante(nombres, apellidos, direccion, telefono, fecha_nacimiento, carnet, email, genero);
    cout << "Bienvenido";
    cout << "\n Ingrese la Opcion a ejecutar: 1. Crear   2. Leer   3. Actualizar   4. Eliminar --- Opcion:  ";
    int opcion = 0;
    cin >> opcion;
    
    
    switch (opcion)

    {
    case 1: cout << "\nUsted ha seleccionado la opcion 1 crear";
        c.crear();
        break;
    case 2: cout << "\nUsted ha seleccionado la opcion 2 leer";
        c.leer();
        break;
    case 3: cout << "\nUsted ha seleccionado la opcion 3 actualizar";
        c.Actualizar();
        break;
    case 4: cout << "\nUsted ha seleccionado la opcion 4 eliminar";
        c.Eliminar();
        break;
    }

    return 0;

}
