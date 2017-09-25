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
#include <msclr\marshal_cppstd.h>
#include <objbase.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <windows.h> 


#pragma once

std::string FIRMWARE;
std::string comandoString;

int counter = -1;
std::string language;
std::string openCounter;
std::string selectedPrinter;
int error, err_mod, num, comboBoxUsed, avrout, lock;

/**GROUPBOX**/
std::string OPENCONTEXT_MSG = "Select firmware file";
std::string FILEBOX_MSG = "File";
std::string SERIALBOX_MSG = "Serial port";
std::string STATUS_MSG = "Status";
std::string END_MSG = "Firmware updated";

/**BUTTONS**/
std::string OPEN_BTN = "Open";
std::string UPDATE_BTN = "Update firmware";

/**STRIP MENU**/
std::string FILE_MSG = "File";
std::string OPEN_MSG = "Open";
std::string EXIT_MSG = "Exit";
std::string PRINTER_MSG = "Printer";
std::string LANGUAGE_MSG = "Language";
std::string ENG_MSG = "English";
std::string ESP_MSG = "Spanish";
std::string HELP_MSG = "Help";
std::string CONTEXT_MSG = "Documentation";
std::string ABOUT_MSG = "About";
std::string COM_ERR_MSG = "Invalid serial port";
std::string ERR_MSG = "There was imposible to upload firmware";
std::string BADFIRM_ERR_MSG = "Selected firmware is not compatible with the printer model";

