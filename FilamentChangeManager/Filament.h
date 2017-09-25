 
#include <sstream>
#include <string>

#ifndef FILAMENT_H
#define FILAMENT_H


class Filament {

public:
	std::string material;
	//int temperatura;  
	std::string temperature;

public:
	Filament();
	//	Filament(std::string, int);
	Filament(std::string, std::string);
};

#endif