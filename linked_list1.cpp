#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node(int val) : data(val), next(nullptr) {}

    int getData() { return data; }
    void setData(int val) { data = val; }

    Node* getNext() { return next; }
    void setNext(Node* node) { next = node; }
};

class Linkedlist{
    private:
    Node* head;

    public:
    Linkedlist() : head(nullptr){}




};





int main(){
    
}