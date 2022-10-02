/**********************************************************
   file: IndicatorUpdate.h
 author: Jordan Kooyman
purpose: Contains the interface to update the list and status of all possible indicators available on the current bomb (only 1 instance is created), passes the data back to the global object dedicated to indicators
**********************************************************/
#pragma once

namespace KTaNEGUIExpert {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	

	/// <summary>
	/// Summary for IndicatorUpdate
	/// </summary>
	public ref class IndicatorUpdate : public System::Windows::Forms::Form
	{
	public:
		IndicatorUpdate(void)
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
		~IndicatorUpdate()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ indicatorsPrompt;
	protected:
	private: System::Windows::Forms::Label^ litLabel;
	private: System::Windows::Forms::Label^ existsLabel;
	private: System::Windows::Forms::CheckBox^ trnLit;
	private: System::Windows::Forms::CheckBox^ sndLit;
	private: System::Windows::Forms::CheckBox^ sigLit;
	private: System::Windows::Forms::CheckBox^ nsaLit;
	private: System::Windows::Forms::CheckBox^ msaLit;
	private: System::Windows::Forms::CheckBox^ indLit;
	private: System::Windows::Forms::CheckBox^ frqLit;
	private: System::Windows::Forms::CheckBox^ frkLit;
	private: System::Windows::Forms::CheckBox^ clrLit;
	private: System::Windows::Forms::CheckBox^ carLit;
	private: System::Windows::Forms::CheckBox^ bobLit;
	private: System::Windows::Forms::CheckBox^ trnExists;
	private: System::Windows::Forms::CheckBox^ sndExists;
	private: System::Windows::Forms::CheckBox^ sigExists;
	private: System::Windows::Forms::CheckBox^ nsaExists;
	private: System::Windows::Forms::CheckBox^ msaExists;
	private: System::Windows::Forms::CheckBox^ indExists;
	private: System::Windows::Forms::CheckBox^ frqExists;
private: System::Windows::Forms::CheckBox^ frkExists;

	private: System::Windows::Forms::CheckBox^ clrExists;
	private: System::Windows::Forms::CheckBox^ carExists;
	private: System::Windows::Forms::CheckBox^ bobExists;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(IndicatorUpdate::typeid));
			this->indicatorsPrompt = (gcnew System::Windows::Forms::Label());
			this->litLabel = (gcnew System::Windows::Forms::Label());
			this->existsLabel = (gcnew System::Windows::Forms::Label());
			this->trnLit = (gcnew System::Windows::Forms::CheckBox());
			this->sndLit = (gcnew System::Windows::Forms::CheckBox());
			this->sigLit = (gcnew System::Windows::Forms::CheckBox());
			this->nsaLit = (gcnew System::Windows::Forms::CheckBox());
			this->msaLit = (gcnew System::Windows::Forms::CheckBox());
			this->indLit = (gcnew System::Windows::Forms::CheckBox());
			this->frqLit = (gcnew System::Windows::Forms::CheckBox());
			this->frkLit = (gcnew System::Windows::Forms::CheckBox());
			this->clrLit = (gcnew System::Windows::Forms::CheckBox());
			this->carLit = (gcnew System::Windows::Forms::CheckBox());
			this->bobLit = (gcnew System::Windows::Forms::CheckBox());
			this->trnExists = (gcnew System::Windows::Forms::CheckBox());
			this->sndExists = (gcnew System::Windows::Forms::CheckBox());
			this->sigExists = (gcnew System::Windows::Forms::CheckBox());
			this->nsaExists = (gcnew System::Windows::Forms::CheckBox());
			this->msaExists = (gcnew System::Windows::Forms::CheckBox());
			this->indExists = (gcnew System::Windows::Forms::CheckBox());
			this->frqExists = (gcnew System::Windows::Forms::CheckBox());
			this->frkExists = (gcnew System::Windows::Forms::CheckBox());
			this->clrExists = (gcnew System::Windows::Forms::CheckBox());
			this->carExists = (gcnew System::Windows::Forms::CheckBox());
			this->bobExists = (gcnew System::Windows::Forms::CheckBox());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// indicatorsPrompt
			// 
			this->indicatorsPrompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->indicatorsPrompt->Location = System::Drawing::Point(14, 16);
			this->indicatorsPrompt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->indicatorsPrompt->Name = L"indicatorsPrompt";
			this->indicatorsPrompt->Size = System::Drawing::Size(299, 43);
			this->indicatorsPrompt->TabIndex = 54;
			this->indicatorsPrompt->Text = L"Please enter all indicators found on the bomb, and whether the LED is lit up";
			this->indicatorsPrompt->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// litLabel
			// 
			this->litLabel->AutoSize = true;
			this->litLabel->Location = System::Drawing::Point(157, 57);
			this->litLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->litLabel->Name = L"litLabel";
			this->litLabel->Size = System::Drawing::Size(45, 13);
			this->litLabel->TabIndex = 53;
			this->litLabel->Text = L"LED On";
			// 
			// existsLabel
			// 
			this->existsLabel->AutoSize = true;
			this->existsLabel->Location = System::Drawing::Point(112, 57);
			this->existsLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->existsLabel->Name = L"existsLabel";
			this->existsLabel->Size = System::Drawing::Size(34, 13);
			this->existsLabel->TabIndex = 52;
			this->existsLabel->Text = L"Exists";
			// 
			// trnLit
			// 
			this->trnLit->AutoSize = true;
			this->trnLit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->trnLit->Location = System::Drawing::Point(172, 275);
			this->trnLit->Margin = System::Windows::Forms::Padding(2);
			this->trnLit->Name = L"trnLit";
			this->trnLit->Size = System::Drawing::Size(13, 12);
			this->trnLit->TabIndex = 21;
			this->trnLit->UseVisualStyleBackColor = true;
			// 
			// sndLit
			// 
			this->sndLit->AutoSize = true;
			this->sndLit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->sndLit->Location = System::Drawing::Point(172, 255);
			this->sndLit->Margin = System::Windows::Forms::Padding(2);
			this->sndLit->Name = L"sndLit";
			this->sndLit->Size = System::Drawing::Size(13, 12);
			this->sndLit->TabIndex = 19;
			this->sndLit->UseVisualStyleBackColor = true;
			// 
			// sigLit
			// 
			this->sigLit->AutoSize = true;
			this->sigLit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->sigLit->Location = System::Drawing::Point(172, 235);
			this->sigLit->Margin = System::Windows::Forms::Padding(2);
			this->sigLit->Name = L"sigLit";
			this->sigLit->Size = System::Drawing::Size(13, 12);
			this->sigLit->TabIndex = 17;
			this->sigLit->UseVisualStyleBackColor = true;
			// 
			// nsaLit
			// 
			this->nsaLit->AutoSize = true;
			this->nsaLit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->nsaLit->Location = System::Drawing::Point(172, 215);
			this->nsaLit->Margin = System::Windows::Forms::Padding(2);
			this->nsaLit->Name = L"nsaLit";
			this->nsaLit->Size = System::Drawing::Size(13, 12);
			this->nsaLit->TabIndex = 15;
			this->nsaLit->UseVisualStyleBackColor = true;
			// 
			// msaLit
			// 
			this->msaLit->AutoSize = true;
			this->msaLit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->msaLit->Location = System::Drawing::Point(172, 195);
			this->msaLit->Margin = System::Windows::Forms::Padding(2);
			this->msaLit->Name = L"msaLit";
			this->msaLit->Size = System::Drawing::Size(13, 12);
			this->msaLit->TabIndex = 13;
			this->msaLit->UseVisualStyleBackColor = true;
			// 
			// indLit
			// 
			this->indLit->AutoSize = true;
			this->indLit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->indLit->Location = System::Drawing::Point(172, 174);
			this->indLit->Margin = System::Windows::Forms::Padding(2);
			this->indLit->Name = L"indLit";
			this->indLit->Size = System::Drawing::Size(13, 12);
			this->indLit->TabIndex = 11;
			this->indLit->UseVisualStyleBackColor = true;
			// 
			// frqLit
			// 
			this->frqLit->AutoSize = true;
			this->frqLit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->frqLit->Location = System::Drawing::Point(172, 154);
			this->frqLit->Margin = System::Windows::Forms::Padding(2);
			this->frqLit->Name = L"frqLit";
			this->frqLit->Size = System::Drawing::Size(13, 12);
			this->frqLit->TabIndex = 9;
			this->frqLit->UseVisualStyleBackColor = true;
			// 
			// frkLit
			// 
			this->frkLit->AutoSize = true;
			this->frkLit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->frkLit->Location = System::Drawing::Point(172, 134);
			this->frkLit->Margin = System::Windows::Forms::Padding(2);
			this->frkLit->Name = L"frkLit";
			this->frkLit->Size = System::Drawing::Size(13, 12);
			this->frkLit->TabIndex = 7;
			this->frkLit->UseVisualStyleBackColor = true;
			// 
			// clrLit
			// 
			this->clrLit->AutoSize = true;
			this->clrLit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->clrLit->Location = System::Drawing::Point(172, 114);
			this->clrLit->Margin = System::Windows::Forms::Padding(2);
			this->clrLit->Name = L"clrLit";
			this->clrLit->Size = System::Drawing::Size(13, 12);
			this->clrLit->TabIndex = 5;
			this->clrLit->UseVisualStyleBackColor = true;
			// 
			// carLit
			// 
			this->carLit->AutoSize = true;
			this->carLit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->carLit->Location = System::Drawing::Point(172, 94);
			this->carLit->Margin = System::Windows::Forms::Padding(2);
			this->carLit->Name = L"carLit";
			this->carLit->Size = System::Drawing::Size(13, 12);
			this->carLit->TabIndex = 3;
			this->carLit->UseVisualStyleBackColor = true;
			// 
			// bobLit
			// 
			this->bobLit->AutoSize = true;
			this->bobLit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bobLit->Location = System::Drawing::Point(172, 74);
			this->bobLit->Margin = System::Windows::Forms::Padding(2);
			this->bobLit->Name = L"bobLit";
			this->bobLit->Size = System::Drawing::Size(13, 12);
			this->bobLit->TabIndex = 1;
			this->bobLit->UseVisualStyleBackColor = true;
			// 
			// trnExists
			// 
			this->trnExists->AutoSize = true;
			this->trnExists->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->trnExists->Location = System::Drawing::Point(122, 275);
			this->trnExists->Margin = System::Windows::Forms::Padding(2);
			this->trnExists->Name = L"trnExists";
			this->trnExists->Size = System::Drawing::Size(47, 17);
			this->trnExists->TabIndex = 20;
			this->trnExists->Text = L"TRN";
			this->trnExists->UseVisualStyleBackColor = true;
			// 
			// sndExists
			// 
			this->sndExists->AutoSize = true;
			this->sndExists->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->sndExists->Location = System::Drawing::Point(122, 255);
			this->sndExists->Margin = System::Windows::Forms::Padding(2);
			this->sndExists->Name = L"sndExists";
			this->sndExists->Size = System::Drawing::Size(47, 17);
			this->sndExists->TabIndex = 18;
			this->sndExists->Text = L"SND";
			this->sndExists->UseVisualStyleBackColor = true;
			// 
			// sigExists
			// 
			this->sigExists->AutoSize = true;
			this->sigExists->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->sigExists->Location = System::Drawing::Point(122, 235);
			this->sigExists->Margin = System::Windows::Forms::Padding(2);
			this->sigExists->Name = L"sigExists";
			this->sigExists->Size = System::Drawing::Size(42, 17);
			this->sigExists->TabIndex = 16;
			this->sigExists->Text = L"SIG";
			this->sigExists->UseVisualStyleBackColor = true;
			// 
			// nsaExists
			// 
			this->nsaExists->AutoSize = true;
			this->nsaExists->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->nsaExists->Location = System::Drawing::Point(122, 215);
			this->nsaExists->Margin = System::Windows::Forms::Padding(2);
			this->nsaExists->Name = L"nsaExists";
			this->nsaExists->Size = System::Drawing::Size(46, 17);
			this->nsaExists->TabIndex = 14;
			this->nsaExists->Text = L"NSA";
			this->nsaExists->UseVisualStyleBackColor = true;
			// 
			// msaExists
			// 
			this->msaExists->AutoSize = true;
			this->msaExists->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->msaExists->Location = System::Drawing::Point(122, 195);
			this->msaExists->Margin = System::Windows::Forms::Padding(2);
			this->msaExists->Name = L"msaExists";
			this->msaExists->Size = System::Drawing::Size(47, 17);
			this->msaExists->TabIndex = 12;
			this->msaExists->Text = L"MSA";
			this->msaExists->UseVisualStyleBackColor = true;
			// 
			// indExists
			// 
			this->indExists->AutoSize = true;
			this->indExists->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->indExists->Location = System::Drawing::Point(122, 174);
			this->indExists->Margin = System::Windows::Forms::Padding(2);
			this->indExists->Name = L"indExists";
			this->indExists->Size = System::Drawing::Size(43, 17);
			this->indExists->TabIndex = 10;
			this->indExists->Text = L"IND";
			this->indExists->UseVisualStyleBackColor = true;
			// 
			// frqExists
			// 
			this->frqExists->AutoSize = true;
			this->frqExists->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->frqExists->Location = System::Drawing::Point(122, 154);
			this->frqExists->Margin = System::Windows::Forms::Padding(2);
			this->frqExists->Name = L"frqExists";
			this->frqExists->Size = System::Drawing::Size(46, 17);
			this->frqExists->TabIndex = 8;
			this->frqExists->Text = L"FRQ";
			this->frqExists->UseVisualStyleBackColor = true;
			// 
			// frkExists
			// 
			this->frkExists->AutoSize = true;
			this->frkExists->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->frkExists->Location = System::Drawing::Point(122, 134);
			this->frkExists->Margin = System::Windows::Forms::Padding(2);
			this->frkExists->Name = L"frkExists";
			this->frkExists->Size = System::Drawing::Size(45, 17);
			this->frkExists->TabIndex = 6;
			this->frkExists->Text = L"FRK";
			this->frkExists->UseVisualStyleBackColor = true;
			// 
			// clrExists
			// 
			this->clrExists->AutoSize = true;
			this->clrExists->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->clrExists->Location = System::Drawing::Point(122, 114);
			this->clrExists->Margin = System::Windows::Forms::Padding(2);
			this->clrExists->Name = L"clrExists";
			this->clrExists->Size = System::Drawing::Size(45, 17);
			this->clrExists->TabIndex = 4;
			this->clrExists->Text = L"CLR";
			this->clrExists->UseVisualStyleBackColor = true;
			// 
			// carExists
			// 
			this->carExists->AutoSize = true;
			this->carExists->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->carExists->Location = System::Drawing::Point(122, 94);
			this->carExists->Margin = System::Windows::Forms::Padding(2);
			this->carExists->Name = L"carExists";
			this->carExists->Size = System::Drawing::Size(46, 17);
			this->carExists->TabIndex = 2;
			this->carExists->Text = L"CAR";
			this->carExists->UseVisualStyleBackColor = true;
			// 
			// bobExists
			// 
			this->bobExists->AutoSize = true;
			this->bobExists->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bobExists->Location = System::Drawing::Point(122, 74);
			this->bobExists->Margin = System::Windows::Forms::Padding(2);
			this->bobExists->Name = L"bobExists";
			this->bobExists->Size = System::Drawing::Size(46, 17);
			this->bobExists->TabIndex = 0;
			this->bobExists->Text = L"BOB";
			this->bobExists->UseVisualStyleBackColor = true;
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(129, 297);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 22;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &IndicatorUpdate::exitButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelButton->Location = System::Drawing::Point(254, 298);
			this->cancelButton->Margin = System::Windows::Forms::Padding(2);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(55, 21);
			this->cancelButton->TabIndex = 23;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &IndicatorUpdate::cancelButton_Click);
			// 
			// IndicatorUpdate
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(325, 328);
			this->ControlBox = false;
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->indicatorsPrompt);
			this->Controls->Add(this->litLabel);
			this->Controls->Add(this->existsLabel);
			this->Controls->Add(this->trnLit);
			this->Controls->Add(this->sndLit);
			this->Controls->Add(this->sigLit);
			this->Controls->Add(this->nsaLit);
			this->Controls->Add(this->msaLit);
			this->Controls->Add(this->indLit);
			this->Controls->Add(this->frqLit);
			this->Controls->Add(this->frkLit);
			this->Controls->Add(this->clrLit);
			this->Controls->Add(this->carLit);
			this->Controls->Add(this->bobLit);
			this->Controls->Add(this->trnExists);
			this->Controls->Add(this->sndExists);
			this->Controls->Add(this->sigExists);
			this->Controls->Add(this->nsaExists);
			this->Controls->Add(this->msaExists);
			this->Controls->Add(this->indExists);
			this->Controls->Add(this->frqExists);
			this->Controls->Add(this->frkExists);
			this->Controls->Add(this->clrExists);
			this->Controls->Add(this->carExists);
			this->Controls->Add(this->bobExists);
			this->Controls->Add(this->exitButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"IndicatorUpdate";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Indicator Update";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/**
		* Store the states of all inputs in an array, then pass to global variable that processes indicators
		* @param None
		* @return None
		*/
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Labeler indicators[11];
		if (bobExists->Checked) indicators[0].text = "BOB"; else indicators[0].text = "DNE";
		if (bobLit->Checked) indicators[0].light = true; else indicators[0].light = false;

		if (carExists->Checked) indicators[1].text = "CAR"; else indicators[1].text = "DNE";
		if (carLit->Checked) indicators[1].light = true; else indicators[1].light = false;

		if (clrExists->Checked) indicators[2].text = "CLR"; else indicators[2].text = "DNE";
		if (clrLit->Checked) indicators[2].light = true; else indicators[2].light = false;

		if (frkExists->Checked) indicators[3].text = "FRK"; else indicators[3].text = "DNE";
		if (frkLit->Checked) indicators[3].light = true; else indicators[3].light = false;

		if (frqExists->Checked) indicators[4].text = "FRQ"; else indicators[4].text = "DNE";
		if (frqLit->Checked) indicators[4].light = true; else indicators[4].light = false;

		if (indExists->Checked) indicators[5].text = "IND"; else indicators[5].text = "DNE";
		if (indLit->Checked) indicators[5].light = true; else indicators[5].light = false;

		if (msaExists->Checked) indicators[6].text = "MSA"; else indicators[6].text = "DNE";
		if (msaLit->Checked) indicators[6].light = true; else indicators[6].light = false;

		if (nsaExists->Checked) indicators[7].text = "NSA"; else indicators[7].text = "DNE";
		if (nsaLit->Checked) indicators[7].light = true; else indicators[7].light = false;

		if (sigExists->Checked) indicators[8].text = "SIG"; else indicators[8].text = "DNE";
		if (sigLit->Checked) indicators[8].light = true; else indicators[8].light = false;

		if (sndExists->Checked) indicators[9].text = "SND"; else indicators[9].text = "DNE";
		if (sndLit->Checked) indicators[9].light = true; else indicators[9].light = false;

		if (trnExists->Checked) indicators[10].text = "TRN"; else indicators[10].text = "DNE";
		if (trnLit->Checked) indicators[10].light = true; else indicators[10].light = false;
		CurrentIndicators.indicatorUpdate(indicators);
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
	//CurrentIndicators.indicatorReset();
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
		bobExists->Checked = false;
		bobLit->Checked = false;
		carExists->Checked = false;
		carLit->Checked = false;
		clrExists->Checked = false;
		clrLit->Checked = false;
		frkExists->Checked = false;
		frkLit->Checked = false;
		frqExists->Checked = false;
		frqLit->Checked = false;
		indExists->Checked = false;
		indLit->Checked = false;
		msaExists->Checked = false;
		msaLit->Checked = false;
		nsaExists->Checked = false;
		nsaLit->Checked = false;
		sigExists->Checked = false;
		sigLit->Checked = false;
		sndExists->Checked = false;
		sndLit->Checked = false;
		trnExists->Checked = false;
		trnLit->Checked = false;
	 }
};
}
