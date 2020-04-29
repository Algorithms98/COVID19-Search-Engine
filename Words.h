//
// Created by PRINCE NDHLOVU on 4/16/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_WORDS_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_WORDS_H

#include <ostream>
#include <iostream>
#include "Porter2_Stemmer.h"
#include "AVLIndex.h"
#include <fstream>
#include <locale>
#include <algorithm>
#include <vector>
#include <utility> //for pair

using namespace std;
using namespace Porter2Stemmer;


class Words {

    friend ostream&operator<<(ostream&, const Words&);

private:
    string text;
    vector<pair<string, int> > file;
    int totalWordFrequency;

public:
    Words();
    Words(string);
    Words(string, string);
    Words(string, pair<string, int>);
    void removePunctuation();
    void stemWords();
    string getQuery();
    vector<pair<string, int>>& getFiles();
    int getTotalWordFrequency();
    void formatQuery();
    bool operator>(const Words&);
    bool operator<(const Words&);
    bool operator==(const Words&);
    int fileLocation(string);
    void addFile(string);
    void addFileIndex(pair<string, int>);

};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_WORDS_H
