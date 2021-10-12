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

void createHTMLFile(string filename, string outPath, string lang);
void createMainPageWithHTMLs(string folderName, string outPath, string lang);
string checkArguments(int argc, char** argv);
string checkLanguage(int argc, char** argv);
bool checkIfConfig(int argc, char** argv);
void makeDir(string outputDir);
string readConfig(string fileName);
string getOutputArgument(int argc, char** argv);
string getLangArgument(int argc, char** argv);


int main(int argc, char** argv)
{   
    if (argc >= 2){
        string name = checkArguments(argc, argv);
        if (name != "terminate"){
            bool configFlag = checkIfConfig(argc, argv);
            string outFolder = "./dist";
            string language = checkLanguage(argc, argv);
            bool valid = true;
            if(configFlag){
                string temp = readConfig(name);
                if(temp.find("\"") == string::npos){
                    cout << "Empty config file. Please try again." << endl;
                    valid = false;
                }else{
                    //get input from config file
                    if (temp.find("input") != string::npos)
                    {
                        size_t start = temp.find("input") + 9;
                        size_t end = temp.find("\"", start + 2);
                        name = temp.substr(start, (end - start));
                    } else {
                        valid = false;
                        cout << "There is no input file" << endl;
                    } 
                    //if output folder is specified in config file
                    if (temp.find("output") != string::npos) {  
                        size_t start = temp.find("output") + 12;
                        size_t end = temp.find("\"", start - 1);
                        outFolder = temp.substr(start, (end - start));
                    }
                    
                    if (temp.find("lang") != string::npos) {  
                        size_t start = temp.find("lang") + 8;
                        size_t end = temp.find("\"", start - 1);
                        language = temp.substr(start, (end - start));
                    }
                }
            }else{
                if (getOutputArgument(argc, argv) != "")
                    outFolder = getOutputArgument(argc, argv);
                if (getLangArgument(argc, argv) != "")
                    language = getLangArgument(argc, argv);
            }

            if (valid){
                makeDir(outFolder); 
                if (name.find(".txt") != string::npos || name.find(".md") != string::npos) {
                    createHTMLFile(name, outFolder, language);
                }
                else{
                    createMainPageWithHTMLs(name, outFolder, language);
                }
            }
        }
    }else {
        cout << "Failed arguments provided";
    }
}

//this function creates a single HTML page
void createHTMLFile(string filename,string outPath, string lang){   
    HTMLFile newFile;
    newFile.openFile(filename, lang);
    newFile.setHtmlFile();
    newFile.writeHTML(outPath);
}

//this function creates multiple HTML page
void createMainPageWithHTMLs(string folderName, string outPath, string lang){
    vector<string> fileNames;
    for (const auto& file : directory_iterator(folderName)) {
        fileNames.push_back(file.path().string());
        MainPage newPage;
        newPage.setMainPage(outPath, fileNames, lang);
        newPage.writeHTML(outPath);
    }       
}

//this function checks for arguments input
string checkArguments(int argc, char** argv){
    string fileName = "";
    
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--version" || string(argv[i]) == "-v") {
            cout << "Potato Generator - Version 0.1";
            fileName = "terminate";
            break;
        }
        else if (string(argv[i]) == "--help" || string(argv[i]) == "-h") {
            cout << "*Run the program with command: ./pgprogram inputName\n";
            cout << "The inputName is a text file name or a folder name\n";
            cout << "*To include a input file/folder, include --input or -i before the file/folder name in the arguments.\n";
            cout << "*To specify an config file, use --config or -c before the config filename.\n";
            cout << "*To see the version of the program, include --version or -v in the arguments.\n";
            cout << "*To need help, include --help or -h in the arguments.\n";
            fileName = "terminate";
            break;
        }
        else if (string(argv[i]) == "--input" || string(argv[i]) == "-i") {
            fileName = argv[i+1];
            break;
        }
        else if (string(argv[i]) == "--config" || string(argv[i]) == "-c") {
            fileName = argv[i+1]; 
            break;
        }
    }
        
    
    return fileName;
}


//this function checks for language specified
string checkLanguage(int argc, char** argv){
    string language = "";
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--lang" || string(argv[i]) == "-l") {
            language = argv[i+1];
        }
    }    
    return language;
}

bool checkIfConfig(int argc, char** argv) {
    bool config = false;
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--config" || string(argv[i]) == "-c") {
            config = true;
        }
    }    
    return config;
}

void makeDir(string outputDir) {
    fs::remove_all(outputDir);
    fs::create_directory(outputDir);
}

string readConfig(string fileName) {
    string storeConfig = "";
    ifstream configFile;
    configFile.open(fileName, ios::in);
    if (configFile.is_open()) {
        getline(configFile, storeConfig, '}');
        configFile.close();
    }
    return storeConfig;
}

string getOutputArgument(int argc, char** argv){
    string value = "";
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--output" || string(argv[i]) == "-o"){
            value = argv[i+1];
            break;
        }
    }
    return value;
}
string getLangArgument(int argc, char** argv){
    string value = "";
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--lang" || string(argv[i]) == "-l"){
            value = argv[i+1];
            break;
        }
    }
    return value;
}