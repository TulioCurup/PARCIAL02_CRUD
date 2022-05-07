#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"


using namespace std;

class Estudiante : Persona {
private: string carnet, email;
	   // constructor
public:
	Estudiante() {
	}
	Estudiante(string nom, string ape, string dir, string tel, string fn, string cnt, string em, string gn) : Persona(nom, ape, dir, tel, gn, fn) {
		carnet = cnt;
		email = em;

	}

	// METODOS
	//set (modificar)
	void setCodigo(string cnt) { carnet = cnt; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(string tel) { telefono = tel; }
	void setGenero(string gn) { genero = gn; }
	void setEmail(string em) { email = em; }
	void setFecha_Nacimiento(int fn) { fecha_nacimiento = fn; }
	//get (mostrar)
	string getCodigo() { return carnet; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }
	string getGenero() { return genero; }
	string getEmail() { return email; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }

	// CREAR
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cout << "\n ingrese carnet:";
		cin >> carnet;
		cout << "ingrese nombre:";
		cin >> nombres;
		cout << "ingrese apellido:";
		cin >> apellidos;
		cout << "ingrese direccion:";
		cin >> direccion;
		cout << "ingrese telefono:";
		cin >> telefono;
		cout << "ingrese genero:";
		cin >> genero;
		cout << "ingrese email:";
		cin >> email;
		cout << "ingrese fecha de nacimiento:";
		cin >> fecha_nacimiento;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO estudiantes(carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento) VALUES ('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" + genero + "','" + email + "','" + fecha_nacimiento + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "\n Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}


	// LEER
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "\n------------ Datos de Estudiantes ------------" << endl;
			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] <<"," << fila[7] << "," << fila[8] << "," << fila[9] << endl;
				}

			}
			else {
				cout << "\n xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << "\n xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	// ACTUALIZAR
	void Actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string id, carnet1,nombres1, apellidos1, direccion1, telefono1, genero1, email1, fecha_nacimiento1;
		cout << "\ningrese Id de estudiante a modificar:";
		cin >> id;
		cout << "ingrese nuevo carnet:";
		cin >> carnet1;
		cout << "ingrese nuevo nombre:";
		cin >> nombres1;
		cout << "ingrese nuevo apellido:";
		cin >> apellidos1;
		cout << "ingrese nueva direccion:";
		cin >> direccion;
		cout << "ingrese nuevo telefono";
		cin >> telefono1;
		cout << "ingrese genero:";
		cin >> genero1;
		cout << "ingrese nuevo email:";
		cin >> email1;
		cout << "ingrese nueva fecha de nacimiento:";
		cin >> fecha_nacimiento1;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string actualizar = "UPDATE `db_escuela`.`estudiantes` SET `carnet` = '" + carnet1 + "', `nombres` = '" + nombres1 + "', `apellidos` = '" + apellidos1 + "', `direccion` = '" + direccion1 + "', `telefono` = '" + telefono1 + "', `genero` = '" + genero1 + "', `email` = '" + email1 + "', `fecha_nacimiento` = '" + fecha_nacimiento1 + "' WHERE (`id_estudiante` ='" + id + "')";
			const char* i = actualizar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "\nActualizacion exitosa ..." << endl;
			}
			else {
				cout << "\n xxx Error al actualizar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	// ELIMINAR
	void Eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string id;
		cout << "\ningrese Id de estudiante a eliminar:";
		cin >> id;
		cn.abrir_conexion();		
		if (cn.getConectar()) {
			
			string eliminar = "DELETE FROM estudiantes WHERE (id_estudiante = '" + id + "')";
			const char* i = eliminar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "\nSe elimino la fila ..." << endl;
			}
			else {
				cout << " xxx Error   xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}




};
