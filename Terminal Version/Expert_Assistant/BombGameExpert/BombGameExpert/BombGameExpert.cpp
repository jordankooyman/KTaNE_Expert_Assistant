// Expert Assistant for Keep Talking and Nobody Explodes Puzzles (no mods... yet!)
// Written by: Jordan Kooyman and Bradley Walby
// Setup and Initialization written by Jordan Kooyman

// Transition to using Github (version control) instead of Onedrive (unreliable, dangerous)

// Better organize dev utilities (such as maze generator) (1 program? - probably not)

// Strongly improve code documentation - update the comment block above each function with description, parameters, returns

// Future Expansion: 
// Use standardized key inputs accross all modules that use single key inputs, based on predefined constants, instead of hardcoded into each module
//      Have a settings menu option (or seperate program?) to change key bindings - store in a text file
// Move base modules to one header file
// Casing Constants moved to their own header file (even modded)
// Have modded modules each in their own header files
// Option to select which modded modules to use
// Add support for extra things on the bomb casing to make future implementation easier - may be done already
// Add optional logging for easier debugging when other users test it? - example: Brad's morse code input length error
//      Store all inputs, and some reference program marks, to a text file that can be reviewed later


#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>

using namespace std;

const bool ALL_PORTS = false; // if true, program will prompt for all ports, even unused ones (in the base game)

class Label
{
public:
    string text = "";
    bool light = false;
};

// Function Prototypes - Setup and Support

void new_bomb(); // Load new bomb info into memory
int indicator(int mode, string tag = "None");                      // By: Jordan Kooyman
bool ports(int index = -1);
int batteries(int);
char serial(int mode = 0, int index = -1); 
int clean_input(int, int, bool wide = false);
void mazeInput(int[], string);
string maze_hunter(int, int[9][13][13], int[2][2], int, int, int);
string morse_clean_input();                                        // By: Bradley Walby
int morse_compare(string, string, int, int);
void morse_check();
void bubble_sort(int arr[], string stg[], int length);
void array_flip(int int_arr[], string str_arr[], int index1, int index2);


// Function Prototypes - Module Puzzles

void Password(); // By: Jordan Kooyman
void Memory();
void Wires1();   // Simple Wires
void Wires2();   // Complicated Wires
void Wires3();   // Wire Sequence
void Button();
void WoF();      // Who's On First
void Simon();
void Knob();
void Maze();
void Keypad();   // By: Bradley Walby
void Morse(string);

/**
* Main program loop. Contains main menu selection and calls to all modules
* @param None
* @return Integer Error Code or 0 if successful
*/
int main()
{
    setlocale(LC_ALL, "en_US.UTF-16");
    // bool loop = true; // Menu loop variable

    cout << "Welcome to the Keep Talking and Nobody Explodes Digital Expert Assistant \n";

    new_bomb(); // Load bomb info from user into memory

    // Module Selection Menu Loop
    while (true) //(loop)
    {
        cout << "\nPlease enter:\n-1: Exit\n0: Load New Bomb Information\n1: Password\n2: Memory\n3: Keypad/Symbols\n4: Simple Wires\n5: Complicated Wires\n6: Wire Sequence\n7: Button\n8: Who's On First\n9: Simon Says\n10: Knobs\n11: Maze\n12: Morse Code\n";
        int selection = clean_input(12, -1); // Expand this when adding a new case and expanding the printed list
        switch (selection)
        {
        case -1: // Exit
            return 0; // loop = false;
            break;
        case 0: // New Bomb - Expand and allow the changing of just one element (such as serial number or indicators)?
            new_bomb();
            break;
        case 1: // Password
            Password();
            break;
        case 2: // Memory
            Memory();
            break;
        case 3: // Keypad
            Keypad();
            break;
        case 4: // Simple Wires
            Wires1();
            break;
		case 5: // Complicated Wires
			Wires2();
			break;
        case 6: // Wire Sequence
            Wires3();
            break;
		case 7: // Button
			Button();
			break;
		case 8: // Who's On First
			WoF();
			break;
		case 9: // Simon Says
			Simon();
			break;
        case 10: // Knobs
            Knob();
            break;
		case 11: // Maze
			Maze();
			break;
        case 12: // Morse Code
            morse_check();
            break;
        default: // Error Case - Should Never Occur
            cout << "Unexpected Error Occured\nCode: 0x01\nTerminating";
            return 1;
        }
    }
    return 0;
}

// Function Definitions - Setup and Support

/**
* Prompt user for all information on the casing of a bomb or reset to null values
* @param None
* @return None
*/
void new_bomb()
{
    // Enter Info? - no = set flag to false, and prompt if input is needed
    cout << "Would you like to enter the bomb information now?\n1 for yes, 2 for no\n";
    if (clean_input(2, 1) == 1)
    {
        // Load Serial Number into memory
        serial(0);

        // Load Indicators into memory
        indicator(-1);

        // Load Ports into memory
        ports(-1);

        // Load Batteries into memory
        batteries(0);
    }
    else
    {
        // Load Serial Number flag showing it was skipped
        serial(7);

        // Load Indicators flag showing it was skipped
        indicator(7);

        // Load Ports flag showing it was skipped
        ports(7);

        // Load Batteries flag showing it was skipped
        batteries(7);
    }

    return;
}

// Expand indicator input to allow for the previous input to be redone in case of user error
/**
* Prompt user for all indicators on bomb casing or provide result from searching previously given information
* @param mode: what thing will happen: -1: load data |   2: data request |   7: false load
* @param tag: optional, needed for data request mode
* @return -1 no value return in selected mode | 0 no value found in search | 1 value found and unlit | 2 value found and lit
*/
int indicator(int mode, string tag) // 
{
    static Label indicators[11];
    static bool loaded = true;
    if (mode == 7)
    {
        loaded = false;
        return -1;
    }
    if (mode == -1) // load data mode
    {
        cout << "Is there an indicator?\n1 for yes\n2 for no\n";
        if (clean_input(2, 1) == 1) mode = 1;
        else mode = 0;
    }
    int i = mode == 2 ? 11:0; // if mode is data request, skip initialization (using ternary operator)
    while (mode && i < 10) // mode = 1
    {
        cout << "Please enter the indicator label\n";
        cin >> indicators[i].text;
		for (int j = 0; j < indicators[i].text.length(); j++) // Force indicator text to be upper case
        {
            indicators[i].text[j] = toupper(indicators[i].text[j]);
        }
        cout << "Does this indicator have a active light?\n1 for yes\n2 for no\n";
        if (clean_input(2, 1) == 1) indicators[i].light = true;
        else indicators[i].light = false;
        cout << "\n\nIs there another indicator?\n1 for yes\n2 for no\n";
        if (clean_input(2, 1) == 1) mode = 1;
        else mode = 0;
        i++;
    }
    if (mode == 1) // mode == 1 - last indicator input possible
    {
        cout << "\n\nPlease enter the last indicator label\n";
        cin >> indicators[i].text;
        cout << "Does this indicator have a active light?\n1 for yes\n2 for no";
        if (clean_input(2, 1) == 1) indicators[i].light = true;
        else indicators[i].light = false;
        i++;
    }
    for (i; i < 11; i++) // Fill in the rest of the array if values are not input
    {
        indicators[i].text = "DNE"; // Does not Exist
        indicators[i].light = false;
    }

    // Data output mode
    if (mode == 2) // Find a match to the tag input
    {
        if (!loaded)
        {
            cout << "Indicator data not found, please input\n";
            indicator(-1);
        }
        for (int j = 0; j < 11; j++) // Search the array for a match
        {
            if (indicators[j].text == tag) // Match found
                return indicators[j].light + 1; // return 1 for unlit, 2 for lit
            else
                return 0; // return 0 for not found
        }
    }
    return -1; // return -1 for error in search (ignored if called in mode 0 or mode 1)
}

/**
* Prompt user for all ports or provide output based on previously given information
* @param index: Which port type to look at  0: DVI-D | 1: Parellel | 2: PS/2 | 3: RJ-45 | 4: Serial | 5: Stereo RCA
* @return Whether or not the desired indicator is on the bomb, and if it is, whether or not it is lit up
*/
bool ports(int index) // Prompt for all ports - Boolean
{    // index 7 = false load
    static bool port[6];
    static bool loaded = true;
    if (index == 7)
    {
        loaded = false;
        return false;
    }
    if (index != -1)
    { 
        if (!loaded)
        {
            // load information, then return expected value
            cout << "Port data not found, please input\n";
            ports(-1); // load ports data
            loaded = true;
        }
        return port[index];
    }
    
    if (ALL_PORTS)
    {
        cout << "\n(1/8) Are there any DVI-D Ports on the bomb?\n1 for yes\n2 for no\nHint: They have a tiny pins and a horizontal slash\n";
        if (clean_input(2, 1) == 1) port[0] = true;
        else port[0] = false;

        cout << "\n(2/8) Are there any Parallel Ports on the bomb?\n1 for yes\n2 for no\nHint: They are long\n";
        if (clean_input(2, 1) == 1) port[1] = true;
        else port[1] = false;

        cout << "\n(3/8) Are there any PS/2 Ports on the bomb?\n1 for yes\n2 for no\nHint: They are circular\n";
        if (clean_input(2, 1) == 1) port[2] = true;
        else port[2] = false;

        cout << "\n(4/8) Are there any RJ-45 Ports on the bomb?\n1 for yes\n2 for no\nHint: They are square\n";
        if (clean_input(2, 1) == 1) port[3] = true;
        else port[3] = false;

        cout << "\n(5/8) Are there any Serial Ports on the bomb?\n1 for yes\n2 for no\nHint: They are small with square pins\n";
        if (clean_input(2, 1) == 1) port[4] = true;
        else port[4] = false;

        cout << "\n(6/8) Are there any Stereo RCA Ports on the bomb?\n1 for yes\n2 for no\nHint: They have 2 small circular ports\n";
        if (clean_input(2, 1) == 1) port[5] = true;
        else port[5] = false;
    }
    else
    {
        port[0] = false;
        cout << "\n(1/4) Are there any Parallel Ports on the bomb?\n1 for yes\n2 for no\nHint: They are long\n";
        if (clean_input(2, 1) == 1) port[1] = true;
        else port[1] = false;
        port[2] = false;
        port[3] = false;
        cout << "\n(2/4) Are there any Serial Ports on the bomb?\n1 for yes\n2 for no\nHint: They are small with square pins\n";
        if (clean_input(2, 1) == 1) port[4] = true;
        else port[4] = false;
        port[5] = false;
    }
    
    return false;
}

