#include <iostream>
using namespace std;

// 노드 구조체
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

/*
-> Node는 연결 리스트의 한 칸임
data에는 실제 값이 들어가고 next에는 다음 노드의 주소가 들어감
Node(int val) : data(val), next(nullptr){}는 생성자임
새 노드를 만들 때 data =ㅍval
next = nullptr로 초기화
즉 노드를 만들면 처음에는 다음 노드 없음 상태로 시작하는 것이다.

*/


// 연결 리스트 클래스
class LinkedList {
private:
    Node* head;
/*
LinkedList는 리스트 전체를 관리하느  클래스
head는 리스트의 첫번째 노드 주소를 저장한다
privatㄷ로 둔 이유는 외부에서 마음대로 head를 바꾸지 못하게 하기 위해서이다
*/

public:
    LinkedList() : head(nullptr) {}
/*
생성자이다.
처음 리스트를 만들면 비어 있으므로 head = nullptr로 시작한다
즉 아무 노드도 없는 상태
*/

    // 맨 앞에 삽입
    void pushFront(int val) {
        Node* newNode = new Node(val);//이뜻은 새 노드를 동적 메모리로 생성하는 것이다
        newNode->next = head; // 새 노드의 다음 칸을 현재 노드로 연결하는 것
        head = newNode;//이제 새 노드가 첫 노드가 된다.
    }
    
 
    // 맨 뒤에 삽입
    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next){
        curr = curr->next;
        }
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
    list.pushFront(55);


    cout << "초기 리스트: ";
    list.print();  // 5 -> 10 -> 20 -> 30 -> NULL

    list.remove(20);
    cout << "20 삭제 후: ";
    list.print();  // 5 -> 10 -> 30 -> NULL

    return 0;
}