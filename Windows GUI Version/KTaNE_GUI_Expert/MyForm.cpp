/**********************************************************
   file: MyForm.cpp
 author: Jordan Kooyman
purpose: Contains main() and all global objects and functions for use between windows

Overall, the program allows for the input and solving of all the built-in bomb modules in Keep Talking and Nobody Explodes utilizing a graphical user interface, designed using Visual C++ and written in C++/CLI
Based on a command prompt application that does the same thing (written by Jordan Kooyman and Bradley Walby)
Bradley did the original logic for Keypad and Morse Code in C++, but Jordan ported them to C++/CLI. All other modules were originally written by Jordan in C++.
March 2022
**********************************************************/

const bool TextMode = false; // Sets whether images or unicode characters are used in the display grid for Keypad

#include <string>
#include <Windows.h>

// Module Window prototypes so handle types can be made for them
namespace KTaNEGUIExpert {
    ref class ModuleSimpleWires;
    ref class ModuleButton;
    ref class ModuleSimonSays;
    ref class ModuleComplicatedWires;
}

// Global Function prototypes - used for accessing data across windows or triggering actions in one window based off an event in another window
void OpenWindow(char WindowID);
void HideWindow(char WindowID);
void UpdateHome();
void pauseCalculation(KTaNEGUIExpert::ModuleSimpleWires^ input);
void pauseCalculation(KTaNEGUIExpert::ModuleButton^ input);
void pauseCalculation(KTaNEGUIExpert::ModuleSimonSays^ input);
void pauseCalculation(KTaNEGUIExpert::ModuleComplicatedWires^ input);
void resumeCalculation();
void ResetForms();

// Indicator Storage Structure
class Labeler
{
public:
    std::string text = "";
    bool light = false;
};

// Bomb Constant Storage and Function Classes
class Indicator
{
private:
    Labeler indicators[11];
    bool loaded;
public:
    Indicator(void) // Default Constructor
    {
        loaded = false;
    }

    /** 
    * Marks the stored indicator information as outdated
    * @param None
    * @return None
    **/
    void indicatorReset()
    {
        loaded = false;
        OpenWindow(0);
    }

    /**
    * Returns whether or not the indicators have been input for the current bomb
    * @param None
    * @return Boolean value: true - indicators can be checked   false - indicators must be input before check
    **/
    bool indicatorValid()
    {
        return loaded;
    }

    /**
    * Stores the recieved input array into the static storage of the class
    * @param Array of 11 elements of Labeler type that contains the indicator tags and light statuses
    * @return None
    **/
    void indicatorUpdate(Labeler inputs[11])
    {
        loaded = true;
        for (int i = 0; i < 11; i++)
        {
            indicators[i].text = inputs[i].text;
            indicators[i].light = inputs[i].light;
        }
    }

    /**
    * Determine if there is a matching indicator to the tag specified
    * @param std::string representing the indicator label
    * @return Whether or not an indicator with the given tag exists, and whether it is lit up or not (0 - Not found, 1 - Found unlit, 2 - Found lit, -1 - Invalid Information Available)
    **/
    int indicatorCheck(std::string tag) // 
    {
        // Find a match to the tag input
        if (!loaded)
        {
            //Output.Show("Indicator data not found, please input");
            OpenWindow(1);
            return -1;
            // pause execution of this function until input is entered
        }
        for (int j = 0; j < 11; j++) // Search the array for a match
        {
            if (indicators[j].text == tag) // Match found
                return indicators[j].light + 1; // return 1 for unlit, 2 for lit
        }
        return 0; // return 0 for no match in search
    }
};

class Ports
{
private:
    bool port[6];
    bool loaded;
public:
    Ports(void) // Default Constructor
    {
        loaded = false;
    }
    /**
    * Recieves ports information from window to be stored for later use
    * @param Boolean Array of size 6, port order: 0 - Serial  1 - Parallel  2 - DVI-D  3 - PS/2  4 - RJ-45  5 - Stereo RCA
    * @return None
    **/
    void portsUpdate(bool input[6])
    {
        for (int i = 0; i < 6; i++)
        {
            port[i] = input[i];
        }
        loaded = true;
    }

    /**
    * Returns whether or not the ports have been input for the current bomb
    * @param None
    * @return Boolean value: true - ports can be checked   false - ports must be input before check
    **/
    bool portsValid()
    {
        return loaded;
    }

    /**
    * Marks the stored ports information as outdated
    * @param None
    * @return None
    **/
    void portsReset()
    {
        loaded = false;
    }