/**
* Prompt user for bomb serial number or provide processed output based on previously given serial number
* @param mode: What will happen 0: input | 1: char output | 2: length output | 7: false load
* @param index: Which index of the serial number is needed (only needed for char output)
* @return Requested information about bomb serial number 
*/
char serial(int mode, int index)
{
    static string Serial; // O becomes 0, and 0 is considered even
    static bool loaded = true;
    if (mode == 7)
    {
        loaded = false;
        return 0;
    }
    if (!mode) // mode 0
    {
        cout << "Please enter the 6 digit serial number on the bomb\n";
        cin >> Serial;
        for (int i = 0; i < Serial.length(); i++) // Convert Os to 0s and ensure all caps
        {
            Serial[i] = toupper(Serial[i]);
            if (Serial[i] == 'O')
            {
                Serial[i] = '0';
            }
        }
    }
    else if (mode == 1 && index != -1)
    {
        if (!loaded)
        {
            cout << "Serial number data not found, please enter\n";
            serial(0); // load serial number
            loaded = true;
        }
        return Serial[index];
    }
    else if (mode == 2)
    {
        if (!loaded)
        {
            cout << "Serial number data not found, please enter\n";
            serial(0); // load serial number
            loaded = true;
        }
        return Serial.length();
    }


    return '~';
}

/**
* Prompt user for battery counts or provide output based on previously given data
* @param mode: What will happen 0: input | 1: output AA | 2: output D | 3: output total | 7: false load
* @return Requested battery count
*/
int batteries(int mode) // Prompt for battery counts
{
    static int Batteries[3];
    static bool loaded = true;
    if (mode == 7)
    {
        loaded = false;
        return -1;
    }
    if (!mode) // input
    {
        if (ALL_PORTS)
        {
            cout << "\n(7/8) How many D cell batteries are on the bomb?\nHint: They are the large batteries\n";
            Batteries[0] = clean_input(10, 0);
            cout << "\n(8/8) How many AA batteries are on the bomb?\nHint: They are the small batteries\n";
        }
        else
        {
            cout << "\n(3/4) How many D cell batteries are on the bomb?\nHint: They are the large batteries\n";
            Batteries[0] = clean_input(10, 0);
            cout << "\n(4/4) How many AA batteries are on the bomb?\nHint: They are the small batteries\n";
        }
        Batteries[1] = clean_input(10, 0);
        Batteries[2] = Batteries[0] + Batteries[1];
        return -1;
    }
    else // output
    {
        if (!loaded)
        {
            cout << "Battery data not found, please enter\n";
            batteries(0); // load battery data
        }
        switch (mode)
        {
        case 3: // total
            return Batteries[2];
        case 2: // D cell
            return Batteries[0];
        case 1: // AA
            return Batteries[1];
        }
    }
}

/**
* Recieve input from the user, and reject not integer inputs that are outside of the specified range (assumes prompt already output)
* @param max: Largest acceptable input value (inclusive) - can be negative (not recommended)
* @param min: Smallest acceptable input value (inclusive) - can be negative (must be smaller than max)
* @param wide: Whether the Console is in normal or wide character output mode (only for erroroneous input message)
* @return User input value within the specifed range
*/
int clean_input(int max, int min, bool wide) // modified fucntion, original from https://stackoverflow.com/questions/22573235/how-can-i-avoid-bad-input-from-a-user
{
    int n;
    cin >> n;
    while (cin.fail() || n > max || n < min)
    {
        cin.clear();
        cin.ignore();
        if (wide) // allow this to be used when using wide character output mode
            wcout << "Not a valid number. Please reenter: ";
        else
            cout << "Not a valid number. Please reenter: ";
        cin >> n;
    }
    return n;
}

/**
* Special Filtered input function that rejects input other than 1 and 2 and prompts user
* @param None
* @return String containing only 1s and 2s
*/
string morse_clean_input() {
    
    string output;
    cout << "Morse (1 for dot, 2 for dash)- ";
    cin >> output;
    for (int i = 0; i < output.length(); i++) {
        if (output[i] != '1' && output[i] != '2') {
            cout << "Bad input detected, retry" << endl;
            morse_check();
        }
    }
    return output;
}

/**
* Prompts a user for ordered pair input
* @param int Array size 2 - stores x and y for return
* @param Prompt string, inserted after "...x-coordinate of "
* @return None
*/
void mazeInput(int position[], string prompt) // function based on clean input that obtains an ordered pair for a specified prompt from the user for use in the Maze module
{ // double x, y positions to account for the borders being stored in memory
    cout << "Please enter the x-coordinate of " << prompt << ": ";
    position[0] = clean_input(6, 1) * 2 - 1;
    cout << "Please enter the y-coordinate of " << prompt << ": ";
    position[1] = clean_input(6, 1) * 2 - 1;
}

/**
* Recursively searches a given maze using a depth-first search algorithm, and when a route is determined, build the instructions in reverse order
* @param Which maze to look at
* @param The maze reference array (6KB)
* @param Where the start and end is
* @param Which direction to search in next
* @param Current x Location in search
* @ param Current y Location in search
* @return String containing all prior steps + current step, being built in reverse order
*/
string maze_hunter(int mazeNumber, int mazes[9][13][13], int positions[2][2], int direction = -1, int currentX = -1, int currentY = -1) // recursively determine the route for a maze and return a string with the directions
{ // 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker  - maze reference
  // -1: unspecified | 0: Up | 1: Right | 2: Down | 3: Left                - direction reference
  // traverse a path until a split is found, then call this function again, one heading in each direction, and return a string with the direction it turned added to the front of all directions returned previously if the end is reached
    // Check if the end has been reached, if so, terminate function chain
    if (currentX == positions[1][0] && currentY == positions[1][1]) return "Done";
    //cout << "\n0 x:" << currentX << " y: " << currentY << "  ";
    string check = "1";
    if (direction == -1)
    { // determine which directions are valid and start the recursive cascade - probably not return, but check if it is valid
        if (mazes[mazeNumber][positions[0][1] - 1][positions[0][0]] == 2)
        {
            check = maze_hunter(mazeNumber, mazes, positions, 0, positions[0][0], positions[0][1]); // open move available above
            //cout << " 1check: " << check[check.length() - 1] << "\t";
            if (check[check.length() - 1] < '~') return "Up " + check; // Determine if a deadend was hit, if not, return the string
            //else cout << "\nignore deadend 0\n";
        }
        if (mazes[mazeNumber][positions[0][1]][positions[0][0] + 1] == 2)
        {
            check = maze_hunter(mazeNumber, mazes, positions, 1, positions[0][0], positions[0][1]); // open move available right
            //cout << " 2check: " << check[check.length() - 1] << "\t";
            if (check[check.length() - 1] < '~') return "Right " + check; // Determine if a deadend was hit, if not, return the string
            //else cout << "\nignore deadend 1\n";
        }
        if (mazes[mazeNumber][positions[0][1] + 1][positions[0][0]] == 2)
        {
            check = maze_hunter(mazeNumber, mazes, positions, 2, positions[0][0], positions[0][1]); // open move available down
            //cout << " 3check: " << check[check.length() - 1] << "\t";
            if (check[check.length() - 1] < '~') return "Down " + check; // Determine if a deadend was hit, if not, return the string
            //else cout << "\nignore deadend 2\n";
        }
        if (mazes[mazeNumber][positions[0][1]][positions[0][0] - 1] == 2)
        {
            check = maze_hunter(mazeNumber, mazes, positions, 3, positions[0][0], positions[0][1]); // open move available left
            //cout << " 4check: " << check[check.length() - 1] << "\t";
            if (check[check.length() - 1] < '~') return "Left " + check; // Determine if a deadend was hit, if not, return the string
            //else cout << "\nignore deadend 3\n";
        }
        //cout << "1";
    }
    //cout << "2: " << direction << " | ";
    // Move in the specified direction
    if (direction == 0) currentY -= 2; // move to next position up
    else if (direction == 1) currentX += 2; // move to next position right
    else if (direction == 2) currentY += 2; // move to next position down
    else if (direction == 3) currentX -= 2; // move to next position left
    else return "Error: Invalid Direction Specified";
    //cout << "3 x:" << currentX << " y: " << currentY << "  ";
    // Check if the end has been reached, if so, terminate function chain
    if (currentX == positions[1][0] && currentY == positions[1][1]) return "End";
    //cout << "4";

    // Determine if in a dead end
    if (direction == 0 && mazes[mazeNumber][currentY][currentX - 1] != 2 && mazes[mazeNumber][currentY][currentX + 1] != 2 && mazes[mazeNumber][currentY + 1][currentX] != 2) return "~";
    else if (direction == 1 && mazes[mazeNumber][currentY][currentX - 1] != 2 && mazes[mazeNumber][currentY - 1][currentX] != 2 && mazes[mazeNumber][currentY + 1][currentX] != 2) return "~";
    else if (direction == 2 && mazes[mazeNumber][currentY][currentX - 1] != 2 && mazes[mazeNumber][currentY][currentX + 1] != 2 && mazes[mazeNumber][currentY - 1][currentX] != 2) return "~";
    else if (direction == 3 && mazes[mazeNumber][currentY - 1][currentX] != 2 && mazes[mazeNumber][currentY][currentX + 1] != 2 && mazes[mazeNumber][currentY + 1][currentX] != 2) return "~";
    //cout << "5: ";
    // Determine the next directions to move, skipping the origin direction  --  Logic seems backwards (only moves in the direction it came from)
    if (mazes[mazeNumber][currentY - 1][currentX] == 2 && direction != 2)
    {
        //cout << "Up";
        check = ("Up, " + maze_hunter(mazeNumber, mazes, positions, 0, currentX, currentY)); // return the string with the current direction before the next set // open move available above
        //cout << " 5check: " << check[check.length() - 1] << "\t";
        if (check[check.length() - 1] < '~') return check; // Determine if a deadend was hit, if not, return the string
        //else cout << "\nignore deadend5\n";
    }
    if (mazes[mazeNumber][currentY][currentX + 1] == 2 && direction != 3)
    {
        //cout << "Right";
        check = ("Right, " + maze_hunter(mazeNumber, mazes, positions, 1, currentX, currentY)); // return the string with the current direction before the next set // open move available right
        //cout << " 6check: -" << check[check.length() - 1] << "-\t" << check << "\t" << (check[check.length() - 1] < '~') << endl;
        if (check[check.length() - 1] < '~') return check; // Determine if a deadend was hit, if not, return the string
        //else cout << "\nignore deadend6\n";
    }
    if (mazes[mazeNumber][currentY + 1][currentX] == 2 && direction != 0)
    {
        //cout << "Down";
        check = ("Down, " + maze_hunter(mazeNumber, mazes, positions, 2, currentX, currentY)); // return the string with the current direction before the next set // open move available down
        //cout << " 7check: " << check[check.length() - 1] << "\t";
        if (check[check.length() - 1] < '~') return check; // Determine if a deadend was hit, if not, return the string
        //else cout << "\nignore deadend7\n";
    }
    if (mazes[mazeNumber][currentY][currentX - 1] == 2 && direction != 1)
    {
        //cout << "Left";
        check = ("Left, " + maze_hunter(mazeNumber, mazes, positions, 3, currentX, currentY)); // return the string with the current direction before the next set // open move available left
        //cout << " 8check: " << check[check.length() - 1] << "\t";
        if (check[check.length() - 1] < '~') return check; // Determine if a deadend was hit, if not, return the string
        //else cout << "\nignore deadend8\n";
    }

    //cout << "6-";
    return "~";
    //return "Null Error: This Function is not working (Hint: Try Implementing it First)";
}

