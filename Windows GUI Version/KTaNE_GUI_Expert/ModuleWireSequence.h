/**********************************************************
   file: ModuleWireSequence.h
 author: Jordan Kooyman
purpose: Contains the Wire Sequence module window and the calculations for displaying the correct results as member functions
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
	/// Summary for ModuleWireSequence
	/// </summary>
	public ref class ModuleWireSequence : public System::Windows::Forms::Form
	{
	public:
		ModuleWireSequence(void)
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
		~ModuleWireSequence()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ exitButton;
	protected:

	private: System::Windows::Forms::Button^ buttonBlack;
	private: System::Windows::Forms::Button^ buttonBlue;
	private: System::Windows::Forms::Button^ buttonRed;
	private: System::Windows::Forms::Label^ outputLabel;
	private: System::Windows::Forms::Button^ resetButton;
	private: System::Windows::Forms::Label^ promptLabel;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModuleWireSequence::typeid));
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->buttonBlack = (gcnew System::Windows::Forms::Button());
			this->buttonBlue = (gcnew System::Windows::Forms::Button());
			this->buttonRed = (gcnew System::Windows::Forms::Button());
			this->outputLabel = (gcnew System::Windows::Forms::Label());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->promptLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(262, 159);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 4;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ModuleWireSequence::exitButton_Click);
			// 
			// buttonBlack
			// 
			this->buttonBlack->BackColor = System::Drawing::Color::Black;
			this->buttonBlack->Location = System::Drawing::Point(209, 74);
			this->buttonBlack->Name = L"buttonBlack";
			this->buttonBlack->Size = System::Drawing::Size(75, 66);
			this->buttonBlack->TabIndex = 2;
			this->buttonBlack->UseVisualStyleBackColor = false;
			this->buttonBlack->Click += gcnew System::EventHandler(this, &ModuleWireSequence::buttonBlack_Click);
			// 
			// buttonBlue
			// 
			this->buttonBlue->BackColor = System::Drawing::Color::Blue;
			this->buttonBlue->Location = System::Drawing::Point(126, 74);
			this->buttonBlue->Name = L"buttonBlue";
			this->buttonBlue->Size = System::Drawing::Size(75, 66);
			this->buttonBlue->TabIndex = 1;
			this->buttonBlue->UseVisualStyleBackColor = false;
			this->buttonBlue->Click += gcnew System::EventHandler(this, &ModuleWireSequence::buttonBlue_Click);
			// 
			// buttonRed
			// 
			this->buttonRed->BackColor = System::Drawing::Color::Red;
			this->buttonRed->Location = System::Drawing::Point(43, 74);
			this->buttonRed->Name = L"buttonRed";
			this->buttonRed->Size = System::Drawing::Size(75, 66);
			this->buttonRed->TabIndex = 0;
			this->buttonRed->UseVisualStyleBackColor = false;
			this->buttonRed->Click += gcnew System::EventHandler(this, &ModuleWireSequence::buttonRed_Click);
			// 
			// outputLabel
			// 
			this->outputLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputLabel->Location = System::Drawing::Point(0, 3);
			this->outputLabel->Name = L"outputLabel";
			this->outputLabel->Size = System::Drawing::Size(326, 59);
			this->outputLabel->TabIndex = 16;
			this->outputLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// resetButton
			// 
			this->resetButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->resetButton->Location = System::Drawing::Point(10, 159);
			this->resetButton->Margin = System::Windows::Forms::Padding(2);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(55, 21);
			this->resetButton->TabIndex = 3;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &ModuleWireSequence::resetButton_Click);
			// 
			// promptLabel
			// 
			this->promptLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->promptLabel->Location = System::Drawing::Point(7, 3);
			this->promptLabel->Name = L"promptLabel";
			this->promptLabel->Size = System::Drawing::Size(310, 68);
			this->promptLabel->TabIndex = 17;
			this->promptLabel->Text = L"Click the button corresponding to the color of wire on the bomb to see when to cu"
				L"t it";
			this->promptLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ModuleWireSequence
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(327, 189);
			this->Controls->Add(this->promptLabel);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->outputLabel);
			this->Controls->Add(this->buttonRed);
			this->Controls->Add(this->buttonBlue);
			this->Controls->Add(this->buttonBlack);
			this->Controls->Add(this->exitButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ModuleWireSequence";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Wire Sequence";
			this->ResumeLayout(false);

		}
#pragma endregion
private:
	int redCounter = 0;
	int blueCounter = 0;
	int blackCounter = 0;
	void displayOutput(int ref[9], System::Windows::Forms::Button^ buttonColor, int count)
	{
		promptLabel->Visible = false;
		if (count > 8)
		{
			System::Windows::Forms::MessageBox::Show("Maximum Count Reached", "Error");
			return;
		}
		System::String^ output;

		switch (ref[count])
		{ // 1: A | 2: B | 3: C | 4: A B | 5: A C | 6: B C | 7: A B C
		case 1:
		{
			output = L"A";
			break;
		}
		case 2:
		{
			output = L"B";
			break;
		}
		case 3:
		{
			output = L"C";
			break;
		}
		case 4:
		{
			output = L"A or B";
			break;
		}
		case 5:
		{
			output = L"A or C";
			break;
		}
		case 6:
		{
			output = L"B or C";
			break;
		}
		case 7:
		{
			output = L"A, B, or C";
			break;
		}
		default:
			break;
		}

		outputLabel->Text = output;
		outputLabel->ForeColor = buttonColor->BackColor;
	}
	
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

private: System::Void buttonRed_Click(System::Object^ sender, System::EventArgs^ e) {
	int reference[9] = { 3,2,1,5,2,5,7,4,2 }; // Red
	if (redCounter > 8)
	{
		System::Windows::Forms::MessageBox::Show("Maximum Red Count Reached", "Error");
		return;
	}
	else
	{
		displayOutput(reference, buttonRed, redCounter);
		redCounter++;
	}
}
private: System::Void buttonBlue_Click(System::Object^ sender, System::EventArgs^ e) {
	int reference[9] = { 2,5,2,1,2,6,3,5,1 }; // Blue
	if (blueCounter > 8)
	{
		System::Windows::Forms::MessageBox::Show("Maximum Blue Count Reached", "Error");
		return;
	}
	else
	{
		displayOutput(reference, buttonBlue, blueCounter);
		blueCounter++;
	}
}
private: System::Void buttonBlack_Click(System::Object^ sender, System::EventArgs^ e) {
	int reference[9] = { 7,5,2,5,2,6,4,3,3 }; // Black
	if (blackCounter > 8)
	{
		System::Windows::Forms::MessageBox::Show("Maximum Black Count Reached", "Error");
		return;
	}
	else
	{
		// Special case to signify button clicked on last black option if 2 black in a row
		if (blackCounter == 8 && outputLabel->ForeColor == buttonBlack->BackColor) 
			outputLabel->Text = "C, Again";
		else // Otherwise, standard procedure
			displayOutput(reference, buttonBlack, blackCounter);
		
		blackCounter++;
	}
}
private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	redCounter = 0;
	blueCounter = 0;
	blackCounter = 0;
	outputLabel->Text = "";
	promptLabel->Visible = true;
}
};
}
