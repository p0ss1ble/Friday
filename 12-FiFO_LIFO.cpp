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
    virtual bool Empty() = 0;
};
/*
class General: public Interface{
    public:
    vector<int> numbers;

    void push(int value){
        numbers.push_back(value);
    }

    bool Empty() {
        return numbers.empty();
    }

};

class Stack: public General{
    public:
    Stack(){};

    int pop() {
        int last_element = numbers[numbers.size() - 1];
        if(!Empty())
            numbers.pop_back();
        return last_element;
    }

};

class Queue: public General{
    public:
    Queue(){};

    int pop() {
        int first_element = numbers[0];
        if(!Empty())
            numbers.erase(numbers.begin());
        return first_element;
    }
};*/

class Stack: public Interface{
    public:
    vector<int> numbers;
    Stack(){};

    void push(int value){
        numbers.push_back(value);
    }

    bool Empty() {
        return numbers.empty();
    }

    int pop() {
        int last_element = numbers[numbers.size() - 1];
        if(!Empty())
            numbers.pop_back();
        return last_element;
    }
};

class Queue: public Interface{
    public:
    vector<int> numbers;
    Queue(){};

    void push(int value){
        numbers.push_back(value);
    }

    bool Empty() {
        return numbers.empty();
    }

    int pop() {
        int first_element = numbers[0];
        if(!Empty())
            numbers.erase(numbers.begin());
        return first_element;
    }

    // int pop(){
    //     try {
    //         if (numbers.size() == 0) {
    //             throw std::out_of_range("Queue is already empty!");
    //         }
    //         int tmp;
    //         tmp = numbers[0];
    //         numbers.erase(numbers.cbegin());  
    //         return tmp;
    //     }
    //     catch (std::out_of_range) {
    //         std::cout << "Queue is empty!" << std::endl;
    //         return -1;
    //     }
    // }
};

int main(){
    // Stack c1;
    // c1.push(1);
    // c1.push(2);
    // c1.push(3);

    // cout << c1.pop() << '\n';
    // for(int  i = 0; i < c1.numbers.size(); i++){
    //     cout << c1.numbers[i] << " ";
    // }
    Queue c2;
    c2.push(1);
    c2.push(2);
    c2.push(3);
    cout << c2.pop() << '\n';
    for(int i = 0; i < c2.numbers.size(); i++){
        cout << c2.numbers[i] << " ";
    }

} 