    /**
    * Checks the stored ports information for the status at the given index
    * @param Index of port requested   port order: 0 - Serial  1 - Parallel  2 - DVI-D  3 - PS/2  4 - RJ-45  5 - Stereo RCA
    * @return Boolean value of port or false if check failed due to outdated information
    **/
    bool portsCheck(int index) // Prompt for all ports - Boolean
    {
        if (!loaded)
        {
            //Output.Show("Port data not found, please input");
            OpenWindow(1);
            return false;
            // pause execution of this function until input is entered
        }
        return port[index];
    }
};

class Batteries
{
private:
    int batteries[3];
    bool loaded;
public:
    Batteries(void) // Default Constructor
    {
        loaded = false;
    }

    /**
    * Updates the stored battery information based on input and marks the information as up-to-date
    * @param Integer array size 3  0 - AA   1 - D Cell   2 - Total
    * @return None
    **/
    void batteriesUpdate(int input[3])
    {
        for (int i = 0; i < 3; i++)
        {
            batteries[i] = input[i];
        }
        loaded = true;
    }

    /**
    * Marks the stored battery information as outdated
    * @param None
    * @return None
    **/
    void batteriesReset()
    {
        loaded = false;
    }

    /**
    * Returns whether the stored information is up to date or outdated
    * @param None
    * @return Boolean  true - Information Valid   false - Information Invalid
    **/
    bool batteriesValid()
    {
        return loaded;
    }

    /**
    * Marks the stored battery information as outdated
    * @param Which battery count to check    0 - AA   1 - D Cell   2 - Total
    * @return Number of batteries in that slot
    **/
    int batteriesCheck(int mode) // Prompt for battery counts
    {
        if (!loaded)
        {
            OpenWindow(3);
            return -2;
        }
        return batteries[mode];
    }
};

class SerialNumber
{
private:
    char serialNumber[6];
    bool loaded;
public:
    SerialNumber(void) // Default Constructor
    {
        loaded = false;
    }
    
    void serialUpdate(char input[6])
    {
        for (int i = 0; i < 6; i++)
        {
            serialNumber[i] = input[i];
        }

        loaded = true;
    }

    void serialReset()
    {
        loaded = false;
    }

    bool serialValid()
    {
        return loaded;
    }

    char serialCheck(int index)
    {
        if (!loaded)
        {
            OpenWindow(4);
            return 1;
        }
        return serialNumber[index];
    }
};

// Bomb Constant Object Declarations
Indicator CurrentIndicators;
Ports CurrentPorts;
Batteries CurrentBatteries;
SerialNumber CurrentSerial;


// Include all Window Header files, now that all needed declarations exist
#include "BatteriesCountUpdate.h"
#include "IndicatorUpdate.h"
#include "PortUpdate.h"
#include "SerialNumUpdate.h"
#include "ButtonOutput.h"

#include "ModuleSimpleWires.h"
#include "ModuleButton.h"
#include "ModuleKeypad.h"
#include "ModuleSimonSays.h"
#include "ModuleWhosOnFirst.h"
#include "ModuleMemory.h"
#include "ModuleMorseCode.h"
#include "ModuleComplicated Wires.h"
#include "ModuleWireSequence.h"
#include "ModuleMaze.h"
#include "ModulePassword.h"
#include "ModuleKnobs.h"

#include "MyForm.h"

// Object (?) to hold the single handle for the 5 windows that only get created once
ref class CurrentForms
{
public:
    CurrentForms(void) // Default Constructor
    {
        System::Windows::Forms::Application::EnableVisualStyles();
        System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(true);
    }
    static KTaNEGUIExpert::MyForm^ form = gcnew KTaNEGUIExpert::MyForm;
    static KTaNEGUIExpert::IndicatorUpdate^ inds = gcnew KTaNEGUIExpert::IndicatorUpdate();
    static KTaNEGUIExpert::PortUpdate^ prts = gcnew KTaNEGUIExpert::PortUpdate();
    static KTaNEGUIExpert::BatteriesCountUpdate^ btrs = gcnew KTaNEGUIExpert::BatteriesCountUpdate();
    static KTaNEGUIExpert::SerialNumUpdate^ srl = gcnew KTaNEGUIExpert::SerialNumUpdate();
};

// Object (?) to hold the handle to the current window attempting to do a calculation that requires other input first
ref class RetryCalculation
{
public:
    static int ID; // Default: 0
    static KTaNEGUIExpert::ModuleSimpleWires^ SimpleWires; // ID: 1
    static KTaNEGUIExpert::ModuleButton^ Button; // ID: 2
    static KTaNEGUIExpert::ModuleSimonSays^ SimonSays; // ID: 3
    static KTaNEGUIExpert::ModuleComplicatedWires^ ComplicatedWires; // ID: 4
};

