/**********************************************************
   file: ModuleSimonSays.h
 author: Jordan Kooyman
purpose: Contains the Simon Says module window and the calculations for translating input to output as member functions
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
	/// Summary for ModuleSimonSays
	/// </summary>
	public ref class ModuleSimonSays : public System::Windows::Forms::Form
	{
	public:
		cli::array<char, 1>^ Clicked;
		int counter = 0;
		ModuleSimonSays(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Clicked = gcnew cli::array<char, 1>(5);
			for (int i = 0; i < 5; i++) // Initialize array to falses
			{
				Clicked[i] = 0;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ModuleSimonSays()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ output1;
	private: System::Windows::Forms::Button^ buttonBlue;
	private: System::Windows::Forms::Button^ buttonRed;
	private: System::Windows::Forms::Button^ buttonYellow;
	private: System::Windows::Forms::Button^ buttonGreen;
	protected:

	protected:




	private: System::Windows::Forms::Label^ output2;
	private: System::Windows::Forms::Label^ output3;
	private: System::Windows::Forms::Label^ output4;
	private: System::Windows::Forms::Label^ output5;




	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ strikes2;
	private: System::Windows::Forms::RadioButton^ strikes1;
	private: System::Windows::Forms::RadioButton^ strikes0;
	private: System::Windows::Forms::Button^ resetButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
public: 
	void displayOutput(Button^ thisButton)
	{
		switch (counter)
		{
		case 0:
			output1->ForeColor = thisButton->ForeColor;
			output1->Text = thisButton->Text;
			output1->Visible = true;
			break;
		case 1:
			output2->ForeColor = thisButton->ForeColor;
			output2->Text = thisButton->Text;
			output2->Visible = true;
			break;
		case 2:
			output3->ForeColor = thisButton->ForeColor;
			output3->Text = thisButton->Text;
			output3->Visible = true;
			break;
		case 3:
			output4->ForeColor = thisButton->ForeColor;
			output4->Text = thisButton->Text;
			output4->Visible = true;
			break;
		case 4:
			output5->ForeColor = thisButton->ForeColor;
			output5->Text = thisButton->Text;
			output5->Visible = true;
			break;
		}
		counter++;
	}


	void Calculate()
	{
		// Ensure Serial Number Exists
		if (!CurrentSerial.serialValid())
		{
			pauseCalculation(this);
			OpenWindow(4);
			return;
		}
		bool vowel = false;
		int strikes;

		// Check Strike Count
		if (strikes0->Checked)
			strikes = 0;
		else if (strikes1->Checked)
			strikes = 1;
		else // strikes2->Checked
			strikes = 2;

		// Check Serial Number for Vowel
		for (int i = 0; i < 6; i++) // Serial Num length must be 6 (only valid input)
		{ 
			char currentLetter = CurrentSerial.serialCheck(i);
			if (currentLetter == 'A' || currentLetter == 'E' || currentLetter == 'I' || currentLetter == 'O' || currentLetter == 'U')
				vowel = true;
		}

		// Process Available Data for use in Logical Transformation
		int input = Clicked[counter];

		// Process Transformation
		if (vowel) // Vowel in Serial Number
		{
			switch (input)
			{
			case 1: // Blue
				if (strikes == 0) // No Strikes - Red
					displayOutput(buttonRed);
				else if (strikes == 1) // 1 Strike - Green
					displayOutput(buttonGreen);
				else // 2 or more Strikes - Blue
					displayOutput(buttonBlue);
				break;
			case 2: // Red
				if (strikes == 0) // No Strikes - Blue
					displayOutput(buttonBlue);
				else if (strikes == 1) // 1 Strike - Yellow
					displayOutput(buttonYellow);
				else // 2 or more Strikes - Green
					displayOutput(buttonGreen);
				break;
			case 3: // Yellow
				if (strikes == 0) // No Strikes - Green
					displayOutput(buttonGreen);
				else if (strikes == 1) // 1 Strike - Red
					displayOutput(buttonRed);
				else // 2 or more Strikes - Blue
					displayOutput(buttonBlue);
				break;
			case 4: // Green
				if (strikes == 0) // No Strikes - Yellow
					displayOutput(buttonYellow);
				else if (strikes == 1) // 1 Strike - Blue
					displayOutput(buttonBlue);
				else // 2 or more Strikes - Yellow
					displayOutput(buttonYellow);
				break;
			default:
				break;
			}
		}
		else // No vowel in serial number
		{
			switch (input)
			{
			case 1: // Blue
				if (strikes == 0) // No Strikes - Yellow
					displayOutput(buttonYellow);
				else if (strikes == 1) // 1 Strike - Blue
					displayOutput(buttonBlue);
				else // 2 or more Strikes - Green
					displayOutput(buttonGreen);
				break;
			case 2: // Red
				if (strikes == 0) // No Strikes - Blue
					displayOutput(buttonBlue);
				else if (strikes == 1) // 1 Strike - Red
					displayOutput(buttonRed);
				else // 2 or more Strikes - Yellow
					displayOutput(buttonYellow);
				break;
			case 3: // Yellow
				if (strikes == 0) // No Strikes - Red
					displayOutput(buttonRed);
				else if (strikes == 1) // 1 Strike - Green
					displayOutput(buttonGreen);
				else // 2 or more Strikes - Red
					displayOutput(buttonRed);
				break;
			case 4: // Green
				if (strikes == 0) // No Strikes - Green
					displayOutput(buttonGreen);
				else if (strikes == 1) // 1 Strike - Yellow
					displayOutput(buttonYellow);
				else // 2 or more Strikes - Blue
					displayOutput(buttonBlue);
				break;
			default:
				break;
			}
		}
	}
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModuleSimonSays::typeid));
			this->output1 = (gcnew System::Windows::Forms::Label());
			this->buttonBlue = (gcnew System::Windows::Forms::Button());
			this->buttonRed = (gcnew System::Windows::Forms::Button());
			this->buttonYellow = (gcnew System::Windows::Forms::Button());
			this->buttonGreen = (gcnew System::Windows::Forms::Button());
			this->output2 = (gcnew System::Windows::Forms::Label());
			this->output3 = (gcnew System::Windows::Forms::Label());
			this->output4 = (gcnew System::Windows::Forms::Label());
			this->output5 = (gcnew System::Windows::Forms::Label());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->strikes2 = (gcnew System::Windows::Forms::RadioButton());
			this->strikes1 = (gcnew System::Windows::Forms::RadioButton());
			this->strikes0 = (gcnew System::Windows::Forms::RadioButton());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// output1
			// 
			this->output1->AutoSize = true;
			this->output1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output1->Location = System::Drawing::Point(16, 9);
			this->output1->Name = L"output1";
			this->output1->Size = System::Drawing::Size(368, 20);
			this->output1->TabIndex = 0;
			this->output1->Text = L"Click the flashing button to see the response";
			this->output1->Visible = false;
			// 
			// buttonBlue
			// 
			this->buttonBlue->BackColor = System::Drawing::Color::MediumBlue;
			this->buttonBlue->ForeColor = System::Drawing::Color::MediumBlue;
			this->buttonBlue->Location = System::Drawing::Point(157, 34);
			this->buttonBlue->Name = L"buttonBlue";
			this->buttonBlue->Size = System::Drawing::Size(75, 74);
			this->buttonBlue->TabIndex = 1;
			this->buttonBlue->Text = L"Blue";
			this->buttonBlue->UseVisualStyleBackColor = false;
			this->buttonBlue->Click += gcnew System::EventHandler(this, &ModuleSimonSays::buttonBlue_Click);
			// 
			// buttonRed
			// 
			this->buttonRed->BackColor = System::Drawing::Color::Firebrick;
			this->buttonRed->ForeColor = System::Drawing::Color::Firebrick;
			this->buttonRed->Location = System::Drawing::Point(80, 108);
			this->buttonRed->Name = L"buttonRed";
			this->buttonRed->Size = System::Drawing::Size(75, 74);
			this->buttonRed->TabIndex = 2;
			this->buttonRed->Text = L"Red";
			this->buttonRed->UseVisualStyleBackColor = false;
			this->buttonRed->Click += gcnew System::EventHandler(this, &ModuleSimonSays::buttonRed_Click);
			// 
			// buttonYellow
			// 
			this->buttonYellow->BackColor = System::Drawing::Color::Goldenrod;
			this->buttonYellow->ForeColor = System::Drawing::Color::Goldenrod;
			this->buttonYellow->Location = System::Drawing::Point(234, 108);
			this->buttonYellow->Name = L"buttonYellow";
			this->buttonYellow->Size = System::Drawing::Size(75, 74);
			this->buttonYellow->TabIndex = 3;
			this->buttonYellow->Text = L"Yellow";
			this->buttonYellow->UseVisualStyleBackColor = false;
			this->buttonYellow->Click += gcnew System::EventHandler(this, &ModuleSimonSays::buttonYellow_Click);
			// 
			// buttonGreen
			// 
			this->buttonGreen->BackColor = System::Drawing::Color::Green;
			this->buttonGreen->ForeColor = System::Drawing::Color::Green;
			this->buttonGreen->Location = System::Drawing::Point(157, 182);
			this->buttonGreen->Name = L"buttonGreen";
			this->buttonGreen->Size = System::Drawing::Size(75, 74);
			this->buttonGreen->TabIndex = 4;
			this->buttonGreen->Text = L"Green";
			this->buttonGreen->UseVisualStyleBackColor = false;
			this->buttonGreen->Click += gcnew System::EventHandler(this, &ModuleSimonSays::buttonGreen_Click);
			// 
			// output2
			// 
			this->output2->AutoSize = true;
			this->output2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output2->Location = System::Drawing::Point(90, 9);
			this->output2->Name = L"output2";
			this->output2->Size = System::Drawing::Size(61, 20);
			this->output2->TabIndex = 5;
			this->output2->Text = L"Yellow";
			this->output2->Visible = false;
			// 
			// output3
			// 
			this->output3->AutoSize = true;
			this->output3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output3->Location = System::Drawing::Point(164, 9);
			this->output3->Name = L"output3";
			this->output3->Size = System::Drawing::Size(61, 20);
			this->output3->TabIndex = 6;
			this->output3->Text = L"Yellow";
			this->output3->Visible = false;
			// 
			// output4
			// 
			this->output4->AutoSize = true;
			this->output4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output4->Location = System::Drawing::Point(238, 9);
			this->output4->Name = L"output4";
			this->output4->Size = System::Drawing::Size(61, 20);
			this->output4->TabIndex = 7;
			this->output4->Text = L"Yellow";
			this->output4->Visible = false;
			// 
			// output5
			// 
			this->output5->AutoSize = true;
			this->output5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output5->Location = System::Drawing::Point(312, 9);
			this->output5->Name = L"output5";
			this->output5->Size = System::Drawing::Size(61, 20);
			this->output5->TabIndex = 8;
			this->output5->Text = L"Yellow";
			this->output5->Visible = false;
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(322, 258);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 11;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ModuleSimonSays::exitButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->strikes2);
			this->groupBox1->Controls->Add(this->strikes1);
			this->groupBox1->Controls->Add(this->strikes0);
			this->groupBox1->Location = System::Drawing::Point(12, 35);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(62, 93);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Strikes";
			// 
			// strikes2
			// 
			this->strikes2->AutoSize = true;
			this->strikes2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->strikes2->Location = System::Drawing::Point(7, 68);
			this->strikes2->Name = L"strikes2";
			this->strikes2->Size = System::Drawing::Size(37, 18);
			this->strikes2->TabIndex = 2;
			this->strikes2->Text = L"2";
			this->strikes2->UseVisualStyleBackColor = true;
			this->strikes2->CheckedChanged += gcnew System::EventHandler(this, &ModuleSimonSays::strikes2_CheckedChanged);
			// 
			// strikes1
			// 
			this->strikes1->AutoSize = true;
			this->strikes1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->strikes1->Location = System::Drawing::Point(7, 44);
			this->strikes1->Name = L"strikes1";
			this->strikes1->Size = System::Drawing::Size(37, 18);
			this->strikes1->TabIndex = 1;
			this->strikes1->Text = L"1";
			this->strikes1->UseVisualStyleBackColor = true;
			this->strikes1->CheckedChanged += gcnew System::EventHandler(this, &ModuleSimonSays::strikes1_CheckedChanged);
			// 
			// strikes0
			// 
			this->strikes0->AutoSize = true;
			this->strikes0->Checked = true;
			this->strikes0->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->strikes0->Location = System::Drawing::Point(7, 20);
			this->strikes0->Name = L"strikes0";
			this->strikes0->Size = System::Drawing::Size(37, 18);
			this->strikes0->TabIndex = 0;
			this->strikes0->TabStop = true;
			this->strikes0->Text = L"0";
			this->strikes0->UseVisualStyleBackColor = true;
			this->strikes0->CheckedChanged += gcnew System::EventHandler(this, &ModuleSimonSays::strikes0_CheckedChanged);
			// 
			// resetButton
			// 
			this->resetButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->resetButton->Location = System::Drawing::Point(11, 258);
			this->resetButton->Margin = System::Windows::Forms::Padding(2);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(55, 21);
			this->resetButton->TabIndex = 13;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &ModuleSimonSays::resetButton_Click);
			// 
			// ModuleSimonSays
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(388, 290);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->output5);
			this->Controls->Add(this->output4);
			this->Controls->Add(this->output3);
			this->Controls->Add(this->output2);
			this->Controls->Add(this->buttonGreen);
			this->Controls->Add(this->buttonYellow);
			this->Controls->Add(this->buttonRed);
			this->Controls->Add(this->buttonBlue);
			this->Controls->Add(this->output1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ModuleSimonSays";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Simon Says";
			this->Load += gcnew System::EventHandler(this, &ModuleSimonSays::ModuleSimonSays_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	output1->Text = "Click the flashing button to see the response";
	output1->ForeColor = System::Drawing::Color::Black;
	strikes0->Checked = true;
	strikes1->Checked = false;
	strikes2->Checked = false;

	counter = 0;
	output1->Visible = true;
	output2->Visible = false;
	output3->Visible = false;
	output4->Visible = false;
	output5->Visible = false;

	for (int i = 0; i < 5; i++) // Loop through Clicked input array, resetting all values
	{
		Clicked[i] = 0;
	}
}
private: System::Void buttonBlue_Click(System::Object^ sender, System::EventArgs^ e) {
	if (counter < 5)
	{
		Clicked[counter] = 1;
		Calculate();
	}
}
private: System::Void buttonYellow_Click(System::Object^ sender, System::EventArgs^ e) {
	if (counter < 5)
	{
		Clicked[counter] = 3;
		Calculate();
	}
}
private: System::Void buttonGreen_Click(System::Object^ sender, System::EventArgs^ e) {
	if (counter < 5)
	{
		Clicked[counter] = 4;
		Calculate();
	}
}
private: System::Void buttonRed_Click(System::Object^ sender, System::EventArgs^ e) {
	if (counter < 5)
	{
		Clicked[counter] = 2;
		Calculate();
	}
}
private: System::Void strikes0_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	// When Strikes Change, reset all prior information (it is now invalid) and reoutput it with new state
	output1->Visible = false;
	output2->Visible = false;
	output3->Visible = false;
	output4->Visible = false;
	output5->Visible = false;

	int temp_Count = counter;
	for (int i = 0; i < temp_Count; i++)
	{
		counter = i;
		//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(counter), "Debug 0");
		Calculate();
	}
}
private: System::Void strikes1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void strikes2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	// When Strikes Change, reset all prior information (it is now invalid) and reoutput it with new state
	output1->Visible = false;
	output2->Visible = false;
	output3->Visible = false;
	output4->Visible = false;
	output5->Visible = false;

	int temp_Count = counter;
	for (int i = 0; i < temp_Count; i++)
	{
		counter = i;
		//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(counter), "Debug 2");
		Calculate();
	}
}
private: System::Void ModuleSimonSays_Load(System::Object^ sender, System::EventArgs^ e) {
	output1->Text = "Click the flashing button to see the response";
	output1->Visible = true;
}
};
}
