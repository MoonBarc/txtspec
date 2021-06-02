#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "config.hpp"

using namespace std;

string center(string input) {
    string padding = "";
    int paddingRequired = (Config::LINE_LENGTH - input.length()) / 2;
    
    for (int i = 0; i < paddingRequired; i++)
    {
        padding.append(" ");
    }

    return padding.append(input);
}

int main() {

    int page = 1;
    int line = 0;
    string data;

    Config::createLines();
    cout << Config::getLine();
    cout << "Processing file...\n";

    ofstream OutputFile("out.txt");
    ifstream InputFile("in.txt");

    OutputFile << Config::getLine() << center(Config::generatePageIndicator(page++)) << Config::getPadding(true);

    while (getline(InputFile, data))
    {
        int n = data.length();
        char d[n+1];
        strcpy(d, data.c_str());
        string more_data;
        string wrapped = wrap(d, Config::LINE_LENGTH);
        stringstream ss(wrapped);
        while(getline(ss, more_data)) {
            line++;
            OutputFile << more_data << "\n";
            if(line % Config::PAGE_LENGTH == 0) {
                OutputFile << Config::getPadding(false) << Config::getLine() << center(Config::generatePageIndicator(page++)) << Config::getPadding(true);
            }
        }
    }
    
    OutputFile.close();
    InputFile.close();

    cout << "Done!\n" << Config::getLine();

    return 0;
};