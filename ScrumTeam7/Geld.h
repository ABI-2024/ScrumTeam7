#pragma once
class Geld
{
private:
	static double Startgeld;
	double Kontostand;
public:
	Geld();
	~Geld();

	
	double getKontostand();
	void addKontostand(double);
	void clearKontostand();
};

