//
// Created by Hayden Huynh on 10/29/19.
//

#ifndef LINKED_LIST_DOUBLENODE_H
#define LINKED_LIST_DOUBLENODE_H

#include <iostream>

class DoubleNode {

public:
    int val;

    DoubleNode* pNext;

    DoubleNode* pPrev;

    DoubleNode(int val);

};

DoubleNode::DoubleNode(int val) {
    this->val = val;
    pNext = NULL;
    pPrev = NULL;
}

#endif //LINKED_LIST_DOUBLENODE_H
