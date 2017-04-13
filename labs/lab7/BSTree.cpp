#include "BSTree.h"
#include <iostream>
#include <math.h>

BSTree::BSTree(): root(nullptr) {
    size = 0;
    root = nullptr;  
}

BSTree::BSTree(const BSTree& original){
    size = 0;
    root = nullptr;
    preOrder(original.root);
}

bool BSTree::empty(){
    return (root==nullptr) ? true : false;
}

bool BSTree::insert(int val){
    //if root is null tree is empty, so create the root
    if(root==nullptr){
        root = new Node(nullptr, val);
        size++;
        return true;
    }
    return insertHelper(root, nullptr, val);
}

bool BSTree::insertHelper(Node* current, Node* previous, int val){
    //when the end is reached add the new node
    if(current==nullptr){
        if(val>previous->value)
            previous->right = new Node(previous, val);
        if(val<previous->value)
            previous->left = new Node(previous, val);
        current = root;
        size++;
        return true;
    }
    //recurse right
    if(val>current->value){
        previous = current;
        current = current->right;
        return this->insertHelper(current, previous, val);
    }
    //recurse left
    if(val<current->value){
        previous = current;
        current = current->left;
        return this->insertHelper(current, previous, val);
    }
    current = root;
    return false;
}

bool BSTree::find(int val){
    return findHelper(root, val);
}

//basically insert without the inserting part
bool BSTree::findHelper(Node* finder,int val){
    if(finder==nullptr)
        return false;
    if(val>finder->value){
        finder = finder->right;
        return findHelper(finder, val);
    }
    else if(val<finder->value){
        finder = finder->left;
        return findHelper(finder, val);
    }
    return true;
}

bool BSTree::remove(int val){
    bool ret = removeHelper(root, val);
    if(ret)
        size--;
    return ret;
}
bool BSTree::removeHelper(Node* current, int val){
    if(current == nullptr) return false;
    if(current->value == val){
        //root with null children
        if(current->left == nullptr && current->right == nullptr && current == root){
            delete root;
            root = nullptr;
        }
        //no root with 2 null children
        else if(current->left == nullptr && current->right == nullptr){
            if(current->parent->left == current){
                current->parent->left = nullptr;
                delete current;
            }
            else{
                current->parent->right = nullptr;
                delete current;
            }
        }
        //2 non null children
        else if(current->left != nullptr && current->right != nullptr){
            typename BSTree::Node* temp = findLargest(current->left);
            current->value = temp->value;
            removeHelper(temp, current->value);
        }
        //root with 1 null child and 1 non null child
        else if(current==root){
            if(current->right == nullptr){ 
                current->left->parent = nullptr;
                Node* t = current->left;
                delete root;
                root = t;
            }
            else if(current->left == nullptr){ 
                current->right->parent = nullptr;
                Node* t = current->right;
                delete root;
                root = t;
            }
        }
        //non root with 1 null child and 1 non null child
        else{
            if(current->right == nullptr){ 
                if(current->parent->left->value == current->value){
                    current->parent->left = current->left;
                    current->left->parent = current->parent;
                    delete current;
                }
                else{
                    current->parent->right = current->left;
                    current->left->parent = current->parent;
                    delete current;
                }
            }
            else if(current->left == nullptr){ 
                if(current->parent->left->value == current->value){
                    current->parent->left = current->right;
                    current->right->parent = current->parent;
                    delete current;
                }
                else{
                    current->parent->right = current->right;
                    current->right->parent = current->parent;
                    delete current;
                }
            }
        }
        return true;
    }
    //recurse left
    else if(current->value > val){
        return removeHelper(current->left, val);
    }
    //recurse right
    else if(current->value < val){
        return removeHelper(current->right, val);
    }
    return false; 
}
BSTree::Node* BSTree::findLargest(Node* start){
    return findLargestHelper(start, start->parent);
}
BSTree::Node* BSTree::findLargestHelper(Node* current, Node* previous){
    if(current == nullptr)
        return previous;
    else
        return findLargestHelper(current->right, current);
}
void BSTree::sortedArray(std::vector<int> &list){
    inOrder(root, list);
}
void BSTree::inOrder(Node* current, std::vector<int> &list){
    if(current != nullptr){
        inOrder(current->left, list);
        list.push_back(current->value);
        inOrder(current->right, list);
    }
}
void BSTree::preOrder(Node* current){
    if(current != nullptr){
        this->insert(current->value);
        preOrder(current->left);
        preOrder(current->right);
    }
}
void BSTree::postOrder(Node* current){
    if(current != nullptr){
        postOrder(current->left);
        postOrder(current->right);
        remove(current->value);
    }
}
BSTree::~BSTree(){
    postOrder(root);
}
