
#include <sstream>
#include <string>

#ifndef Gcode_H
#define Gcode_H 

class Gcode{

public:
	int comand;
	float line;
	std::string value;
	std::string text;
	std::string material;
	std::string representable_color;

public:
	Gcode();
	Gcode(float, int, std::string, std::string);

};

#endif