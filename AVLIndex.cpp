//
// Created by PRINCE NDHLOVU on 4/16/20.
//

#include "AVLIndex.h"

void AVLIndex::addWord(Words weds) {

    words.insert(weds);
}

void AVLIndex::displayWords() {
    words.printInOrder();
}

bool AVLIndex::hasElement(string weds) {

    Words obj(weds);
    return words.contains(weds);
}

Words& AVLIndex::wordLocation(string weds) {
    Words obj(weds);
    return words.find(weds);
}

void AVLIndex::parseWords() {
    words.parseWords();
}

void AVLIndex::setPersistent() {
    words.setPersistent();
}

