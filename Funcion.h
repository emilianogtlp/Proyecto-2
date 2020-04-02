#include <string>
#include "Hora.h"
class Funcion
{
public:
	Funcion();
	Funcion(std::string fun, int numpel, int sal, Hora hr);
	void setCveFuncion(std::string cvefuncion);
	void setNumPeli(int numpeli);
	void setSala(int sal);
	void setHora(Hora hr);
	std::string getCveFuncion();
	int getNumPeli();
	int getSala();
	Hora getHora();
private:
	std::string cveFuncion;
	int numPeli, sala;
	Hora hora;
};

