/**********************************************************
   file: ButtonOutput.h
 author: Jordan Kooyman
purpose: Contains the output window for the button module and the a function to show one of the two possible outcomes for the button
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
	/// Summary for ButtonOutput
	/// </summary>
	public ref class ButtonOutput : public System::Windows::Forms::Form
	{
	public:
		ButtonOutput(void)
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
		~ButtonOutput()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ output1;
	protected:

	private: System::Windows::Forms::Label^ promptLabel;
	private: System::Windows::Forms::GroupBox^ output2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ colorStrip1;
	private: System::Windows::Forms::Label^ holdPrompt;
	private: System::Windows::Forms::Button^ exitButton;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ButtonOutput::typeid));
			this->output1 = (gcnew System::Windows::Forms::GroupBox());
			this->promptLabel = (gcnew System::Windows::Forms::Label());
			this->output2 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->colorStrip1 = (gcnew System::Windows::Forms::Label());
			this->holdPrompt = (gcnew System::Windows::Forms::Label());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->output1->SuspendLayout();
			this->output2->SuspendLayout();
			this->SuspendLayout();
			// 
			// output1
			// 
			this->output1->BackColor = System::Drawing::Color::Transparent;
			this->output1->Controls->Add(this->promptLabel);
			this->output1->Location = System::Drawing::Point(8, 71);
			this->output1->Name = L"output1";
			this->output1->Size = System::Drawing::Size(356, 117);
			this->output1->TabIndex = 0;
			this->output1->TabStop = false;
			this->output1->Visible = false;
			// 
			// promptLabel
			// 
			this->promptLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->promptLabel->Location = System::Drawing::Point(7, 16);
			this->promptLabel->Name = L"promptLabel";
			this->promptLabel->Size = System::Drawing::Size(342, 92);
			this->promptLabel->TabIndex = 0;
			this->promptLabel->Text = L"Click and Release Immediately";
			this->promptLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output2
			// 
			this->output2->BackColor = System::Drawing::Color::Transparent;
			this->output2->Controls->Add(this->label4);
			this->output2->Controls->Add(this->label5);
			this->output2->Controls->Add(this->label2);
			this->output2->Controls->Add(this->label3);
			this->output2->Controls->Add(this->label1);
			this->output2->Controls->Add(this->colorStrip1);
			this->output2->Controls->Add(this->holdPrompt);
			this->output2->Location = System::Drawing::Point(13, 10);
			this->output2->Name = L"output2";
			this->output2->Size = System::Drawing::Size(346, 213);
			this->output2->TabIndex = 1;
			this->output2->TabStop = false;
			this->output2->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(114, 163);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(226, 31);
			this->label4->TabIndex = 6;
			this->label4->Text = L"1 in any position";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(7, 163);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 31);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Other:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(114, 119);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(226, 31);
			this->label2->TabIndex = 4;
			this->label2->Text = L"5 in any position";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->label3->Location = System::Drawing::Point(7, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 31);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Yellow:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(114, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(226, 31);
			this->label1->TabIndex = 2;
			this->label1->Text = L"4 in any position";
			// 
			// colorStrip1
			// 
			this->colorStrip1->AutoSize = true;
			this->colorStrip1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->colorStrip1->ForeColor = System::Drawing::Color::Blue;
			this->colorStrip1->Location = System::Drawing::Point(7, 78);
			this->colorStrip1->Name = L"colorStrip1";
			this->colorStrip1->Size = System::Drawing::Size(81, 31);
			this->colorStrip1->TabIndex = 1;
			this->colorStrip1->Text = L"Blue:";
			// 
			// holdPrompt
			// 
			this->holdPrompt->AutoSize = true;
			this->holdPrompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->holdPrompt->Location = System::Drawing::Point(61, 16);
			this->holdPrompt->Name = L"holdPrompt";
			this->holdPrompt->Size = System::Drawing::Size(224, 42);
			this->holdPrompt->TabIndex = 0;
			this->holdPrompt->Text = L"Hold Button";
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Location = System::Drawing::Point(159, 229);
			this->exitButton->Margin = System::Windows::Forms::Padding(2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(55, 21);
			this->exitButton->TabIndex = 0;
			this->exitButton->Text = L"Done";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &ButtonOutput::exitButton_Click);
			// 
			// ButtonOutput
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(373, 256);
			this->Controls->Add(this->output1);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->output2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ButtonOutput";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Button Output";
			this->output1->ResumeLayout(false);
			this->output2->ResumeLayout(false);
			this->output2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
		  
		   public: void State(char mode)
		   {
			   if (mode == 1) // Click case
			   {
				   output1->Visible = true;
				   output2->Visible = false;
			   }
			   else if (mode == 2) // Hold case
			   {
				   output2->Visible = true;
				   output1->Visible = false;
			   }
		   }
};
}
