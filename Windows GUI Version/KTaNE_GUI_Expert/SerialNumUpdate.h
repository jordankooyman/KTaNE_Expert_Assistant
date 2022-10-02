/**********************************************************
   file: SerialNumUpdate.h
 author: Jordan Kooyman
purpose: Contains the interface to update the serial number on the current bomb (only 1 instance is created), passes the data back to the global object dedicated to the serial number
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
	/// Summary for SerialNumUpdate
	/// </summary>
	public ref class SerialNumUpdate : public System::Windows::Forms::Form
	{
	public:
		SerialNumUpdate(void)
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
		~SerialNumUpdate()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::MaskedTextBox^ serialNumInput;
	protected:

	private: System::Windows::Forms::Label^ serialPrompt;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SerialNumUpdate::typeid));
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->serialNumInput = (gcnew System::Windows::Forms::MaskedTextBox());
			this->serialPrompt = (gcnew System::Windows::Forms::Label());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(147, 67);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 1;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &SerialNumUpdate::exitButton_Click);
			// 
			// serialNumInput
			// 
			this->serialNumInput->AllowPromptAsInput = false;
			this->serialNumInput->AsciiOnly = true;
			this->serialNumInput->BeepOnError = true;
			this->serialNumInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->serialNumInput->CutCopyMaskFormat = System::Windows::Forms::MaskFormat::ExcludePromptAndLiterals;
			this->serialNumInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->serialNumInput->HidePromptOnLeave = true;
			this->serialNumInput->HideSelection = false;
			this->serialNumInput->InsertKeyMode = System::Windows::Forms::InsertKeyMode::Overwrite;
			this->serialNumInput->Location = System::Drawing::Point(140, 38);
			this->serialNumInput->Margin = System::Windows::Forms::Padding(2);
			this->serialNumInput->Mask = L"AAAAAA";
			this->serialNumInput->Name = L"serialNumInput";
			this->serialNumInput->Size = System::Drawing::Size(69, 23);
			this->serialNumInput->TabIndex = 0;
			this->serialNumInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// serialPrompt
			// 
			this->serialPrompt->AutoSize = true;
			this->serialPrompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->serialPrompt->Location = System::Drawing::Point(11, 9);
			this->serialPrompt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->serialPrompt->Name = L"serialPrompt";
			this->serialPrompt->Size = System::Drawing::Size(322, 20);
			this->serialPrompt->TabIndex = 3;
			this->serialPrompt->Text = L"Please enter the Serial Number on the bomb";
			// 
			// cancelButton
			// 
			this->cancelButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelButton->Location = System::Drawing::Point(278, 69);
			this->cancelButton->Margin = System::Windows::Forms::Padding(2);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(55, 21);
			this->cancelButton->TabIndex = 2;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &SerialNumUpdate::cancelButton_Click);
			// 
			// SerialNumUpdate
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(348, 101);
			this->ControlBox = false;
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->serialNumInput);
			this->Controls->Add(this->serialPrompt);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SerialNumUpdate";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Serial Number Update";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/**
		* Store the state of the input in a char array, then pass to global variable that processes serial number
		* @param None
		* @return None
		*/
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialNumInput->Text->Length == 6)
		{
			char Serial[6];
			for (int i = 0; i < 6; i++)
			{
				if (serialNumInput->Text[i] == 'o' || serialNumInput->Text[i] == 'O')
					Serial[i] = '0'; // Convert Os to 0s (case insensitive)
				else if (serialNumInput->Text[i] >= 97 && serialNumInput->Text[i] <= 122)
					Serial[i] = serialNumInput->Text[i] - 32; // Force Upper Case
				else
					Serial[i] = serialNumInput->Text[i];
			}

			CurrentSerial.serialUpdate(Serial);
			this->Hide();
			OpenWindow(0);
			UpdateHome();
			resumeCalculation();
		}
		else 
			System::Windows::Forms::MessageBox::Show("Serial Number must be 6 digits", "Error");
	}
		/**
		* Hide the form without submitting information
		* @param None
		* @return None
		*/
	private: System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		OpenWindow(0);
	}
public:
	/**
	* Reset all form elements to default values
	* @param None
	* @return None
	*/
	void ResetForm() {
		serialNumInput->Text = "";
	}

};
}
