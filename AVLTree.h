//
// Created by PRINCE NDHLOVU on 4/15/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_AVLTREE_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_AVLTREE_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

template <class T>
class AVLTree {

private:
    template <class P>
    class AVLNode {
    public:
        AVLNode *left;
        AVLNode *right;
        int height = 0;
        P data;

        AVLNode() {
            left = nullptr;
            right = nullptr;
            height = 0;
        }

        AVLNode(P &value) {
            this->data = value;
            left = nullptr;
            right = nullptr;
            height = 0;
        }

        AVLNode(P &value, AVLNode *newleft, AVLNode *newright, int newheight) {
            this->data = value;
            this->left = newleft;
            this->right = newright;
            this->height = newheight;
        }

        void operator=(AVLNode<P> &obj) {
            data = obj.data;
            if (obj.left != nullptr) {
                left = new AVLNode<P>();
                left = obj.left;
            } else {
                left = nullptr;
            }
            if (obj.right != nullptr) {
                right = new AVLNode<P>();
                right = obj.right;
            } else {
                right = nullptr;
            }
            height = obj.height;
        }
    };

        AVLNode<T> *root;
        int maxValue(int, int);
        int treeHeight(AVLNode<T>*);
        void doubleRotateRightChild(AVLNode<T>*&);
        void doubleRotateLeftChild(AVLNode<T>*&);
        void rotateLeftChild(AVLNode<T>*&);
        void rotateRightChild(AVLNode<T>*&);
        void destroyTree(AVLNode<T>*);
        void insert(T, AVLNode<T>*&);
        void displayInOrder(AVLNode<T>*&, ostream&);
        T& find(T, AVLNode<T>*);
        void totalNodes(AVLNode<T>*);
        //void parseInOrder(AVLNode<T>*);
        AVLNode<T>* copy(AVLNode<T>*&);
        bool contains(T, AVLNode<T>*);
        void printInOrder(AVLNode<T>*);
        void parseWords(AVLNode<T>*);
        ostream& setPersistent(AVLNode<T>*) ;
        int numOfNodes;

public:
    AVLTree();
    AVLTree(T);
    AVLTree(AVLTree& );
    ~AVLTree();
    AVLTree<T>& operator=(AVLTree<T>&);
    void destroyTree();
    void insert(T);
    bool isEmpty();
    bool contains(T);
    T& find(T);
    void parseWords();
    void printInOrder();
    void displayInOrder(ostream&);
    void setPersistent();
    int getTotalNodes();

};

template <class T>
AVLTree<T>::AVLTree() {
    root = nullptr;
}

template <class T>
AVLTree<T>::AVLTree(T val) {
    root = nullptr;
    insert(val);
}

template <class T>
AVLTree<T>::AVLTree(AVLTree & obj) {
    root = nullptr;

    if(this != &obj){
        destroyTree();
        root = copy(obj.root);
    }
}

template <class T>
AVLTree<T>::~AVLTree() {
    destroyTree();
}

template <class T>
AVLTree<T>& AVLTree<T>::operator=(AVLTree<T> & obj) {

    if(this != &obj){
        destroyTree();
        root = copy(obj.root);
    }
    return *this;
}

template <class T>
typename AVLTree<T>::template AVLNode<T>* AVLTree<T>::copy(AVLNode<T> *& avlNode) {
//AVLTree<T>::AVLNode<T>* AVLTree<T>::copy(AVLTree::AVLNode<T> *& avlNode) {

  //  template<typename T>
  //  typename DSAVLTree<T>::template AVLNode<T>* DSAVLTree<T>::copy(AVLNode<T>*& node)
    if(avlNode != nullptr){
        AVLNode<T>* copyleft = copy(avlNode->left);
        AVLNode<T>* copyright = copy(avlNode->right);
        return new AVLNode<T>(avlNode->data, copyleft, copyright, avlNode->height);
    }
    else if(avlNode == nullptr){
        return nullptr;
    }
}
template <class T>
void AVLTree<T>::destroyTree() {
    destroyTree(root);
}

template <class T>
void AVLTree<T>::destroyTree(AVLNode<T> * avlNode) {
    AVLNode<T> *curr;
    if(avlNode != nullptr){
        if(avlNode->left != nullptr){
            destroyTree(avlNode->left);
        }
        if(avlNode->right != nullptr){
            destroyTree(avlNode->right);
        }
        curr = avlNode;
        delete avlNode;
    }
    avlNode = nullptr;
}

/*
template <class T>
void AVLTree<T>::destroyTree(AVLNode<T> * avlNod) {
    AVLNode<T>* curr;

    if(avlNod != nullptr){
        if(avlNod->left != nullptr){
            destroyTree(avlNod->left);
        }
        if(avlNod->right != nullptr){
            destroyTree(avlNod->right);
        }
        curr = avlNod;
        delete avlNod;
    }
    avlNod = nullptr;
} */

template <class T>
void AVLTree<T>::insert(T i) {

    insert(i,root);
}

template <class T>
void AVLTree<T>::insert(T value, AVLTree::AVLNode<T> *& node) {

    if(node == nullptr) {
        node = new AVLNode<T>(value);
    }
    else if(value < node->data) {
        insert(value, node->left);

        if (treeHeight(node->left) - treeHeight(node->right) == 2) {
            if (value < node->left->data) {
                rotateLeftChild(node);
            } else {
                doubleRotateLeftChild(node);
            }
        }
    }
    else if(value > node->data ){
        insert(value, node->right);

        if(treeHeight(node->right) - treeHeight(node->left) == 2){
            if(node->right->data < value){
                rotateRightChild(node);
            } else{
                doubleRotateRightChild(node);
            }
        }
    }

    node->height = maxValue(treeHeight(node->left), treeHeight(node->right)) + 1;
}
template <class T>
bool AVLTree<T>::isEmpty() {

    if(root == nullptr){
        return true;
    }
    else{
        return false;
    }

}

