/*ESTE CODIGO ES PROPIEDAD DE JORGE TRINCADO CASTÁN DNI:70079643T*/
#include <cstdio>
#include <iostream> 
#include <cstdlib>
#include <iostream>
#include <sstream> 
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <objbase.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <windows.h> 

#include "MyForm.h" 

#define CONFIGFILE  "C:/LEON3D/FW_updater/Config.ini"       //configuration file name 
#define RESULTFILE  "C:/LEON3D/FW_updater/test.inf"       //outputlog file name 
#define BATFILE  "C:/LEON3D/FW_updater/UploadApp.bat"       //outputlog file name 


using std::cout;
using std::cin;
using std::endl;


using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::IO::Ports;
using namespace System::ComponentModel;

void load_config();
void save_config();
void result();
void clean();

[STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);



	load_config();
	counter++;
	Project3::MyForm form;
	Application::Run(%form);
}


void load_config(){
	int t = 1;
	std::ifstream ifs(CONFIGFILE);

	if (!ifs) {
		MessageBox::Show("no se encontró el fichero de configuración");
		//fprintf(stderr, "Fichero de configuracion %s no encontrado", CONFIGFILE);
		//error = 1;
		system("mkdir \"C:/LEON3D/FW_updater\"");
		language ="ESP";
		 selectedPrinter = "LEGIO";
		 openCounter = "0";
		 ifs.close();
		 save_config();




	}
	else {
		ifs >> language;
		ifs >> selectedPrinter;
		ifs >> openCounter;

	}
	//MessageBox::Show(gcnew String(openCounter.c_str()));
	//MessageBox::Show(gcnew String(language.c_str()));
	counter = (int)stoi(openCounter);

	ifs.close();

}

void save_config() {



	std::string escritura = language + " " + selectedPrinter + " " + std::to_string(counter);
	StreamWriter^ sw = gcnew StreamWriter(CONFIGFILE);
	sw->WriteLine(gcnew String(escritura.c_str()));
	sw->Close();

}

void result(){
	//avrout = -1;
	std::ifstream ifs(RESULTFILE);

	if (!ifs) {
		fprintf(stderr, "Fichero de resultados %s no encontrado", RESULTFILE);
		error = 1;
	}

	std::string linea;
	while (!ifs.eof()) {

		std::getline(ifs, linea);
		std::size_t found = linea.find("OK");
		std::size_t found2 = linea.find("error");
		std::size_t found3 = linea.find("can't");
		std::size_t found4 = linea.find("#");

		if (found4 != std::string::npos && lock==0){
			avrout = 0;
			 // MessageBox::Show("OK2");
			ifs.close();

			break;
		}else if (found != std::string::npos){
			avrout = 10;
			//  MessageBox::Show("OK");
			ifs.close();
			 
			break;
		}
		else if (found2 != std::string::npos){
			avrout = 2;
			// 	MessageBox::Show("error");
			ifs.close();
			 
			break;
		}
		else if (found3 != std::string::npos){
			avrout = 3;
			//  MessageBox::Show("can't");
			ifs.close();
			
			break;

		}
	}
	ifs.close();

	//si no se encuentra coincidencia el estado pasa a -1
	//esta rutina se lanza al terminar bkgw1, para que ocurra con independencia de la barra
	//el backgW2 debe leer este estado, si encuentra un -1 devuelve unknown error
	//si encuentra 1 da el mensaje de OK
	//si encuentra 2, 3 ... da el mensaje de ese fallo.


}
using namespace System;

void clean(){
	  
	StreamWriter^ erasefs = gcnew StreamWriter(RESULTFILE);
	erasefs->WriteLine("");
	erasefs->Close(); 

}

void crearBat(){

	StreamWriter^ sw = gcnew StreamWriter(BATFILE);
	sw->WriteLine(gcnew String(comandoString.c_str()));
	sw->Close();

}