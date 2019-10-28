//
// Created by Hayden Huynh on 10/28/19.
//

#ifndef LINKED_LIST_CIRCULARSINGLELINKEDLIST_H
#define LINKED_LIST_CIRCULARSINGLELINKEDLIST_H

#include "SingleNode.h"

class CircularSingleLinkedList {

public:
    SingleNode* pHead;

    SingleNode* pTail;

    int size;

    CircularSingleLinkedList();

    bool rangeCheck(int i);

    void insert(int val, int index);

    void traverse();

    void search(int val);

    void deleteNode(int index);

    void deleteList();
};

CircularSingleLinkedList::CircularSingleLinkedList() {
    pHead = NULL;
    pTail = NULL;
    size = 0;
}

bool CircularSingleLinkedList::rangeCheck(int i) {
    return 0 <= i && i < size;
}

void CircularSingleLinkedList::insert(int val, int index) {
    SingleNode* node = new SingleNode(val);
    if (size == 0) {
        std::cout << "\nLinked List is empty. Inserting the first node.\n";
        pHead = node;
        pTail = node;
        pTail->pNext = pHead;
    }
    else {
        if (index == 0) {
            node->pNext = pHead;
            pHead = node;
            pTail->pNext = pHead;
        }
        else if (index == size) {
            node->pNext = pHead;
            pTail->pNext = node;
            pTail = node;
        }
        else {
            if (rangeCheck(index)) {
                SingleNode* temp = pHead;
                for (int i = 0; i < index-1; i++) {
                    temp = temp->pNext;
                }
                node->pNext = temp->pNext;
                temp->pNext = node;
            }
            else {
                std::cout << "\nIndex out of range.\n";
            }
        }
    }
    size++;
}

void CircularSingleLinkedList::traverse() {
    SingleNode* temp = pHead;
    for (int i = 0; i < size; i++) {
        std::cout << "Node " << i+1 << ": " << temp->val << " -> ";
        temp = temp->pNext;
    }
    if (pHead != NULL) {
        std::cout << "Node 1: " << pHead->val;
    }
    else {
        std::cout << "NULL";
    }
}

void CircularSingleLinkedList::search(int val) {
    SingleNode* temp = pHead;
    for (int i = 0; i < size; i++) {
        if (temp->val == val) {
            std::cout << "\nFound value: " << temp->val << " at index " << i << ".\n";
            return;
        }
        temp = temp->pNext;
    }
    std::cout << "\nGiven value not found.\n";
}

void CircularSingleLinkedList::deleteNode(int index) {
    if (size == 0) {
        std::cout << "\nLinked List is already empty.\n";
    }
    else if (size == 1) {
        std::cout << "\nDeleting the only node in the List.\n";
        delete pHead;
        pHead = NULL;
        pTail = NULL;
        size--;
    }
    else {
        SingleNode *deleteNode;
        if (index == 0) {
            deleteNode = pHead;
            pHead = pHead->pNext;
            pTail->pNext = pHead;
            delete deleteNode;
        } else if (index == size - 1) {
            deleteNode = pTail;
            SingleNode *temp = pHead;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->pNext;
            }
            temp->pNext = pHead;
            pTail = temp;
            delete deleteNode;
        } else {
            if (rangeCheck(index)) {
                SingleNode *temp = pHead;
                for (int i = 0; i < index - 1; i++) {
                    temp = temp->pNext;
                }
                deleteNode = temp->pNext;
                temp->pNext = deleteNode->pNext;
                delete deleteNode;
            } else {
                std::cout << "\nIndex out of range.\n";
            }
        }
        size--;
    }
}

void CircularSingleLinkedList::deleteList() {
    SingleNode* temp = pHead;
    pTail->pNext = NULL;
    while(pHead != NULL) {
        temp = temp->pNext;
        delete pHead;
        pHead = temp;
    }
    pTail = NULL;
    size = 0;
}


#endif //LINKED_LIST_CIRCULARSINGLELINKEDLIST_H
