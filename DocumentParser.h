//
// Created by PRINCE NDHLOVU on 4/18/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_DOCUMENTPARSER_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_DOCUMENTPARSER_H

#include "AVLTree.h"
#include "Words.h"
#include "AVLIndex.h"
#include "HashTable.h"
#include "IndexInterface.h"
#include <unordered_map>
#include <unordered_set>
#include "StopWords.h"

struct DocumentData{

    unsigned int id;
    string text;
};

class DocumentParser {

private:
    int numOfArticles;
    int numOfIndexedWords;
    int numOfTotalWords;
    string filePaths;
    AVLTree<string> stopWords;
   // unordered_set<string> stopWords;
    unordered_map<string, string> stemWordsCache;
    IndexInterface* indexes;
    AVLTree<string> wordsParsed;
    AVLTree<Words> wordsTree;
    AVLIndex wordIndexer;
    vector<int> averageWords;
    HashTable<int, string> authors;

public:
    DocumentParser();
    int getNumOfArticles();
    int getNumOfIndexedWords();
    int getNumOfTotalWords();
    void readDirectory();
    void parseArticles(const string, const string, const int);
    AVLTree<Words>& getWords();
    string getFilePath();
    string& loweringString(string&) const ;
    void displayStatistics();
    void insertTreeWord(string, string);
    void setStopWords();
    AVLTree<string> getStopWords();
    void setIndex(IndexInterface*);
    string cleanWords(string &) ;
    int getAveOfIndexedWords();
    void stemmingStrings(string &) ;
    HashTable<int, string> getAuthors();

};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_DOCUMENTPARSER_H
