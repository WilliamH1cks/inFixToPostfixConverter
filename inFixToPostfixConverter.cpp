#include <iostream>
#include "converter.h"
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input;
    string infix = "";
    converter inToPost;
    input.open("InfixData.txt");
    if (!input)
        cout << "File does not exist." << endl;

    while (getline(input, infix))
    {
        cout << "Infix: " << infix << endl;
        cout << "Postfix: " << inToPost.convert(infix) << endl << endl;
    }

    input.close();
}
