#include "Funcion.h"

Funcion::Funcion()
{
	cveFuncion = "Default";
	numPeli = 0;
	sala = 0;
	hora = Hora(0, 0);
	
}

Funcion::Funcion(std::string fun, int numpel, int sal, Hora hr)
{
	cveFuncion = fun;
	numPeli = numpel;
	sala = sal;
	hora = hr;
}

void Funcion::setCveFuncion(std::string cvefuncion)
{
	cveFuncion = cvefuncion;
}

void Funcion::setNumPeli(int numpeli)
{
	numPeli = numpeli;

}

void Funcion::setSala(int sal)
{
	sala = sal;
}

void Funcion::setHora(Hora hr)
{
	hora = hr;
}

std::string Funcion::getCveFuncion()
{
	return cveFuncion;
}

int Funcion::getNumPeli()
{
	return numPeli;
}

int Funcion::getSala()
{
	return sala;
}

Hora Funcion::getHora()
{
	return hora;
}
