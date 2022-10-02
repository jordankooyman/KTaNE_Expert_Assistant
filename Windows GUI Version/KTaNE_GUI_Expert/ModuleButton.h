/**********************************************************
   file: ModuleButton.h
 author: Jordan Kooyman
purpose: Contains The Button module window and the calculations for the button as a member function
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
	/// Summary for ModuleButton
	/// </summary>
	public ref class ModuleButton : public System::Windows::Forms::Form
	{
	public:
		ModuleButton(void)
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
		~ModuleButton()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ colorContainer;
	private: System::Windows::Forms::RadioButton^ colorRed;
	protected:

	private: System::Windows::Forms::RadioButton^ colorBlue;
	private: System::Windows::Forms::RadioButton^ colorBlack;


	private: System::Windows::Forms::RadioButton^ colorYellow;

	private: System::Windows::Forms::RadioButton^ colorWhite;

	private: System::Windows::Forms::GroupBox^ textContainer;
	private: System::Windows::Forms::RadioButton^ textPress;

	private: System::Windows::Forms::RadioButton^ textHold;

	private: System::Windows::Forms::RadioButton^ textDetonate;

	private: System::Windows::Forms::RadioButton^ textAbort;

	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::Button^ calcButton;

	public: 
		/**
		* Check that all required Bomb Constants have been input, then read in the input data from the GUI and provide the resulting solution to button module
		* @param None
		* @return None
		*/
		void Calculate()
	{
		if (!CurrentBatteries.batteriesValid())
		{
			pauseCalculation(this);
			OpenWindow(3);
		}
		else if (!CurrentIndicators.indicatorValid())
		{
			pauseCalculation(this);
			OpenWindow(1);
		}
		else
		{
			int hold = 0; // 0: Uninitialized, 1: Click, 2: Hold

			if (colorRed->Checked && textHold->Checked) hold = 1;
			else if (CurrentBatteries.batteriesCheck(2) >= 2 && textDetonate->Checked) hold = 1;
			else if (colorBlue->Checked && textAbort->Checked) hold = 2;
			else if (colorWhite->Checked && CurrentIndicators.indicatorCheck("CAR") == 2) hold = 2; // and lit indicator CAR
			else if (CurrentBatteries.batteriesCheck(2) >= 3 && CurrentIndicators.indicatorCheck("FRK") == 2) hold = 1; // and lit indicator FRK
			else hold = 2;

			KTaNEGUIExpert::ButtonOutput^ Output = gcnew KTaNEGUIExpert::ButtonOutput;
			switch (hold)
			{
			case 1: // click
				Output->Show();
				Output->State(1);
				break;
			case 2: // hold
				Output->Show();
				Output->State(2);
				break;
			}
		}
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModuleButton::typeid));
			this->colorContainer = (gcnew System::Windows::Forms::GroupBox());
			this->colorBlack = (gcnew System::Windows::Forms::RadioButton());
			this->colorYellow = (gcnew System::Windows::Forms::RadioButton());
			this->colorWhite = (gcnew System::Windows::Forms::RadioButton());
			this->colorRed = (gcnew System::Windows::Forms::RadioButton());
			this->colorBlue = (gcnew System::Windows::Forms::RadioButton());
			this->textContainer = (gcnew System::Windows::Forms::GroupBox());
			this->textPress = (gcnew System::Windows::Forms::RadioButton());
			this->textHold = (gcnew System::Windows::Forms::RadioButton());
			this->textDetonate = (gcnew System::Windows::Forms::RadioButton());
			this->textAbort = (gcnew System::Windows::Forms::RadioButton());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->calcButton = (gcnew System::Windows::Forms::Button());
			this->colorContainer->SuspendLayout();
			this->textContainer->SuspendLayout();
			this->SuspendLayout();
			// 
			// colorContainer
			// 
			this->colorContainer->Controls->Add(this->colorBlack);
			this->colorContainer->Controls->Add(this->colorYellow);
			this->colorContainer->Controls->Add(this->colorWhite);
			this->colorContainer->Controls->Add(this->colorRed);
			this->colorContainer->Controls->Add(this->colorBlue);
			this->colorContainer->Location = System::Drawing::Point(20, 11);
			this->colorContainer->Name = L"colorContainer";
			this->colorContainer->Size = System::Drawing::Size(88, 145);
			this->colorContainer->TabIndex = 0;
			this->colorContainer->TabStop = false;
			this->colorContainer->Text = L"Button Color";
			// 
			// colorBlack
			// 
			this->colorBlack->AutoSize = true;
			this->colorBlack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->colorBlack->Location = System::Drawing::Point(16, 119);
			this->colorBlack->Name = L"colorBlack";
			this->colorBlack->Size = System::Drawing::Size(57, 17);
			this->colorBlack->TabIndex = 4;
			this->colorBlack->Text = L"Black";
			this->colorBlack->UseVisualStyleBackColor = true;
			// 
			// colorYellow
			// 
			this->colorYellow->AutoSize = true;
			this->colorYellow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->colorYellow->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->colorYellow->Location = System::Drawing::Point(16, 96);
			this->colorYellow->Name = L"colorYellow";
			this->colorYellow->Size = System::Drawing::Size(62, 17);
			this->colorYellow->TabIndex = 3;
			this->colorYellow->Text = L"Yellow";
			this->colorYellow->UseVisualStyleBackColor = true;
			// 
			// colorWhite
			// 
			this->colorWhite->AutoSize = true;
			this->colorWhite->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->colorWhite->ForeColor = System::Drawing::SystemColors::GrayText;
			this->colorWhite->Location = System::Drawing::Point(16, 73);
			this->colorWhite->Name = L"colorWhite";
			this->colorWhite->Size = System::Drawing::Size(58, 17);
			this->colorWhite->TabIndex = 2;
			this->colorWhite->Text = L"White";
			this->colorWhite->UseVisualStyleBackColor = true;
			// 
			// colorRed
			// 
			this->colorRed->AutoSize = true;
			this->colorRed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->colorRed->ForeColor = System::Drawing::Color::Red;
			this->colorRed->Location = System::Drawing::Point(16, 50);
			this->colorRed->Name = L"colorRed";
			this->colorRed->Size = System::Drawing::Size(48, 17);
			this->colorRed->TabIndex = 1;
			this->colorRed->Text = L"Red";
			this->colorRed->UseVisualStyleBackColor = true;
			// 
			// colorBlue
			// 
			this->colorBlue->AutoSize = true;
			this->colorBlue->Checked = true;
			this->colorBlue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->colorBlue->ForeColor = System::Drawing::Color::Blue;
			this->colorBlue->Location = System::Drawing::Point(16, 27);
			this->colorBlue->Name = L"colorBlue";
			this->colorBlue->Size = System::Drawing::Size(50, 17);
			this->colorBlue->TabIndex = 0;
			this->colorBlue->TabStop = true;
			this->colorBlue->Text = L"Blue";
			this->colorBlue->UseVisualStyleBackColor = true;
			// 
			// textContainer
			// 
			this->textContainer->Controls->Add(this->textPress);
			this->textContainer->Controls->Add(this->textHold);
			this->textContainer->Controls->Add(this->textDetonate);
			this->textContainer->Controls->Add(this->textAbort);
			this->textContainer->Location = System::Drawing::Point(144, 11);
			this->textContainer->Name = L"textContainer";
			this->textContainer->Size = System::Drawing::Size(85, 145);
			this->textContainer->TabIndex = 1;
			this->textContainer->TabStop = false;
			this->textContainer->Text = L"Button Text";
			// 
			// textPress
			// 
			this->textPress->AutoSize = true;
			this->textPress->Location = System::Drawing::Point(7, 119);
			this->textPress->Name = L"textPress";
			this->textPress->Size = System::Drawing::Size(51, 17);
			this->textPress->TabIndex = 8;
			this->textPress->TabStop = true;
			this->textPress->Text = L"Press";
			this->textPress->UseVisualStyleBackColor = true;
			// 
			// textHold
			// 
			this->textHold->AutoSize = true;
			this->textHold->Location = System::Drawing::Point(7, 86);
			this->textHold->Name = L"textHold";
			this->textHold->Size = System::Drawing::Size(47, 17);
			this->textHold->TabIndex = 7;
			this->textHold->TabStop = true;
			this->textHold->Text = L"Hold";
			this->textHold->UseVisualStyleBackColor = true;
			// 
			// textDetonate
			// 
			this->textDetonate->AutoSize = true;
			this->textDetonate->Location = System::Drawing::Point(7, 53);
			this->textDetonate->Name = L"textDetonate";
			this->textDetonate->Size = System::Drawing::Size(69, 17);
			this->textDetonate->TabIndex = 3;
			this->textDetonate->TabStop = true;
			this->textDetonate->Text = L"Detonate";
			this->textDetonate->UseVisualStyleBackColor = true;
			// 
			// textAbort
			// 
			this->textAbort->AutoSize = true;
			this->textAbort->Checked = true;
			this->textAbort->Location = System::Drawing::Point(7, 20);
			this->textAbort->Name = L"textAbort";
			this->textAbort->Size = System::Drawing::Size(50, 17);
			this->textAbort->TabIndex = 5;
			this->textAbort->TabStop = true;
			this->textAbort->Text = L"Abort";
			this->textAbort->UseVisualStyleBackColor = true;
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(186, 183);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 10;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ModuleButton::exitButton_Click);
			// 
			// calcButton
			// 
			this->calcButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->calcButton->Location = System::Drawing::Point(90, 161);
			this->calcButton->Margin = System::Windows::Forms::Padding(2);
			this->calcButton->Name = L"calcButton";
			this->calcButton->Size = System::Drawing::Size(68, 25);
			this->calcButton->TabIndex = 9;
			this->calcButton->Text = L"Calculate";
			this->calcButton->UseVisualStyleBackColor = true;
			this->calcButton->Click += gcnew System::EventHandler(this, &ModuleButton::calcButton_Click);
			// 
			// ModuleButton
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(248, 211);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->calcButton);
			this->Controls->Add(this->textContainer);
			this->Controls->Add(this->colorContainer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ModuleButton";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Button";
			this->Shown += gcnew System::EventHandler(this, &ModuleButton::ModuleButton_Shown);
			this->colorContainer->ResumeLayout(false);
			this->colorContainer->PerformLayout();
			this->textContainer->ResumeLayout(false);
			this->textContainer->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

private: System::Void ModuleButton_Shown(System::Object^ sender, System::EventArgs^ e)
{
	colorBlue->Checked = false;
	textAbort->Checked = false;
}

private: System::Void calcButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if ((colorBlue->Checked || colorRed->Checked || colorWhite->Checked || colorYellow->Checked || colorBlack->Checked) && (textAbort->Checked || textDetonate->Checked || textHold->Checked || textPress->Checked))
		Calculate();
	else
		System::Windows::Forms::MessageBox::Show("A Color option and Text option must be selected", "Error");
}
};
}
