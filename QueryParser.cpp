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
    cout << "Enter your search term here \n";
    getline(cin, searchTerm);
    cout << "Search results for search term: " << searchTerm << endl;

    istringstream strings(searchTerm);

    while(getline(strings, searchTerm, ' ')){

        Words sw(searchTerm);
        string singleText = sw.getQuery();

        if(stopWordsTree.contains(singleText)){
            if(singleText == "not" || "and" || "or"){
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
