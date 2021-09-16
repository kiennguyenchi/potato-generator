/*
* This program is A Static Site Generator (SSG) Tool coded in C++ language.
* Author: Chi Kien Nguyen
* Git Hub: https://github.com/kiennguyenchi/potato-generator 
*/

/* This is the file containing functionalities of a main page */
#include <iostream>
#include <vector>
#include <filesystem>
#include "HTMLFile.h"
using namespace std;
namespace fs = std::filesystem;

class MainPage{
    string folderName;
    vector<HTMLFile> sites;
	string htmlFile;
public:
    MainPage(){
        folderName = "";
        htmlFile = "";
    }
    void setMainPage(string name, vector<string> textFiles);
    string getMainPage();
    void displayMainPage();
    void setHTMLMainPage();
    void writeHTML();
    void setFolderName(string name);
    string getFolderName();
};
