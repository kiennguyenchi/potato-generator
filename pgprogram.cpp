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

void createOneHTML(string filename, string outPath, string lang);
void createManyHTML(string folderName, string outPath, string lang);
string checkArguments(int argc, char** argv);
string checkLanguage(int argc, char** argv);
bool checkIfConfig(int argc, char** argv);
void makeDir(string outputDir);
string readConfig(string fileName);


int main(int argc, char** argv)
{    

    if(argc >= 2){
        string language = checkLanguage(argc, argv);
        string name = checkArguments(argc, argv);
        string temp = readConfig(name);
        bool configFlag = checkIfConfig(argc, argv);

        //if empty config
        if (configFlag == true && temp.find("\"") == string::npos) {
            name = "terminate";
        }

        if (name != "terminate") {
            if (name == "")
                name = argv[1];
            
            string outFolder = "./dist";
            //if output folder is specified in config file
            if (temp.find("output") != string::npos) {  
                size_t start = temp.find("output") + 12;
                size_t end = temp.find("\"", start - 1);
                outFolder = temp.substr(start, (end - start));
            }
            makeDir(outFolder);
            //get input from config file
            if (temp.find("input") != string::npos)
            {
                size_t start = temp.find("input") + 9;
                size_t end = temp.find("\"", start + 2);
                name = temp.substr(start, (end - start));
            }

            size_t folderOrFile = name.find(".txt");
            size_t mdFile = name.find(".md");

            if (configFlag || name.find("./") != string::npos) {
                createManyHTML(name, outFolder, language);
            }
            else if (name.find(".txt") != string::npos) {
                createOneHTML(name, outFolder, language);
            }
            else if (name.find(".md") != string::npos) {
                createOneHTML(name, outFolder, language);
            }
        }

        else {
            cout << "Empty config file. Please try again." << endl;
        }
    }
    else {
        cout << "Failed arguments provided";
    }
}

//this function creates a single HTML page
void createOneHTML(string filename,string outPath, string lang){
    HTMLFile newFile;
    newFile.openFile(filename, lang);
    newFile.setHtmlFile();
    newFile.writeHTML(outPath);
}

//this function creates multiple HTML page
void createManyHTML(string folderName, string outPath, string lang){
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
    string fName = "";
    
        if (string(argv[1]) == "--version" || string(argv[1]) == "-v") {
            cout << "Potato Generator - Version 0.1";
            fName = "terminate";
        }else if (string(argv[1]) == "--help" || string(argv[1]) == "-h"){
            cout << "*Run the program with command: ./pgprogram inputName\n";
            cout << "The inputName is a text file name or a folder name\n";
            cout << "*To include a input file/folder, include --input or -i before the file/folder name in the arguments.\n";
            cout << "*To specify an config file, use --config or -c before the config filename.\n";
            cout << "*To see the version of the program, include --version or -v in the arguments.\n";
            cout << "*To need help, include --help or -h in the arguments.\n";
            fName = "terminate";
        }else if (string(argv[1]) == "--input" || string(argv[1]) == "-i"){
            fName = argv[2];
        }
        else if (string(argv[1]) == "--config" || string(argv[1]) == "-c"){
            fName = argv[2];
        }
    
    return fName;
}

//this function checks for language specified
string checkLanguage(int argc, char** argv){
    string language = "";
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--lang" || string(argv[i]) == "-l"){
            language = argv[(i+1)];
            break;
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
    fs::remove_all("./dist");
    if (outputDir != "//dist") {
        outputDir = "./" + outputDir;
        fs::create_directory(outputDir);
    }
    else {
        fs::create_directory("./dist");
    }
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