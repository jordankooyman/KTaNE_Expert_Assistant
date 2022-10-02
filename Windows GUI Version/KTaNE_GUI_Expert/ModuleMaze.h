/**********************************************************
   file: ModuleMaze.h
 author: Jordan Kooyman
purpose: Contains the Maze module window and the calculations for navigating a given maze between two specified points as member functions
**********************************************************/
#pragma once

namespace KTaNEGUIExpert {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ModuleMaze
	/// </summary>
	public ref class ModuleMaze : public System::Windows::Forms::Form
	{
	private:
		cli::array<int, 3>^ Clicked; // Stage (3), Count (1 or 2), X/Y (2)
		cli::array<bool, 2>^ Lines; // Which Lines to show on the Maze
		int stage; // 1: Reference Marks  2: White Square  3: Red Triangle
		int counter; // How many inputs have been given for current stage
		int mazeID;
	private: System::Windows::Forms::Label^ mazeBoxReference1;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;






	private: System::Windows::Forms::Label^ mazeBoxReference2;

	public:
		ModuleMaze(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Clicked = gcnew cli::array<int, 3>(3, 2, 2);
			Lines = gcnew cli::array<bool, 2>(13,13);
			stage = 0;
			counter = 0;
			mazeID = -1;
			for (int i = 0; i < 3; i++) // Initialize array to 0
			{
				for (int j = 0; j < 2; j++)
				{
					for (int k = 0; k < 2; k++)
					{
						Clicked[i, j, k] = 0;
					}
				}
			}
			for (int i = 0; i < 13; i++) // Initialize array to false
			{
				for (int j = 0; j < 13; j++)
				{
					Lines[i, j] = false;
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ModuleMaze()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ mazeBox;
	private: System::Windows::Forms::Label^ mazeLine156;
	protected:

	protected:

	private: System::Windows::Forms::Label^ mazeLine145;

	private: System::Windows::Forms::Label^ mazeLine134;

	private: System::Windows::Forms::Label^ mazeLine123;
	private: System::Windows::Forms::Label^ mazeLine112;





	private: System::Windows::Forms::Label^ mazeBox66;

	private: System::Windows::Forms::Label^ mazeBox56;

	private: System::Windows::Forms::Label^ mazeBox46;

	private: System::Windows::Forms::Label^ mazeBox36;

	private: System::Windows::Forms::Label^ mazeBox26;

	private: System::Windows::Forms::Label^ mazeBox16;
	private: System::Windows::Forms::Label^ mazeBox65;


	private: System::Windows::Forms::Label^ mazeBox55;

	private: System::Windows::Forms::Label^ mazeBox45;

	private: System::Windows::Forms::Label^ mazeBox35;

	private: System::Windows::Forms::Label^ mazeBox25;

	private: System::Windows::Forms::Label^ mazeBox15;
	private: System::Windows::Forms::Label^ mazeBox64;


	private: System::Windows::Forms::Label^ mazeBox54;

	private: System::Windows::Forms::Label^ mazeBox44;

	private: System::Windows::Forms::Label^ mazeBox34;

	private: System::Windows::Forms::Label^ mazeBox24;

	private: System::Windows::Forms::Label^ mazeBox14;
	private: System::Windows::Forms::Label^ mazeBox63;


	private: System::Windows::Forms::Label^ mazeBox53;

	private: System::Windows::Forms::Label^ mazeBox43;

	private: System::Windows::Forms::Label^ mazeBox33;

	private: System::Windows::Forms::Label^ mazeBox23;

	private: System::Windows::Forms::Label^ mazeBox13;
	private: System::Windows::Forms::Label^ mazeBox62;


	private: System::Windows::Forms::Label^ mazeBox52;

	private: System::Windows::Forms::Label^ mazeBox42;

	private: System::Windows::Forms::Label^ mazeBox32;

	private: System::Windows::Forms::Label^ mazeBox22;

	private: System::Windows::Forms::Label^ mazeBox12;
	private: System::Windows::Forms::Label^ mazeBox61;


	private: System::Windows::Forms::Label^ mazeBox51;

	private: System::Windows::Forms::Label^ mazeBox41;

	private: System::Windows::Forms::Label^ mazeBox31;

	private: System::Windows::Forms::Label^ mazeBox21;

	private: System::Windows::Forms::Label^ mazeBox11;
private: System::Windows::Forms::Label^ mazeLineB56;


private: System::Windows::Forms::Label^ mazeLineB45;

private: System::Windows::Forms::Label^ mazeLineB34;

private: System::Windows::Forms::Label^ mazeLineB23;

private: System::Windows::Forms::Label^ mazeLineB12;

private: System::Windows::Forms::Label^ mazeLineA6;

private: System::Windows::Forms::Label^ mazeLineA5;

private: System::Windows::Forms::Label^ mazeLineA4;

private: System::Windows::Forms::Label^ mazeLineA3;

private: System::Windows::Forms::Label^ mazeLineA2;


private: System::Windows::Forms::Label^ mazeLineA1;
private: System::Windows::Forms::Label^ mazeLine956;




private: System::Windows::Forms::Label^ mazeLine945;

private: System::Windows::Forms::Label^ mazeLine934;

private: System::Windows::Forms::Label^ mazeLine923;

private: System::Windows::Forms::Label^ mazeLine912;

private: System::Windows::Forms::Label^ mazeLine86;

private: System::Windows::Forms::Label^ mazeLine85;

private: System::Windows::Forms::Label^ mazeLine84;

private: System::Windows::Forms::Label^ mazeLine83;

private: System::Windows::Forms::Label^ mazeLine82;

private: System::Windows::Forms::Label^ mazeLine81;
private: System::Windows::Forms::Label^ mazeLine756;


private: System::Windows::Forms::Label^ mazeLine745;

private: System::Windows::Forms::Label^ mazeLine734;

private: System::Windows::Forms::Label^ mazeLine723;

private: System::Windows::Forms::Label^ mazeLine712;

private: System::Windows::Forms::Label^ mazeLine66;

private: System::Windows::Forms::Label^ mazeLine65;

private: System::Windows::Forms::Label^ mazeLine64;

private: System::Windows::Forms::Label^ mazeLine63;

private: System::Windows::Forms::Label^ mazeLine62;

private: System::Windows::Forms::Label^ mazeLine61;
private: System::Windows::Forms::Label^ mazeLine556;


private: System::Windows::Forms::Label^ mazeLine545;

private: System::Windows::Forms::Label^ mazeLine534;

private: System::Windows::Forms::Label^ mazeLine523;

private: System::Windows::Forms::Label^ mazeLine512;

private: System::Windows::Forms::Label^ mazeLine46;

private: System::Windows::Forms::Label^ mazeLine45;

private: System::Windows::Forms::Label^ mazeLine44;

private: System::Windows::Forms::Label^ mazeLine43;

private: System::Windows::Forms::Label^ mazeLine42;

private: System::Windows::Forms::Label^ mazeLine41;
private: System::Windows::Forms::Label^ mazeLine356;


private: System::Windows::Forms::Label^ mazeLine345;

private: System::Windows::Forms::Label^ mazeLine334;

private: System::Windows::Forms::Label^ mazeLine323;

private: System::Windows::Forms::Label^ mazeLine312;

private: System::Windows::Forms::Label^ mazeLine26;

private: System::Windows::Forms::Label^ mazeLine25;

private: System::Windows::Forms::Label^ mazeLine24;

private: System::Windows::Forms::Label^ mazeLine23;

private: System::Windows::Forms::Label^ mazeLine22;

private: System::Windows::Forms::Label^ mazeLine21;
private: System::Windows::Forms::Button^ exitButton;
private: System::Windows::Forms::Button^ submitButton;
private: System::Windows::Forms::Label^ promptLabel;
private: System::Windows::Forms::Button^ resetButton;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModuleMaze::typeid));
			this->mazeBox = (gcnew System::Windows::Forms::GroupBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->mazeLineB56 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->mazeLineB45 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->mazeLineB34 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->mazeLineB23 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->mazeLineB12 = (gcnew System::Windows::Forms::Label());
			this->mazeLineA6 = (gcnew System::Windows::Forms::Label());
			this->mazeLineA5 = (gcnew System::Windows::Forms::Label());
			this->mazeLineA4 = (gcnew System::Windows::Forms::Label());
			this->mazeLineA3 = (gcnew System::Windows::Forms::Label());
			this->mazeLineA2 = (gcnew System::Windows::Forms::Label());
			this->mazeLineA1 = (gcnew System::Windows::Forms::Label());
			this->mazeLine956 = (gcnew System::Windows::Forms::Label());
			this->mazeLine945 = (gcnew System::Windows::Forms::Label());
			this->mazeLine934 = (gcnew System::Windows::Forms::Label());
			this->mazeLine923 = (gcnew System::Windows::Forms::Label());
			this->mazeLine912 = (gcnew System::Windows::Forms::Label());
			this->mazeLine86 = (gcnew System::Windows::Forms::Label());
			this->mazeLine85 = (gcnew System::Windows::Forms::Label());
			this->mazeLine84 = (gcnew System::Windows::Forms::Label());
			this->mazeLine83 = (gcnew System::Windows::Forms::Label());
			this->mazeLine82 = (gcnew System::Windows::Forms::Label());
			this->mazeLine81 = (gcnew System::Windows::Forms::Label());
			this->mazeLine756 = (gcnew System::Windows::Forms::Label());
			this->mazeLine745 = (gcnew System::Windows::Forms::Label());
			this->mazeLine734 = (gcnew System::Windows::Forms::Label());
			this->mazeLine723 = (gcnew System::Windows::Forms::Label());
			this->mazeLine712 = (gcnew System::Windows::Forms::Label());
			this->mazeLine66 = (gcnew System::Windows::Forms::Label());
			this->mazeLine65 = (gcnew System::Windows::Forms::Label());
			this->mazeLine64 = (gcnew System::Windows::Forms::Label());
			this->mazeLine63 = (gcnew System::Windows::Forms::Label());
			this->mazeLine62 = (gcnew System::Windows::Forms::Label());
			this->mazeLine61 = (gcnew System::Windows::Forms::Label());
			this->mazeLine556 = (gcnew System::Windows::Forms::Label());
			this->mazeLine545 = (gcnew System::Windows::Forms::Label());
			this->mazeLine534 = (gcnew System::Windows::Forms::Label());
			this->mazeLine523 = (gcnew System::Windows::Forms::Label());
			this->mazeLine512 = (gcnew System::Windows::Forms::Label());
			this->mazeLine46 = (gcnew System::Windows::Forms::Label());
			this->mazeLine45 = (gcnew System::Windows::Forms::Label());
			this->mazeLine44 = (gcnew System::Windows::Forms::Label());
			this->mazeLine43 = (gcnew System::Windows::Forms::Label());
			this->mazeLine42 = (gcnew System::Windows::Forms::Label());
			this->mazeLine41 = (gcnew System::Windows::Forms::Label());
			this->mazeLine356 = (gcnew System::Windows::Forms::Label());
			this->mazeLine345 = (gcnew System::Windows::Forms::Label());
			this->mazeLine334 = (gcnew System::Windows::Forms::Label());
			this->mazeLine323 = (gcnew System::Windows::Forms::Label());
			this->mazeLine312 = (gcnew System::Windows::Forms::Label());
			this->mazeLine26 = (gcnew System::Windows::Forms::Label());
			this->mazeLine25 = (gcnew System::Windows::Forms::Label());
			this->mazeLine24 = (gcnew System::Windows::Forms::Label());
			this->mazeLine23 = (gcnew System::Windows::Forms::Label());
			this->mazeLine22 = (gcnew System::Windows::Forms::Label());
			this->mazeLine21 = (gcnew System::Windows::Forms::Label());
			this->mazeLine156 = (gcnew System::Windows::Forms::Label());
			this->mazeLine145 = (gcnew System::Windows::Forms::Label());
			this->mazeLine134 = (gcnew System::Windows::Forms::Label());
			this->mazeLine123 = (gcnew System::Windows::Forms::Label());
			this->mazeLine112 = (gcnew System::Windows::Forms::Label());
			this->mazeBox66 = (gcnew System::Windows::Forms::Label());
			this->mazeBox56 = (gcnew System::Windows::Forms::Label());
			this->mazeBox46 = (gcnew System::Windows::Forms::Label());
			this->mazeBox36 = (gcnew System::Windows::Forms::Label());
			this->mazeBox26 = (gcnew System::Windows::Forms::Label());
			this->mazeBox16 = (gcnew System::Windows::Forms::Label());
			this->mazeBox65 = (gcnew System::Windows::Forms::Label());
			this->mazeBox55 = (gcnew System::Windows::Forms::Label());
			this->mazeBox45 = (gcnew System::Windows::Forms::Label());
			this->mazeBox35 = (gcnew System::Windows::Forms::Label());
			this->mazeBox25 = (gcnew System::Windows::Forms::Label());
			this->mazeBox15 = (gcnew System::Windows::Forms::Label());
			this->mazeBox64 = (gcnew System::Windows::Forms::Label());
			this->mazeBox54 = (gcnew System::Windows::Forms::Label());
			this->mazeBox44 = (gcnew System::Windows::Forms::Label());
			this->mazeBox34 = (gcnew System::Windows::Forms::Label());
			this->mazeBox24 = (gcnew System::Windows::Forms::Label());
			this->mazeBox14 = (gcnew System::Windows::Forms::Label());
			this->mazeBox63 = (gcnew System::Windows::Forms::Label());
			this->mazeBox53 = (gcnew System::Windows::Forms::Label());
			this->mazeBox43 = (gcnew System::Windows::Forms::Label());
			this->mazeBox33 = (gcnew System::Windows::Forms::Label());
			this->mazeBox23 = (gcnew System::Windows::Forms::Label());
			this->mazeBox13 = (gcnew System::Windows::Forms::Label());
			this->mazeBox62 = (gcnew System::Windows::Forms::Label());
			this->mazeBox52 = (gcnew System::Windows::Forms::Label());
			this->mazeBox42 = (gcnew System::Windows::Forms::Label());
			this->mazeBox32 = (gcnew System::Windows::Forms::Label());
			this->mazeBox22 = (gcnew System::Windows::Forms::Label());
			this->mazeBox12 = (gcnew System::Windows::Forms::Label());
			this->mazeBox61 = (gcnew System::Windows::Forms::Label());
			this->mazeBox51 = (gcnew System::Windows::Forms::Label());
			this->mazeBox41 = (gcnew System::Windows::Forms::Label());
			this->mazeBox31 = (gcnew System::Windows::Forms::Label());
			this->mazeBox21 = (gcnew System::Windows::Forms::Label());
			this->mazeBox11 = (gcnew System::Windows::Forms::Label());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->submitButton = (gcnew System::Windows::Forms::Button());
			this->promptLabel = (gcnew System::Windows::Forms::Label());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->mazeBoxReference1 = (gcnew System::Windows::Forms::Label());
			this->mazeBoxReference2 = (gcnew System::Windows::Forms::Label());
			this->mazeBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// mazeBox
			// 
			this->mazeBox->BackColor = System::Drawing::Color::Silver;
			this->mazeBox->Controls->Add(this->label19);
			this->mazeBox->Controls->Add(this->label20);
			this->mazeBox->Controls->Add(this->label21);
			this->mazeBox->Controls->Add(this->label22);
			this->mazeBox->Controls->Add(this->label23);
			this->mazeBox->Controls->Add(this->label24);
			this->mazeBox->Controls->Add(this->label13);
			this->mazeBox->Controls->Add(this->label14);
			this->mazeBox->Controls->Add(this->label15);
			this->mazeBox->Controls->Add(this->label16);
			this->mazeBox->Controls->Add(this->label17);
			this->mazeBox->Controls->Add(this->label18);
			this->mazeBox->Controls->Add(this->label1);
			this->mazeBox->Controls->Add(this->label2);
			this->mazeBox->Controls->Add(this->label3);
			this->mazeBox->Controls->Add(this->label4);
			this->mazeBox->Controls->Add(this->label5);
			this->mazeBox->Controls->Add(this->label6);
			this->mazeBox->Controls->Add(this->label7);
			this->mazeBox->Controls->Add(this->label8);
			this->mazeBox->Controls->Add(this->mazeLineB56);
			this->mazeBox->Controls->Add(this->label9);
			this->mazeBox->Controls->Add(this->mazeLineB45);
			this->mazeBox->Controls->Add(this->label10);
			this->mazeBox->Controls->Add(this->mazeLineB34);
			this->mazeBox->Controls->Add(this->label11);
			this->mazeBox->Controls->Add(this->mazeLineB23);
			this->mazeBox->Controls->Add(this->label12);
			this->mazeBox->Controls->Add(this->mazeLineB12);
			this->mazeBox->Controls->Add(this->mazeLineA6);
			this->mazeBox->Controls->Add(this->mazeLineA5);
			this->mazeBox->Controls->Add(this->mazeLineA4);
			this->mazeBox->Controls->Add(this->mazeLineA3);
			this->mazeBox->Controls->Add(this->mazeLineA2);
			this->mazeBox->Controls->Add(this->mazeLineA1);
			this->mazeBox->Controls->Add(this->mazeLine956);
			this->mazeBox->Controls->Add(this->mazeLine945);
			this->mazeBox->Controls->Add(this->mazeLine934);
			this->mazeBox->Controls->Add(this->mazeLine923);
			this->mazeBox->Controls->Add(this->mazeLine912);
			this->mazeBox->Controls->Add(this->mazeLine86);
			this->mazeBox->Controls->Add(this->mazeLine85);
			this->mazeBox->Controls->Add(this->mazeLine84);
			this->mazeBox->Controls->Add(this->mazeLine83);
			this->mazeBox->Controls->Add(this->mazeLine82);
			this->mazeBox->Controls->Add(this->mazeLine81);
			this->mazeBox->Controls->Add(this->mazeLine756);
			this->mazeBox->Controls->Add(this->mazeLine745);
			this->mazeBox->Controls->Add(this->mazeLine734);
			this->mazeBox->Controls->Add(this->mazeLine723);
			this->mazeBox->Controls->Add(this->mazeLine712);
			this->mazeBox->Controls->Add(this->mazeLine66);
			this->mazeBox->Controls->Add(this->mazeLine65);
			this->mazeBox->Controls->Add(this->mazeLine64);
			this->mazeBox->Controls->Add(this->mazeLine63);
			this->mazeBox->Controls->Add(this->mazeLine62);
			this->mazeBox->Controls->Add(this->mazeLine61);
			this->mazeBox->Controls->Add(this->mazeLine556);
			this->mazeBox->Controls->Add(this->mazeLine545);
			this->mazeBox->Controls->Add(this->mazeLine534);
			this->mazeBox->Controls->Add(this->mazeLine523);
			this->mazeBox->Controls->Add(this->mazeLine512);
			this->mazeBox->Controls->Add(this->mazeLine46);
			this->mazeBox->Controls->Add(this->mazeLine45);
			this->mazeBox->Controls->Add(this->mazeLine44);
			this->mazeBox->Controls->Add(this->mazeLine43);
			this->mazeBox->Controls->Add(this->mazeLine42);
			this->mazeBox->Controls->Add(this->mazeLine41);
			this->mazeBox->Controls->Add(this->mazeLine356);
			this->mazeBox->Controls->Add(this->mazeLine345);
			this->mazeBox->Controls->Add(this->mazeLine334);
			this->mazeBox->Controls->Add(this->mazeLine323);
			this->mazeBox->Controls->Add(this->mazeLine312);
			this->mazeBox->Controls->Add(this->mazeLine26);
			this->mazeBox->Controls->Add(this->mazeLine25);
			this->mazeBox->Controls->Add(this->mazeLine24);
			this->mazeBox->Controls->Add(this->mazeLine23);
			this->mazeBox->Controls->Add(this->mazeLine22);
			this->mazeBox->Controls->Add(this->mazeLine21);
			this->mazeBox->Controls->Add(this->mazeLine156);
			this->mazeBox->Controls->Add(this->mazeLine145);
			this->mazeBox->Controls->Add(this->mazeLine134);
			this->mazeBox->Controls->Add(this->mazeLine123);
			this->mazeBox->Controls->Add(this->mazeLine112);
			this->mazeBox->Controls->Add(this->mazeBox66);
			this->mazeBox->Controls->Add(this->mazeBox56);
			this->mazeBox->Controls->Add(this->mazeBox46);
			this->mazeBox->Controls->Add(this->mazeBox36);
			this->mazeBox->Controls->Add(this->mazeBox26);
			this->mazeBox->Controls->Add(this->mazeBox16);
			this->mazeBox->Controls->Add(this->mazeBox65);
			this->mazeBox->Controls->Add(this->mazeBox55);
			this->mazeBox->Controls->Add(this->mazeBox45);
			this->mazeBox->Controls->Add(this->mazeBox35);
			this->mazeBox->Controls->Add(this->mazeBox25);
			this->mazeBox->Controls->Add(this->mazeBox15);
			this->mazeBox->Controls->Add(this->mazeBox64);
			this->mazeBox->Controls->Add(this->mazeBox54);
			this->mazeBox->Controls->Add(this->mazeBox44);
			this->mazeBox->Controls->Add(this->mazeBox34);
			this->mazeBox->Controls->Add(this->mazeBox24);
			this->mazeBox->Controls->Add(this->mazeBox14);
			this->mazeBox->Controls->Add(this->mazeBox63);
			this->mazeBox->Controls->Add(this->mazeBox53);
			this->mazeBox->Controls->Add(this->mazeBox43);
			this->mazeBox->Controls->Add(this->mazeBox33);
			this->mazeBox->Controls->Add(this->mazeBox23);
			this->mazeBox->Controls->Add(this->mazeBox13);
			this->mazeBox->Controls->Add(this->mazeBox62);
			this->mazeBox->Controls->Add(this->mazeBox52);
			this->mazeBox->Controls->Add(this->mazeBox42);
			this->mazeBox->Controls->Add(this->mazeBox32);
			this->mazeBox->Controls->Add(this->mazeBox22);
			this->mazeBox->Controls->Add(this->mazeBox12);
			this->mazeBox->Controls->Add(this->mazeBox61);
			this->mazeBox->Controls->Add(this->mazeBox51);
			this->mazeBox->Controls->Add(this->mazeBox41);
			this->mazeBox->Controls->Add(this->mazeBox31);
			this->mazeBox->Controls->Add(this->mazeBox21);
			this->mazeBox->Controls->Add(this->mazeBox11);
			this->mazeBox->ForeColor = System::Drawing::Color::Gold;
			this->mazeBox->Location = System::Drawing::Point(17, 93);
			this->mazeBox->Name = L"mazeBox";
			this->mazeBox->Size = System::Drawing::Size(302, 287);
			this->mazeBox->TabIndex = 0;
			this->mazeBox->TabStop = false;
			// 
			// label19
			// 
			this->label19->BackColor = System::Drawing::Color::Transparent;
			this->label19->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::Gold;
			this->label19->Location = System::Drawing::Point(248, 11);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(20, 20);
			this->label19->TabIndex = 124;
			this->label19->Text = L"6";
			this->label19->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label20
			// 
			this->label20->BackColor = System::Drawing::Color::Transparent;
			this->label20->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::Gold;
			this->label20->Location = System::Drawing::Point(205, 11);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(20, 20);
			this->label20->TabIndex = 123;
			this->label20->Text = L"5";
			this->label20->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label21
			// 
			this->label21->BackColor = System::Drawing::Color::Transparent;
			this->label21->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::Color::Gold;
			this->label21->Location = System::Drawing::Point(162, 11);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(20, 20);
			this->label21->TabIndex = 122;
			this->label21->Text = L"4";
			this->label21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label22
			// 
			this->label22->BackColor = System::Drawing::Color::Transparent;
			this->label22->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::Color::Gold;
			this->label22->Location = System::Drawing::Point(119, 11);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(20, 20);
			this->label22->TabIndex = 121;
			this->label22->Text = L"3";
			this->label22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label23
			// 
			this->label23->BackColor = System::Drawing::Color::Transparent;
			this->label23->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::Color::Gold;
			this->label23->Location = System::Drawing::Point(76, 11);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(20, 20);
			this->label23->TabIndex = 120;
			this->label23->Text = L"2";
			this->label23->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label24
			// 
			this->label24->BackColor = System::Drawing::Color::Transparent;
			this->label24->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::Color::Gold;
			this->label24->Location = System::Drawing::Point(33, 11);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(20, 20);
			this->label24->TabIndex = 119;
			this->label24->Text = L"1";
			this->label24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Gold;
			this->label13->Location = System::Drawing::Point(248, 262);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(20, 20);
			this->label13->TabIndex = 118;
			this->label13->Text = L"6";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label14
			// 
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::Gold;
			this->label14->Location = System::Drawing::Point(205, 262);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(20, 20);
			this->label14->TabIndex = 117;
			this->label14->Text = L"5";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label15
			// 
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::Gold;
			this->label15->Location = System::Drawing::Point(162, 262);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(20, 20);
			this->label15->TabIndex = 116;
			this->label15->Text = L"4";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label16
			// 
			this->label16->BackColor = System::Drawing::Color::Transparent;
			this->label16->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::Gold;
			this->label16->Location = System::Drawing::Point(119, 262);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(20, 20);
			this->label16->TabIndex = 115;
			this->label16->Text = L"3";
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label17
			// 
			this->label17->BackColor = System::Drawing::Color::Transparent;
			this->label17->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::Gold;
			this->label17->Location = System::Drawing::Point(76, 262);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(20, 20);
			this->label17->TabIndex = 114;
			this->label17->Text = L"2";
			this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label18
			// 
			this->label18->BackColor = System::Drawing::Color::Transparent;
			this->label18->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::Color::Gold;
			this->label18->Location = System::Drawing::Point(33, 262);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(20, 20);
			this->label18->TabIndex = 113;
			this->label18->Text = L"1";
			this->label18->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DarkViolet;
			this->label1->Location = System::Drawing::Point(272, 238);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 20);
			this->label1->TabIndex = 112;
			this->label1->Text = L"6";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DarkViolet;
			this->label2->Location = System::Drawing::Point(272, 197);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 20);
			this->label2->TabIndex = 111;
			this->label2->Text = L"5";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::DarkViolet;
			this->label3->Location = System::Drawing::Point(272, 156);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(20, 20);
			this->label3->TabIndex = 110;
			this->label3->Text = L"4";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::DarkViolet;
			this->label4->Location = System::Drawing::Point(272, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(20, 20);
			this->label4->TabIndex = 109;
			this->label4->Text = L"3";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::DarkViolet;
			this->label5->Location = System::Drawing::Point(272, 74);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(20, 20);
			this->label5->TabIndex = 108;
			this->label5->Text = L"2";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::DarkViolet;
			this->label6->Location = System::Drawing::Point(272, 33);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 20);
			this->label6->TabIndex = 107;
			this->label6->Text = L"1";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::DarkViolet;
			this->label7->Location = System::Drawing::Point(10, 238);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(20, 20);
			this->label7->TabIndex = 106;
			this->label7->Text = L"6";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::DarkViolet;
			this->label8->Location = System::Drawing::Point(10, 197);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(20, 20);
			this->label8->TabIndex = 105;
			this->label8->Text = L"5";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// mazeLineB56
			// 
			this->mazeLineB56->BackColor = System::Drawing::Color::Black;
			this->mazeLineB56->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLineB56->Location = System::Drawing::Point(227, 246);
			this->mazeLineB56->Name = L"mazeLineB56";
			this->mazeLineB56->Size = System::Drawing::Size(20, 4);
			this->mazeLineB56->TabIndex = 94;
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::DarkViolet;
			this->label9->Location = System::Drawing::Point(10, 156);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(20, 20);
			this->label9->TabIndex = 104;
			this->label9->Text = L"4";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// mazeLineB45
			// 
			this->mazeLineB45->BackColor = System::Drawing::Color::Black;
			this->mazeLineB45->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLineB45->Location = System::Drawing::Point(184, 246);
			this->mazeLineB45->Name = L"mazeLineB45";
			this->mazeLineB45->Size = System::Drawing::Size(20, 4);
			this->mazeLineB45->TabIndex = 92;
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::DarkViolet;
			this->label10->Location = System::Drawing::Point(10, 115);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(20, 20);
			this->label10->TabIndex = 103;
			this->label10->Text = L"3";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// mazeLineB34
			// 
			this->mazeLineB34->BackColor = System::Drawing::Color::Black;
			this->mazeLineB34->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLineB34->Location = System::Drawing::Point(141, 246);
			this->mazeLineB34->Name = L"mazeLineB34";
			this->mazeLineB34->Size = System::Drawing::Size(20, 4);
			this->mazeLineB34->TabIndex = 91;
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::DarkViolet;
			this->label11->Location = System::Drawing::Point(10, 74);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(20, 20);
			this->label11->TabIndex = 102;
			this->label11->Text = L"2";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// mazeLineB23
			// 
			this->mazeLineB23->BackColor = System::Drawing::Color::Black;
			this->mazeLineB23->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLineB23->Location = System::Drawing::Point(98, 246);
			this->mazeLineB23->Name = L"mazeLineB23";
			this->mazeLineB23->Size = System::Drawing::Size(20, 4);
			this->mazeLineB23->TabIndex = 90;
			// 
			// label12
			// 
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::DarkViolet;
			this->label12->Location = System::Drawing::Point(10, 33);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(20, 20);
			this->label12->TabIndex = 101;
			this->label12->Text = L"1";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// mazeLineB12
			// 
			this->mazeLineB12->BackColor = System::Drawing::Color::Black;
			this->mazeLineB12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLineB12->Location = System::Drawing::Point(55, 246);
			this->mazeLineB12->Name = L"mazeLineB12";
			this->mazeLineB12->Size = System::Drawing::Size(20, 4);
			this->mazeLineB12->TabIndex = 89;
			// 
			// mazeLineA6
			// 
			this->mazeLineA6->BackColor = System::Drawing::Color::Black;
			this->mazeLineA6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLineA6->Location = System::Drawing::Point(256, 220);
			this->mazeLineA6->Name = L"mazeLineA6";
			this->mazeLineA6->Size = System::Drawing::Size(4, 16);
			this->mazeLineA6->TabIndex = 88;
			// 
			// mazeLineA5
			// 
			this->mazeLineA5->BackColor = System::Drawing::Color::Black;
			this->mazeLineA5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLineA5->Location = System::Drawing::Point(213, 220);
			this->mazeLineA5->Name = L"mazeLineA5";
			this->mazeLineA5->Size = System::Drawing::Size(4, 16);
			this->mazeLineA5->TabIndex = 87;
			// 
			// mazeLineA4
			// 
			this->mazeLineA4->BackColor = System::Drawing::Color::Black;
			this->mazeLineA4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLineA4->Location = System::Drawing::Point(170, 220);
			this->mazeLineA4->Name = L"mazeLineA4";
			this->mazeLineA4->Size = System::Drawing::Size(4, 16);
			this->mazeLineA4->TabIndex = 86;
			// 
			// mazeLineA3
			// 
			this->mazeLineA3->BackColor = System::Drawing::Color::Black;
			this->mazeLineA3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLineA3->Location = System::Drawing::Point(127, 220);
			this->mazeLineA3->Name = L"mazeLineA3";
			this->mazeLineA3->Size = System::Drawing::Size(4, 16);
			this->mazeLineA3->TabIndex = 85;
			// 
			// mazeLineA2
			// 
			this->mazeLineA2->BackColor = System::Drawing::Color::Black;
			this->mazeLineA2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLineA2->Location = System::Drawing::Point(84, 220);
			this->mazeLineA2->Name = L"mazeLineA2";
			this->mazeLineA2->Size = System::Drawing::Size(4, 16);
			this->mazeLineA2->TabIndex = 84;
			// 
			// mazeLineA1
			// 
			this->mazeLineA1->BackColor = System::Drawing::Color::Black;
			this->mazeLineA1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLineA1->Location = System::Drawing::Point(41, 220);
			this->mazeLineA1->Name = L"mazeLineA1";
			this->mazeLineA1->Size = System::Drawing::Size(4, 16);
			this->mazeLineA1->TabIndex = 82;
			// 
			// mazeLine956
			// 
			this->mazeLine956->BackColor = System::Drawing::Color::Black;
			this->mazeLine956->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine956->Location = System::Drawing::Point(227, 205);
			this->mazeLine956->Name = L"mazeLine956";
			this->mazeLine956->Size = System::Drawing::Size(20, 4);
			this->mazeLine956->TabIndex = 83;
			// 
			// mazeLine945
			// 
			this->mazeLine945->BackColor = System::Drawing::Color::Black;
			this->mazeLine945->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine945->Location = System::Drawing::Point(184, 205);
			this->mazeLine945->Name = L"mazeLine945";
			this->mazeLine945->Size = System::Drawing::Size(20, 4);
			this->mazeLine945->TabIndex = 81;
			// 
			// mazeLine934
			// 
			this->mazeLine934->BackColor = System::Drawing::Color::Black;
			this->mazeLine934->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine934->Location = System::Drawing::Point(141, 205);
			this->mazeLine934->Name = L"mazeLine934";
			this->mazeLine934->Size = System::Drawing::Size(20, 4);
			this->mazeLine934->TabIndex = 80;
			// 
			// mazeLine923
			// 
			this->mazeLine923->BackColor = System::Drawing::Color::Black;
			this->mazeLine923->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine923->Location = System::Drawing::Point(98, 205);
			this->mazeLine923->Name = L"mazeLine923";
			this->mazeLine923->Size = System::Drawing::Size(20, 4);
			this->mazeLine923->TabIndex = 79;
			// 
			// mazeLine912
			// 
			this->mazeLine912->BackColor = System::Drawing::Color::Black;
			this->mazeLine912->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine912->Location = System::Drawing::Point(55, 205);
			this->mazeLine912->Name = L"mazeLine912";
			this->mazeLine912->Size = System::Drawing::Size(20, 4);
			this->mazeLine912->TabIndex = 78;
			// 
			// mazeLine86
			// 
			this->mazeLine86->BackColor = System::Drawing::Color::Black;
			this->mazeLine86->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine86->Location = System::Drawing::Point(256, 179);
			this->mazeLine86->Name = L"mazeLine86";
			this->mazeLine86->Size = System::Drawing::Size(4, 16);
			this->mazeLine86->TabIndex = 77;
			// 
			// mazeLine85
			// 
			this->mazeLine85->BackColor = System::Drawing::Color::Black;
			this->mazeLine85->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine85->Location = System::Drawing::Point(213, 179);
			this->mazeLine85->Name = L"mazeLine85";
			this->mazeLine85->Size = System::Drawing::Size(4, 16);
			this->mazeLine85->TabIndex = 76;
			// 
			// mazeLine84
			// 
			this->mazeLine84->BackColor = System::Drawing::Color::Black;
			this->mazeLine84->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine84->Location = System::Drawing::Point(170, 179);
			this->mazeLine84->Name = L"mazeLine84";
			this->mazeLine84->Size = System::Drawing::Size(4, 16);
			this->mazeLine84->TabIndex = 75;
			// 
			// mazeLine83
			// 
			this->mazeLine83->BackColor = System::Drawing::Color::Black;
			this->mazeLine83->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine83->Location = System::Drawing::Point(127, 179);
			this->mazeLine83->Name = L"mazeLine83";
			this->mazeLine83->Size = System::Drawing::Size(4, 16);
			this->mazeLine83->TabIndex = 74;
			// 
			// mazeLine82
			// 
			this->mazeLine82->BackColor = System::Drawing::Color::Black;
			this->mazeLine82->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine82->Location = System::Drawing::Point(84, 179);
			this->mazeLine82->Name = L"mazeLine82";
			this->mazeLine82->Size = System::Drawing::Size(4, 16);
			this->mazeLine82->TabIndex = 73;
			// 
			// mazeLine81
			// 
			this->mazeLine81->BackColor = System::Drawing::Color::Black;
			this->mazeLine81->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine81->Location = System::Drawing::Point(41, 179);
			this->mazeLine81->Name = L"mazeLine81";
			this->mazeLine81->Size = System::Drawing::Size(4, 16);
			this->mazeLine81->TabIndex = 71;
			// 
			// mazeLine756
			// 
			this->mazeLine756->BackColor = System::Drawing::Color::Black;
			this->mazeLine756->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine756->Location = System::Drawing::Point(227, 164);
			this->mazeLine756->Name = L"mazeLine756";
			this->mazeLine756->Size = System::Drawing::Size(20, 4);
			this->mazeLine756->TabIndex = 72;
			// 
			// mazeLine745
			// 
			this->mazeLine745->BackColor = System::Drawing::Color::Black;
			this->mazeLine745->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine745->Location = System::Drawing::Point(184, 164);
			this->mazeLine745->Name = L"mazeLine745";
			this->mazeLine745->Size = System::Drawing::Size(20, 4);
			this->mazeLine745->TabIndex = 70;
			// 
			// mazeLine734
			// 
			this->mazeLine734->BackColor = System::Drawing::Color::Black;
			this->mazeLine734->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine734->Location = System::Drawing::Point(141, 164);
			this->mazeLine734->Name = L"mazeLine734";
			this->mazeLine734->Size = System::Drawing::Size(20, 4);
			this->mazeLine734->TabIndex = 69;
			// 
			// mazeLine723
			// 
			this->mazeLine723->BackColor = System::Drawing::Color::Black;
			this->mazeLine723->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine723->Location = System::Drawing::Point(98, 164);
			this->mazeLine723->Name = L"mazeLine723";
			this->mazeLine723->Size = System::Drawing::Size(20, 4);
			this->mazeLine723->TabIndex = 68;
			// 
			// mazeLine712
			// 
			this->mazeLine712->BackColor = System::Drawing::Color::Black;
			this->mazeLine712->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine712->Location = System::Drawing::Point(55, 164);
			this->mazeLine712->Name = L"mazeLine712";
			this->mazeLine712->Size = System::Drawing::Size(20, 4);
			this->mazeLine712->TabIndex = 67;
			// 
			// mazeLine66
			// 
			this->mazeLine66->BackColor = System::Drawing::Color::Black;
			this->mazeLine66->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine66->Location = System::Drawing::Point(256, 138);
			this->mazeLine66->Name = L"mazeLine66";
			this->mazeLine66->Size = System::Drawing::Size(4, 16);
			this->mazeLine66->TabIndex = 66;
			// 
			// mazeLine65
			// 
			this->mazeLine65->BackColor = System::Drawing::Color::Black;
			this->mazeLine65->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine65->Location = System::Drawing::Point(213, 138);
			this->mazeLine65->Name = L"mazeLine65";
			this->mazeLine65->Size = System::Drawing::Size(4, 16);
			this->mazeLine65->TabIndex = 65;
			// 
			// mazeLine64
			// 
			this->mazeLine64->BackColor = System::Drawing::Color::Black;
			this->mazeLine64->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine64->Location = System::Drawing::Point(170, 138);
			this->mazeLine64->Name = L"mazeLine64";
			this->mazeLine64->Size = System::Drawing::Size(4, 16);
			this->mazeLine64->TabIndex = 64;
			// 
			// mazeLine63
			// 
			this->mazeLine63->BackColor = System::Drawing::Color::Black;
			this->mazeLine63->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine63->Location = System::Drawing::Point(127, 138);
			this->mazeLine63->Name = L"mazeLine63";
			this->mazeLine63->Size = System::Drawing::Size(4, 16);
			this->mazeLine63->TabIndex = 63;
			// 
			// mazeLine62
			// 
			this->mazeLine62->BackColor = System::Drawing::Color::Black;
			this->mazeLine62->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine62->Location = System::Drawing::Point(84, 138);
			this->mazeLine62->Name = L"mazeLine62";
			this->mazeLine62->Size = System::Drawing::Size(4, 16);
			this->mazeLine62->TabIndex = 62;
			// 
			// mazeLine61
			// 
			this->mazeLine61->BackColor = System::Drawing::Color::Black;
			this->mazeLine61->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine61->Location = System::Drawing::Point(41, 138);
			this->mazeLine61->Name = L"mazeLine61";
			this->mazeLine61->Size = System::Drawing::Size(4, 16);
			this->mazeLine61->TabIndex = 60;
			// 
			// mazeLine556
			// 
			this->mazeLine556->BackColor = System::Drawing::Color::Black;
			this->mazeLine556->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine556->Location = System::Drawing::Point(227, 123);
			this->mazeLine556->Name = L"mazeLine556";
			this->mazeLine556->Size = System::Drawing::Size(20, 4);
			this->mazeLine556->TabIndex = 61;
			// 
			// mazeLine545
			// 
			this->mazeLine545->BackColor = System::Drawing::Color::Black;
			this->mazeLine545->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine545->Location = System::Drawing::Point(184, 123);
			this->mazeLine545->Name = L"mazeLine545";
			this->mazeLine545->Size = System::Drawing::Size(20, 4);
			this->mazeLine545->TabIndex = 59;
			// 
			// mazeLine534
			// 
			this->mazeLine534->BackColor = System::Drawing::Color::Black;
			this->mazeLine534->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine534->Location = System::Drawing::Point(141, 123);
			this->mazeLine534->Name = L"mazeLine534";
			this->mazeLine534->Size = System::Drawing::Size(20, 4);
			this->mazeLine534->TabIndex = 58;
			// 
			// mazeLine523
			// 
			this->mazeLine523->BackColor = System::Drawing::Color::Black;
			this->mazeLine523->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine523->Location = System::Drawing::Point(98, 123);
			this->mazeLine523->Name = L"mazeLine523";
			this->mazeLine523->Size = System::Drawing::Size(20, 4);
			this->mazeLine523->TabIndex = 57;
			// 
			// mazeLine512
			// 
			this->mazeLine512->BackColor = System::Drawing::Color::Black;
			this->mazeLine512->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine512->Location = System::Drawing::Point(55, 123);
			this->mazeLine512->Name = L"mazeLine512";
			this->mazeLine512->Size = System::Drawing::Size(20, 4);
			this->mazeLine512->TabIndex = 56;
			// 
			// mazeLine46
			// 
			this->mazeLine46->BackColor = System::Drawing::Color::Black;
			this->mazeLine46->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine46->Location = System::Drawing::Point(256, 97);
			this->mazeLine46->Name = L"mazeLine46";
			this->mazeLine46->Size = System::Drawing::Size(4, 16);
			this->mazeLine46->TabIndex = 55;
			// 
			// mazeLine45
			// 
			this->mazeLine45->BackColor = System::Drawing::Color::Black;
			this->mazeLine45->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine45->Location = System::Drawing::Point(213, 97);
			this->mazeLine45->Name = L"mazeLine45";
			this->mazeLine45->Size = System::Drawing::Size(4, 16);
			this->mazeLine45->TabIndex = 54;
			// 
			// mazeLine44
			// 
			this->mazeLine44->BackColor = System::Drawing::Color::Black;
			this->mazeLine44->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine44->Location = System::Drawing::Point(170, 97);
			this->mazeLine44->Name = L"mazeLine44";
			this->mazeLine44->Size = System::Drawing::Size(4, 16);
			this->mazeLine44->TabIndex = 53;
			// 
			// mazeLine43
			// 
			this->mazeLine43->BackColor = System::Drawing::Color::Black;
			this->mazeLine43->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine43->Location = System::Drawing::Point(127, 97);
			this->mazeLine43->Name = L"mazeLine43";
			this->mazeLine43->Size = System::Drawing::Size(4, 16);
			this->mazeLine43->TabIndex = 52;
			// 
			// mazeLine42
			// 
			this->mazeLine42->BackColor = System::Drawing::Color::Black;
			this->mazeLine42->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine42->Location = System::Drawing::Point(84, 97);
			this->mazeLine42->Name = L"mazeLine42";
			this->mazeLine42->Size = System::Drawing::Size(4, 16);
			this->mazeLine42->TabIndex = 51;
			// 
			// mazeLine41
			// 
			this->mazeLine41->BackColor = System::Drawing::Color::Black;
			this->mazeLine41->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine41->Location = System::Drawing::Point(41, 97);
			this->mazeLine41->Name = L"mazeLine41";
			this->mazeLine41->Size = System::Drawing::Size(4, 16);
			this->mazeLine41->TabIndex = 49;
			// 
			// mazeLine356
			// 
			this->mazeLine356->BackColor = System::Drawing::Color::Black;
			this->mazeLine356->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine356->Location = System::Drawing::Point(227, 82);
			this->mazeLine356->Name = L"mazeLine356";
			this->mazeLine356->Size = System::Drawing::Size(20, 4);
			this->mazeLine356->TabIndex = 50;
			// 
			// mazeLine345
			// 
			this->mazeLine345->BackColor = System::Drawing::Color::Black;
			this->mazeLine345->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine345->Location = System::Drawing::Point(184, 82);
			this->mazeLine345->Name = L"mazeLine345";
			this->mazeLine345->Size = System::Drawing::Size(20, 4);
			this->mazeLine345->TabIndex = 48;
			// 
			// mazeLine334
			// 
			this->mazeLine334->BackColor = System::Drawing::Color::Black;
			this->mazeLine334->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine334->Location = System::Drawing::Point(141, 82);
			this->mazeLine334->Name = L"mazeLine334";
			this->mazeLine334->Size = System::Drawing::Size(20, 4);
			this->mazeLine334->TabIndex = 47;
			// 
			// mazeLine323
			// 
			this->mazeLine323->BackColor = System::Drawing::Color::Black;
			this->mazeLine323->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine323->Location = System::Drawing::Point(98, 82);
			this->mazeLine323->Name = L"mazeLine323";
			this->mazeLine323->Size = System::Drawing::Size(20, 4);
			this->mazeLine323->TabIndex = 46;
			// 
			// mazeLine312
			// 
			this->mazeLine312->BackColor = System::Drawing::Color::Black;
			this->mazeLine312->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine312->Location = System::Drawing::Point(55, 82);
			this->mazeLine312->Name = L"mazeLine312";
			this->mazeLine312->Size = System::Drawing::Size(20, 4);
			this->mazeLine312->TabIndex = 45;
			// 
			// mazeLine26
			// 
			this->mazeLine26->BackColor = System::Drawing::Color::Black;
			this->mazeLine26->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine26->Location = System::Drawing::Point(256, 56);
			this->mazeLine26->Name = L"mazeLine26";
			this->mazeLine26->Size = System::Drawing::Size(4, 16);
			this->mazeLine26->TabIndex = 44;
			// 
			// mazeLine25
			// 
			this->mazeLine25->BackColor = System::Drawing::Color::Black;
			this->mazeLine25->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine25->Location = System::Drawing::Point(213, 56);
			this->mazeLine25->Name = L"mazeLine25";
			this->mazeLine25->Size = System::Drawing::Size(4, 16);
			this->mazeLine25->TabIndex = 43;
			// 
			// mazeLine24
			// 
			this->mazeLine24->BackColor = System::Drawing::Color::Black;
			this->mazeLine24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine24->Location = System::Drawing::Point(170, 56);
			this->mazeLine24->Name = L"mazeLine24";
			this->mazeLine24->Size = System::Drawing::Size(4, 16);
			this->mazeLine24->TabIndex = 42;
			// 
			// mazeLine23
			// 
			this->mazeLine23->BackColor = System::Drawing::Color::Black;
			this->mazeLine23->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine23->Location = System::Drawing::Point(127, 56);
			this->mazeLine23->Name = L"mazeLine23";
			this->mazeLine23->Size = System::Drawing::Size(4, 16);
			this->mazeLine23->TabIndex = 41;
			// 
			// mazeLine22
			// 
			this->mazeLine22->BackColor = System::Drawing::Color::Black;
			this->mazeLine22->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine22->Location = System::Drawing::Point(84, 56);
			this->mazeLine22->Name = L"mazeLine22";
			this->mazeLine22->Size = System::Drawing::Size(4, 16);
			this->mazeLine22->TabIndex = 40;
			// 
			// mazeLine21
			// 
			this->mazeLine21->BackColor = System::Drawing::Color::Black;
			this->mazeLine21->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine21->Location = System::Drawing::Point(41, 56);
			this->mazeLine21->Name = L"mazeLine21";
			this->mazeLine21->Size = System::Drawing::Size(4, 16);
			this->mazeLine21->TabIndex = 39;
			// 
			// mazeLine156
			// 
			this->mazeLine156->BackColor = System::Drawing::Color::Black;
			this->mazeLine156->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine156->Location = System::Drawing::Point(227, 41);
			this->mazeLine156->Name = L"mazeLine156";
			this->mazeLine156->Size = System::Drawing::Size(20, 4);
			this->mazeLine156->TabIndex = 39;
			// 
			// mazeLine145
			// 
			this->mazeLine145->BackColor = System::Drawing::Color::Black;
			this->mazeLine145->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine145->Location = System::Drawing::Point(184, 41);
			this->mazeLine145->Name = L"mazeLine145";
			this->mazeLine145->Size = System::Drawing::Size(20, 4);
			this->mazeLine145->TabIndex = 38;
			// 
			// mazeLine134
			// 
			this->mazeLine134->BackColor = System::Drawing::Color::Black;
			this->mazeLine134->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine134->Location = System::Drawing::Point(141, 41);
			this->mazeLine134->Name = L"mazeLine134";
			this->mazeLine134->Size = System::Drawing::Size(20, 4);
			this->mazeLine134->TabIndex = 37;
			// 
			// mazeLine123
			// 
			this->mazeLine123->BackColor = System::Drawing::Color::Black;
			this->mazeLine123->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine123->Location = System::Drawing::Point(98, 41);
			this->mazeLine123->Name = L"mazeLine123";
			this->mazeLine123->Size = System::Drawing::Size(20, 4);
			this->mazeLine123->TabIndex = 36;
			// 
			// mazeLine112
			// 
			this->mazeLine112->BackColor = System::Drawing::Color::Black;
			this->mazeLine112->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeLine112->Location = System::Drawing::Point(55, 41);
			this->mazeLine112->Name = L"mazeLine112";
			this->mazeLine112->Size = System::Drawing::Size(20, 4);
			this->mazeLine112->TabIndex = 1;
			// 
			// mazeBox66
			// 
			this->mazeBox66->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox66->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox66->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox66->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox66->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox66->Location = System::Drawing::Point(246, 236);
			this->mazeBox66->Name = L"mazeBox66";
			this->mazeBox66->Size = System::Drawing::Size(25, 25);
			this->mazeBox66->TabIndex = 35;
			this->mazeBox66->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox66->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox66_Click);
			// 
			// mazeBox56
			// 
			this->mazeBox56->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox56->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox56->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox56->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox56->Location = System::Drawing::Point(246, 195);
			this->mazeBox56->Name = L"mazeBox56";
			this->mazeBox56->Size = System::Drawing::Size(25, 25);
			this->mazeBox56->TabIndex = 34;
			this->mazeBox56->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox56->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox56_Click);
			// 
			// mazeBox46
			// 
			this->mazeBox46->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox46->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox46->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox46->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox46->Location = System::Drawing::Point(246, 154);
			this->mazeBox46->Name = L"mazeBox46";
			this->mazeBox46->Size = System::Drawing::Size(25, 25);
			this->mazeBox46->TabIndex = 33;
			this->mazeBox46->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox46->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox46_Click);
			// 
			// mazeBox36
			// 
			this->mazeBox36->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox36->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox36->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox36->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox36->Location = System::Drawing::Point(246, 113);
			this->mazeBox36->Name = L"mazeBox36";
			this->mazeBox36->Size = System::Drawing::Size(25, 25);
			this->mazeBox36->TabIndex = 32;
			this->mazeBox36->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox36->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox36_Click);
			// 
			// mazeBox26
			// 
			this->mazeBox26->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox26->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox26->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox26->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox26->Location = System::Drawing::Point(246, 72);
			this->mazeBox26->Name = L"mazeBox26";
			this->mazeBox26->Size = System::Drawing::Size(25, 25);
			this->mazeBox26->TabIndex = 31;
			this->mazeBox26->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox26->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox26_Click);
			// 
			// mazeBox16
			// 
			this->mazeBox16->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox16->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox16->Location = System::Drawing::Point(246, 31);
			this->mazeBox16->Name = L"mazeBox16";
			this->mazeBox16->Size = System::Drawing::Size(25, 25);
			this->mazeBox16->TabIndex = 30;
			this->mazeBox16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox16->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox16_Click);
			// 
			// mazeBox65
			// 
			this->mazeBox65->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox65->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox65->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox65->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox65->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox65->Location = System::Drawing::Point(203, 236);
			this->mazeBox65->Name = L"mazeBox65";
			this->mazeBox65->Size = System::Drawing::Size(25, 25);
			this->mazeBox65->TabIndex = 29;
			this->mazeBox65->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox65->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox65_Click);
			// 
			// mazeBox55
			// 
			this->mazeBox55->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox55->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox55->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox55->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox55->Location = System::Drawing::Point(203, 195);
			this->mazeBox55->Name = L"mazeBox55";
			this->mazeBox55->Size = System::Drawing::Size(25, 25);
			this->mazeBox55->TabIndex = 28;
			this->mazeBox55->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox55->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox55_Click);
			// 
			// mazeBox45
			// 
			this->mazeBox45->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox45->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox45->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox45->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox45->Location = System::Drawing::Point(203, 154);
			this->mazeBox45->Name = L"mazeBox45";
			this->mazeBox45->Size = System::Drawing::Size(25, 25);
			this->mazeBox45->TabIndex = 27;
			this->mazeBox45->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox45->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox45_Click);
			// 
			// mazeBox35
			// 
			this->mazeBox35->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox35->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox35->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox35->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox35->Location = System::Drawing::Point(203, 113);
			this->mazeBox35->Name = L"mazeBox35";
			this->mazeBox35->Size = System::Drawing::Size(25, 25);
			this->mazeBox35->TabIndex = 26;
			this->mazeBox35->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox35->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox35_Click);
			// 
			// mazeBox25
			// 
			this->mazeBox25->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox25->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox25->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox25->Location = System::Drawing::Point(203, 72);
			this->mazeBox25->Name = L"mazeBox25";
			this->mazeBox25->Size = System::Drawing::Size(25, 25);
			this->mazeBox25->TabIndex = 25;
			this->mazeBox25->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox25->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox25_Click);
			// 
			// mazeBox15
			// 
			this->mazeBox15->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox15->Location = System::Drawing::Point(203, 31);
			this->mazeBox15->Name = L"mazeBox15";
			this->mazeBox15->Size = System::Drawing::Size(25, 25);
			this->mazeBox15->TabIndex = 24;
			this->mazeBox15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox15->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox15_Click);
			// 
			// mazeBox64
			// 
			this->mazeBox64->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox64->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox64->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox64->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox64->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox64->Location = System::Drawing::Point(160, 236);
			this->mazeBox64->Name = L"mazeBox64";
			this->mazeBox64->Size = System::Drawing::Size(25, 25);
			this->mazeBox64->TabIndex = 23;
			this->mazeBox64->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox64->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox64_Click);
			// 
			// mazeBox54
			// 
			this->mazeBox54->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox54->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox54->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox54->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox54->Location = System::Drawing::Point(160, 195);
			this->mazeBox54->Name = L"mazeBox54";
			this->mazeBox54->Size = System::Drawing::Size(25, 25);
			this->mazeBox54->TabIndex = 22;
			this->mazeBox54->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox54->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox54_Click);
			// 
			// mazeBox44
			// 
			this->mazeBox44->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox44->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox44->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox44->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox44->Location = System::Drawing::Point(160, 154);
			this->mazeBox44->Name = L"mazeBox44";
			this->mazeBox44->Size = System::Drawing::Size(25, 25);
			this->mazeBox44->TabIndex = 21;
			this->mazeBox44->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox44->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox44_Click);
			// 
			// mazeBox34
			// 
			this->mazeBox34->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox34->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox34->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox34->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox34->Location = System::Drawing::Point(160, 113);
			this->mazeBox34->Name = L"mazeBox34";
			this->mazeBox34->Size = System::Drawing::Size(25, 25);
			this->mazeBox34->TabIndex = 20;
			this->mazeBox34->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox34->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox34_Click);
			// 
			// mazeBox24
			// 
			this->mazeBox24->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox24->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox24->Location = System::Drawing::Point(160, 72);
			this->mazeBox24->Name = L"mazeBox24";
			this->mazeBox24->Size = System::Drawing::Size(25, 25);
			this->mazeBox24->TabIndex = 19;
			this->mazeBox24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox24->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox24_Click);
			// 
			// mazeBox14
			// 
			this->mazeBox14->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox14->Location = System::Drawing::Point(160, 31);
			this->mazeBox14->Name = L"mazeBox14";
			this->mazeBox14->Size = System::Drawing::Size(25, 25);
			this->mazeBox14->TabIndex = 18;
			this->mazeBox14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox14->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox14_Click);
			// 
			// mazeBox63
			// 
			this->mazeBox63->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox63->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox63->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox63->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox63->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox63->Location = System::Drawing::Point(117, 236);
			this->mazeBox63->Name = L"mazeBox63";
			this->mazeBox63->Size = System::Drawing::Size(25, 25);
			this->mazeBox63->TabIndex = 17;
			this->mazeBox63->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox63->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox63_Click);
			// 
			// mazeBox53
			// 
			this->mazeBox53->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox53->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox53->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox53->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox53->Location = System::Drawing::Point(117, 195);
			this->mazeBox53->Name = L"mazeBox53";
			this->mazeBox53->Size = System::Drawing::Size(25, 25);
			this->mazeBox53->TabIndex = 16;
			this->mazeBox53->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox53->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox53_Click);
			// 
			// mazeBox43
			// 
			this->mazeBox43->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox43->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox43->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox43->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox43->Location = System::Drawing::Point(117, 154);
			this->mazeBox43->Name = L"mazeBox43";
			this->mazeBox43->Size = System::Drawing::Size(25, 25);
			this->mazeBox43->TabIndex = 15;
			this->mazeBox43->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox43->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox43_Click);
			// 
			// mazeBox33
			// 
			this->mazeBox33->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox33->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox33->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox33->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox33->Location = System::Drawing::Point(117, 113);
			this->mazeBox33->Name = L"mazeBox33";
			this->mazeBox33->Size = System::Drawing::Size(25, 25);
			this->mazeBox33->TabIndex = 14;
			this->mazeBox33->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox33->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox33_Click);
			// 
			// mazeBox23
			// 
			this->mazeBox23->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox23->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox23->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox23->Location = System::Drawing::Point(117, 72);
			this->mazeBox23->Name = L"mazeBox23";
			this->mazeBox23->Size = System::Drawing::Size(25, 25);
			this->mazeBox23->TabIndex = 13;
			this->mazeBox23->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox23->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox23_Click);
			// 
			// mazeBox13
			// 
			this->mazeBox13->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox13->Location = System::Drawing::Point(117, 31);
			this->mazeBox13->Name = L"mazeBox13";
			this->mazeBox13->Size = System::Drawing::Size(25, 25);
			this->mazeBox13->TabIndex = 12;
			this->mazeBox13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox13->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox13_Click);
			// 
			// mazeBox62
			// 
			this->mazeBox62->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox62->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox62->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox62->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox62->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox62->Location = System::Drawing::Point(74, 236);
			this->mazeBox62->Name = L"mazeBox62";
			this->mazeBox62->Size = System::Drawing::Size(25, 25);
			this->mazeBox62->TabIndex = 11;
			this->mazeBox62->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox62->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox62_Click);
			// 
			// mazeBox52
			// 
			this->mazeBox52->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox52->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox52->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox52->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox52->Location = System::Drawing::Point(74, 195);
			this->mazeBox52->Name = L"mazeBox52";
			this->mazeBox52->Size = System::Drawing::Size(25, 25);
			this->mazeBox52->TabIndex = 10;
			this->mazeBox52->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox52->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox52_Click);
			// 
			// mazeBox42
			// 
			this->mazeBox42->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox42->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox42->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox42->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox42->Location = System::Drawing::Point(74, 154);
			this->mazeBox42->Name = L"mazeBox42";
			this->mazeBox42->Size = System::Drawing::Size(25, 25);
			this->mazeBox42->TabIndex = 9;
			this->mazeBox42->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox42->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox42_Click);
			// 
			// mazeBox32
			// 
			this->mazeBox32->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox32->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox32->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox32->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox32->Location = System::Drawing::Point(74, 113);
			this->mazeBox32->Name = L"mazeBox32";
			this->mazeBox32->Size = System::Drawing::Size(25, 25);
			this->mazeBox32->TabIndex = 8;
			this->mazeBox32->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox32->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox32_Click);
			// 
			// mazeBox22
			// 
			this->mazeBox22->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox22->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox22->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox22->Location = System::Drawing::Point(74, 72);
			this->mazeBox22->Name = L"mazeBox22";
			this->mazeBox22->Size = System::Drawing::Size(25, 25);
			this->mazeBox22->TabIndex = 7;
			this->mazeBox22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox22->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox22_Click);
			// 
			// mazeBox12
			// 
			this->mazeBox12->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox12->ForeColor = System::Drawing::Color::Red;
			this->mazeBox12->Location = System::Drawing::Point(74, 31);
			this->mazeBox12->Name = L"mazeBox12";
			this->mazeBox12->Size = System::Drawing::Size(25, 25);
			this->mazeBox12->TabIndex = 6;
			this->mazeBox12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox12->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox12_Click);
			// 
			// mazeBox61
			// 
			this->mazeBox61->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox61->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox61->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox61->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox61->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox61->Location = System::Drawing::Point(31, 236);
			this->mazeBox61->Name = L"mazeBox61";
			this->mazeBox61->Size = System::Drawing::Size(25, 25);
			this->mazeBox61->TabIndex = 5;
			this->mazeBox61->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox61->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox61_Click);
			// 
			// mazeBox51
			// 
			this->mazeBox51->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox51->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox51->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox51->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox51->Location = System::Drawing::Point(31, 195);
			this->mazeBox51->Name = L"mazeBox51";
			this->mazeBox51->Size = System::Drawing::Size(25, 25);
			this->mazeBox51->TabIndex = 4;
			this->mazeBox51->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox51->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox51_Click);
			// 
			// mazeBox41
			// 
			this->mazeBox41->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox41->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox41->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox41->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox41->Location = System::Drawing::Point(31, 154);
			this->mazeBox41->Name = L"mazeBox41";
			this->mazeBox41->Size = System::Drawing::Size(25, 25);
			this->mazeBox41->TabIndex = 3;
			this->mazeBox41->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox41->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox41_Click);
			// 
			// mazeBox31
			// 
			this->mazeBox31->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox31->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox31->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox31->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox31->Location = System::Drawing::Point(31, 113);
			this->mazeBox31->Name = L"mazeBox31";
			this->mazeBox31->Size = System::Drawing::Size(25, 25);
			this->mazeBox31->TabIndex = 2;
			this->mazeBox31->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox31->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox31_Click);
			// 
			// mazeBox21
			// 
			this->mazeBox21->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox21->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox21->Location = System::Drawing::Point(31, 72);
			this->mazeBox21->Name = L"mazeBox21";
			this->mazeBox21->Size = System::Drawing::Size(25, 25);
			this->mazeBox21->TabIndex = 1;
			this->mazeBox21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox21->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox21_Click);
			// 
			// mazeBox11
			// 
			this->mazeBox11->BackColor = System::Drawing::Color::Transparent;
			this->mazeBox11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBox11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBox11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBox11->ForeColor = System::Drawing::Color::White;
			this->mazeBox11->Location = System::Drawing::Point(31, 31);
			this->mazeBox11->Name = L"mazeBox11";
			this->mazeBox11->Size = System::Drawing::Size(25, 25);
			this->mazeBox11->TabIndex = 0;
			this->mazeBox11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBox11->Click += gcnew System::EventHandler(this, &ModuleMaze::mazeBox11_Click);
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(264, 410);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 12;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ModuleMaze::exitButton_Click);
			// 
			// submitButton
			// 
			this->submitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->submitButton->Location = System::Drawing::Point(134, 385);
			this->submitButton->Margin = System::Windows::Forms::Padding(2);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(68, 25);
			this->submitButton->TabIndex = 11;
			this->submitButton->Text = L"Submit";
			this->submitButton->UseVisualStyleBackColor = true;
			this->submitButton->Click += gcnew System::EventHandler(this, &ModuleMaze::submitButton_Click);
			// 
			// promptLabel
			// 
			this->promptLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->promptLabel->Location = System::Drawing::Point(-1, -1);
			this->promptLabel->Name = L"promptLabel";
			this->promptLabel->Size = System::Drawing::Size(341, 91);
			this->promptLabel->TabIndex = 13;
			this->promptLabel->Text = L"Please select the two green circle reference points, then click submit";
			this->promptLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// resetButton
			// 
			this->resetButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->resetButton->Location = System::Drawing::Point(17, 410);
			this->resetButton->Margin = System::Windows::Forms::Padding(2);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(55, 21);
			this->resetButton->TabIndex = 14;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &ModuleMaze::resetButton_Click);
			// 
			// mazeBoxReference1
			// 
			this->mazeBoxReference1->BackColor = System::Drawing::Color::Transparent;
			this->mazeBoxReference1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBoxReference1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBoxReference1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBoxReference1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBoxReference1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mazeBoxReference1.Image")));
			this->mazeBoxReference1->Location = System::Drawing::Point(104, 407);
			this->mazeBoxReference1->Name = L"mazeBoxReference1";
			this->mazeBoxReference1->Size = System::Drawing::Size(25, 25);
			this->mazeBoxReference1->TabIndex = 95;
			this->mazeBoxReference1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBoxReference1->Visible = false;
			// 
			// mazeBoxReference2
			// 
			this->mazeBoxReference2->BackColor = System::Drawing::Color::Transparent;
			this->mazeBoxReference2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mazeBoxReference2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mazeBoxReference2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeBoxReference2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mazeBoxReference2->Location = System::Drawing::Point(135, 412);
			this->mazeBoxReference2->Name = L"mazeBoxReference2";
			this->mazeBoxReference2->Size = System::Drawing::Size(25, 25);
			this->mazeBoxReference2->TabIndex = 96;
			this->mazeBoxReference2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->mazeBoxReference2->Visible = false;
			// 
			// ModuleMaze
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 438);
			this->Controls->Add(this->mazeBoxReference2);
			this->Controls->Add(this->mazeBoxReference1);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->promptLabel);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->submitButton);
			this->Controls->Add(this->mazeBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ModuleMaze";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Maze";
			this->Load += gcnew System::EventHandler(this, &ModuleMaze::ModuleMaze_Load);
			this->mazeBox->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

private:
	void LocationClick(int y, int x, Label^ CurrentLabel)
	{
		switch (stage)
		{
		case 0: // Selecting Marker Locations
			if ((Clicked[stage, 0, 0] == x && Clicked[stage, 0, 1] == y) || (Clicked[stage, 1, 0] == x && Clicked[stage, 1, 1] == y))
			{ // Unselect
				CurrentLabel->Image = mazeBoxReference2->Image;
				counter--;
				if (Clicked[stage, 0, 0] == x) // Item is in count 0 - Move count 1 to 0
				{
					Clicked[stage, 0, 0] = Clicked[stage, 1, 0];
					Clicked[stage, 0, 1] = Clicked[stage, 1, 1];
				}
				else // Item is in count 1 - Reset to Zero
				{
					Clicked[stage, 1, 0] = 0;
					Clicked[stage, 1, 1] = 0;
				}
			}
			else
			{ // Select if possible
				if (counter < 2)
				{
					CurrentLabel->Image = mazeBoxReference1->Image;
					Clicked[stage, counter, 0] = x;
					Clicked[stage, counter, 1] = y;
					counter++;
				}
			}
			break;
		case 1: // Placing White Box
			if ((Clicked[stage, 0, 0] == x && Clicked[stage, 0, 1] == y) || (Clicked[stage, 1, 0] == x && Clicked[stage, 1, 1] == y))
			{ // Unselect
				CurrentLabel->Text = "";
				counter--;
				if (Clicked[stage, 0, 0] == x) // Item is in count 0 - Move count 1 to 0
				{
					Clicked[stage, 0, 0] = Clicked[stage, 1, 0];
					Clicked[stage, 0, 1] = Clicked[stage, 1, 1];
				}
				else // Item is in count 1 - Reset to Zero
				{
					Clicked[stage, 1, 0] = 0;
					Clicked[stage, 1, 1] = 0;
				}
			}
			else
			{ // Select if possible
				if (counter < 1)
				{
					CurrentLabel->Text = L"■";
					CurrentLabel->ForeColor = System::Drawing::Color::White;
					Clicked[stage, counter, 0] = x;
					Clicked[stage, counter, 1] = y;
					counter++;
				}
			}
			break;
		case 2: // Placing Red Triangle
			if ((Clicked[stage, 0, 0] == x && Clicked[stage, 0, 1] == y) || (Clicked[stage, 1, 0] == x && Clicked[stage, 1, 1] == y))
			{ // Unselect
				CurrentLabel->Text = "";
				counter--;
				if (Clicked[stage, 0, 0] == x) // Item is in count 0 - Move count 1 to 0
				{
					Clicked[stage, 0, 0] = Clicked[stage, 1, 0];
					Clicked[stage, 0, 1] = Clicked[stage, 1, 1];
				}
				else // Item is in count 1 - Reset to Zero
				{
					Clicked[stage, 1, 0] = 0;
					Clicked[stage, 1, 1] = 0;
				}
			}
			else
			{ // Select if possible
				if (counter < 1)
				{
					CurrentLabel->Text = L"▲";
					CurrentLabel->ForeColor = System::Drawing::Color::Red;
					Clicked[stage, counter, 0] = x;
					Clicked[stage, counter, 1] = y;
					counter++;
				}
			}
			break;
		}
	}

	/**
	* Recursively searches a given maze using a depth-first search algorithm, and when a route is determined, build the instructions in reverse order
	* @param Which maze to look at
	* @param The maze reference array (6KB)
	* @param Where the start and end is
	* @param Which direction to search in next
	* @param Current x Location in search
	* @ param Current y Location in search
	* @return String containing all prior steps + current step, being built in reverse order
	*/
	std::string maze_hunter(int mazeNumber, int mazes[9][13][13], int positions[2][2], int direction, int currentX, int currentY) // recursively determine the route for a maze and return a string with the directions
	{ // 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker  - maze reference
	  // -1: unspecified | 0: Up | 1: Right | 2: Down | 3: Left                - direction reference
	  // traverse a path until a split is found, then call this function again, one heading in each direction, and return a string with the direction it turned added to the front of all directions returned previously if the end is reached
		// Check if the end has been reached, if so, terminate function chain
		if (currentX == positions[1][0] && currentY == positions[1][1]) return "Done";
		//cout << "\n0 x:" << currentX << " y: " << currentY << "  ";
		std::string check = "1";
		if (direction == -1)
		{ // determine which directions are valid and start the recursive cascade - probably not return, but check if it is valid
			if (mazes[mazeNumber][positions[0][1] - 1][positions[0][0]] == 2)
			{
				check = maze_hunter(mazeNumber, mazes, positions, 0, positions[0][0], positions[0][1]); // open move available above
				//cout << " 1check: " << check[check.length() - 1] << "\t";
				if (check[check.length() - 1] < '~') return "U" + check; // Determine if a deadend was hit, if not, return the string
				//else cout << "\nignore deadend 0\n";
			}
			if (mazes[mazeNumber][positions[0][1]][positions[0][0] + 1] == 2)
			{
				check = maze_hunter(mazeNumber, mazes, positions, 1, positions[0][0], positions[0][1]); // open move available right
				//cout << " 2check: " << check[check.length() - 1] << "\t";
				if (check[check.length() - 1] < '~') return "R " + check; // Determine if a deadend was hit, if not, return the string
				//else cout << "\nignore deadend 1\n";
			}
			if (mazes[mazeNumber][positions[0][1] + 1][positions[0][0]] == 2)
			{
				check = maze_hunter(mazeNumber, mazes, positions, 2, positions[0][0], positions[0][1]); // open move available down
				//cout << " 3check: " << check[check.length() - 1] << "\t";
				if (check[check.length() - 1] < '~') return "D" + check; // Determine if a deadend was hit, if not, return the string
				//else cout << "\nignore deadend 2\n";
			}
			if (mazes[mazeNumber][positions[0][1]][positions[0][0] - 1] == 2)
			{
				check = maze_hunter(mazeNumber, mazes, positions, 3, positions[0][0], positions[0][1]); // open move available left
				//cout << " 4check: " << check[check.length() - 1] << "\t";
				if (check[check.length() - 1] < '~') return "L" + check; // Determine if a deadend was hit, if not, return the string
				//else cout << "\nignore deadend 3\n";
			}
			//cout << "1";
		}
		//cout << "2: " << direction << " | ";
		// Move in the specified direction
		if (direction == 0) currentY -= 2; // move to next position up
		else if (direction == 1) currentX += 2; // move to next position right
		else if (direction == 2) currentY += 2; // move to next position down
		else if (direction == 3) currentX -= 2; // move to next position left
		else return "Error: Invalid Direction Specified";
		//cout << "3 x:" << currentX << " y: " << currentY << "  ";
		// Check if the end has been reached, if so, terminate function chain
		if (currentX == positions[1][0] && currentY == positions[1][1]) return "End";
		//cout << "4";

		// Determine if in a dead end
		if (direction == 0 && mazes[mazeNumber][currentY][currentX - 1] != 2 && mazes[mazeNumber][currentY][currentX + 1] != 2 && mazes[mazeNumber][currentY + 1][currentX] != 2) return "~";
		else if (direction == 1 && mazes[mazeNumber][currentY][currentX - 1] != 2 && mazes[mazeNumber][currentY - 1][currentX] != 2 && mazes[mazeNumber][currentY + 1][currentX] != 2) return "~";
		else if (direction == 2 && mazes[mazeNumber][currentY][currentX - 1] != 2 && mazes[mazeNumber][currentY][currentX + 1] != 2 && mazes[mazeNumber][currentY - 1][currentX] != 2) return "~";
		else if (direction == 3 && mazes[mazeNumber][currentY - 1][currentX] != 2 && mazes[mazeNumber][currentY][currentX + 1] != 2 && mazes[mazeNumber][currentY + 1][currentX] != 2) return "~";
		//cout << "5: ";
		// Determine the next directions to move, skipping the origin direction  --  Logic seems backwards (only moves in the direction it came from)
		if (mazes[mazeNumber][currentY - 1][currentX] == 2 && direction != 2)
		{
			//cout << "Up";
			check = ("U" + maze_hunter(mazeNumber, mazes, positions, 0, currentX, currentY)); // return the string with the current direction before the next set // open move available above
			//cout << " 5check: " << check[check.length() - 1] << "\t";
			if (check[check.length() - 1] < '~') return check; // Determine if a deadend was hit, if not, return the string
			//else cout << "\nignore deadend5\n";
		}
		if (mazes[mazeNumber][currentY][currentX + 1] == 2 && direction != 3)
		{
			//cout << "Right";
			check = ("R" + maze_hunter(mazeNumber, mazes, positions, 1, currentX, currentY)); // return the string with the current direction before the next set // open move available right
			//cout << " 6check: -" << check[check.length() - 1] << "-\t" << check << "\t" << (check[check.length() - 1] < '~') << endl;
			if (check[check.length() - 1] < '~') return check; // Determine if a deadend was hit, if not, return the string
			//else cout << "\nignore deadend6\n";
		}
		if (mazes[mazeNumber][currentY + 1][currentX] == 2 && direction != 0)
		{
			//cout << "Down";
			check = ("D" + maze_hunter(mazeNumber, mazes, positions, 2, currentX, currentY)); // return the string with the current direction before the next set // open move available down
			//cout << " 7check: " << check[check.length() - 1] << "\t";
			if (check[check.length() - 1] < '~') return check; // Determine if a deadend was hit, if not, return the string
			//else cout << "\nignore deadend7\n";
		}
		if (mazes[mazeNumber][currentY][currentX - 1] == 2 && direction != 1)
		{
			//cout << "Left";
			check = ("L " + maze_hunter(mazeNumber, mazes, positions, 3, currentX, currentY)); // return the string with the current direction before the next set // open move available left
			//cout << " 8check: " << check[check.length() - 1] << "\t";
			if (check[check.length() - 1] < '~') return check; // Determine if a deadend was hit, if not, return the string
			//else cout << "\nignore deadend8\n";
		}

		//cout << "6-";
		return "~";
		//return "Null Error: This Function is not working (Hint: Try Implementing it First)";
	}

	void ShowLine(int line)
	{
		switch (line)
		{
		case 11:
			mazeLine112->Visible = true;
			break;
		case 12:
			mazeLine123->Visible = true;
			break;
		case 13:
			mazeLine134->Visible = true;
			break;
		case 14:
			mazeLine145->Visible = true;
			break;
		case 15:
			mazeLine156->Visible = true;
			break;

		case 21:
			mazeLine21->Visible = true;
			break;
		case 22:
			mazeLine22->Visible = true;
			break;
		case 23:
			mazeLine23->Visible = true;
			break;
		case 24:
			mazeLine24->Visible = true;
			break;
		case 25:
			mazeLine25->Visible = true;
			break;
		case 26:
			mazeLine26->Visible = true;
			break;

		case 31:
			mazeLine312->Visible = true;
			break;
		case 32:
			mazeLine323->Visible = true;
			break;
		case 33:
			mazeLine334->Visible = true;
			break;
		case 34:
			mazeLine345->Visible = true;
			break;
		case 35:
			mazeLine356->Visible = true;
			break;

		case 41:
			mazeLine41->Visible = true;
			break;
		case 42:
			mazeLine42->Visible = true;
			break;
		case 43:
			mazeLine43->Visible = true;
			break;
		case 44:
			mazeLine44->Visible = true;
			break;
		case 45:
			mazeLine45->Visible = true;
			break;
		case 46:
			mazeLine46->Visible = true;
			break;

		case 51:
			mazeLine512->Visible = true;
			break;
		case 52:
			mazeLine523->Visible = true;
			break;
		case 53:
			mazeLine534->Visible = true;
			break;
		case 54:
			mazeLine545->Visible = true;
			break;
		case 55:
			mazeLine556->Visible = true;
			break;

		case 61:
			mazeLine61->Visible = true;
			break;
		case 62:
			mazeLine62->Visible = true;
			break;
		case 63:
			mazeLine63->Visible = true;
			break;
		case 64:
			mazeLine64->Visible = true;
			break;
		case 65:
			mazeLine65->Visible = true;
			break;
		case 66:
			mazeLine66->Visible = true;
			break;

		case 71:
			mazeLine712->Visible = true;
			break;
		case 72:
			mazeLine723->Visible = true;
			break;
		case 73:
			mazeLine734->Visible = true;
			break;
		case 74:
			mazeLine745->Visible = true;
			break;
		case 75:
			mazeLine756->Visible = true;
			break;

		case 81:
			mazeLine81->Visible = true;
			break;
		case 82:
			mazeLine82->Visible = true;
			break;
		case 83:
			mazeLine83->Visible = true;
			break;
		case 84:
			mazeLine84->Visible = true;
			break;
		case 85:
			mazeLine85->Visible = true;
			break;
		case 86:
			mazeLine86->Visible = true;
			break;

		case 91:
			mazeLine912->Visible = true;
			break;
		case 92:
			mazeLine923->Visible = true;
			break;
		case 93:
			mazeLine934->Visible = true;
			break;
		case 94:
			mazeLine945->Visible = true;
			break;
		case 95:
			mazeLine956->Visible = true;
			break;

		case 101:
			mazeLineA1->Visible = true;
			break;
		case 102:
			mazeLineA2->Visible = true;
			break;
		case 103:
			mazeLineA3->Visible = true;
			break;
		case 104:
			mazeLineA4->Visible = true;
			break;
		case 105:
			mazeLineA5->Visible = true;
			break;
		case 106:
			mazeLineA6->Visible = true;
			break;

		case 111:
			mazeLineB12->Visible = true;
			break;
		case 112:
			mazeLineB23->Visible = true;
			break;
		case 113:
			mazeLineB34->Visible = true;
			break;
		case 114:
			mazeLineB45->Visible = true;
			break;
		case 115:
			mazeLineB56->Visible = true;
			break;
		}
	}

	void UpdateLines()
	{
		int lineToShow = 0;
		for (int i = 1; i < 12; i++) // Ignore Top and Bottom Edges
		{
			for (int j = 1; j < 12; j++) // Ignore Sides
			{
				if (Lines[j, i]) // If there should be a line at this position, determine a unique identifier to switch case on to display it
				{
					if (!(i % 2)) // Rows with 6 lines
					{
						lineToShow = i * 10 + ((j + 1) / 2);
					}
					else // Rows with 5 Lines
					{
						lineToShow = i * 10 + (j / 2);
					}
					ShowLine(lineToShow);
				}
			}
		}
	}

	void ResetMaze()
	{
		// Reset Variables to default values
		stage = 0;
		counter = 0;
		mazeID = -1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					Clicked[i, j, k] = 0;
				}
			}
		}
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				Lines[i, j] = false;
			}
		}

		// Hide Maze Path Lines
		mazeLine112->Visible = false;
		mazeLine123->Visible = false;
		mazeLine134->Visible = false;
		mazeLine145->Visible = false;
		mazeLine156->Visible = false;
		mazeLine21->Visible = false;
		mazeLine22->Visible = false;
		mazeLine23->Visible = false;
		mazeLine24->Visible = false;
		mazeLine25->Visible = false;
		mazeLine26->Visible = false;
		mazeLine312->Visible = false;
		mazeLine323->Visible = false;
		mazeLine334->Visible = false;
		mazeLine345->Visible = false;
		mazeLine356->Visible = false;
		mazeLine41->Visible = false;
		mazeLine42->Visible = false;
		mazeLine43->Visible = false;
		mazeLine44->Visible = false;
		mazeLine45->Visible = false;
		mazeLine46->Visible = false;
		mazeLine512->Visible = false;
		mazeLine523->Visible = false;
		mazeLine534->Visible = false;
		mazeLine545->Visible = false;
		mazeLine556->Visible = false;
		mazeLine61->Visible = false;
		mazeLine62->Visible = false;
		mazeLine63->Visible = false;
		mazeLine64->Visible = false;
		mazeLine65->Visible = false;
		mazeLine66->Visible = false;
		mazeLine712->Visible = false;
		mazeLine723->Visible = false;
		mazeLine734->Visible = false;
		mazeLine745->Visible = false;
		mazeLine756->Visible = false;
		mazeLine81->Visible = false;
		mazeLine82->Visible = false;
		mazeLine83->Visible = false;
		mazeLine84->Visible = false;
		mazeLine85->Visible = false;
		mazeLine86->Visible = false;
		mazeLine912->Visible = false;
		mazeLine923->Visible = false;
		mazeLine934->Visible = false;
		mazeLine945->Visible = false;
		mazeLine956->Visible = false;
		mazeLineA1->Visible = false;
		mazeLineA2->Visible = false;
		mazeLineA3->Visible = false;
		mazeLineA4->Visible = false;
		mazeLineA5->Visible = false;
		mazeLineA6->Visible = false;
		mazeLineB12->Visible = false;
		mazeLineB23->Visible = false;
		mazeLineB34->Visible = false;
		mazeLineB45->Visible = false;
		mazeLineB56->Visible = false;

		mazeBox11->Text = "";
		mazeBox11->Image = mazeBoxReference2->Image;
		mazeBox12->Text = "";
		mazeBox12->Image = mazeBoxReference2->Image;
		mazeBox13->Text = "";
		mazeBox13->Image = mazeBoxReference2->Image;
		mazeBox14->Text = "";
		mazeBox14->Image = mazeBoxReference2->Image;
		mazeBox15->Text = "";
		mazeBox15->Image = mazeBoxReference2->Image;
		mazeBox16->Text = "";
		mazeBox16->Image = mazeBoxReference2->Image;
		mazeBox21->Text = "";
		mazeBox21->Image = mazeBoxReference2->Image;
		mazeBox22->Text = "";
		mazeBox22->Image = mazeBoxReference2->Image;
		mazeBox23->Text = "";
		mazeBox23->Image = mazeBoxReference2->Image;
		mazeBox24->Text = "";
		mazeBox24->Image = mazeBoxReference2->Image;
		mazeBox25->Text = "";
		mazeBox25->Image = mazeBoxReference2->Image;
		mazeBox26->Text = "";
		mazeBox26->Image = mazeBoxReference2->Image;
		mazeBox31->Text = "";
		mazeBox31->Image = mazeBoxReference2->Image;
		mazeBox32->Text = "";
		mazeBox32->Image = mazeBoxReference2->Image;
		mazeBox33->Text = "";
		mazeBox33->Image = mazeBoxReference2->Image;
		mazeBox34->Text = "";
		mazeBox34->Image = mazeBoxReference2->Image;
		mazeBox35->Text = "";
		mazeBox35->Image = mazeBoxReference2->Image;
		mazeBox36->Text = "";
		mazeBox36->Image = mazeBoxReference2->Image;
		mazeBox41->Text = "";
		mazeBox41->Image = mazeBoxReference2->Image;
		mazeBox42->Text = "";
		mazeBox42->Image = mazeBoxReference2->Image;
		mazeBox43->Text = "";
		mazeBox43->Image = mazeBoxReference2->Image;
		mazeBox44->Text = "";
		mazeBox44->Image = mazeBoxReference2->Image;
		mazeBox45->Text = "";
		mazeBox45->Image = mazeBoxReference2->Image;
		mazeBox46->Text = "";
		mazeBox46->Image = mazeBoxReference2->Image;
		mazeBox51->Text = "";
		mazeBox51->Image = mazeBoxReference2->Image;
		mazeBox52->Text = "";
		mazeBox52->Image = mazeBoxReference2->Image;
		mazeBox53->Text = "";
		mazeBox53->Image = mazeBoxReference2->Image;
		mazeBox54->Text = "";
		mazeBox54->Image = mazeBoxReference2->Image;
		mazeBox55->Text = "";
		mazeBox55->Image = mazeBoxReference2->Image;
		mazeBox56->Text = "";
		mazeBox56->Image = mazeBoxReference2->Image;
		mazeBox61->Text = "";
		mazeBox61->Image = mazeBoxReference2->Image;
		mazeBox62->Text = "";
		mazeBox62->Image = mazeBoxReference2->Image;
		mazeBox63->Text = "";
		mazeBox63->Image = mazeBoxReference2->Image;
		mazeBox64->Text = "";
		mazeBox64->Image = mazeBoxReference2->Image;
		mazeBox65->Text = "";
		mazeBox65->Image = mazeBoxReference2->Image;
		mazeBox66->Text = "";
		mazeBox66->Image = mazeBoxReference2->Image;

		promptLabel->Text = "Please select the two green circle reference point, Then click submit";
	}

