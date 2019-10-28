//
// Created by Hayden Huynh on 10/28/19.
//

#ifndef LINKED_LIST_SINGLELINKEDLIST_H
#define LINKED_LIST_SINGLELINKEDLIST_H

#include "SingleNode.h"

class SingleLinkedList {

public:
    SingleNode* pHead;

    SingleNode* pTail;

    int size;

    SingleLinkedList();

    bool rangeCheck(int i);

    void insert(int val, int index);

    void traverse();

    void search(int val);

    void deleteNode(int index);

    void deleteList();
};

SingleLinkedList::SingleLinkedList() {
    pHead = NULL;
    pTail = NULL;
    size = 0;
}

bool SingleLinkedList::rangeCheck(int i) {
    return 0 <= i && i < size;
}

void SingleLinkedList::insert(int val, int index) {
    SingleNode* node = new SingleNode(val);
    if (size == 0) {
        std::cout << "\nLinked List is empty. Inserting the first node.\n";
        pHead = node;
        pTail = node;
    }
    else {
        if (index == 0) {
            node->pNext = pHead;
            pHead = node;
        }
        else if (index == size) {
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

void SingleLinkedList::traverse() {
    SingleNode* temp = pHead;
    int count = 1;
    while (temp != NULL) {
        std::cout << "Node " << count << ": " << temp->val << " -> ";
        temp = temp->pNext;
        count++;
    }
    std::cout << "NULL\n";
}

void SingleLinkedList::search(int val) {
    SingleNode* temp = pHead;
    int count = 0;
    while (temp != NULL) {
        if (temp->val == val) {
            std::cout << "\nFound value: " << temp->val << " at index " << count << ".\n";
            return;
        }
        temp = temp->pNext;
        count++;
    }
    std::cout << "\nGiven value not found.\n";
}

void SingleLinkedList::deleteNode(int index) {
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
        SingleNode* deleteNode;
        if (index == 0) {
            deleteNode = pHead;
            pHead = pHead->pNext;
            delete deleteNode;
        }
        else if (index == size-1) {
            deleteNode = pTail;
            SingleNode* temp = pHead;
            for (int i = 0; i < index-1; i++) {
                temp = temp->pNext;
            }
            temp->pNext = NULL;
            pTail = temp;
            delete deleteNode;
        }
        else {
            if (rangeCheck(index)) {
                SingleNode *temp = pHead;
                for (int i = 0; i < index - 1; i++) {
                    temp = temp->pNext;
                }
                deleteNode = temp->pNext;
                temp->pNext = deleteNode->pNext;
                delete deleteNode;
            }
            else {
                std::cout << "\nIndex out of range.\n";
            }
        }
        size--;
    }
}

void SingleLinkedList::deleteList() {
    SingleNode* temp = pHead;
    while(pHead != NULL) {
        temp = temp->pNext;
        delete pHead;
        pHead = temp;
    }
    pTail = NULL;
    size = 0;
}

#endif //LINKED_LIST_SINGLELINKEDLIST_H