/**
* Determine how far from a perfect match two strings of morse code are
* Compares arg input against arg comparator within the indexes lowerbound and upperbound (inclusive) and returns match
* @param Thing to Compare
* @param Thing to Compare Against
* @param Lower Bound of search
* @param Upper Bound of search
* @return Integer count of differences
*/
int morse_compare(string input, string comparator, int lb, int ub) {
    int diff_tally = 0;
    for (int i = lb; i <= ub; i++) {
        if (input[i] != comparator[i]) {
            diff_tally++;
        }
    }
    return diff_tally;
}

/**
* Operates the other Morse Code functions in order to start the puzzle solver
* @param None
* @return None
*/
void morse_check() {
    string morse = morse_clean_input();
    Morse(morse);
    
}

/**
* Used by Bubble Sort to accomplish sorting for Morse Code
* @param Morse Code integer and string arrays, and which indexes to flip (keeping both arrays in sync)
* @return Flipped arrays via reference
*/
void array_flip(int int_arr[], string str_arr[], int index1, int index2) {
    int temp_int = int_arr[index1];
    string temp_str = str_arr[index1];
    int_arr[index1] = int_arr[index2];
    str_arr[index1] = str_arr[index2];
    int_arr[index2] = temp_int;
    str_arr[index2] = temp_str;
    return;
}

/**
* Sorting function for Morse Code
* @param Morse Code arrays to sort, keeping both in sync
* @return Sorted arrays via reference
*/
void bubble_sort(int arr[], string stg[], int length) {
    for (int i = 0; i < length - 2; i++) {
        for (int j = 0; j < length - 2; j++) {
            if (arr[i] > arr[i + 1]) {
                array_flip(arr, stg, i, (i + 1));
            }
        }
    }
}

// Function Definitions - Module Puzzles