using namespace System;

using namespace System::Windows::Forms;

[STAThread]

void main()//array<String^>^ args)

{
    CurrentIndicators.indicatorReset();

    System::Windows::Forms::Application::Run(CurrentForms::form); // Pass a managed reference to windows to start displaying the program and set the given form to visible
}


/**
* Show the window of the specified ID (only works for single instance windows - members of CurrentForms ref class)
* @param Window ID: 0 - Home Page  1 - Indicator Input  2 - Ports Input  3 - Batteries Input  4 - Serial Number Input
* @return None
*/
void OpenWindow(char WindowID)
{
    switch (WindowID)
    {
    case 0:
        CurrentForms::form->Show(); // -> operator used instead of . operator due to managed (garbage collector can move) reference (handle)
        return;
    case 1:
        CurrentForms::inds->Show();
        return;
    case 2:
        CurrentForms::prts->Show();
        return;
    case 3:
        CurrentForms::btrs->Show();
        return;
    case 4:
        CurrentForms::srl->Show();
        return;
    }
}

/**
* Hide the window of the specified ID (only works for single instance windows - members of CurrentForms ref class)
* @param Window ID: 0 - Home Page  1 - Indicator Input  2 - Ports Input  3 - Batteries Input  4 - Serial Number Input
* @return None
*/
void HideWindow(char WindowID)
{
    
    switch (WindowID)
    {
    case 0:
        CurrentForms::form->Hide(); // -> operator used instead of . operator due to managed (garbage collector can move) reference (handle)
        return;
    case 1:
        CurrentForms::inds->Hide();
        return;
    case 2:
        CurrentForms::prts->Hide();
        return;
    case 3:
        CurrentForms::btrs->Hide();
        return;
    case 4:
        CurrentForms::srl->Hide();
        return;
    }
}

/**
* Ensure Home page is visible and call the update method on that instance to display new versions of input constants
* @param None
* @return None
*/
void UpdateHome()
{
    OpenWindow(0);
    CurrentForms::form->Update(); // -> operator used instead of . operator due to managed (garbage collector can move) reference (handle)
}

/**
* Reset Input parameters on Bomb Constant Inputs
* @param None
* @return None
*/
void ResetForms()
{
    CurrentForms::prts->ResetForm();
    CurrentForms::inds->ResetForm();
    CurrentForms::srl->ResetForm();
    CurrentForms::btrs->ResetForm();
}

/**
* Checks reference class data to determine if a module calculation required additional input, and if so, reattempt calculation
* @param None
* @return None
*/
void resumeCalculation()
{
    //System::Windows::Forms::MessageBox::Show("Resume Attempt", "Debug");
    int WindowID = RetryCalculation::ID;
    RetryCalculation::ID = 0;
    switch (WindowID)
    {
    case 1:
        //System::Windows::Forms::MessageBox::Show("Resume Simple Wires", "Debug");
        RetryCalculation::SimpleWires->Calculate();
        break;
    case 2:
        //System::Windows::Forms::MessageBox::Show("Resume Button", "Debug");
        RetryCalculation::Button->Calculate();
        break;
    case 3:
        //System::Windows::Forms::MessageBox::Show("Resume Simon Says", "Debug");
        RetryCalculation::SimonSays->Calculate();
        break;
    case 4:
        //System::Windows::Forms::MessageBox::Show("Resume Complicated Wires", "Debug");
        RetryCalculation::ComplicatedWires->Calculate();
        break;
    default:
        break;
    }
}

/**
* Stores a handle in a reference class object (?) to allow access to that instance of the window and sets an indicator to know which module calculation required additional input to resume after input is complete
* @param Handle to window to return to (overloaded for all modules that use Bomb Constants)
* @return None
*/
void pauseCalculation(KTaNEGUIExpert::ModuleSimpleWires^ input)
{
    RetryCalculation::SimpleWires = input;
    RetryCalculation::ID = 1;
}
void pauseCalculation(KTaNEGUIExpert::ModuleButton^ input)
{
    RetryCalculation::Button = input;
    RetryCalculation::ID = 2;
}
void pauseCalculation(KTaNEGUIExpert::ModuleSimonSays^ input)
{
    RetryCalculation::SimonSays = input;
    RetryCalculation::ID = 3;
}
void pauseCalculation(KTaNEGUIExpert::ModuleComplicatedWires^ input)
{
    RetryCalculation::ComplicatedWires = input;
    RetryCalculation::ID = 4;
}