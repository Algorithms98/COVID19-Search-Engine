//
// Created by PRINCE NDHLOVU on 4/27/20.
//

#include "UserInterface.h"

int UserInterface::loadData() {

    cout << "This is the Search Engine  \n";
    cout << "1: Add articles into the index \n";
    cout << "2: Clear all the data in the index \n";
    cout << "3: Exit from the current menu \n";
    cout < "Your move \n";

    int choice;
    cin >> choice;
    return choice;

}

int UserInterface::searchArticles() {

    cout << "1: Search for a term \n";
    cout << "2: Display the Statistics \n";
    cout << "3: Exit \n";
    cout << "Your move \n";

    int choice;
    cin >> choice;
    return  choice;
}

int UserInterface::operationMode() {

    cout << "Select your mode of operation from the options below \n";
    cout << "1: Load Articles into the search Engine \n";
    cout << "2: Search for Articles in the search Engine \n";
    cout << "3: Exit \n";
    cout << "Your move :\n";

    int choice;
    cin >> choice;

    return choice;
}

void UserInterface::searchEngine() {

    IndexHandler indexH;
    int option = operationMode();

    while (option != 3){
        switch (option){

            case 1:

                int choice = loadData();

                while(choice != 3){
                    if(choice == 1) {
                        indexH.addToIndex();
                        break;
                    } else if(choice == 2){
                        indexH.cleanIndex();
                        break;
                    } else{
                        cout << "Please enter a valid menu option 1-3 \n";
                        choice = loadData();
                        break;
                    }
                   // choice = loadData();

                }
               // break;
                //choice = loadData();

            case 2:
                int choice = searchArticles();

                while (choice != 3){

                    if(choice == 1){
                        SearchEngine searchE(indexH.getIndexPtr(), indexH.getNumOfArticles());
                        searchE.getQuery();
                        break;
                    } else if(choice == 2){
                        indexH.displayStatistics();
                        break;
                    } else{
                        cout << "Please enter a valid menu option 1-3 \n";
                    }
                    choice = searchArticles();
                }
                break;
            default:
                cout << "Please enter a valid menu option 1-3 \n";
                option = operationMode();
                //break;

        }
    }
}