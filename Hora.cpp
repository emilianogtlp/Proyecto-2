#include "Hora.h"

Hora::Hora()
{
	hh = 0;
	mm = 0;
}

Hora::Hora(int hora, int min)
{
	hh = hora;
	mm = min;
}

void Hora::setHh(int hora)
{
	hh = hora;
}

void Hora::setMm(int min)
{
	mm = min;
}

int Hora::getHh()
{
	return hh;
}

int Hora::getMm()
{
	return mm;
}
