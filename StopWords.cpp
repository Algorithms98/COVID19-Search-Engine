//
// Created by PRINCE NDHLOVU on 4/16/20.
//

#include "StopWords.h"
#include <iostream>

StopWords::StopWords() {

}

AVLTree<string>& StopWords::getStopTree() {
    return stopTree;
}

void StopWords::insertStopWords() {
    ifstream inputFile;
    inputFile.open("StopWords.txt");

    if(!inputFile.is_open()){
        cout << "StopWords file could not be opened \n";
    }

    string word;
    inputFile >> word;

    while (!inputFile.eof()){
        stopTree.insert(word);
        inputFile >> word;
    }

    inputFile.close();
}