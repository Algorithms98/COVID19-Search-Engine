//
// Created by PRINCE NDHLOVU on 4/15/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_AVLTREE_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_AVLTREE_H

#include <iostream>
#include <queue>
#include <list>
#include <utility>
#include <string>
#include <fstream>

using namespace std;

/*
 * Implemantation based on Data Structure & Algorithm Analysis in C++ by Mark Allen
 */
template <class T>
class AVLTree {

private:

    template<class P> class AVLNode
    {
    private:
        P data;                 //contains data payload
        AVLNode<P> * left;      //points to left subtree
        AVLNode<P> * right;     //points to right subtree
        int height;             //indicates height of node

    public:
        AVLNode(const P& inputData, AVLNode<P> * leftPtr = nullptr,
                AVLNode<P> * rightPtr = nullptr, int nodeHeight = 1)
                : data(inputData), left(leftPtr), right(rightPtr),
                  height(nodeHeight) {}

        void updateHeight() {
            //set height to be the max height of both children + 1
            height = std::max(getHeight(left), getHeight(right)) + 1;
        }

        int getHeight(const AVLNode<T> * arg) const {
            //returns 0 if pointer is null, its height if not
            if(arg == nullptr)
                return 0;
            else
                return arg->height;
        }

        void updateHeight(AVLNode<T>* arg) {
            if(arg != nullptr)
                arg->height = std::max(getHeight(arg->left), getHeight(arg->right)) + 1;
        }

        friend class AVLTree;
    };

    AVLNode<T> * root;
    int numOfNodes = 0;

    T& findMax(AVLNode<T>*&); //finds the maximum value in tree rooted at arg
    T& findMin(AVLNode<T>*&); //finds the minimum value in tree rooted at arg
    void insert( T &, AVLNode<T> *&); //inserts to tree rooted at arg
    std::pair<T,bool> search(const T&, AVLNode<T>*&); //searches in tree rooted at arg
    bool hasElement( T , AVLNode<T>*) ; //determines if arg is an element of tree rooted at arg
    void destroyTree(AVLNode<T>*&); //clears tree rooted at arg
    int getBalance(AVLNode<T>*); //get balance of node
    void rebalance(T, AVLNode<T>*&); //rebalance node
    void getTopFifty(std::vector<T>&, AVLNode<T>*&);
    std::ostream& displayInOrder(AVLNode<T>* ,std::ostream&) const;//displayInOrder tree rooted at arg
    void RotateLeftChild(AVLNode<T>*&); //case 1 rotation
    void RotateRightChild(AVLNode<T>*&); //case 4 rotation
    void doubleRotateLeftChild(AVLNode<T>*&); //case 2 rotation
    void doubleRotateRightChild(AVLNode<T>*&); //case 3 rotation
    void parseWords(AVLNode<T>*);
    void setPersistent(AVLNode<T>*) ;
    T& find(T, AVLNode<T>*);
    void printInOrder(AVLNode<T>* avlNode);



public:
    AVLTree();
    AVLTree(const AVLTree<T>&); //copy constructor
    AVLTree<T>& operator =(const AVLTree<T>&); //overloaded assignment op
    ~AVLTree(); //destructor
    bool contains( T ); //determines if arg is an element
    std::pair<T,bool> search(const T &); //searches for and returns arg
    void insert( T &); //inserts arg
    bool isEmpty() const; //determines if tree is empty
    void destroyTree(); //clears the tree
    std::pair<T, bool> stringSearch(const std::string &);

    T& findMax(); //finds the maximum value
    T& findMin();//finds the minimum value
    std::ostream& displayInOrder(std::ostream&) ; //prints in level-order
    int getTotalNodes() ;
    void parseWords();
    void setPersistent();
    T& find(T);
    void printInOrder();


    template <class P>
    friend std::ostream& operator <<(std::ostream&, const AVLTree<P>&);     //stream insertion operator
};





//CONSTRUCTORS AND RULE OF THREE


template<class T>
AVLTree<T>::AVLTree() : root(nullptr) { }

/*
 * Copy constructor performs breadth-first traversal of
 */
