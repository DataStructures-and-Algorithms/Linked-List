//
// Created by Hayden Huynh on 10/28/19.
//

#ifndef LINKED_LIST_SINGLENODE_H
#define LINKED_LIST_SINGLENODE_H

#include <iostream>

class SingleNode {

public:

    int val;

    SingleNode* pNext;

    SingleNode(int val);

};

SingleNode::SingleNode(int val) {
    this->val = val;
    pNext = NULL;
}

#endif //LINKED_LIST_SINGLENODE_H
