
#include "Gcode.h"


Gcode::Gcode() {
}

Gcode::Gcode(float _line, int _comand, std::string _value, std::string _material) {
	line = _line;
	comand = _comand;
	value = _value;
	material = _material;
	representable_color;



	if (comand == 1) {


		text = "M104 P1 s" + value;



	}
	else if (comand == 2) text = "M600";


}
