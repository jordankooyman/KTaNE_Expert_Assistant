/**********************************************************
   file: ModuleSimpleWires.h
 author: Jordan Kooyman
purpose: Contains Simple Wires module window and the calculations for simple wires as a member function
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
	/// Summary for ModuleSimpleWires
	/// </summary>
	public ref class ModuleSimpleWires : public System::Windows::Forms::Form
	{
	//private: System::Windows::Forms::Form^ otherform;
	public:
		ModuleSimpleWires()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ModuleSimpleWires()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ inputPrompt;
	protected:
	private: System::Windows::Forms::GroupBox^ wire1;
	private: System::Windows::Forms::RadioButton^ yellowWire1;

	private: System::Windows::Forms::RadioButton^ whiteWire1;

	private: System::Windows::Forms::RadioButton^ blackWire1;

	private: System::Windows::Forms::RadioButton^ blueWire1;

	private: System::Windows::Forms::RadioButton^ redWire1;
	private: System::Windows::Forms::GroupBox^ wire2;
	private: System::Windows::Forms::RadioButton^ yellowWire2;

	private: System::Windows::Forms::RadioButton^ whiteWire2;

	private: System::Windows::Forms::RadioButton^ blackWire2;

	private: System::Windows::Forms::RadioButton^ blueWire2;

	private: System::Windows::Forms::RadioButton^ redWire2;

	private: System::Windows::Forms::GroupBox^ wire3;
	private: System::Windows::Forms::RadioButton^ yellowWire3;

	private: System::Windows::Forms::RadioButton^ whiteWire3;

	private: System::Windows::Forms::RadioButton^ blackWire3;

	private: System::Windows::Forms::RadioButton^ blueWire3;

	private: System::Windows::Forms::RadioButton^ redWire3;

	private: System::Windows::Forms::GroupBox^ wire4;
	private: System::Windows::Forms::RadioButton^ yellowWire4;

	private: System::Windows::Forms::RadioButton^ whiteWire4;

	private: System::Windows::Forms::RadioButton^ blackWire4;

	private: System::Windows::Forms::RadioButton^ blueWire4;

	private: System::Windows::Forms::RadioButton^ redWire4;

	private: System::Windows::Forms::GroupBox^ wire5;
	private: System::Windows::Forms::RadioButton^ yellowWire5;

	private: System::Windows::Forms::RadioButton^ whiteWire5;

	private: System::Windows::Forms::RadioButton^ blackWire5;

	private: System::Windows::Forms::RadioButton^ blueWire5;

	private: System::Windows::Forms::RadioButton^ redWire5;

	private: System::Windows::Forms::GroupBox^ wire6;
	private: System::Windows::Forms::RadioButton^ yellowWire6;

	private: System::Windows::Forms::RadioButton^ whiteWire6;

	private: System::Windows::Forms::RadioButton^ blackWire6;

	private: System::Windows::Forms::RadioButton^ blueWire6;

	private: System::Windows::Forms::RadioButton^ redWire6;

	private: System::Windows::Forms::RadioButton^ noneWire4;
	private: System::Windows::Forms::RadioButton^ noneWire5;
	private: System::Windows::Forms::RadioButton^ noneWire6;
	private: System::Windows::Forms::Button^ calcButton;

	public:
		/**
		* Check that all required Bomb Constants have been input, then read in the input data from the GUI and provide the resulting solution to simple wires module
		* @param None
		* @return None
		*/
		void Calculate()
		{
			if (!CurrentSerial.serialValid())
			{
				pauseCalculation(this);
				OpenWindow(4);
				return;
			}

			int wires[6] = { 0, 0, 0, 0, 0, 0 }; // 0: Uninitialized, 1: Yellow, 2: Red, 3: Blue, 4: Black, 5: White
			int none = 0;
			int yellow_count = 0;
			int red_count = 0;
			int blue_count = 0;
			int black_count = 0;
			int white_count = 0;
			if (redWire1->Checked) {
				wires[0] = 2;
				red_count++;
			}
			else if (blueWire1->Checked) {
				wires[0] = 3;
				blue_count++;
			}
			else if (blackWire1->Checked) {
				wires[0] = 4;
				black_count++;
			}
			else if (yellowWire1->Checked) {
				wires[0] = 1;
				yellow_count++;
			}
			else if (whiteWire1->Checked) {
				wires[0] = 5;
				red_count++;
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("At least 3 wire colors must be selected", "Error");
				return;
			}

			if (redWire2->Checked) {
				wires[2 - 1] = 2;
				red_count++;
			}
			else if (blueWire2->Checked) {
				wires[2 - 1] = 3;
				blue_count++;
			}
			else if (blackWire2->Checked) {
				wires[2 - 1] = 4;
				black_count++;
			}
			else if (yellowWire2->Checked) {
				wires[2 - 1] = 1;
				yellow_count++;
			}
			else if (whiteWire2->Checked) {
				wires[2 - 1] = 5;
				red_count++;
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("At least 3 wire colors must be selected", "Error");
				return;
			}

			if (redWire3->Checked) {
				wires[3 - 1] = 2;
				red_count++;
			}
			else if (blueWire3->Checked) {
				wires[3 - 1] = 3;
				blue_count++;
			}
			else if (blackWire3->Checked) {
				wires[3 - 1] = 4;
				black_count++;
			}
			else if (yellowWire3->Checked) {
				wires[3 - 1] = 1;
				yellow_count++;
			}
			else if (whiteWire3->Checked) {
				wires[3 - 1] = 5;
				red_count++;
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("At least 3 wire colors must be selected", "Error");
				return;
			}

			if (redWire4->Checked) {
				wires[4 - 1] = 2;
				red_count++;
			}
			else if (blueWire4->Checked) {
				wires[4 - 1] = 3;
				blue_count++;
			}
			else if (blackWire4->Checked) {
				wires[4 - 1] = 4;
				black_count++;
			}
			else if (yellowWire4->Checked) {
				wires[4 - 1] = 1;
				yellow_count++;
			}
			else if (whiteWire4->Checked) {
				wires[4 - 1] = 5;
				red_count++;
			}
			else if (noneWire4->Checked)
			{
				none++;
				wires[4 - 1] = 0;
			}

			if (redWire5->Checked) {
				wires[5 - 1] = 2;
				red_count++;
			}
			else if (blueWire5->Checked) {
				wires[5 - 1] = 3;
				blue_count++;
			}
			else if (blackWire5->Checked) {
				wires[5 - 1] = 4;
				black_count++;
			}
			else if (yellowWire5->Checked) {
				wires[5 - 1] = 1;
				yellow_count++;
			}
			else if (whiteWire5->Checked) {
				wires[5 - 1] = 5;
				red_count++;
			}
			else if (noneWire5->Checked)
			{
				none++;
				wires[5 - 1] = 0;
			}

			if (redWire6->Checked) {
				wires[6 - 1] = 2;
				red_count++;
			}
			else if (blueWire6->Checked) {
				wires[6 - 1] = 3;
				blue_count++;
			}
			else if (blackWire6->Checked) {
				wires[6 - 1] = 4;
				black_count++;
			}
			else if (yellowWire6->Checked) {
				wires[6 - 1] = 1;
				yellow_count++;
			}
			else if (whiteWire6->Checked) {
				wires[6 - 1] = 5;
				red_count++;
			}
			else if (noneWire6->Checked)
			{
				none++;
				wires[6 - 1] = 0;
			}
			
			int wire_count = 6 - none;
			switch (wire_count)
			{
			case 3:
				if (wires[0] == 3 && wires[1] == 3 && wires[2] == 2) System::Windows::Forms::MessageBox::Show("Cut the 2nd wire", "Result");
				else if (wires[0] != 2 && wires[1] != 2 && wires[2] != 2) System::Windows::Forms::MessageBox::Show("Cut the 2nd wire", "Result");
				else System::Windows::Forms::MessageBox::Show("Cut the 3rd wire", "Result");
				break;
			case 4:
				if (red_count > 1 && CurrentSerial.serialCheck(5) % 2 == 1) System::Windows::Forms::MessageBox::Show("Cut the last red wire", "Result");
				else if (wires[3] == 1 && red_count == 0) System::Windows::Forms::MessageBox::Show("Cut the 1st wire", "Result");
				else if (blue_count == 1) System::Windows::Forms::MessageBox::Show("Cut the 1st wire", "Result");
				else if (yellow_count > 1) System::Windows::Forms::MessageBox::Show("Cut the 4th wire", "Result");
				else System::Windows::Forms::MessageBox::Show("Cut the 2nd wire", "Result");
				break;
			case 5:
				if (wires[4] == 4 && CurrentSerial.serialCheck(5) % 2 == 1) System::Windows::Forms::MessageBox::Show("Cut the 4th wire", "Result");
				else if (red_count == 1 && yellow_count > 1) System::Windows::Forms::MessageBox::Show("Cut the 1st wire", "Result");
				else if (black_count == 0) System::Windows::Forms::MessageBox::Show("Cut the 2nd wire", "Result");
				else System::Windows::Forms::MessageBox::Show("Cut the 1st wire", "Result");
				break;
			case 6:
				if (yellow_count == 0 && CurrentSerial.serialCheck(5) % 2 == 1) System::Windows::Forms::MessageBox::Show("Cut the 3rd wire", "Result");
				else if (yellow_count == 1 && white_count > 1) System::Windows::Forms::MessageBox::Show("Cut the 4th wire", "Result");
				else if (red_count == 0) System::Windows::Forms::MessageBox::Show("Cut the 6th wire", "Result");
				else  System::Windows::Forms::MessageBox::Show("Cut the 4th wire", "Result");
				break;
			default:
				System::Windows::Forms::MessageBox::Show("Error", "Result");
				break;
			}
		}


	private: System::Windows::Forms::Button^ exitButton;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModuleSimpleWires::typeid));
			this->inputPrompt = (gcnew System::Windows::Forms::Label());
			this->wire1 = (gcnew System::Windows::Forms::GroupBox());
			this->yellowWire1 = (gcnew System::Windows::Forms::RadioButton());
			this->whiteWire1 = (gcnew System::Windows::Forms::RadioButton());
			this->blackWire1 = (gcnew System::Windows::Forms::RadioButton());
			this->blueWire1 = (gcnew System::Windows::Forms::RadioButton());
			this->redWire1 = (gcnew System::Windows::Forms::RadioButton());
			this->wire2 = (gcnew System::Windows::Forms::GroupBox());
			this->yellowWire2 = (gcnew System::Windows::Forms::RadioButton());
			this->whiteWire2 = (gcnew System::Windows::Forms::RadioButton());
			this->blackWire2 = (gcnew System::Windows::Forms::RadioButton());
			this->blueWire2 = (gcnew System::Windows::Forms::RadioButton());
			this->redWire2 = (gcnew System::Windows::Forms::RadioButton());
			this->wire3 = (gcnew System::Windows::Forms::GroupBox());
			this->yellowWire3 = (gcnew System::Windows::Forms::RadioButton());
			this->whiteWire3 = (gcnew System::Windows::Forms::RadioButton());
			this->blackWire3 = (gcnew System::Windows::Forms::RadioButton());
			this->blueWire3 = (gcnew System::Windows::Forms::RadioButton());
			this->redWire3 = (gcnew System::Windows::Forms::RadioButton());
			this->wire4 = (gcnew System::Windows::Forms::GroupBox());
			this->noneWire4 = (gcnew System::Windows::Forms::RadioButton());
			this->yellowWire4 = (gcnew System::Windows::Forms::RadioButton());
			this->whiteWire4 = (gcnew System::Windows::Forms::RadioButton());
			this->blackWire4 = (gcnew System::Windows::Forms::RadioButton());
			this->blueWire4 = (gcnew System::Windows::Forms::RadioButton());
			this->redWire4 = (gcnew System::Windows::Forms::RadioButton());
			this->wire5 = (gcnew System::Windows::Forms::GroupBox());
			this->noneWire5 = (gcnew System::Windows::Forms::RadioButton());
			this->yellowWire5 = (gcnew System::Windows::Forms::RadioButton());
			this->whiteWire5 = (gcnew System::Windows::Forms::RadioButton());
			this->blackWire5 = (gcnew System::Windows::Forms::RadioButton());
			this->blueWire5 = (gcnew System::Windows::Forms::RadioButton());
			this->redWire5 = (gcnew System::Windows::Forms::RadioButton());
			this->wire6 = (gcnew System::Windows::Forms::GroupBox());
			this->noneWire6 = (gcnew System::Windows::Forms::RadioButton());
			this->yellowWire6 = (gcnew System::Windows::Forms::RadioButton());
			this->whiteWire6 = (gcnew System::Windows::Forms::RadioButton());
			this->blackWire6 = (gcnew System::Windows::Forms::RadioButton());
			this->blueWire6 = (gcnew System::Windows::Forms::RadioButton());
			this->redWire6 = (gcnew System::Windows::Forms::RadioButton());
			this->calcButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->wire1->SuspendLayout();
			this->wire2->SuspendLayout();
			this->wire3->SuspendLayout();
			this->wire4->SuspendLayout();
			this->wire5->SuspendLayout();
			this->wire6->SuspendLayout();
			this->SuspendLayout();
			// 
			// inputPrompt
			// 
			this->inputPrompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputPrompt->Location = System::Drawing::Point(10, 18);
			this->inputPrompt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->inputPrompt->Name = L"inputPrompt";
			this->inputPrompt->Size = System::Drawing::Size(515, 42);
			this->inputPrompt->TabIndex = 0;
			this->inputPrompt->Text = L"Enter all the wire colors, selecting none if all wires have been entered already,"
				L" then click calculate";
			this->inputPrompt->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// wire1
			// 
			this->wire1->Controls->Add(this->yellowWire1);
			this->wire1->Controls->Add(this->whiteWire1);
			this->wire1->Controls->Add(this->blackWire1);
			this->wire1->Controls->Add(this->blueWire1);
			this->wire1->Controls->Add(this->redWire1);
			this->wire1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->wire1->Location = System::Drawing::Point(10, 66);
			this->wire1->Margin = System::Windows::Forms::Padding(2);
			this->wire1->Name = L"wire1";
			this->wire1->Padding = System::Windows::Forms::Padding(2);
			this->wire1->Size = System::Drawing::Size(84, 166);
			this->wire1->TabIndex = 1;
			this->wire1->TabStop = false;
			this->wire1->Text = L"Wire 1";
			// 
			// yellowWire1
			// 
			this->yellowWire1->AutoSize = true;
			this->yellowWire1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->yellowWire1->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->yellowWire1->Location = System::Drawing::Point(16, 136);
			this->yellowWire1->Margin = System::Windows::Forms::Padding(2);
			this->yellowWire1->Name = L"yellowWire1";
			this->yellowWire1->Size = System::Drawing::Size(62, 17);
			this->yellowWire1->TabIndex = 4;
			this->yellowWire1->TabStop = true;
			this->yellowWire1->Text = L"Yellow";
			this->yellowWire1->UseVisualStyleBackColor = true;
			// 
			// whiteWire1
			// 
			this->whiteWire1->AutoSize = true;
			this->whiteWire1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->whiteWire1->ForeColor = System::Drawing::SystemColors::GrayText;
			this->whiteWire1->Location = System::Drawing::Point(16, 108);
			this->whiteWire1->Margin = System::Windows::Forms::Padding(2);
			this->whiteWire1->Name = L"whiteWire1";
			this->whiteWire1->Size = System::Drawing::Size(58, 17);
			this->whiteWire1->TabIndex = 3;
			this->whiteWire1->TabStop = true;
			this->whiteWire1->Text = L"White";
			this->whiteWire1->UseVisualStyleBackColor = true;
			// 
			// blackWire1
			// 
			this->blackWire1->AutoSize = true;
			this->blackWire1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blackWire1->Location = System::Drawing::Point(16, 80);
			this->blackWire1->Margin = System::Windows::Forms::Padding(2);
			this->blackWire1->Name = L"blackWire1";
			this->blackWire1->Size = System::Drawing::Size(57, 17);
			this->blackWire1->TabIndex = 2;
			this->blackWire1->TabStop = true;
			this->blackWire1->Text = L"Black";
			this->blackWire1->UseVisualStyleBackColor = true;
			// 
			// blueWire1
			// 
			this->blueWire1->AutoSize = true;
			this->blueWire1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blueWire1->ForeColor = System::Drawing::Color::Blue;
			this->blueWire1->Location = System::Drawing::Point(16, 52);
			this->blueWire1->Margin = System::Windows::Forms::Padding(2);
			this->blueWire1->Name = L"blueWire1";
			this->blueWire1->Size = System::Drawing::Size(50, 17);
			this->blueWire1->TabIndex = 1;
			this->blueWire1->TabStop = true;
			this->blueWire1->Text = L"Blue";
			this->blueWire1->UseVisualStyleBackColor = true;
			// 
			// redWire1
			// 
			this->redWire1->AutoSize = true;
			this->redWire1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->redWire1->ForeColor = System::Drawing::Color::Red;
			this->redWire1->Location = System::Drawing::Point(16, 24);
			this->redWire1->Margin = System::Windows::Forms::Padding(2);
			this->redWire1->Name = L"redWire1";
			this->redWire1->Size = System::Drawing::Size(48, 17);
			this->redWire1->TabIndex = 0;
			this->redWire1->TabStop = true;
			this->redWire1->Text = L"Red";
			this->redWire1->UseVisualStyleBackColor = true;
			// 
			// wire2
			// 
			this->wire2->Controls->Add(this->yellowWire2);
			this->wire2->Controls->Add(this->whiteWire2);
			this->wire2->Controls->Add(this->blackWire2);
			this->wire2->Controls->Add(this->blueWire2);
			this->wire2->Controls->Add(this->redWire2);
			this->wire2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->wire2->Location = System::Drawing::Point(98, 66);
			this->wire2->Margin = System::Windows::Forms::Padding(2);
			this->wire2->Name = L"wire2";
			this->wire2->Padding = System::Windows::Forms::Padding(2);
			this->wire2->Size = System::Drawing::Size(84, 166);
			this->wire2->TabIndex = 2;
			this->wire2->TabStop = false;
			this->wire2->Text = L"Wire 2";
			// 
			// yellowWire2
			// 
			this->yellowWire2->AutoSize = true;
			this->yellowWire2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->yellowWire2->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->yellowWire2->Location = System::Drawing::Point(16, 136);
			this->yellowWire2->Margin = System::Windows::Forms::Padding(2);
			this->yellowWire2->Name = L"yellowWire2";
			this->yellowWire2->Size = System::Drawing::Size(62, 17);
			this->yellowWire2->TabIndex = 9;
			this->yellowWire2->TabStop = true;
			this->yellowWire2->Text = L"Yellow";
			this->yellowWire2->UseVisualStyleBackColor = true;
			// 
			// whiteWire2
			// 
			this->whiteWire2->AutoSize = true;
			this->whiteWire2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->whiteWire2->ForeColor = System::Drawing::SystemColors::GrayText;
			this->whiteWire2->Location = System::Drawing::Point(16, 108);
			this->whiteWire2->Margin = System::Windows::Forms::Padding(2);
			this->whiteWire2->Name = L"whiteWire2";
			this->whiteWire2->Size = System::Drawing::Size(58, 17);
			this->whiteWire2->TabIndex = 8;
			this->whiteWire2->TabStop = true;
			this->whiteWire2->Text = L"White";
			this->whiteWire2->UseVisualStyleBackColor = true;
			// 
			// blackWire2
			// 
			this->blackWire2->AutoSize = true;
			this->blackWire2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blackWire2->Location = System::Drawing::Point(16, 80);
			this->blackWire2->Margin = System::Windows::Forms::Padding(2);
			this->blackWire2->Name = L"blackWire2";
			this->blackWire2->Size = System::Drawing::Size(57, 17);
			this->blackWire2->TabIndex = 7;
			this->blackWire2->TabStop = true;
			this->blackWire2->Text = L"Black";
			this->blackWire2->UseVisualStyleBackColor = true;
			// 
			// blueWire2
			// 
			this->blueWire2->AutoSize = true;
			this->blueWire2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blueWire2->ForeColor = System::Drawing::Color::Blue;
			this->blueWire2->Location = System::Drawing::Point(16, 52);
			this->blueWire2->Margin = System::Windows::Forms::Padding(2);
			this->blueWire2->Name = L"blueWire2";
			this->blueWire2->Size = System::Drawing::Size(50, 17);
			this->blueWire2->TabIndex = 3;
			this->blueWire2->TabStop = true;
			this->blueWire2->Text = L"Blue";
			this->blueWire2->UseVisualStyleBackColor = true;
			// 
			// redWire2
			// 
			this->redWire2->AutoSize = true;
			this->redWire2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->redWire2->ForeColor = System::Drawing::Color::Red;
			this->redWire2->Location = System::Drawing::Point(16, 24);
			this->redWire2->Margin = System::Windows::Forms::Padding(2);
			this->redWire2->Name = L"redWire2";
			this->redWire2->Size = System::Drawing::Size(48, 17);
			this->redWire2->TabIndex = 5;
			this->redWire2->TabStop = true;
			this->redWire2->Text = L"Red";
			this->redWire2->UseVisualStyleBackColor = true;
			// 
			// wire3
			// 
			this->wire3->Controls->Add(this->yellowWire3);
			this->wire3->Controls->Add(this->whiteWire3);
			this->wire3->Controls->Add(this->blackWire3);
			this->wire3->Controls->Add(this->blueWire3);
			this->wire3->Controls->Add(this->redWire3);
			this->wire3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->wire3->Location = System::Drawing::Point(186, 66);
			this->wire3->Margin = System::Windows::Forms::Padding(2);
			this->wire3->Name = L"wire3";
			this->wire3->Padding = System::Windows::Forms::Padding(2);
			this->wire3->Size = System::Drawing::Size(84, 166);
			this->wire3->TabIndex = 5;
			this->wire3->TabStop = false;
			this->wire3->Text = L"Wire 3";
			// 
			// yellowWire3
			// 
			this->yellowWire3->AutoSize = true;
			this->yellowWire3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->yellowWire3->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->yellowWire3->Location = System::Drawing::Point(16, 136);
			this->yellowWire3->Margin = System::Windows::Forms::Padding(2);
			this->yellowWire3->Name = L"yellowWire3";
			this->yellowWire3->Size = System::Drawing::Size(62, 17);
			this->yellowWire3->TabIndex = 14;
			this->yellowWire3->TabStop = true;
			this->yellowWire3->Text = L"Yellow";
			this->yellowWire3->UseVisualStyleBackColor = true;
			// 
			// whiteWire3
			// 
			this->whiteWire3->AutoSize = true;
			this->whiteWire3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->whiteWire3->ForeColor = System::Drawing::SystemColors::GrayText;
			this->whiteWire3->Location = System::Drawing::Point(16, 108);
			this->whiteWire3->Margin = System::Windows::Forms::Padding(2);
			this->whiteWire3->Name = L"whiteWire3";
			this->whiteWire3->Size = System::Drawing::Size(58, 17);
			this->whiteWire3->TabIndex = 13;
			this->whiteWire3->TabStop = true;
			this->whiteWire3->Text = L"White";
			this->whiteWire3->UseVisualStyleBackColor = true;
			// 
			// blackWire3
			// 
			this->blackWire3->AutoSize = true;
			this->blackWire3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blackWire3->Location = System::Drawing::Point(16, 80);
			this->blackWire3->Margin = System::Windows::Forms::Padding(2);
			this->blackWire3->Name = L"blackWire3";
			this->blackWire3->Size = System::Drawing::Size(57, 17);
			this->blackWire3->TabIndex = 12;
			this->blackWire3->TabStop = true;
			this->blackWire3->Text = L"Black";
			this->blackWire3->UseVisualStyleBackColor = true;
			// 
			// blueWire3
			// 
			this->blueWire3->AutoSize = true;
			this->blueWire3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blueWire3->ForeColor = System::Drawing::Color::Blue;
			this->blueWire3->Location = System::Drawing::Point(16, 52);
			this->blueWire3->Margin = System::Windows::Forms::Padding(2);
			this->blueWire3->Name = L"blueWire3";
			this->blueWire3->Size = System::Drawing::Size(50, 17);
			this->blueWire3->TabIndex = 11;
			this->blueWire3->TabStop = true;
			this->blueWire3->Text = L"Blue";
			this->blueWire3->UseVisualStyleBackColor = true;
			// 
			// redWire3
			// 
			this->redWire3->AutoSize = true;
			this->redWire3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->redWire3->ForeColor = System::Drawing::Color::Red;
			this->redWire3->Location = System::Drawing::Point(16, 24);
			this->redWire3->Margin = System::Windows::Forms::Padding(2);
			this->redWire3->Name = L"redWire3";
			this->redWire3->Size = System::Drawing::Size(48, 17);
			this->redWire3->TabIndex = 10;
			this->redWire3->TabStop = true;
			this->redWire3->Text = L"Red";
			this->redWire3->UseVisualStyleBackColor = true;
			// 
			// wire4
			// 
			this->wire4->Controls->Add(this->noneWire4);
			this->wire4->Controls->Add(this->yellowWire4);
			this->wire4->Controls->Add(this->whiteWire4);
			this->wire4->Controls->Add(this->blackWire4);
			this->wire4->Controls->Add(this->blueWire4);
			this->wire4->Controls->Add(this->redWire4);
			this->wire4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->wire4->Location = System::Drawing::Point(274, 66);
			this->wire4->Margin = System::Windows::Forms::Padding(2);
			this->wire4->Name = L"wire4";
			this->wire4->Padding = System::Windows::Forms::Padding(2);
			this->wire4->Size = System::Drawing::Size(84, 190);
			this->wire4->TabIndex = 5;
			this->wire4->TabStop = false;
			this->wire4->Text = L"Wire 4";
			// 
			// noneWire4
			// 
			this->noneWire4->AutoSize = true;
			this->noneWire4->Checked = true;
			this->noneWire4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->noneWire4->ForeColor = System::Drawing::Color::DarkRed;
			this->noneWire4->Location = System::Drawing::Point(16, 164);
			this->noneWire4->Margin = System::Windows::Forms::Padding(2);
			this->noneWire4->Name = L"noneWire4";
			this->noneWire4->Size = System::Drawing::Size(55, 17);
			this->noneWire4->TabIndex = 20;
			this->noneWire4->TabStop = true;
			this->noneWire4->Text = L"None";
			this->noneWire4->UseVisualStyleBackColor = true;
			// 
			// yellowWire4
			// 
			this->yellowWire4->AutoSize = true;
			this->yellowWire4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->yellowWire4->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->yellowWire4->Location = System::Drawing::Point(16, 136);
			this->yellowWire4->Margin = System::Windows::Forms::Padding(2);
			this->yellowWire4->Name = L"yellowWire4";
			this->yellowWire4->Size = System::Drawing::Size(62, 17);
			this->yellowWire4->TabIndex = 19;
			this->yellowWire4->Text = L"Yellow";
			this->yellowWire4->UseVisualStyleBackColor = true;
			// 
			// whiteWire4
			// 
			this->whiteWire4->AutoSize = true;
			this->whiteWire4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->whiteWire4->ForeColor = System::Drawing::SystemColors::GrayText;
			this->whiteWire4->Location = System::Drawing::Point(16, 108);
			this->whiteWire4->Margin = System::Windows::Forms::Padding(2);
			this->whiteWire4->Name = L"whiteWire4";
			this->whiteWire4->Size = System::Drawing::Size(58, 17);
			this->whiteWire4->TabIndex = 18;
			this->whiteWire4->Text = L"White";
			this->whiteWire4->UseVisualStyleBackColor = true;
			// 
			// blackWire4
			// 
			this->blackWire4->AutoSize = true;
			this->blackWire4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blackWire4->Location = System::Drawing::Point(16, 80);
			this->blackWire4->Margin = System::Windows::Forms::Padding(2);
			this->blackWire4->Name = L"blackWire4";
			this->blackWire4->Size = System::Drawing::Size(57, 17);
			this->blackWire4->TabIndex = 17;
			this->blackWire4->Text = L"Black";
			this->blackWire4->UseVisualStyleBackColor = true;
			// 
			// blueWire4
			// 
			this->blueWire4->AutoSize = true;
			this->blueWire4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blueWire4->ForeColor = System::Drawing::Color::Blue;
			this->blueWire4->Location = System::Drawing::Point(16, 52);
			this->blueWire4->Margin = System::Windows::Forms::Padding(2);
			this->blueWire4->Name = L"blueWire4";
			this->blueWire4->Size = System::Drawing::Size(50, 17);
			this->blueWire4->TabIndex = 16;
			this->blueWire4->Text = L"Blue";
			this->blueWire4->UseVisualStyleBackColor = true;
			// 
			// redWire4
			// 
			this->redWire4->AutoSize = true;
			this->redWire4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->redWire4->ForeColor = System::Drawing::Color::Red;
			this->redWire4->Location = System::Drawing::Point(16, 24);
			this->redWire4->Margin = System::Windows::Forms::Padding(2);
			this->redWire4->Name = L"redWire4";
			this->redWire4->Size = System::Drawing::Size(48, 17);
			this->redWire4->TabIndex = 15;
			this->redWire4->Text = L"Red";
			this->redWire4->UseVisualStyleBackColor = true;
			// 
			// wire5
			// 
			this->wire5->Controls->Add(this->noneWire5);
			this->wire5->Controls->Add(this->yellowWire5);
			this->wire5->Controls->Add(this->whiteWire5);
			this->wire5->Controls->Add(this->blackWire5);
			this->wire5->Controls->Add(this->blueWire5);
			this->wire5->Controls->Add(this->redWire5);
			this->wire5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->wire5->Location = System::Drawing::Point(362, 66);
			this->wire5->Margin = System::Windows::Forms::Padding(2);
			this->wire5->Name = L"wire5";
			this->wire5->Padding = System::Windows::Forms::Padding(2);
			this->wire5->Size = System::Drawing::Size(84, 190);
			this->wire5->TabIndex = 5;
			this->wire5->TabStop = false;
			this->wire5->Text = L"Wire 5";
			// 
			// noneWire5
			// 
			this->noneWire5->AutoSize = true;
			this->noneWire5->Checked = true;
			this->noneWire5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->noneWire5->ForeColor = System::Drawing::Color::DarkRed;
			this->noneWire5->Location = System::Drawing::Point(16, 164);
			this->noneWire5->Margin = System::Windows::Forms::Padding(2);
			this->noneWire5->Name = L"noneWire5";
			this->noneWire5->Size = System::Drawing::Size(55, 17);
			this->noneWire5->TabIndex = 26;
			this->noneWire5->TabStop = true;
			this->noneWire5->Text = L"None";
			this->noneWire5->UseVisualStyleBackColor = true;
			// 
			// yellowWire5
			// 
			this->yellowWire5->AutoSize = true;
			this->yellowWire5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->yellowWire5->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->yellowWire5->Location = System::Drawing::Point(16, 136);
			this->yellowWire5->Margin = System::Windows::Forms::Padding(2);
			this->yellowWire5->Name = L"yellowWire5";
			this->yellowWire5->Size = System::Drawing::Size(62, 17);
			this->yellowWire5->TabIndex = 25;
			this->yellowWire5->TabStop = true;
			this->yellowWire5->Text = L"Yellow";
			this->yellowWire5->UseVisualStyleBackColor = true;
			// 
			// whiteWire5
			// 
			this->whiteWire5->AutoSize = true;
			this->whiteWire5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->whiteWire5->ForeColor = System::Drawing::SystemColors::GrayText;
			this->whiteWire5->Location = System::Drawing::Point(16, 108);
			this->whiteWire5->Margin = System::Windows::Forms::Padding(2);
			this->whiteWire5->Name = L"whiteWire5";
			this->whiteWire5->Size = System::Drawing::Size(58, 17);
			this->whiteWire5->TabIndex = 24;
			this->whiteWire5->TabStop = true;
			this->whiteWire5->Text = L"White";
			this->whiteWire5->UseVisualStyleBackColor = true;
			// 
			// blackWire5
			// 
			this->blackWire5->AutoSize = true;
			this->blackWire5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blackWire5->Location = System::Drawing::Point(16, 80);
			this->blackWire5->Margin = System::Windows::Forms::Padding(2);
			this->blackWire5->Name = L"blackWire5";
			this->blackWire5->Size = System::Drawing::Size(57, 17);
			this->blackWire5->TabIndex = 23;
			this->blackWire5->TabStop = true;
			this->blackWire5->Text = L"Black";
			this->blackWire5->UseVisualStyleBackColor = true;
			// 
			// blueWire5
			// 
			this->blueWire5->AutoSize = true;
			this->blueWire5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blueWire5->ForeColor = System::Drawing::Color::Blue;
			this->blueWire5->Location = System::Drawing::Point(16, 52);
			this->blueWire5->Margin = System::Windows::Forms::Padding(2);
			this->blueWire5->Name = L"blueWire5";
			this->blueWire5->Size = System::Drawing::Size(50, 17);
			this->blueWire5->TabIndex = 22;
			this->blueWire5->TabStop = true;
			this->blueWire5->Text = L"Blue";
			this->blueWire5->UseVisualStyleBackColor = true;
			// 
			// redWire5
			// 
			this->redWire5->AutoSize = true;
			this->redWire5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->redWire5->ForeColor = System::Drawing::Color::Red;
			this->redWire5->Location = System::Drawing::Point(16, 24);
			this->redWire5->Margin = System::Windows::Forms::Padding(2);
			this->redWire5->Name = L"redWire5";
			this->redWire5->Size = System::Drawing::Size(48, 17);
			this->redWire5->TabIndex = 21;
			this->redWire5->TabStop = true;
			this->redWire5->Text = L"Red";
			this->redWire5->UseVisualStyleBackColor = true;
			// 
			// wire6
			// 
			this->wire6->Controls->Add(this->noneWire6);
			this->wire6->Controls->Add(this->yellowWire6);
			this->wire6->Controls->Add(this->whiteWire6);
			this->wire6->Controls->Add(this->blackWire6);
			this->wire6->Controls->Add(this->blueWire6);
			this->wire6->Controls->Add(this->redWire6);
			this->wire6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->wire6->Location = System::Drawing::Point(450, 66);
			this->wire6->Margin = System::Windows::Forms::Padding(2);
			this->wire6->Name = L"wire6";
			this->wire6->Padding = System::Windows::Forms::Padding(2);
			this->wire6->Size = System::Drawing::Size(82, 190);
			this->wire6->TabIndex = 5;
			this->wire6->TabStop = false;
			this->wire6->Text = L"Wire 6";
			// 
			// noneWire6
			// 
			this->noneWire6->AutoSize = true;
			this->noneWire6->Checked = true;
			this->noneWire6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->noneWire6->ForeColor = System::Drawing::Color::DarkRed;
			this->noneWire6->Location = System::Drawing::Point(16, 164);
			this->noneWire6->Margin = System::Windows::Forms::Padding(2);
			this->noneWire6->Name = L"noneWire6";
			this->noneWire6->Size = System::Drawing::Size(55, 17);
			this->noneWire6->TabIndex = 32;
			this->noneWire6->TabStop = true;
			this->noneWire6->Text = L"None";
			this->noneWire6->UseVisualStyleBackColor = true;
			// 
			// yellowWire6
			// 
			this->yellowWire6->AutoSize = true;
			this->yellowWire6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->yellowWire6->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->yellowWire6->Location = System::Drawing::Point(16, 136);
			this->yellowWire6->Margin = System::Windows::Forms::Padding(2);
			this->yellowWire6->Name = L"yellowWire6";
			this->yellowWire6->Size = System::Drawing::Size(62, 17);
			this->yellowWire6->TabIndex = 31;
			this->yellowWire6->TabStop = true;
			this->yellowWire6->Text = L"Yellow";
			this->yellowWire6->UseVisualStyleBackColor = true;
			// 
			// whiteWire6
			// 
			this->whiteWire6->AutoSize = true;
			this->whiteWire6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->whiteWire6->ForeColor = System::Drawing::SystemColors::GrayText;
			this->whiteWire6->Location = System::Drawing::Point(16, 108);
			this->whiteWire6->Margin = System::Windows::Forms::Padding(2);
			this->whiteWire6->Name = L"whiteWire6";
			this->whiteWire6->Size = System::Drawing::Size(58, 17);
			this->whiteWire6->TabIndex = 30;
			this->whiteWire6->TabStop = true;
			this->whiteWire6->Text = L"White";
			this->whiteWire6->UseVisualStyleBackColor = true;
			// 
			// blackWire6
			// 
			this->blackWire6->AutoSize = true;
			this->blackWire6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blackWire6->Location = System::Drawing::Point(16, 80);
			this->blackWire6->Margin = System::Windows::Forms::Padding(2);
			this->blackWire6->Name = L"blackWire6";
			this->blackWire6->Size = System::Drawing::Size(57, 17);
			this->blackWire6->TabIndex = 29;
			this->blackWire6->TabStop = true;
			this->blackWire6->Text = L"Black";
			this->blackWire6->UseVisualStyleBackColor = true;
			// 
			// blueWire6
			// 
			this->blueWire6->AutoSize = true;
			this->blueWire6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blueWire6->ForeColor = System::Drawing::Color::Blue;
			this->blueWire6->Location = System::Drawing::Point(16, 52);
			this->blueWire6->Margin = System::Windows::Forms::Padding(2);
			this->blueWire6->Name = L"blueWire6";
			this->blueWire6->Size = System::Drawing::Size(50, 17);
			this->blueWire6->TabIndex = 28;
			this->blueWire6->TabStop = true;
			this->blueWire6->Text = L"Blue";
			this->blueWire6->UseVisualStyleBackColor = true;
			// 
			// redWire6
			// 
			this->redWire6->AutoSize = true;
			this->redWire6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->redWire6->ForeColor = System::Drawing::Color::Red;
			this->redWire6->Location = System::Drawing::Point(16, 24);
			this->redWire6->Margin = System::Windows::Forms::Padding(2);
			this->redWire6->Name = L"redWire6";
			this->redWire6->Size = System::Drawing::Size(48, 17);
			this->redWire6->TabIndex = 27;
			this->redWire6->TabStop = true;
			this->redWire6->Text = L"Red";
			this->redWire6->UseVisualStyleBackColor = true;
			// 
			// calcButton
			// 
			this->calcButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->calcButton->Location = System::Drawing::Point(233, 278);
			this->calcButton->Margin = System::Windows::Forms::Padding(2);
			this->calcButton->Name = L"calcButton";
			this->calcButton->Size = System::Drawing::Size(68, 25);
			this->calcButton->TabIndex = 33;
			this->calcButton->Text = L"Calculate";
			this->calcButton->UseVisualStyleBackColor = true;
			this->calcButton->Click += gcnew System::EventHandler(this, &ModuleSimpleWires::button1_Click);
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(477, 285);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 34;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ModuleSimpleWires::exitButton_Click);
			// 
			// ModuleSimpleWires
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(542, 311);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->calcButton);
			this->Controls->Add(this->wire6);
			this->Controls->Add(this->wire5);
			this->Controls->Add(this->wire4);
			this->Controls->Add(this->wire3);
			this->Controls->Add(this->wire2);
			this->Controls->Add(this->wire1);
			this->Controls->Add(this->inputPrompt);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ModuleSimpleWires";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Simple Wires";
			this->Load += gcnew System::EventHandler(this, &ModuleSimpleWires::ModuleSimpleWires_Load);
			this->wire1->ResumeLayout(false);
			this->wire1->PerformLayout();
			this->wire2->ResumeLayout(false);
			this->wire2->PerformLayout();
			this->wire3->ResumeLayout(false);
			this->wire3->PerformLayout();
			this->wire4->ResumeLayout(false);
			this->wire4->PerformLayout();
			this->wire5->ResumeLayout(false);
			this->wire5->PerformLayout();
			this->wire6->ResumeLayout(false);
			this->wire6->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ModuleSimpleWires_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Calculate();
	}
private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	//otherform->Show();
}
};
}
