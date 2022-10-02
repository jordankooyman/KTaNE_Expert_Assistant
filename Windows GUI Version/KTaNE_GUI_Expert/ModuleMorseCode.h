/**********************************************************
   file: ModuleMorseCode.h
 author: Jordan Kooyman and Bradley Walby
purpose: Contains the Morse Code module window and the calculations for decripting morse code (with error correction) as member functions
Original logic written by Bradley, ported to this program by Jordan
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
	/// Summary for ModuleMorseCode
	/// </summary>
	public ref class ModuleMorseCode : public System::Windows::Forms::Form
	{
	public:
		ModuleMorseCode(void)
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
		~ModuleMorseCode()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ exitButton;
	protected:
	private: System::Windows::Forms::Button^ calcButton;
	private: System::Windows::Forms::MaskedTextBox^ morseInput;

	private: System::Windows::Forms::Label^ promptLabel;
	private: System::Windows::Forms::Button^ resetButton;
    private: System::Windows::Forms::Label^ ref1;
    private: System::Windows::Forms::Label^ ref2;


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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModuleMorseCode::typeid));
            this->exitButton = (gcnew System::Windows::Forms::Button());
            this->calcButton = (gcnew System::Windows::Forms::Button());
            this->morseInput = (gcnew System::Windows::Forms::MaskedTextBox());
            this->promptLabel = (gcnew System::Windows::Forms::Label());
            this->resetButton = (gcnew System::Windows::Forms::Button());
            this->ref1 = (gcnew System::Windows::Forms::Label());
            this->ref2 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // exitButton
            // 
            this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->exitButton->Location = System::Drawing::Point(294, 208);
            this->exitButton->Margin = System::Windows::Forms::Padding(2);
            this->exitButton->Name = L"exitButton";
            this->exitButton->Size = System::Drawing::Size(55, 21);
            this->exitButton->TabIndex = 12;
            this->exitButton->Text = L"Done";
            this->exitButton->UseVisualStyleBackColor = true;
            this->exitButton->Click += gcnew System::EventHandler(this, &ModuleMorseCode::exitButton_Click);
            // 
            // calcButton
            // 
            this->calcButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->calcButton->Location = System::Drawing::Point(146, 192);
            this->calcButton->Margin = System::Windows::Forms::Padding(2);
            this->calcButton->Name = L"calcButton";
            this->calcButton->Size = System::Drawing::Size(68, 25);
            this->calcButton->TabIndex = 11;
            this->calcButton->Text = L"Calculate";
            this->calcButton->UseVisualStyleBackColor = true;
            this->calcButton->Click += gcnew System::EventHandler(this, &ModuleMorseCode::calcButton_Click);
            // 
            // morseInput
            // 
            this->morseInput->AsciiOnly = true;
            this->morseInput->Location = System::Drawing::Point(115, 160);
            this->morseInput->Mask = L">AAAAAAAAAAaaaaaaaaa";
            this->morseInput->Name = L"morseInput";
            this->morseInput->Size = System::Drawing::Size(130, 20);
            this->morseInput->TabIndex = 13;
            this->morseInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // promptLabel
            // 
            this->promptLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->promptLabel->Location = System::Drawing::Point(1, 0);
            this->promptLabel->Name = L"promptLabel";
            this->promptLabel->Size = System::Drawing::Size(359, 157);
            this->promptLabel->TabIndex = 14;
            this->promptLabel->Text = L"Please Enter the Morse Code string using letters for dot and numbers for dash";
            this->promptLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // resetButton
            // 
            this->resetButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->resetButton->Location = System::Drawing::Point(12, 208);
            this->resetButton->Margin = System::Windows::Forms::Padding(2);
            this->resetButton->Name = L"resetButton";
            this->resetButton->Size = System::Drawing::Size(55, 21);
            this->resetButton->TabIndex = 23;
            this->resetButton->Text = L"Reset";
            this->resetButton->UseVisualStyleBackColor = true;
            this->resetButton->Click += gcnew System::EventHandler(this, &ModuleMorseCode::resetButton_Click);
            // 
            // ref1
            // 
            this->ref1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->ref1->Location = System::Drawing::Point(9, 93);
            this->ref1->Name = L"ref1";
            this->ref1->Size = System::Drawing::Size(152, 64);
            this->ref1->TabIndex = 24;
            this->ref1->Text = L"Please Enter the Morse Code string using letters for dot and numbers for dash";
            this->ref1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            this->ref1->Visible = false;
            // 
            // ref2
            // 
            this->ref2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->ref2->Location = System::Drawing::Point(167, 94);
            this->ref2->Name = L"ref2";
            this->ref2->Size = System::Drawing::Size(160, 63);
            this->ref2->TabIndex = 25;
            this->ref2->Text = L"Please Enter the Morse Code string using letters for dot and numbers for dash";
            this->ref2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            this->ref2->Visible = false;
            // 
            // ModuleMorseCode
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(360, 235);
            this->Controls->Add(this->resetButton);
            this->Controls->Add(this->promptLabel);
            this->Controls->Add(this->morseInput);
            this->Controls->Add(this->exitButton);
            this->Controls->Add(this->calcButton);
            this->Controls->Add(this->ref2);
            this->Controls->Add(this->ref1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"ModuleMorseCode";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Morse Code";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
private:
    int morse_compare(string input, string comparator, int lb, int ub) { // Compares arg input against arg comparator within the indexes lowerbound and upperbound (inclusive) and returns match
        int diff_tally = 0;
        for (int i = lb; i <= ub; i++) {
            if (input[i] != comparator[i]) {
                diff_tally++;
            }
        }
        return diff_tally;
    }
    void array_flip(int int_arr[], string str_arr[], int index1, int index2) {
        int temp_int = int_arr[index1];
        string temp_str = str_arr[index1];
        int_arr[index1] = int_arr[index2];
        str_arr[index1] = str_arr[index2];
        int_arr[index2] = temp_int;
        str_arr[index2] = temp_str;
        return;
    }
    void bubble_sort(int arr[], string stg[], int length) {
        for (int i = 0; i < length - 2; i++) {
            for (int j = 0; j < length - 2; j++) {
                if (arr[i] > arr[i + 1]) {
                    array_flip(arr, stg, i, (i + 1));
                }
            }
        }
    }
    void Morse(string input) {
        //String Morse Answers-   Shells                Halls               Slick              Trick           Boxes             Leaks           Strobe            Bistro             Flick               Bombs              Break           Brick              Steak        Sting         Vector             Beats
        //Frequencies-            3.505                 3.515               3.522              3.532           3.535             3.542           3.545             3.552              3.555               3.565              3.572           3.572              3.582        3.592         3.595              3.600
        string StrKeywords[16] = { "1111111112111211111","11111212111211111","1111211112121212","2121112121212","211122221121111","1211112212111","111212122221111","2111111112121222","11211211112121212","2111222222111111","2111121112212","2111121112121212","1112112212","11121121221","1112121212222121","21111122111" };
        __int64 IntKeywords[16] = { 1111111112111211111 , 11111212111211111 , 1111211112121212 , 2121112121212 , 211122221121111 , 1211112212111 , 111212122221111 , 2111111112121222 , 11211211112121212 , 2111222222111111 , 2111121112212 , 2111121112121212 , 1112112212 , 11121121221 , 1112121212222121 , 21111122111 };
        string morse = input;

        switch (morse.length()) {

            /*
             *   Matches can be in the following categories-
             *  -Unique Length, no other code shares the total length
             *  -Perfect, the entire input was correct
             *  -Main Window, the primary window search found a perfect and unique match
             *  -Scdy. Window, the secondary window search found a perfect and unique match
             *  -Error, prints matches from least to most erronious (with error count)
             */

        case 10:
            promptLabel->Text += "Unique Length Match: Steak - 3.582";
            break;
        case 19:
            promptLabel->Text += "Unique Length Match: Shells - 3.505";
            break;
        case 17:
            if (morse == StrKeywords[1]) {
                promptLabel->Text += "Perfect Match: Halls - 3.515";
            }
            else if (morse == StrKeywords[8]) {
                promptLabel->Text += "Perfect Match: Flick - 3.555";
            }
            else {
                if (morse_compare(morse, StrKeywords[1], 10, 16) == 0) {
                    promptLabel->Text += "Main Window Match: Halls - 3.515";
                }
                else if (morse_compare(morse, StrKeywords[8], 10, 16) == 0) {
                    promptLabel->Text += "Main Window Match: Flick - 3.555";
                }
                else {
                    if (morse_compare(morse, StrKeywords[1], 2, 7) == 0) {
                        promptLabel->Text += "Secondary Window Match: Halls - 3.515";
                    }
                    else if (morse_compare(morse, StrKeywords[8], 2, 7) == 0) {
                        promptLabel->Text += "Secondary Window Match: Flick- 3.555";
                    }
                    else {
                        int error_tally[2] = { morse_compare(morse, StrKeywords[1], 0, 16), morse_compare(morse, StrKeywords[8], 0, 16) };
                        string error_str[2] = { "Halls", "Flick" };
                        if (error_tally[0] < error_tally[1]) {
                            promptLabel->Text += System::Convert::ToString(error_tally[0]) + " Errors, Halls - 3.515: " + System::Convert::ToString(error_tally[1]) + " Errors, Flick- 3.555";
                        }
                        else {
                            promptLabel->Text += System::Convert::ToString(error_tally[1]) + " Errors, Flick - 3.555: " + System::Convert::ToString(error_tally[0]) + " Errors, Halls- 3.515";
                        }
                    }
                }
            }
            break;
        case 16:
            if (morse == StrKeywords[2]) {
                promptLabel->Text += "Perfect Match: Slick - 3.522";
            }
            else if (morse == StrKeywords[7]) {
                promptLabel->Text += "Perfect Match: Bistro - 3.552";
            }
            else if (morse == StrKeywords[9]) {
                promptLabel->Text += "Perfect Match: Bombs - 3.565";
            }
            else if (morse == StrKeywords[11]) {
                promptLabel->Text += "Perfect Match: Brick - 3.572";
            }
            else if (morse == StrKeywords[14]) {
                promptLabel->Text += "Perfect Match: Vector - 3.595";
            }
            else {
                if (morse_compare(morse, StrKeywords[2], 0, 8) == 0) {
                    promptLabel->Text += "Main Window Match: Slick - 3.522";
                }
                else if (morse_compare(morse, StrKeywords[7], 0, 8) == 0) {
                    promptLabel->Text += "Main Window Match: Bistro - 3.552";
                }
                else if (morse_compare(morse, StrKeywords[9], 0, 8) == 0) {
                    promptLabel->Text += "Main Window Match: Bombs - 3.565";
                }
                else if (morse_compare(morse, StrKeywords[11], 0, 8) == 0) {
                    promptLabel->Text += "Main Window Match: Brick - 3.575";
                }
                else if (morse_compare(morse, StrKeywords[14], 0, 8) == 0) {
                    promptLabel->Text += "Main Window Match: Vector - 3.595";
                }
                else {
                    if (morse_compare(morse, StrKeywords[2], 10, 15) == 0) {
                        promptLabel->Text += "Secondary Window Match: Slick - 3.522";
                    }
                    else if (morse_compare(morse, StrKeywords[7], 10, 15) == 0) {
                        promptLabel->Text += "Secondary Window Match: Bistro - 3.552";
                    }
                    else if (morse_compare(morse, StrKeywords[9], 10, 15) == 0) {
                        promptLabel->Text += "Secondary Window Match: Bombs - 3.565";
                    }
                    else if (morse_compare(morse, StrKeywords[11], 10, 15) == 0) {
                        promptLabel->Text += "Secondary Window Match: Brick - 3.575";
                    }
                    else if (morse_compare(morse, StrKeywords[14], 10, 15) == 0) {
                        promptLabel->Text += "Secondary Window Match: Vector - 3.595";
                    }
                    else {
                        int err_arr[5] = { morse_compare(morse, StrKeywords[2], 0, 15),
                                           morse_compare(morse, StrKeywords[7], 0, 15),
                                           morse_compare(morse, StrKeywords[9], 0, 15),
                                           morse_compare(morse, StrKeywords[11], 0, 15),
                                           morse_compare(morse, StrKeywords[14], 0, 15) };
                        string str_err[5] = { "Slick - 3.522","Bistro - 3.552","Bombs - 3.565","Brick - 3.575","Vector - 3.595" };
                        bubble_sort(err_arr, str_err, 5);
                        for (int i = 0; i < 5; i++) {
                            promptLabel->Text += System::Convert::ToString(err_arr[i]) + " Errors, " + gcnew String(str_err[i].data()) + "\n";
                        }
                    }
                }
            }
            break;
        case 15:
            if (morse == StrKeywords[4]) {
                promptLabel->Text += "Perfect Match: Boxes - 3.535";
            }
            else if (morse == StrKeywords[6]) {
                promptLabel->Text += "Perfect Match: Strobe - 3.545";
            }
            else {
                if (morse_compare(morse, StrKeywords[4], 3, 10) == 0) {
                    promptLabel->Text += "Main Window Match: Boxes - 3.535";
                }
                else if (morse_compare(morse, StrKeywords[6], 3, 10) == 0) {
                    promptLabel->Text += "Main Window Match: Strobe - 3.545";
                }
                else {
                    if (morse_compare(morse, StrKeywords[4], 0, 3) == 0) {
                        promptLabel->Text += "Secondary Window Match: Boxes - 3.535";
                    }
                    else if (morse_compare(morse, StrKeywords[6], 0, 3) == 0) {
                        promptLabel->Text += "Secondary Window Match: Strobe- 3.545";
                    }
                    else {
                        int err_arr[2] = { morse_compare(morse, StrKeywords[4], 0, 3),morse_compare(morse, StrKeywords[6], 0, 3) };
                        string str_arr[2] = { "Boxes - 3.535", "Strobe - 3.545" };
                        bubble_sort(err_arr, str_arr, 2);
                        for (int i = 0; i < 2; i++) {
                            promptLabel->Text += System::Convert::ToString(err_arr[i]) + " Errors, " + gcnew String(str_arr[i].c_str()) + "\n";
                        }
                    }
                }
            }
            break;
        case 13:
            if (morse == StrKeywords[3]) {
                promptLabel->Text += "Perfect Match: Trick - 3.532";
            }
            else if (morse == StrKeywords[5]) {
                promptLabel->Text += "Perfect Match: Leaks - 3.542";
            }
            else if (morse == StrKeywords[10]) {
                promptLabel->Text += "Perfect Match: Break - 3.572";
            }
            else {
                if (morse_compare(morse, StrKeywords[3], 5, 10) == 0) {
                    promptLabel->Text += "Main Window Match: Trick - 3.532";
                }
                else if (morse_compare(morse, StrKeywords[5], 5, 10) == 0) {
                    promptLabel->Text += "Main Window Match: Leaks - 3.542";
                }
                else if (morse_compare(morse, StrKeywords[10], 5, 10) == 0) {
                    promptLabel->Text += "Main Window Match: Break - 3.542";
                }
                else {
                    if (morse_compare(morse, StrKeywords[3], 0, 2) == 0) {
                        promptLabel->Text += "Secondary Window Match: Trick - 3.532";
                    }
                    else if (morse_compare(morse, StrKeywords[5], 0, 2) == 0) {
                        promptLabel->Text += "Secondary Window Match: Leaks - 3.542";
                    }
                    else if (morse_compare(morse, StrKeywords[10], 0, 2) == 0) {
                        promptLabel->Text += "Secondary Window Match: Break - 3.542";
                    }
                    else {
                        int err_arr[3] = { morse_compare(morse, StrKeywords[3], 0, 12), morse_compare(morse, StrKeywords[5], 0, 12), morse_compare(morse, StrKeywords[10], 0, 12) };
                        string str_arr[3] = { "Trick - 3.532", "Leaks - 3.542", "Break - 3.572" };
                        bubble_sort(err_arr, str_arr, 3);
                        for (int i = 0; i < 3; i++) {
                            promptLabel->Text += System::Convert::ToString(err_arr[i]) + " Errors, " + gcnew String(str_arr[i].c_str()) + "\n";
                        }
                    }
                }
            }
            break;
        case 11:
            if (morse == StrKeywords[13]) {
                promptLabel->Text += "Perfect Match: Sting - 3.592";
            }
            else if (morse == StrKeywords[15]) {
                promptLabel->Text += "Perfect Match: Beats - 3.600";
            }
            else {
                if (morse_compare(morse, StrKeywords[13], 6, 9) == 0) {
                    promptLabel->Text += "Main Window Match: Sting - 3.592";
                }
                else if (morse_compare(morse, StrKeywords[15], 6, 9) == 0) {
                    promptLabel->Text += "Main Window Match: Beats - 3.600";
                }
                else {
                    if (morse_compare(morse, StrKeywords[13], 0, 3 == 0)) {
                        promptLabel->Text += "Secondary Window Match: Sting - 3.592";
                    }
                    else if (morse_compare(morse, StrKeywords[15], 0, 3) == 0) {
                        promptLabel->Text += "Secondary Window Match: Beats - 3.600";
                    }
                    else {
                        int err_arr[2] = { morse_compare(morse, StrKeywords[13], 0, 10), morse_compare(morse, StrKeywords[15], 0, 10) };
                        string str_arr[2] = { "Sting - 3.592", "Beats - 3.600" };
                        bubble_sort(err_arr, str_arr, 2);
                        for (int i = 0; i < 2; i++) {
                            promptLabel->Text += System::Convert::ToString(err_arr[i]) + " Errors, " + gcnew String(str_arr[i].c_str()) + "\n";
                        }
                    }
                }
            }
            break;
        default:
            int length = input.length();
            if (length <= 9 || length >= 20) {
                promptLabel->Text = "Error detected, invalid length, exiting";
                return;
            }
            string str1;
            for (int i = 0; i < length - 1; i++) {
                str1[i] = input[i];
            }
            Morse(str1);
            string str2 = input + "0";
            Morse(str2);
            break;
        }

        // If output is small enough, enlarge for better readability
        if (promptLabel->Text->Length < 100)
        {
            promptLabel->Font = ref2->Font;
        }
    }
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void calcButton_Click(System::Object^ sender, System::EventArgs^ e) {
    promptLabel->Text = "";
    promptLabel->Font = ref1->Font;
    std::string ConvertedInput = "";

    // Convert System::String letters to std::string 1s (dots) and System::String numbers to std::string 2s (dashes)
    for (int i = 0; i < morseInput->Text->Length; i++)
    {
        if (morseInput->Text[i] >= 65 && morseInput->Text[i] <= 90) // Uppercase Letter (input forced to uppercase in textbox)
        { // Dot
            ConvertedInput += '1';
        }
        else if (morseInput->Text[i] >= 48 && morseInput->Text[i] <= 57) // Number
        { // Dash
            ConvertedInput += '2';
        }
        else // Otherwise, error message (should never occur, mask is alphanumeric only)
        {
            System::Windows::Forms::MessageBox::Show("Symbols cannot be interpreted", "Error");
            return;
        }
    }

    Morse(ConvertedInput);
}
private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	morseInput->Text = "";
    promptLabel->Text = "Please Enter the Morse Code string using letters for dot and numbers for dash";
    promptLabel->Font = ref2->Font;
}
};
}
