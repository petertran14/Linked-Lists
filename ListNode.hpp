#ifndef LISTNODES_LISTNODE_HPP
#define LISTNODES_LISTNODE_HPP

#include <iostream>

using namespace std;

class BADINDEX {};

class ListNode
{
    struct Node
    {
        int data;
        Node *next;

        Node(int d)
        {
            this->data = d;
        }
    };

    Node *head;
    Node *tail;

public:
    ListNode();
    ~ListNode();
    ListNode(const ListNode&);
    ListNode& operator=(const ListNode&);

    ListNode& pushBack(int);
    ListNode& pushFront(int);
    ListNode& popBack(int&);
    ListNode& popFront(int&);

    bool isEmpty() const;
    int getSize() const;
    int Front() const;
    int Back() const;
    int operator[](int) const;
    void add(int);
};

ListNode::ListNode() {

    this->head = NULL;
    this->tail = NULL;
}

ListNode::~ListNode() {

    Node *temp = this->head;

    while(temp) {

        this->head = this->head->next;
        temp->next = NULL;
        delete temp;
        temp = this->head;
    }
}

ListNode::ListNode(const ListNode &that) {

    this->head = this->tail = NULL;

    if (that.getSize() > 0) {

        Node *temp = that.head;

        if(this->isEmpty()) {

            this->head = new Node(temp->data);
            this->head->next = NULL;
            this->tail = this->head;
            temp = temp->next;
        }

        while(temp) {

            this->tail->next = new Node(temp->data);
            this->tail = this->tail->next;
            this->tail->next = NULL;
            temp = temp->next;
        }
    }
}

ListNode& ListNode::operator=(const ListNode &that) {

    if (this != &that) {

        Node *garbage = this->head;

        while(garbage) {

            this->head = this->head->next;
            garbage->next = NULL;
            delete garbage;
            garbage = this->head;
        }
    }

    Node *temp = that.head;

    if (this->isEmpty()) {

        this->head = new Node(temp->data);
        this->head->next = NULL;
        this->tail = this->head;
        temp = temp->next;
    }

    while (temp) {

        this->tail->next = new Node(temp->data);
        this->tail = this->tail->next;
        this->tail->next = NULL;
        temp = temp->next;
    }

    return *this;
}

ListNode& ListNode::pushBack(int value) {

    if(this->isEmpty()) {

        this->head = new Node(value);
        this->head->next = NULL;
        this->tail = this->head;
    }

    else {

        this->tail->next = new Node(value);
        this->tail = this->tail->next;
        this->tail->next = NULL;
    }

    return *this;
}

ListNode& ListNode::pushFront(int value) {

    if(this->isEmpty()) {

        this->head = new Node(value);
        this->head->next = NULL;
        this->tail = this->head;
    }

    else {

        Node *temp = new Node(value);
        temp->next = this->head;
        //this->head->next = temp;
        this->head = temp;
    }

    return *this;
}

ListNode& ListNode::popBack(int &value) {

    if(this->isEmpty()) {

        throw BADINDEX();
    }

    value = this->tail->data;

    if(this->getSize() == 1) {

        delete this->head;
        this->head = this->tail = NULL;
    }

    else {

        Node *garbage = this->tail;
        Node *temp = this->head;

        while (temp->next->next) {

            temp = temp->next;
        }

        this->tail = temp;
        this->tail->next = NULL;
        garbage->next = NULL;
        delete garbage;
    }

    return *this;
}

ListNode& ListNode::popFront(int &value) {

    if (this->isEmpty()) {

        throw BADINDEX();
    }

    value = this->head->data;

    if (this->getSize() == 1) {

        delete this->head;
        this->head = this->tail = NULL;
    }

    else {

        Node *garbage = this->head;
        this->head = this->head->next;
        garbage->next = NULL;
        delete garbage;
    }

    return *this;
}

bool ListNode::isEmpty() const {

    return this->head == NULL;
}

int ListNode::getSize() const {

    Node *temp = this->head;
    int count = 0;

    while (temp) {

        temp = temp->next;
        count++;
    }

    return count;
}

int ListNode::Front() const {

    return this->head->data;
}

int ListNode::Back() const {

    return this->tail->data;
}

int ListNode::operator[](int index) const {

    if (this->isEmpty()) {

        throw BADINDEX();
    }

    Node *temp = this->head;
    int count = 0;

    while (temp) {

        if (count == index) {

            return temp->data;
        }

        temp = temp->next;
        count++;
    }

    throw BADINDEX();
}

void ListNode::add(int num) {

    Node *temp = this->head;

    if (this->head == NULL || num <= this->head->data) {

        this->head = new Node(num);
        this->head->next = temp;
    }

    else {

        Node *post = this->head->next;

        while (post != NULL && post->data < num) {

            temp = post;
            post = post->next;
        }

        temp->next = new Node(num);
        temp->next->next = post;
    }
}


#endif //LISTNODES_LISTNODE_HPP
