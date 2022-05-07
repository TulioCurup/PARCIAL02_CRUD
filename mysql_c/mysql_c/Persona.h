#pragma once
#include <iostream>
using namespace std;
class Persona
{
	// atributos
protected: string nombres, apellidos, direccion, telefono, genero , fecha_nacimiento;

		 // costructor
protected:
	Persona() {
	}
	Persona(string nom, string ape, string dir, string tel, string gn, string fn) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		genero = gn;
		fecha_nacimiento = fn;
	}




};