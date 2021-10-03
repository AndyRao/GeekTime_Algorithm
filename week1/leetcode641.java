class MyCircularDeque {
    private int front;
    private int rear;
    private int capacity;
    private int[] deque;
    public MyCircularDeque(int k) {
        this.front = 0;
        this.rear = 0;
        this.capacity = k + 1;
        this.deque = new int[capacity];

    }
    
    public boolean insertFront(int value) {
      if(isFull()) {
          return false;
      }
      front = (front - 1 + capacity) % capacity;
      deque[front] = value;
      return true;  
    }
    
    public boolean insertLast(int value) {
        if(isFull()) {
            return false;
        }
        deque[rear] = value;
        rear = (rear + 1) % capacity;
        return true; 
    }
    
    public boolean deleteFront() {
        if(isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }
    
    public boolean deleteLast() {
        if(isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }
    
    public int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return deque[front];
    }
    
    public int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return deque[(rear - 1 + capacity) % capacity];
    }
    
    public boolean isEmpty() {
        return front == rear;
    }
    
    public boolean isFull() {
        return (rear + 1) % capacity == front;
    }
}

