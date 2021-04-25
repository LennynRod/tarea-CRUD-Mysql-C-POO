#pragma once
#include "Persona.h"
#include<mysql.h>
#include<iostream>
#include<string>
#include"ConexionBD.h"

using namespace std;
class Cliente : 
    public Persona{

	//atributos
	private: string nit,ID;

//constructor
	public:
		Cliente() {
		}

		Cliente(string id,string nom, string ape, string dir, int tel,string fn, string n) : Persona(nom, ape, dir, tel,fn) {
			nit = n;
			ID = id;
		}


		void crear() {
			int q_estado;
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion();
			if (cn.getConectar()) {
				string t = to_string(telefono);

				string insert = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento)VALUES('"+nit+"','" + nombres + "','" +apellidos + "','" + direccion + "','"  +t+ "','" + fecha_nacimiento + "')";
				const char* i = insert.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "Ingreso exitoso..." << endl;
				}
				else {
					cout << "error al ingresar..." << endl;
				}

			}
			else {
				cout << "Error en la conexión..." << endl;
			}
			cn.cerrar_conexion();

		}

		void leer() {
			int q_estado;
			ConexionBD cn = ConexionBD();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			cn.abrir_conexion();
			if (cn.getConectar()) {

				string consulta = "select * from clientes";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());

					cout << "------------------------------Clietes------------------------------" << endl << endl;
					while (fila = mysql_fetch_row(resultado)) {
						cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << endl;


					}

				}
				else {
					cout << "error al consultar..." << endl;
				}

				



			}
			else {
				cout << "Error en la conexión..." << endl;
			}
			cn.cerrar_conexion();
		}

		void actualizar() {
			int q_estado;
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			system("pause");
			string update = "update db_empresa.clientes set  nit=('" + nit + "'),nombres = ('" + nombres + "'),apellidos = ('" + apellidos + "'),direccion =('" + direccion + "'),telefono =('" + t + "'),fecha_nacimiento = ('" + fecha_nacimiento + "')  where('" +ID+ "') = id_cliente";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				cout << "Actualizacion exitosa..." << endl;
			}
			else {
				cout << "Error al Actualizar..." << endl;
			}
		}
		else {
			cout << "Error en la conexion..." << endl;
		}cn.cerrar_conexion();


		}

		void eliminar() {
			int q_estado;
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion();
			if (cn.getConectar()) {
				string update = "delete from db_empresa.clientes  where('" + ID + "')=id_cliente";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "Eliminacion exitosa..." << endl;
				}
				else {
					cout << "Error al eliminar..." << endl;
				}
			}
			else {
				cout << "Error en la conexiÃ³n..." << endl;
			}cn.cerrar_conexion();






		}





};