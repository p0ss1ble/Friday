#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>
#include <stdarg.h>

using namespace std;

//1 variant
//stack like plates(how to add and erase)
class Stack{
    public:
    vector<int> numbers;

    Stack(vector<int> x): numbers(x) {}
    Stack(){}

    void Push(int chislo){
        numbers.push_back(chislo);
    }

    bool Empty(){
        return numbers.empty();
    }

    int Pop(){
        int last_element = numbers[numbers.size() -1];
        if(!Empty())
            numbers.pop_back();
        return last_element;
    }

    int End(){
        return numbers.back();
    }

    /*Stack(int n, ...){
    va_list factor;
    va_start(factor, n);
    for(int i = 0; i < n; i++){
        numbers.push_back(va_arg(factor, int));
    }
    }*/

    // Stack(int first = -1, ...){
    //     if(first != -1){
    //         numbers.push_back(first);
    //     }
    //     va_list factor;
    //     va_start(factor, first);
    //     while((int)*factor > 0){
    //         numbers.push_back(va_arg(factor, int));
    //     }
    //     va_end(factor);
    // }
}; 

// the first go, the first out

class Queue{
    private: 
    vector<int> numbers;

    public:
    void Enqueue(int value){
        numbers.push_back(value);
    }

    bool Empty(){
        return numbers.empty();
    }
    int Dequeue(){
        int first_element = numbers[0];
        if(!Empty()){
            numbers.erase(numbers.begin());
        }
        return first_element;
    }

    int First(){
        return numbers.front();
    }
}; 

int main(){
    /*Stack stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    cout << stack.Pop() << '\n';
    for(int  i = 0; i < stack.numbers.size(); i++){
        cout << stack.numbers[i] << " ";
    }*/
    
    /*
    //this method also works
    while(!stack.Empty()){
        cout << stack.Pop() << '\n';
    }
    */

    /*vector<int> a = {1,2,3};
    Stack st1(a);
    for( int i = 0; i < st1.numbers.size(); i++){
        cout << '\n' << st1.numbers[i];
    }*/
    
    // Stack st(3, 1,2,3);
    // for( int i = 0; i < st.numbers.size(); i++){
    //     cout << '\n' << st.numbers[i];
    // }

    /*
    Queue queue;
    queue.Enqueue(4);
    queue.Enqueue(5);

    while(!queue.Empty()){
        cout << queue.First() << queue.Dequeue() << endl;
    }
    */

}

/*
//2 variant
class Stack{
    private:
    vector<int> numbers;

    public: 
    void Push(int chislo){
        numbers.push_back(chislo);
    }

    bool Empty(){
        return numbers.empty();
    }

    virtual int Pop(){
        last_element = numbers[]
        if(!Empty())
            numbers.pop_back();
    }

    int End(){
        return numbers.back();
    }
};

class Queue: public Stack{
    private:
    vector<int> numbers;

    public: 

    int Pop() override{
        if(!Empty())
            numbers.erase(numbers.begin());
    }

    int First(){
        return numbers.front();
    }
    
} */
/*
class Stack{
    private:
    vector<int> numbers;
    public:
    void push(int value){
        numbers.push_back(value);
    }
    bool Empty(){
        return numbers.empty();
    }
    void pop(){
        if(!Empty())
            numbers.pop_back();
    }
    int end() {
        return numbers.back();
        //last number remember
    }
};
class Queue: public Stack{
    private:
    vector<int> numbers;
    public:
    void push(int value){
        vector<int> time;
        while(!Empty()){
            time.push_back(end());
            pop();
        }
        time.push_back(value);
        while(!time.empty()){
            push(time.back());
            time.pop_back();
        }
    }

    void pop(){
        if(!Empty()){
            numbers.erase(numbers.begin());
        }
    }

};
*/


/*
//3 variant
//override используется в классе-потомке, 
//чтобы указать что функция должна переопределять виртуальную функцию, объявленную в базовом классе.
class Interface{
    public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual bool Empty() = 0;
};

class C1 : public Interface {
    private:
    vector<int> numbers;

    public:
    void push(int value) override{
        numbers.push_back(value);
    }

    bool Empty() override{
        return numbers.empty();
    }
    void pop() override{
        if(!Empty())
            numbers.pop_back();
    }
};

class C2 : public C1{
    private:
    vector<int> numbers;

    public:
    void pop() override{
        if(!Empty())
            numbers.erase(numbers.begin());
    }
};

int main(){
    C1 c1;
    c1.push(1);
    c1.push(2);

    C2 c2;
    c2.push(1);

}
*/