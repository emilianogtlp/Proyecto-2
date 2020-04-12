#include <string>
#include "Actor.h"
class Pelicula
{
public:
	Pelicula();
	Pelicula(int numpeli, int a, int dur, int cantia, std::string titu, std::string gen);

private:
	int NumPeli, anio, duracion, cantActores;
	std::string titulo, genero;
	Actor listaActores[];
};

