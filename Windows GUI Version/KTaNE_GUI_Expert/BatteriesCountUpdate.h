/**********************************************************
   file: BatteriesCountUpdate.h
 author: Jordan Kooyman
purpose: Contains the interface to update the number of batteries available on the current bomb (only 1 instance is created), passes the data back to the global object dedicated to batteries
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
	/// Summary for BatteriesCountUpdate
	/// </summary>
	public ref class BatteriesCountUpdate : public System::Windows::Forms::Form
	{
	public:
		BatteriesCountUpdate(void)
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
		~BatteriesCountUpdate()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ promptLabel;
	protected:
	private: System::Windows::Forms::Label^ dCellLabel;
	private: System::Windows::Forms::Label^ aaLabel;
	private: System::Windows::Forms::MaskedTextBox^ dCellCountInput;
	private: System::Windows::Forms::MaskedTextBox^ aaCountInput;
	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::Button^ cancelButton;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BatteriesCountUpdate::typeid));
			this->promptLabel = (gcnew System::Windows::Forms::Label());
			this->dCellLabel = (gcnew System::Windows::Forms::Label());
			this->aaLabel = (gcnew System::Windows::Forms::Label());
			this->dCellCountInput = (gcnew System::Windows::Forms::MaskedTextBox());
			this->aaCountInput = (gcnew System::Windows::Forms::MaskedTextBox());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// promptLabel
			// 
			this->promptLabel->AutoSize = true;
			this->promptLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->promptLabel->Location = System::Drawing::Point(11, 9);
			this->promptLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->promptLabel->Name = L"promptLabel";
			this->promptLabel->Size = System::Drawing::Size(424, 20);
			this->promptLabel->TabIndex = 12;
			this->promptLabel->Text = L"Please enter the count of each type of battery on the bomb";
			// 
			// dCellLabel
			// 
			this->dCellLabel->AutoSize = true;
			this->dCellLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->dCellLabel->Location = System::Drawing::Point(257, 39);
			this->dCellLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->dCellLabel->Name = L"dCellLabel";
			this->dCellLabel->Size = System::Drawing::Size(49, 17);
			this->dCellLabel->TabIndex = 11;
			this->dCellLabel->Text = L"D Cell:";
			// 
			// aaLabel
			// 
			this->aaLabel->AutoSize = true;
			this->aaLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->aaLabel->Location = System::Drawing::Point(113, 39);
			this->aaLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->aaLabel->Name = L"aaLabel";
			this->aaLabel->Size = System::Drawing::Size(30, 17);
			this->aaLabel->TabIndex = 10;
			this->aaLabel->Text = L"AA:";
			// 
			// dCellCountInput
			// 
			this->dCellCountInput->AllowPromptAsInput = false;
			this->dCellCountInput->BeepOnError = true;
			this->dCellCountInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dCellCountInput->CutCopyMaskFormat = System::Windows::Forms::MaskFormat::ExcludePromptAndLiterals;
			this->dCellCountInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dCellCountInput->HidePromptOnLeave = true;
			this->dCellCountInput->HideSelection = false;
			this->dCellCountInput->InsertKeyMode = System::Windows::Forms::InsertKeyMode::Overwrite;
			this->dCellCountInput->Location = System::Drawing::Point(308, 38);
			this->dCellCountInput->Margin = System::Windows::Forms::Padding(2);
			this->dCellCountInput->Mask = L"00";
			this->dCellCountInput->Name = L"dCellCountInput";
			this->dCellCountInput->PromptChar = '-';
			this->dCellCountInput->ResetOnPrompt = false;
			this->dCellCountInput->Size = System::Drawing::Size(24, 21);
			this->dCellCountInput->TabIndex = 1;
			this->dCellCountInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->dCellCountInput->ValidatingType = System::Int32::typeid;
			// 
			// aaCountInput
			// 
			this->aaCountInput->AllowPromptAsInput = false;
			this->aaCountInput->BeepOnError = true;
			this->aaCountInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->aaCountInput->CutCopyMaskFormat = System::Windows::Forms::MaskFormat::ExcludePromptAndLiterals;
			this->aaCountInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->aaCountInput->HidePromptOnLeave = true;
			this->aaCountInput->HideSelection = false;
			this->aaCountInput->InsertKeyMode = System::Windows::Forms::InsertKeyMode::Overwrite;
			this->aaCountInput->Location = System::Drawing::Point(147, 39);
			this->aaCountInput->Margin = System::Windows::Forms::Padding(2);
			this->aaCountInput->Mask = L"00";
			this->aaCountInput->Name = L"aaCountInput";
			this->aaCountInput->PromptChar = '-';
			this->aaCountInput->ResetOnPrompt = false;
			this->aaCountInput->Size = System::Drawing::Size(22, 21);
			this->aaCountInput->TabIndex = 0;
			this->aaCountInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->aaCountInput->ValidatingType = System::Int32::typeid;
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(194, 64);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 2;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &BatteriesCountUpdate::exitButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelButton->Location = System::Drawing::Point(380, 67);
			this->cancelButton->Margin = System::Windows::Forms::Padding(2);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(55, 21);
			this->cancelButton->TabIndex = 3;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &BatteriesCountUpdate::cancelButton_Click);
			// 
			// BatteriesCountUpdate
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(449, 99);
			this->ControlBox = false;
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->promptLabel);
			this->Controls->Add(this->dCellLabel);
			this->Controls->Add(this->aaLabel);
			this->Controls->Add(this->dCellCountInput);
			this->Controls->Add(this->aaCountInput);
			this->Controls->Add(this->exitButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"BatteriesCountUpdate";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Battery Count Update";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &BatteriesCountUpdate::BatteriesCountUpdate_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/**
		* Store the states of all inputs in an array, then pass to global variable that processes batteries
		* @param None
		* @return None
		*/
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int Counts[3];
		Counts[0] = System::Convert::ToInt32(aaCountInput->Text);
		Counts[1] = System::Convert::ToInt32(dCellCountInput->Text);
		Counts[2] = Counts[0] + Counts[1];
		CurrentBatteries.batteriesUpdate(Counts);

		resumeCalculation(); // Check if any calculation function called for indicator update, if so, attempt that calculation again
		this->Hide();
		UpdateHome();
	}
		/**
		* Hide the form without submitting information
		* @param None
		* @return None
		*/
private: System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenWindow(0);
	this->Hide();
}
public:
	/**
	* Reset all form elements to default values
	* @param None
	* @return None
	*/
	void ResetForm() {
		   aaCountInput->Text = "";
		   dCellCountInput->Text = "";
	 }
private: System::Void BatteriesCountUpdate_Load(System::Object^ sender, System::EventArgs^ e) {
	
}
};
}
