/*
 * ProcesoArchivo.cpp
 *
 *  Created on: 2 dic. 2020
 *      Author: gimnasialp
 */
#include "ProcesoArchivo.h"

using namespace std;

ProcesoArchivo::ProcesoArchivo() {

}

/*
 * pre: Efectua todo el procesamiento del archivo.
 * pos: Valida en conjunto las acciones del programa.
 *      Especificamente verifica existencia del archivo
 *      y la visualizacion del menu.
 */
void ProcesoArchivo::lecturaArchivo() {
	bool abierto = false;
	do {
		ifstream entrada(obtenerNombreArchivo().c_str());
		if (entrada) {
			inicializacionEstructuras(entrada);
			entrada.close();
			abierto = true;
		} else {
			cout << "El Archivo no existe" << endl;
		}
	} while (!abierto);
}

/*
 * pre: Solicita Nombre de Archivo
 * pos: Devuelve el nombre ingresado del archivo
 */
std::string ProcesoArchivo::obtenerNombreArchivo() {
	string nombre;
	cout << "Ingrese nombre del archivo contenedor " << endl;
	cin >> nombre;
	return nombre + ".txt";
}

void ProcesoArchivo::inicializacionEstructuras(ifstream &entrada) {
	string linea, datoObtenido;
	if (entrada.is_open()) {
		while (!entrada.eof()) {
			getline(entrada, linea);
			if (linea != FIN) {
				//
				//for (int i = 0; i < CANTIDAD_DATOS; i++) {
					datoObtenido = linea.substr(0, linea.find(" ", 0));
					//imprimo linea leida
					cout << linea;
					//linea = truncarInfoLinea(datoObtenido, linea);

				//}
				cout << endl;
			}
		}
	}
}

/*
 * pre: Se le pasa el dato obtenido y la linea del archivo.
 * pos: Devuelve la cadena achicada segun la info obtenida anteriormente.
 */
string ProcesoArchivo::truncarInfoLinea(string datoObtenido, string linea) {
	if (datoObtenido != "") {
		return (linea.erase(0, datoObtenido.size() + 1));
	} else {
		return linea.erase(0, 1);
	}
}
