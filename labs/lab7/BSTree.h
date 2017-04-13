#ifndef BSTREE_H
#define BSTREE_H

#include <queue>
#include <vector>

class BSTree{
    private:
        class Node{
            public:
                Node* parent;
                Node* left;
                Node* right;
                int value;
                Node(Node* p, int val){
                    parent = p;
                    left = nullptr;
                    right = nullptr;
                    value = val;
                }
                Node(Node* p){
                    parent = p;
                    left = nullptr;
                    right = nullptr;
                }
                
        };
        Node* root;
        bool findHelper(Node* finder, int val);
        bool removeHelper(Node* n, int num);
        bool insertHelper(Node* current, Node* previous, int val);
        Node* findLargest(Node* start);
        Node* findLargestHelper(Node* current, Node* previous);
        void inOrder(Node* current, std::vector<int> &list);
        void preOrder(Node* current);
        void postOrder(Node* current);
    public:
        int size;
        BSTree();
        BSTree(const BSTree &original);
        bool empty();
        bool insert(int val);
        bool find(int val);
        bool remove(int num);
        void sortedArray(std::vector<int> &list);
        ~BSTree();

};

#endif
