
#include <cstdio>
#include <iostream> 
#include <cstdlib>
#include <iostream>
#include <sstream> 
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <string>


#include "MyForm.h" 
#include "Filament.h"

#define FINAL_MENSAJE 127
#define RXTX_PLOAD_WIDTH 32
#define MAXLINE 256
#define FILAMENTSFILE    "C:/LEON3D/Filament_Change_Manager/Profiles.txt"         //filaments file name
#define CONFIGFILE  "C:/LEON3D/Filament_Change_Manager/Config.txt"       //configuration file name 


using std::cout;
using std::cin;
using std::endl;


using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;




std::string comandos[1000000];
int lineaGcode[10000];

int numGcodes;


[STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	load_filaments();
	load_config();

	FilamentChangeManager::MyForm form;
	Application::Run(%form);

}



int load_filaments() {
	std::string material;
	std::string temperature;
	int t = 0;

	std::ifstream ifs(FILAMENTSFILE);

	if (!ifs) {
		MessageBox::Show("No se pudo acceder al fichero de perfiles de impresión. Deberá cargarlo manualmente en: \n Preferencias>Cargar perfiles", "Filament change manager", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		system("mkdir \"C:/LEON3D/Filament_Change_Manager\"");
		ifs.close();
		filamentArr[0] = Filament("PLA Gris", "212");
		filamentArr[1] = Filament("PLA Amarillo", "214");
		filamentArr[2] = Filament("PLA Azul", "230");
		filamentArr[3] = Filament("PLA Blanco", "205");
		filamentArr[4] = Filament("PLA Naranja", "230");
		filamentArr[5] = Filament("PLA Rojo", "205");
		filamentArr[6] = Filament("PLA Negro", "214");
		numColors = 6;
		t = 6;
		 return t;
	}
	else{
		ifs.close();


#pragma warning(disable : 4996)
		StreamReader^ sr = gcnew StreamReader(FILAMENTSFILE);






		while (sr->Peek() >= 0) {
			String^ Slinea = sr->ReadLine();
			//MessageBox::Show(Slinea);
			msclr::interop::marshal_context context;
			std::string linea = context.marshal_as<std::string>(Slinea);

			std::size_t found = linea.find("[filament");
			if (found != std::string::npos) {
				std::size_t found1 = linea.find(":");
				std::size_t found2 = linea.find("]");
				int desde = static_cast<int>(found1);
				int hasta = static_cast<int>(found2);

				if (desde < hasta) {
					int tamañoNombre = hasta - desde;
					material = linea.substr(desde + 1, tamañoNombre - 1);
					//MessageBox::Show(gcnew String(material.c_str()));
				}
			}

			std::size_t found6 = linea.find("_temperature");
			if (found6 != std::string::npos) {
			}
			else {
				std::size_t found3 = linea.find("temperature");
				if (found3 != std::string::npos) {
					std::size_t found4 = linea.find("=");
					int desde2 = static_cast<int>(found4);
					temperature = linea.substr(desde2 + 2, 3);
					//MessageBox::Show(gcnew String(temperature.c_str()));
					filamentArr[t] = Filament(material, temperature);
					//MessageBox::Show(gcnew String(filamentArr[t].material.c_str()) +", "+ gcnew String(filamentArr[t].temperature.c_str()));
					material = "";
					temperature = "";
					t++;
					numColors++;
				}
			}

			std::size_t found5 = linea.find("[presets]");
			if (found5 != std::string::npos) {
				sr->Close();
				return t;
				break;
			}
		}


		sr->Close();
	}return 0;
}



/*read configuration from persisten file*/
int load_config() {
	int t = 1;
	std::ifstream ifs(CONFIGFILE);

	if (!ifs) {
		fprintf(stderr, "Fichero de configuracion %s no encontrado", CONFIGFILE);
		//MessageBox::Show("No se pudo acceder al fichero de perfiles de impresión. Deberá cargarlo manualmente en: \n Preferencias>Cargar perfiles","Filament change manager", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		language = "ESP";
		unitParam = "mm",
		initialColor = "PLA Gray";
		saveConfig();
	}
	else {
		ifs >> language;
		ifs >> unitParam;
		ifs >> initialColor;
		//if (!ifs) {//si sigue habiendo algo en el stream reader es porque tenemos un color seleccionado por el usuario, hay que concantenar PLA color
		std::string aux;
		ifs >> aux;
		initialColor = initialColor + " " + aux;
		//}
		//std::cout << "lenguaje sleccionado: " << language << ", parametro1: " << unitParam << std::endl;
		//MessageBox::Show(gcnew String(initialColor.c_str()));
	}

	ifs.close();
	return 1;
}

void readGcode() {
	int t = 1, u = 0;
	float z0 = 0, z1 = 0, z2 = 0;
	layerHeight = 0;
	firstLayerHeight = 0;
	MAXZ = 0;
	mmGcode[0] = 0;
	char *GFILE = new char[GGFILE.length() + 1];
	std::strcpy(GFILE, GGFILE.c_str());

	std::ifstream ifs(GFILE);

	if (!ifs) {
		exit(-7);
	}
	//std::cout << "comienza a parsear" << std::endl;


	while (!ifs.eof()) {
		std::getline(ifs, comandos[numGcodes]);

		if (comandos[numGcodes].size()>1) {				//ignorig first lines of the gcode file
			if (comandos[numGcodes].at(3) == 'Z') {		//if gcode line contains 'Z'
				//G1 Z3.200
				lineaGcode[u] = numGcodes; //hasta ahora guardaba solo la posición de los gcodes en el fichero original
				if (u == 0 && (float)atof(comandos[numGcodes].substr(4, 5).c_str()) == 5)mmGcode[0] = 0;
				else{
					mmGcode[u + 1] = (float)atof(comandos[numGcodes].substr(4, 5).c_str());
					if (mmGcode[u + 1] >= MAXZ)	MAXZ = mmGcode[u + 1];
					u++;
					//std::cout << comandos[numGcodes].substr(3, 1) << "        " << u << std::endl;
				}
			}
		}
		//std::cout<<comandos[i]<<"                "<<i<<std::endl;
		numGcodes++;
	}
	//std::cout << u << std::endl;
	//std::cout << numGcodes << std::endl;

	ifs.close();
	Zlevels = u + 1;

}


void writeGfile() {
	int actual_line = 0;
	int buscarExt = 0;

	//for (int q = 0; q < Gcode_counter; q++){
		//MessageBox::Show(gcnew String(Gcode_insert[q].text.c_str()));
	//}

	/*casting input gfile name*/
	char *IN_GFILE = new char[GGFILE.length() + 1];
	std::strcpy(IN_GFILE, GGFILE.c_str());

	/*creating output gfile name*/
	if (SAVEFILE == "") {
		onlyname = GGFILE.substr(0, GGFILE.length() - 6);
		if (language == "ESP"){
			onlyname = onlyname + "_modificado.gcode";
		}
		else if (language == "ENG"){
			onlyname = onlyname + "_modified.gcode";
		}
	}
	else if (SAVEFILE != "") onlyname = SAVEFILE;

	/*opening input & output gfiles*/
	std::ifstream ifs(IN_GFILE);
	std::ofstream ofs(onlyname, std::ios_base::out);

	if (!ifs) {
		//fprintf(stderr, "Fallo al abrir el fichero original", IN_GFILE);
		exit(-9);
	}

	if (!ofs) {
		//std::cout << "Fallo al abrir el fichero de destino" << std::endl;
		exit(-9);
	}

	int actualGcode = 0;
	while (!ifs.eof()) {

		std::getline(ifs, comandos[numGcodes]);
		//MessageBox::Show("LineaACtual: " + actual_line + "lieaBuscada " + Decimal(lineaGcode[Gcode_insert[actualGcode].line]));
		/*if (lineaGcode[Gcode_insert[actualGcode].line-1] == (actual_line)) {
		MessageBox::Show("encontrada linea" + Decimal(lineaGcode[Gcode_insert[actualGcode].line]) + " en " + Decimal(actual_line));
		MessageBox::Show(gcnew String(comandos[numGcodes].c_str()));
		buscarExt = 1;
		}*/
		std::size_t found1 = comandos[numGcodes].find("G1 Z");
		if (found1 != std::string::npos) {		//if gcode line contains 'Z'
			if (((float)atof(comandos[numGcodes].substr(4, 5).c_str())) == Gcode_insert[actualGcode].line){
				//MessageBox::Show("encontrado Z" + gcnew String(comandos[numGcodes].c_str()));
				buscarExt = 1;
			}
		}
		

		if (buscarExt){		//cuando se encuentra extrusión se introduce el cambio
			std::size_t founda = comandos[numGcodes].find("G1");
			if (founda != std::string::npos) {
				std::size_t found = comandos[numGcodes].find(" E");
				if (found != std::string::npos) {
					//MessageBox::Show(gcnew String(comandos[numGcodes].c_str()));
					ofs << Gcode_insert[actualGcode].text;
					ofs << "\r";
					actualGcode++;
					ofs << Gcode_insert[actualGcode].text;
					ofs << "\r";
					actualGcode++;
					actual_line += 2;
					buscarExt = 0;
				}
			}
			//sino sale pero no pone buscarExt = 0, 
		}
		ofs << comandos[numGcodes];//primero se mete el gcode leído, dado que el m600 va siempre después del Exx
		ofs << "\r";
		actual_line++;

		numGcodes++;
	}

	ifs.close();
	ofs.close();

}


int read_new_filaments_file() {

	/*delete old filaments profiles*/
	for (int d = 0; d <numColors; d++)	filamentArr[d] = Filament();
	numColors = 0;

	std::string material;
	std::string temperature;

	int t = 0;

	String^ NEWFICH = gcnew String(NFFILE.c_str()); //para convertir el nombre de fichero a system string
#pragma warning(disable : 4996)
	StreamReader^ srd = gcnew StreamReader(NEWFICH);	//


	while (srd->Peek() >= 0) {
		String^ Slinea = srd->ReadLine();
		msclr::interop::marshal_context context;
		std::string linea = context.marshal_as<std::string>(Slinea);

		virtualFile[line] = linea;
		line++;
		//MessageBox::Show(Slinea);

		std::size_t found = linea.find("[filament");
		if (found != std::string::npos) {
			std::size_t found1 = linea.find(":");
			std::size_t found2 = linea.find("]");
			int desde = static_cast<int>(found1);
			int hasta = static_cast<int>(found2);

			if (desde<hasta) {
				int tamañoNombre = hasta - desde;
				material = linea.substr(desde + 1, tamañoNombre - 1);
				//MessageBox::Show(gcnew String(material.c_str()));
			}
		}

		std::size_t found6 = linea.find("_temperature");
		if (found6 != std::string::npos) {//no hacer nada cuando se trata de otras temperaturas que no son la del extrusor
		}
		else {
			std::size_t found3 = linea.find("temperature");
			if (found3 != std::string::npos) {
				std::size_t found4 = linea.find("=");
				int desde2 = static_cast<int>(found4);
				temperature = linea.substr(desde2 + 2, 3);
				//MessageBox::Show(gcnew String(temperature.c_str()));
				filamentArr[t] = Filament(material, temperature);
				//MessageBox::Show(gcnew String(filamentArr[t].material.c_str()) + ", " + gcnew String(filamentArr[t].temperature.c_str()));
				material = "";
				temperature = "";
				t++;
				numColors++;
			}
		}

		std::size_t found5 = linea.find("[presets]"); //cuando encuentra esto sale. No es necesario seguir leyendo el fichero
		if (found5 != std::string::npos) {
			srd->Close();
			break;
		}
	}

	srd->Close();
	return 0;

}

void saveProfiles() {

	StreamWriter^ swr = gcnew StreamWriter(FILAMENTSFILE);
	for (int i = 0; i < line; i++) 	swr->WriteLine(gcnew String(virtualFile[i].c_str()));
	swr->Close();

}

void saveConfig() {

	std::string escritura = language + " " + unitParam + " " + initialColor;
	StreamWriter^ sw = gcnew StreamWriter(CONFIGFILE);
	sw->WriteLine(gcnew String(escritura.c_str()));
	sw->Close();

}

 