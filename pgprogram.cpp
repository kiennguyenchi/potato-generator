/*
* This program is A Static Site Generator (SSG) Tool coded in C++ language.
* Author: Chi Kien Nguyen
* Git Hub: https://github.com/kiennguyenchi/potato-generator 
*/

/* This is the file containing main function to run the program */
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "MainPage.h"
using namespace std;
using std::filesystem::directory_iterator;
namespace fs = std::filesystem;

void createOneHTML(string filename);
void createManyHTML(string folderName);
string checkArguments(int argc, char** argv);

int main(int argc, char** argv)
{
    if(argc >= 2){
        string name = checkArguments(argc, argv);
        
        if (name != "terminate"){
            if (name == "")
                name = argv[1];
            size_t folderOrFile = name.find(".txt");
            size_t mdFile = name.find(".md");
            
            fs::remove_all("./dist");
            fs::current_path("./");
            fs::create_directory("dist");

            if (folderOrFile > name.size() || mdFile > name.size()){
                createManyHTML(name);
            }else{
                createOneHTML(name);
            }
        }

    }else{
        cout << "Failed arguments provided";
    }
}

//this function creates a single HTML page
void createOneHTML(string filename){
    HTMLFile newFile;
    newFile.openFile(filename);
    newFile.setHtmlFile();
    newFile.writeHTML();
}

//this function creates multiple HTML page
void createManyHTML(string folderName){
    vector<string> fileNames;
    for (const auto & file : directory_iterator(folderName))
        fileNames.push_back(file.path().string());
    MainPage newPage;
    newPage.setMainPage(folderName, fileNames);
    newPage.writeHTML();
}

//this function checks for arguments input
string checkArguments(int argc, char** argv){
    string fName = "";
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--version" || string(argv[i]) == "-v") {
            cout << "Potato Generator - Version 0.1";
            fName = "terminate";
            break;
        }else if (string(argv[i]) == "--help" || string(argv[i]) == "-h"){
            cout << "*Run the program with command: pgprogram inputName\n";
            cout << "The inputName is a text file name or a folder name\n";
            cout << "*To include a input file/folder, include --input or -i before the file/folder name in the arguments.\n";
            cout << "*To see the version of the program, include --version or -v in the arguments.\n";
            cout << "*To need help, include --help or -h in the arguments.\n";
            fName = "terminate";
            break;
        }else if (string(argv[i]) == "--input" || string(argv[i]) == "-i"){
            fName = argv[(i+1)];
            break;
        }
    }
    return fName;
}