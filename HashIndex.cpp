//
// Created by PRINCE NDHLOVU on 4/24/20.
//

#include "HashIndex.h"

void HashIndex::addWord(Words word) {
    words.insert(word.getQuery() , word);
}

void HashIndex::displayWords() {
    words.display();
}

bool HashIndex::hasElement(string word) {
    return words.contains(word);
}

Words& HashIndex::wordLocation(string word) {
    return words.find(word);
}

void HashIndex::parseWords() {

}

void HashIndex::setPersistent() {

}
