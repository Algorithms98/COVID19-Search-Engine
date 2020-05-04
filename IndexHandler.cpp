//
// Created by PRINCE NDHLOVU on 4/16/20.
//

#include "IndexHandler.h"

IndexHandler::IndexHandler() {

    numOfArtArticles = 0;
    numOfIndexedWords = 0;
    numOfWordsTotal =0;

}

IndexInterface*& IndexHandler::getIndexPtr() {

    return index;
}

void IndexHandler::addToIndex() {

    DocumentParser parse;
    index = new AVLIndex;
    parse.setIndex(index);
   parse.readDirectory();

  numOfIndexedWords = parse.getNumOfIndexedWords();
  numOfArtArticles = parse.getNumOfArticles();
  numOfWordsTotal = parse.getNumOfTotalWords();

  writeToIndex(parse.getWords());
}

void IndexHandler::cleanIndex() {

    filename.open("IndexFile.txt");

    if(!filename.is_open()){
        cout << "Could not open the file \n";
    } else{

        if(remove("IndexFile.txt") != 0){
            perror("File deletion failed, there was an error");
        } else{
            puts("File deleted successfully");
        }

    }
}

//not finished
void IndexHandler::readIndex() {

    filename.open("IndexFile.txt");
    string w;
    int fileCount;
    int count;

     filename >> numOfArtArticles;
     filename >> numOfIndexedWords;
     filename >> numOfWordsTotal;

     filename >> w;

     while (!filename.eof()){
         Words phrase(w);
         filename >> fileCount;
         string jsonData;
         for(int i = 0; i < fileCount; i++){
             filename >> count;
             getline(filename, jsonData);
             jsonData = jsonData.substr(1, jsonData.length());
             phrase.addFileIndex(pair<string, int>(jsonData, count));
         }
         index->addWord(phrase);
         filename >> w;
     }

     filename.close();

}
void IndexHandler::writeToIndex(AVLTree<Words> & querries) {

    filename.open("IndexFile.txt");

    if(!filename.is_open()){
        cout << "Could not open Corpus file for writing  \n";
    }

    filename << numOfArtArticles << endl;
    filename << numOfIndexedWords << endl;
    filename << numOfWordsTotal << endl;

    querries.displayInOrder(filename);
    filename.close();
}

vector<string> IndexHandler::getArticleFiles() {

}
void IndexHandler::getTopWords() {

}

int IndexHandler::getNumOfArticles() {

    return numOfArtArticles;
}



void IndexHandler::displayStatistics() {

    cout << "Number of total unique words is: " << numOfWordsTotal  << endl;
    cout << "Number of articles parsed is: " << numOfArtArticles << endl;
    cout << "Number of words indexed is: " << numOfIndexedWords << endl;
    cout << "Average number of indexed words is " << endl;
    cout << "Total number of unique Authors is " << "" << endl;

}

IndexHandler::~IndexHandler() {

}

IndexHandler::IndexHandler(const IndexHandler &obj) {
    numOfArtArticles = obj.numOfArtArticles;
    numOfIndexedWords = obj.numOfIndexedWords;
    numOfWordsTotal = obj.numOfWordsTotal;
    articleFiles = obj.articleFiles;

}

IndexHandler &IndexHandler::operator=(const IndexHandler &obj) {

     numOfArtArticles = obj.numOfArtArticles;
     numOfIndexedWords = obj.numOfIndexedWords;
     numOfWordsTotal = obj.numOfWordsTotal;
     articleFiles = obj.articleFiles;
      //  words = obj.words;

    return *this;
}

