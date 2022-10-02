/**********************************************************
   file: ModulePassword.h
 author: Jordan Kooyman
purpose: Contains the Password module window and the calculations for identifing all potential password matches as member functions
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
	/// Summary for ModulePassword
	/// </summary>
	public ref class ModulePassword : public System::Windows::Forms::Form
	{
	public:
		ModulePassword(void)
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
		~ModulePassword()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ exitButton;
	protected:
	private: System::Windows::Forms::Button^ calcButton;
	private: System::Windows::Forms::MaskedTextBox^ pos1Input;
	private: System::Windows::Forms::MaskedTextBox^ pos2Input;
	private: System::Windows::Forms::MaskedTextBox^ pos3Input;







	private: System::Windows::Forms::Label^ pos1Label;
	private: System::Windows::Forms::Label^ pos2Label;
	private: System::Windows::Forms::Label^ pos3Label;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModulePassword::typeid));
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->calcButton = (gcnew System::Windows::Forms::Button());
			this->pos1Input = (gcnew System::Windows::Forms::MaskedTextBox());
			this->pos2Input = (gcnew System::Windows::Forms::MaskedTextBox());
			this->pos3Input = (gcnew System::Windows::Forms::MaskedTextBox());
			this->pos1Label = (gcnew System::Windows::Forms::Label());
			this->pos2Label = (gcnew System::Windows::Forms::Label());
			this->pos3Label = (gcnew System::Windows::Forms::Label());
			this->outputLabel = (gcnew System::Windows::Forms::Label());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// exitButton
			// 
			resources->ApplyResources(this->exitButton, L"exitButton");
			this->exitButton->Name = L"exitButton";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ModulePassword::exitButton_Click);
			// 
			// calcButton
			// 
			resources->ApplyResources(this->calcButton, L"calcButton");
			this->calcButton->Name = L"calcButton";
			this->calcButton->UseVisualStyleBackColor = true;
			this->calcButton->Click += gcnew System::EventHandler(this, &ModulePassword::calcButton_Click);
			// 
			// pos1Input
			// 
			resources->ApplyResources(this->pos1Input, L"pos1Input");
			this->pos1Input->HidePromptOnLeave = true;
			this->pos1Input->Name = L"pos1Input";
			// 
			// pos2Input
			// 
			resources->ApplyResources(this->pos2Input, L"pos2Input");
			this->pos2Input->HidePromptOnLeave = true;
			this->pos2Input->Name = L"pos2Input";
			// 
			// pos3Input
			// 
			resources->ApplyResources(this->pos3Input, L"pos3Input");
			this->pos3Input->HidePromptOnLeave = true;
			this->pos3Input->Name = L"pos3Input";
			// 
			// pos1Label
			// 
			resources->ApplyResources(this->pos1Label, L"pos1Label");
			this->pos1Label->Name = L"pos1Label";
			// 
			// pos2Label
			// 
			resources->ApplyResources(this->pos2Label, L"pos2Label");
			this->pos2Label->Name = L"pos2Label";
			// 
			// pos3Label
			// 
			resources->ApplyResources(this->pos3Label, L"pos3Label");
			this->pos3Label->Name = L"pos3Label";
			// 
			// outputLabel
			// 
			resources->ApplyResources(this->outputLabel, L"outputLabel");
			this->outputLabel->Name = L"outputLabel";
			// 
			// resetButton
			// 
			resources->ApplyResources(this->resetButton, L"resetButton");
			this->resetButton->Name = L"resetButton";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &ModulePassword::resetButton_Click);
			// 
			// ModulePassword
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->pos3Label);
			this->Controls->Add(this->pos2Label);
			this->Controls->Add(this->pos1Label);
			this->Controls->Add(this->pos3Input);
			this->Controls->Add(this->pos2Input);
			this->Controls->Add(this->pos1Input);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->calcButton);
			this->Controls->Add(this->outputLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ModulePassword";
			this->Load += gcnew System::EventHandler(this, &ModulePassword::ModulePassword_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void calcButton_Click(System::Object^ sender, System::EventArgs^ e) {
	// Ensure minimum information required is entered
	if (pos1Input->Text->Length != 6)
	{
		System::Windows::Forms::MessageBox::Show("6 Letters must be input in the First Column", "Error");
	}
	if (pos2Input->Text->Length != 6)
	{
		System::Windows::Forms::MessageBox::Show("6 Letters must be input in the Second Column", "Error");
	}
	if (pos3Input->Text->Length != 6)
	{
		System::Windows::Forms::MessageBox::Show("6 Letters must be input in the Third Column", "Error");
	}

	wchar_t word_bank[35][5] = { {'a', 'b', 'o', 'u', 't'}, {'a', 'f', 't', 'e', 'r'}, {'a', 'g', 'a', 'i', 'n'}, {'b', 'e', 'l', 'o', 'w'}, {'c', 'o', 'u', 'l', 'd'},
							  {'e', 'v', 'e', 'r', 'y'}, {'f', 'i', 'r', 's', 't'}, {'f', 'o', 'u', 'n', 'd'}, {'g', 'r', 'e', 'a', 't'}, {'h', 'o', 'u', 's', 'e'},
							  {'l', 'a', 'r', 'g', 'e'}, {'l', 'e', 'a', 'r', 'n'}, {'n', 'e', 'v', 'e', 'r'}, {'o', 't', 'h', 'e', 'r'}, {'p', 'l', 'a', 'c', 'e'},
							  {'p', 'l', 'a', 'n', 't'}, {'p', 'o', 'i', 'n', 't'}, {'r', 'i', 'g', 'h', 't'}, {'s', 'm', 'a', 'l', 'l'}, {'s', 'o', 'u', 'n', 'd'},
							  {'s', 'p', 'e', 'l', 'l'}, {'s', 't', 'i', 'l', 'l'}, {'s', 't', 'u', 'd', 'y'}, {'t', 'h', 'e', 'i', 'r'}, {'t', 'h', 'e', 'r', 'e'},
							  {'t', 'h', 'e', 's', 'e'}, {'t', 'h', 'i', 'n', 'g'}, {'t', 'h', 'i', 'n', 'k'}, {'t', 'h', 'r', 'e', 'e'}, {'w', 'a', 't', 'e', 'r'},
							  {'w', 'h', 'e', 'r', 'e'}, {'w', 'h', 'i', 'c', 'h'}, {'w', 'o', 'r', 'l', 'd'}, {'w', 'o', 'u', 'l', 'd'}, {'w', 'r', 'i', 't', 'e'} };
	/*string word_bank[35] = {"about","after","again","below","could",
							 "every","first","found","great","house",
							 "large","learn","never","other","place",
							 "plant","point","right","small","sound",
							 "spell","still","study","their","there",
							 "these","thing","think","three","water",
							 "where","which","world","would","write" };*/
	System::String^ Output = "";
	for (int i = 0; i < 35; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (word_bank[i][0] == tolower(pos1Input->Text[j]))
			{
				for (int k = 0; k < 6; k++)
				{
					if (word_bank[i][1] == tolower(pos2Input->Text[k]))
					{
						for (int l = 0; l < 6; l++)
						{
							if (word_bank[i][2] == tolower(pos3Input->Text[l]))
							{
								for (int m = 0; m < 5; m++)
								{
									Output += System::Convert::ToString(word_bank[i][m]);
								}
								Output += " ";
							}
						}
					}
				}
			}
		}
	}
	outputLabel->Text = Output;
}
private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	outputLabel->Text = "Fill in all 6 letters for each prompt, then click calculate";
	pos1Input->Text = "";
	pos2Input->Text = "";
	pos3Input->Text = "";
}
private: System::Void ModulePassword_Load(System::Object^ sender, System::EventArgs^ e) {
	outputLabel->Text = "Fill in all 6 letters for each prompt, then click calculate";
	pos1Input->Text = "";
	pos2Input->Text = "";
	pos3Input->Text = "";
}
};
}
