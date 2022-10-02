/**********************************************************
   file: ModuleWhosOnFirst.h
 author: Jordan Kooyman
purpose: Contains the Who's On First module window and the checks for both stages to determine position or list to read as member functions
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
	/// Summary for ModuleWhosOnFirst
	/// </summary>
	public ref class ModuleWhosOnFirst : public System::Windows::Forms::Form
	{
	public:
		ModuleWhosOnFirst(void)
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
		~ModuleWhosOnFirst()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ exitButton;
	protected:
	private: System::Windows::Forms::Button^ calcButton;
	private: System::Windows::Forms::Label^ displayPrompt;
	private: System::Windows::Forms::Label^ labelLocationPrompt;
	private: System::Windows::Forms::MaskedTextBox^ displayInput;
	private: System::Windows::Forms::MaskedTextBox^ labelInput;
	private: System::Windows::Forms::Label^ resultList;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModuleWhosOnFirst::typeid));
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->calcButton = (gcnew System::Windows::Forms::Button());
			this->displayPrompt = (gcnew System::Windows::Forms::Label());
			this->labelLocationPrompt = (gcnew System::Windows::Forms::Label());
			this->displayInput = (gcnew System::Windows::Forms::MaskedTextBox());
			this->labelInput = (gcnew System::Windows::Forms::MaskedTextBox());
			this->resultList = (gcnew System::Windows::Forms::Label());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(241, 193);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 4;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ModuleWhosOnFirst::exitButton_Click);
			// 
			// calcButton
			// 
			this->calcButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->calcButton->Location = System::Drawing::Point(119, 77);
			this->calcButton->Margin = System::Windows::Forms::Padding(2);
			this->calcButton->Name = L"calcButton";
			this->calcButton->Size = System::Drawing::Size(68, 25);
			this->calcButton->TabIndex = 1;
			this->calcButton->Text = L"Submit";
			this->calcButton->UseVisualStyleBackColor = true;
			this->calcButton->Click += gcnew System::EventHandler(this, &ModuleWhosOnFirst::calcButton_Click);
			// 
			// displayPrompt
			// 
			this->displayPrompt->AutoSize = true;
			this->displayPrompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->displayPrompt->Location = System::Drawing::Point(82, 16);
			this->displayPrompt->Name = L"displayPrompt";
			this->displayPrompt->Size = System::Drawing::Size(77, 24);
			this->displayPrompt->TabIndex = 16;
			this->displayPrompt->Text = L"Display";
			// 
			// labelLocationPrompt
			// 
			this->labelLocationPrompt->AutoSize = true;
			this->labelLocationPrompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelLocationPrompt->Location = System::Drawing::Point(12, 48);
			this->labelLocationPrompt->Name = L"labelLocationPrompt";
			this->labelLocationPrompt->Size = System::Drawing::Size(220, 24);
			this->labelLocationPrompt->TabIndex = 17;
			this->labelLocationPrompt->Text = L"Label on Middle Right:";
			this->labelLocationPrompt->Visible = false;
			// 
			// displayInput
			// 
			this->displayInput->HidePromptOnLeave = true;
			this->displayInput->Location = System::Drawing::Point(164, 18);
			this->displayInput->Mask = L">\?\?\?CC\?\?\?";
			this->displayInput->Name = L"displayInput";
			this->displayInput->Size = System::Drawing::Size(61, 20);
			this->displayInput->TabIndex = 0;
			// 
			// labelInput
			// 
			this->labelInput->HidePromptOnLeave = true;
			this->labelInput->Location = System::Drawing::Point(239, 50);
			this->labelInput->Mask = L">L\?\?CC\?\?";
			this->labelInput->Name = L"labelInput";
			this->labelInput->Size = System::Drawing::Size(56, 20);
			this->labelInput->TabIndex = 2;
			this->labelInput->Visible = false;
			// 
			// resultList
			// 
			this->resultList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultList->Location = System::Drawing::Point(5, 111);
			this->resultList->Name = L"resultList";
			this->resultList->Size = System::Drawing::Size(296, 76);
			this->resultList->TabIndex = 21;
			this->resultList->Text = L"Result List";
			this->resultList->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// resetButton
			// 
			this->resetButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->resetButton->Location = System::Drawing::Point(10, 193);
			this->resetButton->Margin = System::Windows::Forms::Padding(2);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(55, 21);
			this->resetButton->TabIndex = 3;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &ModuleWhosOnFirst::resetButton_Click);
			// 
			// ModuleWhosOnFirst
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(306, 220);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->resultList);
			this->Controls->Add(this->labelInput);
			this->Controls->Add(this->displayInput);
			this->Controls->Add(this->labelLocationPrompt);
			this->Controls->Add(this->displayPrompt);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->calcButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ModuleWhosOnFirst";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Who\'s On First";
			this->Load += gcnew System::EventHandler(this, &ModuleWhosOnFirst::ModuleWhosOnFirst_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	int stage = 0;
private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	displayInput->Text = "";
	labelInput->Text = "";
	resultList->Text = "";
	displayInput->Enabled = true;
	labelInput->Visible = false;
	labelLocationPrompt->Visible = false;
	stage = 0;
}
private: System::Void ModuleWhosOnFirst_Load(System::Object^ sender, System::EventArgs^ e) {
	displayInput->Text = "";
	labelInput->Text = "";
	resultList->Text = "";
	displayInput->Enabled = true;
	labelInput->Visible = false;
	labelLocationPrompt->Visible = false;
}
private: System::Void calcButton_Click(System::Object^ sender, System::EventArgs^ e) {
	cli::array<String^>^ answers_p1 = gcnew cli::array<String^>(28) { "YES", "FIRST", "DISPLAY", "OKAY", "SAYS", "NOTHING", "", "BLANK", "NO", "LED", "LEAD", "READ", "RED", "REED", "LEED", "HOLD ON", "YOU", "YOU ARE", "YOUR", "YOU'RE", "UR", "THERE", "THEY'RE", "THEIR", "THEY ARE", "SEE", "C", "CEE" };
	int position_p1[28] = { 3,2,6,2,6,3,5,4,6,3,6,4,4,5,5,6,4,6,4,4,1,6,5,4,3,6,2,6 }; // 1: Top Left | 2: Top Right | 3: Middle Left | 4: Middle Right | 5: Bottom Left | 6: Bottom Right
	cli::array<String^>^ answers_p2 = gcnew cli::array<String^>(28) { "READY", "FIRST", "NO", "BLANK", "NOTHING", "YES", "WHAT", "UHHH", "LEFT", "RIGHT", "MIDDLE", "OKAY", "WAIT", "PRESS", "YOU", "YOU ARE", "YOUR", "YOU'RE", "UR", "U", "UH HUH", "UH UH", "WHAT?", "DONE", "NEXT", "HOLD", "SURE", "LIKE" };
	cli::array<String^>^ result_p2 = gcnew cli::array<String^>(28) { "YES, OKAY, WHAT, MIDDLE, LEFT, PRESS, RIGHT, BLANK, READY", "LEFT, OKAY, YES, MIDDLE, NO, RIGHT, NOTHING, UHHH, WAIT, READY, BLANK, WHAT, PRESS, FIRST", "BLANK, UHHH, WAIT, FIRST, WHAT, READY, RIGHT, YES, NOTHING, LEFT, PRESS, OKAY, NO", "WAIT, RIGHT, OKAY, MIDDLE, BLANK", "UHHH, RIGHT, OKAY, MIDDLE, YES, BLANK, NO, PRESS, LEFT, WHAT, WAIT, FIRST, NOTHING", "OKAY, RIGHT, UHHH, MIDDLE, FIRST, WHAT, PRESS, READY, NOTHING, YES", "UHHH, WHAT", "READY, NOTHING, LEFT, WHAT, OKAY, YES, RIGHT, NO, PRESS, BLANK, UHHH", "RIGHT, LEFT", "YES, NOTHING, READY, PRESS, NO, WAIT, WHAT, RIGHT", "BLANK, READY, OKAY, WHAT, NOTHING, PRESS, NO, WAIT, LEFT, MIDDLE", "MIDDLE, NO, FIRST, YES, UHHH, NOTHING, WAIT, OKAY", "UHHH, NO, BLANK, OKAY, YES, LEFT, FIRST, PRESS, WHAT, WAIT", "RIGHT, MIDDLE, YES, READY, PRESS", "SURE, YOU ARE, YOUR, YOU'RE, NEXT, UH HUH, UR, HOLD, WHAT?, YOU", "YOUR, NEXT, LIKE, UH HUH, WHAT?, DONE, UH UH, HOLD, YOU, U, YOU'RE, SURE, UR, YOU ARE", "UH UH, YOU ARE, UH HUH, YOUR", "YOU, YOU'RE", "DONE, U, UR", "UH HUH, SURE, NEXT, WHAT?, YOU'RE, UR, UH UH, DONE, U", "UH HUH", "UR, U, YOU ARE, YOU'RE, NEXT, UH UH", "YOU, HOLD, YOU'RE, YOUR, U, DONE, UH UH, LIKE, YOU ARE, UH HUH, UR, NEXT, WHAT?", "SURE, UH HUH, NEXT, WHAT?, YOUR, UR, YOU'RE, HOLD, LIKE, YOU, U, YOU ARE, UH UH, DONE", "WHAT?, UH HUH, UH UH, YOUR, HOLD, SURE, NEXT", "YOU ARE, U, DONE, UH UH, YOU, UR, SURE, WHAT?, YOU'RE, NEXT, HOLD", "YOU ARE, DONE, LIKE, YOU'RE, YOU, HOLD, UH HUH, UR, SURE", "YOU'RE, NEXT, U, UR, HOLD, DONE, UH UH, WHAT?, UH HUH, YOU, LIKE" };
	int match = -1;
	int i = 0;

	if (stage == 0)
	{
		//System::Windows::Forms::MessageBox::Show("Stage 0", "Debug");
		while (i < 28 && match == -1)
		{
			if (answers_p1[i] == displayInput->Text)
			{
				match = position_p1[i];
			}
			i++;
		}
		if (match != -1)
		{
			// 1: Top Left | 2: Top Right | 3: Middle Left | 4: Middle Right | 5: Bottom Left | 6: Bottom Right
			switch (match)
			{// The 6 positions to read the label from, then another text input before a long string output
			case 1: // Top Left
				labelLocationPrompt->Text = "Label on Top Left:";
				break;
			case 2: // Top Right
				labelLocationPrompt->Text = "Label on Top Right:";
				break;
			case 3: // Middle Left
				labelLocationPrompt->Text = "Label on Middle Left:";
				break;
			case 4: // Middle Right
				labelLocationPrompt->Text = "Label on Middle Right:";
				break;
			case 5: // Bottom Left
				labelLocationPrompt->Text = "Label on Bottom Left:";
				break;
			case 6: // Bottom Right
				labelLocationPrompt->Text = "Label on Bottom Right:";
				break;
			}
			stage = 1;
			displayInput->Enabled = false;
			labelInput->Visible = true;
			labelLocationPrompt->Visible = true;
		}
		else
		{
			System::Windows::Forms::MessageBox::Show("No match found for Input", "Error");
		}
	}
	else // stage 1
	{
		//System::Windows::Forms::MessageBox::Show("Stage 1", "Debug");
		while (i < 28 && match == -1)
		{
			if (answers_p2[i] == labelInput->Text)
			{
				//System::Windows::Forms::MessageBox::Show(answers_p2[i], "Debug 2");
				resultList->Text = result_p2[i]; // Output the final part
				match = i; // Break out of loop
			}
			i++;
		}
		if (match == -1)
			System::Windows::Forms::MessageBox::Show("No match found for Input", "Error");
	}
}
};
}
