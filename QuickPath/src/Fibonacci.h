//
// Created by Vivien Bistrel TSANGUE CHOUNGOU on 03/02/2025.
//

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <limits>

class FibonacciHeap {
public:
    struct Node {
        int key;
        int value;  // This can be used to store any other data, such as the node ID
        Node* parent;
        Node* child;
        Node* next;
        Node* prev;
        int degree;
        bool mark;

        Node(int key, int value) : key(key), value(value), parent(nullptr), child(nullptr), next(this), prev(this), degree(0), mark(false) {}
    };

    FibonacciHeap() : minNode(nullptr), nodeCount(0) {}

    ~FibonacciHeap() {
        while (minNode != nullptr) {
            extractMin();
        }
    }

    void insert(int key, int value) {
        Node* newNode = new Node(key, value);
        if (!minNode) {
            minNode = newNode;
        } else {
            // Add new node to the root list
            minNode->prev->next = newNode;
            newNode->prev = minNode->prev;
            newNode->next = minNode;
            minNode->prev = newNode;
            if (newNode->key < minNode->key) {
                minNode = newNode;
            }
        }
        nodeCount++;
    }

    Node* extractMin() {
        Node* z = minNode;
        if (z == nullptr) return nullptr;

        // Remove the minimum node from the root list
        if (z->child != nullptr) {
            Node* child = z->child;
            do {
                Node* nextChild = child->next;
                child->prev = minNode->prev;
                child->next = minNode;
                minNode->prev->next = child;
                minNode->prev = child;
                child->parent = nullptr;
                child = nextChild;
            } while (child != z->child);
        }

        z->prev->next = z->next;
        z->next->prev = z->prev;
        if (z == z->next) {
            minNode = nullptr;
        } else {
            minNode = z->next;
            consolidate();
        }

        nodeCount--;
        return z;
    }

    void decreaseKey(Node* node, int newKey) {
        if (newKey > node->key) return; // Invalid operation

        node->key = newKey;
        Node* parent = node->parent;
        if (parent && node->key < parent->key) {
            cut(node, parent);
            cascadingCut(parent);
        }

        if (node->key < minNode->key) {
            minNode = node;
        }
    }

    Node* getMin() {
        return minNode;
    }

    int size() const {
        return nodeCount;
    }

private:
    Node* minNode;
    int nodeCount;

    void consolidate() {
        std::unordered_map<int, Node*> degreeTable;
        Node* start = minNode;
        Node* current = start;
        do {
            Node* x = current;
            int d = x->degree;
            while (degreeTable.count(d)) {
                Node* y = degreeTable[d];
                if (x->key > y->key) std::swap(x, y);
                link(y, x);
                degreeTable.erase(d);
                d++;
            }
            degreeTable[d] = x;
            current = current->next;
        } while (current != start);

        minNode = nullptr;
        for (auto& entry : degreeTable) {
            if (!minNode || entry.second->key < minNode->key) {
                minNode = entry.second;
            }
        }
    }

    void link(Node* y, Node* x) {
        y->prev->next = y->next;
        y->next->prev = y->prev;
        y->parent = x;
        if (x->child == nullptr) {
            x->child = y;
            y->next = y->prev = y;
        } else {
            y->next = x->child;
            y->prev = x->child->prev;
            x->child->prev->next = y;
            x->child->prev = y;
        }
        x->degree++;
        y->mark = false;
    }

    void cut(Node* node, Node* parent) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        parent->degree--;
        node->parent = nullptr;
        node->mark = false;

        node->next = minNode;
        node->prev = minNode->prev;
        minNode->prev->next = node;
        minNode->prev = node;
    }

    void cascadingCut(Node* parent) {
        if (parent->parent != nullptr) {
            if (!parent->mark) {
                parent->mark = true;
            } else {
                cut(parent, parent->parent);
                cascadingCut(parent->parent);
            }
        }
    }
};



#endif //FIBONACCI_H