private: System::Void mazeBox11_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(1, 1, mazeBox11);
}
private: System::Void mazeBox12_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(1, 2, mazeBox12);
}
private: System::Void mazeBox13_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(1, 3, mazeBox13);
}
private: System::Void mazeBox14_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(1, 4, mazeBox14);
}
private: System::Void mazeBox15_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(1, 5, mazeBox15);
}
private: System::Void mazeBox16_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(1, 6, mazeBox16);
}
private: System::Void mazeBox21_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(2, 1, mazeBox21);
}
private: System::Void mazeBox22_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(2, 2, mazeBox22);
}
private: System::Void mazeBox23_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(2, 3, mazeBox23);
}
private: System::Void mazeBox24_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(2, 4, mazeBox24);
}
private: System::Void mazeBox25_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(2, 5, mazeBox25);
}
private: System::Void mazeBox26_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(2, 6, mazeBox26);
}
private: System::Void mazeBox31_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(3, 1, mazeBox31);
}
private: System::Void mazeBox32_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(3, 2, mazeBox32);
}
private: System::Void mazeBox33_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(3, 3, mazeBox33);
}
private: System::Void mazeBox34_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(3, 4, mazeBox34);
}
private: System::Void mazeBox35_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(3, 5, mazeBox35);
}
private: System::Void mazeBox36_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(3, 6, mazeBox36);
}
private: System::Void mazeBox41_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(4, 1, mazeBox41);
}
private: System::Void mazeBox42_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(4, 2, mazeBox42);
}
private: System::Void mazeBox43_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(4, 3, mazeBox43);
}
private: System::Void mazeBox44_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(4, 4, mazeBox44);
}
private: System::Void mazeBox45_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(4, 5, mazeBox45);
}
private: System::Void mazeBox46_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(4, 6, mazeBox46);
}
private: System::Void mazeBox51_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(5, 1, mazeBox51);
}
private: System::Void mazeBox52_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(5, 2, mazeBox52);
}
private: System::Void mazeBox53_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(5, 3, mazeBox53);
}
private: System::Void mazeBox54_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(5, 4, mazeBox54);
}
private: System::Void mazeBox55_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(5, 5, mazeBox55);
}
private: System::Void mazeBox56_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(5, 6, mazeBox56);
}
private: System::Void mazeBox61_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(6, 1, mazeBox61);
}
private: System::Void mazeBox62_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(6, 2, mazeBox62);
}
private: System::Void mazeBox63_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(6, 3, mazeBox63);
}
private: System::Void mazeBox64_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(6, 4, mazeBox64);
}
private: System::Void mazeBox65_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(6, 5, mazeBox65);
}
private: System::Void mazeBox66_Click(System::Object^ sender, System::EventArgs^ e) {
	LocationClick(6, 6, mazeBox66);
}

