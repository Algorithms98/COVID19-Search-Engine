//
// Created by PRINCE NDHLOVU on 4/18/20.
//

#include "DocumentParser.h"
#include "json.hpp"
#include "Porter2_Stemmer.h"
#include <sstream>
#include <algorithm>
#include <string>
#include <dirent.h>
#include <iostream>
#include "parser.hpp"
#include <filesystem>

using namespace std;
using nlohmann::json;
namespace fs = std::filesystem;


DocumentParser::DocumentParser() {
    StopWords sw;
    sw.insertStopWords();
    stopWords = sw.getStopTree();
    numOfArticles = 0;
    numOfIndexedWords = 0;
    numOfTotalWords =0;

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
    cout << "Enter the name of the directory pathfor the Articles: ";
    cin >> directoryPath;


    if(directoryPath[directoryPath.size() - 1] != '/') {
        cout << "You missed a foward slash character '/' , I have added it for you \n";
        directoryPath = directoryPath + '/';
    }


    DIR* corpus;
    struct dirent* dir;

    char filePath[5000];

    cout << "aboout \n";
    for(auto& file: filesystem::recursive_directory_iterator(directoryPath)){

        if(file.path().extension() == ".json"){
            numOfArticles++;
            string fileId = file.path().c_str();
            cout << fileId << endl;
            string tmp = file.path().c_str();
            fileId = fileId.substr(41, tmp.size() - 15);
            fileId = fileId.substr(0, fileId.size()-5);
            cout << fileId << endl;
            strncpy(filePath, directoryPath.c_str(), 5000);
            strncat(filePath, "/",5000);
            strncat(filePath, file.path().c_str(), 5000);

            if(numOfArticles <= 2){
                parseArticles(file.path().c_str(), directoryPath, fileId);
            }

        }
    }

//    while((corpus = opendir(directoryPath.c_str())) == nullptr){
//        cout << "Could not open file directory:" << directoryPath << endl;
//        cout << "Enter the name of the directory path  for the Articles: ";
//        cin >> directoryPath;
//    }
//    cout << "before insertion \n";
//    while ((dir = readdir(corpus)) != nullptr){
//        cout << "inside the loop \n";
//        cout << dir->d_name << endl;
//
//        if(strncmp(dir->d_name, "..", 2)!= 0 && strncmp(dir->d_name, ".", 1) != 0){
//            string fileName = dir->d_name;
//            string fileId = fileName.substr(0, fileName.size()-5);
//            string fileExtension = fileName.substr(fileName.size() -5, fileName.size());
//
//            cout << "got this far \n";
//            if(fileExtension == ".json"){
//                numOfArticles++;
//                strncpy(filePath, directoryPath.c_str(), 5000);
//                strncat(filePath, "/",5000);
//                strncat(filePath, dir->d_name, 5000);
//
//                cout << "About to parse a file \n";
//                if(numOfArticles <= 2){
//                    cout << fileId << endl;
//                   // int num = stoi(fileId);
//                    parseArticles(filePath, directoryPath, fileId);
//                    cout << "Parsed an article \n";
//                }
//            }
//        }
//
//        if(numOfArticles <= 2){
//            break;
//        }
//    }
//    closedir(corpus);
}

/*
 * Parsing the articles and adding the words into the AVLTree
 */
void DocumentParser::parseArticles(const string fileDirectory , const string filePath, string id) {
    cout << "parsing an article \n";
    ifstream articles(fileDirectory);
    string temp;
    string text;
    if(!articles.is_open()){
        cout << "The file path does not exist \n";
    }


    DocumentData data;
    json j;
    j = json::parse(articles);

    //articles >> j;  //if(!j["authors"][i]["last"].empty()){
    string name="";
    int i = 0;

    /*
     * Adding the authors into the hash table
     */
    //while(j["authors"][i]["last"] != NULL){
      //  name = j["authors"][i]["last"].get<string>();
      //  authors.insert(id, name);
       // i++;
 //   }

    int k = 0;
    while (j["body_text"][k]["text"].size() != NULL){

        //j["body_text"][k]["text"].size() != j["body_text"][k].size())

                text = j["body_text"][k]["text"].get<string>();
                cout << text << endl ;
                k++;
    }

    string line;
    stringstream ss(text);
    while (ss >> line){
        numOfTotalWords++;
        insertTreeWord(line, filePath);
    }

    articles.close();
    cout << "words have been inserted into the AVL Tree \n";

}

AVLTree<Words>& DocumentParser::getWords() {
    return wordsTree;
}

string DocumentParser::getFilePath() {
    return filePaths;
}

// inserting parsed words into the AVL tree
void DocumentParser::insertTreeWord(string name, string fileName) {

    if(!(stopWords.contains(name))){
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
    cout << "Number of total unique words is: " << numOfTotalWords  << endl;
    cout << "Number of articles parsed is: " << numOfArticles << endl;
    cout << "Number of words indexed is: " << numOfIndexedWords << endl;
    cout << "Average number of indexed words is " << getAveOfIndexedWords() << endl;
    cout << "Total number of unique Authors is " << "" << endl;

}
void DocumentParser::setStopWords() {

    string word;
    ifstream stopFile("StopWords.txt");

    //stopWords.clear();
    while(!stopFile.eof()){
        stopFile >> word;
        stopWords.insert(word);
    }

}

AVLTree<string> DocumentParser::getStopWords() {
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

void DocumentParser::stemmingStrings( string& word) {

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
string DocumentParser::cleanWords(string & entry)  {
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

    if(stopWords.contains(temp) ){
        return "";
    }

    stemmingStrings(temp);
    return temp;

}


void DocumentParser::setIndex(IndexInterface * indx) {

    indexes = indx;
}

HashTable<string, string> DocumentParser::getAuthors() {
    return  authors;
}
