//rev_01
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <sstream> 
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <objbase.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <windows.h> 


#pragma once

/*our oun librarys*/
#include "Filament.h"
#include "Gcode.h"

/*global declarations*/

#define ENG 1;
#define ESP 0;

/*gobal variables*/
std::string GGFILE;			//c++ string with gcode file path
std::string NFFILE;			//c++ string with gcode new filaments file path
std::string SAVEFILE;

Filament filamentArr[100];	//filament data table
Gcode Gcode_insert[40];		//filament change order
float mmGcode[10000];       //posiciones del eje z en milimetros

int numColors, Zlevels = 1, Gcode_counter = 0, filaments_load = 0;
int enabledDrawing, oldNumColors; //para controlar que se pinten las líneas de la representación o no
int cargado_combobox_barra = 0;		//distinto de cero tras la representacion inicial
int error;	//distinto de cero si no se ha logrado abrir un fichero de inicio
int line;	//
int err_mod; //para controlar que no se represente nada cuando sea un fichero modificado anteriormente
float firstLayerHeight;
float layerHeight;

float NUD1lastValue;
int NUD1AP; //NumericUpDown1 Actual Position
int NUD1LV; //NumericUpDown1 Last Value 
float MAXZ;
float mejorAprox = 20;

int quieto = 0;

std::string stringLayerHeight;
std::string selected_temperature;
std::string selected_filament_text;
std::string onlyname;
std::string language = "ENG", unitParam = "mm", initialColor = "PLA Gray"; //global configuration  parameters
std::string virtualFile[10000];

/*STRINGS DE LOS MENSAJES*/
/**HEADERS**/
std::string OPENCONTEXT_MSG = "Select .gcode file";
std::string NEW_PERFILES_FILECONTEXT_MSG = "Select profiles file";
std::string FILEBOX_MSG = "File";
std::string FILAMENTBOX_MSG = "Filament";
std::string STATUS_MSG = "Status";
std::string ZLAYERBOX_MSG = "  Layer";
std::string ENDBOX_MSG = "File saved!";

/**BUTTONS**/
std::string OPEN_BTN = "Open";
std::string ADDCHANGE_BTN = "Add filament change";
std::string SAVE_BTN = "Save changes";

/**CONSOLE**/
std::string MSG1 = "Filament change to ";
std::string MSG2 = ", at ";

/**STRIP MENU**/
std::string FILE_MSG = "File";
std::string OPEN_MSG = "Open";
std::string SAVE_MSG = "Save";
std::string SAVEAS_MSG = "Save as";
std::string EXIT_MSG = "Exit";
std::string PREFERENCES_MSG = "Preferences";
std::string LANGUAGE_MSG = "Language";
std::string UNITS_MSG = "Units";
std::string INITIAL_COLOR_MSG = "Initial color";
std::string LOAD_FILAMENTS_FILE_MSG = "Load filaments file";
std::string SLICED_LAYERS_MSG = "Sliced layers";
std::string HELP_MSG = "Help";
std::string CONTEXT_MSG = "Documentation";
std::string ABOUT_MSG = "About";
std::string ENG_MSG = "English";
std::string ESP_MSG = "Spanish";
std::string MM_MSG = "millimeters";
std::string LAYERS_MSG = "Layers";
std::string COMBOBOX1_MSG = "-Select filament-";
std::string  READ_ERR_MSG = "A file previously modified can't be opened";
std::string INSERT_ERR_MSG = "Upper chages should be deleted to insert this command";
std::string FIL_ERR_MSG = "please, select a filament profile";
//std::string WS_MSG = "LEON3D WebSite";

/*rutines*/
int load_config();
int load_filaments();
int read_new_filaments_file();

void readGcode();
void writeGfile();
void saveProfiles();
void saveConfig();

namespace FilamentChangeManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			if (language == "ENG") {
				//HEADERS 
				OPENCONTEXT_MSG = "Select .gcode file";
				NEW_PERFILES_FILECONTEXT_MSG = "Select profiles file";
				FILEBOX_MSG = "File";
				FILAMENTBOX_MSG = "Filament";
				STATUS_MSG = "Status";
				ZLAYERBOX_MSG = "  Layer";
				ENDBOX_MSG = "File saved!";

				//BUTTONS
				OPEN_BTN = "Open";
				ADDCHANGE_BTN = "Add filament change";
				SAVE_BTN = "Save changes";

				//CONSOLE
				MSG1 = "Filament change to";
				MSG2 = ", at ";