template <class T>
bool AVLTree<T>::contains(T i) {

    return contains(i, root);

}

template <class T>
bool AVLTree<T>::contains(T value, AVLNode<T> * node) {

    while(node != nullptr ){
        if(value < node->data){
            node = node->left;
        }
        else if( value >node->data){
            node = node->right;
        }
        else {
            return true;
        }
    }
    return false;
}

template <class T>
T& AVLTree<T>::find(T i) {

    return find(i, root);

}

template <class T>
T& AVLTree<T>::find(T value, AVLNode<T> * node) {

    while(node != nullptr ){
        if(value < node->data){
            node = node->left;
        }
        else if( value >node->data){
            node = node->right;
        }
        else {
            return node->data;
        }
    }
    throw out_of_range("The element does not exist in the AVL Tree");

}

template <class T>
void AVLTree<T>::displayInOrder(AVLTree<T>::AVLNode<T> *& avlNode, ostream & outputFile) {

    if(avlNode != nullptr){
        displayInOrder(avlNode->left, outputFile);
        outputFile << avlNode->data;
        displayInOrder(avlNode->right, outputFile);
    }

}
template <class T>
void AVLTree<T>::displayInOrder(ostream & outputFile) {

    displayInOrder(root, outputFile);

}

template <class T>
int AVLTree<T>::maxValue(int leftSubTree, int rightSubTree){

    if(leftSubTree > rightSubTree){
        return leftSubTree;
    } else{
        return rightSubTree;
    }

}
template <class T>
int AVLTree<T>::treeHeight(AVLTree::AVLNode<T> * avlNode) {

    if(avlNode == nullptr){
        cout << "AVL TREE IS EMPTY \n";
        return -1;
    }
    else{
        return avlNode->height;
    }


}
template <class T>
void AVLTree<T>::doubleRotateRightChild(AVLTree::AVLNode<T> *& avlNode) {

    rotateLeftChild(avlNode->right);
    rotateRightChild(avlNode);
}
template <class T>
void AVLTree<T>::doubleRotateLeftChild(AVLTree::AVLNode<T> *& avlNode) {

    rotateRightChild(avlNode->left);
    rotateLeftChild(avlNode);
}

template <class T>
void AVLTree<T>::rotateLeftChild(AVLNode<T>*& avlNode) {

    AVLNode<T> *node = avlNode->left;

    avlNode->left = node->right;
    node->right = avlNode;
    avlNode->height = maxValue(treeHeight(avlNode->left), treeHeight(avlNode->right)) + 1;
    node->height = maxValue(treeHeight(node->left), avlNode->height) + 1;
    avlNode = node;

}

template <class T>
void AVLTree<T>::rotateRightChild(AVLTree::AVLNode<T> *& avlNode) {

    AVLNode<T>* node = avlNode->right;


    avlNode->right = node->left;
    node->left = avlNode;
    avlNode->height = maxValue(treeHeight(avlNode->left), treeHeight(avlNode->right)) + 1;
    node->height = maxValue(treeHeight(node->right), node->height) + 1;
    avlNode = node;

}


template <class T>
void AVLTree<T>::parseWords() {

    parseWords(root);

}

template <class T>
void AVLTree<T>::parseWords(AVLTree::AVLNode<T> * node) {

    if(node != nullptr){
        parseWords(node->left);
        cout << node->data;
        parseWords(node->right);
    }

    if(isEmpty() == true){
        cout << "The AVL Tree is empty \n";
    }


}
template <class T>
void AVLTree<T>::totalNodes(AVLNode<T>* node){

    AVLNode<T>* tmpL = node;
    AVLNode<T>* tmpR = node;

    if(isEmpty() == true){
        cout << "The AVL Tree is empty \n";
    }

    while (tmpL != nullptr ){
        tmpL = tmpL->left;
        numOfNodes++;
    }

    while (tmpR != nullptr){
        tmpR = tmpR->right;
        numOfNodes++;
    }

}

template <class T>
int AVLTree<T>::getTotalNodes() {
    return numOfNodes;
}

template <class T>
void AVLTree<T>::printInOrder(AVLNode<T>* avlNode){

    if(avlNode != nullptr){
        printInOrder(avlNode->left);
        cout << avlNode->data <<" \n";
        printInOrder(avlNode->right);
    }
    if(isEmpty()){
        cout << "AVL TREE IS EMPTY \n";
    }

}

template <class T>
void AVLTree<T>::printInOrder() {
    printInOrder(root);
}

template <class T>
ostream& AVLTree<T>::setPersistent(AVLTree<T>::AVLNode<T> * node) {

    ofstream file;
    file.open("Filename.txt");

    if(!file.is_open()){
        cout << " Error, the Persistent file could not be opened \n";
    }

    if(isEmpty() == true){
        cout << "The tree is empty \n";
    }

    if(node != nullptr){
        setPersistent(node->left);
        file << node->data << " \n";
        setPersistent(node->right);
    }

}

template <class T>
void AVLTree<T>::setPersistent() {

    setPersistent(root);
}


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_AVLTREE_H
