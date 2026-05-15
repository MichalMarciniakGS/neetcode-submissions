struct ListNode{
    ListNode* prev;
    ListNode* next;
    int val;

    ListNode(int val) : val(val), prev(nullptr), next(nullptr) {};
};

class Deque {

    private:
    ListNode* dummyHead;
    ListNode* dummyTail;

public:
    Deque() {
        dummyHead = new ListNode(0);
        dummyTail = new ListNode(0);

        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    bool isEmpty() {
        return dummyHead->next == dummyTail;
    }

    void append(int value) {
        ListNode* newNode = new ListNode(value);
        ListNode* prevNode = dummyTail->prev;

        newNode->next = dummyTail;
        newNode->prev = prevNode;

        prevNode->next = newNode;
        dummyTail->prev = newNode;
    }

    void appendleft(int value) {
        ListNode* newNode = new ListNode(value);
        ListNode* nextNode = dummyHead->next;

        newNode->prev = dummyHead;
        newNode->next = nextNode;

        dummyHead->next = newNode;
        nextNode->prev = newNode;
    }

    int pop() {
        if(isEmpty()){
            return -1;
        }
        ListNode* prevNode = dummyTail->prev->prev;
        int retVal = dummyTail->prev->val;

        dummyTail->prev = prevNode;
        prevNode->next = dummyTail;

        return retVal;
    }

    int popleft() {
        if(isEmpty()){
            return -1;
        }

        ListNode* nextNode = dummyHead->next->next;
        int retVal = dummyHead->next->val;

        dummyHead->next = nextNode;
        nextNode->prev = dummyHead;

        return retVal;
    }
};
