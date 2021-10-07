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

void createOneHTML(string filename, string lang);
void createManyHTML(string folderName, string lang);
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
        if (name != "terminate") {
            if (name == "")
                name = argv[1];
            size_t folderOrFile = name.find(".txt");
            size_t mdFile = name.find(".md");

            //if output folder is specified
            if (readConfig(name).find("output")) {                  
                string temp = readConfig(name);
                string outFolder = temp.substr((temp.find("output") + 10), temp.find(("\"\"" - 1), temp.find("./")));
                std::cout << outFolder;
            }

            if (readConfig(name).find("input") != string::npos)
            {

            }

            if (folderOrFile > name.size()){
                if (mdFile > name.size()){
                    createManyHTML(name, language);
                }else{
                    createOneHTML(name, language);
                }
            }else{
                createOneHTML(name, language);
            }
        }

    }else{
        cout << "Failed arguments provided";
    }
}

//this function creates a single HTML page
void createOneHTML(string filename, string lang){
    HTMLFile newFile;
    newFile.openFile(filename, lang);
    newFile.setHtmlFile();
    newFile.writeHTML();
}

//this function creates multiple HTML page
void createManyHTML(string folderName, string lang){
    vector<string> fileNames;
    for (const auto & file : directory_iterator(folderName))
        fileNames.push_back(file.path().string());
    MainPage newPage;
    newPage.setMainPage(folderName, fileNames, lang);
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
            cout << "*Run the program with command: ./pgprogram inputName\n";
            cout << "The inputName is a text file name or a folder name\n";
            cout << "*To include a input file/folder, include --input or -i before the file/folder name in the arguments.\n";
            cout << "*To specify an config file, use --config or -c before the config filename.\n";
            cout << "*To see the version of the program, include --version or -v in the arguments.\n";
            cout << "*To need help, include --help or -h in the arguments.\n";
            fName = "terminate";
            break;
        }else if (string(argv[i]) == "--input" || string(argv[i]) == "-i"){
            fName = argv[(i+1)];
            break;
        }
        else if (string(argv[i]) == "--config" || string(argv[i]) == "-c"){
            fName = argv[(i + 1)];
            break;
        }
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
    if (outputDir != "") {
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