#include <iostream>
#include <cstdlib> // cnntains the system("pause") function
#include <random> // random numbres library
#include <string> // includes the string datatype
#include <conio.h> // includes key functions

using namespace std;

void mimae()
{
    cout << "\n /$$$$$$$$                                                                    /$$       /$$      /$$                    \n|__  $$__/                                                                   |__/      | $$$    /$$$                    \n   | $$  /$$$$$$         /$$$$$$  /$$$$$$/$$$$   /$$$$$$        /$$$$$$/$$$$  /$$      | $$$$  /$$$$  /$$$$$$   /$$$$$$ \n   | $$ /$$__  $$       |____  $$| $$_  $$_  $$ /$$__  $$      | $$_  $$_  $$| $$      | $$ $$/$$ $$ |____  $$ /$$__  $$\n   | $$| $$$$$$$$        /$$$$$$$| $$   $$   $$| $$    $$      | $$   $$   $$| $$      | $$  $$$| $$  /$$$$$$$| $$$$$$$$\n   | $$| $$_____/       /$$__  $$| $$ | $$ | $$| $$  | $$      | $$ | $$ | $$| $$      | $$   $ | $$ /$$__  $$| $$_____/\n   | $$|  $$$$$$$      |  $$$$$$$| $$ | $$ | $$|  $$$$$$/      | $$ | $$ | $$| $$      | $$  /  | $$|  $$$$$$$|  $$$$$$$\n   |__/  _______/        _______/|__/ |__/ |__/  ______/       |__/ |__/ |__/|__/      |__/     |__/  _______/  _______/";
}

bool random_bool() {
    // Create a static instance of std::random_device to seed the random number generator
    static std::random_device rd;
    // Create a static instance of std::mt19937 random number generator
    static std::mt19937 gen(rd());
    // Create a static instance of std::uniform_int_distribution to generate random integers between 0 and 1 (inclusive)
    static std::uniform_int_distribution<> distrib(0, 1);
    // Generate a random integer using the distribution and return true if it is 1, false otherwise
    return distrib(gen) == 1;
}

void machine()
{
    string columns[21] = {};
    for (int i = 0; i < 300; i++) //this has to be the number of marbles
    {
        int reference = 0;
        for (int k = 0; k < 20; k++)
        {
            bool random_result = random_bool();
            if(random_result == true)
            {
                reference += 1;
            }
            else if (random_result == false)
            {
                reference -= 1;
            }
        }
        reference = reference / 2; //for some reason we always get a pair number, so to get around that problem, we execute twice the random iterations (20), and then divide by 2, so we get a truly random number between -10 and 10
        reference += 10;
        columns[reference] += "#";
    }
    for (int c = 0; c < 21; c++)
    {
        cout << columns[c] << "\n";
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
}

int main()
{
    cout << "Hello, my name is Miguel Veliz, and you are now going to see a simple implementation of the Galton Machine." << "\n";
    cout << "But, what is a Galton Machine?, well, in few words, it is a bunch of marbles that have gone through a random process, but with an expected outcome." << "\n";
    cout << "Now, we are going to see the same process in c++." << "\n";
    cout << "Please, press the letter R in your keyboard to start a simulation. You can repeat this process many times. Press X in your keyboard to close the program." << "\n";

    while (true) {
        // Read input from the user
        int key = getch();
        
        // Check if a key was pressed
        if (key != -1) {
            // Run the appropriate function based on the key value
            switch(key) {
                case 'r':
                    machine();
                break;
                case 'm':
                    mimae();
                break;
                case 'x':
                    return 0;
                break;
                default:
                    // Do nothing for other keys
                break;
            }
        }
    }
    system("pause");
}