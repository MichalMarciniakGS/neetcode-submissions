class DynamicArray {

private:
int* newArray;
int capacity;
int length;

public:

    DynamicArray(int capacity) : capacity(capacity), length(0) {
        if(capacity > 0){
            newArray = new int[capacity];
        }
    }

    int get(int i) {
        return newArray[i];
    }

    void set(int i, int n) {
        newArray[i] = n;
    }

    void pushback(int n) {
        if (length == capacity){
            resize();
        }
        newArray[length] = n;
        length++;
    }

    int popback() {
        if (length > 0){
            length--;
        }
        return newArray[length];
    }

    void resize() {
        capacity = getCapacity()*2;
        int* newestArray = new int[capacity];
        for(int i=0;i < getSize(); i++){
            newestArray[i] = newArray[i];
        }
        delete[] newArray;
        newArray = newestArray;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
