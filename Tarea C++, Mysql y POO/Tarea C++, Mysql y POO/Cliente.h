#pragma once

#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"


using namespace std;
class Cliente : public Persona {
	// atributos
private: string nit;
	   // constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
	}
	//metodos
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	//metodo
	void crear(){
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string t = to_string(telefono);

			string insert = "insert into clientes(nit,nombres,apellidos,direccion,telefono, fecha_nacimiento, clientes )values ('"+ nit + "','" + nombres + "','" + apellidos + "', '" + direccion + "','" + t + "','" + fecha_nacimiento + "');";
				const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar() , i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ...." << endl;


			}
			void actualizar_db_empresa() {
				int id;
				string  idempleado, idpuesto;

				leer();

				cout << "\n introduza el ID ";
				cin >> id;

				cin.ignore();

				cout << "\nNombre del empleado: ";
				getline(cin, marca);

				consulta = "UPDATE db_empresa SET clientes db_empresa = (nit,nombres,apellidos,direccion,telefono, fecha_nacimiento, clientes )values ('" + nit + "','" + nombres + "','" + apellidos + "', '" + direccion + "','" + t + "','" + fecha_nacimiento + "');";
				const char* i = consulta.c_str();
				q_estado = mysql_query(conectar, i);
				if (!q_estado) {
					cout << " actualizada con Exito" << endl;
					leer_marcas();
				}
				else {
					cout << "Error al actualizar marca" << endl;
				}


	}else {
			cout << " ---- Error en la conexion-----" << endl;

		}
		cn.cerrar_conexion();



	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
	
		string consulta;
	consulta = "SELECT * FROM clientes";
	const char* i = consulta.c_str();
	q_estado = mysql_query(cn.getconectar, c);
	if (!q_estado) {
		resultado = mysql_store_result(cn.getconectar());
		cout << "--------------------Cliente--------------------" << endl;
		while (fila = mysql_fetch_row(resultado)) {
			cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << endl;
			cout << "--------------------------" << endl;
		}
	}
	else {
		cout << "Error al leer marcas" << endl;
	}


		-----------------
		}
		else {
			cout << " ---- Error en la conexion-----" << endl;
	
		}void eliminar_marca() {
			int id;
			string idempleado, idpuesto;

			leer_empleado();

			cout << "\nId del empleado: ";
			cin >> id;

			consulta = "DELETE FROM marcas WHERE marcas.id = " + to_string(id);
			const char* i = consulta.c_str();
			q_estado = mysql_query(conectar, i);
			if (!q_estado) {
				cout << "Marca eliminada con Exito" << endl;
				leer_marcas();
			}
			else {
				cout << "Error al eliminar marca" << endl;
			}
		}
		cn.cerrar_conexion();
	}

};

