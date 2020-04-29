//
// Created by PRINCE NDHLOVU on 4/18/20.
//

#include "DocumentParser.h"
#include "json.hpp"
#include "Porter2_Stemmer.h"
#include <sstream>
#include <algorithm>
#include <vetcor>
#include <string>
#include <dirent.h>
#include <iostream>
#include "../parser.hpp"

using namespace std;
using nlohmann::json;


DocumentParser::DocumentParser() {

}

int DocumentParser::getNumOfArticles() {
    return numOfArticles;
}

int DocumentParser::getNumOfIndexedWords() {
    return numOfIndexedWords;
}

int DocumentParser::getNumOfTotalWords() {
    return numOfTotalWords;
}

// Read the input data using the directory file path
void DocumentParser::readDirectory() {

    string directoryPath;
    cout << "Enter the name of the directory path for the Articles: ";
    cin >> directoryPath;

    if(directoryPath[directoryPath.size() - 1] != '/') {
        cout << "You missed a foward slash character '/' , I have added it for you \n";
        directoryPath = directoryPath + '/';
    }

    DIR* corpus;
    struct dirent* dir;

    char filePath[5000];

    while((corpus = opendir(directoryPath.c_str())) == nullptr){
        cout << "Could not open file directory:" << directoryPath << endl;
        cout << "Enter the name of the directory path  for the Articles: ";
        cin >> directoryPath;
    }

    while ((dir = readdir(corpus)) != nullptr){
        if(strncmp(dir->d_name, "..", 2)!= 0 && strncmp(dir->d_name, ".", 1) != 0){
            string fileName = dir->d_name;
            string fileId = fileName.substr(0, fileName.size()-5);
            string fileExtension = fileName.substr(fileName.size() -5, fileName.size());

            if(fileExtension == ".json"){
                numOfArticles++;
                strncpy(filePath, directoryPath.c_str(), 5000);
                strncat(filePath, "/",5000);
                strncat(filePath, dir->d_name, 5000);


                if(numOfArticles <= 12000){
                    parseArticles(filePath, directoryPath);
                }
            }
        }
    }
    closedir(corpus);
}

// Parsing the json element
void DocumentParser::parseArticles(const string fileDirectory , const string filePath) {

    ifstream articles(fileDirectory);
    string temp
    if(!articles.is_open()){
        cout << "The file path does not exist \n";
    }

    DocumentData data;
    json j;
    j = json::parse(articles);

    //articles >> j;

    while (j["body_text"]["text"].size() != NULL){

                text = j["body_text"]["text"].get<string>();

    }

    string line;
    stringstream ss(text);
    while (ss >> line){
        numOfTotalWords++;
        insertTreeWord(line, filePath);
    }

//    string row;
//    getline(articles, row);
//    while (!articles.eof()){
//        stringstream ss(row);
//       while (ss >> temp){
//           numOfTotalWords++;
//           insertTreeWord(temp, fileDirectory);
//       }
//       getline(articles, row);
//    }
    articles.close();
    cout << "words have been inserted into the AVL Tree \n";

}

AVLTree<Words> DocumentParser::getWords() {
    return wordsTree
}

string DocumentParser::getFilePath() {
    return filePaths;
}

// inserting parsed words into the AVL tree
void DocumentParser::insertTreeWord(string name, string fileName) {

    if(!stopWords.contains(name)){
        Words curr(name, fileName);
        if(curr.getQuery() != ""){
            if(!wordsTree.contains(curr)){
                numOfIndexedWords++;
                wordsTree.insert(curr);
            } else{
                wordsTree.find(curr).addFile(fileName);
            }
        }
    }
}

void DocumentParser::displayStatistics() {

}
void DocumentParser::setStopWords() {

    string word;
    ifstream stopFile("StopWords.txt");

    stopWords.clear();
    while(!stopFile.eof()){
        stopFile >> word;
        stopWords.insert(word);
    }

}

unordered_set<string> DocumentParser::getStopWords() {
    return  stopWords;
}

int DocumentParser::getAveOfIndexedWords() {

    int n =  0,  total = 0;
    for (auto i : averageWords){
        total = total + i;
        n++;
    }
    return total / n;

}

void DocumentParser::stemmingStrings( string& word) const{

    string key = word;

    if(stemWordsCache.find(key) != stemWordsCache.end()){
        word = stemWordsCache.at(word);
        return;
    }

    Porter2Stemmer::stem(word);
    stemWordsCache.emplace(key, word);

}

// Lower the string
string & DocumentParser::loweringString(string & entry) const {

    for(int i = 0; i < entry.size(); i++){
        entry[i] = tolower(entry[i]);
    }
    return entry;

}
string DocumentParser::cleanWords(string & entry) const {
    string temp = entry;
    if(entry.size() == 0){
        return entry;
    }
    loweringString(temp);

    temp.erase(std::remove_if(temp.begin(), temp.end(), [] (char c){
        return !(c == '\'' || (c >= 'a' && c <= 'z'));
    }), temp.end());

    if(temp.size() == 0){
        return temp;
    }

    if(stopWords.contains(temp)){
        return "";
    }

    stemmingStrings(temp);
    return temp;

}

void DocumentParser::search(const string & entry) {

    cout << "Searching for the word: " << entry << endl;

    Words searchWord = cleanWords(entry);

    cout << "Results: " << endl;
    //cout << "Total number of nodes in tree is: " << wordsTree



}

void DocumentParser::setIndex(IndexInterface * indx) {

    indexes = indx;
}