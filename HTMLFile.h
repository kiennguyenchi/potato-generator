/*
* This program is A Static Site Generator (SSG) Tool coded in C++ language.
* Author: Chi Kien Nguyen
* Git Hub: https://github.com/kiennguyenchi/potato-generator 
*/

/* This is the file containing functionalities of a single HTML page */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
class HTMLFile
{
	vector<string> textFile;
	string htmlFile;
public:
    HTMLFile(){
        htmlFile = "";
    }

    void openFile(string fileName);
    vector<string> getTextFile();
    void displayTextFile();
    void setHtmlFile();
    string getHtmlFile();
    void displayHtmlFile();
    string getTitle();
    string getURL();
    void setHtmlHead(string title);
    void setHtmlBody(vector<string> file);
    void writeHTML();
};