				//BARRA DE HERRAMIENTAS
				FILE_MSG = "File";
				OPEN_MSG = "Open";
				SAVE_MSG = "Save";
				SAVEAS_MSG = "Save as";
				EXIT_MSG = "Exit";
				PREFERENCES_MSG = "Preferences";
				LANGUAGE_MSG = "Language";
				ENG_MSG = "English";
				ESP_MSG = "Spanish";
				MM_MSG = "Millimeters";
				LAYERS_MSG = "Layers";
				UNITS_MSG = "Units";
				INITIAL_COLOR_MSG = "Initial color";
				LOAD_FILAMENTS_FILE_MSG = "Load filaments file";
				SLICED_LAYERS_MSG = "Sliced layers";
				HELP_MSG = "Help";
				CONTEXT_MSG = "Documentation";
				ABOUT_MSG = "About";
				COMBOBOX1_MSG = "-Select filament-";
				READ_ERR_MSG = "A file previously modified can't be opened";
				INSERT_ERR_MSG = "Upper changes should be deleted in order to insert this command";
				FIL_ERR_MSG = "please, select a filament profile";

			}
			else if (language == "ESP") {
				//HEADERS 
				OPENCONTEXT_MSG = "Seleccione un fichero .gcode";
				NEW_PERFILES_FILECONTEXT_MSG = "Seleccione fichero de perfiles";
				FILEBOX_MSG = "Fichero";
				FILAMENTBOX_MSG = "Filamento";
				STATUS_MSG = "Cambios introducidos";
				ZLAYERBOX_MSG = " Capa";
				ENDBOX_MSG = "Fichero guardado con éxito";

				//BOTONES
				OPEN_BTN = "Abrir";
				ADDCHANGE_BTN = "Añadir cambio";
				SAVE_BTN = "Guardar cambios";

				//CONSOLA
				MSG1 = "Nuevo filamento ";
				MSG2 = ", altura";

				//BARRA DE HERRAMIENTAS
				FILE_MSG = "Archivo";
				OPEN_MSG = "Abrir";
				SAVE_MSG = "Guardar";
				SAVEAS_MSG = "Guardar como";
				EXIT_MSG = "Salir";
				PREFERENCES_MSG = "Preferencias";
				LANGUAGE_MSG = "Lenguaje";
				ENG_MSG = "Inglés";
				ESP_MSG = "Español";
				UNITS_MSG = "Unidades";
				MM_MSG = "Milimetros";
				LAYERS_MSG = "Capas";
				INITIAL_COLOR_MSG = "Color inicial";
				LOAD_FILAMENTS_FILE_MSG = "Cargar perfiles";
				SLICED_LAYERS_MSG = "Capas";
				HELP_MSG = "Ayuda";
				CONTEXT_MSG = "Documentacion";
				ABOUT_MSG = "Sobre FCM";
				COMBOBOX1_MSG = "-Seleccione un filamento-";
				READ_ERR_MSG = "No se puede abrir un fichero modificado anteriormente";
				INSERT_ERR_MSG = "Los cambios superiores deben ser eliminados para poder introducir este comando";
				FIL_ERR_MSG = "porfavor, seleccione  un perfil de filamento";
			}

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;

	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;

	private: System::Windows::Forms::Button^  button4;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker3;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker4;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  archivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  preferencesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  languageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  englishToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  spanishToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  unitsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  milimetersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  slicedLayersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  contextToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  inicialColorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripComboBox^  toolStripComboBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  loadFilamentsFileToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::ToolStripMenuItem^  webSiteToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker3 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker4 = (gcnew System::ComponentModel::BackgroundWorker());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->archivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->preferencesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->spanishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->unitsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->milimetersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->slicedLayersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->inicialColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->loadFilamentsFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->webSiteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->backgroundWorker5 = (gcnew System::ComponentModel::BackgroundWorker());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(110, 26);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(440, 57);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = (gcnew String(FILEBOX_MSG.c_str()));

			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(17, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(310, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(347, 17);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button1->Text = gcnew String(OPEN_BTN.c_str());

			// 
			// groupBox2
			// 
			this->groupBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->groupBox2->Controls->Add(this->groupBox5);
			this->groupBox2->Controls->Add(this->groupBox4);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Enabled = false;
			this->groupBox2->Location = System::Drawing::Point(110, 86);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(440, 75);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = gcnew String(FILAMENTBOX_MSG.c_str());

			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->numericUpDown2);
			this->groupBox5->Location = System::Drawing::Point(172, 10);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(79, 48);
			this->groupBox5->TabIndex = 5;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"ºC";
			this->groupBox5->Enter += gcnew System::EventHandler(this, &MyForm::groupBox5_Enter);
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(15, 19);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 270, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(52, 20);
			this->numericUpDown2->TabIndex = 7;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->numericUpDown1);
			this->groupBox4->Location = System::Drawing::Point(245, 10);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(82, 48);
			this->groupBox4->TabIndex = 6;
			this->groupBox4->TabStop = false;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(16, 19);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(54, 20);
			this->numericUpDown1->TabIndex = 4;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(347, 19);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 39);
			this->button2->TabIndex = 3;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			this->button2->Text = gcnew String(ADDCHANGE_BTN.c_str());

			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(17, 29);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(144, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Tag = L"";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ComboBox1_SelectedIndexChanged);
			this->comboBox1->Click += gcnew System::EventHandler(this, &MyForm::comboBox1_Click);
			this->comboBox1->Text = gcnew String(COMBOBOX1_MSG.c_str());

			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button4);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Enabled = false;
			this->groupBox3->Location = System::Drawing::Point(110, 165);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(440, 97);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = gcnew String(STATUS_MSG.c_str());

			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(368, 65);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(30, 23);
			this->button4->TabIndex = 2;
			this->button4->Text = L"<<";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(17, 20);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(310, 68);
			this->textBox2->TabIndex = 1;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(347, 20);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 43);
			this->button3->TabIndex = 0;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			this->button3->Text = gcnew String(SAVE_BTN.c_str());

			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(35, 44);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(48, 241);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Text = L"notifyIcon1";
			this->notifyIcon1->Visible = true;
			this->notifyIcon1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::notifyIcon1_MouseDoubleClick);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"(*.gcode)|*.gcode";
			this->openFileDialog1->Filter = L"(*.gcode)|*.gcode";
			this->openFileDialog1->InitialDirectory = L"C:\\Users";
			this->openFileDialog1->ShowReadOnly = true;
			this->openFileDialog1->ValidateNames = false;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker2_DoWork);
			this->backgroundWorker2->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker2_RunWorkerCompleted);
			// 
			// backgroundWorker3
			// 
			this->backgroundWorker3->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker3_DoWork);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(162, 269);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(268, 55);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->CreatePrompt = true;
			this->saveFileDialog1->DefaultExt = L"gcode";
			this->saveFileDialog1->Filter = L"(*.gcode)|*.gcode";
			this->saveFileDialog1->InitialDirectory = L"C:\\Users";
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::saveFileDialog1_FileOk);
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->toolStripSeparator1, this->exitToolStripMenuItem
			});
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(12, 20);
			this->archivoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::archivoToolStripMenuItem_Click);
			this->archivoToolStripMenuItem->Text = gcnew String(FILE_MSG.c_str());

			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);

			this->openToolStripMenuItem->Text = gcnew String(OPEN_MSG.c_str());

			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			this->saveToolStripMenuItem->Enabled = false;
			this->saveToolStripMenuItem->Text = gcnew String(SAVE_MSG.c_str());

			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveAsToolStripMenuItem_Click);
			this->saveAsToolStripMenuItem->Enabled = false;
			this->saveAsToolStripMenuItem->Text = gcnew String(SAVEAS_MSG.c_str());

			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(64, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			this->exitToolStripMenuItem->Text = gcnew String(EXIT_MSG.c_str());

			// 
			// preferencesToolStripMenuItem
			// 
			this->preferencesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->languageToolStripMenuItem,
					this->unitsToolStripMenuItem, this->inicialColorToolStripMenuItem, this->loadFilamentsFileToolStripMenuItem

			});
			this->preferencesToolStripMenuItem->Name = L"preferencesToolStripMenuItem";
			this->preferencesToolStripMenuItem->Size = System::Drawing::Size(12, 20);
			this->preferencesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::preferencesToolStripMenuItem_Click_1);
			this->preferencesToolStripMenuItem->Text = gcnew String(PREFERENCES_MSG.c_str());

			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->spanishToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			this->languageToolStripMenuItem->Text = gcnew String(LANGUAGE_MSG.c_str());

			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Checked = true;
			this->englishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Indeterminate;
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->englishToolStripMenuItem->Text = L"English";
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::englishToolStripMenuItem_Click);
			this->englishToolStripMenuItem->Text = gcnew String(ENG_MSG.c_str());
			// 
			// spanishToolStripMenuItem
			// 
			this->spanishToolStripMenuItem->Checked = true;
			this->spanishToolStripMenuItem->CheckOnClick = true;
			this->spanishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->spanishToolStripMenuItem->Name = L"spanishToolStripMenuItem";
			this->spanishToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->spanishToolStripMenuItem->Text = L"Spanish";
			this->spanishToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::spanishToolStripMenuItem_Click);
			this->spanishToolStripMenuItem->Text = gcnew String(ESP_MSG.c_str());


			// 
			// unitsToolStripMenuItem
			// 
			this->unitsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->milimetersToolStripMenuItem,
					this->slicedLayersToolStripMenuItem
			});
			this->unitsToolStripMenuItem->Name = L"unitsToolStripMenuItem";
			this->unitsToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			this->unitsToolStripMenuItem->Text = gcnew String(UNITS_MSG.c_str());

			// 
			// milimetersToolStripMenuItem
			// 
			this->milimetersToolStripMenuItem->Checked = true;
			this->milimetersToolStripMenuItem->CheckOnClick = true;
			this->milimetersToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->milimetersToolStripMenuItem->Name = L"milimetersToolStripMenuItem";
			this->milimetersToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->milimetersToolStripMenuItem->Text = gcnew String(MM_MSG.c_str());
			this->milimetersToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::milimetersToolStripMenuItem_Click_1);
			// 
			// slicedLayersToolStripMenuItem
			// 
			this->slicedLayersToolStripMenuItem->Name = L"slicedLayersToolStripMenuItem";
			this->slicedLayersToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->slicedLayersToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::slicedLayersToolStripMenuItem_Click);
			this->slicedLayersToolStripMenuItem->Text = gcnew String(SLICED_LAYERS_MSG.c_str());

			// 
			// inicialColorToolStripMenuItem
			// 
			this->inicialColorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripComboBox1 });
			this->inicialColorToolStripMenuItem->Name = L"inicialColorToolStripMenuItem";
			this->inicialColorToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			this->inicialColorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::inicialColorToolStripMenuItem_Click);
			this->inicialColorToolStripMenuItem->MouseEnter += gcnew System::EventHandler(this, &MyForm::inicialColorToolStripMenuItem_Click);
			this->inicialColorToolStripMenuItem->Text = gcnew String(INITIAL_COLOR_MSG.c_str());

			// 
			// toolStripComboBox1
			// 
			this->toolStripComboBox1->Name = L"toolStripComboBox1";
			this->toolStripComboBox1->Size = System::Drawing::Size(121, 23);
			this->toolStripComboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::toolStripComboBox1_SelectedIndexChanged);
			this->toolStripComboBox1->Click += gcnew System::EventHandler(this, &MyForm::toolStripComboBox1_Click);
			this->toolStripComboBox1->Text = gcnew String(initialColor.c_str());

			// 
			// loadFilamentsFileToolStripMenuItem
			// 
			this->loadFilamentsFileToolStripMenuItem->Name = L"loadFilamentsFileToolStripMenuItem";
			this->loadFilamentsFileToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			this->loadFilamentsFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadFilamentsFileToolStripMenuItem_Click);
			this->loadFilamentsFileToolStripMenuItem->Text = gcnew String(LOAD_FILAMENTS_FILE_MSG.c_str());

			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->contextToolStripMenuItem,
					this->aboutToolStripMenuItem,
					//this->webSiteToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(12, 20);
			this->helpToolStripMenuItem->Text = gcnew String(HELP_MSG.c_str());

			// 
			// contextToolStripMenuItem
			// 
			this->contextToolStripMenuItem->Name = L"contextToolStripMenuItem";
			this->contextToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			this->contextToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::contextToolStripMenuItem_Click);
			this->contextToolStripMenuItem->Text = gcnew String(CONTEXT_MSG.c_str());

			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			this->aboutToolStripMenuItem->Text = gcnew String(ABOUT_MSG.c_str());
			// 
			// webSiteToolStripMenuItem
			// 
			this->webSiteToolStripMenuItem->Name = L"webSiteToolStripMenuItem";
			this->webSiteToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->webSiteToolStripMenuItem->Text = L"LEON3D website";
			this->webSiteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::webSiteToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->archivoToolStripMenuItem,
					this->preferencesToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(591, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->DefaultExt = L"(*.txt)|*.txt";
			this->openFileDialog2->Filter = L"(*.ini)|*.ini";
			this->openFileDialog2->InitialDirectory = L"C:\\Users";
			this->openFileDialog2->ShowReadOnly = true;
			this->openFileDialog2->ValidateNames = false;
			this->openFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog2_FileOk);
			// 
			// backgroundWorker5
			// 
			this->backgroundWorker5->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker5_DoWork);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Control;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Location = System::Drawing::Point(44, 280);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(39, 13);
			this->textBox4->TabIndex = 8;
			this->textBox4->Text = L"Z = 0";
			this->textBox4->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = false;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(575, 335);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"LEON 3D Filament Change Manager rev.02A";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->groupBox4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion


	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (!quieto){
					 mejorAprox = 200;

					 if (unitParam == "mm"){		//si está en mm hay que actualizar la posición del array de representación

						 if (NUD1AP > 1) {
							 // numericUpDown1->Increment = Decimal(mmGcode[2] + 0.01 - mmGcode[1]);
							 layerHeight = mmGcode[3] + 0.01 - mmGcode[2];
							 numericUpDown1->Increment = Decimal(layerHeight);
							 //MessageBox::Show("grosor de capa: " + Decimal(layerHeight) + ", posicion actual: " + NUD1AP);
						 }



						 if (abs(mmGcode[NUD1AP] - ((float)numericUpDown1->Value)) > layerHeight * 2){//cambiar 1 por layerHeight para mayor precision

							 //MessageBox::Show("lyh" + layerHeight + ";" + layerHeight*2);
							 //MessageBox::Show("entra en el modo raro: Posicion array" + (mmGcode[NUD1AP] + "-posicion numeric" + ((float)numericUpDown1->Value)) + "; resta:" + abs(mmGcode[NUD1AP] - ((float)numericUpDown1->Value)));
							 for (int i = 1; i <= Zlevels; i++){ //este for recorre el array de Zs para localizar la más aproximada al valor introducido por el usuario
								 float resta = abs(mmGcode[i] - (float)numericUpDown1->Value);
								 // MessageBox::Show("resta: " + resta + "; mejor actual: " + mejorAprox);
								 if (resta <  mejorAprox){
									 // MessageBox::Show("mejor: " + mmGcode[i] + "-" + (float)numericUpDown1->Value + "=" + resta + ";" + mejorAprox);
									 mejorAprox = resta;
									 NUD1AP = i;
									 NUD1LV = i;
								 }
								 else if (resta >mejorAprox)break;

							 }
						 }
						 else if (((float)numericUpDown1->Value) > mmGcode[NUD1AP]){
							 //MessageBox::Show("normal>; valor actual: " + mmGcode[NUD1AP] + ";posicion nueva= " +( NUD1AP + 1) + "; valor superior " + mmGcode[NUD1AP + 1]);
							 NUD1AP++;
							 NUD1LV++;
							 numericUpDown1->Value = Decimal(mmGcode[NUD1AP]);
						 }
						 else if (((float)numericUpDown1->Value) < mmGcode[NUD1AP]){
							 //MessageBox::Show("normal<; valor actual: " + mmGcode[NUD1AP] + ";posicion nueva= " + (NUD1AP -1) + "; valor inferior " + mmGcode[NUD1AP - 1]);
							 NUD1AP--;
							 NUD1LV--;
							 numericUpDown1->Value = Decimal(mmGcode[NUD1AP]);
						 }


						 //MessageBox::Show("nueva posicion: " + NUD1AP + "nuevo valor: " + Decimal(mmGcode[NUD1AP]));

					 }

					 if (unitParam == "layer"){//si está en capas....

						 if (abs(NUD1LV - (int)numericUpDown1->Value) > 1){
							 //else if ((((int)numericUpDown1->Value) > (NUD1LV + 1))||(((int)numericUpDown1->Value) < (NUD1LV - 1))){

							 NUD1AP = NUD1LV = (int)numericUpDown1->Value;
							 // MessageBox::Show("level nud raro: " + Decimal(NUD1LV));


						 }
						 else if (((int)numericUpDown1->Value) == (NUD1LV + 1)){
							 NUD1AP++;
							 NUD1LV++;
							 // MessageBox::Show("level nud subir: " + Decimal(NUD1LV));

						 }
						 else if (((int)numericUpDown1->Value) == (NUD1LV - 1)){
							 NUD1AP--;
							 NUD1LV--;
							 // MessageBox::Show("level nud bajar: " + Decimal(NUD1LV));

						 }

						 numericUpDown1->Value = Decimal(NUD1LV);//actualizo el valor del numericUpDown
					 }
					 // MessageBox::Show("level nud final: " + Decimal(NUD1LV));

				 }
	}
	private: System::Void notifyIcon1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	}
	private: System::Void openFileDialog1_FileOk_1(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}


	private:
		void button1_Click(System::Object ^ sender,
			System::EventArgs ^ e)
		{
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				err_mod = 0;
				//System::IO::StreamReader(openFileDialog1->FileName);

				String^ filenname = System::IO::Path::GetFileName(openFileDialog1->FileName);
				String^ path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);

				//GPATH = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);

				/*codigo muy bueno! pasa de string del sistema a string normal*/
				// System::String^ managedString = "test";
				msclr::interop::marshal_context context;
				GGFILE = context.marshal_as<std::string>(openFileDialog1->FileName);
				// *GGFILE = strdup(GFILE.c_str());
				// textBox1->Text = (openFileDialog1->FileName);
				// MessageBox::Show( filenname );  /*CODIGO BUENO: muestra un string del sistema en un textbox*/
				// readGcode();
				if (GGFILE.substr(GGFILE.size() - 17, 17) == "_modificado.gcode") {
					MessageBox::Show(gcnew String(READ_ERR_MSG.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					err_mod = 1;
				}
				if (GGFILE.substr(GGFILE.size() - 15, 15) == "_modified.gcode") {
					MessageBox::Show(gcnew String(READ_ERR_MSG.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					err_mod = 1;
				}


				backgroundWorker1->RunWorkerAsync(1);  //starting background worker


				comboBox1->Items->Add("err");
				comboBox1->Items->Clear();
				for (int u = 0; u < numColors; u++) comboBox1->Items->Add(gcnew String(filamentArr[u].material.c_str()));
				filaments_load = 1;


				String^ str3 = gcnew String(GGFILE.c_str());
				//MessageBox::Show( str3 );

				if (!err_mod) {
					textBox1->Text = (openFileDialog1->FileName);
					this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
					this->pictureBox1->Refresh();
					this->textBox4->Visible = true;
					this->groupBox2->Enabled = true;
					textBox2->Text = gcnew String(" ");
					saveAsToolStripMenuItem->Enabled = false;
					saveToolStripMenuItem->Enabled = false;
					groupBox3->Enabled = false;
					comboBox1->Text = gcnew String(COMBOBOX1_MSG.c_str());
					for (int t = 0; t < Gcode_counter; t++)  Gcode_insert[t] = Gcode();
					Gcode_counter = 0;

				}
			}
		}


	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
				 readGcode();




	}
	private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
				 //for (int i = 0; i < Zlevels; i++) MessageBox::Show(i+":"+mmGcode[i]);

				 mejorAprox = 20;
				 //std::ostringstream Stream;
				 //Stream << layerHeight;


				 if (unitParam == "mm") {
					 //MessageBox::Show("capas"+Decimal(Zlevels)+", grosor de capa: "+Decimal(layerHeight)+", altura"+Decimal(Zlevels*layerHeight));
					 numericUpDown1->DecimalPlaces = 2;
					 numericUpDown1->Increment = Decimal(0.1);
					 // if (NUD1AP <= 1) numericUpDown1->Increment = Decimal(mmGcode[1] + 0.01 - mmGcode[0]);
					 numericUpDown1->Value = 0;
					 numericUpDown1->Maximum = Decimal(MAXZ);
					 numericUpDown1->Value = Decimal(MAXZ);
					 groupBox4->Text = " Z mm";
					 NUD1LV = Zlevels - 1;
				 }
				 else {
					 numericUpDown1->Value = 0;
					 numericUpDown1->Increment = Decimal(1);
					 numericUpDown1->Maximum = Zlevels - 1;
					 numericUpDown1->Minimum = 0;
					 numericUpDown1->Value = Zlevels - 1;
					 NUD1LV = Zlevels - 1;
				 }

				 if (unitParam == "layer")  groupBox4->Text = gcnew String(ZLAYERBOX_MSG.c_str());


	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 System::Object ^o2 = nullptr;
				 /*hay que lanzar una rutina que: o bien sea capaz de saber el número del array que se corresponde con lo mostrado en el combo box
				 *o bien hay que hacerse un equials con los valores del array, esto es más probable...
				 *if(combobox.text==filamentArr[i].material) tempreratura = filamentArr[i].Temp;
				 */

				 /*to submit selected filament name and temperature*/
				 this->groupBox3->Enabled = true;
				 this->saveToolStripMenuItem->Enabled = true;
				 this->saveAsToolStripMenuItem->Enabled = true;
				 msclr::interop::marshal_context context;
				 if (comboBox1->SelectedItem != o2) {
					 selected_filament_text = context.marshal_as<std::string>(comboBox1->SelectedItem->ToString());


					 for (int t = 0; t <= numColors; t++) {
						 if (selected_filament_text == filamentArr[t].material) {
							 selected_temperature = filamentArr[t].temperature;

							 /*si el usuario cambia manualmente el valor de la temperatura....*/
							 msclr::interop::marshal_context context;
							 String^ stringVal = System::Convert::ToString(numericUpDown2->Value);
							 std::string aux1 = context.marshal_as<std::string>(stringVal);
							 selected_temperature = aux1;
							 //MessageBox::Show("d: " + numericUpDown2->Value);
							 //MessageBox::Show(gcnew String(((filamentArr[t].material + ":" + selected_temperature).c_str())) + ";" + gcnew String((aux1.c_str())));
						 }
					 }

					 /*to submit selected Zline*/
					 //se trata de hacer numericUpDown.value, pasarlo a int?? y meterlo al constructor
					 //puede ser interesante no pasarlo a int dado que finalmente vamos a crear un string

					 /*create new gcode object with selected values: line, code, temperature*/
					 // if (unitParam == "mm") {


					 //MessageBox::Show(" " + Decimal(Gcode_insert[Gcode_counter - 3].line) + ";" + Decimal(Gcode_insert[Gcode_counter - 2].line) + ";" + Decimal(mmGcode[NUD1AP]));
					 if (mmGcode[NUD1AP] < (Gcode_insert[Gcode_counter - 2].line)){
						 MessageBox::Show(gcnew String(INSERT_ERR_MSG.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 }
					 else{
						 Gcode_insert[Gcode_counter] = Gcode(mmGcode[NUD1AP], 1, selected_temperature, selected_filament_text);
						 Gcode_counter++;
						 Gcode_insert[Gcode_counter] = Gcode(mmGcode[NUD1AP], 2, selected_temperature, selected_filament_text);
						 Gcode_counter++;
					 }


					 // MessageBox::Show(" " + Decimal(Gcode_insert[Gcode_counter - 3].line) + ";" +  Decimal(Gcode_insert[Gcode_counter - 2].line) + ";" + Decimal(NUD1AP));
					 /*	 ESTO HAY QUE METERLO EN UN BACKGROWND WORKER
					 //for (int u = 0; u < Gcode_counter; u++) if (Gcode_insert[u].line>)
					 int pos = Gcode_counter, w=1;
					 if(Gcode_counter>=2){
					 while (w!=0){
					 w = 0;
					 for (int u = 0; u < Gcode_counter; u + 2) {
					 if (Gcode_insert[u].line > Gcode_insert[u + 2].line){
					 Gcode aux1 = Gcode_insert[u + 2];
					 Gcode aux2 = Gcode_insert[u + 3];
					 Gcode_insert[u + 2] = Gcode_insert[u];
					 Gcode_insert[u + 3] = Gcode_insert[u+1];
					 Gcode_insert[u] = aux1;
					 Gcode_insert[u + 1] = aux2;
					 w++;
					 MessageBox::Show("corregido" + Decimal(u));
					 }
					 }
					 }
					 }

					 }
					 */




					 /*}
					 else if (unitParam == "layer") {
					 Gcode_insert[Gcode_counter] = Gcode((int)numericUpDown1->Value, 1, selected_temperature, selected_filament_text);
					 Gcode_counter++;
					 Gcode_insert[Gcode_counter] = Gcode((int)numericUpDown1->Value, 2, selected_temperature, selected_filament_text);
					 Gcode_counter++;
					 }*/

					 for (int i = 0; i < Gcode_counter; i++) {
						 if (i == 0) textBox2->Text = gcnew String((MSG1.c_str() + Gcode_insert[i].material + MSG2.c_str() + (std::to_string(Gcode_insert[i].line).substr(0, 5)) + " mm, temp: " + Gcode_insert[i].value + "ºC").c_str());
						 else textBox2->Text += ("\r\n" + gcnew String((MSG1.c_str() + Gcode_insert[i].material + MSG2.c_str() + (std::to_string(Gcode_insert[i].line).substr(0, 5)) + " mm, temp: " + Gcode_insert[i].value + "ºC").c_str()));
						 i++;
					 }

 
				 }
				 else MessageBox::Show("Debe seleccionar un filamento");

				 enabledDrawing = 1;//permito que se vean las lineas del interior del rectángulo
				 //this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
				 this->pictureBox1->Refresh();
				 this->textBox4->Visible = true;
	}

			 /*writting old and new gcodes in the */
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

				 //	MessageBox::Show("lanzando escritura");
				 backgroundWorker2->RunWorkerAsync(2);
	}

	private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
				 writeGfile();

				 //MessageBox::Show("Fichero modificado con éxito");
	}

	private: System::Void backgroundWorker2_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
				 MessageBox::Show(gcnew String(ENDBOX_MSG.c_str()),"Filament Change Manager", MessageBoxButtons::OK,MessageBoxIcon::Asterisk);
				 if (SAVEFILE != "") SAVEFILE = "";

	}
			 

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 int acualGcodeCounter = Gcode_counter;
				 if (Gcode_counter >= 0) {
					 textBox2->Text = gcnew String(" ");
					 backgroundWorker3->RunWorkerAsync(3);

					 for (int i = 0; i < Gcode_counter; i++) {//vuelvo a imprimir todas las instrucciones de la consola (pero no saldrá la que hemos eliminado)
						 if (i == 0) textBox2->Text = gcnew String((MSG1.c_str() + Gcode_insert[i].material + MSG2.c_str() + (std::to_string(Gcode_insert[i].line).substr(0, 5)) + " mm, temp: " + Gcode_insert[i].value + "ºC").c_str());
						 else textBox2->Text += ("\r\n" + gcnew String((MSG1.c_str() + Gcode_insert[i].material + MSG2.c_str() + (std::to_string(Gcode_insert[i].line).substr(0, 5)) + " mm, temp: " + Gcode_insert[i].value + "ºC").c_str()));
						 i++;
					 }
				 }
				 else {
					 //MessageBox::Show("no hay nuevas instrucciones");
					 textBox2->Text = gcnew String(" ");
				 }
				 if (Gcode_counter == 0) {
					 textBox2->Text = gcnew String(" ");
					 saveAsToolStripMenuItem->Enabled = false;
					 saveToolStripMenuItem->Enabled = false;
					 groupBox3->Enabled = false;
				 }

				 if (acualGcodeCounter != Gcode_counter) {

					 //	 pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
					 pictureBox1->Refresh();
				 }




	}

			 /*To erase gcodes from the terminal with de "back" button*/
	private: System::Void backgroundWorker3_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
				 if (Gcode_counter >= 2) {
					 //MessageBox::Show("voy a quitar dos gcodes");
					 Gcode_insert[Gcode_counter] = Gcode_insert[Gcode_counter + 1];
					 Gcode_counter--;
					 Gcode_insert[Gcode_counter] = Gcode_insert[Gcode_counter + 1];
					 Gcode_counter--;

				 }
				 else if (Gcode_counter < 2) {
					 //MessageBox::Show("no quito más");
				 }

	}

			 /*To change extrusor temperature showed in textBox3*/
	private: void ComboBox1_SelectedIndexChanged(Object^ sender, System::EventArgs^ e) {
				 //String^ selected_filament_text2 = (String^)(comboBox1->SelectedItem);
				 std::string selection;
				 String^salida;

				 msclr::interop::marshal_context context;
				 selection = context.marshal_as<std::string>(comboBox1->SelectedItem->ToString());

				 for (int t = 0; t <= numColors; t++) {
					 if (selection == filamentArr[t].material) {
						 //salida = gcnew String((filamentArr[t].temperature + "ºC").c_str());
						 numericUpDown2->Value = Decimal(std::stoi(filamentArr[t].temperature));
						 // textBox3->Text = salida;
						 button2->Enabled = true;

						 break;
					 }
				 }

	}


	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 this->Controls->Add(pictureBox1);
				 Graphics^ g = e->Graphics;
				 Color myColor;
				 // myColor = Color::Gray;/*CAMBIAR ESTO POR EL INITIAL COLOR EN SYSTEM STRING*/

				 if (initialColor == "PLA Gris")	myColor = Color::Gray;
				 else if (initialColor == "PLA Amarillo")	myColor = Color::Yellow;
				 else if (initialColor == "PLA Azul") myColor = Color::Blue;
				 else if (initialColor == "PLA Blanco") myColor = Color::White;
				 else if (initialColor == "PLA Naranja") myColor = Color::Orange;
				 else if (initialColor == "PLA Rojo") myColor = Color::Red;
				 else if (initialColor == "PLA Negro") myColor = Color::Black;
				 else if (initialColor == "PLA Morado") myColor = Color::Purple;
				 else if (initialColor == "PLA Verde") myColor = Color::Green;
				 else if (initialColor == "PLA  Flex Amarillo") myColor = Color::Yellow;
				 else if (initialColor == "TCP-Flex 65") myColor = Color::DarkGray;
				 else if (initialColor == "ABS Blanco") myColor = Color::White;
				 else if (initialColor == "ABS Negro") myColor = Color::Black;
				 else if (initialColor == "ABS Rojo") myColor = Color::Red;
				 else if (initialColor == "ASA") myColor = Color::LightSlateGray;
				 else if (initialColor == "Sandstone LAYBRICK") myColor = Color::Khaki;
				 else if (initialColor == "Nylon Bridge") myColor = Color::LightGray;
				 else if (initialColor == "LAYWOOD-D3") myColor = Color::LightSalmon;
				 else if (initialColor == "FILAFLEX") myColor = Color::Aqua;
				 else if (initialColor == "Ultra Nylon") myColor = Color::Azure;
				 else myColor = Color::LightSlateGray;

				 Pen^ MyPen = gcnew Pen(myColor, 3.0f);
				 /*transformación de la medida obsoluta de la figura a relativa*/
				 int q = 230;
				 float LPP = q / MAXZ;; //Layers Per Pixel
				// MessageBox::Show("" + Decimal(LPP));

				 /*Este for, va a dibujar 200 líneas*/
				 int t = 233;
				 int s = 0;



				 for (int i = 0; i <= 233; i++) {
					 g->DrawLine(MyPen, 0, t, 45, t);
					 t--;

					 float changeline2 = (Gcode_insert[s].line * 230);
					 changeline2 /= MAXZ;
					

					 if (i == (int)changeline2 && s < Gcode_counter) {
						 //MessageBox::Show("i"+Decimal(i)+"Gcode: " + Decimal(Gcode_insert[s].line) + "ch1: " + Decimal(Gcode_insert[s].line * 230) + "max: " + Decimal(MAXZ) + "changeline2: " + Decimal(changeline2));
						 // MessageBox::Show("linea actual: " + i + "; cambio en: " + (int)changeline2   + "gcode: " + s);
						 if (Gcode_insert[s].material == "PLA Gris")	myColor = Color::Gray;
						 else if (Gcode_insert[s].material == "PLA Amarillo")	myColor = Color::Yellow;
						 else if (Gcode_insert[s].material == "PLA Azul") myColor = Color::Blue;
						 else if (Gcode_insert[s].material == "PLA Blanco") myColor = Color::White;
						 else if (Gcode_insert[s].material == "PLA Naranja") myColor = Color::Orange;
						 else if (Gcode_insert[s].material == "PLA Rojo") myColor = Color::Red;
						 else if (Gcode_insert[s].material == "PLA Negro") myColor = Color::Black;
						 else if (Gcode_insert[s].material == "TCP Flex")  myColor = Color::DarkGray;
						 else if (Gcode_insert[s].material == "PLA Morado") myColor = Color::Purple;
						 else if (Gcode_insert[s].material == "PLA Verde") myColor = Color::Green;
						 else if (Gcode_insert[s].material == "PLA  Flex Amarillo") myColor = Color::Yellow;
						 else if (Gcode_insert[s].material == "TCP-Flex 65") myColor = Color::DarkGray;
						 else if (Gcode_insert[s].material == "ABS Blanco") myColor = Color::White;
						 else if (Gcode_insert[s].material == "ABS Negro") myColor = Color::Black;
						 else if (Gcode_insert[s].material == "ABS Rojo") myColor = Color::Red;
						 else if (Gcode_insert[s].material == "ASA") myColor = Color::LightSlateGray;
						 else if (Gcode_insert[s].material == "Sandstone LAYBRICK") myColor = Color::Khaki;
						 else if (Gcode_insert[s].material == "Nylon Bridge") myColor = Color::LightGoldenrodYellow;
						 else if (Gcode_insert[s].material == "LAYWOOD-D3") myColor = Color::LightSalmon;
						 else if (Gcode_insert[s].material == "FILAFLEX") myColor = Color::Aqua;
						 else if (Gcode_insert[s].material == "Ultra Nylon") myColor = Color::Azure;
						 //else(myColor = Color::Cyan);
						 // MessageBox::Show("cambio de color"+ gcnew String(Gcode_insert[s].material.c_str()));
						 s += 2;
						 MyPen->Color = myColor;
					 }


				 }

				 int x = 0;
				 int y = 0;
				 int width = 45;
				 int height = 235;
				 // Draw rectangle to screen.
				 e->Graphics->DrawRectangle(System::Drawing::Pens::Black, x, y, width, height);

				 x++;
				 y++;
				 width = 43;
				 height = 233;
				 // Draw rectangle to screen.
				 e->Graphics->DrawRectangle(System::Drawing::Pens::White, x, y, width, height);




	}

	private: System::Void toolStripStatusLabel1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void archivoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
			 //rutina que abre un fichero gcode desde el menú abrir
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 //System::IO::StreamReader ^ sr = gcnew
					 //System::IO::StreamReader(openFileDialog1->FileName);

					 String^ filenname = System::IO::Path::GetFileName(openFileDialog1->FileName);
					 String^ path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);

					 msclr::interop::marshal_context context;
					 GGFILE = context.marshal_as<std::string>(openFileDialog1->FileName);

					 backgroundWorker1->RunWorkerAsync(1);  //starting background worker
					 textBox1->Text = (openFileDialog1->FileName);


					 comboBox1->Items->Add("err");
					 comboBox1->Items->Clear();
					 for (int u = 0; u < numColors; u++) comboBox1->Items->Add(gcnew String(filamentArr[u].material.c_str()));
					 filaments_load = 1;

					 String^ str3 = gcnew String(GGFILE.c_str());

					 //sr->Close();
					 this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
					 this->pictureBox1->Refresh();
				 }
	}

	private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 //al pulsar "save" se lanza la rutina de escritura en el fichero de destino
				 backgroundWorker2->RunWorkerAsync(2);
	}

	private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					 String^ path = System::IO::Path::GetDirectoryName(saveFileDialog1->FileName);

					 msclr::interop::marshal_context context;//convierto de string de sistema a std string
					 SAVEFILE = context.marshal_as<std::string>(saveFileDialog1->FileName);
					 //if (SAVEFILE == "") SAVEFILE == NFFILE;

					 //---ojo! mete lo del nombre de emergencia...
					 backgroundWorker2->RunWorkerAsync(2);	//lanza el back que escribe los gcodes en un nuevo fichero

					 String^ str3 = gcnew String(NFFILE.c_str());
					 //MessageBox::Show(str3);


				 }
	}

	private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

	}

	private: System::Void preferencesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void milimetersToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void inicialColorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 // rutina que carga los filamentos en el un comboBox nuevo
				 if (cargado_combobox_barra == 0) {
					 for (int u = 0; u < numColors; u++) toolStripComboBox1->Items->Add(gcnew String(filamentArr[u].material.c_str()));
					 cargado_combobox_barra = 1;
				 }
				 else if (cargado_combobox_barra == 3) {
					 toolStripComboBox1->Items->Clear();
					 for (int u = 0; u < numColors; u++) toolStripComboBox1->Items->Add(gcnew String(filamentArr[u].material.c_str()));
					 cargado_combobox_barra = 1;
				 }

	}

	private: System::Void toolStripComboBox1_Click(System::Object^  sender, System::EventArgs^  e) {

	}


	private: System::Void loadFilamentsFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {

					 //System::IO::StreamReader(openFileDialog2->FileName);//la llamada a sistema nos mete el path en fileName
					 String^ path = System::IO::Path::GetDirectoryName(openFileDialog2->FileName);

					 msclr::interop::marshal_context context;//convierto de string de sistema a std string
					 NFFILE = context.marshal_as<std::string>(openFileDialog2->FileName);

					 backgroundWorker5->RunWorkerAsync(5);  //lanza background worker que lee el fichero indicado en GGFILE2


					 //MessageBox::Show( str3 );
				 }
	}

	private: System::Void backgroundWorker5_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

				 cargado_combobox_barra = 3;
				 filaments_load = 0;
				 //MessageBox::Show("asdasd");
				 read_new_filaments_file();
				 saveProfiles();
	}



	private: System::Void preferencesToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 //este código es solo para actualizar los check:
				 if (language == "ENG") {
					 this->spanishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;
					 this->englishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
				 }
				 else {
					 this->spanishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
					 this->englishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;
				 }

				 if (unitParam == "mm") {
					 this->milimetersToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
					 this->slicedLayersToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;
				 }
				 else {
					 this->milimetersToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;
					 this->slicedLayersToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
				 }

	}

	private: System::Void englishToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 language = "ENG";

				 OPENCONTEXT_MSG = "Select .gcode file";
				 NEW_PERFILES_FILECONTEXT_MSG = "Select profiles file";
				 FILEBOX_MSG = "File";
				 FILAMENTBOX_MSG = "Filament";
				 STATUS_MSG = "Status";
				 if (unitParam != "mm")	ZLAYERBOX_MSG = "  Layer";
				 if (unitParam == "mm")	ZLAYERBOX_MSG = " Z mm";
				 ENDBOX_MSG = "File saved!";

				 //BUTTONS
				 OPEN_BTN = "Open";
				 ADDCHANGE_BTN = "Add filament change";
				 SAVE_BTN = "Save changes";

				 //CONSOLE
				 MSG1 = "Filament change to";
				 MSG2 = ", at ";

				 //STRIP MENU
				 FILE_MSG = "File";
				 OPEN_MSG = "Open";
				 SAVE_MSG = "Save";
				 SAVEAS_MSG = "Save as";
				 EXIT_MSG = "Exit";
				 PREFERENCES_MSG = "Preferences";
				 LANGUAGE_MSG = "Language";
				 ENG_MSG = "English";
				 ESP_MSG = "Spanish";
				 MM_MSG = "Millimeters";

				 UNITS_MSG = "Units";
				 INITIAL_COLOR_MSG = "Initial color";
				 LOAD_FILAMENTS_FILE_MSG = "Load filaments file";
				 SLICED_LAYERS_MSG = "Sliced layers";
				 HELP_MSG = "Help";
				 CONTEXT_MSG = "Documentation";
				 ABOUT_MSG = "About";
				 COMBOBOX1_MSG = "-Select filament-";
				 READ_ERR_MSG = "A file previously modified can't be opened";
				 INSERT_ERR_MSG = "Upper changes should be deleted in order to insert this command";
				 FIL_ERR_MSG = "please, select a filament profile";
				 LangChange();


	}

	private: System::Void spanishToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 language = "ESP";
				 OPENCONTEXT_MSG = "Seleccione un fichero .gcode";
				 NEW_PERFILES_FILECONTEXT_MSG = "Seleccione fichero de perfiles";
				 FILEBOX_MSG = "Fichero";
				 FILAMENTBOX_MSG = "Filamento";
				 STATUS_MSG = "Cambios introducidos";
				 if (unitParam != "mm")	ZLAYERBOX_MSG = " Capa";
				 ENDBOX_MSG = "Fichero guardado con éxito";

				 //BOTONES
				 OPEN_BTN = "Abrir";
				 ADDCHANGE_BTN = "Añadir cambio";
				 SAVE_BTN = "Guardar cambios";

				 //CONSOLA
				 MSG1 = "Nuevo filamento ";
				 MSG2 = ", altura ";

				 //BARRA DE HERRAMIENTAS
				 FILE_MSG = "Archivo";
				 OPEN_MSG = "Abrir";
				 SAVE_MSG = "Guardar";
				 SAVEAS_MSG = "Guardar como";
				 EXIT_MSG = "Salir";
				 PREFERENCES_MSG = "Preferencias";
				 LANGUAGE_MSG = "Lenguaje";
				 ENG_MSG = "Inglés";
				 ESP_MSG = "Español";
				 UNITS_MSG = "Unidades";
				 MM_MSG = "Milimetros";

				 INITIAL_COLOR_MSG = "Color inicial";
				 LOAD_FILAMENTS_FILE_MSG = "Cargar perfiles";
				 SLICED_LAYERS_MSG = "Capas";
				 HELP_MSG = "Ayuda";
				 CONTEXT_MSG = "Documentacion";
				 ABOUT_MSG = "Sobre FCM";
				 COMBOBOX1_MSG = "-Seleccione un filamento-";
				 READ_ERR_MSG = "No se puede abrir un fichero modificado anteriormente";
				 INSERT_ERR_MSG = "Los cambios superiores deben ser eliminados para poder introducir este comando";
				 FIL_ERR_MSG = "porfavor, seleccione un filamento";
				 LangChange();


	}

	private: void LangChange() {
				 this->groupBox1->Text = (gcnew String(FILEBOX_MSG.c_str()));
				 this->groupBox2->Text = gcnew String(FILAMENTBOX_MSG.c_str());
				 if (unitParam == "layer")  groupBox4->Text = gcnew String(ZLAYERBOX_MSG.c_str());
				 else if (unitParam == "mm")  groupBox4->Text = " Z mm";
				 this->groupBox3->Text = gcnew String(STATUS_MSG.c_str());

				 this->openFileDialog1->Title = gcnew String(OPENCONTEXT_MSG.c_str());
				 this->openFileDialog2->Title = gcnew String(NEW_PERFILES_FILECONTEXT_MSG.c_str());

				 this->button1->Text = gcnew String(OPEN_BTN.c_str());
				 this->button2->Text = gcnew String(ADDCHANGE_BTN.c_str());
				 this->button3->Text = gcnew String(SAVE_BTN.c_str());

				 this->archivoToolStripMenuItem->Text = gcnew String(FILE_MSG.c_str());
				 this->openToolStripMenuItem->Text = gcnew String(OPEN_MSG.c_str());
				 this->saveToolStripMenuItem->Text = gcnew String(SAVE_MSG.c_str());
				 this->saveAsToolStripMenuItem->Text = gcnew String(SAVEAS_MSG.c_str());
				 this->exitToolStripMenuItem->Text = gcnew String(EXIT_MSG.c_str());
				 this->preferencesToolStripMenuItem->Text = gcnew String(PREFERENCES_MSG.c_str());
				 this->languageToolStripMenuItem->Text = gcnew String(LANGUAGE_MSG.c_str());
				 this->unitsToolStripMenuItem->Text = gcnew String(UNITS_MSG.c_str());
				 this->inicialColorToolStripMenuItem->Text = gcnew String(INITIAL_COLOR_MSG.c_str());
				 this->loadFilamentsFileToolStripMenuItem->Text = gcnew String(LOAD_FILAMENTS_FILE_MSG.c_str());
				 this->slicedLayersToolStripMenuItem->Text = gcnew String(SLICED_LAYERS_MSG.c_str());
				 this->helpToolStripMenuItem->Text = gcnew String(HELP_MSG.c_str());
				 this->contextToolStripMenuItem->Text = gcnew String(CONTEXT_MSG.c_str());
				 this->aboutToolStripMenuItem->Text = gcnew String(ABOUT_MSG.c_str());
				 this->comboBox1->Text = gcnew String(COMBOBOX1_MSG.c_str());

				 this->englishToolStripMenuItem->Text = gcnew String(ENG_MSG.c_str());
				 this->spanishToolStripMenuItem->Text = gcnew String(ESP_MSG.c_str());
				 this->milimetersToolStripMenuItem->Text = gcnew String(MM_MSG.c_str());

				 saveConfig();

	}

	private: System::Void toolStripComboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

				 //convertir a string para poder compararlo con los nombres guardados en el array de colores
				 msclr::interop::marshal_context context;
				 initialColor = context.marshal_as<std::string>(toolStripComboBox1->SelectedItem->ToString());
				 // MessageBox::Show(gcnew String(CONTEXT_MSG.c_str())); //imprime el color seleccionado
				 saveConfig();
				 pictureBox1->Refresh();

	}

	private: System::Void milimetersToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 quieto = 1;
				 if (unitParam != "mm") {
					 float lastValue = (float)numericUpDown1->Value;
					 unitParam = "mm";
					 groupBox4->Text = L" Z mm";
					 numericUpDown1->Value = 0;
					 numericUpDown1->DecimalPlaces = 2;
					 if (NUD1AP > 1) numericUpDown1->Increment = Decimal(mmGcode[3] + 0.01 - mmGcode[2]);
					 // if (NUD1AP <= 1) numericUpDown1->Increment = Decimal(mmGcode[1] + 0.01 - mmGcode[0]);
					 numericUpDown1->Maximum = Decimal(MAXZ);

					 //MessageBox::Show("c: " + Decimal((firstLayerHeight - layerHeight)));
					 if (Zlevels < 1) numericUpDown1->Value = 0;
					 else if (lastValue == Zlevels - 1) numericUpDown1->Value = Decimal(MAXZ);
					 else if (lastValue <  Zlevels - 1) numericUpDown1->Value = Decimal(mmGcode[NUD1AP]);
					 quieto = 0;
					 //MessageBox::Show("capas" + Decimal(Zlevels) + ", grosor de capa: " + Decimal(layerHeight) + ", altura" + Decimal(Zlevels*layerHeight) + "; "+numericUpDown1->Value);
					 saveConfig();
				 }
	}


	private: System::Void slicedLayersToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 quieto = 1;
				 numericUpDown1->Maximum = Zlevels - 1;

				 if (unitParam != "layer") {
					 unitParam = "layer";
					 float lastValue = (float)numericUpDown1->Value;
					 groupBox4->Text = gcnew String(ZLAYERBOX_MSG.c_str());
					 numericUpDown1->Value = Zlevels - 1;
					 numericUpDown1->Maximum = Zlevels - 1;
					 numericUpDown1->DecimalPlaces = 0;
					 numericUpDown1->Increment = Decimal(1);

					 if (Zlevels < 1){
						 numericUpDown1->Value = 0;
						 NUD1LV = 0;

					 }
					 else if (lastValue == MAXZ) {
						 numericUpDown1->Value = Zlevels - 1;
						 NUD1LV = Zlevels - 1;

					 }
					 else{
						 numericUpDown1->Value = NUD1LV;

					 }
					 quieto = 0;

					 saveConfig();
				 }

	}

	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
	}

	private: System::Void contextToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 int i = system("start http://www.leon-3d.es/wp-content/uploads/2016/07/Manual-FMC.pdf");
				 //int i = system("C:/LEON3D/Filament_Change_Manager/Manual.pdf");
	}

	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 //OJO!! no tocar los espacios, tabulan el mensaje
				 MessageBox::Show("                rev.02A \r\n      Copyright® 2016 \n  LEON 3D IMPRESION S.L.         \n       All rights reserved     ", gcnew String(ABOUT_MSG.c_str()), MessageBoxButtons::OK,  MessageBoxIcon::Asterisk);
				 // MessageBox::Show("The calculations are complete","My Application", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);



	}

	private: System::Void openFileDialog2_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}

	private: System::Void groupBox5_Enter(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void comboBox1_DropDown(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void comboBox1_Click(System::Object^  sender, System::EventArgs^  e) {
				 comboBox1->Items->Add("err");
				 comboBox1->Items->Clear();
				 for (int u = 0; u < numColors; u++) comboBox1->Items->Add(gcnew String(filamentArr[u].material.c_str()));
				 filaments_load = 1;
	}
	private: System::Void webSiteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				 int i = system("START https://www.leon-3d.es/ ");

	}
	};

}

