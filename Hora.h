#pragma once
#include <iostream>
class Hora
{
public:
	Hora();
	Hora(int hora, int min);
	void setHh(int hora);
	void setMm(int min);
	int getHh();
	int getMm();
	void mostrarhora();

private:
	int hh, mm;
};