void load_config();
void save_config();
void LangChange();
void result();
void clean();
void crearBat();

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::ComponentModel;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			if (language == "ENG") {

				/**GROUPBOX**/
				OPENCONTEXT_MSG = "Select firmware file";
				FILEBOX_MSG = "File";
				SERIALBOX_MSG = "Serial port";
				STATUS_MSG = "Status";
				END_MSG = "Firmware updated";

				/**BUTTONS**/
				OPEN_BTN = "Open";
				UPDATE_BTN = "Update firmware";

				/**STRIP MENU**/
				FILE_MSG = "File";
				OPEN_MSG = "Open";
				EXIT_MSG = "Exit";
				PRINTER_MSG = "Printer";
				LANGUAGE_MSG = "Language";
				ENG_MSG = "English";
				ESP_MSG = "Spanish";
				HELP_MSG = "Help";
				CONTEXT_MSG = "Documentation";
				ABOUT_MSG = "About";
				COM_ERR_MSG = "Invalid serial port";
				language = "ENG";
				ERR_MSG = "firmware coud not be updated";
				BADFIRM_ERR_MSG = "Selected firmware is not compatible with the printer model";
			}
			else{

				/**GROUPBOX**/
				OPENCONTEXT_MSG = "Seleccione un firmware";
				FILEBOX_MSG = "Fichero";
				SERIALBOX_MSG = "Puerto serie";
				STATUS_MSG = "Estado";
				END_MSG = "Firmware actualizado";

				/**BUTTONS**/
				OPEN_BTN = "Abrir";
				UPDATE_BTN = "Grabar";

				/**STRIP MENU**/
				FILE_MSG = "Fichero";
				OPEN_MSG = "Abrir";
				EXIT_MSG = "Salir";
				PRINTER_MSG = "Impresora";
				LANGUAGE_MSG = "Idioma";
				ENG_MSG = "Inglés";
				ESP_MSG = "Español";
				HELP_MSG = "Ayuda";
				CONTEXT_MSG = "Documentacion";
				ABOUT_MSG = "Sobre Firmware updater";
				COM_ERR_MSG = "Puerto serie erroneo";
				language = "ESP";
				ERR_MSG = "imposible al actualizar firmware";
				BADFIRM_ERR_MSG = "El firmware seleccionado no es compatible con el modelo de impresora";
			}


			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::ComboBox^  comboBox1;


	private: System::Windows::Forms::Button^  button2;
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;


	private: System::Windows::Forms::OpenFileDialog^  OpenFileDialog1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  languageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  englishToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  spanishToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  preferencesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lEGIOToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lIONToolStripMenuItem;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;






	private: System::ComponentModel::IContainer^  components;
			
	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->OpenFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->spanishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->preferencesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lEGIOToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lIONToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(294, 46);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = gcnew String(FILEBOX_MSG.c_str());
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(236, 14);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(46, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = gcnew String(OPEN_BTN.c_str());
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(8, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(222, 20);
			this->textBox1->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Location = System::Drawing::Point(312, 27);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(80, 46);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = gcnew String(SERIALBOX_MSG.c_str());
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(10, 15);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(60, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->DropDown += gcnew System::EventHandler(this, &MyForm::comboBox1_DropDown);
			this->comboBox1->SelectedValueChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedValueChanged);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(257, 19);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 24);
			this->button2->TabIndex = 4;
			this->button2->Text = gcnew String(UPDATE_BTN.c_str());
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(8, 19);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(222, 24);
			this->progressBar1->TabIndex = 5;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(56, 131);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(278, 50);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->progressBar1);
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Location = System::Drawing::Point(12, 72);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(380, 53);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = gcnew String(STATUS_MSG.c_str());
			// 
			// backgroundWorker1
			// 
			//this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			//this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged_1);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// OpenFileDialog1
			// 
			this->OpenFileDialog1->DefaultExt = L"(*.hex)|*.hex";
			this->OpenFileDialog1->Filter = L"(*.hex)|*.hex";
			this->OpenFileDialog1->InitialDirectory = L"C:\\Users";
			this->OpenFileDialog1->ShowReadOnly = true;
			this->OpenFileDialog1->ValidateNames = false;
			this->OpenFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::Open_FileOk);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->languageToolStripMenuItem, this->preferencesToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(405, 24);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->toolStripSeparator1, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = gcnew String(FILE_MSG.c_str());
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = gcnew String(OPEN_MSG.c_str());
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(100, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->exitToolStripMenuItem->Text = gcnew String(EXIT_MSG.c_str());
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->spanishToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->languageToolStripMenuItem->Text = gcnew String(LANGUAGE_MSG.c_str());
			this->languageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::languageToolStripMenuItem_Click);
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->englishToolStripMenuItem->Text = gcnew String(ENG_MSG.c_str());
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::englishToolStripMenuItem_Click);
			// 
			// spanishToolStripMenuItem
			// 
			this->spanishToolStripMenuItem->Name = L"spanishToolStripMenuItem";
			this->spanishToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->spanishToolStripMenuItem->Text = gcnew String(ESP_MSG.c_str());
			this->spanishToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::spanishToolStripMenuItem_Click);
			// 
			// preferencesToolStripMenuItem
			// 
			this->preferencesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->lEGIOToolStripMenuItem,
					this->lIONToolStripMenuItem
			});
			this->preferencesToolStripMenuItem->Name = L"preferencesToolStripMenuItem";
			this->preferencesToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->preferencesToolStripMenuItem->Text = gcnew String(PRINTER_MSG.c_str());

			// 
			// lEGIOToolStripMenuItem
			// 

			if (selectedPrinter == "LEGIO") {
				this->lIONToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;
				this->lEGIOToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			}
			else {
				this->lIONToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
				this->lEGIOToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;
			}
			this->lEGIOToolStripMenuItem->Name = L"lEGIOToolStripMenuItem";
			this->lEGIOToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->lEGIOToolStripMenuItem->Text = L"LEGIO";
			this->lEGIOToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::lEGIOToolStripMenuItem_Click);
			// 
			// lIONToolStripMenuItem
			// 


			this->lIONToolStripMenuItem->Name = L"lIONToolStripMenuItem";
			this->lIONToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->lIONToolStripMenuItem->Text = L"LION PRO";
			this->lIONToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::lIONToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->helpToolStripMenuItem1,
					this->aboutToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = gcnew String(HELP_MSG.c_str());
			// 
			// helpToolStripMenuItem1
			// 
			this->helpToolStripMenuItem1->Name = L"helpToolStripMenuItem1";
			this->helpToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->helpToolStripMenuItem1->Text = gcnew String(CONTEXT_MSG.c_str());
			this->helpToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::contextToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = gcnew String(ABOUT_MSG.c_str());
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			//
			//backgroundWorker2
			//
			this->backgroundWorker2->WorkerReportsProgress = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker2_DoWork);
			this->backgroundWorker2->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker2_ProgressChanged);
			this->backgroundWorker2->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker2_RunWorkerCompleted);

			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(405, 187);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"FW updater rev_0H";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void languageToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 /* if (language == "ENG") {
				 this->spanishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;
				 this->englishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
				 }
				 else {
				 this->spanishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->englishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;
				 }*/
	}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (OpenFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 err_mod = 0;

					 String^ filenname = System::IO::Path::GetFileName(OpenFileDialog1->FileName);
					 String^ path = System::IO::Path::GetDirectoryName(OpenFileDialog1->FileName);

					 msclr::interop::marshal_context context;
					 FIRMWARE = context.marshal_as<std::string>(OpenFileDialog1->FileName);

					 String^ str3 = gcnew String(FIRMWARE.c_str());
					 // MessageBox::Show( str3 );


					 /* if (!err_mod) {
					 textBox1->Text = (filenname);
					 this->button2->Enabled = true;

					 }
					 }*/
					 if (!err_mod) {
						 std::size_t found = FIRMWARE.find(selectedPrinter);
						 if (found != std::string::npos){
							 avrout = 1;//OJO ESTO ANTES ERA UN 1
							 textBox1->Text = (filenname);
							 this->button2->Enabled = true;
						 }
						 else{

							 MessageBox::Show(gcnew String(BADFIRM_ERR_MSG.c_str()), "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
							 this->button2->Enabled = false;
							 textBox1->Text = ("");
						 }
					 }
				 }
	}


	private: System::Void toolStripDropDownButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void Open_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
				 array<String^>^ serialPorts = nullptr;
				 try
				 {
					 // Get a list of serial port names.
					 serialPorts = SerialPort::GetPortNames();
				 }
				 catch (Win32Exception^ ex)
				 {
					 Console::WriteLine(ex->Message);
				 }

				 Console::WriteLine("The following serial ports were found:");
				 comboBox1->Items->Add("err");
				 comboBox1->Items->Clear();
				 // Display each port name to the console.
				 for each(String^ port in serialPorts)
				 {
					 //Console::WriteLine(port);
					 comboBox1->Items->Add(port);
					 comboBox1->SelectedItem = port;
				 }
				  
	}



	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
	}

	private: System::Void contextToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 int i = system("start http://www.leon-3d.es/wp-content/uploads/2016/07/Manual_FW-Updater.pdf");
					}

	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 //OJO!! no tocar los espacios, tabulan el mensaje
				 MessageBox::Show("                rev. 0H \r\n      Copyright® 2016 \n  LEON 3D IMPRESION S.L. \n       All rights reserved    ");
				 // MessageBox::Show("The calculations are complete","My Application", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);

	}

	private: System::Void englishToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 // this->spanishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;
				 // this->englishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
				 /**GROUPBOX**/
				 OPENCONTEXT_MSG = "Select firmware file";
				 FILEBOX_MSG = "File";
				 SERIALBOX_MSG = "Serial port";
				 STATUS_MSG = "Status";
				 END_MSG = "Firmware updated";

				 /**BUTTONS**/
				 OPEN_BTN = "Open";
				 UPDATE_BTN = "Update firmware";

				 /**STRIP MENU**/
				 FILE_MSG = "File";
				 OPEN_MSG = "Open";
				 EXIT_MSG = "Exit";
				 PRINTER_MSG = "Printer";
				 LANGUAGE_MSG = "Language";
				 ENG_MSG = "English";
				 ESP_MSG = "Spanish";
				 HELP_MSG = "Help";
				 CONTEXT_MSG = "Documentation";
				 ABOUT_MSG = "About";
				 COM_ERR_MSG = "Invalid serial port";
				 BADFIRM_ERR_MSG = "The firmware that you selected is not compatible with this printer model";
				 language = "ENG";
				 ERR_MSG = "Firmware coud not be updated";
				 LangChange();
	}

	private: System::Void spanishToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 // this->spanishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
				 // this->englishToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;


				 /**GROUPBOX**/
				 OPENCONTEXT_MSG = "Seleccione un firmware";
				 FILEBOX_MSG = "Fichero";
				 SERIALBOX_MSG = "Puerto serie";
				 STATUS_MSG = "Estado";
				 END_MSG = "Firmware actualizado";

				 /**BUTTONS**/
				 OPEN_BTN = "Abrir";
				 UPDATE_BTN = "Grabar";

				 /**STRIP MENU**/
				 FILE_MSG = "Fichero";
				 OPEN_MSG = "Abrir";
				 EXIT_MSG = "Salir";
				 PRINTER_MSG = "Impresora";
				 LANGUAGE_MSG = "Idioma";
				 ENG_MSG = "Inglés";
				 ESP_MSG = "Español";
				 HELP_MSG = "Ayuda";
				 CONTEXT_MSG = "Documentacion";
				 ABOUT_MSG = "Sobre Firmware updater";
				 COM_ERR_MSG = "Seleccione un puerto serie";
				 language = "ESP";
				 BADFIRM_ERR_MSG = "El firmware seleccionado no es compatible con el modelo de impresora";
				 ERR_MSG = "imposible actualizar el software";
				 LangChange();


	}

	private: void LangChange() {
				 // MessageBox::Show(gcnew String(language.c_str()));
				 this->groupBox1->Text = gcnew String(FILEBOX_MSG.c_str());
				 this->groupBox2->Text = gcnew String(SERIALBOX_MSG.c_str());
				 this->groupBox3->Text = gcnew String(STATUS_MSG.c_str());
				 this->fileToolStripMenuItem->Text = gcnew String(FILE_MSG.c_str());
				 this->openToolStripMenuItem->Text = gcnew String(OPEN_MSG.c_str());
				 this->exitToolStripMenuItem->Text = gcnew String(EXIT_MSG.c_str());
				 this->languageToolStripMenuItem->Text = gcnew String(LANGUAGE_MSG.c_str());
				 this->englishToolStripMenuItem->Text = gcnew String(ENG_MSG.c_str());
				 this->spanishToolStripMenuItem->Text = gcnew String(ESP_MSG.c_str());
				 this->preferencesToolStripMenuItem->Text = gcnew String(PRINTER_MSG.c_str());
				 this->helpToolStripMenuItem->Text = gcnew String(HELP_MSG.c_str());
				 this->helpToolStripMenuItem1->Text = gcnew String(CONTEXT_MSG.c_str());
				 this->aboutToolStripMenuItem->Text = gcnew String(ABOUT_MSG.c_str());
				 this->button2->Text = gcnew String(UPDATE_BTN.c_str());
				 this->button1->Text = gcnew String(OPEN_BTN.c_str());
				  
				 save_config();

	}



	private: System::Void lEGIOToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 selectedPrinter = "LEGIO";
				 this->lIONToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;
				 this->lEGIOToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
				 save_config();

				 this->button2->Enabled = false;
				 textBox1->Text = ("");
				 FIRMWARE == "";
	}

	private: System::Void lIONToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				 selectedPrinter = "LION";
				 this->lIONToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->lEGIOToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;
				 save_config();



				 this->button2->Enabled = false;
				 textBox1->Text = ("");
				 FIRMWARE == "";

	}

	private: System::Void comboBox1_DropDown(System::Object^  sender, System::EventArgs^  e) {
				 array<String^>^ serialPorts = nullptr;
				 try
				 {
					 // Get a list of serial port names.
					 serialPorts = SerialPort::GetPortNames();
				 }
				 catch (Win32Exception^ ex)
				 {
					 Console::WriteLine(ex->Message);
				 }

				 Console::WriteLine("The following serial ports were found:");
				 comboBox1->Items->Add("err");
				 comboBox1->Items->Clear();
				 // Display each port name to the console.
				 for each(String^ port in serialPorts)
				 {
					 //Console::WriteLine(port);
					 comboBox1->Items->Add(port);

				 }

	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 /*
			
				   array<String^>^ serialPorts = nullptr;
				 try{
					 serialPorts = SerialPort::GetPortNames();
				 }
				 catch (Win32Exception^ ex){ 
				 }
  
				 comboBox1->Items->Clear();
			 
				 for each(String^ port in serialPorts)
				 { 
					 comboBox1->Items->Add(port);
					 comboBox1->SelectedItem = port;
				  	 }*/
				 

				 //avrdude -C avrdude.conf -p at90usb1286 -c avr109 -P \\.\COM6 -b 115200 -D -U flash:w:091-11005-001.hex:i
				 if (comboBoxUsed != 0){
					 msclr::interop::marshal_context context;
					 std::string com = context.marshal_as<std::string>(comboBox1->SelectedItem->ToString());

					 if (com.size() == 4){
						 com = com.substr(3, 1);
					 }
					 else if (com.size() == 5){
						 com = com.substr(3, 2);
					 }

					 //MessageBox::Show(gcnew String(com.c_str()));
					 num = std::stoi(com);
					  
					 this->button2->Enabled = false;
					 backgroundWorker1->RunWorkerAsync(1);  //starting background worker
					 backgroundWorker2->RunWorkerAsync();
				 }
				 else{
					 MessageBox::Show(gcnew String(COM_ERR_MSG.c_str()), "Warning", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				 }

	}

	private: System::Void comboBox1_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 comboBoxUsed++;

	}


	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
				 
				 avrout = -1;

				 // std::string fileName1 = "091-11005-001.hex";
				 String^ a = gcnew String(FIRMWARE.c_str());

				 String^ comando = (gcnew String("@echo off\nCLS\nmode CON: COLS=15 LINES=2\n@echo Please wait...\nCMD /C (\"C:\\Program Files (x86)\\LEON3D\\FW updater\\avrdude.exe\" -C \"C:\\Program Files (x86)\\LEON3D\\FW updater\\avrdude.conf\" -p at90usb1286 -c avr109 -P //./COM" + num + " -b 115200 -D -U flash:w:\"" + a + "\":i) 2>\"C:/LEON3D/FW_updater/test.inf\"\nCLS\n@exit"));
		//"C:\Program Files (x86)\LEON3D\FW updater\avrdude.exe"		
				 msclr::interop::marshal_context context2;
				 comandoString = context2.marshal_as<std::string>(comando);
				 // Console::WriteLine(comando);
				 const char * comandoChar = comandoString.c_str();
				 crearBat();
				 // int i = system(comandoChar);
				 // WinExec((LPCSTR)comandoChar, SW_SHOWNORMAL);

				 STARTUPINFO si = { sizeof(STARTUPINFO) };
				 PROCESS_INFORMATION pi;
				 int o = CreateProcess(L"C:\\LEON3D\\FW_updater\\UploadApp.bat",
					 NULL,
					 NULL, NULL, CREATE_NO_WINDOW, 0, NULL, NULL, &si, &pi);



	}

	private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
				 
				// result();
				 // MessageBox::Show(gcnew String(END_MSG.c_str()), "Printer updater", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				// progressBar1->Value = 0;

	}



	private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
				 lock = 0;
				 avrout = -1;
				 for (int i = 0; i <= 100; i++)
				 {
					 backgroundWorker2->ReportProgress(i);
					 if (i >30 && avrout<2){
						 if (i>90) lock = 1;
						 result();
						// MessageBox::Show("out" + Decimal(avrout));
						 if (avrout == -1){
							 backgroundWorker2->ReportProgress(0);
							 MessageBox::Show(gcnew String(ERR_MSG.c_str()), "Error.", MessageBoxButtons::OK, MessageBoxIcon::Error);
							 backgroundWorker2->ReportProgress(0);
							 break;
						 }
					 }
						 System::Threading::Thread::Sleep(70);
				 

				 if (avrout == 10){

					 backgroundWorker2->ReportProgress(100);
					 MessageBox::Show(gcnew String(END_MSG.c_str()), "Printer updater", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
					 backgroundWorker2->ReportProgress(0);
					 break;
				 }if (avrout == 2){
					 MessageBox::Show(gcnew String(ERR_MSG.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 backgroundWorker2->ReportProgress(0);
					 break;
				 }if (avrout == 3){
					 MessageBox::Show(gcnew String(COM_ERR_MSG.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

					 backgroundWorker2->ReportProgress(0);
					 break;

				 } 
				 //akí vamos a llamar a la rutina que parsea el fichero de salida y busca "ERR" o "OK"
				 }
	}

	private: System::Void backgroundWorker2_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
				 progressBar1->Value = e->ProgressPercentage;
	}

	private: System::Void backgroundWorker2_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
				 this->button2->Enabled = true;
				 //progressBar1->ForeColor = System::Drawing::Color::Red;
				 if (avrout == -1){
					//  MessageBox::Show(gcnew String(ERR_MSG.c_str()), "Error2", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 
					  
				 }
				 else{clean();}

				
				 // else{ MessageBox::Show("AVR END"); }
				 
	}

	};
}
