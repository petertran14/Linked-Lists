#ifndef LISTNODES_QUEUES_HPP
#define LISTNODES_QUEUES_HPP

class IntQueue
{
private:
    int *data;
    int capacity;
    int front;
    int rear;
    int size;

public:
    IntQueue();
    ~IntQueue();
    IntQueue(const IntQueue&);
    IntQueue& operator=(const IntQueue&);

    void enqueue(int);
    void dequeue(int&);
};

IntQueue::IntQueue() {

    this->size = 0;
    this->capacity = 10;
    this->data = new int(this->capacity);
    this->front = -1;
    this->rear = -1;
}

IntQueue::~IntQueue() {

    delete [] this->data;
}

IntQueue::IntQueue(const IntQueue& that) {

    this->size = that.size;
    this->capacity = that.capacity;

    this->data = new int[this->capacity];

    for (int i = 0; i < this->size; i++) {

        this->data[i] = that.data[i];
    }

    this->front = 0;
    this->rear = this->size - 1;
}

IntQueue& IntQueue::operator=(const IntQueue& that) {

    if (this != &that) {

        this->size = that.size;
        this->capacity = that.capacity;
        delete [] this->data;

        this->data = new int[this->capacity];

        for (int i = 0; i < this->size; i++) {

            this->data[i] = that.data[i];
        }

        this->front = 0;
        this->rear = this->size - 1;
    }

    return *this;
}

void IntQueue::enqueue(int value) {

    if (this->size == this->capacity) {

        //grow()
    }

    this->rear = this->rear + 1 % this->capacity;

    this->data[this->rear] = value;

    this->size++;
}

void IntQueue::dequeue(int& value) {

    if (this->size == this->capacity) {

        //grow()
    }

    this->front = this->front + 1 % this->capacity;

    value = this->data[this->front];

    this->size--;
}


#endif //LISTNODES_QUEUES_HPP
