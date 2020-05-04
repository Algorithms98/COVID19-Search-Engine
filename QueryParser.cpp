//
// Created by PRINCE NDHLOVU on 4/18/20.
//

#include "QueryParser.h"

QueryParser::QueryParser() {

    stopWordsTree = swords.getStopTree();

}

queue<string> & QueryParser::getUserInput() {

    string searchTerm;

    clearQ(userInput);
    cout << "Enter your search term here: ";
    getline(cin, searchTerm);
    cout << endl ;
    cout << "Search results for search term: " << searchTerm << endl;

    istringstream strings(searchTerm);

    while(getline(strings, searchTerm, ' ')){

        Words sw(searchTerm);   //lowers the word to lower case chars, stems the word, removes punctuation
        string singleText = sw.getQuery();

        if(singleText == "author") {
            author = true;
        }

        if(stopWordsTree.contains(singleText)){
            if(singleText == "not" || "and" || "or" || "author"){
                userInput.push(singleText);
                continue;
            }
            else{
                cout << "The search entry had stop word <" << singleText << "> . " << "Enter another word. \n";

                clearQ(userInput);
                getUserInput();
                break;

            }
        }
        else{
            userInput.push(singleText);
        }
    }
    return userInput;

}

void  QueryParser::clearQ(queue <string> & q) {

    while (!q.empty()){
        q.pop();
    }

}

bool QueryParser::hasAuthor() {
    return author;
}