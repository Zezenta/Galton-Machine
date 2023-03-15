#include <iostream>
#include <cstdlib> // cnntains the system("pause") function
#include <random> // random numbres library
#include <string> // includes the string datatype

using namespace std;
string columns[21] = {};

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
    for (int i = 0; i < 800; i++) //this has to be the number of marbles
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
        reference = reference / 2;
        reference += 10;
        columns[reference] += "#";
    }
    for (int c = 0; c < 21; c++)
    {
        cout << columns[c] << "\n";
    }
}

int main()
{
    cout << "Hello, my name is Miguel Veliz, and you are now going to see a simple implementation of the Galton Machine." << "\n";
    cout << "But, what is a Galton Machine?, well, in few words, it is a bunch of marbles that have gone through a random process, but with an expected outcome." << "\n";
    cout << "Now, we are going to see the same process in c++." << "\n";
    cout << "Please, press the letter r in your keyboard and then press enter to restart the simulation" << "\n";

    string input_letter;
    cin >> input_letter;
    if(input_letter == "r")
    {
        machine();
    }
    system("pause");
}