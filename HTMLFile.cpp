/*
* This program is A Static Site Generator (SSG) Tool coded in C++ language.
* Author: Chi Kien Nguyen
* Git Hub: https://github.com/kiennguyenchi/potato-generator 
*/

/* This is the file containing functionalities of a single HTML page */
#include "HTMLFile.h"

//this function opens and reads a text file
void HTMLFile::openFile(string fileName){
    ifstream externalFile;
    externalFile.open(fileName, ios::in);
    if (externalFile.is_open()){
        string temp = "";
        string para = "";
        while(getline(externalFile, temp)){
            if (temp == ""){
                textFile.push_back(para);
                para = "";
            }else{
                para += (" " + temp);
            }
            temp = "";
        }
        externalFile.close();
    }

}

//this function returns a text file with paragraphs in vector<string> type
vector<string> HTMLFile::getTextFile(){
    return textFile;
}

//this function prints the read text file
void HTMLFile::displayTextFile(){
    int pos = 0;
    while (pos < (textFile.size())){
        cout << textFile.at(pos++) << "\n";
    }
}

//this function sets up a HTML page
void HTMLFile::setHtmlFile(){
    setHtmlHead(getTextFile().at(0));
    setHtmlBody(getTextFile());
}

//this function displays HTML page
void HTMLFile::displayHtmlFile(){
    cout << htmlFile << endl;
}

//this function returns HTML page code
string HTMLFile::getHtmlFile(){
    return htmlFile;
}

//this function gets title of the page
string HTMLFile::getTitle(){
    return textFile.at(0).substr(1, textFile.at(0).size() - 1);
}

//this function gets URL of the page
string HTMLFile::getURL(){
    return (getTitle().substr(0, getTitle().find('.')) + ".html");
}

//this function sets up HTML Page header
void HTMLFile::setHtmlHead(string title){
    htmlFile ="<!doctype html><html lang='en'>\n<head>\n\t<meta charset='utf-8'>\n";
    htmlFile += ("\t<title>" + title + "</title>\n");
    htmlFile += ("<link rel='stylesheet' href='../pgprogram.css'>");
    htmlFile += "\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n</head>\n";
}

//this function sets up HTML Page body
void HTMLFile::setHtmlBody(vector<string> file){
    htmlFile += ("\n<body>\n\t<div><h1>" + file.at(0) + "</h1></div><br>\n\t<div>\n");
    for(int i=1; i < file.size(); i++){
            htmlFile += ("\t\t<p>" + file.at(i) + "</p><br>\n");
            if (file.at(i).find('#') != -1){
                file.at(i).erase(file.at(i).find('#'), 1);
                htmlFile += "<h1>" + file.at(i) + "</h1>";
            }
    }
    htmlFile += "\t</div>\n</body>\n</html>";
}

//this function creates HTML Page
void HTMLFile::writeHTML(){
    string name = "dist/" + getURL();
    ofstream file(name);
    file << getHtmlFile() << endl;
    file.close();
}