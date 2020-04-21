#include "Pelicula.h"
#include <iostream>

Pelicula::Pelicula()
{
	NumPeli = 0;
	anio = 0;
	duracion = 0;
	cantActores = 0;
	titulo = "";
	genero = "";
	listaActores[9]; //si hay errores revertir a 10
}

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

Actor Pelicula::getListaActores(int num)
{
	return listaActores[num];
}

int Pelicula::getNumPeli()
{
	return NumPeli;
}

std::string Pelicula::getTitulo()
{
	return titulo;
}

int Pelicula::getAnio()
{
	return anio;
}

int Pelicula::getDuracion()
{
	return duracion;
}

std::string Pelicula::getGenero()
{
	return genero;
}

int Pelicula::getCantActores()
{
	return cantActores;
}

void Pelicula::setNumPeli(int numpeli)
{
	NumPeli = numpeli;
}

void Pelicula::setTitulo(std::string titu)
{
	titulo = titu;
}

void Pelicula::setAnio(int a)
{
	anio = a;
}

void Pelicula::setDuracion(int dur)
{
	duracion = dur;
}

void Pelicula::setGenero(std::string gen)
{
	genero = gen;
}

bool Pelicula::addListaActores(Actor act)
{
	int ejecutador = 1;
	if (cantActores != 0) {
	// barrer listaactores con metodos de actor para comprobar que no se repita el id
		for (int i = 0; i < 10; i++) {
			if ((act.getId() == listaActores[i].getId()) && ejecutador == 1)
			{
				ejecutador = 0;
				//std::cout << "El actor ya se encuentra registrado." << std::endl;
				return false;
			}
			if ((act.getId() != listaActores[i].getId()) && ejecutador == 1 && listaActores[i].getId() == 0) {
				listaActores[i].setId(act.getId());
				listaActores[i].setNombre(act.getNombre());
				ejecutador = 0;
				cantActores = cantActores + 1;
				//std::cout << "Actor agregado exitosamente" << std::endl;
				return true;
			}
		}
	}
	if (cantActores == 10)
	{
		//std::cout << "La lista de actores se encuentra llena." << std::endl;
		return false;
	}
	if (cantActores == 0)
	{
		listaActores[0].setId(act.getId());
		listaActores[0].setNombre(act.getNombre());
		cantActores = cantActores + 1;
		return true;
	}
}
