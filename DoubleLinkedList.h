//
// Created by Hayden Huynh on 10/29/19.
//

#ifndef LINKED_LIST_DOUBLELINKEDLIST_H
#define LINKED_LIST_DOUBLELINKEDLIST_H

#include "DoubleNode.h"

class DoubleLinkedList {

private:
    DoubleNode* pHead;

    DoubleNode* pTail;

    int size;

    bool rangeCheck(int i);

public:
    DoubleLinkedList();

    void insert(int val, int index);

    void traverse();

    void reverseTraverse();

    void search(int val);

    void deleteNode(int index);

    void deleteList();
};

DoubleLinkedList::DoubleLinkedList() {
    pHead = NULL;
    pTail = NULL;
    size = 0;
}

bool DoubleLinkedList::rangeCheck(int i) {
    return 0 <= i && i < size;
}

void DoubleLinkedList::insert(int val, int index) {
    DoubleNode* node = new DoubleNode(val);
    if (size == 0) {
        std::cout << "\nInserting the first node.\n";
        pHead = node;
        pTail = node;
    }
    else {
        if (index == 0) {
            node->pNext = pHead;
            pHead->pPrev = node;
            pHead = node;
        }
        else if (index == size) {
            pTail->pNext = node;
            node->pPrev = pTail;
            pTail = node;
        }
        else {
            if (rangeCheck(index)) {
                DoubleNode* temp = pHead;
                for (int i = 0; i < index - 1; i++) {
                    temp = temp->pNext;
                }
                node->pPrev = temp;
                node->pNext = temp->pNext;
                temp->pNext->pPrev = node;
                temp->pNext = node;
            }
            else {
                std::cout << "\nIndex out of range.\n";
            }
        }
    }
    size++;
}

void DoubleLinkedList::traverse() {
    DoubleNode* temp = pHead;
    int count = 1;
    while (temp != NULL) {
        std::cout << "Node " << count << ": " << temp->val << " <-> ";
        count++;
        temp = temp->pNext;
    }
    std::cout << "NULL\n\n";
}

void DoubleLinkedList::reverseTraverse() {
    DoubleNode* temp = pTail;
    int count = size;
    while (temp != NULL) {
        std::cout << "Node " << count << ": " << temp->val << " <-> ";
        count--;
        temp = temp->pPrev;
    }
    std::cout << "NULL\n\n";
}

void DoubleLinkedList::search(int val) {
    DoubleNode* temp = pHead;
    int count = 0;
    while (temp != NULL) {
        if (temp->val == val) {
            std::cout << "\nFound value: " << temp->val << " at index " << count << ".\n";
            return;
        }
        count++;
        temp = temp->pNext;
    }
    std::cout << "\nGiven value not found.\n";
}

void DoubleLinkedList::deleteNode(int index) {
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
        DoubleNode* deleteNode;
        if (index == 0) {
            deleteNode = pHead;
            pHead->pNext->pPrev = NULL;
            pHead = pHead->pNext;
            delete deleteNode;
        }
        else if (index == size-1) {
            deleteNode = pTail;
            pTail->pPrev->pNext = NULL;
            pTail = pTail->pPrev;
            delete deleteNode;
        }
        else {
            if (rangeCheck(index)) {
                DoubleNode* temp = pHead;
                for (int i = 0; i < index - 1; i++) {
                    temp = temp->pNext;
                }
                deleteNode = temp->pNext;
                temp->pNext = deleteNode->pNext;
                deleteNode->pNext->pPrev = temp;
                delete deleteNode;
            }
            else {
                std::cout << "\nIndex out of range.\n";
            }
        }
        size--;
    }
}

void DoubleLinkedList::deleteList() {
    DoubleNode* temp = pHead;
    while (pHead != NULL) {
        temp = temp->pNext;
        delete pHead;
        pHead = temp;
    }
    pTail = NULL;
    size = 0;
}

#endif //LINKED_LIST_DOUBLELINKEDLIST_H
