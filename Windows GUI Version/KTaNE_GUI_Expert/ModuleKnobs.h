/**********************************************************
   file: ModuleKnobs.h
 author: Jordan Kooyman
purpose: Contains The Knob module window and the calculations for solving the knob as a member function
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
	/// Summary for ModuleKnobs
	/// </summary>
	public ref class ModuleKnobs : public System::Windows::Forms::Form
	{
	private:
		cli::array<bool, 1>^ Clicked;
	public:
		ModuleKnobs(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Clicked = gcnew cli::array<bool, 1>(12);
			for (int i = 0; i < 12; i++) // Initialize array to falses
			{
				Clicked[i] = false;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ModuleKnobs()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ exitButton;
	protected:
	private: System::Windows::Forms::Button^ calcButton;
	private: System::Windows::Forms::Label^ LED1;
	private: System::Windows::Forms::Label^ LED2;
	private: System::Windows::Forms::Label^ LED4;



	private: System::Windows::Forms::Label^ LED3;
	private: System::Windows::Forms::Label^ LED6;



	private: System::Windows::Forms::Label^ LED5;
	private: System::Windows::Forms::Label^ LED8;



	private: System::Windows::Forms::Label^ LED7;
	private: System::Windows::Forms::Label^ LED10;


	private: System::Windows::Forms::Label^ LED9;
	private: System::Windows::Forms::Label^ LED12;


	private: System::Windows::Forms::Label^ LED11;


	private: System::Windows::Forms::Label^ outputLabel;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModuleKnobs::typeid));
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->calcButton = (gcnew System::Windows::Forms::Button());
			this->LED1 = (gcnew System::Windows::Forms::Label());
			this->LED2 = (gcnew System::Windows::Forms::Label());
			this->LED4 = (gcnew System::Windows::Forms::Label());
			this->LED3 = (gcnew System::Windows::Forms::Label());
			this->LED6 = (gcnew System::Windows::Forms::Label());
			this->LED5 = (gcnew System::Windows::Forms::Label());
			this->LED8 = (gcnew System::Windows::Forms::Label());
			this->LED7 = (gcnew System::Windows::Forms::Label());
			this->LED10 = (gcnew System::Windows::Forms::Label());
			this->LED9 = (gcnew System::Windows::Forms::Label());
			this->LED12 = (gcnew System::Windows::Forms::Label());
			this->LED11 = (gcnew System::Windows::Forms::Label());
			this->outputLabel = (gcnew System::Windows::Forms::Label());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(166, 211);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 12;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ModuleKnobs::exitButton_Click);
			// 
			// calcButton
			// 
			this->calcButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->calcButton->Location = System::Drawing::Point(79, 178);
			this->calcButton->Margin = System::Windows::Forms::Padding(2);
			this->calcButton->Name = L"calcButton";
			this->calcButton->Size = System::Drawing::Size(68, 25);
			this->calcButton->TabIndex = 11;
			this->calcButton->Text = L"Submit";
			this->calcButton->UseVisualStyleBackColor = true;
			this->calcButton->Click += gcnew System::EventHandler(this, &ModuleKnobs::calcButton_Click);
			// 
			// LED1
			// 
			this->LED1->BackColor = System::Drawing::Color::Lime;
			this->LED1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LED1->Location = System::Drawing::Point(18, 59);
			this->LED1->Name = L"LED1";
			this->LED1->Size = System::Drawing::Size(25, 25);
			this->LED1->TabIndex = 13;
			this->LED1->Text = L"1";
			this->LED1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LED1->Click += gcnew System::EventHandler(this, &ModuleKnobs::LED1_Click);
			// 
			// LED2
			// 
			this->LED2->BackColor = System::Drawing::Color::DarkGreen;
			this->LED2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LED2->Location = System::Drawing::Point(18, 98);
			this->LED2->Name = L"LED2";
			this->LED2->Size = System::Drawing::Size(25, 25);
			this->LED2->TabIndex = 14;
			this->LED2->Text = L"2";
			this->LED2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LED2->Click += gcnew System::EventHandler(this, &ModuleKnobs::LED2_Click);
			// 
			// LED4
			// 
			this->LED4->BackColor = System::Drawing::Color::DarkGreen;
			this->LED4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LED4->Location = System::Drawing::Point(49, 117);
			this->LED4->Name = L"LED4";
			this->LED4->Size = System::Drawing::Size(25, 25);
			this->LED4->TabIndex = 16;
			this->LED4->Text = L"4";
			this->LED4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LED4->Click += gcnew System::EventHandler(this, &ModuleKnobs::LED4_Click);
			// 
			// LED3
			// 
			this->LED3->BackColor = System::Drawing::Color::DarkGreen;
			this->LED3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LED3->Location = System::Drawing::Point(49, 78);
			this->LED3->Name = L"LED3";
			this->LED3->Size = System::Drawing::Size(25, 25);
			this->LED3->TabIndex = 15;
			this->LED3->Text = L"3";
			this->LED3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LED3->Click += gcnew System::EventHandler(this, &ModuleKnobs::LED3_Click);
			// 
			// LED6
			// 
			this->LED6->BackColor = System::Drawing::Color::DarkGreen;
			this->LED6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LED6->Location = System::Drawing::Point(80, 137);
			this->LED6->Name = L"LED6";
			this->LED6->Size = System::Drawing::Size(25, 25);
			this->LED6->TabIndex = 18;
			this->LED6->Text = L"6";
			this->LED6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LED6->Click += gcnew System::EventHandler(this, &ModuleKnobs::LED6_Click);
			// 
			// LED5
			// 
			this->LED5->BackColor = System::Drawing::Color::DarkGreen;
			this->LED5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LED5->Location = System::Drawing::Point(80, 98);
			this->LED5->Name = L"LED5";
			this->LED5->Size = System::Drawing::Size(25, 25);
			this->LED5->TabIndex = 17;
			this->LED5->Text = L"5";
			this->LED5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LED5->Click += gcnew System::EventHandler(this, &ModuleKnobs::LED5_Click);
			// 
			// LED8
			// 
			this->LED8->BackColor = System::Drawing::Color::DarkGreen;
			this->LED8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LED8->Location = System::Drawing::Point(121, 137);
			this->LED8->Name = L"LED8";
			this->LED8->Size = System::Drawing::Size(25, 25);
			this->LED8->TabIndex = 20;
			this->LED8->Text = L"8";
			this->LED8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LED8->Click += gcnew System::EventHandler(this, &ModuleKnobs::LED8_Click);
			// 
			// LED7
			// 
			this->LED7->BackColor = System::Drawing::Color::DarkGreen;
			this->LED7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LED7->Location = System::Drawing::Point(121, 98);
			this->LED7->Name = L"LED7";
			this->LED7->Size = System::Drawing::Size(25, 25);
			this->LED7->TabIndex = 19;
			this->LED7->Text = L"7";
			this->LED7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LED7->Click += gcnew System::EventHandler(this, &ModuleKnobs::LED7_Click);
			// 
			// LED10
			// 
			this->LED10->BackColor = System::Drawing::Color::DarkGreen;
			this->LED10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LED10->Location = System::Drawing::Point(152, 117);
			this->LED10->Name = L"LED10";
			this->LED10->Size = System::Drawing::Size(25, 25);
			this->LED10->TabIndex = 22;
			this->LED10->Text = L"10";
			this->LED10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LED10->Click += gcnew System::EventHandler(this, &ModuleKnobs::LED10_Click);
			// 
			// LED9
			// 
			this->LED9->BackColor = System::Drawing::Color::DarkGreen;
			this->LED9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LED9->Location = System::Drawing::Point(152, 78);
			this->LED9->Name = L"LED9";
			this->LED9->Size = System::Drawing::Size(25, 25);
			this->LED9->TabIndex = 21;
			this->LED9->Text = L"9";
			this->LED9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LED9->Click += gcnew System::EventHandler(this, &ModuleKnobs::LED9_Click);
			// 
			// LED12
			// 
			this->LED12->BackColor = System::Drawing::Color::DarkGreen;
			this->LED12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LED12->Location = System::Drawing::Point(183, 98);
			this->LED12->Name = L"LED12";
			this->LED12->Size = System::Drawing::Size(25, 25);
			this->LED12->TabIndex = 24;
			this->LED12->Text = L"12";
			this->LED12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LED12->Click += gcnew System::EventHandler(this, &ModuleKnobs::LED12_Click);
			// 
			// LED11
			// 
			this->LED11->BackColor = System::Drawing::Color::DarkGreen;
			this->LED11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LED11->Location = System::Drawing::Point(183, 59);
			this->LED11->Name = L"LED11";
			this->LED11->Size = System::Drawing::Size(25, 25);
			this->LED11->TabIndex = 23;
			this->LED11->Text = L"11";
			this->LED11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LED11->Click += gcnew System::EventHandler(this, &ModuleKnobs::LED11_Click);
			// 
			// outputLabel
			// 
			this->outputLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputLabel->Location = System::Drawing::Point(2, -2);
			this->outputLabel->Name = L"outputLabel";
			this->outputLabel->Size = System::Drawing::Size(226, 66);
			this->outputLabel->TabIndex = 25;
			this->outputLabel->Text = L"Input all lit LEDs, then submit";
			this->outputLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// resetButton
			// 
			this->resetButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->resetButton->Location = System::Drawing::Point(11, 211);
			this->resetButton->Margin = System::Windows::Forms::Padding(2);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(55, 21);
			this->resetButton->TabIndex = 26;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &ModuleKnobs::resetButton_Click);
			// 
			// ModuleKnobs
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(227, 241);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->LED12);
			this->Controls->Add(this->LED11);
			this->Controls->Add(this->LED10);
			this->Controls->Add(this->LED9);
			this->Controls->Add(this->LED8);
			this->Controls->Add(this->LED7);
			this->Controls->Add(this->LED6);
			this->Controls->Add(this->LED5);
			this->Controls->Add(this->LED4);
			this->Controls->Add(this->LED3);
			this->Controls->Add(this->LED2);
			this->Controls->Add(this->LED1);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->calcButton);
			this->Controls->Add(this->outputLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ModuleKnobs";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Knobs";
			this->Load += gcnew System::EventHandler(this, &ModuleKnobs::ModuleKnobs_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
private:
	void ResetForm()
	{
		for (int i = 0; i < 12; i++) // Reset array to falses
		{
			Clicked[i] = false;
		}
		LED1->BackColor = System::Drawing::Color::DarkGreen;
		LED2->BackColor = System::Drawing::Color::DarkGreen;
		LED3->BackColor = System::Drawing::Color::DarkGreen;
		LED4->BackColor = System::Drawing::Color::DarkGreen;
		LED5->BackColor = System::Drawing::Color::DarkGreen;
		LED6->BackColor = System::Drawing::Color::DarkGreen;
		LED7->BackColor = System::Drawing::Color::DarkGreen;
		LED8->BackColor = System::Drawing::Color::DarkGreen;
		LED9->BackColor = System::Drawing::Color::DarkGreen;
		LED10->BackColor = System::Drawing::Color::DarkGreen;
		LED11->BackColor = System::Drawing::Color::DarkGreen;
		LED12->BackColor = System::Drawing::Color::DarkGreen;

		outputLabel->Text = "Input all lit LEDs, then submit";
	}
	void ToggleState(System::Windows::Forms::Label^ label, int ID)
	{
		if (Clicked[ID - 1]) // On
		{
			Clicked[ID - 1] = false;
			label->BackColor = System::Drawing::Color::DarkGreen;
		}
		else // Off
		{
			Clicked[ID - 1] = true;
			label->BackColor = System::Drawing::Color::Lime;
		}
	}
private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ResetForm();
}
private: System::Void ModuleKnobs_Load(System::Object^ sender, System::EventArgs^ e) {
	ResetForm();
}
private: System::Void calcButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!Clicked[3 - 1] && Clicked[5 - 1] && Clicked[6 - 1] && !Clicked[7 - 1])
		outputLabel->Text = "Up Position";
	else if (Clicked[3 - 1] && Clicked[5 - 1] && Clicked[6 - 1] && !Clicked[7 - 1])
		outputLabel->Text = "Down Position";
	else if (!Clicked[3 - 1] && Clicked[5 - 1] && !Clicked[6 - 1] && !Clicked[7 - 1])
		outputLabel->Text = "Down Position";
	else if (!Clicked[3 - 1] && !Clicked[5 - 1] && !Clicked[6 - 1] && !Clicked[7 - 1])
		outputLabel->Text = "Left Position";
	else if (!Clicked[3 - 1] && Clicked[5 - 1] && Clicked[6 - 1] && Clicked[7 - 1])
		outputLabel->Text = "Right Position";
	else
		outputLabel->Text = "No Match Found";
}

private: System::Void LED1_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleState(LED1, 1);
}
private: System::Void LED2_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleState(LED2, 2);
}
private: System::Void LED3_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleState(LED3, 3);
}
private: System::Void LED4_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleState(LED4, 4);
}
private: System::Void LED5_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleState(LED5, 5);
}
private: System::Void LED6_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleState(LED6, 6);
}
private: System::Void LED7_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleState(LED7, 7);
}
private: System::Void LED8_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleState(LED8, 8);
}
private: System::Void LED9_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleState(LED9, 9);
}
private: System::Void LED10_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleState(LED10, 10);
}
private: System::Void LED11_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleState(LED11, 11);
}
private: System::Void LED12_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleState(LED12, 12);
}
};
}
