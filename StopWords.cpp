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
    cout << "Entering insertStopWords method in Stop Words..." << endl;
   // system("read -n 1 -s -p \"Press any key to continue...\"");
    ifstream inputFile;
    inputFile.open("StopWords.txt");

    if(!inputFile.is_open()){
        cout << "StopWords file could not be opened \n";
        exit(0);
    }

    string word;
//    inputFile >> word;
//
//    while (!inputFile.eof()){
//       // inputFile >> word;
//        stopTree.insert(word);
//        inputFile >> word;
//    }

    while(inputFile >> word){

        stopTree.insert(word);

    }

    inputFile.close();
}