template<class T>
AVLTree<T>::AVLTree(const AVLTree<T>& rhs)  {
    //initialize root to nullptr first
    root = nullptr;

    //create a queue of node pointers and push root
    std::queue<AVLNode<T>*> tempQueue;

    if(root != nullptr)
        tempQueue.push(rhs.root);

    AVLNode<T>* temp;

    //while queue not empty
    while(!tempQueue.empty()) {
        //pop to temp from queue
        temp = tempQueue.front();
        tempQueue.pop();

        //insert value popped to this tree
        insert(temp->data);

        //if right child not null, push to queue
        if(temp->right != nullptr)
            tempQueue.push(temp->right);

        //if left child not null, push to queue
        if(temp->left != nullptr)
            tempQueue.push(temp->left);
    }
}


/*
 * Overloaded assignment op performs breadth-first traversal of
 * input tree, inserting each element to this tree
 */
template<class T>
AVLTree<T>& AVLTree<T>::operator =(const AVLTree<T>& rhs) {
    //check to see that input is a different object
    if(&rhs != this) {
        //initialize root to nullptr first
        root = nullptr;

        //performs copy constructor logic
        std::queue<AVLNode<T>*> tempQueue;

        if(root != nullptr)
            tempQueue.push(rhs.root);

        AVLNode<T>* temp;

        //while queue not empty
        while(!tempQueue.empty()) {
            //pop to temp from queue
            temp = tempQueue.front();
            tempQueue.pop();

            //insert value popped to this tree
            insert(temp->data);

            //if right child not null, push to queue
            if(temp->right != nullptr)
                tempQueue.push(temp->right);

            //if left child not null, push to queue
            if(temp->left != nullptr)
                tempQueue.push(temp->left);
        }
    }

    //returns reference to this
    return *this;
}


template<class T>
AVLTree<T>::~AVLTree() {

    destroyTree(root);
    if(root != nullptr) {
        delete root;
        root = nullptr;
    }
}



/*
 * PERSISTENCE FILES
 */


/*
 * Parse the words into the AVLTree
 */
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

    if(isEmpty()){
        cout << "The AVL Tree is empty, Could not parse the words \n";
    }


}

template <class T>
void AVLTree<T>::setPersistent() {
    setPersistent(root);
}

template <class T>
void AVLTree<T>::setPersistent(AVLTree<T>::AVLNode<T> * node) {

    ofstream file;
    file.open("IndexFile.txt");

    if(!file.is_open()){
        cout << " Error, the Persistent file could not be opened \n";
    }

    if(isEmpty() == true){
        cout << "The tree is empty, Coming from setPersistent in the AVLTREE \n";
    }

    if(node != nullptr){
        setPersistent(node->left);
        file << node->data << " \n";
        setPersistent(node->right);
    }
    file.close();

}

//GETTERS AND SETTERS


/*
 * Returns the maximum value contained in the tree.
 */
template<class T>
T& AVLTree<T>::findMax() {
    //call private max function with root pointer
    return findMax(root);
}


template<class T>
T& AVLTree<T>::findMax(AVLNode<T> *& current) {
    //if right pointer is null, return this value
    if(current->right == nullptr)
        return current->data;

        //else recursive call with right pointer
    else
        return findMax(current->right);
}


/*
 * Returns the minimum value contained in the tree.
 */
template<class T>
T& AVLTree<T>::findMin() {
    //call private min function with root pointer
    return(findMin(root));
}



template<class T>
T& AVLTree<T>::findMin(AVLNode<T> *& current) {
    //if left pointer is null, return this value
    if(current->left == nullptr)
        return current->data;

        //else recursive call with left pointer
    else
        return findMin(current->left);
}


/*
 * Returns true if tree is empty, false if not.
 */
template<class T>
bool AVLTree<T>::isEmpty() const {
    //returns true iff root is null
    return root == nullptr;
}


/*
 *  Deletes all elements in the tree
 */
template<class T>
void AVLTree<T>::destroyTree() {
    //calls private destroyTree all function with root pointer
    destroyTree(root);
    if(root != nullptr){
        delete root;
        root = nullptr;
    }
}


/*
 * Traverses tree, deleting elements at each recursive call
 */

template<class T>
void AVLTree<T>::destroyTree(AVLNode<T> *& current) {
    //if left not null, call recursively with left, then delete left
    if(current != nullptr) {
        if(current->left != nullptr){
            destroyTree(current->left);
            delete current->left;
        }
        if(current->right != nullptr) {
            destroyTree(current->right);
            delete current->right;
        }
    }
}


