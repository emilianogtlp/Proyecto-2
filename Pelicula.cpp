#include "Pelicula.h"

Pelicula::Pelicula(int numpeli, int a, int dur, int cantia, std::string titu, std::string gen)
{
	NumPeli = numpeli;
	anio = a;
	duracion = dur;
	cantActores = cantia;
	titulo = titu;
	genero = gen;
	listaActores[cantia];
}
