#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>
#include <stdarg.h>

using namespace std;

class Interface{
    public:
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    //virtual bool Empty() = 0;
};

class LinkedListNode {
public:
    int value;
    LinkedListNode* next;

    LinkedListNode(int val) : value(val), next(nullptr) {}
};

class LinkedList: public Interface {
    public:
    int value = 0;
    LinkedListNode* head = nullptr;
    int length = 0;

    int len() {
        return length;
    }

    void push(int value) {
        LinkedListNode* newNode = new LinkedListNode(value);
        if (head == nullptr) {
            head = newNode;
        } 
        else {
            LinkedListNode* current = head;
            while ((*current).next != nullptr) {
                current = (*current).next;
            }
            (*current).next = newNode;
        }
        length++;
    }

    int pop() {
        if (head == nullptr) {
            cout << "Empty";
            return -1;
        }
        int poppedValue = (*head).value;
        LinkedListNode* temp = head;
        head = (*head).next;
        delete temp;
        length--;
        return poppedValue;
    }

    // bool Empty() {
    //     return head == nullptr;
    // }

    void printList() {
        LinkedListNode* current = head;
        while (current != nullptr) {
            cout << (*current).value << " ";
            current = (*current).next;
        }
        // if(current == nullptr){
        //     cout << "EMPTY!" << "\n";
        // }
    }

};

template<typename T>
void reverse(T& a){
    for (int i = 0; i < a.get_data().size() / 2; i++) {
        swap(a.get_data()[i], a.get_data()[a.get_data().size() - i - 1]);
    }
}

void reverse(LinkedList& a){
    vector<int> list_body;
    int lenght = a.len();
    for (int i = 0; i < lenght; i++) {
        list_body.push_back(a.pop());
    }
    for (int i = lenght-1; i >= 0; i--) {
        a.push(list_body[i]);
    } 
}

int main(){
    LinkedList ll;
    ll.push(50);
    ll.push(60);
    ll.push(70);
    ll.printList();
    reverse(ll);
    ll.printList();
    return 0;
}