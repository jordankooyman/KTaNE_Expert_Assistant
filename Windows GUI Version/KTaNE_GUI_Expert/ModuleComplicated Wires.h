/**********************************************************
   file: ModuleComplicatedWires.h
 author: Jordan Kooyman
purpose: Contains Complicated Wires module window and the calculations for a wire as a member function

Issue with trying to set an Icon on this form only (resource not accessible) - happens for any icon
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
	/// Summary for ModuleComplicatedWires
	/// </summary>
	public ref class ModuleComplicatedWires : public System::Windows::Forms::Form
	{
	public:
		ModuleComplicatedWires(void)
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
		~ModuleComplicatedWires()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ exitButton;
	protected:
	private: System::Windows::Forms::Button^ calcButton;
	private: System::Windows::Forms::GroupBox^ wire1;
	private: System::Windows::Forms::Label^ wire1Result;

	private: System::Windows::Forms::CheckBox^ wire1LED;

	private: System::Windows::Forms::CheckBox^ wire1Star;

	private: System::Windows::Forms::CheckBox^ wire1Blue;

	private: System::Windows::Forms::CheckBox^ wire1Red;
	private: System::Windows::Forms::GroupBox^ wire2;

	private: System::Windows::Forms::Label^ wire2Result;

	private: System::Windows::Forms::CheckBox^ wire2LED;

	private: System::Windows::Forms::CheckBox^ wire2Star;

	private: System::Windows::Forms::CheckBox^ wire2Blue;

	private: System::Windows::Forms::CheckBox^ wire2Red;
	private: System::Windows::Forms::GroupBox^ wire3;


	private: System::Windows::Forms::Label^ wire3Result;

	private: System::Windows::Forms::CheckBox^ wire3LED;

	private: System::Windows::Forms::CheckBox^ wire3Star;

	private: System::Windows::Forms::CheckBox^ wire3Blue;

	private: System::Windows::Forms::CheckBox^ wire3Red;
	private: System::Windows::Forms::GroupBox^ wire6;


	private: System::Windows::Forms::Label^ wire6Result;

	private: System::Windows::Forms::CheckBox^ wire6LED;

	private: System::Windows::Forms::CheckBox^ wire6Star;

	private: System::Windows::Forms::CheckBox^ wire6Blue;

	private: System::Windows::Forms::CheckBox^ wire6Red;
	private: System::Windows::Forms::GroupBox^ wire5;


	private: System::Windows::Forms::Label^ wire5Result;

	private: System::Windows::Forms::CheckBox^ wire5LED;

	private: System::Windows::Forms::CheckBox^ wire5Star;

	private: System::Windows::Forms::CheckBox^ wire5Blue;

	private: System::Windows::Forms::CheckBox^ wire5Red;
	private: System::Windows::Forms::GroupBox^ wire4;


	private: System::Windows::Forms::Label^ wire4Result;

	private: System::Windows::Forms::CheckBox^ wire4LED;

	private: System::Windows::Forms::CheckBox^ wire4Star;

	private: System::Windows::Forms::CheckBox^ wire4Blue;

	private: System::Windows::Forms::CheckBox^ wire4Red;
	private: System::Windows::Forms::Button^ resetButton;
	private: System::Windows::Forms::Label^ inputPrompt;



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
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->calcButton = (gcnew System::Windows::Forms::Button());
			this->wire1 = (gcnew System::Windows::Forms::GroupBox());
			this->wire1LED = (gcnew System::Windows::Forms::CheckBox());
			this->wire1Star = (gcnew System::Windows::Forms::CheckBox());
			this->wire1Blue = (gcnew System::Windows::Forms::CheckBox());
			this->wire1Red = (gcnew System::Windows::Forms::CheckBox());
			this->wire1Result = (gcnew System::Windows::Forms::Label());
			this->wire2 = (gcnew System::Windows::Forms::GroupBox());
			this->wire2Result = (gcnew System::Windows::Forms::Label());
			this->wire2LED = (gcnew System::Windows::Forms::CheckBox());
			this->wire2Star = (gcnew System::Windows::Forms::CheckBox());
			this->wire2Blue = (gcnew System::Windows::Forms::CheckBox());
			this->wire2Red = (gcnew System::Windows::Forms::CheckBox());
			this->wire3 = (gcnew System::Windows::Forms::GroupBox());
			this->wire3Result = (gcnew System::Windows::Forms::Label());
			this->wire3LED = (gcnew System::Windows::Forms::CheckBox());
			this->wire3Star = (gcnew System::Windows::Forms::CheckBox());
			this->wire3Blue = (gcnew System::Windows::Forms::CheckBox());
			this->wire3Red = (gcnew System::Windows::Forms::CheckBox());
			this->wire6 = (gcnew System::Windows::Forms::GroupBox());
			this->wire6Result = (gcnew System::Windows::Forms::Label());
			this->wire6LED = (gcnew System::Windows::Forms::CheckBox());
			this->wire6Blue = (gcnew System::Windows::Forms::CheckBox());
			this->wire6Red = (gcnew System::Windows::Forms::CheckBox());
			this->wire6Star = (gcnew System::Windows::Forms::CheckBox());
			this->wire5 = (gcnew System::Windows::Forms::GroupBox());
			this->wire5Result = (gcnew System::Windows::Forms::Label());
			this->wire5LED = (gcnew System::Windows::Forms::CheckBox());
			this->wire5Star = (gcnew System::Windows::Forms::CheckBox());
			this->wire5Blue = (gcnew System::Windows::Forms::CheckBox());
			this->wire5Red = (gcnew System::Windows::Forms::CheckBox());
			this->wire4 = (gcnew System::Windows::Forms::GroupBox());
			this->wire4Result = (gcnew System::Windows::Forms::Label());
			this->wire4LED = (gcnew System::Windows::Forms::CheckBox());
			this->wire4Star = (gcnew System::Windows::Forms::CheckBox());
			this->wire4Blue = (gcnew System::Windows::Forms::CheckBox());
			this->wire4Red = (gcnew System::Windows::Forms::CheckBox());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->inputPrompt = (gcnew System::Windows::Forms::Label());
			this->wire1->SuspendLayout();
			this->wire2->SuspendLayout();
			this->wire3->SuspendLayout();
			this->wire6->SuspendLayout();
			this->wire5->SuspendLayout();
			this->wire4->SuspendLayout();
			this->SuspendLayout();
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(571, 233);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 12;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ModuleComplicatedWires::exitButton_Click);
			// 
			// calcButton
			// 
			this->calcButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->calcButton->Location = System::Drawing::Point(285, 215);
			this->calcButton->Margin = System::Windows::Forms::Padding(2);
			this->calcButton->Name = L"calcButton";
			this->calcButton->Size = System::Drawing::Size(68, 25);
			this->calcButton->TabIndex = 11;
			this->calcButton->Text = L"Calculate";
			this->calcButton->UseVisualStyleBackColor = true;
			this->calcButton->Click += gcnew System::EventHandler(this, &ModuleComplicatedWires::calcButton_Click);
			// 
			// wire1
			// 
			this->wire1->Controls->Add(this->wire1LED);
			this->wire1->Controls->Add(this->wire1Star);
			this->wire1->Controls->Add(this->wire1Blue);
			this->wire1->Controls->Add(this->wire1Red);
			this->wire1->Controls->Add(this->wire1Result);
			this->wire1->Location = System::Drawing::Point(13, 54);
			this->wire1->Name = L"wire1";
			this->wire1->Size = System::Drawing::Size(97, 154);
			this->wire1->TabIndex = 13;
			this->wire1->TabStop = false;
			this->wire1->Text = L"Wire 1";
			// 
			// wire1LED
			// 
			this->wire1LED->AutoSize = true;
			this->wire1LED->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire1LED->ForeColor = System::Drawing::Color::Gold;
			this->wire1LED->Location = System::Drawing::Point(7, 97);
			this->wire1LED->Name = L"wire1LED";
			this->wire1LED->Size = System::Drawing::Size(59, 22);
			this->wire1LED->TabIndex = 3;
			this->wire1LED->Text = L"LED";
			this->wire1LED->UseVisualStyleBackColor = true;
			// 
			// wire1Star
			// 
			this->wire1Star->AutoSize = true;
			this->wire1Star->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire1Star->ForeColor = System::Drawing::Color::Goldenrod;
			this->wire1Star->Location = System::Drawing::Point(7, 73);
			this->wire1Star->Name = L"wire1Star";
			this->wire1Star->Size = System::Drawing::Size(58, 22);
			this->wire1Star->TabIndex = 2;
			this->wire1Star->Text = L"Star";
			this->wire1Star->UseVisualStyleBackColor = true;
			// 
			// wire1Blue
			// 
			this->wire1Blue->AutoSize = true;
			this->wire1Blue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire1Blue->ForeColor = System::Drawing::Color::MediumBlue;
			this->wire1Blue->Location = System::Drawing::Point(7, 44);
			this->wire1Blue->Name = L"wire1Blue";
			this->wire1Blue->Size = System::Drawing::Size(88, 19);
			this->wire1Blue->TabIndex = 1;
			this->wire1Blue->Text = L"Blue Wire";
			this->wire1Blue->UseVisualStyleBackColor = true;
			// 
			// wire1Red
			// 
			this->wire1Red->AutoSize = true;
			this->wire1Red->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire1Red->ForeColor = System::Drawing::Color::Firebrick;
			this->wire1Red->Location = System::Drawing::Point(7, 20);
			this->wire1Red->Name = L"wire1Red";
			this->wire1Red->Size = System::Drawing::Size(85, 19);
			this->wire1Red->TabIndex = 0;
			this->wire1Red->Text = L"Red Wire";
			this->wire1Red->UseVisualStyleBackColor = true;
			// 
			// wire1Result
			// 
			this->wire1Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire1Result->ForeColor = System::Drawing::Color::Firebrick;
			this->wire1Result->Location = System::Drawing::Point(0, 128);
			this->wire1Result->Name = L"wire1Result";
			this->wire1Result->Size = System::Drawing::Size(97, 25);
			this->wire1Result->TabIndex = 4;
			this->wire1Result->Text = L"Don\'t Cut";
			this->wire1Result->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// wire2
			// 
			this->wire2->Controls->Add(this->wire2Result);
			this->wire2->Controls->Add(this->wire2LED);
			this->wire2->Controls->Add(this->wire2Star);
			this->wire2->Controls->Add(this->wire2Blue);
			this->wire2->Controls->Add(this->wire2Red);
			this->wire2->Location = System::Drawing::Point(116, 54);
			this->wire2->Name = L"wire2";
			this->wire2->Size = System::Drawing::Size(97, 154);
			this->wire2->TabIndex = 14;
			this->wire2->TabStop = false;
			this->wire2->Text = L"Wire 2";
			// 
			// wire2Result
			// 
			this->wire2Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire2Result->ForeColor = System::Drawing::Color::Firebrick;
			this->wire2Result->Location = System::Drawing::Point(0, 128);
			this->wire2Result->Name = L"wire2Result";
			this->wire2Result->Size = System::Drawing::Size(97, 25);
			this->wire2Result->TabIndex = 4;
			this->wire2Result->Text = L"Don\'t Cut";
			this->wire2Result->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// wire2LED
			// 
			this->wire2LED->AutoSize = true;
			this->wire2LED->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire2LED->ForeColor = System::Drawing::Color::Gold;
			this->wire2LED->Location = System::Drawing::Point(7, 97);
			this->wire2LED->Name = L"wire2LED";
			this->wire2LED->Size = System::Drawing::Size(59, 22);
			this->wire2LED->TabIndex = 3;
			this->wire2LED->Text = L"LED";
			this->wire2LED->UseVisualStyleBackColor = true;
			// 
			// wire2Star
			// 
			this->wire2Star->AutoSize = true;
			this->wire2Star->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire2Star->ForeColor = System::Drawing::Color::Goldenrod;
			this->wire2Star->Location = System::Drawing::Point(7, 73);
			this->wire2Star->Name = L"wire2Star";
			this->wire2Star->Size = System::Drawing::Size(58, 22);
			this->wire2Star->TabIndex = 2;
			this->wire2Star->Text = L"Star";
			this->wire2Star->UseVisualStyleBackColor = true;
			// 
			// wire2Blue
			// 
			this->wire2Blue->AutoSize = true;
			this->wire2Blue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire2Blue->ForeColor = System::Drawing::Color::MediumBlue;
			this->wire2Blue->Location = System::Drawing::Point(7, 44);
			this->wire2Blue->Name = L"wire2Blue";
			this->wire2Blue->Size = System::Drawing::Size(88, 19);
			this->wire2Blue->TabIndex = 1;
			this->wire2Blue->Text = L"Blue Wire";
			this->wire2Blue->UseVisualStyleBackColor = true;
			// 
			// wire2Red
			// 
			this->wire2Red->AutoSize = true;
			this->wire2Red->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire2Red->ForeColor = System::Drawing::Color::Firebrick;
			this->wire2Red->Location = System::Drawing::Point(7, 20);
			this->wire2Red->Name = L"wire2Red";
			this->wire2Red->Size = System::Drawing::Size(85, 19);
			this->wire2Red->TabIndex = 0;
			this->wire2Red->Text = L"Red Wire";
			this->wire2Red->UseVisualStyleBackColor = true;
			// 
			// wire3
			// 
			this->wire3->Controls->Add(this->wire3Result);
			this->wire3->Controls->Add(this->wire3LED);
			this->wire3->Controls->Add(this->wire3Star);
			this->wire3->Controls->Add(this->wire3Blue);
			this->wire3->Controls->Add(this->wire3Red);
			this->wire3->Location = System::Drawing::Point(219, 54);
			this->wire3->Name = L"wire3";
			this->wire3->Size = System::Drawing::Size(97, 154);
			this->wire3->TabIndex = 14;
			this->wire3->TabStop = false;
			this->wire3->Text = L"Wire 3";
			// 
			// wire3Result
			// 
			this->wire3Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire3Result->ForeColor = System::Drawing::Color::Firebrick;
			this->wire3Result->Location = System::Drawing::Point(0, 128);
			this->wire3Result->Name = L"wire3Result";
			this->wire3Result->Size = System::Drawing::Size(97, 25);
			this->wire3Result->TabIndex = 4;
			this->wire3Result->Text = L"Don\'t Cut";
			this->wire3Result->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// wire3LED
			// 
			this->wire3LED->AutoSize = true;
			this->wire3LED->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire3LED->ForeColor = System::Drawing::Color::Gold;
			this->wire3LED->Location = System::Drawing::Point(7, 97);
			this->wire3LED->Name = L"wire3LED";
			this->wire3LED->Size = System::Drawing::Size(59, 22);
			this->wire3LED->TabIndex = 3;
			this->wire3LED->Text = L"LED";
			this->wire3LED->UseVisualStyleBackColor = true;
			// 
			// wire3Star
			// 
			this->wire3Star->AutoSize = true;
			this->wire3Star->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire3Star->ForeColor = System::Drawing::Color::Goldenrod;
			this->wire3Star->Location = System::Drawing::Point(7, 73);
			this->wire3Star->Name = L"wire3Star";
			this->wire3Star->Size = System::Drawing::Size(58, 22);
			this->wire3Star->TabIndex = 2;
			this->wire3Star->Text = L"Star";
			this->wire3Star->UseVisualStyleBackColor = true;
			// 
			// wire3Blue
			// 
			this->wire3Blue->AutoSize = true;
			this->wire3Blue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire3Blue->ForeColor = System::Drawing::Color::MediumBlue;
			this->wire3Blue->Location = System::Drawing::Point(7, 44);
			this->wire3Blue->Name = L"wire3Blue";
			this->wire3Blue->Size = System::Drawing::Size(88, 19);
			this->wire3Blue->TabIndex = 1;
			this->wire3Blue->Text = L"Blue Wire";
			this->wire3Blue->UseVisualStyleBackColor = true;
			// 
			// wire3Red
			// 
			this->wire3Red->AutoSize = true;
			this->wire3Red->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire3Red->ForeColor = System::Drawing::Color::Firebrick;
			this->wire3Red->Location = System::Drawing::Point(7, 20);
			this->wire3Red->Name = L"wire3Red";
			this->wire3Red->Size = System::Drawing::Size(85, 19);
			this->wire3Red->TabIndex = 0;
			this->wire3Red->Text = L"Red Wire";
			this->wire3Red->UseVisualStyleBackColor = true;
			// 
			// wire6
			// 
			this->wire6->Controls->Add(this->wire6Result);
			this->wire6->Controls->Add(this->wire6LED);
			this->wire6->Controls->Add(this->wire6Blue);
			this->wire6->Controls->Add(this->wire6Red);
			this->wire6->Controls->Add(this->wire6Star);
			this->wire6->Location = System::Drawing::Point(528, 54);
			this->wire6->Name = L"wire6";
			this->wire6->Size = System::Drawing::Size(97, 154);
			this->wire6->TabIndex = 17;
			this->wire6->TabStop = false;
			this->wire6->Text = L"Wire 6";
			// 
			// wire6Result
			// 
			this->wire6Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire6Result->ForeColor = System::Drawing::Color::Green;
			this->wire6Result->Location = System::Drawing::Point(0, 128);
			this->wire6Result->Name = L"wire6Result";
			this->wire6Result->Size = System::Drawing::Size(97, 25);
			this->wire6Result->TabIndex = 4;
			this->wire6Result->Text = L"Cut";
			this->wire6Result->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// wire6LED
			// 
			this->wire6LED->AutoSize = true;
			this->wire6LED->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire6LED->ForeColor = System::Drawing::Color::Gold;
			this->wire6LED->Location = System::Drawing::Point(7, 97);
			this->wire6LED->Name = L"wire6LED";
			this->wire6LED->Size = System::Drawing::Size(59, 22);
			this->wire6LED->TabIndex = 3;
			this->wire6LED->Text = L"LED";
			this->wire6LED->UseVisualStyleBackColor = true;
			// 
			// wire6Blue
			// 
			this->wire6Blue->AutoSize = true;
			this->wire6Blue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire6Blue->ForeColor = System::Drawing::Color::MediumBlue;
			this->wire6Blue->Location = System::Drawing::Point(7, 44);
			this->wire6Blue->Name = L"wire6Blue";
			this->wire6Blue->Size = System::Drawing::Size(88, 19);
			this->wire6Blue->TabIndex = 1;
			this->wire6Blue->Text = L"Blue Wire";
			this->wire6Blue->UseVisualStyleBackColor = true;
			// 
			// wire6Red
			// 
			this->wire6Red->AutoSize = true;
			this->wire6Red->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire6Red->ForeColor = System::Drawing::Color::Firebrick;
			this->wire6Red->Location = System::Drawing::Point(7, 20);
			this->wire6Red->Name = L"wire6Red";
			this->wire6Red->Size = System::Drawing::Size(85, 19);
			this->wire6Red->TabIndex = 0;
			this->wire6Red->Text = L"Red Wire";
			this->wire6Red->UseVisualStyleBackColor = true;
			// 
			// wire6Star
			// 
			this->wire6Star->AutoSize = true;
			this->wire6Star->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire6Star->ForeColor = System::Drawing::Color::Goldenrod;
			this->wire6Star->Location = System::Drawing::Point(7, 73);
			this->wire6Star->Name = L"wire6Star";
			this->wire6Star->Size = System::Drawing::Size(58, 22);
			this->wire6Star->TabIndex = 2;
			this->wire6Star->Text = L"Star";
			this->wire6Star->UseVisualStyleBackColor = true;
			// 
			// wire5
			// 
			this->wire5->Controls->Add(this->wire5Result);
			this->wire5->Controls->Add(this->wire5LED);
			this->wire5->Controls->Add(this->wire5Star);
			this->wire5->Controls->Add(this->wire5Blue);
			this->wire5->Controls->Add(this->wire5Red);
			this->wire5->Location = System::Drawing::Point(425, 54);
			this->wire5->Name = L"wire5";
			this->wire5->Size = System::Drawing::Size(97, 154);
			this->wire5->TabIndex = 16;
			this->wire5->TabStop = false;
			this->wire5->Text = L"Wire 5";
			// 
			// wire5Result
			// 
			this->wire5Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire5Result->ForeColor = System::Drawing::Color::Green;
			this->wire5Result->Location = System::Drawing::Point(0, 128);
			this->wire5Result->Name = L"wire5Result";
			this->wire5Result->Size = System::Drawing::Size(97, 25);
			this->wire5Result->TabIndex = 4;
			this->wire5Result->Text = L"Cut";
			this->wire5Result->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// wire5LED
			// 
			this->wire5LED->AutoSize = true;
			this->wire5LED->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire5LED->ForeColor = System::Drawing::Color::Gold;
			this->wire5LED->Location = System::Drawing::Point(7, 97);
			this->wire5LED->Name = L"wire5LED";
			this->wire5LED->Size = System::Drawing::Size(59, 22);
			this->wire5LED->TabIndex = 3;
			this->wire5LED->Text = L"LED";
			this->wire5LED->UseVisualStyleBackColor = true;
			// 
			// wire5Star
			// 
			this->wire5Star->AutoSize = true;
			this->wire5Star->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire5Star->ForeColor = System::Drawing::Color::Goldenrod;
			this->wire5Star->Location = System::Drawing::Point(7, 73);
			this->wire5Star->Name = L"wire5Star";
			this->wire5Star->Size = System::Drawing::Size(58, 22);
			this->wire5Star->TabIndex = 2;
			this->wire5Star->Text = L"Star";
			this->wire5Star->UseVisualStyleBackColor = true;
			// 
			// wire5Blue
			// 
			this->wire5Blue->AutoSize = true;
			this->wire5Blue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire5Blue->ForeColor = System::Drawing::Color::MediumBlue;
			this->wire5Blue->Location = System::Drawing::Point(7, 44);
			this->wire5Blue->Name = L"wire5Blue";
			this->wire5Blue->Size = System::Drawing::Size(88, 19);
			this->wire5Blue->TabIndex = 1;
			this->wire5Blue->Text = L"Blue Wire";
			this->wire5Blue->UseVisualStyleBackColor = true;
			// 
			// wire5Red
			// 
			this->wire5Red->AutoSize = true;
			this->wire5Red->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire5Red->ForeColor = System::Drawing::Color::Firebrick;
			this->wire5Red->Location = System::Drawing::Point(7, 20);
			this->wire5Red->Name = L"wire5Red";
			this->wire5Red->Size = System::Drawing::Size(85, 19);
			this->wire5Red->TabIndex = 0;
			this->wire5Red->Text = L"Red Wire";
			this->wire5Red->UseVisualStyleBackColor = true;
			// 
			// wire4
			// 
			this->wire4->Controls->Add(this->wire4Result);
			this->wire4->Controls->Add(this->wire4LED);
			this->wire4->Controls->Add(this->wire4Star);
			this->wire4->Controls->Add(this->wire4Blue);
			this->wire4->Controls->Add(this->wire4Red);
			this->wire4->Location = System::Drawing::Point(322, 54);
			this->wire4->Name = L"wire4";
			this->wire4->Size = System::Drawing::Size(97, 154);
			this->wire4->TabIndex = 15;
			this->wire4->TabStop = false;
			this->wire4->Text = L"Wire 4";
			// 
			// wire4Result
			// 
			this->wire4Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire4Result->ForeColor = System::Drawing::Color::Green;
			this->wire4Result->Location = System::Drawing::Point(0, 128);
			this->wire4Result->Name = L"wire4Result";
			this->wire4Result->Size = System::Drawing::Size(97, 25);
			this->wire4Result->TabIndex = 4;
			this->wire4Result->Text = L"Cut";
			this->wire4Result->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// wire4LED
			// 
			this->wire4LED->AutoSize = true;
			this->wire4LED->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire4LED->ForeColor = System::Drawing::Color::Gold;
			this->wire4LED->Location = System::Drawing::Point(7, 97);
			this->wire4LED->Name = L"wire4LED";
			this->wire4LED->Size = System::Drawing::Size(59, 22);
			this->wire4LED->TabIndex = 3;
			this->wire4LED->Text = L"LED";
			this->wire4LED->UseVisualStyleBackColor = true;
			// 
			// wire4Star
			// 
			this->wire4Star->AutoSize = true;
			this->wire4Star->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire4Star->ForeColor = System::Drawing::Color::Goldenrod;
			this->wire4Star->Location = System::Drawing::Point(7, 73);
			this->wire4Star->Name = L"wire4Star";
			this->wire4Star->Size = System::Drawing::Size(58, 22);
			this->wire4Star->TabIndex = 2;
			this->wire4Star->Text = L"Star";
			this->wire4Star->UseVisualStyleBackColor = true;
			// 
			// wire4Blue
			// 
			this->wire4Blue->AutoSize = true;
			this->wire4Blue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire4Blue->ForeColor = System::Drawing::Color::MediumBlue;
			this->wire4Blue->Location = System::Drawing::Point(7, 44);
			this->wire4Blue->Name = L"wire4Blue";
			this->wire4Blue->Size = System::Drawing::Size(88, 19);
			this->wire4Blue->TabIndex = 1;
			this->wire4Blue->Text = L"Blue Wire";
			this->wire4Blue->UseVisualStyleBackColor = true;
			// 
			// wire4Red
			// 
			this->wire4Red->AutoSize = true;
			this->wire4Red->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wire4Red->ForeColor = System::Drawing::Color::Firebrick;
			this->wire4Red->Location = System::Drawing::Point(7, 20);
			this->wire4Red->Name = L"wire4Red";
			this->wire4Red->Size = System::Drawing::Size(85, 19);
			this->wire4Red->TabIndex = 0;
			this->wire4Red->Text = L"Red Wire";
			this->wire4Red->UseVisualStyleBackColor = true;
			// 
			// resetButton
			// 
			this->resetButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->resetButton->Location = System::Drawing::Point(12, 233);
			this->resetButton->Margin = System::Windows::Forms::Padding(2);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(55, 21);
			this->resetButton->TabIndex = 18;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &ModuleComplicatedWires::resetButton_Click);
			// 
			// inputPrompt
			// 
			this->inputPrompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputPrompt->Location = System::Drawing::Point(7, 7);
			this->inputPrompt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->inputPrompt->Name = L"inputPrompt";
			this->inputPrompt->Size = System::Drawing::Size(625, 42);
			this->inputPrompt->TabIndex = 19;
			this->inputPrompt->Text = L"Enter all the information for each wire, ignoring white, then click calculate";
			this->inputPrompt->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// ModuleComplicatedWires
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(638, 262);
			this->Controls->Add(this->inputPrompt);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->calcButton);
			this->Controls->Add(this->wire6);
			this->Controls->Add(this->wire3);
			this->Controls->Add(this->wire5);
			this->Controls->Add(this->wire2);
			this->Controls->Add(this->wire4);
			this->Controls->Add(this->wire1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ModuleComplicatedWires";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Complicated Wires";
			this->Load += gcnew System::EventHandler(this, &ModuleComplicatedWires::ModuleComplicatedWires_Load);
			this->wire1->ResumeLayout(false);
			this->wire1->PerformLayout();
			this->wire2->ResumeLayout(false);
			this->wire2->PerformLayout();
			this->wire3->ResumeLayout(false);
			this->wire3->PerformLayout();
			this->wire6->ResumeLayout(false);
			this->wire6->PerformLayout();
			this->wire5->ResumeLayout(false);
			this->wire5->PerformLayout();
			this->wire4->ResumeLayout(false);
			this->wire4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private:
	// Check the provided elements for different combinations, returns true or false based on the reference Venn Diagram in the Bomb Defusal manual
	void WireCheck(System::Windows::Forms::CheckBox^ red, System::Windows::Forms::CheckBox^ blue, System::Windows::Forms::CheckBox^ star, System::Windows::Forms::CheckBox^ led, System::Windows::Forms::Label^ output)
	{
		bool BatteryResult = CurrentBatteries.batteriesCheck(2) >= 2; // At least 2 batteries
		bool SerialResult = CurrentSerial.serialCheck(5) % 2 == 0 && CurrentSerial.serialCheck(5) < 58; // Even number in last digit
		bool PortsResult = CurrentPorts.portsCheck(1);
		bool Result;

		//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(SerialResult), "Debug");
		//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(CurrentSerial.serialCheck(5)), "Debug");

		if (blue->Checked && red->Checked) // Both
		{
			if (star->Checked && led->Checked) // Both
			{
				Result = false;
			}
			else if (star->Checked) // Star
			{
				Result = PortsResult;
			}
			else if (led->Checked) // LED
			{
				Result = SerialResult;
			}
			else // Neither (not input)
			{
				Result = SerialResult;
			}
		}
		else if (red->Checked) // Red (white optional)
		{
			if (star->Checked && led->Checked) // Both
			{
				Result = BatteryResult;
			}
			else if (star->Checked) // Star
			{
				Result = true;
			}
			else if (led->Checked) // LED
			{
				Result = BatteryResult;
			}
			else // Neither (not input)
			{
				Result = SerialResult;
			}
		}
		else if (blue->Checked) // Blue (white optional)
		{
			if (star->Checked && led->Checked) // Both
			{
				Result = PortsResult;
			}
			else if (star->Checked) // Star
			{
				Result = false;
			}
			else if (led->Checked) // LED
			{
				Result = PortsResult;
			}
			else // Neither (not input)
			{
				Result = SerialResult;
			}
		}
		else // White (not input)
		{
			if (star->Checked && led->Checked) // Both
			{
				Result = BatteryResult;
			}
			else if (star->Checked) // Star
			{
				Result = true;
			}
			else if (led->Checked) // LED
			{
				Result = false;
			}
			else // Neither (not input)
			{
				Result = true;
			}
		}
		if (Result) // Cut
		{
			output->Text = "Cut";
			output->ForeColor = System::Drawing::Color::Green;
		}
		else // Do not Cut
		{
			output->Text = "Don't Cut";
			output->ForeColor = System::Drawing::Color::Firebrick;
		}
	}
	void ResetForm()
	{
		wire1Red->Checked = false;
		wire1Blue->Checked = false;
		wire1Star->Checked = false;
		wire1LED->Checked = false;
		wire1Result->Text = "";
		wire2Red->Checked = false;
		wire2Blue->Checked = false;
		wire2Star->Checked = false;
		wire2LED->Checked = false;
		wire2Result->Text = "";
		wire3Red->Checked = false;
		wire3Blue->Checked = false;
		wire3Star->Checked = false;
		wire3LED->Checked = false;
		wire3Result->Text = "";
		wire4Red->Checked = false;
		wire4Blue->Checked = false;
		wire4Star->Checked = false;
		wire4LED->Checked = false;
		wire4Result->Text = "";
		wire5Red->Checked = false;
		wire5Blue->Checked = false;
		wire5Star->Checked = false;
		wire5LED->Checked = false;
		wire5Result->Text = "";
		wire6Red->Checked = false;
		wire6Blue->Checked = false;
		wire6Star->Checked = false;
		wire6LED->Checked = false;
		wire6Result->Text = "";
	}
public:
	void Calculate()
	{
		//Ensure all needed Bomb Constants have been input, otherwise, request them and stop calculation to resume later
		if (!CurrentSerial.serialValid())
		{
			pauseCalculation(this);
			OpenWindow(4);
			return;
		}
		else if (!CurrentBatteries.batteriesValid())
		{
			pauseCalculation(this);
			OpenWindow(3);
			return;
		}
		else if (!CurrentPorts.portsValid())
		{
			pauseCalculation(this);
			OpenWindow(2);
			return;
		}

		WireCheck(wire1Red, wire1Blue, wire1Star, wire1LED, wire1Result);
		WireCheck(wire2Red, wire2Blue, wire2Star, wire2LED, wire2Result);
		WireCheck(wire3Red, wire3Blue, wire3Star, wire3LED, wire3Result);
		WireCheck(wire4Red, wire4Blue, wire4Star, wire4LED, wire4Result);
		WireCheck(wire5Red, wire5Blue, wire5Star, wire5LED, wire5Result);
		WireCheck(wire6Red, wire6Blue, wire6Star, wire6LED, wire6Result);
	}

	private: System::Void ModuleComplicatedWires_Load(System::Object^ sender, System::EventArgs^ e) {
		ResetForm();
	}
private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void calcButton_Click(System::Object^ sender, System::EventArgs^ e) {
	Calculate();
}
private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ResetForm();
}
};
}
