class MyCircularQueue {
public:
    int *arr;
    int size;
    int front;
    int rear;

    // Initialize the queue with capacity k
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    // Insert element into circular queue
    bool enQueue(int value) {
        if (isFull())
        return false;

        // First element
        if (front == -1) {
            front = rear = 0;
            arr[rear] = value;
        }
        // Circular wrap
        else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        }
        // Normal case
        else {
            rear++;
            arr[rear] = value;
        }
        return true;
    }
    
    // Delete element from circular queue
    bool deQueue() {
        if (isEmpty()) 
        return false;

        // Single element case
        if (front == rear) {
            front = rear = -1;
        }
        // Circular wrap
        else if (front == size - 1) {
            front = 0;
        }
        // Normal case
        else {
            front++;
        }
        return true;
    }
    
    // Get front item
    int Front() {
        if (isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    // Get rear item
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }
    
    // Check if queue is full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front == (rear + 1) % size));
    }
};