private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ResetMaze();
}
private: System::Void submitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (stage)
	{
	case 0:
		if (counter == 2)
		{
			// Check if the entered Markers correspond to a maze
			int x1 = Clicked[0, 0, 0];
			int y1 = Clicked[0, 0, 1];
			int x2 = Clicked[0, 1, 0];
			int y2 = Clicked[0, 1, 1];
			if (((x1 == 1 && y1 == 2) && (x2 == 6 && y2 == 3)) || ((x2 == 1 && y2 == 2) && (x1 == 6 && y1 == 3)))
				mazeID = 1;
			else if (((x1 == 2 && y1 == 4) && (x2 == 5 && y2 == 2)) || ((x2 == 2 && y2 == 4) && (x1 == 5 && y1 == 2)))
				mazeID = 2;
			else if (((x1 == 4 && y1 == 4) && (x2 == 6 && y2 == 4)) || ((x2 == 4 && y2 == 4) && (x1 == 6 && y1 == 4)))
				mazeID = 3;
			else if (((x1 == 1 && y1 == 1) && (x2 == 1 && y2 == 4)) || ((x2 == 1 && y2 == 1) && (x1 == 1 && y1 == 4)))
				mazeID = 4;
			else if (((x1 == 5 && y1 == 3) && (x2 == 4 && y2 == 6)) || ((x2 == 5 && y2 == 3) && (x1 == 4 && y1 == 6)))
				mazeID = 5;
			else if (((x1 == 3 && y1 == 5) && (x2 == 5 && y2 == 1)) || ((x2 == 3 && y2 == 5) && (x1 == 5 && y1 == 1)))
				mazeID = 6;
			else if (((x1 == 2 && y1 == 1) && (x2 == 2 && y2 == 6)) || ((x2 == 2 && y2 == 1) && (x1 == 2 && y1 == 6)))
				mazeID = 7;
			else if (((x1 == 4 && y1 == 1) && (x2 == 3 && y2 == 4)) || ((x2 == 4 && y2 == 1) && (x1 == 3 && y1 == 4)))
				mazeID = 8;
			else if (((x1 == 3 && y1 == 2) && (x2 == 1 && y2 == 5)) || ((x2 == 3 && y2 == 2) && (x1 == 1 && y1 == 5)))
				mazeID = 9;
			else
			{
				System::Windows::Forms::MessageBox::Show("No Maze Found for Markers Entered", "Error");
				return;
			}
			//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(mazeID), "Debug");
			stage = 1;
			counter = 0;
			promptLabel->Text = L"Please Select where the White Square (start) is Located";
		}
		else
		{
			System::Windows::Forms::MessageBox::Show("Two Markers Must be Entered", "Error");
		}
		break;
	case 1:
		if (counter == 1)
		{
			stage = 2;
			counter = 0;
			promptLabel->Text = L"Please Select where the Red Triangle (end) is Located";
		}
		else
		{
			System::Windows::Forms::MessageBox::Show("White Square Must be Entered", "Error");
		}
		break;
	case 2:
		if (counter == 1)
		{
			stage = 3;
			counter = 0;
			promptLabel->Text = L"Good Copy";

			// 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
			int mazes[9][13][13]{ { {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 1 | 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
		{1,0,2,0,2,0,1,0,2,0,2,0,1}, // 1
		{3,2,3,1,3,2,3,2,3,1,3,1,3},
		{1,5,1,0,2,0,1,0,2,0,2,0,1}, // 2
		{3,2,3,2,3,1,3,1,3,1,3,2,3},
		{1,0,1,0,2,0,1,0,2,0,2,5,1}, // 3
		{3,2,3,1,3,2,3,2,3,1,3,2,3},
		{1,0,1,0,2,0,2,0,1,0,2,0,1}, // 4
		{3,2,3,1,3,1,3,1,3,1,3,2,3},
		{1,0,2,0,2,0,1,0,2,0,1,0,1}, // 5
		{3,2,3,1,3,2,3,2,3,1,3,2,3},
		{1,0,2,0,1,0,2,0,1,0,2,0,1}, // 6
		{3,1,3,1,3,1,3,1,3,1,3,1,3} },
		{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 2 | 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
		{1,0,2,0,2,0,1,0,2,0,2,0,1}, // 1
		{3,1,3,2,3,1,3,2,3,2,3,1,3},
		{1,0,2,0,1,0,2,0,1,5,2,0,1}, // 2
		{3,2,3,1,3,2,3,1,3,1,3,2,3},
		{1,0,1,0,2,0,1,0,2,0,2,0,1}, // 3
		{3,2,3,2,3,1,3,2,3,1,3,2,3},
		{1,0,2,5,1,0,2,0,1,0,1,0,1}, // 4
		{3,2,3,1,3,2,3,1,3,2,3,2,3},
		{1,0,1,0,1,0,1,0,2,0,1,0,1}, // 5
		{3,2,3,2,3,2,3,2,3,1,3,2,3},
		{1,0,1,0,2,0,1,0,2,0,2,0,1}, // 6
		{3,1,3,1,3,1,3,1,3,1,3,1,3} },
		{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 3 | 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
		{1,0,2,0,2,0,1,0,1,0,2,0,1}, // 1
		{3,2,3,1,3,2,3,2,3,2,3,2,3},
		{1,0,1,0,1,0,1,0,2,0,1,0,1}, // 2
		{3,1,3,2,3,2,3,1,3,1,3,2,3},
		{1,0,2,0,1,0,1,0,2,0,1,0,1}, // 3
		{3,2,3,2,3,2,3,2,3,2,3,2,3},
		{1,0,1,0,1,0,1,5,1,0,1,5,1}, // 4
		{3,2,3,2,3,2,3,2,3,2,3,2,3},
		{1,0,1,0,2,0,1,0,1,0,1,0,1}, // 5
		{3,2,3,1,3,1,3,2,3,2,3,2,3},
		{1,0,2,0,2,0,2,0,1,0,2,0,1}, // 6
		{3,1,3,1,3,1,3,1,3,1,3,1,3} },
		{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 4 | 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
		{1,5,2,0,1,0,2,0,2,0,2,0,1}, // 1
		{3,2,3,2,3,1,3,1,3,1,3,2,3},
		{1,0,1,0,1,0,2,0,2,0,2,0,1}, // 2
		{3,2,3,2,3,2,3,1,3,1,3,2,3},
		{1,0,1,0,2,0,1,0,2,0,1,0,1}, // 3
		{3,2,3,1,3,1,3,2,3,1,3,2,3},
		{1,5,1,0,2,0,2,0,2,0,2,0,1}, // 4
		{3,2,3,1,3,1,3,1,3,1,3,2,3},
		{1,0,2,0,2,0,2,0,2,0,1,0,1}, // 5
		{3,2,3,1,3,1,3,1,3,2,3,2,3},
		{1,0,2,0,2,0,1,0,2,0,1,0,1}, // 6
		{3,1,3,1,3,1,3,1,3,1,3,1,3} },
		{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 5 | 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
		{1,0,2,0,2,0,2,0,2,0,2,0,1}, // 1
		{3,1,3,1,3,1,3,1,3,2,3,2,3},
		{1,0,2,0,2,0,2,0,2,0,1,0,1}, // 2
		{3,2,3,1,3,1,3,2,3,1,3,1,3},
		{1,0,2,0,1,0,2,0,1,5,2,0,1}, // 3
		{3,2,3,2,3,1,3,1,3,2,3,2,3},
		{1,0,1,0,2,0,2,0,1,0,1,0,1}, // 4
		{3,2,3,1,3,1,3,2,3,1,3,2,3},
		{1,0,1,0,2,0,2,0,2,0,1,0,1}, // 5
		{3,2,3,2,3,1,3,1,3,1,3,2,3},
		{1,0,1,0,2,0,2,5,2,0,2,0,1}, // 6
		{3,1,3,1,3,1,3,1,3,1,3,1,3} },
		{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 6 | 0: Space | 1 : Border | 2 : Open Border | 3 : Null | 4 : TBD | 5 : Marker
		{1,0,1,0,2,0,1,0,2,5,2,0,1}, // 1
		{3,2,3,2,3,2,3,1,3,2,3,2,3},
		{1,0,1,0,1,0,1,0,2,0,1,0,1}, // 2
		{3,2,3,2,3,2,3,2,3,1,3,2,3},
		{1,0,2,0,1,0,1,0,1,0,2,0,1}, // 3
		{3,2,3,1,3,1,3,2,3,2,3,1,3},
		{1,0,2,0,1,0,2,0,1,0,1,0,1}, // 4
		{3,1,3,2,3,2,3,2,3,2,3,2,3},
		{1,0,2,0,1,5,1,0,1,0,2,0,1}, // 5
		{3,2,3,1,3,1,3,2,3,1,3,2,3},
		{1,0,2,0,2,0,2,0,1,0,2,0,1}, // 6
		{3,1,3,1,3,1,3,1,3,1,3,1,3} },
		{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 7 | 0: Space | 1 : Border | 2 : Open Border | 3 : Null | 4 : TBD | 5 : Marker
		{1,0,2,5,2,0,2,0,1,0,2,0,1}, // 1
		{3,2,3,1,3,1,3,2,3,2,3,2,3},
		{1,0,1,0,2,0,1,0,2,0,1,0,1}, // 2
		{3,2,3,2,3,1,3,1,3,1,3,2,3},
		{1,0,2,0,1,0,2,0,1,0,2,0,1}, // 3
		{3,1,3,1,3,2,3,1,3,2,3,1,3},
		{1,0,2,0,1,0,2,0,2,0,1,0,1}, // 4
		{3,2,3,2,3,2,3,1,3,1,3,2,3},
		{1,0,1,0,1,0,2,0,2,0,1,0,1}, // 5
		{3,2,3,1,3,1,3,1,3,2,3,2,3},
		{1,0,2,5,2,0,2,0,2,0,2,0,1}, // 6
		{3,1,3,1,3,1,3,1,3,1,3,1,3} },
		{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 8 | 0: Space | 1 : Border | 2 : Open Border | 3 : Null | 4 : TBD | 5 : Marker
		{1,0,1,0,2,0,2,5,1,0,2,0,1}, // 1
		{3,2,3,2,3,1,3,2,3,2,3,2,3},
		{1,0,2,0,2,0,1,0,2,0,1,0,1}, // 2
		{3,2,3,1,3,1,3,1,3,1,3,2,3},
		{1,0,1,0,2,0,2,0,2,0,1,0,1}, // 3
		{3,2,3,2,3,1,3,1,3,2,3,2,3},
		{1,0,1,0,2,5,1,0,2,0,2,0,1}, // 4
		{3,2,3,1,3,2,3,1,3,1,3,1,3},
		{1,0,1,0,1,0,2,0,2,0,2,0,1}, // 5
		{3,2,3,2,3,1,3,1,3,1,3,1,3},
		{1,0,2,0,2,0,2,0,2,0,2,0,1}, // 6
		{3,1,3,1,3,1,3,1,3,1,3,1,3} },
		{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 9 | 0: Space | 1 : Border | 2 : Open Border | 3 : Null | 4 : TBD | 5 : Marker
		{1,0,1,0,2,0,2,0,2,0,2,0,1}, // 1
		{3,2,3,2,3,1,3,1,3,2,3,2,3},
		{1,0,1,0,1,5,2,0,1,0,1,0,1}, // 2
		{3,2,3,2,3,2,3,1,3,2,3,2,3},
		{1,0,2,0,2,0,1,0,2,0,1,0,1}, // 3
		{3,2,3,1,3,1,3,2,3,1,3,2,3},
		{1,0,1,0,1,0,2,0,1,0,2,0,1}, // 4
		{3,2,3,2,3,2,3,1,3,1,3,2,3},
		{1,5,1,0,1,0,1,0,2,0,1,0,1}, // 5
		{3,2,3,2,3,2,3,2,3,2,3,1,3},
		{1,0,2,0,1,0,2,0,1,0,2,0,1}, // 6
		{3,1,3,1,3,1,3,1,3,1,3,1,3} } }; // 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
			// Nearly 6KB of Data stored in the mazes array


		const int offset = 1;
			// 2 x,y pairs for the start and end positions (adjusted position to reflect location in full reference array) | 0 = start | 1 = end
		int positions[2][2] = { {Clicked[1, 0, 0] * 2 - offset, Clicked[1, 0, 1] * 2 - offset},{Clicked[2, 0, 0] * 2 - offset, Clicked[2, 0, 1] * 2 - offset} }; // White Square, Red Triangle

			// Determine Path through Maze Recursively using a depth-first search
			std::string thePath = maze_hunter(mazeID - 1, mazes, positions, -1, positions[0][0], positions[0][1]);
			System::String^ Path = "";

			// Build a System String based on the directions in the std string, and store the path in a seperate array to draw later
			for (int i = 0; i < thePath.length(); i++)
			{
				switch (thePath[i])
				{
				case 'R':
					Path += L"Right, ";
					Lines[positions[0][0]+1, positions[0][1]] = true; // Show Line to the right
					positions[0][0] += 2; // Move to next location
					break;
				case 'U':
					Path += L"Up, ";
					Lines[positions[0][0], positions[0][1]-1] = true; // Show Line to the right
					positions[0][1] -= 2; // Move to next location
					break;
				case 'D':
					Path += L"Down, ";
					Lines[positions[0][0], positions[0][1]+1] = true; // Show Line to the right
					positions[0][1] += 2; // Move to next location
					break;
				case 'L':
					Path += L"Left, ";
					Lines[positions[0][0] - 1, positions[0][1]] = true; // Show Line to the right
					positions[0][0] -= 2; // Move to next location
					break;
				}
			}
			UpdateLines(); // Parse the Array that was built to numeric ID codes to know which lines to make visible
			promptLabel->Text = Path->Substring(0,Path->Length - 2); // Output rebuilt path, excluding the final ", "
		}
		else
		{
			System::Windows::Forms::MessageBox::Show("Red Triangle Must be Entered", "Error");
		}
		break;
	}
}

private: System::Void ModuleMaze_Load(System::Object^ sender, System::EventArgs^ e) {
	ResetMaze();
}

};
}