/*
 * Overloaded stream insertion operator prints each element according
 * to a preorder traversal.
 */
template<class T>
std::ostream& operator <<(std::ostream& os, const AVLTree<T>& tree) {
    //passes root pointer to displayInOrder function
    tree.displayInOrder(os, tree.root);
    return os;
}


/*
 * Private interface for stream insertion operator
 */
template<class T>
std::ostream& AVLTree<T>::displayInOrder(AVLNode<T> * current, std::ostream & os) const {
    //if not null
    if(current != nullptr) {
        //stream insert node data (followed by height for debugging purposes)
        os << current->data << ' ' << current->height << std::endl;

        //call displayInOrder with left pointer
        displayInOrder(os, current->left);

        //call displayInOrder with right pointer
        displayInOrder(os, current->right);
    }

    //return ostream object
    return os;
}


/*
 * Prints contents of the tree according to a level-order traversal
 */
template <class T>
std::ostream& AVLTree<T>::displayInOrder(std::ostream & os)  {
    //initialize queue of avlnode pointers
    std::queue<AVLNode<T> *> printQueue;

    //push root to queue
    if(root != nullptr)
        printQueue.push(root);
    AVLNode<T> * temp;

    //while queue not empty, displayInOrder next node and push all non-null children
    while(!printQueue.empty()) {
        temp = printQueue.front();
        printQueue.pop();

        os << temp->data << std::endl;

        if(temp->right != nullptr)
            printQueue.push(temp->right);
        if(temp->left != nullptr)
            printQueue.push(temp->left);
    }

    return os;
}


template <class T>
void AVLTree<T>::printInOrder(AVLNode<T>* avlNode){

    if(avlNode != nullptr){
        printInOrder(avlNode->left);
        cout << avlNode->data <<" \n";
        printInOrder(avlNode->right);
    }
    if(isEmpty()){
        cout << "AVL TREE IS EMPTY, COULD NOT PRINT IN ORDER COMING FROM THE AVLTREE  \n";
    }

}

template <class T>
void AVLTree<T>::printInOrder() {
    printInOrder(root);
}



template <class T>
void AVLTree<T>::getTopFifty(std::vector<T> & tops, AVLNode<T> *& current) {

    if(current != nullptr) {
        getTopFifty(tops, current->left);

        if(current->data.getTotalFreq() >= 1000) {
            tops.push_back(current->data);
        }

        getTopFifty(tops, current->right);
    }
}



//SEARCHING


/*
 * Determines whether or not the passed argument is an element of the tree
 */
template<class T>
bool AVLTree<T>::contains( T  arg)  {
    //return value of private function, passing root pointer
    return hasElement(arg, root);
}


/*
 * Private interface for contains method
 */
template<class T>
bool AVLTree<T>::hasElement( T  value, AVLNode<T> * node)  {

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

/*
 * Method that traverses the tree and returns the value by reference if found in the tree
 */
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
    throw out_of_range("The element does not exist in the AVL Tree, Coming from the find in the AVLTREE");

}

/*
 * Searches for the passed value and returns that data from the tree if it is there.
 * If not, indicates with a false value.
 */
template<class T>
std::pair<T, bool> AVLTree<T>::search(const T & arg) {
    //return value of private function, passing root pointer
    return search(arg, root);
}


/*
 * Private interface for search method
 */
//searches for and returns arg in tree rooted at arg
template<class T>
std::pair<T, bool> AVLTree<T>::search(const T & arg, AVLNode<T> *& current) {
    if(current == nullptr)
        return std::pair<T, bool>(arg, false);

    //if value is target, return reference to value
    if(current->data == arg)
        return std::pair<T, bool>(current->data, true);

        //if target value less than this, recursive call
    else if(arg < current->data)
        return search(arg, current->left);

        //if target value greater than this
    else
        return search(arg, current->right);
}


/*
 * Searches the tree for IndexedTerms based on their string keys
 */
template<class T>
std::pair<T, bool> AVLTree<T>::stringSearch(const std::string & word) {
    return stringSearch(word, root);
}




//INSERTING


/*
 * Determines where a passed value should be inserted into the tree
 * and inserts there.
 */
template<class T>
void AVLTree<T>::insert( T & arg) {

    //call private function with root pointer
    insert(arg, root);
}


