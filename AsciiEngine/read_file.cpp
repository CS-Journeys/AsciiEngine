/*
 * read_file.cpp
 * 
 * "main" file for the AsciiEngine++
 * Asks for and compiles user input game file
*/
#include "Engine.h"

#include <fstream>

int main() {
    ifstream inputFile, launchFile;
    string fileName, gameName, line;

    //Engine launch art
    launchFile.open("AsciiEngine/lib/launch.txt");
    while (getline(launchFile, line)) {
        cout << line << endl;
        Sleep(100);
    }

    //Get input game file
    cout << "Enter Game File Path (with \".cpp\" extension): " << endl;
    getline(cin, fileName);

    //Get output executable name
    cout << "Enter Game Project Name (omit file extension): " << endl;
    cin >> gameName;

    //Open input game file
    inputFile.open(fileName);

    //Check inputfile opens and is a .cpp extension
    if (fileName.find(".cpp") == string::npos || !inputFile) {
        cout << "Error: Game file either not found or not a (.cpp) extension." << endl;
        return 1;
    }
    inputFile.close();
    
    //Compile command for game
    const string command = R"(g++ -static-libgcc -static-libstdc++ -o )" + gameName + ".exe" + R"( .\AsciiEngine\game_ext.cpp .\AsciiEngine\Engine.cpp )" + "\""+fileName+"\"";

    //Compile the input game
    system(command.c_str());
    cout << gameName << ".exe compiled successfully" << endl; //Confirmation message


    return 0;
}