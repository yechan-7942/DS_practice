#include <iostream>
using namespace std;

// 노드 구조체
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// 연결 리스트 클래스
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // 맨 앞에 삽입
    void pushFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 맨 뒤에 삽입
    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }

    // 특정 값 삭제
    void remove(int val) {
        if (!head) return;

        // 헤드가 삭제 대상일 때
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        while (curr->next && curr->next->data != val)
            curr = curr->next;

        if (curr->next) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }

    // 출력
    void print() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }

    // 소멸자 (메모리 해제)
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);
    list.pushFront(5);

    cout << "초기 리스트: ";
    list.print();  // 5 -> 10 -> 20 -> 30 -> NULL

    list.remove(20);
    cout << "20 삭제 후: ";
    list.print();  // 5 -> 10 -> 30 -> NULL

    return 0;
}