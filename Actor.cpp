#include "Actor.h"

Actor::Actor()
{
	id = 0;
	nombre = "default";
}

Actor::Actor(int ID, std::string nom)
{
	id = ID;
	nombre = nom;
}

void Actor::setId(int ID)
{
	id = ID;
}

void Actor::setNombre(std::string nom)
{
	nombre = nom;
}

int Actor::getId()
{
	return id;
}

std::string Actor::getNombre()
{
	return nombre;
}
