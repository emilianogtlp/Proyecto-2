#pragma once
class Hora
{
public:
	Hora();
	Hora(int hora, int min);
	void setHh(int hora);
	void setMm(int min);
	int getHh();
	int getMm();

private:
	int hh, mm;
};

