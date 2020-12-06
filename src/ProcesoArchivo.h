
#include <iostream>
#include <fstream>

class ProcesoArchivo{

private:
	const std::string FIN="fin";
	const int CANTIDAD_DATOS=3;
public:

	ProcesoArchivo();

	void lecturaArchivo();

	/*
	 * pre: Solicita Nombre de Archivo por pantalla
	 * pos: Devuelve el nombre ingresado del archivo
	 */
	std::string obtenerNombreArchivo();

	void inicializacionEstructuras( std::ifstream &entrada );

	std::string truncarInfoLinea(std::string datoObtenido,std::string linea);

};


