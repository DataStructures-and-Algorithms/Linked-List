//
// Created by Hayden Huynh on 10/29/19.
//

#ifndef LINKED_LIST_CIRCULARDOUBLELINKEDLIST_H
#define LINKED_LIST_CIRCULARDOUBLELINKEDLIST_H

#include "DoubleNode.h"

class CircularDoubleLinkedList {

private:
    DoubleNode* pHead;

    DoubleNode* pTail;

    int size;

    bool rangeCheck(int i);

public:
    CircularDoubleLinkedList();

    void insert(int val, int index);

    void traverse();

    void reverseTraverse();

    void search(int val);

    void deleteNode(int index);

    void deleteList();
};

CircularDoubleLinkedList::CircularDoubleLinkedList() {
    pHead = NULL;
    pTail = NULL;
    size = 0;
}

bool CircularDoubleLinkedList::rangeCheck(int i) {
    return 0 <= i && i < size;
}

void CircularDoubleLinkedList::insert(int val, int index) {
    DoubleNode* node = new DoubleNode(val);
    if (size == 0) {
        std::cout << "\nInserting the first node.\n";
        node->pNext = node;
        node->pPrev = node;
        pHead = node;
        pTail = node;
    }
    else {
        if (index == 0) {
            node->pNext = pHead;
            node->pPrev = pTail;
            pTail->pNext = node;
            pHead->pPrev = node;
            pHead = node;
        }
        else if (index == size) {
            node->pPrev = pTail;
            node->pNext = pHead;
            pTail->pNext = node;
            pHead->pPrev = node;
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

void CircularDoubleLinkedList::traverse() {
    DoubleNode* temp = pHead;
    for (int i = 0; i < size; i++) {
        std::cout << "Node " << i+1 << ": " << temp->val << " <-> ";
        temp = temp->pNext;
    }
    if (pHead != NULL) {
        std::cout << "Node 1: " << pHead->val << "\n\n";
    }
    else {
        std::cout << "NULL\n\n";
    }

}

void CircularDoubleLinkedList::reverseTraverse() {
    DoubleNode* temp = pTail;
    for (int i = size; i > 0; i--) {
        std::cout << "Node " << i << ": " << temp->val << " <-> ";
        temp = temp->pPrev;
    }
    if (pTail != NULL) {
        std::cout << "Node " << size << ": " << pTail->val << "\n\n";
    }
    else {
        std::cout << "NULL\n\n";
    }
}

void CircularDoubleLinkedList::search(int val) {
    DoubleNode* temp = pHead;
    for (int i = 0; i < size; i++) {
        if (temp->val == val) {
            std::cout << "\nFound value: " << temp->val << " at index " << i << ".\n";
            return;
        }
        temp = temp->pNext;
    }
    std::cout << "\nGiven value not found.\n";
}

void CircularDoubleLinkedList::deleteNode(int index) {
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
            pHead->pNext->pPrev = pTail;
            pHead = pHead->pNext;
            pTail->pNext = pHead;
            delete deleteNode;
        }
        else if (index == size-1) {
            deleteNode = pTail;
            pTail->pPrev->pNext = pHead;
            pTail = pTail->pPrev;
            pHead->pPrev = pTail;
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

void CircularDoubleLinkedList::deleteList() {
    pHead->pPrev = NULL;
    pTail->pNext = NULL;
    DoubleNode* temp = pHead;
    while (pHead != NULL) {
        temp = temp->pNext;
        delete pHead;
        pHead = temp;
    }
    pTail = NULL;
    size = 0;
}

#endif //LINKED_LIST_CIRCULARDOUBLELINKEDLIST_H
