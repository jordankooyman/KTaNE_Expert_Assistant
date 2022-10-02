/**********************************************************
   file: ModuleMemory.h
 author: Jordan Kooyman
purpose: Contains the Memory module window and the calculations for solving each step as a member function
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
	/// Summary for ModuleMemory
	/// </summary>
	public ref class ModuleMemory : public System::Windows::Forms::Form
	{
	public:
		ModuleMemory(void)
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
		~ModuleMemory()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::Button^ calcButton;
	private: System::Windows::Forms::Label^ displayLabel;
	private: System::Windows::Forms::Label^ labelLabel;
	private: System::Windows::Forms::Label^ positionLabel;
	private: System::Windows::Forms::MaskedTextBox^ stage1Display;
	private: System::Windows::Forms::MaskedTextBox^ stage1Label;
	private: System::Windows::Forms::MaskedTextBox^ stage1Position;
	private: System::Windows::Forms::MaskedTextBox^ stage2Position;
	private: System::Windows::Forms::MaskedTextBox^ stage2Label;








	private: System::Windows::Forms::MaskedTextBox^ stage2Display;
	private: System::Windows::Forms::MaskedTextBox^ stage3Position;
	private: System::Windows::Forms::MaskedTextBox^ stage3Label;



	private: System::Windows::Forms::MaskedTextBox^ stage3Display;
	private: System::Windows::Forms::MaskedTextBox^ stage4Position;
	private: System::Windows::Forms::MaskedTextBox^ stage4Label;



	private: System::Windows::Forms::MaskedTextBox^ stage4Display;
	private: System::Windows::Forms::Button^ resetButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MaskedTextBox^ stage5Display;
	private: System::Windows::Forms::MaskedTextBox^ stage5Position;
	private: System::Windows::Forms::MaskedTextBox^ stage5Label;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModuleMemory::typeid));
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->calcButton = (gcnew System::Windows::Forms::Button());
			this->displayLabel = (gcnew System::Windows::Forms::Label());
			this->labelLabel = (gcnew System::Windows::Forms::Label());
			this->positionLabel = (gcnew System::Windows::Forms::Label());
			this->stage1Display = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage1Label = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage1Position = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage2Position = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage2Label = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage2Display = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage3Position = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage3Label = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage3Display = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage4Position = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage4Label = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage4Display = (gcnew System::Windows::Forms::MaskedTextBox());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->stage5Display = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage5Position = (gcnew System::Windows::Forms::MaskedTextBox());
			this->stage5Label = (gcnew System::Windows::Forms::MaskedTextBox());
			this->SuspendLayout();
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(192, 246);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 16;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ModuleMemory::exitButton_Click);
			// 
			// calcButton
			// 
			this->calcButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->calcButton->Location = System::Drawing::Point(94, 227);
			this->calcButton->Margin = System::Windows::Forms::Padding(2);
			this->calcButton->Name = L"calcButton";
			this->calcButton->Size = System::Drawing::Size(68, 25);
			this->calcButton->TabIndex = 17;
			this->calcButton->Text = L"Submit";
			this->calcButton->UseVisualStyleBackColor = true;
			this->calcButton->Click += gcnew System::EventHandler(this, &ModuleMemory::calcButton_Click);
			// 
			// displayLabel
			// 
			this->displayLabel->AutoSize = true;
			this->displayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->displayLabel->Location = System::Drawing::Point(11, 63);
			this->displayLabel->Name = L"displayLabel";
			this->displayLabel->Size = System::Drawing::Size(77, 24);
			this->displayLabel->TabIndex = 15;
			this->displayLabel->Text = L"Display";
			// 
			// labelLabel
			// 
			this->labelLabel->AutoSize = true;
			this->labelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelLabel->Location = System::Drawing::Point(94, 63);
			this->labelLabel->Name = L"labelLabel";
			this->labelLabel->Size = System::Drawing::Size(61, 24);
			this->labelLabel->TabIndex = 16;
			this->labelLabel->Text = L"Label";
			// 
			// positionLabel
			// 
			this->positionLabel->AutoSize = true;
			this->positionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->positionLabel->Location = System::Drawing::Point(161, 63);
			this->positionLabel->Name = L"positionLabel";
			this->positionLabel->Size = System::Drawing::Size(84, 24);
			this->positionLabel->TabIndex = 17;
			this->positionLabel->Text = L"Position";
			// 
			// stage1Display
			// 
			this->stage1Display->AsciiOnly = true;
			this->stage1Display->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage1Display->HidePromptOnLeave = true;
			this->stage1Display->Location = System::Drawing::Point(32, 94);
			this->stage1Display->Mask = L"0";
			this->stage1Display->Name = L"stage1Display";
			this->stage1Display->Size = System::Drawing::Size(34, 22);
			this->stage1Display->TabIndex = 0;
			this->stage1Display->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage1Display->ValidatingType = System::Int32::typeid;
			this->stage1Display->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &ModuleMemory::stage1Display_MaskInputRejected);
			// 
			// stage1Label
			// 
			this->stage1Label->AsciiOnly = true;
			this->stage1Label->Enabled = false;
			this->stage1Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage1Label->HidePromptOnLeave = true;
			this->stage1Label->Location = System::Drawing::Point(107, 94);
			this->stage1Label->Mask = L"0";
			this->stage1Label->Name = L"stage1Label";
			this->stage1Label->Size = System::Drawing::Size(34, 22);
			this->stage1Label->TabIndex = 1;
			this->stage1Label->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage1Label->ValidatingType = System::Int32::typeid;
			this->stage1Label->Visible = false;
			// 
			// stage1Position
			// 
			this->stage1Position->AsciiOnly = true;
			this->stage1Position->Enabled = false;
			this->stage1Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage1Position->HidePromptOnLeave = true;
			this->stage1Position->Location = System::Drawing::Point(186, 94);
			this->stage1Position->Mask = L"0";
			this->stage1Position->Name = L"stage1Position";
			this->stage1Position->Size = System::Drawing::Size(34, 22);
			this->stage1Position->TabIndex = 2;
			this->stage1Position->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage1Position->ValidatingType = System::Int32::typeid;
			this->stage1Position->Visible = false;
			// 
			// stage2Position
			// 
			this->stage2Position->AsciiOnly = true;
			this->stage2Position->Enabled = false;
			this->stage2Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage2Position->HidePromptOnLeave = true;
			this->stage2Position->Location = System::Drawing::Point(186, 120);
			this->stage2Position->Mask = L"0";
			this->stage2Position->Name = L"stage2Position";
			this->stage2Position->Size = System::Drawing::Size(34, 22);
			this->stage2Position->TabIndex = 5;
			this->stage2Position->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage2Position->ValidatingType = System::Int32::typeid;
			this->stage2Position->Visible = false;
			// 
			// stage2Label
			// 
			this->stage2Label->AsciiOnly = true;
			this->stage2Label->Enabled = false;
			this->stage2Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage2Label->HidePromptOnLeave = true;
			this->stage2Label->Location = System::Drawing::Point(107, 120);
			this->stage2Label->Mask = L"0";
			this->stage2Label->Name = L"stage2Label";
			this->stage2Label->Size = System::Drawing::Size(34, 22);
			this->stage2Label->TabIndex = 4;
			this->stage2Label->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage2Label->ValidatingType = System::Int32::typeid;
			this->stage2Label->Visible = false;
			// 
			// stage2Display
			// 
			this->stage2Display->AsciiOnly = true;
			this->stage2Display->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage2Display->HidePromptOnLeave = true;
			this->stage2Display->Location = System::Drawing::Point(32, 120);
			this->stage2Display->Mask = L"0";
			this->stage2Display->Name = L"stage2Display";
			this->stage2Display->Size = System::Drawing::Size(34, 22);
			this->stage2Display->TabIndex = 3;
			this->stage2Display->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage2Display->ValidatingType = System::Int32::typeid;
			this->stage2Display->Visible = false;
			// 
			// stage3Position
			// 
			this->stage3Position->AsciiOnly = true;
			this->stage3Position->Enabled = false;
			this->stage3Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage3Position->HidePromptOnLeave = true;
			this->stage3Position->Location = System::Drawing::Point(186, 146);
			this->stage3Position->Mask = L"0";
			this->stage3Position->Name = L"stage3Position";
			this->stage3Position->Size = System::Drawing::Size(34, 22);
			this->stage3Position->TabIndex = 8;
			this->stage3Position->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage3Position->ValidatingType = System::Int32::typeid;
			this->stage3Position->Visible = false;
			// 
			// stage3Label
			// 
			this->stage3Label->AsciiOnly = true;
			this->stage3Label->Enabled = false;
			this->stage3Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage3Label->HidePromptOnLeave = true;
			this->stage3Label->Location = System::Drawing::Point(107, 146);
			this->stage3Label->Mask = L"0";
			this->stage3Label->Name = L"stage3Label";
			this->stage3Label->Size = System::Drawing::Size(34, 22);
			this->stage3Label->TabIndex = 7;
			this->stage3Label->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage3Label->ValidatingType = System::Int32::typeid;
			this->stage3Label->Visible = false;
			// 
			// stage3Display
			// 
			this->stage3Display->AsciiOnly = true;
			this->stage3Display->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage3Display->HidePromptOnLeave = true;
			this->stage3Display->Location = System::Drawing::Point(32, 146);
			this->stage3Display->Mask = L"0";
			this->stage3Display->Name = L"stage3Display";
			this->stage3Display->Size = System::Drawing::Size(34, 22);
			this->stage3Display->TabIndex = 6;
			this->stage3Display->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage3Display->ValidatingType = System::Int32::typeid;
			this->stage3Display->Visible = false;
			// 
			// stage4Position
			// 
			this->stage4Position->AsciiOnly = true;
			this->stage4Position->Enabled = false;
			this->stage4Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage4Position->HidePromptOnLeave = true;
			this->stage4Position->Location = System::Drawing::Point(186, 172);
			this->stage4Position->Mask = L"0";
			this->stage4Position->Name = L"stage4Position";
			this->stage4Position->Size = System::Drawing::Size(34, 22);
			this->stage4Position->TabIndex = 11;
			this->stage4Position->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage4Position->ValidatingType = System::Int32::typeid;
			this->stage4Position->Visible = false;
			// 
			// stage4Label
			// 
			this->stage4Label->AsciiOnly = true;
			this->stage4Label->Enabled = false;
			this->stage4Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage4Label->HidePromptOnLeave = true;
			this->stage4Label->Location = System::Drawing::Point(107, 172);
			this->stage4Label->Mask = L"0";
			this->stage4Label->Name = L"stage4Label";
			this->stage4Label->Size = System::Drawing::Size(34, 22);
			this->stage4Label->TabIndex = 10;
			this->stage4Label->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage4Label->ValidatingType = System::Int32::typeid;
			this->stage4Label->Visible = false;
			// 
			// stage4Display
			// 
			this->stage4Display->AsciiOnly = true;
			this->stage4Display->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage4Display->HidePromptOnLeave = true;
			this->stage4Display->Location = System::Drawing::Point(32, 172);
			this->stage4Display->Mask = L"0";
			this->stage4Display->Name = L"stage4Display";
			this->stage4Display->Size = System::Drawing::Size(34, 22);
			this->stage4Display->TabIndex = 9;
			this->stage4Display->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage4Display->ValidatingType = System::Int32::typeid;
			this->stage4Display->Visible = false;
			// 
			// resetButton
			// 
			this->resetButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->resetButton->Location = System::Drawing::Point(10, 246);
			this->resetButton->Margin = System::Windows::Forms::Padding(2);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(55, 21);
			this->resetButton->TabIndex = 15;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &ModuleMemory::resetButton_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(-1, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(257, 61);
			this->label1->TabIndex = 31;
			this->label1->Text = L"Fill in the Display between 1 and 4, then either the label or position  based on "
				L"the one just filled in";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// stage5Display
			// 
			this->stage5Display->AsciiOnly = true;
			this->stage5Display->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage5Display->HidePromptOnLeave = true;
			this->stage5Display->Location = System::Drawing::Point(31, 200);
			this->stage5Display->Mask = L"0";
			this->stage5Display->Name = L"stage5Display";
			this->stage5Display->Size = System::Drawing::Size(34, 22);
			this->stage5Display->TabIndex = 12;
			this->stage5Display->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage5Display->ValidatingType = System::Int32::typeid;
			this->stage5Display->Visible = false;
			// 
			// stage5Position
			// 
			this->stage5Position->AsciiOnly = true;
			this->stage5Position->Enabled = false;
			this->stage5Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage5Position->HidePromptOnLeave = true;
			this->stage5Position->Location = System::Drawing::Point(186, 200);
			this->stage5Position->Mask = L"0";
			this->stage5Position->Name = L"stage5Position";
			this->stage5Position->Size = System::Drawing::Size(34, 22);
			this->stage5Position->TabIndex = 14;
			this->stage5Position->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage5Position->ValidatingType = System::Int32::typeid;
			this->stage5Position->Visible = false;
			// 
			// stage5Label
			// 
			this->stage5Label->AsciiOnly = true;
			this->stage5Label->Enabled = false;
			this->stage5Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stage5Label->HidePromptOnLeave = true;
			this->stage5Label->Location = System::Drawing::Point(107, 200);
			this->stage5Label->Mask = L"0";
			this->stage5Label->Name = L"stage5Label";
			this->stage5Label->Size = System::Drawing::Size(34, 22);
			this->stage5Label->TabIndex = 13;
			this->stage5Label->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->stage5Label->ValidatingType = System::Int32::typeid;
			this->stage5Label->Visible = false;
			// 
			// ModuleMemory
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(256, 271);
			this->Controls->Add(this->stage5Position);
			this->Controls->Add(this->stage5Label);
			this->Controls->Add(this->stage5Display);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->stage4Position);
			this->Controls->Add(this->stage4Label);
			this->Controls->Add(this->stage4Display);
			this->Controls->Add(this->stage3Position);
			this->Controls->Add(this->stage3Label);
			this->Controls->Add(this->stage3Display);
			this->Controls->Add(this->stage2Position);
			this->Controls->Add(this->stage2Label);
			this->Controls->Add(this->stage2Display);
			this->Controls->Add(this->stage1Position);
			this->Controls->Add(this->stage1Label);
			this->Controls->Add(this->stage1Display);
			this->Controls->Add(this->positionLabel);
			this->Controls->Add(this->labelLabel);
			this->Controls->Add(this->displayLabel);
			this->Controls->Add(this->calcButton);
			this->Controls->Add(this->exitButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ModuleMemory";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Memory";
			this->Load += gcnew System::EventHandler(this, &ModuleMemory::ModuleMemory_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private:
	void ResetForm()
	{
		stage1Display->Visible = true;
		stage1Display->Enabled = true;
		stage1Display->Text = "0";
		stage1Label->Visible = true;
		stage1Label->Enabled = false;
		stage1Label->Text = "0";
		stage1Position->Visible = true;
		stage1Position->Enabled = false;
		stage1Position->Text = "0";

		stage2Display->Visible = false;
		stage2Display->Enabled = true;
		stage2Display->Text = "0";
		stage2Label->Visible = false;
		stage2Label->Enabled = false;
		stage2Label->Text = "0";
		stage2Position->Visible = false;
		stage2Position->Enabled = false;
		stage2Position->Text = "0";

		stage3Display->Visible = false;
		stage3Display->Enabled = true;
		stage3Display->Text = "0";
		stage3Label->Visible = false;
		stage3Label->Enabled = false;
		stage3Label->Text = "0";
		stage3Position->Visible = false;
		stage3Position->Enabled = false;
		stage3Position->Text = "0";

		stage4Display->Visible = false;
		stage4Display->Enabled = true;
		stage4Display->Text = "0";
		stage4Label->Visible = false;
		stage4Label->Enabled = false;
		stage4Label->Text = "0";
		stage4Position->Visible = false;
		stage4Position->Enabled = false;
		stage4Position->Text = "0";

		stage5Display->Visible = false;
		stage5Display->Enabled = true;
		stage5Display->Text = "0";
		stage5Label->Visible = false;
		stage5Label->Enabled = false;
		stage5Label->Text = "0";
		stage5Position->Visible = false;
		stage5Position->Enabled = false;
		stage5Position->Text = "0";
		
		stage = 1;
	}
	int stage = 1;
private: System::Void stage1Display_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
}
private: System::Void calcButton_Click(System::Object^ sender, System::EventArgs^ e) {
	//System::Windows::Forms::MessageBox::Show("A Color option and Text option must be selected", "Error");
	//Ensure no blank strings will be checked
	if (stage1Display->Text == "" || stage2Display->Text == "" || stage3Display->Text == "" || stage4Display->Text == "" || stage5Display->Text == "" || stage1Position->Text == "" || stage2Position->Text == "" || stage3Position->Text == "" || stage4Position->Text == "" || stage5Position->Text == "" || stage1Label->Text == "" || stage2Label->Text == "" || stage3Label->Text == "" || stage4Label->Text == "" || stage5Label->Text == "")
	{
		System::Windows::Forms::MessageBox::Show("A number between 1 and 4 (inclusive) must be entered in each text box", "Error");
		return;
	}
	switch (stage)
	{
	case 1: // Stage 1
		if (System::Convert::ToInt32(stage1Display->Text) <= 0 || System::Convert::ToInt32(stage1Display->Text) >= 5) // Input Not Within Bounds
		{
			System::Windows::Forms::MessageBox::Show("A number between 1 and 4 (inclusive) must be entered in each text box", "Error");
			return;
		}
		switch (System::Convert::ToInt32(stage1Display->Text))
		{
		case 1:
		case 2:
		{
			stage1Position->Text = "2";
			stage1Position->Visible = true;
			stage1Label->Enabled = true;
			stage1Label->Visible = true;
			stage1Display->Enabled = false;
			stage2Display->Visible = true;
			break;
		}
		case 3:
		{
			stage1Position->Text = "3";
			stage1Position->Visible = true;
			stage1Label->Enabled = true;
			stage1Label->Visible = true;
			stage1Display->Enabled = false;
			stage2Display->Visible = true;
			break;
		}
		case 4:
		{
			stage1Position->Text = "4";
			stage1Position->Visible = true;
			stage1Label->Enabled = true;
			stage1Label->Visible = true;
			stage1Display->Enabled = false;
			stage2Display->Visible = true;
			break;
		}
		}
		stage++;
		break;
	case 2: // Stage 2
		if (System::Convert::ToInt32(stage2Display->Text) <= 0 || System::Convert::ToInt32(stage2Display->Text) >= 5 || System::Convert::ToInt32(stage1Position->Text) <= 0 || System::Convert::ToInt32(stage1Position->Text) >= 5 || System::Convert::ToInt32(stage1Label->Text) <= 0 || System::Convert::ToInt32(stage1Label->Text) >= 5) // Stage 2 Display, Stage 1 Label, and Stage 1 Positon, if any input Not Within Bounds
		{
			System::Windows::Forms::MessageBox::Show("A number between 1 and 4 (inclusive) must be entered in each text boxs", "Error");
			return;
		}
		switch (System::Convert::ToInt32(stage2Display->Text))
		{
		case 1:
		{
			stage2Label->Text = "4";
			stage2Position->Visible = true;
			stage2Position->Enabled = true;
			stage2Label->Visible = true;
			stage2Display->Enabled = false;
			stage3Display->Visible = true;
			stage1Label->Enabled = false;
			stage1Position->Enabled = false;
			break;
		}
		case 2:
		case 4:
		{
			stage2Position->Text = stage1Position->Text;
			stage2Position->Visible = true;
			stage2Label->Enabled = true;
			stage2Label->Visible = true;
			stage2Display->Enabled = false;
			stage3Display->Visible = true;
			stage1Label->Enabled = false;
			stage1Position->Enabled = false;
			break;
		}
		case 3:
		{
			stage2Position->Text = "1";
			stage2Position->Visible = true;
			stage2Label->Enabled = true;
			stage2Label->Visible = true;
			stage2Display->Enabled = false;
			stage3Display->Visible = true;
			stage1Label->Enabled = false;
			stage1Position->Enabled = false;
			break;
		}
		}
		stage++;
		break;
	case 3: // Stage 3
		if (System::Convert::ToInt32(stage3Display->Text) <= 0 || System::Convert::ToInt32(stage3Display->Text) >= 5 || System::Convert::ToInt32(stage2Position->Text) <= 0 || System::Convert::ToInt32(stage2Position->Text) >= 5 || System::Convert::ToInt32(stage2Label->Text) <= 0 || System::Convert::ToInt32(stage2Label->Text) >= 5) // Stage 3 Display, Stage 2 Label, and Stage 2 Positon, if any input Not Within Bounds
		{
			System::Windows::Forms::MessageBox::Show("A number between 1 and 4 (inclusive) must be entered in each text boxs", "Error");
			return;
		}
		switch (System::Convert::ToInt32(stage3Display->Text))
		{
		case 1:
		{
			stage3Label->Text = stage2Label->Text;
			stage3Position->Visible = true;
			stage3Position->Enabled = true;
			stage3Label->Visible = true;
			stage3Display->Enabled = false;
			stage4Display->Visible = true;
			stage2Label->Enabled = false;
			stage2Position->Enabled = false;
			break;
		}
		case 2:
		{
			stage3Label->Text = stage1Label->Text;
			stage3Position->Visible = true;
			stage3Position->Enabled = true;
			stage3Label->Visible = true;
			stage3Display->Enabled = false;
			stage4Display->Visible = true;
			stage2Label->Enabled = false;
			stage2Position->Enabled = false;
			break;
		}
		case 3:
		{
			stage3Position->Text = "3";
			stage3Position->Visible = true;
			stage3Label->Enabled = true;
			stage3Label->Visible = true;
			stage3Display->Enabled = false;
			stage4Display->Visible = true;
			stage2Label->Enabled = false;
			stage2Position->Enabled = false;
			break;
		}
		case 4:
		{
			stage3Label->Text = "4";
			stage3Position->Visible = true;
			stage3Position->Enabled = true;
			stage3Label->Visible = true;
			stage3Display->Enabled = false;
			stage4Display->Visible = true;
			stage2Label->Enabled = false;
			stage2Position->Enabled = false;
			break;
		}
		}
		stage++;
		break;
	case 4: // Stage 4
		if (System::Convert::ToInt32(stage4Display->Text) <= 0 || System::Convert::ToInt32(stage4Display->Text) >= 5 || System::Convert::ToInt32(stage3Position->Text) <= 0 || System::Convert::ToInt32(stage3Position->Text) >= 5 || System::Convert::ToInt32(stage3Label->Text) <= 0 || System::Convert::ToInt32(stage3Label->Text) >= 5) // Stage 4 Display, Stage 3 Label, and Stage 3 Positon, if any input Not Within Bounds
		{
			System::Windows::Forms::MessageBox::Show("A number between 1 and 4 (inclusive) must be entered in each text boxs", "Error");
			return;
		}
		switch (System::Convert::ToInt32(stage4Display->Text))
		{
		case 1:
		{
			stage4Position->Text = stage1Position->Text;
			stage4Position->Visible = true;
			stage4Label->Enabled = true;
			stage4Label->Visible = true;
			stage4Display->Enabled = false;
			stage5Display->Visible = true;
			stage3Label->Enabled = false;
			stage3Position->Enabled = false;
			break;
		}
		case 2:
		{
			stage4Position->Text = "1";
			stage4Position->Visible = true;
			stage4Label->Enabled = true;
			stage4Label->Visible = true;
			stage4Display->Enabled = false;
			stage5Display->Visible = true;
			stage3Label->Enabled = false;
			stage3Position->Enabled = false;
			break;
		}
		case 3:
		case 4:
		{
			stage4Position->Text = stage2Position->Text;
			stage4Position->Visible = true;
			stage4Label->Enabled = true;
			stage4Label->Visible = true;
			stage4Display->Enabled = false;
			stage5Display->Visible = true;
			stage3Label->Enabled = false;
			stage3Position->Enabled = false;
			break;
		}
		}
		stage++;
		break;
	case 5: // Stage 5
		if (System::Convert::ToInt32(stage5Display->Text) <= 0 || System::Convert::ToInt32(stage5Display->Text) >= 5 || System::Convert::ToInt32(stage4Position->Text) <= 0 || System::Convert::ToInt32(stage4Position->Text) >= 5 || System::Convert::ToInt32(stage4Label->Text) <= 0 || System::Convert::ToInt32(stage4Label->Text) >= 5) // Stage 5 Display, Stage 4 Label, and Stage 4 Positon, if any input Not Within Bounds
		{
			System::Windows::Forms::MessageBox::Show("A number between 1 and 4 (inclusive) must be entered in each text boxs", "Error");
			return;
		}
		switch (System::Convert::ToInt32(stage5Display->Text))
		{
		case 1:
		{
			stage5Label->Text = stage1Label->Text;
			stage5Position->Visible = true;
			stage5Position->Enabled = false;
			stage5Label->Visible = true;
			stage5Display->Enabled = false;
			stage4Label->Enabled = false;
			stage4Position->Enabled = false;
			break;
		}
		case 2:
		{
			stage5Label->Text = stage2Label->Text;
			stage5Position->Visible = true;
			stage5Position->Enabled = false;
			stage5Label->Visible = true;
			stage5Display->Enabled = false;
			stage4Label->Enabled = false;
			stage4Position->Enabled = false;
			break;
		}
		case 3:
		{
			stage5Label->Text = stage4Label->Text;
			stage5Position->Visible = true;
			stage5Position->Enabled = false;
			stage5Label->Visible = true;
			stage5Display->Enabled = false;
			stage4Label->Enabled = false;
			stage4Position->Enabled = false;
			break;
		}
		case 4:
		{
			stage5Label->Text = stage3Label->Text;
			stage5Position->Visible = true;
			stage5Position->Enabled = false;
			stage5Label->Visible = true;
			stage5Display->Enabled = false;
			stage4Label->Enabled = false;
			stage4Position->Enabled = false;
			break;
		}
		}
		stage++;
		stage5Position->Visible = false;
		break;
	}
}
private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ResetForm();
}
private: System::Void ModuleMemory_Load(System::Object^ sender, System::EventArgs^ e) {
	ResetForm();
}
};
}
