/**********************************************************
   file: PortUpdate.h
 author: Jordan Kooyman
purpose: Contains the interface to update the list of ports available on the current bomb (only 1 instance is created), passes the data back to the global object dedicated to ports
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
	/// Summary for PortUpdate
	/// </summary>
	public ref class PortUpdate : public System::Windows::Forms::Form
	{
	public:
		PortUpdate(void)
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
		~PortUpdate()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ rcaCheck;
	protected:

	private: System::Windows::Forms::CheckBox^ rj45Check;
	protected:

	private: System::Windows::Forms::CheckBox^ ps2Check;

	private: System::Windows::Forms::CheckBox^ dvidCheck;

	private: System::Windows::Forms::CheckBox^ parallelCheck;

	private: System::Windows::Forms::CheckBox^ serialCheck;
	private: System::Windows::Forms::Label^ promptLabel;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PortUpdate::typeid));
			this->rcaCheck = (gcnew System::Windows::Forms::CheckBox());
			this->rj45Check = (gcnew System::Windows::Forms::CheckBox());
			this->ps2Check = (gcnew System::Windows::Forms::CheckBox());
			this->dvidCheck = (gcnew System::Windows::Forms::CheckBox());
			this->parallelCheck = (gcnew System::Windows::Forms::CheckBox());
			this->serialCheck = (gcnew System::Windows::Forms::CheckBox());
			this->promptLabel = (gcnew System::Windows::Forms::Label());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// rcaCheck
			// 
			this->rcaCheck->AutoSize = true;
			this->rcaCheck->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->rcaCheck->Location = System::Drawing::Point(174, 83);
			this->rcaCheck->Margin = System::Windows::Forms::Padding(2);
			this->rcaCheck->Name = L"rcaCheck";
			this->rcaCheck->Size = System::Drawing::Size(80, 17);
			this->rcaCheck->TabIndex = 5;
			this->rcaCheck->Text = L"Stereo RCA";
			this->rcaCheck->UseVisualStyleBackColor = true;
			// 
			// rj45Check
			// 
			this->rj45Check->AutoSize = true;
			this->rj45Check->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->rj45Check->Location = System::Drawing::Point(174, 63);
			this->rj45Check->Margin = System::Windows::Forms::Padding(2);
			this->rj45Check->Name = L"rj45Check";
			this->rj45Check->Size = System::Drawing::Size(52, 17);
			this->rj45Check->TabIndex = 4;
			this->rj45Check->Text = L"RJ-45";
			this->rj45Check->UseVisualStyleBackColor = true;
			// 
			// ps2Check
			// 
			this->ps2Check->AutoSize = true;
			this->ps2Check->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ps2Check->Location = System::Drawing::Point(174, 43);
			this->ps2Check->Margin = System::Windows::Forms::Padding(2);
			this->ps2Check->Name = L"ps2Check";
			this->ps2Check->Size = System::Drawing::Size(49, 17);
			this->ps2Check->TabIndex = 3;
			this->ps2Check->Text = L"PS/2";
			this->ps2Check->UseVisualStyleBackColor = true;
			// 
			// dvidCheck
			// 
			this->dvidCheck->AutoSize = true;
			this->dvidCheck->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->dvidCheck->Location = System::Drawing::Point(70, 83);
			this->dvidCheck->Margin = System::Windows::Forms::Padding(2);
			this->dvidCheck->Name = L"dvidCheck";
			this->dvidCheck->Size = System::Drawing::Size(53, 17);
			this->dvidCheck->TabIndex = 2;
			this->dvidCheck->Text = L"DVI-D";
			this->dvidCheck->UseVisualStyleBackColor = true;
			// 
			// parallelCheck
			// 
			this->parallelCheck->AutoSize = true;
			this->parallelCheck->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->parallelCheck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->parallelCheck->Location = System::Drawing::Point(70, 63);
			this->parallelCheck->Margin = System::Windows::Forms::Padding(2);
			this->parallelCheck->Name = L"parallelCheck";
			this->parallelCheck->Size = System::Drawing::Size(93, 17);
			this->parallelCheck->TabIndex = 1;
			this->parallelCheck->Text = L"Parallel Port";
			this->parallelCheck->UseVisualStyleBackColor = true;
			// 
			// serialCheck
			// 
			this->serialCheck->AutoSize = true;
			this->serialCheck->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->serialCheck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->serialCheck->Location = System::Drawing::Point(70, 43);
			this->serialCheck->Margin = System::Windows::Forms::Padding(2);
			this->serialCheck->Name = L"serialCheck";
			this->serialCheck->Size = System::Drawing::Size(83, 17);
			this->serialCheck->TabIndex = 0;
			this->serialCheck->Text = L"Serial Port";
			this->serialCheck->UseVisualStyleBackColor = true;
			// 
			// promptLabel
			// 
			this->promptLabel->AutoSize = true;
			this->promptLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->promptLabel->Location = System::Drawing::Point(10, 9);
			this->promptLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->promptLabel->Name = L"promptLabel";
			this->promptLabel->Size = System::Drawing::Size(300, 20);
			this->promptLabel->TabIndex = 9;
			this->promptLabel->Text = L"Please select all ports found on the bomb";
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(134, 116);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 6;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &PortUpdate::exitButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelButton->Location = System::Drawing::Point(254, 116);
			this->cancelButton->Margin = System::Windows::Forms::Padding(2);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(55, 21);
			this->cancelButton->TabIndex = 7;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &PortUpdate::cancelButton_Click);
			// 
			// PortUpdate
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(320, 146);
			this->ControlBox = false;
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->rcaCheck);
			this->Controls->Add(this->rj45Check);
			this->Controls->Add(this->ps2Check);
			this->Controls->Add(this->dvidCheck);
			this->Controls->Add(this->parallelCheck);
			this->Controls->Add(this->serialCheck);
			this->Controls->Add(this->promptLabel);
			this->Controls->Add(this->exitButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PortUpdate";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ports Update";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/**
		* Store the states of all inputs in an array, then pass to global variable that processes ports
		* @param None
		* @return None
		*/
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		bool ports[6];
		ports[0] = serialCheck->Checked;
		ports[1] = parallelCheck->Checked;
		ports[2] = dvidCheck->Checked;
		ports[3] = ps2Check->Checked;
		ports[4] = rj45Check->Checked;
		ports[5] = rcaCheck->Checked;

		CurrentPorts.portsUpdate(ports);
		resumeCalculation();  // Check if any calculation function called for indicator update, if so, attempt that calculation again
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
		   serialCheck->Checked = false;
		   parallelCheck->Checked = false;
		   dvidCheck->Checked = false;
		   ps2Check->Checked = false;
		   rj45Check->Checked = false;
		   rcaCheck->Checked = false;
	    }
};
}