/*
 * Private interface for insertion method
 */
template<class T>
void AVLTree<T>::insert( T & arg, AVLNode<T> *& current) {
    //if current is null, assign current to pointer
    if(current == nullptr) {
        current = new AVLNode<T>(arg);
        numOfNodes++;
    }

        //if node equal to value, append data to this element
//    else if(current->data == arg) {
//        current->data += arg;
//    }

        //if value greater than node
    else if(arg > current->data) {
        //call recursively with right pointer
        insert(arg, current->right);

        //rebalance current and set height
        rebalance(arg, current);
        current->updateHeight();
    }

        //if value greater than node
    else if(arg < current->data) {
        //call recursively with left pointer
        insert(arg, current->left);

        //rebalance current and set height
        rebalance(arg, current);
        current->updateHeight();
    }
}

/*
 * Returns the number of terms that have been indexed by the tree
 */
template <class T>
int AVLTree<T>::getTotalNodes()  {
    return numOfNodes;
}



//ROTATING


/*
 * Gets the balance (difference in child heights) of node passed as argument
 */
template <class T>
int AVLTree<T>::getBalance(AVLNode<T> * balancingNode) {
    //returns height of right - height of right
    return balancingNode->getHeight(balancingNode->right) -
           balancingNode->getHeight(balancingNode->left);
}


/*
 * Determines whether or not a node is imbalanced and, if so,
 * rebalances the node with the appropriate rotation
 */
template <class T>
void AVLTree<T>::rebalance(T arg, AVLNode<T> *& current) {
    //get balance of node
    int bal = getBalance(current);

    //if balance less than -1
    if(bal < -1) {
        //if left of left of current is arg, case 1
        if(arg < current->left->data)
            RotateLeftChild(current);

            //if right of left of current is arg, case 2
        else if(arg > current->left->data)
            doubleRotateLeftChild(current);
    }

        //if balance greater than 1
    else if(bal > 1) {
        //if left of right of current is arg, case 3
        if(arg < current->right->data)
            doubleRotateRightChild(current);

            //if right of right of current is arg, case 4
        else if(arg > current->right->data)
            RotateRightChild(current);
    }
}


/*
 * Case 1 rotation, when inserted node is in left subtree of left child
 */
template <class T>
void AVLTree<T>::RotateLeftChild(AVLNode<T> *& topNode) {
    //get pointer to left child (LC)
    AVLNode<T>* leftChild = topNode->left;

    //make temp pointer to LR
    AVLNode<T>* temp = topNode->left->right;

    //make LC point to root node on the right
    leftChild->right = topNode;

    //make root pointer point to LC
    topNode = leftChild;

    //make root's right node's left pointer go to temp
    leftChild->right->left = temp;

    //make sure heights are updated
    topNode->updateHeight(leftChild->right);
    topNode->updateHeight(leftChild->left);
}


/*
 * Case 4 rotation, when inserted node is in right subtree of right child
 */
template <class T>
void AVLTree<T>::RotateRightChild(AVLNode<T> *& topNode) {
    //get pointer to right child (RC)
    AVLNode<T>* rightChild = topNode->right;

    //make temp pointer to RL
    AVLNode<T>* temp = topNode->right->left;

    //make RC point to root node on the left
    rightChild->left = topNode;

    //make root pointer point to RC
    topNode = rightChild;

    //make root's left node's right pointer go to temp
    rightChild->left->right = temp;

    //make sure heights are updated
    topNode->updateHeight(rightChild->right);
    topNode->updateHeight(rightChild->left);
}


/*
 * Case 2 rotation, when inserted node is in right subtree of left child
 */
template <class T>
void AVLTree<T>::doubleRotateLeftChild(AVLNode<T> *& topNode) {
    //case 4 rotation on root's left pointer
    RotateRightChild(topNode->left);

    //case 1 rotation on root pointer
    RotateLeftChild(topNode);
}


/*
 * Case 3 rotation, when inserted node is in left subtree of right child
 */
template <class T>
void AVLTree<T>::doubleRotateRightChild(AVLNode<T> *& topNode) {
    //case 1 rotation on root's right pointer
    RotateLeftChild(topNode->right);

    //case 4 rotation on root pointer
    RotateRightChild(topNode);
}

#endif //CS2341_SEARCHENGINE_ALGORITHMS98_AVLTREE_H

