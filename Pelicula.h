#include <string>
#include "Actor.h"
class Pelicula
{
public:
	Pelicula();
	Pelicula(int numpeli, int a, int dur, int cantia, std::string titu, std::string gen);
	// metodos de acceso //
	Actor getListaActores(int num);
	int getNumPeli();
	std::string getTitulo();
	int getAnio();
	int getDuracion();
	std::string getGenero();

	// metodos de modificacion //
	void setNumPeli(int numpeli);
	void setTitulo(std::string titu);
	void setAnio(int a);
	void setDuracion(int dur);
	void setGenero(std::string gen);
	bool addListaActores(Actor act);

private:
	int NumPeli, anio, duracion, cantActores;
	std::string titulo, genero;
	Actor listaActores[10];
};

