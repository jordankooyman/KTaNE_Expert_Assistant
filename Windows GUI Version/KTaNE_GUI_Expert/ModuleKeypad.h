/**********************************************************
   file: ModuleKeypad.h
 author: Jordan Kooyman and Bradley Walby
purpose: Contains Keypad module window with all interaction elements and the calculations for keypad (original by Bradley, ported by Jordan) as a member function
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
	/// Summary for ModuleKeypad
	/// </summary>
	public ref class ModuleKeypad : public System::Windows::Forms::Form
	{
	public:
		cli::array<bool, 2>^ Clicked;
		ModuleKeypad(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Clicked = gcnew cli::array<bool,2>(9,3);
			for (int i = 0; i < 9; i++) // Initialize array to falses
			{
				for (int j = 0; j < 3; j++)
				{
					Clicked[i, j] = false;
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ModuleKeypad()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ symbol11;
	private: System::Windows::Forms::Label^ symbol12;
	private: System::Windows::Forms::Label^ symbol13;
	private: System::Windows::Forms::Label^ symbol14;
	private: System::Windows::Forms::Label^ symbol15;
	protected:





	private: System::Windows::Forms::Label^ symbol21;
	private: System::Windows::Forms::Label^ symbol22;
	private: System::Windows::Forms::Label^ symbol23;
	private: System::Windows::Forms::Label^ symbol24;
	private: System::Windows::Forms::Label^ symbol16;



	protected:

	protected:

	protected:









	private: System::Windows::Forms::Label^ symbol31;
	private: System::Windows::Forms::Label^ symbol32;
	private: System::Windows::Forms::Label^ symbol33;
	private: System::Windows::Forms::Label^ symbol34;
	private: System::Windows::Forms::Label^ symbol17;






	private: System::Windows::Forms::Label^ symbol35;
	private: System::Windows::Forms::Label^ symbol36;
	private: System::Windows::Forms::Label^ symbol37;
	private: System::Windows::Forms::Label^ symbol18;





	private: System::Windows::Forms::Label^ symbol27;
	private: System::Windows::Forms::Label^ symbol28;



	private: System::Windows::Forms::Label^ symbol26;

	private: System::Windows::Forms::Label^ symbol39;

	private: System::Windows::Forms::Label^ symbol38;
	private: System::Windows::Forms::Label^ symbol19;


	private: System::Windows::Forms::Label^ symbol29;


	private: System::Windows::Forms::Label^ symbol25;
	private: System::Windows::Forms::GroupBox^ symbolsContainer;


	private: System::Windows::Forms::Label^ result1;
	private: System::Windows::Forms::Label^ result2;
	private: System::Windows::Forms::Label^ result3;
	private: System::Windows::Forms::Label^ result4;




	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::Button^ calcButton;

		   private:
			   const Color ClickedColor = System::Drawing::Color::Green;
			   const Color UnclickedColor = System::Drawing::Color::Black;
			   const Color UnclickedColorB = System::Drawing::SystemColors::ControlLight;
private: System::Windows::Forms::Button^ resetButton;
private: System::Windows::Forms::Label^ s11;
private: System::Windows::Forms::Label^ s25;
private: System::Windows::Forms::Label^ s12;
private: System::Windows::Forms::Label^ s29;
private: System::Windows::Forms::Label^ s13;
private: System::Windows::Forms::Label^ s19;
private: System::Windows::Forms::Label^ s14;
private: System::Windows::Forms::Label^ s38;
private: System::Windows::Forms::Label^ s15;
private: System::Windows::Forms::Label^ s39;
private: System::Windows::Forms::Label^ s34;
private: System::Windows::Forms::Label^ s21;
private: System::Windows::Forms::Label^ s17;
private: System::Windows::Forms::Label^ s26;
private: System::Windows::Forms::Label^ s33;
private: System::Windows::Forms::Label^ s22;
private: System::Windows::Forms::Label^ s35;
private: System::Windows::Forms::Label^ s28;
private: System::Windows::Forms::Label^ s32;
private: System::Windows::Forms::Label^ s23;
private: System::Windows::Forms::Label^ s36;
private: System::Windows::Forms::Label^ s16;
private: System::Windows::Forms::Label^ s27;
private: System::Windows::Forms::Label^ s18;
private: System::Windows::Forms::Label^ s31;
private: System::Windows::Forms::Label^ s37;
private: System::Windows::Forms::Label^ s24;
private: System::Windows::Forms::Label^ promptLabel;
	   int ClickedCount = 0;
public:
	void Calculate() // Searching and matching logic by Bradley Walby, ported to this application by Jordan Kooyman
	{
		if (ClickedCount != 4)
		{
			System::Windows::Forms::MessageBox::Show("4 Symbols Must be Selected", "Error");
			return;
		}
		int keycodes[6][7] = {  { 19, 33, 29, 32, 23, 16, 28},
								{ 35, 19, 28, 39, 14, 16, 18},
								{12, 24, 39, 21, 17, 29, 14},
								{31, 11, 25, 23, 21, 18, 15},
								{26, 15, 25, 27, 11, 37, 13},
								{31, 35, 38, 34, 26, 36, 22} };

		int sym_ref[4];
		int locations[8][2] = { {-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1} };
		int loc_element = 0;
		int column_used = -2;
		int count = 1;
		
		//Inputs
		for (int x = 0; x < 9; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (Clicked[x, y]) // If button clicked
				{
					//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(10 * (y + 1) + (x + 1)), "Debug");
					sym_ref[loc_element] = 10 * (y+1) + (x+1); // store the id to be processed later 
					loc_element++;
				}
			}
		}
		loc_element = 0;

		//Identify the symbols referenced
		for (int column = 0; column < 6; column++) {
			for (int element = 0; element < 7; element++) {
				for (int i = 0; i < 4; i++) {
					if (keycodes[column][element] == sym_ref[i]) {
						locations[loc_element][0] = column;
						locations[loc_element][1] = element;
						loc_element++;
					}
				}
			}
		}

		//identify the correct row to reference
		int col_tally1 = 0, col_tally2 = 0, col_tally3 = 0, col_tally4 = 0, col_tally5 = 0, col_tally6 = 0;
		for (int i = 0; i < 8; i++) {
			switch (locations[i][0]) {
			case 0:
				++col_tally1;
				break;
			case 1:
				++col_tally2;
				break;
			case 2:
				++col_tally3;
				break;
			case 3:
				++col_tally4;
				break;
			case 4:
				++col_tally5;
				break;
			case 5:
				++col_tally6;
				break;
			}

			if (col_tally1 == 4) {
				column_used = 0;
				break;
			}
			else if (col_tally2 == 4) {
				column_used = 1;
				break;
			}
			else if (col_tally3 == 4) {
				column_used = 2;
				break;
			}
			else if (col_tally4 == 4) {
				column_used = 3;
				break;
			}
			else if (col_tally5 == 4) {
				column_used = 4;
				break;
			}
			else if (col_tally6 == 4) {
				column_used = 5;
				break;
			}
			else {
			}
		}

		//Display the four inputs in the correct order
		int counter = 1;
		for (int i = 0; i < 8; i++) {
			Label^ thisLabel;
			if (locations[i][0] == column_used) { // if current item is in the desired column
				//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(column_used), "Debug 1");
				//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(keycodes[locations[i][0]][locations[i][1]]), "Debug 2");
				switch (keycodes[locations[i][0]][locations[i][1]])
				{
				case 11:
					thisLabel = symbol11;
					break;
				case 12:
					thisLabel = symbol12;
					break;
				case 13:
					thisLabel = symbol13;
					break;
				case 14:
					thisLabel = symbol14;
					break;
				case 15:
					thisLabel = symbol15;
					break;
				case 16:
					thisLabel = symbol16;
					break;
				case 17:
					thisLabel = symbol17;
					break;
				case 18:
					thisLabel = symbol18;
					break;
				case 19:
					thisLabel = symbol19;
					break;
				case 21:
					thisLabel = symbol21;
					break;
				case 22:
					thisLabel = symbol22;
					break;
				case 23:
					thisLabel = symbol23;
					break;
				case 24:
					thisLabel = symbol24;
					break;
				case 25:
					thisLabel = symbol25;
					break;
				case 26:
					thisLabel = symbol26;
					break;
				case 27:
					thisLabel = symbol27;
					break;
				case 28:
					thisLabel = symbol28;
					break;
				case 29:
					thisLabel = symbol29;
					break;
				case 31:
					thisLabel = symbol31;
					break;
				case 32:
					thisLabel = symbol32;
					break;
				case 33:
					thisLabel = symbol33;
					break;
				case 34:
					thisLabel = symbol34;
					break;
				case 35:
					thisLabel = symbol35;
					break;
				case 36:
					thisLabel = symbol36;
					break;
				case 37:
					thisLabel = symbol37;
					break;
				case 38:
					thisLabel = symbol38;
					break;
				case 39:
					thisLabel = symbol39;
					break;
				}
				switch (counter)
				{
				case 1:
					result1->Text = thisLabel->Text;
					result1->Font = thisLabel->Font;
					result1->Image = thisLabel->Image;
					result1->Visible = true;
					counter++;
					break;
				case 2:
					result2->Text = thisLabel->Text;
					result2->Font = thisLabel->Font;
					result2->Image = thisLabel->Image;
					result2->Visible = true;
					counter++;
					break;
				case 3:
					result3->Text = thisLabel->Text;
					result3->Font = thisLabel->Font;
					result3->Image = thisLabel->Image;
					result3->Visible = true;
					counter++;
					break;
				case 4:
					result4->Text = thisLabel->Text;
					result4->Font = thisLabel->Font;
					result4->Image = thisLabel->Image;
					result4->Visible = true;
					counter++;
					break;
				}
				//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(counter), "Debug 3");
			}
		}
		if (counter != 5)
		{
			System::Windows::Forms::MessageBox::Show("No Combination Found\nPlease Check Your Inputs", "Error");
		}
		else // If a combination has been output, hide the prompt covering it
			promptLabel->Visible = false;
	}
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModuleKeypad::typeid));
			this->symbol11 = (gcnew System::Windows::Forms::Label());
			this->symbol12 = (gcnew System::Windows::Forms::Label());
			this->symbol13 = (gcnew System::Windows::Forms::Label());
			this->symbol14 = (gcnew System::Windows::Forms::Label());
			this->symbol15 = (gcnew System::Windows::Forms::Label());
			this->symbol21 = (gcnew System::Windows::Forms::Label());
			this->symbol22 = (gcnew System::Windows::Forms::Label());
			this->symbol23 = (gcnew System::Windows::Forms::Label());
			this->symbol24 = (gcnew System::Windows::Forms::Label());
			this->symbol16 = (gcnew System::Windows::Forms::Label());
			this->symbol31 = (gcnew System::Windows::Forms::Label());
			this->symbol32 = (gcnew System::Windows::Forms::Label());
			this->symbol33 = (gcnew System::Windows::Forms::Label());
			this->symbol34 = (gcnew System::Windows::Forms::Label());
			this->symbol17 = (gcnew System::Windows::Forms::Label());
			this->symbol35 = (gcnew System::Windows::Forms::Label());
			this->symbol36 = (gcnew System::Windows::Forms::Label());
			this->symbol37 = (gcnew System::Windows::Forms::Label());
			this->symbol18 = (gcnew System::Windows::Forms::Label());
			this->symbol27 = (gcnew System::Windows::Forms::Label());
			this->symbol28 = (gcnew System::Windows::Forms::Label());
			this->symbol26 = (gcnew System::Windows::Forms::Label());
			this->symbol39 = (gcnew System::Windows::Forms::Label());
			this->symbol38 = (gcnew System::Windows::Forms::Label());
			this->symbol19 = (gcnew System::Windows::Forms::Label());
			this->symbol29 = (gcnew System::Windows::Forms::Label());
			this->symbol25 = (gcnew System::Windows::Forms::Label());
			this->symbolsContainer = (gcnew System::Windows::Forms::GroupBox());
			this->s11 = (gcnew System::Windows::Forms::Label());
			this->s25 = (gcnew System::Windows::Forms::Label());
			this->s12 = (gcnew System::Windows::Forms::Label());
			this->s29 = (gcnew System::Windows::Forms::Label());
			this->s13 = (gcnew System::Windows::Forms::Label());
			this->s19 = (gcnew System::Windows::Forms::Label());
			this->s14 = (gcnew System::Windows::Forms::Label());
			this->s38 = (gcnew System::Windows::Forms::Label());
			this->s15 = (gcnew System::Windows::Forms::Label());
			this->s39 = (gcnew System::Windows::Forms::Label());
			this->s34 = (gcnew System::Windows::Forms::Label());
			this->s21 = (gcnew System::Windows::Forms::Label());
			this->s17 = (gcnew System::Windows::Forms::Label());
			this->s26 = (gcnew System::Windows::Forms::Label());
			this->s33 = (gcnew System::Windows::Forms::Label());
			this->s22 = (gcnew System::Windows::Forms::Label());
			this->s35 = (gcnew System::Windows::Forms::Label());
			this->s28 = (gcnew System::Windows::Forms::Label());
			this->s32 = (gcnew System::Windows::Forms::Label());
			this->s23 = (gcnew System::Windows::Forms::Label());
			this->s36 = (gcnew System::Windows::Forms::Label());
			this->s16 = (gcnew System::Windows::Forms::Label());
			this->s27 = (gcnew System::Windows::Forms::Label());
			this->s18 = (gcnew System::Windows::Forms::Label());
			this->s31 = (gcnew System::Windows::Forms::Label());
			this->s37 = (gcnew System::Windows::Forms::Label());
			this->s24 = (gcnew System::Windows::Forms::Label());
			this->result1 = (gcnew System::Windows::Forms::Label());
			this->result2 = (gcnew System::Windows::Forms::Label());
			this->result3 = (gcnew System::Windows::Forms::Label());
			this->result4 = (gcnew System::Windows::Forms::Label());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->calcButton = (gcnew System::Windows::Forms::Button());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->promptLabel = (gcnew System::Windows::Forms::Label());
			this->symbolsContainer->SuspendLayout();
			this->SuspendLayout();
			// 
			// symbol11
			// 
			this->symbol11->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol11->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol11->Font = (gcnew System::Drawing::Font(L"Century", 33, System::Drawing::FontStyle::Bold));
			this->symbol11->Location = System::Drawing::Point(27, 29);
			this->symbol11->Name = L"symbol11";
			this->symbol11->Size = System::Drawing::Size(66, 65);
			this->symbol11->TabIndex = 0;
			this->symbol11->Text = L"¶";
			this->symbol11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol11->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol11_Click);
			// 
			// symbol12
			// 
			this->symbol12->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol12->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol12->Font = (gcnew System::Drawing::Font(L"Century", 42, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->symbol12->Location = System::Drawing::Point(104, 29);
			this->symbol12->Name = L"symbol12";
			this->symbol12->Size = System::Drawing::Size(66, 65);
			this->symbol12->TabIndex = 1;
			this->symbol12->Text = L"©";
			this->symbol12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol12->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol12_Click);
			// 
			// symbol13
			// 
			this->symbol13->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol13->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol13->Font = (gcnew System::Drawing::Font(L"Century", 34, System::Drawing::FontStyle::Bold));
			this->symbol13->Location = System::Drawing::Point(181, 29);
			this->symbol13->Name = L"symbol13";
			this->symbol13->Size = System::Drawing::Size(66, 65);
			this->symbol13->TabIndex = 2;
			this->symbol13->Text = L"★";
			this->symbol13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol13->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol13_Click);
			// 
			// symbol14
			// 
			this->symbol14->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol14->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol14->Font = (gcnew System::Drawing::Font(L"Century", 34, System::Drawing::FontStyle::Bold));
			this->symbol14->Location = System::Drawing::Point(258, 29);
			this->symbol14->Name = L"symbol14";
			this->symbol14->Size = System::Drawing::Size(66, 65);
			this->symbol14->TabIndex = 3;
			this->symbol14->Text = L"☆";
			this->symbol14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol14->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol14_Click);
			// 
			// symbol15
			// 
			this->symbol15->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol15->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol15->Font = (gcnew System::Drawing::Font(L"Century", 40, System::Drawing::FontStyle::Bold));
			this->symbol15->Location = System::Drawing::Point(335, 29);
			this->symbol15->Name = L"symbol15";
			this->symbol15->Size = System::Drawing::Size(66, 65);
			this->symbol15->TabIndex = 4;
			this->symbol15->Text = L"ټ";
			this->symbol15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol15->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol15_Click);
			// 
			// symbol21
			// 
			this->symbol21->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol21->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol21->Font = (gcnew System::Drawing::Font(L"Century", 32, System::Drawing::FontStyle::Bold));
			this->symbol21->Location = System::Drawing::Point(27, 107);
			this->symbol21->Name = L"symbol21";
			this->symbol21->Size = System::Drawing::Size(66, 65);
			this->symbol21->TabIndex = 5;
			this->symbol21->Text = L"Җ";
			this->symbol21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol21->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol21_Click);
			// 
			// symbol22
			// 
			this->symbol22->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol22->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol22->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol22->Font = (gcnew System::Drawing::Font(L"Century", 38, System::Drawing::FontStyle::Bold));
			this->symbol22->Location = System::Drawing::Point(104, 107);
			this->symbol22->Name = L"symbol22";
			this->symbol22->Size = System::Drawing::Size(66, 65);
			this->symbol22->TabIndex = 6;
			this->symbol22->Text = L"Ω";
			this->symbol22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol22->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol22_Click);
			// 
			// symbol23
			// 
			this->symbol23->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol23->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol23->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol23->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->symbol23->Location = System::Drawing::Point(181, 107);
			this->symbol23->Name = L"symbol23";
			this->symbol23->Size = System::Drawing::Size(66, 65);
			this->symbol23->TabIndex = 7;
			this->symbol23->Text = L"Ѭ";
			this->symbol23->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol23->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol23_Click);
			// 
			// symbol24
			// 
			this->symbol24->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol24->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol24->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol24->Font = (gcnew System::Drawing::Font(L"Century", 32, System::Drawing::FontStyle::Bold));
			this->symbol24->Location = System::Drawing::Point(258, 107);
			this->symbol24->Name = L"symbol24";
			this->symbol24->Size = System::Drawing::Size(66, 65);
			this->symbol24->TabIndex = 8;
			this->symbol24->Text = L"Ѽ";
			this->symbol24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol24->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol24_Click);
			// 
			// symbol16
			// 
			this->symbol16->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol16->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol16->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol16->Font = (gcnew System::Drawing::Font(L"Century", 38, System::Drawing::FontStyle::Bold));
			this->symbol16->Location = System::Drawing::Point(412, 29);
			this->symbol16->Name = L"symbol16";
			this->symbol16->Size = System::Drawing::Size(66, 65);
			this->symbol16->TabIndex = 9;
			this->symbol16->Text = L"ϗ";
			this->symbol16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol16->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol16_Click);
			// 
			// symbol31
			// 
			this->symbol31->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol31->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol31->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol31->Font = (gcnew System::Drawing::Font(L"Century", 39, System::Drawing::FontStyle::Bold));
			this->symbol31->Location = System::Drawing::Point(27, 184);
			this->symbol31->Name = L"symbol31";
			this->symbol31->Size = System::Drawing::Size(66, 65);
			this->symbol31->TabIndex = 10;
			this->symbol31->Text = L"б";
			this->symbol31->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol31->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol31_Click);
			// 
			// symbol32
			// 
			this->symbol32->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol32->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol32->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol32->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->symbol32->Location = System::Drawing::Point(104, 184);
			this->symbol32->Name = L"symbol32";
			this->symbol32->Size = System::Drawing::Size(66, 65);
			this->symbol32->TabIndex = 11;
			this->symbol32->Text = L"ϟ";
			this->symbol32->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol32->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol32_Click);
			// 
			// symbol33
			// 
			this->symbol33->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol33->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol33->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol33->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->symbol33->Location = System::Drawing::Point(181, 184);
			this->symbol33->Name = L"symbol33";
			this->symbol33->Size = System::Drawing::Size(66, 65);
			this->symbol33->TabIndex = 12;
			this->symbol33->Text = L"Ѧ";
			this->symbol33->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol33->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol33_Click);
			// 
			// symbol34
			// 
			this->symbol34->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol34->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol34->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol34->Font = (gcnew System::Drawing::Font(L"Century", 39, System::Drawing::FontStyle::Bold));
			this->symbol34->Location = System::Drawing::Point(258, 184);
			this->symbol34->Name = L"symbol34";
			this->symbol34->Size = System::Drawing::Size(66, 65);
			this->symbol34->TabIndex = 13;
			this->symbol34->Text = L"æ";
			this->symbol34->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol34->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol34_Click);
			// 
			// symbol17
			// 
			this->symbol17->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol17->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol17->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol17->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->symbol17->Location = System::Drawing::Point(489, 29);
			this->symbol17->Name = L"symbol17";
			this->symbol17->Size = System::Drawing::Size(66, 65);
			this->symbol17->TabIndex = 14;
			this->symbol17->Text = L"Ԇ";
			this->symbol17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol17->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol17_Click);
			// 
			// symbol35
			// 
			this->symbol35->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol35->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol35->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol35->Font = (gcnew System::Drawing::Font(L"Century", 32, System::Drawing::FontStyle::Bold));
			this->symbol35->Location = System::Drawing::Point(335, 184);
			this->symbol35->Name = L"symbol35";
			this->symbol35->Size = System::Drawing::Size(66, 65);
			this->symbol35->TabIndex = 15;
			this->symbol35->Text = L"Ӭ";
			this->symbol35->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol35->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol35_Click);
			// 
			// symbol36
			// 
			this->symbol36->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol36->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol36->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol36->Font = (gcnew System::Drawing::Font(L"Century", 34, System::Drawing::FontStyle::Bold));
			this->symbol36->Location = System::Drawing::Point(412, 184);
			this->symbol36->Name = L"symbol36";
			this->symbol36->Size = System::Drawing::Size(66, 65);
			this->symbol36->TabIndex = 16;
			this->symbol36->Text = L"Ҋ";
			this->symbol36->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol36->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol36_Click);
			// 
			// symbol37
			// 
			this->symbol37->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol37->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol37->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol37->Font = (gcnew System::Drawing::Font(L"Century", 34, System::Drawing::FontStyle::Bold));
			this->symbol37->Location = System::Drawing::Point(489, 184);
			this->symbol37->Name = L"symbol37";
			this->symbol37->Size = System::Drawing::Size(66, 65);
			this->symbol37->TabIndex = 17;
			this->symbol37->Text = L"Ѯ";
			this->symbol37->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol37->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol37_Click);
			// 
			// symbol18
			// 
			this->symbol18->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol18->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol18->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol18->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->symbol18->Location = System::Drawing::Point(566, 29);
			this->symbol18->Name = L"symbol18";
			this->symbol18->Size = System::Drawing::Size(66, 65);
			this->symbol18->TabIndex = 18;
			this->symbol18->Text = L"¿";
			this->symbol18->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol18->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol18_Click);
			// 
			// symbol27
			// 
			this->symbol27->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol27->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol27->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol27->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->symbol27->Location = System::Drawing::Point(489, 107);
			this->symbol27->Name = L"symbol27";
			this->symbol27->Size = System::Drawing::Size(66, 65);
			this->symbol27->TabIndex = 19;
			this->symbol27->Text = L"Ͼ";
			this->symbol27->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol27->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol27_Click);
			// 
			// symbol28
			// 
			this->symbol28->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol28->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol28->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol28->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->symbol28->Location = System::Drawing::Point(566, 107);
			this->symbol28->Name = L"symbol28";
			this->symbol28->Size = System::Drawing::Size(66, 65);
			this->symbol28->TabIndex = 20;
			this->symbol28->Text = L"Ͽ";
			this->symbol28->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol28->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol28_Click);
			// 
			// symbol26
			// 
			this->symbol26->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol26->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol26->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol26->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->symbol26->Location = System::Drawing::Point(412, 107);
			this->symbol26->Name = L"symbol26";
			this->symbol26->Size = System::Drawing::Size(66, 65);
			this->symbol26->TabIndex = 21;
			this->symbol26->Text = L"Ψ";
			this->symbol26->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol26->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol26_Click);
			// 
			// symbol39
			// 
			this->symbol39->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol39->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol39->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol39->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->symbol39->Location = System::Drawing::Point(643, 184);
			this->symbol39->Name = L"symbol39";
			this->symbol39->Size = System::Drawing::Size(66, 65);
			this->symbol39->TabIndex = 22;
			this->symbol39->Text = L"Ҩ";
			this->symbol39->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol39->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol39_Click);
			// 
			// symbol38
			// 
			this->symbol38->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol38->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol38->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol38->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->symbol38->Location = System::Drawing::Point(566, 184);
			this->symbol38->Name = L"symbol38";
			this->symbol38->Size = System::Drawing::Size(66, 65);
			this->symbol38->TabIndex = 23;
			this->symbol38->Text = L"҂";
			this->symbol38->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol38->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol38_Click);
			// 
			// symbol19
			// 
			this->symbol19->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol19->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol19->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol19->Font = (gcnew System::Drawing::Font(L"Century", 40, System::Drawing::FontStyle::Bold));
			this->symbol19->Location = System::Drawing::Point(643, 29);
			this->symbol19->Name = L"symbol19";
			this->symbol19->Size = System::Drawing::Size(66, 65);
			this->symbol19->TabIndex = 24;
			this->symbol19->Text = L"ϙ";
			this->symbol19->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol19->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol19_Click);
			// 
			// symbol29
			// 
			this->symbol29->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol29->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol29->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol29->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->symbol29->Location = System::Drawing::Point(643, 107);
			this->symbol29->Name = L"symbol29";
			this->symbol29->Size = System::Drawing::Size(66, 65);
			this->symbol29->TabIndex = 25;
			this->symbol29->Text = L"ƛ";
			this->symbol29->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol29->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol29_Click);
			// 
			// symbol25
			// 
			this->symbol25->BackColor = System::Drawing::SystemColors::ControlLight;
			this->symbol25->Cursor = System::Windows::Forms::Cursors::Hand;
			this->symbol25->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->symbol25->Font = (gcnew System::Drawing::Font(L"Century", 37, System::Drawing::FontStyle::Bold));
			this->symbol25->Location = System::Drawing::Point(335, 107);
			this->symbol25->Name = L"symbol25";
			this->symbol25->Size = System::Drawing::Size(66, 65);
			this->symbol25->TabIndex = 26;
			this->symbol25->Text = L"Ѣ";
			this->symbol25->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->symbol25->Click += gcnew System::EventHandler(this, &ModuleKeypad::symbol25_Click);
			// 
			// symbolsContainer
			// 
			this->symbolsContainer->Controls->Add(this->symbol11);
			this->symbolsContainer->Controls->Add(this->symbol25);
			this->symbolsContainer->Controls->Add(this->symbol12);
			this->symbolsContainer->Controls->Add(this->symbol29);
			this->symbolsContainer->Controls->Add(this->symbol13);
			this->symbolsContainer->Controls->Add(this->symbol19);
			this->symbolsContainer->Controls->Add(this->symbol14);
			this->symbolsContainer->Controls->Add(this->symbol38);
			this->symbolsContainer->Controls->Add(this->symbol15);
			this->symbolsContainer->Controls->Add(this->symbol39);
			this->symbolsContainer->Controls->Add(this->symbol21);
			this->symbolsContainer->Controls->Add(this->symbol26);
			this->symbolsContainer->Controls->Add(this->symbol22);
			this->symbolsContainer->Controls->Add(this->symbol28);
			this->symbolsContainer->Controls->Add(this->symbol23);
			this->symbolsContainer->Controls->Add(this->symbol27);
			this->symbolsContainer->Controls->Add(this->symbol24);
			this->symbolsContainer->Controls->Add(this->symbol18);
			this->symbolsContainer->Controls->Add(this->symbol16);
			this->symbolsContainer->Controls->Add(this->symbol37);
			this->symbolsContainer->Controls->Add(this->symbol31);
			this->symbolsContainer->Controls->Add(this->symbol36);
			this->symbolsContainer->Controls->Add(this->symbol32);
			this->symbolsContainer->Controls->Add(this->symbol35);
			this->symbolsContainer->Controls->Add(this->symbol33);
			this->symbolsContainer->Controls->Add(this->symbol17);
			this->symbolsContainer->Controls->Add(this->symbol34);
			this->symbolsContainer->Controls->Add(this->s11);
			this->symbolsContainer->Controls->Add(this->s25);
			this->symbolsContainer->Controls->Add(this->s12);
			this->symbolsContainer->Controls->Add(this->s29);
			this->symbolsContainer->Controls->Add(this->s13);
			this->symbolsContainer->Controls->Add(this->s19);
			this->symbolsContainer->Controls->Add(this->s14);
			this->symbolsContainer->Controls->Add(this->s38);
			this->symbolsContainer->Controls->Add(this->s15);
			this->symbolsContainer->Controls->Add(this->s39);
			this->symbolsContainer->Controls->Add(this->s34);
			this->symbolsContainer->Controls->Add(this->s21);
			this->symbolsContainer->Controls->Add(this->s17);
			this->symbolsContainer->Controls->Add(this->s26);
			this->symbolsContainer->Controls->Add(this->s33);
			this->symbolsContainer->Controls->Add(this->s22);
			this->symbolsContainer->Controls->Add(this->s35);
			this->symbolsContainer->Controls->Add(this->s28);
			this->symbolsContainer->Controls->Add(this->s32);
			this->symbolsContainer->Controls->Add(this->s23);
			this->symbolsContainer->Controls->Add(this->s36);
			this->symbolsContainer->Controls->Add(this->s16);
			this->symbolsContainer->Controls->Add(this->s27);
			this->symbolsContainer->Controls->Add(this->s18);
			this->symbolsContainer->Controls->Add(this->s31);
			this->symbolsContainer->Controls->Add(this->s37);
			this->symbolsContainer->Controls->Add(this->s24);
			this->symbolsContainer->Location = System::Drawing::Point(29, 24);
			this->symbolsContainer->Name = L"symbolsContainer";
			this->symbolsContainer->Size = System::Drawing::Size(737, 279);
			this->symbolsContainer->TabIndex = 27;
			this->symbolsContainer->TabStop = false;
			// 
			// s11
			// 
			this->s11->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s11->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s11->Font = (gcnew System::Drawing::Font(L"Century", 33, System::Drawing::FontStyle::Bold));
			this->s11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s11.Image")));
			this->s11->Location = System::Drawing::Point(24, 27);
			this->s11->Name = L"s11";
			this->s11->Size = System::Drawing::Size(70, 70);
			this->s11->TabIndex = 27;
			this->s11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s11->Visible = false;
			// 
			// s25
			// 
			this->s25->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s25->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s25->Font = (gcnew System::Drawing::Font(L"Century", 37, System::Drawing::FontStyle::Bold));
			this->s25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s25.Image")));
			this->s25->Location = System::Drawing::Point(332, 105);
			this->s25->Name = L"s25";
			this->s25->Size = System::Drawing::Size(70, 70);
			this->s25->TabIndex = 53;
			this->s25->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s25->Visible = false;
			// 
			// s12
			// 
			this->s12->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s12->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s12->Font = (gcnew System::Drawing::Font(L"Century", 42, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s12.Image")));
			this->s12->Location = System::Drawing::Point(101, 27);
			this->s12->Name = L"s12";
			this->s12->Size = System::Drawing::Size(70, 70);
			this->s12->TabIndex = 28;
			this->s12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s12->Visible = false;
			// 
			// s29
			// 
			this->s29->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s29->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s29->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s29->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s29->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s29.Image")));
			this->s29->Location = System::Drawing::Point(640, 105);
			this->s29->Name = L"s29";
			this->s29->Size = System::Drawing::Size(70, 70);
			this->s29->TabIndex = 52;
			this->s29->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s29->Visible = false;
			// 
			// s13
			// 
			this->s13->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s13->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s13->Font = (gcnew System::Drawing::Font(L"Century", 34, System::Drawing::FontStyle::Bold));
			this->s13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s13.Image")));
			this->s13->Location = System::Drawing::Point(178, 27);
			this->s13->Name = L"s13";
			this->s13->Size = System::Drawing::Size(70, 70);
			this->s13->TabIndex = 29;
			this->s13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s13->Visible = false;
			// 
			// s19
			// 
			this->s19->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s19->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s19->Font = (gcnew System::Drawing::Font(L"Century", 40, System::Drawing::FontStyle::Bold));
			this->s19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s19.Image")));
			this->s19->Location = System::Drawing::Point(640, 27);
			this->s19->Name = L"s19";
			this->s19->Size = System::Drawing::Size(70, 70);
			this->s19->TabIndex = 51;
			this->s19->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s19->Visible = false;
			// 
			// s14
			// 
			this->s14->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s14->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s14->Font = (gcnew System::Drawing::Font(L"Century", 34, System::Drawing::FontStyle::Bold));
			this->s14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s14.Image")));
			this->s14->Location = System::Drawing::Point(255, 27);
			this->s14->Name = L"s14";
			this->s14->Size = System::Drawing::Size(70, 70);
			this->s14->TabIndex = 30;
			this->s14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s14->Visible = false;
			// 
			// s38
			// 
			this->s38->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s38->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s38->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s38->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s38->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s38.Image")));
			this->s38->Location = System::Drawing::Point(563, 182);
			this->s38->Name = L"s38";
			this->s38->Size = System::Drawing::Size(70, 70);
			this->s38->TabIndex = 50;
			this->s38->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s38->Visible = false;
			// 
			// s15
			// 
			this->s15->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s15->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s15->Font = (gcnew System::Drawing::Font(L"Century", 40, System::Drawing::FontStyle::Bold));
			this->s15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s15.Image")));
			this->s15->Location = System::Drawing::Point(332, 27);
			this->s15->Name = L"s15";
			this->s15->Size = System::Drawing::Size(70, 70);
			this->s15->TabIndex = 31;
			this->s15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s15->Visible = false;
			// 
			// s39
			// 
			this->s39->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s39->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s39->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s39->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s39->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s39.Image")));
			this->s39->Location = System::Drawing::Point(640, 182);
			this->s39->Name = L"s39";
			this->s39->Size = System::Drawing::Size(70, 70);
			this->s39->TabIndex = 49;
			this->s39->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s39->Visible = false;
			// 
			// s34
			// 
			this->s34->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s34->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s34->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s34->Font = (gcnew System::Drawing::Font(L"Century", 39, System::Drawing::FontStyle::Bold));
			this->s34->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s34.Image")));
			this->s34->Location = System::Drawing::Point(255, 182);
			this->s34->Name = L"s34";
			this->s34->Size = System::Drawing::Size(70, 70);
			this->s34->TabIndex = 40;
			this->s34->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s34->Visible = false;
			// 
			// s21
			// 
			this->s21->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s21->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s21->Font = (gcnew System::Drawing::Font(L"Century", 32, System::Drawing::FontStyle::Bold));
			this->s21->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s21.Image")));
			this->s21->Location = System::Drawing::Point(24, 105);
			this->s21->Name = L"s21";
			this->s21->Size = System::Drawing::Size(70, 70);
			this->s21->TabIndex = 32;
			this->s21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s21->Visible = false;
			// 
			// s17
			// 
			this->s17->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s17->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s17->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s17.Image")));
			this->s17->Location = System::Drawing::Point(486, 27);
			this->s17->Name = L"s17";
			this->s17->Size = System::Drawing::Size(70, 70);
			this->s17->TabIndex = 41;
			this->s17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s17->Visible = false;
			// 
			// s26
			// 
			this->s26->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s26->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s26->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s26->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s26.Image")));
			this->s26->Location = System::Drawing::Point(409, 105);
			this->s26->Name = L"s26";
			this->s26->Size = System::Drawing::Size(70, 70);
			this->s26->TabIndex = 48;
			this->s26->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s26->Visible = false;
			// 
			// s33
			// 
			this->s33->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s33->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s33->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s33->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s33->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s33.Image")));
			this->s33->Location = System::Drawing::Point(178, 182);
			this->s33->Name = L"s33";
			this->s33->Size = System::Drawing::Size(70, 70);
			this->s33->TabIndex = 39;
			this->s33->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s33->Visible = false;
			// 
			// s22
			// 
			this->s22->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s22->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s22->Font = (gcnew System::Drawing::Font(L"Century", 38, System::Drawing::FontStyle::Bold));
			this->s22->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s22.Image")));
			this->s22->Location = System::Drawing::Point(101, 105);
			this->s22->Name = L"s22";
			this->s22->Size = System::Drawing::Size(70, 70);
			this->s22->TabIndex = 33;
			this->s22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s22->Visible = false;
			// 
			// s35
			// 
			this->s35->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s35->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s35->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s35->Font = (gcnew System::Drawing::Font(L"Century", 32, System::Drawing::FontStyle::Bold));
			this->s35->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s35.Image")));
			this->s35->Location = System::Drawing::Point(332, 182);
			this->s35->Name = L"s35";
			this->s35->Size = System::Drawing::Size(70, 70);
			this->s35->TabIndex = 42;
			this->s35->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s35->Visible = false;
			// 
			// s28
			// 
			this->s28->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s28->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s28->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s28->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s28->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s28.Image")));
			this->s28->Location = System::Drawing::Point(563, 105);
			this->s28->Name = L"s28";
			this->s28->Size = System::Drawing::Size(70, 70);
			this->s28->TabIndex = 47;
			this->s28->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s28->Visible = false;
			// 
			// s32
			// 
			this->s32->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s32->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s32->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s32->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s32->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s32.Image")));
			this->s32->Location = System::Drawing::Point(101, 182);
			this->s32->Name = L"s32";
			this->s32->Size = System::Drawing::Size(70, 70);
			this->s32->TabIndex = 38;
			this->s32->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s32->Visible = false;
			// 
			// s23
			// 
			this->s23->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s23->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s23->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s23->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s23.Image")));
			this->s23->Location = System::Drawing::Point(178, 105);
			this->s23->Name = L"s23";
			this->s23->Size = System::Drawing::Size(70, 70);
			this->s23->TabIndex = 34;
			this->s23->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s23->Visible = false;
			// 
			// s36
			// 
			this->s36->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s36->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s36->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s36->Font = (gcnew System::Drawing::Font(L"Century", 34, System::Drawing::FontStyle::Bold));
			this->s36->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s36.Image")));
			this->s36->Location = System::Drawing::Point(409, 182);
			this->s36->Name = L"s36";
			this->s36->Size = System::Drawing::Size(70, 70);
			this->s36->TabIndex = 43;
			this->s36->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s36->Visible = false;
			// 
			// s16
			// 
			this->s16->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s16->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s16->Font = (gcnew System::Drawing::Font(L"Century", 38, System::Drawing::FontStyle::Bold));
			this->s16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s16.Image")));
			this->s16->Location = System::Drawing::Point(409, 27);
			this->s16->Name = L"s16";
			this->s16->Size = System::Drawing::Size(70, 70);
			this->s16->TabIndex = 36;
			this->s16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s16->Visible = false;
			// 
			// s27
			// 
			this->s27->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s27->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s27->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s27->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s27->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s27.Image")));
			this->s27->Location = System::Drawing::Point(486, 105);
			this->s27->Name = L"s27";
			this->s27->Size = System::Drawing::Size(70, 70);
			this->s27->TabIndex = 46;
			this->s27->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s27->Visible = false;
			// 
			// s18
			// 
			this->s18->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s18->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s18->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s18.Image")));
			this->s18->Location = System::Drawing::Point(563, 27);
			this->s18->Name = L"s18";
			this->s18->Size = System::Drawing::Size(70, 70);
			this->s18->TabIndex = 45;
			this->s18->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s18->Visible = false;
			// 
			// s31
			// 
			this->s31->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s31->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s31->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s31->Font = (gcnew System::Drawing::Font(L"Century", 39, System::Drawing::FontStyle::Bold));
			this->s31->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s31.Image")));
			this->s31->Location = System::Drawing::Point(24, 182);
			this->s31->Name = L"s31";
			this->s31->Size = System::Drawing::Size(70, 70);
			this->s31->TabIndex = 37;
			this->s31->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s31->Visible = false;
			// 
			// s37
			// 
			this->s37->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s37->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s37->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s37->Font = (gcnew System::Drawing::Font(L"Century", 34, System::Drawing::FontStyle::Bold));
			this->s37->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s37.Image")));
			this->s37->Location = System::Drawing::Point(486, 182);
			this->s37->Name = L"s37";
			this->s37->Size = System::Drawing::Size(70, 70);
			this->s37->TabIndex = 44;
			this->s37->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s37->Visible = false;
			// 
			// s24
			// 
			this->s24->BackColor = System::Drawing::SystemColors::ControlDark;
			this->s24->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->s24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->s24->Font = (gcnew System::Drawing::Font(L"Century", 32, System::Drawing::FontStyle::Bold));
			this->s24->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s24.Image")));
			this->s24->Location = System::Drawing::Point(255, 105);
			this->s24->Name = L"s24";
			this->s24->Size = System::Drawing::Size(70, 70);
			this->s24->TabIndex = 35;
			this->s24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->s24->Visible = false;
			// 
			// result1
			// 
			this->result1->BackColor = System::Drawing::SystemColors::Control;
			this->result1->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->result1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->result1->Location = System::Drawing::Point(249, 318);
			this->result1->Name = L"result1";
			this->result1->Size = System::Drawing::Size(66, 65);
			this->result1->TabIndex = 27;
			this->result1->Text = L"¶";
			this->result1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->result1->Visible = false;
			// 
			// result2
			// 
			this->result2->BackColor = System::Drawing::SystemColors::Control;
			this->result2->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->result2->Location = System::Drawing::Point(326, 318);
			this->result2->Name = L"result2";
			this->result2->Size = System::Drawing::Size(66, 65);
			this->result2->TabIndex = 28;
			this->result2->Text = L"©";
			this->result2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->result2->Visible = false;
			// 
			// result3
			// 
			this->result3->BackColor = System::Drawing::SystemColors::Control;
			this->result3->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->result3->Location = System::Drawing::Point(403, 318);
			this->result3->Name = L"result3";
			this->result3->Size = System::Drawing::Size(66, 65);
			this->result3->TabIndex = 29;
			this->result3->Text = L"★";
			this->result3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->result3->Visible = false;
			// 
			// result4
			// 
			this->result4->BackColor = System::Drawing::SystemColors::Control;
			this->result4->Font = (gcnew System::Drawing::Font(L"Century", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->result4->Location = System::Drawing::Point(480, 318);
			this->result4->Name = L"result4";
			this->result4->Size = System::Drawing::Size(66, 65);
			this->result4->TabIndex = 30;
			this->result4->Text = L"☆";
			this->result4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->result4->Visible = false;
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(728, 400);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 2;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ModuleKeypad::exitButton_Click);
			// 
			// calcButton
			// 
			this->calcButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->calcButton->Location = System::Drawing::Point(363, 396);
			this->calcButton->Margin = System::Windows::Forms::Padding(2);
			this->calcButton->Name = L"calcButton";
			this->calcButton->Size = System::Drawing::Size(68, 25);
			this->calcButton->TabIndex = 1;
			this->calcButton->Text = L"Calculate";
			this->calcButton->UseVisualStyleBackColor = true;
			this->calcButton->Click += gcnew System::EventHandler(this, &ModuleKeypad::calcButton_Click);
			// 
			// resetButton
			// 
			this->resetButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->resetButton->Location = System::Drawing::Point(29, 400);
			this->resetButton->Margin = System::Windows::Forms::Padding(2);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(55, 21);
			this->resetButton->TabIndex = 0;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &ModuleKeypad::resetButton_Click);
			// 
			// promptLabel
			// 
			this->promptLabel->AutoSize = true;
			this->promptLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->promptLabel->Location = System::Drawing::Point(14, 329);
			this->promptLabel->Name = L"promptLabel";
			this->promptLabel->Size = System::Drawing::Size(767, 31);
			this->promptLabel->TabIndex = 31;
			this->promptLabel->Text = L"Select the 4 symbols from the module, then click calculate";
			// 
			// ModuleKeypad
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(794, 432);
			this->Controls->Add(this->promptLabel);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->calcButton);
			this->Controls->Add(this->result1);
			this->Controls->Add(this->result2);
			this->Controls->Add(this->symbolsContainer);
			this->Controls->Add(this->result3);
			this->Controls->Add(this->result4);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ModuleKeypad";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Keypad (Symbols)";
			this->Load += gcnew System::EventHandler(this, &ModuleKeypad::ModuleKeypad_Load);
			this->symbolsContainer->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void symbol11_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[0, 0]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol11;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if(TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol12_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[1, 0]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol12;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol13_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[2, 0]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol13;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol14_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[3, 0]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol14;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol15_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[4, 0]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol15;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol16_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[5, 0]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol16;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol17_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[6, 0]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol17;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol18_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[7, 0]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol18;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol19_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[8, 0]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol19;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol21_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[0, 1]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol21;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol22_Click(System::Object^ sender, System::EventArgs^ e) {
	symbol22->ForeColor = System::Drawing::Color::Green;
	interior_ptr<bool> ThisClick = &Clicked[1, 1]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol22;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol23_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[2, 1]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol23;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol24_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[3, 1]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol24;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol25_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[4, 1]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol25;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol26_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[5, 1]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol26;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol27_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[6, 1]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol27;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol28_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[7, 1]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol28;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol29_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[8, 1]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol29;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol31_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[0, 2]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol31;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol32_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[1, 2]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol32;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol33_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[2, 2]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol33;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol34_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[3, 2]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol34;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol35_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[4, 2]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol35;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol36_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[5, 2]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol36;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol37_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[6, 2]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol37;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol38_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[7, 2]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol38;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void symbol39_Click(System::Object^ sender, System::EventArgs^ e) {
	interior_ptr<bool> ThisClick = &Clicked[8, 2]; // Local Variables to make copy/paste for each one easier
	Label^ thisLabel = symbol39;
	if (!*ThisClick)
	{
		if (ClickedCount < 4)
		{
			*ThisClick = true;
			ClickedCount++;
			if (TextMode)
				thisLabel->ForeColor = ClickedColor;
			else
				thisLabel->BackColor = ClickedColor;
		}
	}
	else
	{
		*ThisClick = false;
		ClickedCount--;
		if (TextMode)
			thisLabel->ForeColor = UnclickedColor;
		else
			thisLabel->BackColor = UnclickedColorB;
	}
}
private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void calcButton_Click(System::Object^ sender, System::EventArgs^ e) {
	Calculate();
}
private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	result1->Visible = false;
	result2->Visible = false;
	result3->Visible = false;
	result4->Visible = false;
	promptLabel->Visible = true;

	symbol11->ForeColor = UnclickedColor;
	symbol12->ForeColor = UnclickedColor;
	symbol13->ForeColor = UnclickedColor;
	symbol14->ForeColor = UnclickedColor;
	symbol15->ForeColor = UnclickedColor;
	symbol16->ForeColor = UnclickedColor;
	symbol17->ForeColor = UnclickedColor;
	symbol18->ForeColor = UnclickedColor;
	symbol19->ForeColor = UnclickedColor;
	symbol21->ForeColor = UnclickedColor;
	symbol22->ForeColor = UnclickedColor;
	symbol23->ForeColor = UnclickedColor;
	symbol24->ForeColor = UnclickedColor;
	symbol25->ForeColor = UnclickedColor;
	symbol26->ForeColor = UnclickedColor;
	symbol27->ForeColor = UnclickedColor;
	symbol28->ForeColor = UnclickedColor;
	symbol29->ForeColor = UnclickedColor;
	symbol31->ForeColor = UnclickedColor;
	symbol32->ForeColor = UnclickedColor;
	symbol33->ForeColor = UnclickedColor;
	symbol34->ForeColor = UnclickedColor;
	symbol35->ForeColor = UnclickedColor;
	symbol36->ForeColor = UnclickedColor;
	symbol37->ForeColor = UnclickedColor;
	symbol38->ForeColor = UnclickedColor;
	symbol39->ForeColor = UnclickedColor;

	symbol11->BackColor = UnclickedColorB;
	symbol12->BackColor = UnclickedColorB;
	symbol13->BackColor = UnclickedColorB;
	symbol14->BackColor = UnclickedColorB;
	symbol15->BackColor = UnclickedColorB;
	symbol16->BackColor = UnclickedColorB;
	symbol17->BackColor = UnclickedColorB;
	symbol18->BackColor = UnclickedColorB;
	symbol19->BackColor = UnclickedColorB;
	symbol21->BackColor = UnclickedColorB;
	symbol22->BackColor = UnclickedColorB;
	symbol23->BackColor = UnclickedColorB;
	symbol24->BackColor = UnclickedColorB;
	symbol25->BackColor = UnclickedColorB;
	symbol26->BackColor = UnclickedColorB;
	symbol27->BackColor = UnclickedColorB;
	symbol28->BackColor = UnclickedColorB;
	symbol29->BackColor = UnclickedColorB;
	symbol31->BackColor = UnclickedColorB;
	symbol32->BackColor = UnclickedColorB;
	symbol33->BackColor = UnclickedColorB;
	symbol34->BackColor = UnclickedColorB;
	symbol35->BackColor = UnclickedColorB;
	symbol36->BackColor = UnclickedColorB;
	symbol37->BackColor = UnclickedColorB;
	symbol38->BackColor = UnclickedColorB;
	symbol39->BackColor = UnclickedColorB;

	ClickedCount = 0;
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			Clicked[x, y] = false;
		}
	}
}
private: System::Void ModuleKeypad_Load(System::Object^ sender, System::EventArgs^ e) {
	// Initialize Grid
	if (TextMode)
	{
		this->symbol11->Text = L"¶";
		this->symbol12->Text = L"©";
		this->symbol13->Text = L"★";
		this->symbol14->Text = L"☆";
		this->symbol15->Text = L"ټ";
		this->symbol16->Text = L"ϗ";
		this->symbol17->Text = L"Ԇ";
		this->symbol18->Text = L"¿";
		this->symbol19->Text = L"ϙ";

		this->symbol21->Text = L"Җ";
		this->symbol22->Text = L"Ω";
		this->symbol23->Text = L"Ѭ";
		this->symbol24->Text = L"Ѽ";
		this->symbol25->Text = L"Ѣ";
		this->symbol26->Text = L"Ψ";
		this->symbol27->Text = L"Ͼ";
		this->symbol28->Text = L"Ͽ";
		this->symbol29->Text = L"ƛ";

		this->symbol31->Text = L"б";
		this->symbol32->Text = L"ϟ";
		this->symbol33->Text = L"Ѧ";
		this->symbol34->Text = L"æ";
		this->symbol35->Text = L"Ӭ";
		this->symbol36->Text = L"Ҋ";
		this->symbol37->Text = L"Ѯ";
		this->symbol38->Text = L"҂";
		this->symbol39->Text = L"Ҩ";
	}
	else
	{
		this->symbol11->Image = s11->Image;
		this->symbol12->Image = s12->Image;
		this->symbol13->Image = s13->Image;
		this->symbol14->Image = s14->Image;
		this->symbol15->Image = s15->Image;
		this->symbol16->Image = s16->Image;
		this->symbol17->Image = s17->Image;
		this->symbol18->Image = s18->Image;
		this->symbol19->Image = s19->Image;

		this->symbol21->Image = s21->Image;
		this->symbol22->Image = s22->Image;
		this->symbol23->Image = s23->Image;
		this->symbol24->Image = s24->Image;
		this->symbol25->Image = s25->Image;
		this->symbol26->Image = s26->Image;
		this->symbol27->Image = s27->Image;
		this->symbol28->Image = s28->Image;
		this->symbol29->Image = s29->Image;

		this->symbol31->Image = s31->Image;
		this->symbol32->Image = s32->Image;
		this->symbol33->Image = s33->Image;
		this->symbol34->Image = s34->Image;
		this->symbol35->Image = s35->Image;
		this->symbol36->Image = s36->Image;
		this->symbol37->Image = s37->Image;
		this->symbol38->Image = s38->Image;
		this->symbol39->Image = s39->Image;

		this->symbol11->Text = L"";
		this->symbol12->Text = L"";
		this->symbol13->Text = L"";
		this->symbol14->Text = L"";
		this->symbol15->Text = L"";
		this->symbol16->Text = L"";
		this->symbol17->Text = L"";
		this->symbol18->Text = L"";
		this->symbol19->Text = L"";

		this->symbol21->Text = L"";
		this->symbol22->Text = L"";
		this->symbol23->Text = L"";
		this->symbol24->Text = L"";
		this->symbol25->Text = L"";
		this->symbol26->Text = L"";
		this->symbol27->Text = L"";
		this->symbol28->Text = L"";
		this->symbol29->Text = L"";

		this->symbol31->Text = L"";
		this->symbol32->Text = L"";
		this->symbol33->Text = L"";
		this->symbol34->Text = L"";
		this->symbol35->Text = L"";
		this->symbol36->Text = L"";
		this->symbol37->Text = L"";
		this->symbol38->Text = L"";
		this->symbol39->Text = L"";
	}
}
};
}
