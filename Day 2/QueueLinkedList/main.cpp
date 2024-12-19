#include <iostream>

using namespace std;
class Node{
public:
int data;
Node* next;
    Node(int d){
    data = d;
    next = NULL;
    }

};

class QueueLL{
    Node * front;
    Node* rear;
 public:
    QueueLL(){
    front = NULL;
    rear = NULL;
    }
   void enqueue(int data){
        Node* node = new Node(data);
    if(front == NULL && rear == NULL){
        front = node;
        rear = node;
    }
    rear->next = node;
    rear = node;

    }
    int dequeue(){
    if(front == NULL && rear == NULL){
        throw "Queue Empty";
    }
    Node* deleted = front;
    int returned = front->data;
    front = front->next;
    delete deleted;
    if(front == NULL)
        rear == NULL;
    return returned;

    }
    int getFront(){
    if(front == NULL)
        throw "Queue empty";
    return front->data;
    }

     int getRear(){
    if(front == NULL)
        throw "Queue empty";
    return rear->data;
    }

    void display(){
        if(front == NULL)
            throw "Queue is empty";
      Node*  cursor = front;
    while(cursor != NULL){
        cout << cursor->data<<endl;
        cursor = cursor->next;

    }

    }

};
int main()
{
    QueueLL q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    try{
    q.display();
    }
    catch (const char* msg){
    cout << msg;
    }
    return 0;
}
