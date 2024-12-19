#include <iostream>

using namespace std;
class Node{
public:
int data;
Node* prev;
    Node(int d){
    data = d;
    prev = NULL;
    }
};
class StackLL{
Node* top;

public:
    StackLL(){
          top = NULL;
    }
    void push(int data){
    Node * n = new Node(data);
    n->prev = top;
    top = n;
    cout << top->data <<"  "<< n->data <<endl;
    }

    int pop(){
    if(top == NULL)
        throw "Stack Empty";

    Node* deleted = top;
    top = top->prev;
    int returned = deleted->data;
    delete deleted;
    return returned;

    }
    int peek(){
    if(top == NULL)
        throw "Stack is empty";
    return top->data;
    }
    void display(){
    if(top == NULL)
        throw "Stack is empty";
    Node* cursor = top;
    while(cursor != NULL){
        cout<<cursor->data<<endl;
        cursor = cursor->prev;
    }
    }



};

int main()
{
    cout << "Hello world!" << endl;
    StackLL s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    try{
   cout<< s.pop()<<endl;
   cout<< s.pop()<<endl;
   cout<< s.pop()<<endl;
        s.pop();}
        catch(const char* e){
           cout << e;
        }
    return 0;
}
