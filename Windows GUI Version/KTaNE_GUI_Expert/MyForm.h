/**********************************************************
   file: MyForm.h
 author: Jordan Kooyman
purpose: Contains main menu window and all member functions of the main menu
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
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ simpleWiresModule;

	protected:

	protected:


	private: System::Windows::Forms::Button^ buttonModule;
	private: System::Windows::Forms::Button^ simonModule;
	private: System::Windows::Forms::Button^ keypadModule;





	private: System::Windows::Forms::Button^ whosOnFirstModule;

	private: System::Windows::Forms::Button^ complicatedWiresModule;
	private: System::Windows::Forms::Button^ wireSequenceModule;


	private: System::Windows::Forms::Button^ morseModule;

	private: System::Windows::Forms::Button^ mazeModule;
	private: System::Windows::Forms::Button^ memoryModule;



	private: System::Windows::Forms::Button^ passwordModule;
	private: System::Windows::Forms::Button^ knobsModule;




	private: System::Windows::Forms::Label^ serialNumLabel;
	private: System::Windows::Forms::Label^ batteriesLabel;


	private: System::Windows::Forms::Label^ portsLabel;

	private: System::Windows::Forms::Label^ indicatorsLabel;

	private: System::Windows::Forms::Label^ serialNum;
	private: System::Windows::Forms::Label^ dCellLabel;




	private: System::Windows::Forms::Label^ serialLabel;
	private: System::Windows::Forms::Label^ parallelLabel;
	private: System::Windows::Forms::Label^ aaLabel;
	private: System::Windows::Forms::Label^ totalLabel;




	private: System::Windows::Forms::Label^ dvidLabel;
	private: System::Windows::Forms::Label^ ps2Label;
	private: System::Windows::Forms::Label^ rj45Label;
	private: System::Windows::Forms::Label^ rcaLabel;






	private: System::Windows::Forms::Label^ totalCount;

	private: System::Windows::Forms::Label^ aaCount;
	private: System::Windows::Forms::Label^ dCellCount;



	private: System::Windows::Forms::Label^ rcaStatus;

	private: System::Windows::Forms::Label^ rj45Status;

	private: System::Windows::Forms::Label^ ps2Status;

	private: System::Windows::Forms::Label^ dvidStatus;

	private: System::Windows::Forms::Label^ parallelStatus;

	private: System::Windows::Forms::Label^ serialStatus;
private: System::Windows::Forms::Button^ updatePorts;
private: System::Windows::Forms::Button^ updateSerialNumber;


private: System::Windows::Forms::Button^ updateBatteries;

private: System::Windows::Forms::Button^ updateIndicators;

private: System::Windows::Forms::Label^ bobIndicatorStatus;
private: System::Windows::Forms::Label^ carIndicatorStatus;
private: System::Windows::Forms::Label^ clrIndicatorStatus;
private: System::Windows::Forms::Label^ frkIndicatorStatus;
private: System::Windows::Forms::Label^ frqIndicatorStatus;
private: System::Windows::Forms::Label^ indIndicatorStatus;
private: System::Windows::Forms::Label^ msaIndicatorStatus;
private: System::Windows::Forms::Label^ nsaIndicatorStatus;
private: System::Windows::Forms::Label^ sigIndicatorStatus;
private: System::Windows::Forms::Label^ sndIndicatorStatus;
private: System::Windows::Forms::Label^ trnIndicatorStatus;
private: System::Windows::Forms::Label^ promptLabel;
private: System::Windows::Forms::Button^ newBomb;



	   //public event EventHandler Shown;

	public:
		void Update()
		{
			// Color variables - changes the colors used for all Bomb Constant outputs
			const Color DNE = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192))); // Indicator Only
			const Color Unlit = System::Drawing::Color::Black; // Used in most functions, default case color
			const Color Lit = System::Drawing::Color::DarkGoldenrod; // Indicator Only
			const Color Undefined = System::Drawing::SystemColors::Control; // Disabled color (same as backgroud)
			const Color Good = System::Drawing::Color::Green; // Port Only
			const Color Bad = System::Drawing::Color::Red; // Port Only
			int state;

			// Port Output Text Variables
			System::String^ GoodStatus = "Yes";
			System::String^ BadStatus = "No";

			// Check that all needed Indicator information is available (but do not request input)
			if (CurrentIndicators.indicatorValid())
			{
				// Update Indicator Display 
				state = CurrentIndicators.indicatorCheck("CAR");
				if (!(state - 1))
					this->carIndicatorStatus->ForeColor = Unlit;
				else if (!(state - 2))
					this->carIndicatorStatus->ForeColor = Lit;
				else
					this->carIndicatorStatus->ForeColor = DNE;
				//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(state), "Debug1");
				state = CurrentIndicators.indicatorCheck("BOB");
				if (!(state - 1))
					this->bobIndicatorStatus->ForeColor = Unlit;
				else if (!(state - 2))
					this->bobIndicatorStatus->ForeColor = Lit;
				else
					this->bobIndicatorStatus->ForeColor = DNE;
				//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(state), "Debug2");
				state = CurrentIndicators.indicatorCheck("CLR");
				if (!(state - 1))
					this->clrIndicatorStatus->ForeColor = Unlit;
				else if (!(state - 2))
					this->clrIndicatorStatus->ForeColor = Lit;
				else
					this->clrIndicatorStatus->ForeColor = DNE;
				//System::Windows::Forms::MessageBox::Show("3", "Debug");
				state = CurrentIndicators.indicatorCheck("FRK");
				if (!(state - 1))
					this->frkIndicatorStatus->ForeColor = Unlit;
				else if (!(state - 2))
					this->frkIndicatorStatus->ForeColor = Lit;
				else
					this->frkIndicatorStatus->ForeColor = DNE;
				//System::Windows::Forms::MessageBox::Show("4", "Debug");
				state = CurrentIndicators.indicatorCheck("FRQ");
				if (!(state - 1))
					this->frqIndicatorStatus->ForeColor = Unlit;
				else if (!(state - 2))
					this->frqIndicatorStatus->ForeColor = Lit;
				else
					this->frqIndicatorStatus->ForeColor = DNE;

				state = CurrentIndicators.indicatorCheck("IND");
				if (!(state - 1))
					this->indIndicatorStatus->ForeColor = Unlit;
				else if (!(state - 2))
					this->indIndicatorStatus->ForeColor = Lit;
				else
					this->indIndicatorStatus->ForeColor = DNE;

				state = CurrentIndicators.indicatorCheck("MSA");
				if (!(state - 1))
					this->msaIndicatorStatus->ForeColor = Unlit;
				else if (!(state - 2))
					this->msaIndicatorStatus->ForeColor = Lit;
				else
					this->msaIndicatorStatus->ForeColor = DNE;

				state = CurrentIndicators.indicatorCheck("NSA");
				if (!(state - 1))
					this->nsaIndicatorStatus->ForeColor = Unlit;
				else if (!(state - 2))
					this->nsaIndicatorStatus->ForeColor = Lit;
				else
					this->nsaIndicatorStatus->ForeColor = DNE;

				state = CurrentIndicators.indicatorCheck("SIG");
				if (!(state - 1))
					this->sigIndicatorStatus->ForeColor = Unlit;
				else if (!(state - 2))
					this->sigIndicatorStatus->ForeColor = Lit;
				else
					this->sigIndicatorStatus->ForeColor = DNE;

				state = CurrentIndicators.indicatorCheck("SND");
				if (!(state - 1))
					this->sndIndicatorStatus->ForeColor = Unlit;
				else if (!(state - 2))
					this->sndIndicatorStatus->ForeColor = Lit;
				else
					this->sndIndicatorStatus->ForeColor = DNE;

				state = CurrentIndicators.indicatorCheck("TRN");
				if (!(state - 1))
					this->trnIndicatorStatus->ForeColor = Unlit;
				else if (!(state - 2))
					this->trnIndicatorStatus->ForeColor = Lit;
				else
					this->trnIndicatorStatus->ForeColor = DNE;
				//System::Windows::Forms::MessageBox::Show("8", "Debug");
			}
			else
			{
				bobIndicatorStatus->ForeColor = Undefined;
				carIndicatorStatus->ForeColor = Undefined;
				clrIndicatorStatus->ForeColor = Undefined;
				frkIndicatorStatus->ForeColor = Undefined;
				frqIndicatorStatus->ForeColor = Undefined;
				indIndicatorStatus->ForeColor = Undefined;
				msaIndicatorStatus->ForeColor = Undefined;
				nsaIndicatorStatus->ForeColor = Undefined;
				sigIndicatorStatus->ForeColor = Undefined;
				sndIndicatorStatus->ForeColor = Undefined;
				trnIndicatorStatus->ForeColor = Undefined;
			}

			// Update Port Display
			if (CurrentPorts.portsValid())
			{
				if (CurrentPorts.portsCheck(0))
				{
					serialStatus->Text = GoodStatus;
					serialStatus->ForeColor = Good;
				}	
				else
				{
					serialStatus->Text = BadStatus;
					serialStatus->ForeColor = Bad;
				}

				if (CurrentPorts.portsCheck(1))
				{
					parallelStatus->Text = GoodStatus;
					parallelStatus->ForeColor = Good;
				}
				else
				{
					parallelStatus->Text = BadStatus;
					parallelStatus->ForeColor = Bad;
				}

				if (CurrentPorts.portsCheck(2))
				{
					dvidStatus->Text = GoodStatus;
					dvidStatus->ForeColor = Good;
				}
				else
				{
					dvidStatus->Text = BadStatus;
					dvidStatus->ForeColor = Bad;
				}

				if (CurrentPorts.portsCheck(3))
				{
					ps2Status->Text = GoodStatus;
					ps2Status->ForeColor = Good;
				}
				else
				{
					ps2Status->Text = BadStatus;
					ps2Status->ForeColor = Bad;
				}

				if (CurrentPorts.portsCheck(4))
				{
					rj45Status->Text = GoodStatus;
					rj45Status->ForeColor = Good;
				}
				else
				{
					rj45Status->Text = BadStatus;
					rj45Status->ForeColor = Bad;
				}

				if (CurrentPorts.portsCheck(5))
				{
					rcaStatus->Text = GoodStatus;
					rcaStatus->ForeColor = Good;
				}
				else
				{
					rcaStatus->Text = BadStatus;
					rcaStatus->ForeColor = Bad;
				}
			}
			else
			{
				serialStatus->ForeColor = Undefined;
				parallelStatus->ForeColor = Undefined;
				dvidStatus->ForeColor = Undefined;
				ps2Status->ForeColor = Undefined;
				rj45Status->ForeColor = Undefined;
				rcaStatus->ForeColor = Undefined;
			}

			// Update Batteries Display
			if (CurrentBatteries.batteriesValid())
			{
				dCellCount->ForeColor = Unlit;
				aaCount->ForeColor = Unlit;
				totalCount->ForeColor = Unlit;

				dCellCount->Text = System::Convert::ToString(CurrentBatteries.batteriesCheck(1));
				aaCount->Text = System::Convert::ToString(CurrentBatteries.batteriesCheck(0));
				totalCount->Text = System::Convert::ToString(CurrentBatteries.batteriesCheck(2));
			}
			else
			{
				dCellCount->ForeColor = Undefined;
				aaCount->ForeColor = Undefined;
				totalCount->ForeColor = Undefined;
			}

			// Update Serial Display
			if (CurrentSerial.serialValid())
			{
				char Serial[7];
				for (int i = 0; i < 6; i++) { Serial[i] = CurrentSerial.serialCheck(i); }
				Serial[6] = '\0';
				serialNum->ForeColor = Unlit;
				serialNum->Text = gcnew String(Serial);
			}
			else
			{
				serialNum->ForeColor = Undefined;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->simpleWiresModule = (gcnew System::Windows::Forms::Button());
			this->buttonModule = (gcnew System::Windows::Forms::Button());
			this->simonModule = (gcnew System::Windows::Forms::Button());
			this->keypadModule = (gcnew System::Windows::Forms::Button());
			this->whosOnFirstModule = (gcnew System::Windows::Forms::Button());
			this->complicatedWiresModule = (gcnew System::Windows::Forms::Button());
			this->wireSequenceModule = (gcnew System::Windows::Forms::Button());
			this->morseModule = (gcnew System::Windows::Forms::Button());
			this->mazeModule = (gcnew System::Windows::Forms::Button());
			this->memoryModule = (gcnew System::Windows::Forms::Button());
			this->passwordModule = (gcnew System::Windows::Forms::Button());
			this->knobsModule = (gcnew System::Windows::Forms::Button());
			this->serialNumLabel = (gcnew System::Windows::Forms::Label());
			this->batteriesLabel = (gcnew System::Windows::Forms::Label());
			this->portsLabel = (gcnew System::Windows::Forms::Label());
			this->indicatorsLabel = (gcnew System::Windows::Forms::Label());
			this->serialNum = (gcnew System::Windows::Forms::Label());
			this->dCellLabel = (gcnew System::Windows::Forms::Label());
			this->serialLabel = (gcnew System::Windows::Forms::Label());
			this->parallelLabel = (gcnew System::Windows::Forms::Label());
			this->aaLabel = (gcnew System::Windows::Forms::Label());
			this->totalLabel = (gcnew System::Windows::Forms::Label());
			this->dvidLabel = (gcnew System::Windows::Forms::Label());
			this->ps2Label = (gcnew System::Windows::Forms::Label());
			this->rj45Label = (gcnew System::Windows::Forms::Label());
			this->rcaLabel = (gcnew System::Windows::Forms::Label());
			this->totalCount = (gcnew System::Windows::Forms::Label());
			this->aaCount = (gcnew System::Windows::Forms::Label());
			this->dCellCount = (gcnew System::Windows::Forms::Label());
			this->rcaStatus = (gcnew System::Windows::Forms::Label());
			this->rj45Status = (gcnew System::Windows::Forms::Label());
			this->ps2Status = (gcnew System::Windows::Forms::Label());
			this->dvidStatus = (gcnew System::Windows::Forms::Label());
			this->parallelStatus = (gcnew System::Windows::Forms::Label());
			this->serialStatus = (gcnew System::Windows::Forms::Label());
			this->updatePorts = (gcnew System::Windows::Forms::Button());
			this->updateSerialNumber = (gcnew System::Windows::Forms::Button());
			this->updateBatteries = (gcnew System::Windows::Forms::Button());
			this->updateIndicators = (gcnew System::Windows::Forms::Button());
			this->bobIndicatorStatus = (gcnew System::Windows::Forms::Label());
			this->carIndicatorStatus = (gcnew System::Windows::Forms::Label());
			this->clrIndicatorStatus = (gcnew System::Windows::Forms::Label());
			this->frkIndicatorStatus = (gcnew System::Windows::Forms::Label());
			this->frqIndicatorStatus = (gcnew System::Windows::Forms::Label());
			this->indIndicatorStatus = (gcnew System::Windows::Forms::Label());
			this->msaIndicatorStatus = (gcnew System::Windows::Forms::Label());
			this->nsaIndicatorStatus = (gcnew System::Windows::Forms::Label());
			this->sigIndicatorStatus = (gcnew System::Windows::Forms::Label());
			this->sndIndicatorStatus = (gcnew System::Windows::Forms::Label());
			this->trnIndicatorStatus = (gcnew System::Windows::Forms::Label());
			this->newBomb = (gcnew System::Windows::Forms::Button());
			this->promptLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// simpleWiresModule
			// 
			this->simpleWiresModule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->simpleWiresModule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->simpleWiresModule->Location = System::Drawing::Point(23, 85);
			this->simpleWiresModule->Name = L"simpleWiresModule";
			this->simpleWiresModule->Size = System::Drawing::Size(141, 27);
			this->simpleWiresModule->TabIndex = 0;
			this->simpleWiresModule->Text = L"Simple Wires";
			this->simpleWiresModule->UseVisualStyleBackColor = true;
			this->simpleWiresModule->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// buttonModule
			// 
			this->buttonModule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonModule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->buttonModule->Location = System::Drawing::Point(168, 85);
			this->buttonModule->Margin = System::Windows::Forms::Padding(2);
			this->buttonModule->Name = L"buttonModule";
			this->buttonModule->Size = System::Drawing::Size(141, 27);
			this->buttonModule->TabIndex = 1;
			this->buttonModule->Text = L"Button";
			this->buttonModule->UseVisualStyleBackColor = true;
			this->buttonModule->Click += gcnew System::EventHandler(this, &MyForm::buttonModule_Click);
			// 
			// simonModule
			// 
			this->simonModule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->simonModule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->simonModule->Location = System::Drawing::Point(459, 85);
			this->simonModule->Margin = System::Windows::Forms::Padding(2);
			this->simonModule->Name = L"simonModule";
			this->simonModule->Size = System::Drawing::Size(141, 27);
			this->simonModule->TabIndex = 3;
			this->simonModule->Text = L"Simon Says";
			this->simonModule->UseVisualStyleBackColor = true;
			this->simonModule->Click += gcnew System::EventHandler(this, &MyForm::simonModule_Click);
			// 
			// keypadModule
			// 
			this->keypadModule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->keypadModule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->keypadModule->Location = System::Drawing::Point(313, 85);
			this->keypadModule->Margin = System::Windows::Forms::Padding(2);
			this->keypadModule->Name = L"keypadModule";
			this->keypadModule->Size = System::Drawing::Size(141, 27);
			this->keypadModule->TabIndex = 2;
			this->keypadModule->Text = L"Keypad (Symbols)";
			this->keypadModule->UseVisualStyleBackColor = true;
			this->keypadModule->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// whosOnFirstModule
			// 
			this->whosOnFirstModule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->whosOnFirstModule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->whosOnFirstModule->Location = System::Drawing::Point(23, 127);
			this->whosOnFirstModule->Margin = System::Windows::Forms::Padding(2);
			this->whosOnFirstModule->Name = L"whosOnFirstModule";
			this->whosOnFirstModule->Size = System::Drawing::Size(141, 27);
			this->whosOnFirstModule->TabIndex = 4;
			this->whosOnFirstModule->Text = L"Who\'s on First";
			this->whosOnFirstModule->UseVisualStyleBackColor = true;
			this->whosOnFirstModule->Click += gcnew System::EventHandler(this, &MyForm::whosOnFirstModule_Click);
			// 
			// complicatedWiresModule
			// 
			this->complicatedWiresModule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->complicatedWiresModule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->complicatedWiresModule->Location = System::Drawing::Point(459, 127);
			this->complicatedWiresModule->Margin = System::Windows::Forms::Padding(2);
			this->complicatedWiresModule->Name = L"complicatedWiresModule";
			this->complicatedWiresModule->Size = System::Drawing::Size(141, 27);
			this->complicatedWiresModule->TabIndex = 7;
			this->complicatedWiresModule->Text = L"Complicated Wires";
			this->complicatedWiresModule->UseVisualStyleBackColor = true;
			this->complicatedWiresModule->Click += gcnew System::EventHandler(this, &MyForm::complicatedWiresModule_Click);
			// 
			// wireSequenceModule
			// 
			this->wireSequenceModule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->wireSequenceModule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->wireSequenceModule->Location = System::Drawing::Point(23, 170);
			this->wireSequenceModule->Margin = System::Windows::Forms::Padding(2);
			this->wireSequenceModule->Name = L"wireSequenceModule";
			this->wireSequenceModule->Size = System::Drawing::Size(141, 27);
			this->wireSequenceModule->TabIndex = 8;
			this->wireSequenceModule->Text = L"Wire Sequence";
			this->wireSequenceModule->UseVisualStyleBackColor = true;
			this->wireSequenceModule->Click += gcnew System::EventHandler(this, &MyForm::wireSequenceModule_Click);
			// 
			// morseModule
			// 
			this->morseModule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->morseModule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->morseModule->Location = System::Drawing::Point(313, 127);
			this->morseModule->Margin = System::Windows::Forms::Padding(2);
			this->morseModule->Name = L"morseModule";
			this->morseModule->Size = System::Drawing::Size(141, 27);
			this->morseModule->TabIndex = 6;
			this->morseModule->Text = L"Morse Code";
			this->morseModule->UseVisualStyleBackColor = true;
			this->morseModule->Click += gcnew System::EventHandler(this, &MyForm::morseModule_Click);
			// 
			// mazeModule
			// 
			this->mazeModule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mazeModule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->mazeModule->Location = System::Drawing::Point(168, 170);
			this->mazeModule->Margin = System::Windows::Forms::Padding(2);
			this->mazeModule->Name = L"mazeModule";
			this->mazeModule->Size = System::Drawing::Size(141, 27);
			this->mazeModule->TabIndex = 9;
			this->mazeModule->Text = L"Maze";
			this->mazeModule->UseVisualStyleBackColor = true;
			this->mazeModule->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// memoryModule
			// 
			this->memoryModule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->memoryModule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->memoryModule->Location = System::Drawing::Point(168, 127);
			this->memoryModule->Margin = System::Windows::Forms::Padding(2);
			this->memoryModule->Name = L"memoryModule";
			this->memoryModule->Size = System::Drawing::Size(141, 27);
			this->memoryModule->TabIndex = 5;
			this->memoryModule->Text = L"Memory";
			this->memoryModule->UseVisualStyleBackColor = true;
			this->memoryModule->Click += gcnew System::EventHandler(this, &MyForm::memoryModule_Click);
			// 
			// passwordModule
			// 
			this->passwordModule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->passwordModule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordModule->Location = System::Drawing::Point(313, 170);
			this->passwordModule->Margin = System::Windows::Forms::Padding(2);
			this->passwordModule->Name = L"passwordModule";
			this->passwordModule->Size = System::Drawing::Size(141, 27);
			this->passwordModule->TabIndex = 10;
			this->passwordModule->Text = L"Password";
			this->passwordModule->UseVisualStyleBackColor = true;
			this->passwordModule->Click += gcnew System::EventHandler(this, &MyForm::passwordModule_Click);
			// 
			// knobsModule
			// 
			this->knobsModule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->knobsModule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->knobsModule->Location = System::Drawing::Point(459, 170);
			this->knobsModule->Margin = System::Windows::Forms::Padding(2);
			this->knobsModule->Name = L"knobsModule";
			this->knobsModule->Size = System::Drawing::Size(141, 27);
			this->knobsModule->TabIndex = 11;
			this->knobsModule->Text = L"Knobs";
			this->knobsModule->UseVisualStyleBackColor = true;
			this->knobsModule->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// serialNumLabel
			// 
			this->serialNumLabel->AutoSize = true;
			this->serialNumLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->serialNumLabel->Location = System::Drawing::Point(53, 216);
			this->serialNumLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->serialNumLabel->Name = L"serialNumLabel";
			this->serialNumLabel->Size = System::Drawing::Size(109, 20);
			this->serialNumLabel->TabIndex = 15;
			this->serialNumLabel->Text = L"Serial Number";
			this->serialNumLabel->Click += gcnew System::EventHandler(this, &MyForm::serialNumLabel_Click);
			// 
			// batteriesLabel
			// 
			this->batteriesLabel->AutoSize = true;
			this->batteriesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->batteriesLabel->Location = System::Drawing::Point(71, 281);
			this->batteriesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->batteriesLabel->Name = L"batteriesLabel";
			this->batteriesLabel->Size = System::Drawing::Size(73, 20);
			this->batteriesLabel->TabIndex = 16;
			this->batteriesLabel->Text = L"Batteries";
			// 
			// portsLabel
			// 
			this->portsLabel->AutoSize = true;
			this->portsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->portsLabel->Location = System::Drawing::Point(250, 216);
			this->portsLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->portsLabel->Name = L"portsLabel";
			this->portsLabel->Size = System::Drawing::Size(46, 20);
			this->portsLabel->TabIndex = 17;
			this->portsLabel->Text = L"Ports";
			// 
			// indicatorsLabel
			// 
			this->indicatorsLabel->AutoSize = true;
			this->indicatorsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->indicatorsLabel->Location = System::Drawing::Point(395, 216);
			this->indicatorsLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->indicatorsLabel->Name = L"indicatorsLabel";
			this->indicatorsLabel->Size = System::Drawing::Size(79, 20);
			this->indicatorsLabel->TabIndex = 18;
			this->indicatorsLabel->Text = L"Indicators";
			// 
			// serialNum
			// 
			this->serialNum->AutoSize = true;
			this->serialNum->ForeColor = System::Drawing::Color::Black;
			this->serialNum->Location = System::Drawing::Point(80, 240);
			this->serialNum->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->serialNum->Name = L"serialNum";
			this->serialNum->Size = System::Drawing::Size(53, 13);
			this->serialNum->TabIndex = 19;
			this->serialNum->Text = L"serialNum";
			// 
			// dCellLabel
			// 
			this->dCellLabel->AutoSize = true;
			this->dCellLabel->Location = System::Drawing::Point(58, 308);
			this->dCellLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->dCellLabel->Name = L"dCellLabel";
			this->dCellLabel->Size = System::Drawing::Size(38, 13);
			this->dCellLabel->TabIndex = 20;
			this->dCellLabel->Text = L"D Cell:";
			// 
			// serialLabel
			// 
			this->serialLabel->AutoSize = true;
			this->serialLabel->Location = System::Drawing::Point(237, 240);
			this->serialLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->serialLabel->Name = L"serialLabel";
			this->serialLabel->Size = System::Drawing::Size(36, 13);
			this->serialLabel->TabIndex = 21;
			this->serialLabel->Text = L"Serial:";
			// 
			// parallelLabel
			// 
			this->parallelLabel->AutoSize = true;
			this->parallelLabel->Location = System::Drawing::Point(230, 256);
			this->parallelLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->parallelLabel->Name = L"parallelLabel";
			this->parallelLabel->Size = System::Drawing::Size(44, 13);
			this->parallelLabel->TabIndex = 22;
			this->parallelLabel->Text = L"Parallel:";
			// 
			// aaLabel
			// 
			this->aaLabel->AutoSize = true;
			this->aaLabel->Location = System::Drawing::Point(71, 324);
			this->aaLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->aaLabel->Name = L"aaLabel";
			this->aaLabel->Size = System::Drawing::Size(24, 13);
			this->aaLabel->TabIndex = 23;
			this->aaLabel->Text = L"AA:";
			// 
			// totalLabel
			// 
			this->totalLabel->AutoSize = true;
			this->totalLabel->Location = System::Drawing::Point(63, 339);
			this->totalLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->totalLabel->Name = L"totalLabel";
			this->totalLabel->Size = System::Drawing::Size(34, 13);
			this->totalLabel->TabIndex = 24;
			this->totalLabel->Text = L"Total:";
			// 
			// dvidLabel
			// 
			this->dvidLabel->AutoSize = true;
			this->dvidLabel->Location = System::Drawing::Point(234, 272);
			this->dvidLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->dvidLabel->Name = L"dvidLabel";
			this->dvidLabel->Size = System::Drawing::Size(39, 13);
			this->dvidLabel->TabIndex = 25;
			this->dvidLabel->Text = L"DVI-D:";
			// 
			// ps2Label
			// 
			this->ps2Label->AutoSize = true;
			this->ps2Label->Location = System::Drawing::Point(241, 287);
			this->ps2Label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ps2Label->Name = L"ps2Label";
			this->ps2Label->Size = System::Drawing::Size(35, 13);
			this->ps2Label->TabIndex = 26;
			this->ps2Label->Text = L"PS/2:";
			// 
			// rj45Label
			// 
			this->rj45Label->AutoSize = true;
			this->rj45Label->Location = System::Drawing::Point(235, 303);
			this->rj45Label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->rj45Label->Name = L"rj45Label";
			this->rj45Label->Size = System::Drawing::Size(38, 13);
			this->rj45Label->TabIndex = 27;
			this->rj45Label->Text = L"RJ-45:";
			// 
			// rcaLabel
			// 
			this->rcaLabel->AutoSize = true;
			this->rcaLabel->Location = System::Drawing::Point(207, 318);
			this->rcaLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->rcaLabel->Name = L"rcaLabel";
			this->rcaLabel->Size = System::Drawing::Size(66, 13);
			this->rcaLabel->TabIndex = 28;
			this->rcaLabel->Text = L"Stereo RCA:";
			// 
			// totalCount
			// 
			this->totalCount->AutoSize = true;
			this->totalCount->ForeColor = System::Drawing::Color::Black;
			this->totalCount->Location = System::Drawing::Point(97, 339);
			this->totalCount->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->totalCount->Name = L"totalCount";
			this->totalCount->Size = System::Drawing::Size(55, 13);
			this->totalCount->TabIndex = 32;
			this->totalCount->Text = L"totalCount";
			// 
			// aaCount
			// 
			this->aaCount->AutoSize = true;
			this->aaCount->ForeColor = System::Drawing::Color::Black;
			this->aaCount->Location = System::Drawing::Point(97, 323);
			this->aaCount->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->aaCount->Name = L"aaCount";
			this->aaCount->Size = System::Drawing::Size(47, 13);
			this->aaCount->TabIndex = 31;
			this->aaCount->Text = L"aaCount";
			// 
			// dCellCount
			// 
			this->dCellCount->AutoSize = true;
			this->dCellCount->ForeColor = System::Drawing::Color::Black;
			this->dCellCount->Location = System::Drawing::Point(97, 307);
			this->dCellCount->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->dCellCount->Name = L"dCellCount";
			this->dCellCount->Size = System::Drawing::Size(58, 13);
			this->dCellCount->TabIndex = 30;
			this->dCellCount->Text = L"dCellCount";
			// 
			// rcaStatus
			// 
			this->rcaStatus->AutoSize = true;
			this->rcaStatus->ForeColor = System::Drawing::Color::Black;
			this->rcaStatus->Location = System::Drawing::Point(275, 318);
			this->rcaStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->rcaStatus->Name = L"rcaStatus";
			this->rcaStatus->Size = System::Drawing::Size(52, 13);
			this->rcaStatus->TabIndex = 38;
			this->rcaStatus->Text = L"rcaStatus";
			// 
			// rj45Status
			// 
			this->rj45Status->AutoSize = true;
			this->rj45Status->ForeColor = System::Drawing::Color::Black;
			this->rj45Status->Location = System::Drawing::Point(275, 303);
			this->rj45Status->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->rj45Status->Name = L"rj45Status";
			this->rj45Status->Size = System::Drawing::Size(54, 13);
			this->rj45Status->TabIndex = 37;
			this->rj45Status->Text = L"rj45Status";
			// 
			// ps2Status
			// 
			this->ps2Status->AutoSize = true;
			this->ps2Status->ForeColor = System::Drawing::Color::Black;
			this->ps2Status->Location = System::Drawing::Point(275, 287);
			this->ps2Status->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ps2Status->Name = L"ps2Status";
			this->ps2Status->Size = System::Drawing::Size(54, 13);
			this->ps2Status->TabIndex = 36;
			this->ps2Status->Text = L"ps2Status";
			// 
			// dvidStatus
			// 
			this->dvidStatus->AutoSize = true;
			this->dvidStatus->ForeColor = System::Drawing::Color::Black;
			this->dvidStatus->Location = System::Drawing::Point(275, 272);
			this->dvidStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->dvidStatus->Name = L"dvidStatus";
			this->dvidStatus->Size = System::Drawing::Size(57, 13);
			this->dvidStatus->TabIndex = 35;
			this->dvidStatus->Text = L"dvidStatus";
			// 
			// parallelStatus
			// 
			this->parallelStatus->AutoSize = true;
			this->parallelStatus->ForeColor = System::Drawing::Color::Black;
			this->parallelStatus->Location = System::Drawing::Point(275, 256);
			this->parallelStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->parallelStatus->Name = L"parallelStatus";
			this->parallelStatus->Size = System::Drawing::Size(70, 13);
			this->parallelStatus->TabIndex = 34;
			this->parallelStatus->Text = L"parallelStatus";
			// 
			// serialStatus
			// 
			this->serialStatus->AutoSize = true;
			this->serialStatus->ForeColor = System::Drawing::Color::Black;
			this->serialStatus->Location = System::Drawing::Point(275, 240);
			this->serialStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->serialStatus->Name = L"serialStatus";
			this->serialStatus->Size = System::Drawing::Size(61, 13);
			this->serialStatus->TabIndex = 33;
			this->serialStatus->Text = L"serialStatus";
			// 
			// updatePorts
			// 
			this->updatePorts->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->updatePorts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->updatePorts->Location = System::Drawing::Point(237, 351);
			this->updatePorts->Margin = System::Windows::Forms::Padding(2);
			this->updatePorts->Name = L"updatePorts";
			this->updatePorts->Size = System::Drawing::Size(65, 27);
			this->updatePorts->TabIndex = 14;
			this->updatePorts->Text = L"Update";
			this->updatePorts->UseVisualStyleBackColor = true;
			this->updatePorts->Click += gcnew System::EventHandler(this, &MyForm::updatePorts_Click);
			// 
			// updateSerialNumber
			// 
			this->updateSerialNumber->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->updateSerialNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->updateSerialNumber->Location = System::Drawing::Point(74, 256);
			this->updateSerialNumber->Margin = System::Windows::Forms::Padding(2);
			this->updateSerialNumber->Name = L"updateSerialNumber";
			this->updateSerialNumber->Size = System::Drawing::Size(65, 27);
			this->updateSerialNumber->TabIndex = 12;
			this->updateSerialNumber->Text = L"Update";
			this->updateSerialNumber->UseVisualStyleBackColor = true;
			this->updateSerialNumber->Click += gcnew System::EventHandler(this, &MyForm::updateSerialNumber_Click);
			// 
			// updateBatteries
			// 
			this->updateBatteries->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->updateBatteries->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->updateBatteries->Location = System::Drawing::Point(75, 351);
			this->updateBatteries->Margin = System::Windows::Forms::Padding(2);
			this->updateBatteries->Name = L"updateBatteries";
			this->updateBatteries->Size = System::Drawing::Size(65, 27);
			this->updateBatteries->TabIndex = 13;
			this->updateBatteries->Text = L"Update";
			this->updateBatteries->UseVisualStyleBackColor = true;
			this->updateBatteries->Click += gcnew System::EventHandler(this, &MyForm::updateBatteries_Click);
			// 
			// updateIndicators
			// 
			this->updateIndicators->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->updateIndicators->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->updateIndicators->Location = System::Drawing::Point(399, 351);
			this->updateIndicators->Margin = System::Windows::Forms::Padding(2);
			this->updateIndicators->Name = L"updateIndicators";
			this->updateIndicators->Size = System::Drawing::Size(65, 27);
			this->updateIndicators->TabIndex = 15;
			this->updateIndicators->Text = L"Update";
			this->updateIndicators->UseVisualStyleBackColor = true;
			this->updateIndicators->Click += gcnew System::EventHandler(this, &MyForm::updateIndicators_Click);
			// 
			// bobIndicatorStatus
			// 
			this->bobIndicatorStatus->AutoSize = true;
			this->bobIndicatorStatus->ForeColor = System::Drawing::Color::Black;
			this->bobIndicatorStatus->Location = System::Drawing::Point(404, 242);
			this->bobIndicatorStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->bobIndicatorStatus->Name = L"bobIndicatorStatus";
			this->bobIndicatorStatus->Size = System::Drawing::Size(29, 13);
			this->bobIndicatorStatus->TabIndex = 43;
			this->bobIndicatorStatus->Text = L"BOB";
			// 
			// carIndicatorStatus
			// 
			this->carIndicatorStatus->AutoSize = true;
			this->carIndicatorStatus->ForeColor = System::Drawing::Color::Black;
			this->carIndicatorStatus->Location = System::Drawing::Point(404, 263);
			this->carIndicatorStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->carIndicatorStatus->Name = L"carIndicatorStatus";
			this->carIndicatorStatus->Size = System::Drawing::Size(29, 13);
			this->carIndicatorStatus->TabIndex = 44;
			this->carIndicatorStatus->Text = L"CAR";
			// 
			// clrIndicatorStatus
			// 
			this->clrIndicatorStatus->AutoSize = true;
			this->clrIndicatorStatus->ForeColor = System::Drawing::Color::Black;
			this->clrIndicatorStatus->Location = System::Drawing::Point(404, 283);
			this->clrIndicatorStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->clrIndicatorStatus->Name = L"clrIndicatorStatus";
			this->clrIndicatorStatus->Size = System::Drawing::Size(28, 13);
			this->clrIndicatorStatus->TabIndex = 45;
			this->clrIndicatorStatus->Text = L"CLR";
			// 
			// frkIndicatorStatus
			// 
			this->frkIndicatorStatus->AutoSize = true;
			this->frkIndicatorStatus->ForeColor = System::Drawing::Color::Black;
			this->frkIndicatorStatus->Location = System::Drawing::Point(404, 303);
			this->frkIndicatorStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->frkIndicatorStatus->Name = L"frkIndicatorStatus";
			this->frkIndicatorStatus->Size = System::Drawing::Size(28, 13);
			this->frkIndicatorStatus->TabIndex = 46;
			this->frkIndicatorStatus->Text = L"FRK";
			// 
			// frqIndicatorStatus
			// 
			this->frqIndicatorStatus->AutoSize = true;
			this->frqIndicatorStatus->ForeColor = System::Drawing::Color::Black;
			this->frqIndicatorStatus->Location = System::Drawing::Point(404, 323);
			this->frqIndicatorStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->frqIndicatorStatus->Name = L"frqIndicatorStatus";
			this->frqIndicatorStatus->Size = System::Drawing::Size(29, 13);
			this->frqIndicatorStatus->TabIndex = 47;
			this->frqIndicatorStatus->Text = L"FRQ";
			// 
			// indIndicatorStatus
			// 
			this->indIndicatorStatus->AutoSize = true;
			this->indIndicatorStatus->ForeColor = System::Drawing::Color::Black;
			this->indIndicatorStatus->Location = System::Drawing::Point(437, 242);
			this->indIndicatorStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->indIndicatorStatus->Name = L"indIndicatorStatus";
			this->indIndicatorStatus->Size = System::Drawing::Size(26, 13);
			this->indIndicatorStatus->TabIndex = 48;
			this->indIndicatorStatus->Text = L"IND";
			// 
			// msaIndicatorStatus
			// 
			this->msaIndicatorStatus->AutoSize = true;
			this->msaIndicatorStatus->ForeColor = System::Drawing::Color::Black;
			this->msaIndicatorStatus->Location = System::Drawing::Point(437, 259);
			this->msaIndicatorStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->msaIndicatorStatus->Name = L"msaIndicatorStatus";
			this->msaIndicatorStatus->Size = System::Drawing::Size(30, 13);
			this->msaIndicatorStatus->TabIndex = 49;
			this->msaIndicatorStatus->Text = L"MSA";
			// 
			// nsaIndicatorStatus
			// 
			this->nsaIndicatorStatus->AutoSize = true;
			this->nsaIndicatorStatus->ForeColor = System::Drawing::Color::Black;
			this->nsaIndicatorStatus->Location = System::Drawing::Point(437, 276);
			this->nsaIndicatorStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->nsaIndicatorStatus->Name = L"nsaIndicatorStatus";
			this->nsaIndicatorStatus->Size = System::Drawing::Size(29, 13);
			this->nsaIndicatorStatus->TabIndex = 50;
			this->nsaIndicatorStatus->Text = L"NSA";
			// 
			// sigIndicatorStatus
			// 
			this->sigIndicatorStatus->AutoSize = true;
			this->sigIndicatorStatus->ForeColor = System::Drawing::Color::Black;
			this->sigIndicatorStatus->Location = System::Drawing::Point(437, 293);
			this->sigIndicatorStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->sigIndicatorStatus->Name = L"sigIndicatorStatus";
			this->sigIndicatorStatus->Size = System::Drawing::Size(25, 13);
			this->sigIndicatorStatus->TabIndex = 51;
			this->sigIndicatorStatus->Text = L"SIG";
			// 
			// sndIndicatorStatus
			// 
			this->sndIndicatorStatus->AutoSize = true;
			this->sndIndicatorStatus->ForeColor = System::Drawing::Color::Black;
			this->sndIndicatorStatus->Location = System::Drawing::Point(437, 310);
			this->sndIndicatorStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->sndIndicatorStatus->Name = L"sndIndicatorStatus";
			this->sndIndicatorStatus->Size = System::Drawing::Size(30, 13);
			this->sndIndicatorStatus->TabIndex = 52;
			this->sndIndicatorStatus->Text = L"SND";
			// 
			// trnIndicatorStatus
			// 
			this->trnIndicatorStatus->AutoSize = true;
			this->trnIndicatorStatus->ForeColor = System::Drawing::Color::Black;
			this->trnIndicatorStatus->Location = System::Drawing::Point(437, 327);
			this->trnIndicatorStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->trnIndicatorStatus->Name = L"trnIndicatorStatus";
			this->trnIndicatorStatus->Size = System::Drawing::Size(30, 13);
			this->trnIndicatorStatus->TabIndex = 53;
			this->trnIndicatorStatus->Text = L"TRN";
			// 
			// newBomb
			// 
			this->newBomb->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->newBomb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->newBomb->Location = System::Drawing::Point(493, 276);
			this->newBomb->Margin = System::Windows::Forms::Padding(2);
			this->newBomb->Name = L"newBomb";
			this->newBomb->Size = System::Drawing::Size(87, 27);
			this->newBomb->TabIndex = 16;
			this->newBomb->Text = L"New Bomb";
			this->newBomb->UseVisualStyleBackColor = true;
			this->newBomb->Click += gcnew System::EventHandler(this, &MyForm::newBomb_Click);
			// 
			// promptLabel
			// 
			this->promptLabel->AutoSize = true;
			this->promptLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28));
			this->promptLabel->Location = System::Drawing::Point(185, 23);
			this->promptLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->promptLabel->Name = L"promptLabel";
			this->promptLabel->Size = System::Drawing::Size(258, 44);
			this->promptLabel->TabIndex = 1;
			this->promptLabel->Text = L"Pick a Module";
			this->promptLabel->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 382);
			this->Controls->Add(this->newBomb);
			this->Controls->Add(this->trnIndicatorStatus);
			this->Controls->Add(this->sndIndicatorStatus);
			this->Controls->Add(this->sigIndicatorStatus);
			this->Controls->Add(this->nsaIndicatorStatus);
			this->Controls->Add(this->msaIndicatorStatus);
			this->Controls->Add(this->indIndicatorStatus);
			this->Controls->Add(this->frqIndicatorStatus);
			this->Controls->Add(this->frkIndicatorStatus);
			this->Controls->Add(this->clrIndicatorStatus);
			this->Controls->Add(this->carIndicatorStatus);
			this->Controls->Add(this->bobIndicatorStatus);
			this->Controls->Add(this->updateIndicators);
			this->Controls->Add(this->updateBatteries);
			this->Controls->Add(this->updateSerialNumber);
			this->Controls->Add(this->updatePorts);
			this->Controls->Add(this->rcaStatus);
			this->Controls->Add(this->rj45Status);
			this->Controls->Add(this->ps2Status);
			this->Controls->Add(this->dvidStatus);
			this->Controls->Add(this->parallelStatus);
			this->Controls->Add(this->serialStatus);
			this->Controls->Add(this->totalCount);
			this->Controls->Add(this->aaCount);
			this->Controls->Add(this->dCellCount);
			this->Controls->Add(this->rcaLabel);
			this->Controls->Add(this->rj45Label);
			this->Controls->Add(this->ps2Label);
			this->Controls->Add(this->dvidLabel);
			this->Controls->Add(this->totalLabel);
			this->Controls->Add(this->aaLabel);
			this->Controls->Add(this->parallelLabel);
			this->Controls->Add(this->serialLabel);
			this->Controls->Add(this->dCellLabel);
			this->Controls->Add(this->serialNum);
			this->Controls->Add(this->indicatorsLabel);
			this->Controls->Add(this->portsLabel);
			this->Controls->Add(this->batteriesLabel);
			this->Controls->Add(this->serialNumLabel);
			this->Controls->Add(this->knobsModule);
			this->Controls->Add(this->passwordModule);
			this->Controls->Add(this->memoryModule);
			this->Controls->Add(this->mazeModule);
			this->Controls->Add(this->morseModule);
			this->Controls->Add(this->wireSequenceModule);
			this->Controls->Add(this->complicatedWiresModule);
			this->Controls->Add(this->whosOnFirstModule);
			this->Controls->Add(this->keypadModule);
			this->Controls->Add(this->simonModule);
			this->Controls->Add(this->buttonModule);
			this->Controls->Add(this->promptLabel);
			this->Controls->Add(this->simpleWiresModule);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Keep Talking and Nobody Explodes Expert";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // Simple Wires
		ModuleSimpleWires^ wrs = gcnew ModuleSimpleWires();
		wrs->Show();
		//this->Hide();
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	ModuleKeypad^ kpd = gcnew ModuleKeypad();
	kpd->Show();
	}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	ModuleKnobs^ knbs = gcnew ModuleKnobs();
	knbs->Show();
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	ModuleMaze^ mz = gcnew ModuleMaze();
	mz->Show();
}
private: System::Void serialNumLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void updateIndicators_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	OpenWindow(1);
}
private: System::Void newBomb_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrentIndicators.indicatorReset();
	CurrentPorts.portsReset();
	CurrentBatteries.batteriesReset();
	CurrentSerial.serialReset();

	ResetForms();

	Update();
}
private: System::Void updatePorts_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	OpenWindow(2);
}
private: System::Void updateBatteries_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	OpenWindow(3);
}
private: System::Void updateSerialNumber_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	OpenWindow(4);
}
	   private: System::Void MyForm_Shown(System::Object^ sender, System::EventArgs^ e)
	   {
		   Update();
	   }
private: System::Void buttonModule_Click(System::Object^ sender, System::EventArgs^ e) {
	ModuleButton^ bttn = gcnew ModuleButton();
	bttn->Show();
}
private: System::Void simonModule_Click(System::Object^ sender, System::EventArgs^ e) {
	ModuleSimonSays^ smnss = gcnew ModuleSimonSays();
	smnss->Show();
}
private: System::Void whosOnFirstModule_Click(System::Object^ sender, System::EventArgs^ e) {
	ModuleWhosOnFirst^ whnfrst = gcnew ModuleWhosOnFirst();
	whnfrst->Show();
}
private: System::Void memoryModule_Click(System::Object^ sender, System::EventArgs^ e) {
	ModuleMemory^ mmr = gcnew ModuleMemory();
	mmr->Show();
}
private: System::Void morseModule_Click(System::Object^ sender, System::EventArgs^ e) {
	ModuleMorseCode^ mrscd = gcnew ModuleMorseCode();
	mrscd->Show();
}
private: System::Void complicatedWiresModule_Click(System::Object^ sender, System::EventArgs^ e) {
	ModuleComplicatedWires^ cmplctdwrs = gcnew ModuleComplicatedWires();
	cmplctdwrs->Show();
}
private: System::Void wireSequenceModule_Click(System::Object^ sender, System::EventArgs^ e) {
	ModuleWireSequence^ wrsqnc = gcnew ModuleWireSequence();
	wrsqnc->Show();
}
private: System::Void passwordModule_Click(System::Object^ sender, System::EventArgs^ e) {
	ModulePassword^ psswrd = gcnew ModulePassword();
	psswrd->Show();
}
};
}