/**
* Prompts user for all possible letters in a given column of the module, then identifies any and all matches in the reference table
* @param None
* @return None
*/
void Password() // Takes in all letters in a password module (first 3 columns only) and determines all possible valid combinations
{// potentially expand with variants that use 4 and/or 5 columns for higher accuracy (parameter or new function?)
    cout << "\nSimply enter all the letters for the first 3 columns on the bomb as prompted, then find the one correct combintation based on the outputs given\n";
    string column_1, column_2, column_3;
    char word_bank[35][5] = { {'a', 'b', 'o', 'u', 't'}, {'a', 'f', 't', 'e', 'r'}, {'a', 'g', 'a', 'i', 'n'}, {'b', 'e', 'l', 'o', 'w'}, {'c', 'o', 'u', 'l', 'd'},
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
    cout << "\nType all letters before hitting enter\nFirst Column - ";
    cin >> column_1;
    cout << "\nSecond Column - ";
    cin >> column_2;
    cout << "\nThird Column - ";
    cin >> column_3;
    cout << "\nPotential Answers:\n";
    for (int i = 0; i < 35; i++)
    {
        for (int j = 0; j < column_1.length(); j++)
        {
            if (word_bank[i][0] == tolower(column_1[j]))
            {
                for (int k = 0; k < column_2.length(); k++)
                {
                    if (word_bank[i][1] == tolower(column_2[k]))
                    {
                        for (int l = 0; l < column_3.length(); l++)
                        {
                            if (word_bank[i][2] == tolower(column_3[l]))
                            {
                                for (int m = 0; m < 5; m++)
                                {
                                    cout << word_bank[i][m];
                                }
                                cout << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}

/**
* Prompts the user for info displayed on module, then instructs on which position or label to click, requests the other, then repeats 3 more times until the last cycle where it only asks for the display information
* @param None
* @return None
*/
void Memory() 
{ // Prompt user for all relevant information in the module, outputting the correct position or label
    int display = 0;
    int mem[4][2] = {}; // Stage | Label, Position
    // Stage 1
    cout << "\nStage 1\nDisplay: ";
    display = clean_input(4, 1);
    switch (display)
    {
    case 1:
    case 2:
    {
        cout << "Position 2\n\nLabel: ";
        mem[0][1] = 2;
        mem[0][0] = clean_input(4, 1);
        break;
    }
    case 3:
    {
        cout << "Position 3\n\nLabel: ";
        mem[0][1] = 3;
        mem[0][0] = clean_input(4, 1);
        break;
    }
    case 4:
    {
        cout << "Position 4\n\nLabel: ";
        mem[0][1] = 4;
        mem[0][0] = clean_input(4, 1);
        break;
    }
    }
    // Stage 2
    cout << "\nStage 2\nDisplay: ";
    display = clean_input(4, 1);
    switch (display)
    {
    case 1:
    {
        cout << "Label 4\n\nPosition: ";
        mem[1][0] = 4;
        mem[1][1] = clean_input(4, 1);
        break;
    }
    case 2:
    case 4:
    {
        cout << "Position " << mem[0][1] << "\n\nLabel: ";
        mem[1][1] = mem[0][1];
        mem[1][0] = clean_input(4, 1);
        break;
    }
    case 3:
    {
        cout << "Position 1\n\nLabel: ";
        mem[1][1] = 1;
        mem[1][0] = clean_input(4, 1);
        break;
    }
    }
    // Stage 3
    cout << "\nStage 3\nDisplay: ";
    display = clean_input(4, 1);
    switch (display)
    {
    case 1:
    {
        cout << "Label " << mem[1][0] << "\n\nPosition: ";
        mem[2][0] = mem[1][0];
        mem[2][1] = clean_input(4, 1);
        break;
    }
    case 2:
    {
        cout << "Label " << mem[0][0] << "\n\nPosition: ";
        mem[2][0] = mem[0][0];
        mem[2][1] = clean_input(4, 1);
        break;
    }
    case 3:
    {
        cout << "Position 3\n\nLabel: ";
        mem[2][1] = 3;
        mem[2][0] = clean_input(4, 1);
        break;
    }
    case 4:
    {
        cout << "Label 4\n\nPosition: ";
        mem[2][0] = 4;
        mem[2][1] = clean_input(4, 1);
        break;
    }
    }
    // Stage 4
    cout << "\nStage 4\nDisplay: ";
    display = clean_input(4, 1);
    switch (display)
    {
    case 1:
    {
        cout << "Position " << mem[0][1] << "\n\nLabel: ";
        mem[3][1] = mem[0][1];
        mem[3][0] = clean_input(4, 1);
        break;
    }
    case 2:
    {
        cout << "Position 1\n\nLabel: ";
        mem[3][1] = 1;
        mem[3][0] = clean_input(4, 1);
        break;
    }
    case 3:
    case 4:
    {
        cout << "Position " << mem[1][1] << "\n\nLabel: ";
        mem[3][1] = mem[1][1];
        mem[3][0] = clean_input(4, 1);
        break;
    }
    }
    // Stage 5
    cout << "\nStage 5\nDisplay: ";
    display = clean_input(4, 1);
    switch (display)
    {
    case 1:
    {
        cout << "Label " << mem[0][0] << endl;
        break;
    }
    case 2:
    {
        cout << "Label " << mem[1][0] << endl;
        break;
    }
    case 3:
    {
        cout << "Label " << mem[3][0] << endl;
        break;
    }
    case 4:
    {
        cout << "Label " << mem[2][0] << endl;
        break;
    }
    }
}

/**
* Prompts the user for the id of 4 symbols displayed, then uses that to determine what order they should go in according to a fixed reference table
* @param None
* @return None
*/
void Keypad() // setmode reference: https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/setmode?view=msvc-160#return-value
{//      Notes: wcout will need to be used instead of cout in this function
 // The Stars, the Copyright, and the 'nose-thingy' do not work in Unicode 16 (i beleive they are UTF-32, and Windows refuses to accept them) - a potential explanation: https://github.com/ww898/utf-cpp
    setlocale(LC_ALL, "en_US.UTF-16"); // Do Not Modify unless absolutely necessary
    int mode_check = _setmode(_fileno(stdout), _O_U16TEXT); // Do Not Modify unless absolutely necessary
    int keycodes[6][7] = {{ 1, 2, 3, 4, 5, 6, 7},
                          { 8, 1, 7, 9,10, 6,11},
                          {12,13, 9,14,15, 3,10},
                          {16,17,18, 5,14,11,19},
                          {20,19,18,21,17,22,23},
                          {16, 8,24,25,20,26,27}};

    wchar_t symbols[6][7] = {{L'Ϙ',L'Ѧ',L'λ',L'Ϟ',L'Ѭ',L'ϗ',L'Ͽ'}, // * for filled star, # for hollow star, P for paragraph
                            {L'Ӭ',L'Ϙ',L'Ͽ',L'Ҩ',L'#',L'ϗ',L'¿'},
                            {L'©',L'ώ',L'Ҩ',L'Җ',L'Ԇ',L'λ',L'#'},
                            {L'б',L'P',L'Б',L'Ѭ',L'Җ',L'¿',L'þ'},
                            {L'ψ',L'þ',L'Б',L'Ͼ',L'P',L'Ѯ',L'*'},
                            {L'б',L'Ӭ',L'҂',L'ӕ',L'ψ',L'Й',L'Ω'} }; // the L before signifies wide character and makes it work, do not forget to use it when declaring new unicode based strings (may be a seperate data type) or wide chars

    int sym_ref[4];
    int locations[8][2] = { {-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1} };
    int loc_element = 0;
    int column_used = -1;
    int count = 1;

    //Print reference table
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (keycodes[i][j] == count) {
                wcout << count << "- ";
                if (symbols[i][j] == L'þ') { wcout << ":"; } // Added by Jordan Kooyman
                wcout << symbols[i][j] << endl;
                count++;
            }
        }
    }
	//Prompt User for input
    wcout << "Enter the integers for the symbols needed-\n";
    //Recieve Correct inputs from user (use w_clean_input()) - prompt for all 4 values
    for (int i = 0; i < 4; i++) {
        sym_ref[i] = clean_input(27, 1, true);
    }
	//Identify the symbols referenced
    for (int column = 0; column < 6; column++) {
        for (int element = 0; element < 7; element++) {
            for (int i = 0; i < 4; i++) {
                if (keycodes[column][element] == sym_ref[i]) {
                    locations[loc_element][0] = column;
                    locations[loc_element][1] = element;
                    loc_element++;
                }
            }
        }
    }
    /*for (int i = 0; i < 8; i++) {
        wcout << locations[i][0] << ", " << locations[i][1] << endl;
    }*/
    //wcout << endl;
    //identify the correct row to reference
    int col_tally1 = 0, col_tally2 = 0, col_tally3 = 0, col_tally4 = 0, col_tally5 = 0, col_tally6 = 0;
    for (int i = 0; i < 8; i++) {
        switch (locations[i][0]) {
            case 0:
                ++col_tally1;
                break;
            case 1:
                ++col_tally2;
                break;
            case 2:
                ++col_tally3;
                break;
            case 3:
                ++col_tally4;
                break;
            case 4:
                ++col_tally5;
                break;
            case 5:
                ++col_tally6;
                break;
        }

        if (col_tally1 == 4) {
            column_used = 0;
            break;
        }
        else if (col_tally2 == 4) {
            column_used = 1;
            break;
        }
        else if (col_tally3 == 4) {
            column_used = 2;
            break;
        }
        else if (col_tally4 == 4) {
            column_used = 3;
            break;
        }
        else if (col_tally5 == 4) {
            column_used = 4;
            break;
        }
        else if (col_tally6 == 4) {
            column_used = 5;
            break;
        }
        else {
        }
    }
	//Display the four inputs in the correct order
    wcout << endl;
    for (int i = 0; i < 8; i++) {
        int symbol_locations[4][2];
        int counter = 0;
        if (locations[i][0] == column_used) {
            symbol_locations[counter][0] = locations[i][0];
            symbol_locations[counter][1] = locations[i][1];
            if (symbols[symbol_locations[counter][0]][symbol_locations[counter][1]] == L'þ') { wcout << ":"; } // Added by Jordan Kooyman
            wcout << symbols[symbol_locations[counter][0]][symbol_locations[counter][1]] << "\t";
            counter++;
        }
    }
    wcout << endl << endl;
    setlocale(LC_ALL, "en_US.UTF-8"); // Do Not Modify unless absolutely necessary
    mode_check = _setmode(_fileno(stdout), _O_TEXT); // Do Not Modify unless absolutely necessary
}

/**
* [Simple Wires] Prompts user for number of wires and the colors of the wires, then tells the user which color wire to cut on the bomb
* @param None
* @return None
*/
void Wires1() // Simple Wires
{
    cout << "How many wires (3, 4, 5, or 6)\n";
    int wire_count = clean_input(6, 3);
    int wires[6] = { 0, 0, 0, 0, 0, 0 }; // 0: Uninitialized, 1: Yellow, 2: Red, 3: Blue, 4: Black, 5: White
    // Prompt the user for a given number of wires, in order and store in an array
    cout << "Please enter all " << wire_count << " wires, in the order on the bomb using single letters only\nA: Yellow\nS: Red\nD: Blue\nF: Black\nG: White\n";
    int good_count = 0;
    while (good_count < wire_count) // ignore spaces and wrong numbers
    {
        char input;
        cin >> input; // Case insensitive
        input = toupper(input);
        if (input == 'A')
        {
            wires[good_count] = 1;
            good_count++;
        }
        else if (input == 'S')
        {
            wires[good_count] = 2;
            good_count++;
        }
        else if (input == 'D')
        {
            wires[good_count] = 3;
            good_count++;
        }
        else if (input == 'F')
        {
            wires[good_count] = 4;
            good_count++;
        }
        else if (input == 'G')
        {
            wires[good_count] = 5;
            good_count++;
        }
    }
    int yellow_count = 0;
    int red_count = 0;
    int blue_count = 0;
    int black_count = 0;
    int white_count = 0;
    for (int i = 0; i < wire_count; i++)
    {
        if (wires[i] == 1) yellow_count++;
        else if (wires[i] == 2) red_count++;
        else if (wires[i] == 3) blue_count++;
        else if (wires[i] == 4) black_count++;
        else if (wires[i] == 5) white_count++;
    }
    switch (wire_count)
    {
    case 3:
        if (wires[0] == 3 && wires[1] == 3 && wires[2] == 2) cout << "Cut the 2nd wire\n";
        else if (wires[0] != 2 && wires[1] != 2 && wires[2] != 2) cout << "Cut the 2nd wire\n";
        else cout << "Cut the 3rd wire\n";
        break;
    case 4:
        if (red_count > 1 && serial(1,5) % 2 == 1) cout << "Cut the last red wire\n";
        else if (wires[3] == 1 && red_count == 0) cout << "Cut the 1st wire\n";
        else if (blue_count == 1) cout << "Cut the 1st wire\n";
        else if (yellow_count > 1) cout << "Cut the 4th wire\n";
        else cout << "Cut the 2nd wire\n";
        break;
    case 5:
        if (wires[4] == 4 && serial(1, 5) % 2 == 1) cout << "Cut the 4th wire\n";
        else if (red_count == 1 && yellow_count > 1) cout << "Cut the 1st wire\n";
        else if (black_count == 0) cout << "Cut the 2nd wire\n";
        else cout << "Cut the 1st wire\n";
        break;
    case 6:
        if (yellow_count == 0 && serial(1, 5) % 2 == 1) cout << "Cut the 3rd wire\n";
        else if (yellow_count == 1 && white_count > 1) cout << "Cut the 4th wire\n";
        else if (red_count == 0) cout << "Cut the 6th wire\n";
        else cout << "Cut the 4th wire\n";
        break;
    default:
        break;
    }
}

/**
* [Complicated Wires] Prompts user for all information about 1 wire at a time, determining whether or not to cut it. Allows for input of multiple wires at once
* @param None
* @return None
*/
void Wires2() // Complicated Wires
{// rewrite input to handle all attributes in one line, and no seperate merge cases (as well as multiple wires in one input)
// A: Red   S: Blue   D: White      W: LED   X: Star
    bool  exit = false;
    bool buffered = false;
    string buffer = "";
// cout << "Please enter the first wire color or exit:\n0: Exit\n1: White\n2: Red [White Optional]\n3: Blue [White Optional]\n4: Red and Blue\n";
    while (true)
    {   
        int input[2] = { 1,4 };// = { clean_input(4, 0),0 }; // Color (white), Leds/Stars (none)
        int output = 0; // 0: Do Not | 1: Cut | 2: Last Serial Even | 3: Parallel | 4: 2+ Bat
        string temp_input = buffer;
        if (!buffered)
        {
            cout << "Please enter all the attributes of a single wire:\nA: Red Wire\tS: Blue Wire\tD: White Wire\nW: Led\tX: Star\nQ: New Wire\t1: Exit\n";
            cin >> temp_input;
        }
        buffered = false;
        //getline(cin, temp_input);
        int i = 0;
        while (i < temp_input.length() && !buffered)
        {
            temp_input[i] = toupper(temp_input[i]);
            switch (temp_input[i])
            {
            case 65: // Red
                if (input[0] == 1) { input[0] = 2; } // white (default)
                else if (input[0] == 3) { input[0] = 4; } // already blue
                break;
            case 83: // Blue
                if (input[0] == 1) { input[0] = 3; } // white (default)
                else if (input[0] == 2) { input[0] = 4; } // already red
                break;
            //case 68: // White (default, ignore)
            //    break;
            case 87: // LED
                if (input[1] == 4) { input[1] = 2; } // none (default)
                else if (input[1] == 1) { input[1] = 3; } // already star
                break;
            case 88: // Star
                if (input[1] == 4) { input[1] = 1; } // none (default)
                else if (input[1] == 2) { input[1] = 3; } // already LED
                break;
            case 49: // Exit
                exit = true;
                break;
            case 81: // New Wire (Spacer)
                buffered = true;
                if (i + 1 < temp_input.length()) { buffer = temp_input.substr(i + 1, temp_input.length() - (i + 1)); }
                break;
            }
            i++;
        }
        // cout << "What modifiers are there?\n1: Star\n2: LED\n3: Both\n4: Neither\n";
        // input[1] = clean_input(4, 1);
        switch (input[0]) // determine which output based on the table https://ktane.fandom.com/wiki/Complicated_Wires#optimized_(LeGeND/Lebossle)
        {
        case 1: // White
            switch (input[1])
            {
            case 1: // Star
                output = 1;
                break;
            case 2: // LED
                output = 0;
                break;
            case 3: // Both
                output = 4;
                break;
            case 4: // Neither
                output = 1;
                break;
            default:
                break;
            }
            break;
        case 2: // Red
            switch (input[1])
            {
            case 1: // Star
                output = 1;
                break;
            case 2: // LED
                output = 4;
                break;
            case 3: // Both
                output = 4;
                break;
            case 4: // Neither
                output = 2;
                break;
            default:
                break;
            }
            break;
        case 3: // Blue
            switch (input[1])
            {
            case 1: // Star
                output = 0;
                break;
            case 2: // LED
                output = 3;
                break;
            case 3: // Both
                output = 3;
                break;
            case 4: // Neither
                output = 2;
                break;
            default:
                break;
            }
            break;
        case 4: // Red and Blue
            switch (input[1])
            {
            case 1: // Star
                output = 3;
                break;
            case 2: // LED
                output = 2;
                break;
            case 3: // Both
                output = 0;
                break;
            case 4: // Neither
                output = 2;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        switch (output) // process output cases that are not yes/no on cut
        {
        case 2:
            if (int(serial(1, 5)) % 2 == 0) output = 1; //int(serial[5]) % 2 == 0) output = 1;
            else output = 0;
            break;
        case 3:
            if (ports(1)) output = 1;
            else output = 0;
            break;
        case 4:
            if (batteries(3) >= 2) output = 1;
            else output = 0;
            break;
        default:
            break;
        }
        if (output == 1) cout << "\nYes: Cut the wire\n\n";
        else cout << "\nNo: Do NOT cut the wire\n\n";
        // cout << "Please enter the next wire color or exit:\n0: Exit\n1: White\n2: Red\n3: Blue\n4: Red and Blue\n";
        // input[0] = clean_input(4, 0);
        if (!buffered && exit) { return; }
    }
}

/**
* [Wire Sequence] Prompts user for 1 wire at a time, telling user which place it should end at to cut it
* @param None
* @return None
*/
void Wires3() // Wire Sequence -- Allow multiple inputs on one line?
{ // 1: A | 2: B | 3: C | 4: A B | 5: A C | 6: B C | 7: A B C
    int reference[3][9] = { {3,2,1,5,2,5,7,4,2},   // Red
                            {2,5,2,1,2,6,3,5,1},   // Blue
                            {7,5,2,5,2,6,4,3,3} }; // Black
    int counter[3] = { 0,0,0 }; // Red, Blue, Black
    cout << "Enter:\n1: Exit\nA: Red\nS: Blue\nD: Black\n";
    char input;
    do
    {
        int output = 0;
        cout << "\nNext Value:\t";
        cin >> input;
        input = toupper(input); // Case Insensitive
        if (input == 'A')
        {
            output = reference[0][counter[0]];
            counter[0]++;
        }
        else if (input == 'S')
        {
            output = reference[1][counter[1]];
            counter[1]++;
        }
        else if (input == 'D')
        {
            output = reference[2][counter[2]];
            counter[2]++;
        }
        switch (output)
        { // 1: A | 2: B | 3: C | 4: A B | 5: A C | 6: B C | 7: A B C
        case 1:
        {
            cout << "\nA\n";
            break;
        }
        case 2:
        {
            cout << "\nB\n";
            break;
        }
        case 3:
        {
            cout << "\nC\n";
            break;
        }
        case 4:
        {
            cout << "\nA or B\n";
            break;
        }
        case 5:
        {
            cout << "\nA or C\n";
            break;
        }
        case 6:
        {
            cout << "\nB or C\n";
            break;
        }
        case 7:
        {
            cout << "\nAll\n";
            break;
        }
        default:
            break;
        }
    } while (input != '1');
}

/**
* Prompts for button color and label, then either tells user to click or hold based on inputs and Bomb Constants. If hold, then prompts for color strip
* @param None
* @return None
*/
void Button()
{// List of colors - select, then list of Labels - select
    int info[3] = { 0,   // Color: 1: Blue | 2: Red | 3: White | 4: Yellow | 5: Black
                    0,   // Label: 1: Abort | 2: Detonate | 3: Hold | 4: Press
                    0 }; // Strip: 1: Blue | 2: Red | 3: White | 4: Yellow
    int hold = 0; // 0: Uninitialized, 1: Click, 2: Hold
    cout << "Please select the corresponding button color from the list below:\n1: Blue\n2: Red\n3: White\n4: Yellow\n5: Black\n";
    info[0] = clean_input(5, 1);
    cout << "Please select the corresponding button label from the list below:\n1: Abort\n2: Detonate\n3:Hold\n4: Press\n";
    info[1] = clean_input(4, 1);

    if (info[0] == 2 && info[1] == 3) hold = 1;
    else if (batteries(3) >= 2 && info[1] == 2) hold = 1;
    else if (info[0] == 1 && info[1] == 1) hold = 2;
    else if (info[0] == 3 && indicator(2, "CAR") == 2) hold = 2; // and lit indicator CAR
    else if (batteries(3) >= 3 && indicator(2, "FRK") == 2) hold = 1; // and lit indicator FRK
    else hold = 2;

    switch (hold)
    {
    case 1: // click
        cout << "Click the button\n";
        break;
    case 2: // hold
        cout << "Hold the button\nPlease enter the strip color from the list below:\n1: Blue\n2: Red\n3: White\n4: Yellow\n";
        info[2] = clean_input(4, 1);
        if (info[2] == 1) cout << "Release with\t4\tin any position\n";
        else if (info[2] == 4) cout << "Release with\t5\tin any position\n";
        else cout << "Release with\t1\tin any position\n";
        break;
    default:
        cout << "Error: 0x02\n";
        break;
    }
}

/**
* Prompt user for display text, then instructs on which position on keypad to input, then provides a list of button labels to click, where the first match found should be clicked by defuser
* @param None
* @return None
*/
void WoF() // Who's on First https://ktane.fandom.com/wiki/Who%27s_on_First#Original
{
    cout << "Enter 0 to return to the menu\n";
    string input = "1";
    string answers_p1[28] = { "YES", "FIRST", "DISPLAY", "OKAY", "SAYS", "NOTHING", " ", "BLANK", "NO", "LED", "LEAD", "READ", "RED", "REED", "LEED", "HOLD ON", "YOU", "YOU ARE", "YOUR", "YOU'RE", "UR", "THERE", "THEY'RE", "THEIR", "THEY ARE", "SEE", "C", "CEE"};
    int position_p1[28] = { 3,2,6,2,6,3,5,4,6,3,6,4,4,5,5,6,4,6,4,4,1,6,5,4,3,6,2,6 }; // 1: Top Left | 2: Top Right | 3: Middle Left | 4: Middle Right | 5: Bottom Left | 6: Bottom Right
    string answers_p2[28] = { "READY", "FIRST", "NO", "BLANK", "NOTHING", "YES", "WHAT", "UHHH", "LEFT", "RIGHT", "MIDDLE", "OKAY", "WAIT", "PRESS", "YOU", "YOU ARE", "YOUR", "YOU'RE", "UR", "U", "UH HUH", "UH UH", "WHAT?", "DONE", "NEXT", "HOLD", "SURE", "LIKE" };
    string result_p2[28] = {"YES, OKAY, WHAT, MIDDLE, LEFT, PRESS, RIGHT, BLANK, READY", "LEFT, OKAY, YES, MIDDLE, NO, RIGHT, NOTHING, UHHH, WAIT, READY, BLANK, WHAT, PRESS, FIRST", "BLANK, UHHH, WAIT, FIRST, WHAT, READY, RIGHT, YES, NOTHING, LEFT, PRESS, OKAY, NO", "WAIT, RIGHT, OKAY, MIDDLE, BLANK", "UHHH, RIGHT, OKAY, MIDDLE, YES, BLANK, NO, PRESS, LEFT, WHAT, WAIT, FIRST, NOTHING", "OKAY, RIGHT, UHHH, MIDDLE, FIRST, WHAT, PRESS, READY, NOTHING, YES", "UHHH, WHAT", "READY, NOTHING, LEFT, WHAT, OKAY, YES, RIGHT, NO, PRESS, BLANK, UHHH", "RIGHT, LEFT", "YES, NOTHING, READY, PRESS, NO, WAIT, WHAT, RIGHT", "BLANK, READY, OKAY, WHAT, NOTHING, PRESS, NO, WAIT, LEFT, MIDDLE", "MIDDLE, NO, FIRST, YES, UHHH, NOTHING, WAIT, OKAY", "UHHH, NO, BLANK, OKAY, YES, LEFT, FIRST, PRESS, WHAT, WAIT", "RIGHT, MIDDLE, YES, READY, PRESS", "SURE, YOU ARE, YOUR, YOU'RE, NEXT, UH HUH, UR, HOLD, WHAT?, YOU", "YOUR, NEXT, LIKE, UH HUH, WHAT?, DONE, UH UH, HOLD, YOU, U, YOU'RE, SURE, UR, YOU ARE", "UH UH, YOU ARE, UH HUH, YOUR", "YOU, YOU'RE", "DONE, U, UR", "UH HUH, SURE, NEXT, WHAT?, YOU'RE, UR, UH UH, DONE, U", "UH HUH", "UR, U, YOU ARE, YOU'RE, NEXT, UH UH", "YOU, HOLD, YOU'RE, YOUR, U, DONE, UH UH, LIKE, YOU ARE, UH HUH, UR, NEXT, WHAT?", "SURE, UH HUH, NEXT, WHAT?, YOUR, UR, YOU'RE, HOLD, LIKE, YOU, U, YOU ARE, UH UH, DONE", "WHAT?, UH HUH, UH UH, YOUR, HOLD, SURE, NEXT", "YOU ARE, U, DONE, UH UH, YOU, UR, SURE, WHAT?, YOU'RE, NEXT, HOLD", "YOU ARE, DONE, LIKE, YOU'RE, YOU, HOLD, UH HUH, UR, SURE", "YOU'RE, NEXT, U, UR, HOLD, DONE, UH UH, WHAT?, UH HUH, YOU, LIKE"};
    while (input != "0")
    {
        int match = -1;
        cout << "Please enter the text on the screen:\t(Enter a space if blank)\n";
        while (match == -1)
        {
            getline(cin, input);
            for (int i = 0; i < input.length(); i++) { input[i] = toupper(input[i]); } // force upper case
            int i = 0;
            while (i < 28 && match == -1)
            {
                if (answers_p1[i] == input)
                {
                    match = position_p1[i];
                }
                else if (input == "0") {
                    return;
                }
                i++;
            }
            if (match == -1) cout << "Invalid Input. Please Try Again\n";
        }
        cout << "Please enter the\tLABEL\ton button positon:\t";
        switch (match)
        {// The 6 positions to read the label from, then another text input before a long string output
        case 1: // Top Left
            cout << "Top Left\n";
            break;
        case 2: // Top Right
            cout << "Top Right\n";
            break;
        case 3: // Middle Left
            cout << "Middle Left\n";
            break;
        case 4: // Middle Right
            cout << "Middle Right\n";
            break;
        case 5: // Bottom Left
            cout << "Bottom Left\n";
            break;
        case 6: // Bottom Right
            cout << "Bottom Right\n";
            break;
        }
        match = -1;
        while (match == -1)
        {
            getline(cin, input);
            for (int i = 0; i < input.length(); i++) { input[i] = toupper(input[i]); } // force upper case
            int i = 0;
            while (i < 28 && match == -1)
            {
                if (answers_p2[i] == input)
                {
                    cout << endl << result_p2[i] << endl << endl; // Output the final part
                    match = i; // Break out of loop
                }
                i++;
            }
            if (match == -1) cout << "Invalid Input. Please Try Again\n";
        }
        cout << "Enter 0 to return to the menu\n";
    }
}

/**
* Allows the user to enter a string of letters to be translated to different colors to click in sequence to solve the Simon Says puzzle
* @param None
* @return None
*/
void Simon() // https://ktane.fandom.com/wiki/Simon_Says
{ // handle letter input with multiple letters input at one time - only prompt once all previous input has been parsed - 3 to 5 stages - keep going until exit code
    // Allow for strike count to be changed any time
    cout << "How many strikes does the bomb have?\nIf greater than 2, only enter 3\n";
    int strikes = clean_input(3, 0);
    string input = "";
    bool vowel = false;
    for (int i = 0; i < serial(2); i++) { if (serial(1, i) == 'A' || serial(1, i) == 'E' || serial(1, i) == 'I' || serial(1, i) == 'O' || serial(1, i) == 'U') vowel = true; }
    bool loop = true;
    while (loop)
    {
        cout << "Please enter a letter for the corresponding option\nE: Exit\nS: Update Strikes\nB: Blue\nR: Red\nY: Yellow\nG: Green\n";
        cin >> input;
        for (int i = 0; i < input.length(); i++) { input[i] = toupper(input[i]); } // force upper case on input
        int i = 0;
        while (i < input.length() && input[i] != 'E') // loop through all letters input, stopping at the end or when the exit input is reached
        {
            if (vowel) // Vowel in Serial Number
            {
                switch (input[i])
                {
                case 'S':
                    cout << "How many strikes does the bomb have?\nIf greater than 2, only enter 3\n";
                    strikes = clean_input(3, 0);
                    break;
                case 'B':
                    if (strikes == 0) cout << "Red" << endl; // No Strikes
                    else if (strikes == 1) cout << "Green" << endl; // 1 Strike
                    else cout << "Blue" << endl; // 2 or more Strikes
                    break;
                case 'R':
                    if (strikes == 0) cout << "Blue" << endl; // No Strikes
                    else if (strikes == 1) cout << "Yellow" << endl; // 1 Strike
                    else cout << "Green" << endl; // 2 or more Strikes
                    break;
                case 'Y':
                    if (strikes == 0) cout << "Green" << endl; // No Strikes
                    else if (strikes == 1) cout << "Red" << endl; // 1 Strike
                    else cout << "Blue" << endl; // 2 or more Strikes
                    break;
                case 'G':
                    if (strikes == 0) cout << "Yellow" << endl; // No Strikes
                    else if (strikes == 1) cout << "Blue" << endl; // 1 Strike
                    else cout << "Yellow" << endl; // 2 or more Strikes
                    break;
                default:
                    break;
                }
            }
            else // No vowel in serial number
            {
                switch (input[i])
                {
                case 'S':
                    cout << "How many strikes does the bomb have?\nIf greater than 2, only enter 3\n";
                    strikes = clean_input(3, 0);
                    break;
                case 'B':
                    if (strikes == 0) cout << "Yellow" << endl; // No Strikes
                    else if (strikes == 1) cout << "Blue" << endl; // 1 Strike
                    else cout << "Green" << endl; // 2 or more Strikes
                    break;
                case 'R':
                    if (strikes == 0) cout << "Blue" << endl; // No Strikes
                    else if (strikes == 1) cout << "Red" << endl; // 1 Strike
                    else cout << "Yellow" << endl; // 2 or more Strikes
                    break;
                case 'Y':
                    if (strikes == 0) cout << "Red" << endl; // No Strikes
                    else if (strikes == 1) cout << "Green" << endl; // 1 Strike
                    else cout << "Red" << endl; // 2 or more Strikes
                    break;
                case 'G':
                    if (strikes == 0) cout << "Green" << endl; // No Strikes
                    else if (strikes == 1) cout << "Yellow" << endl; // 1 Strike
                    else cout << "Blue" << endl; // 2 or more Strikes
                    break;
                default:
                    break;
                }
            }
            i++;
        }
        if (input[i] == 'E') loop = false;
    }
}

/**
* Prompt user to input LEDs shown on module, then determines and outputs which direction knob should be turned to
* @param None
* @return None
*/
void Knob()//https://ktane.fandom.com/wiki/Knob
{
    // input the 12 inputs
    // find a (general)match and output
    int input;
    bool leds[12] = { false, false, false, false, false, false,  false, false, false, false, false, false };
    cout << "Please enter the LED positions separated by spaces that are lit according the following arrangement:\n1          11\n2 3     9  12\n  4 5 7 10   \n    6 8      \n";
    while (cin >> input)// gather all input from user and parse into the bool array
    {
        if (input > 0 && input < 13) // ignore input that is out of bounds
        {
            leds[input - 1] = true;
        }
    }
    if (leds[3 - 1] == false && leds[5 - 1] == true && leds[6 - 1] == true && leds[7 - 1] == false) { cout << "Up Position\n"; }
    else if (leds[5 - 1] == false && leds[7 - 1] == false) { cout << "Left Position\n"; }
    else if (leds[5 - 1] == true && leds[7 - 1] == true) { cout << "Right Position\n"; }
    else if (leds[1 - 1] == true && leds[2 - 1] == false && leds[3 - 1] == false && leds[4 - 1] == true && leds[5 - 1] == true && leds[6 - 1] == false && leds[7 - 1] == false && leds[8 - 1] == false && leds[9 - 1] == true && leds[10 - 1] == false && leds[11 - 1] == false && leds[12 - 1] == true) { cout << "Down Position\n"; }
    else if (leds[1 - 1] == false && leds[2 - 1] == true && leds[3 - 1] == true && leds[4 - 1] == true && leds[5 - 1] == true && leds[6 - 1] == true && leds[7 - 1] == false && leds[8 - 1] == true && leds[9 - 1] == false && leds[10 - 1] == false && leds[11 - 1] == true && leds[12 - 1] == true) { cout << "Down Position\n"; }
    else { cout << "Error: No Combination found for Input\n"; }
    return;
}

/**
* Prompt user for x,y coordinate inputs for 4 key maze data points using maze input, then call maze hunter to find path, then print out path
* @param None
* @return None
*/
void Maze() // https://ktane.fandom.com/wiki/Maze - Test Data: 1 2 6 3 1 1 1 2
{ // 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
    int mazes[9][13][13]{ { {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 1 | 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
{1,0,2,0,2,0,1,0,2,0,2,0,1}, // 1
{3,2,3,1,3,2,3,2,3,1,3,1,3},
{1,5,1,0,2,0,1,0,2,0,2,0,1}, // 2
{3,2,3,2,3,1,3,1,3,1,3,2,3},
{1,0,1,0,2,0,1,0,2,0,2,5,1}, // 3
{3,2,3,1,3,2,3,2,3,1,3,2,3},
{1,0,1,0,2,0,2,0,1,0,2,0,1}, // 4
{3,2,3,1,3,1,3,1,3,1,3,2,3},
{1,0,2,0,2,0,1,0,2,0,1,0,1}, // 5
{3,2,3,1,3,2,3,2,3,1,3,2,3},
{1,0,2,0,1,0,2,0,1,0,2,0,1}, // 6
{3,1,3,1,3,1,3,1,3,1,3,1,3} },
{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 2 | 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
{1,0,2,0,2,0,1,0,2,0,2,0,1}, // 1
{3,1,3,2,3,1,3,2,3,2,3,1,3},
{1,0,2,0,1,0,2,0,1,5,2,0,1}, // 2
{3,2,3,1,3,2,3,1,3,1,3,2,3},
{1,0,1,0,2,0,1,0,2,0,2,0,1}, // 3
{3,2,3,2,3,1,3,2,3,1,3,2,3},
{1,0,2,5,1,0,2,0,1,0,1,0,1}, // 4
{3,2,3,1,3,2,3,1,3,2,3,2,3},
{1,0,1,0,1,0,1,0,2,0,1,0,1}, // 5
{3,2,3,2,3,2,3,2,3,1,3,2,3},
{1,0,1,0,2,0,1,0,2,0,2,0,1}, // 6
{3,1,3,1,3,1,3,1,3,1,3,1,3} },
{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 3 | 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
{1,0,2,0,2,0,1,0,1,0,2,0,1}, // 1
{3,2,3,1,3,2,3,2,3,2,3,2,3},
{1,0,1,0,1,0,1,0,2,0,1,0,1}, // 2
{3,1,3,2,3,2,3,1,3,1,3,2,3},
{1,0,2,0,1,0,1,0,2,0,1,0,1}, // 3
{3,2,3,2,3,2,3,2,3,2,3,2,3},
{1,0,1,0,1,0,1,5,1,0,1,5,1}, // 4
{3,2,3,2,3,2,3,2,3,2,3,2,3},
{1,0,1,0,2,0,1,0,1,0,1,0,1}, // 5
{3,2,3,1,3,1,3,2,3,2,3,2,3},
{1,0,2,0,2,0,2,0,1,0,2,0,1}, // 6
{3,1,3,1,3,1,3,1,3,1,3,1,3} },
{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 4 | 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
{1,5,2,0,1,0,2,0,2,0,2,0,1}, // 1
{3,2,3,2,3,1,3,1,3,1,3,2,3},
{1,0,1,0,1,0,2,0,2,0,2,0,1}, // 2
{3,2,3,2,3,2,3,1,3,1,3,2,3},
{1,0,1,0,2,0,1,0,2,0,1,0,1}, // 3
{3,2,3,1,3,1,3,2,3,1,3,2,3},
{1,5,1,0,2,0,2,0,2,0,2,0,1}, // 4
{3,2,3,1,3,1,3,1,3,1,3,2,3},
{1,0,2,0,2,0,2,0,2,0,1,0,1}, // 5
{3,2,3,1,3,1,3,1,3,2,3,2,3},
{1,0,2,0,2,0,1,0,2,0,1,0,1}, // 6
{3,1,3,1,3,1,3,1,3,1,3,1,3} },
{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 5 | 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
{1,0,2,0,2,0,2,0,2,0,2,0,1}, // 1
{3,1,3,1,3,1,3,1,3,2,3,2,3},
{1,0,2,0,2,0,2,0,2,0,1,0,1}, // 2
{3,2,3,1,3,1,3,2,3,1,3,1,3},
{1,0,2,0,1,0,2,0,1,5,2,0,1}, // 3
{3,2,3,2,3,1,3,1,3,2,3,2,3},
{1,0,1,0,2,0,2,0,1,0,1,0,1}, // 4
{3,2,3,1,3,1,3,2,3,1,3,2,3},
{1,0,1,0,2,0,2,0,2,0,1,0,1}, // 5
{3,2,3,2,3,1,3,1,3,1,3,2,3},
{1,0,1,0,2,0,2,5,2,0,2,0,1}, // 6
{3,1,3,1,3,1,3,1,3,1,3,1,3} },
{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 6 | 0: Space | 1 : Border | 2 : Open Border | 3 : Null | 4 : TBD | 5 : Marker
{1,0,1,0,2,0,1,0,2,5,2,0,1}, // 1
{3,2,3,2,3,2,3,1,3,2,3,2,3},
{1,0,1,0,1,0,1,0,2,0,1,0,1}, // 2
{3,2,3,2,3,2,3,2,3,1,3,2,3},
{1,0,2,0,1,0,1,0,1,0,2,0,1}, // 3
{3,2,3,1,3,1,3,2,3,2,3,1,3},
{1,0,2,0,1,0,2,0,1,0,1,0,1}, // 4
{3,1,3,2,3,2,3,2,3,2,3,2,3},
{1,0,2,0,1,5,1,0,1,0,2,0,1}, // 5
{3,2,3,1,3,1,3,2,3,1,3,2,3},
{1,0,2,0,2,0,2,0,1,0,2,0,1}, // 6
{3,1,3,1,3,1,3,1,3,1,3,1,3} },
{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 7 | 0: Space | 1 : Border | 2 : Open Border | 3 : Null | 4 : TBD | 5 : Marker
{1,0,2,5,2,0,2,0,1,0,2,0,1}, // 1
{3,2,3,1,3,1,3,2,3,2,3,2,3},
{1,0,1,0,2,0,1,0,2,0,1,0,1}, // 2
{3,2,3,2,3,1,3,1,3,1,3,2,3},
{1,0,2,0,1,0,2,0,1,0,2,0,1}, // 3
{3,1,3,1,3,2,3,1,3,2,3,1,3},
{1,0,2,0,1,0,2,0,2,0,1,0,1}, // 4
{3,2,3,2,3,2,3,1,3,1,3,2,3},
{1,0,1,0,1,0,2,0,2,0,1,0,1}, // 5
{3,2,3,1,3,1,3,1,3,2,3,2,3},
{1,0,2,5,2,0,2,0,2,0,2,0,1}, // 6
{3,1,3,1,3,1,3,1,3,1,3,1,3} },
{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 8 | 0: Space | 1 : Border | 2 : Open Border | 3 : Null | 4 : TBD | 5 : Marker
{1,0,1,0,2,0,2,5,1,0,2,0,1}, // 1
{3,2,3,2,3,1,3,2,3,2,3,2,3},
{1,0,2,0,2,0,1,0,2,0,1,0,1}, // 2
{3,2,3,1,3,1,3,1,3,1,3,2,3},
{1,0,1,0,2,0,2,0,2,0,1,0,1}, // 3
{3,2,3,2,3,1,3,1,3,2,3,2,3},
{1,0,1,0,2,5,1,0,2,0,2,0,1}, // 4
{3,2,3,1,3,2,3,1,3,1,3,1,3},
{1,0,1,0,1,0,2,0,2,0,2,0,1}, // 5
{3,2,3,2,3,1,3,1,3,1,3,1,3},
{1,0,2,0,2,0,2,0,2,0,2,0,1}, // 6
{3,1,3,1,3,1,3,1,3,1,3,1,3} },
{ {3,1,3,1,3,1,3,1,3,1,3,1,3}, // Maze 9 | 0: Space | 1 : Border | 2 : Open Border | 3 : Null | 4 : TBD | 5 : Marker
{1,0,1,0,2,0,2,0,2,0,2,0,1}, // 1
{3,2,3,2,3,1,3,1,3,2,3,2,3},
{1,0,1,0,1,5,2,0,1,0,1,0,1}, // 2
{3,2,3,2,3,2,3,1,3,2,3,2,3},
{1,0,2,0,2,0,1,0,2,0,1,0,1}, // 3
{3,2,3,1,3,1,3,2,3,1,3,2,3},
{1,0,1,0,1,0,2,0,1,0,2,0,1}, // 4
{3,2,3,2,3,2,3,1,3,1,3,2,3},
{1,5,1,0,1,0,1,0,2,0,1,0,1}, // 5
{3,2,3,2,3,2,3,2,3,2,3,1,3},
{1,0,2,0,1,0,2,0,1,0,2,0,1}, // 6
{3,1,3,1,3,1,3,1,3,1,3,1,3} } }; // 0: Space | 1: Border | 2: Open Border | 3: Null | 4: TBD | 5: Marker
// Nearly 6KB of Data stored in the mazes array
                            /*
                            cout << mazes[0][1][3] << endl << mazes[0][11][5] << endl;
                            for (int Row = 1; Row < 12; Row += 2) // check all rows with valid positions in each maze
                            {
                                string test = "Row: ";
                                for (int Column = 1; Column < 12; Column += 2) // check all columns with valid positions in each row in each maze
                                {
                                    cout << mazes[0][Row][Column] << " ";
                                    if (mazes[0][Row][Column] == 5) test.append(to_string(Row) + " Column: " + to_string(Column));
                                }
                                cout << "\t" << test << endl;
                            }
                            */
    int mazeNumber = -1;
    int identifiers[2][2] = {}; // 2 x,y pairs for the two identifier marks
    int positions[2][2] = {}; // 2 x,y pairs for the start and end positions | 0 = start | 1 = end

    while (mazeNumber == -1) // loop until a valid maze is selected
    {
        //input identifiers from user
        mazeInput(identifiers[0], "the first identifier (green circle)");
        mazeInput(identifiers[1], "the second identifier (green circle)");

        //ignore duplicate inputs
        if (identifiers[0][0] == identifiers[1][0] && identifiers[0][1] == identifiers[1][1]) cout << "Error: Only one unique identifier detected\nPlease Try Again\n";
        else
        {
            //identify maze
            for (int MazeCount = 0; MazeCount < 9; MazeCount++) // Loop through all 9 mazes and check if the two given identifiers point to a valid maze
            {
                if (mazes[MazeCount][identifiers[0][1]][identifiers[0][0]] == 5 && mazes[MazeCount][identifiers[1][1]][identifiers[1][0]] == 5) mazeNumber = MazeCount;
                //cout << endl << MazeCount << endl << mazeNumber << endl << endl << identifiers[0][0] << ", " << identifiers[0][1] << endl << identifiers[1][0] << ", " << identifiers[1][1];
            }
            if (mazeNumber == -1) cout << "Invalid positions entered\nNo corresponding maze found\nPlease Try Again\n";
        }
    }

    //input start and end from user
    mazeInput(positions[0], "the current position (white square)");
    mazeInput(positions[1], "the target position (red triangle)");

    //determine route recursively
    cout << "\nOutput: " << maze_hunter(mazeNumber, mazes, positions, -1, positions[0][0], positions[0][1]) << endl;
}

/**
* Takes in a string of 1 (dot) and 2 (dash) and determines which one (or ones) it most closely matches from the reference table
* @param A clean input from a different dedicated function
* @return None
*/
void Morse(string input) {
    //String Morse Answers-   Shells                Halls               Slick              Trick           Boxes             Leaks           Strobe            Bistro             Flick               Bombs              Break           Brick              Steak        Sting         Vector             Beats
    //Frequencies-            3.505                 3.515               3.522              3.532           3.535             3.542           3.545             3.552              3.555               3.565              3.572           3.572              3.582        3.592         3.595              3.600
    string StrKeywords[16] = { "1111111112111211111","11111212111211111","1111211112121212","2121112121212","211122221121111","1211112212111","111212122221111","2111111112121222","11211211112121212","2111222222111111","2111121112212","2111121112121212","1112112212","11121121221","1112121212222121","21111122111" };
    int IntKeywords[16] =    {  1111111112111211111 , 11111212111211111 , 1111211112121212 , 2121112121212 , 211122221121111 , 1211112212111 , 111212122221111 , 2111111112121222 , 11211211112121212 , 2111222222111111 , 2111121112212 , 2111121112121212 , 1112112212 , 11121121221 , 1112121212222121 , 21111122111 };
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
        cout << "Unique Length Match" << endl << "Steak- 3.582";
        break;
    case 19:
        cout << "Unique Length Match" << endl << "Shells- 3.505";
        break;
    case 17:
        if (morse == StrKeywords[1]) {
            cout << "Perfect Match" << endl << "Halls- 3.515";
        }
        else if (morse == StrKeywords[8]) {
            cout << "Perfect Match" << endl << "Flick- 3.555";
        }
        else {
            if (morse_compare(morse, StrKeywords[1], 10, 16) == 0) {
                cout << "Main Window Match" << endl << "Halls - 3.515";
            }
            else if (morse_compare(morse, StrKeywords[8], 10, 16) == 0) {
                cout << "Main Window Match" << endl << "Flick- 3.555";
            }
            else {
                if (morse_compare(morse, StrKeywords[1], 2, 7) == 0) {
                    cout << "Secondary Window Match" << endl << "Halls - 3.515";
                }
                else if (morse_compare(morse, StrKeywords[8], 2, 7) == 0) {
                    cout << "Secondary Window Match" << endl << "Flick- 3.555";
                }
                else {
                    int error_tally[2] = { morse_compare(morse, StrKeywords[1], 0, 16), morse_compare(morse, StrKeywords[8], 0, 16) };
                    string error_str[2] = { "Halls", "Flick" };
                    if (error_tally[0] < error_tally[1]) {
                        cout << error_tally[0] << " Errors, Halls- 3.515" << endl << error_tally[1] << " Errors, Flick- 3.555";
                    }
                    else {
                        cout << error_tally[1] << " Errors, Flick- 3.555" << endl << error_tally[0] << " Errors, Halls- 3.515";
                    }
                }
            }
        }
        break;
    case 16:
        if (morse == StrKeywords[2]) {
            cout << "Perfect Match" << endl << "Slick- 3.522";
        }
        else if (morse == StrKeywords[7]) {
            cout << "Perfect Match" << endl << "Bistro- 3.552";
        }
        else if (morse == StrKeywords[9]) {
            cout << "Perfect Match" << endl << "Bombs- 3.565";
        }
        else if (morse == StrKeywords[11]) {
            cout << "Perfect Match" << endl << "Brick- 3.572";
        }
        else if (morse == StrKeywords[14]) {
            cout << "Perfect Match" << endl << "Vector- 3.595";
        }
        else {
            if (morse_compare(morse, StrKeywords[2], 0, 8) == 0) {
                cout << "Main Window Match" << endl << "Slick- 3.522";
            }
            else if (morse_compare(morse, StrKeywords[7], 0, 8) == 0) {
                cout << "Main Window Match" << endl << "Bistro- 3.552";
            }
            else if (morse_compare(morse, StrKeywords[9], 0, 8) == 0) {
                cout << "Main Window Match" << endl << "Bombs- 3.565";
            }
            else if (morse_compare(morse, StrKeywords[11], 0, 8) == 0) {
                cout << "Main Window Match" << endl << "Brick- 3.575";
            }
            else if (morse_compare(morse, StrKeywords[14], 0, 8) == 0) {
                cout << "Main Window Match" << endl << "Vector- 3.595";
            }
            else {
                if (morse_compare(morse, StrKeywords[2], 10, 15) == 0) {
                    cout << "Secondary Window Match" << endl << "Slick- 3.522";
                }
                else if (morse_compare(morse, StrKeywords[7], 10, 15) == 0) {
                    cout << "Secondary Window Match" << endl << "Bistro- 3.552";
                }
                else if (morse_compare(morse, StrKeywords[9], 10, 15) == 0) {
                    cout << "Secondary Window Match" << endl << "Bombs- 3.565";
                }
                else if (morse_compare(morse, StrKeywords[11], 10, 15) == 0) {
                    cout << "Secondary Window Match" << endl << "Brick- 3.575";
                }
                else if (morse_compare(morse, StrKeywords[14], 10, 15) == 0) {
                    cout << "Secondary Window Match" << endl << "Vector- 3.595";
                }
                else {
                    int err_arr[5] = { morse_compare(morse, StrKeywords[2], 0, 15),
                                       morse_compare(morse, StrKeywords[7], 0, 15),
                                       morse_compare(morse, StrKeywords[9], 0, 15),
                                       morse_compare(morse, StrKeywords[11], 0, 15),
                                       morse_compare(morse, StrKeywords[14], 0, 15) };
                    string str_err[5] = { "Slick- 3.522","Bistro- 3.552","Bombs- 3.565","Brick- 3.575","Vector- 3.595" };
                    bubble_sort(err_arr, str_err, 5);
                    for (int i = 0; i < 5; i++) {
                        cout << err_arr[i] << " Errors, " << str_err[i] << endl;
                    }
                }
            }
        }
        break;
    case 15:
        if (morse == StrKeywords[4]) {
            cout << "Perfect Match" << endl << "Boxes- 3.535";
        }
        else if (morse == StrKeywords[6]) {
            cout << "Perfect Match" << endl << "Strobe- 3.545";
        }
        else {
            if (morse_compare(morse, StrKeywords[4], 3, 10) == 0) {
                cout << "Main Window Match" << endl << "Boxes- 3.535";
            }
            else if (morse_compare(morse, StrKeywords[6], 3, 10) == 0) {
                cout << "Main Window Match" << endl << "Strobe- 3.545";
            }
            else {
                if (morse_compare(morse, StrKeywords[4], 0, 3) == 0) {
                    cout << "Secondary Window Match" << endl << "Boxes - 3.535";
                }
                else if (morse_compare(morse, StrKeywords[6], 0, 3) == 0) {
                    cout << "Secondary Window Match" << endl << "Strobe- 3.545";
                }
                else {
                    int err_arr[2] = { morse_compare(morse, StrKeywords[4], 0, 3),morse_compare(morse, StrKeywords[6], 0, 3) };
                    string str_arr[2] = { "Boxes- 3.535", "Strobe- 3.545" };
                    bubble_sort(err_arr, str_arr, 2);
                    for (int i = 0; i < 2; i++) {
                        cout << err_arr[i] << " Errors, " << str_arr[i] << endl;
                    }
                }
            }
        }
        break;
    case 13:
        if (morse == StrKeywords[3]) {
            cout << "Perfect Match" << endl << "Trick- 3.532";
        }
        else if (morse == StrKeywords[5]) {
            cout << "Perfect Match" << endl << "Leaks- 3.542";
        }
        else if (morse == StrKeywords[10]) {
            cout << "Perfect Match" << endl << "Break- 3.572";
        }
        else {
            if (morse_compare(morse, StrKeywords[3], 5, 10) == 0) {
                cout << "Main Window Match" << endl << "Trick- 3.532";
            }
            else if (morse_compare(morse, StrKeywords[5], 5, 10) == 0) {
                cout << "Main Window Match" << endl << "Leaks- 3.542";
            }
            else if (morse_compare(morse, StrKeywords[10], 5, 10) == 0) {
                cout << "Main Window Match" << endl << "Break- 3.542";
            }
            else {
                if (morse_compare(morse, StrKeywords[3], 0, 2) == 0) {
                    cout << "Secondary Window Match" << endl << "Trick- 3.532";
                }
                else if (morse_compare(morse, StrKeywords[5], 0, 2) == 0) {
                    cout << "Secondary Window Match" << endl << "Leaks- 3.542";
                }
                else if (morse_compare(morse, StrKeywords[10], 0, 2) == 0) {
                    cout << "Secondary Window Match" << endl << "Break- 3.542";
                }
                else {
                    int err_arr[3] = { morse_compare(morse, StrKeywords[3], 0, 12), morse_compare(morse, StrKeywords[5], 0, 12), morse_compare(morse, StrKeywords[10], 0, 12) };
                    string str_arr[3] = { "Trick- 3.532", "Leaks- 3.542", "Break- 3.572" };
                    bubble_sort(err_arr, str_arr, 3);
                    for (int i = 0; i < 3; i++) {
                        cout << err_arr[i] << " Errors, " << str_arr[i] << endl;
                    }
                }
            }
        }
        break;
    case 11:
        if (morse == StrKeywords[13]) {
            cout << "Perfect Match" << endl << "Sting- 3.592";
        }
        else if (morse == StrKeywords[15]) {
            cout << "Perfect Match" << endl << "Beats- 3.600";
        }
        else {
            if (morse_compare(morse, StrKeywords[13], 6, 9) == 0) {
                cout << "Main Window Match" << endl << "Sting- 3.592";
            }
            else if (morse_compare(morse, StrKeywords[15], 6, 9) == 0) {
                cout << "Main Window Match" << endl << "Beats- 3.600";
            }
            else {
                if (morse_compare(morse, StrKeywords[13], 0, 3 == 0)) {
                    cout << "Secondary Window Match" << endl << "Sting- 3.592";
                }
                else if (morse_compare(morse, StrKeywords[15], 0, 3) == 0) {
                    cout << "Secondary Window Match" << endl << "Beats- 3.600";
                }
                else {
                    int err_arr[2] = { morse_compare(morse, StrKeywords[13], 0, 10), morse_compare(morse, StrKeywords[15], 0, 10) };
                    string str_arr[2] = { "Sting- 3.592", "Beats- 3.600" };
                    bubble_sort(err_arr, str_arr, 2);
                    for (int i = 0; i < 2; i++) {
                        cout << err_arr[i] << " Errors, " << str_arr[i] << endl;
                    }
                }
            }
        }
        break;
    default:
        int length = input.length();
        if (length <= 9 || length >= 20) {
            cout << "Error detected, invalid length, exiting";
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
}