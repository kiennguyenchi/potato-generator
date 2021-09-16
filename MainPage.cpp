/*
* This program is A Static Site Generator (SSG) Tool coded in C++ language.
* Author: Chi Kien Nguyen
* Git Hub: https://github.com/kiennguyenchi/potato-generator 
*/

/* This is the file containing functionalities of a main page */
#include "MainPage.h"

//this function sets up main page and linked websites
void MainPage::setMainPage(string name, vector<string> textFiles){
    setFolderName(name);
    for (int i = 0; i < textFiles.size();i++){
        HTMLFile newFile;
        newFile.openFile(textFiles.at(i));
        newFile.setHtmlFile();
        string fileName = textFiles.at(i).substr(textFiles.at(i).find(folderName) + 2, textFiles.at(i).size() - 2);
        newFile.writeHTML();
        sites.push_back(newFile);
    }
    setHTMLMainPage();
}

//this function returns html main page in string
string MainPage:: getMainPage(){
    return htmlFile;
}

//this function displays html page
void MainPage:: displayMainPage(){
    cout << htmlFile << endl;
}

//this function sets up html main page
void MainPage::setHTMLMainPage(){
    htmlFile ="<!doctype html><html lang='en'>\n<head>\n\t<meta charset='utf-8'>\n";
    htmlFile += ("\t<title>" + getFolderName() + "</title>\n");
    htmlFile += ("<link rel='stylesheet' href='../pgprogram.css'>");
    htmlFile += "\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n</head>\n";
    htmlFile += ("\n<body>\n\t<div><h1>"+getFolderName()+"</h1></div><br>\n");
    for(int i=0; i < sites.size(); i++){
            htmlFile += ("\t\t<div id='menu'><a href='" + sites.at(i).getURL() + "'>" + sites.at(i).getTitle() + "</a></div>\n");
    }
    htmlFile += "\n</body>\n</html>";
}

//this function writes HTML main page
void MainPage:: writeHTML(){
    string name = "dist/";
    name += (getFolderName() +".html");
    ofstream file(name);
    file << getMainPage() << endl;
    file.close();
}

//this function sets up folder name
void MainPage::setFolderName(string name){
    folderName = name;
}

//this function returns folder name
string MainPage::getFolderName(){
    return folderName;
}