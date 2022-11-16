#include<iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
}; 

template<typename T>
class LL {
    Node<T>* head;
    Node<T>* tail;

    LL() {
        head = nullptr;
        tail = nullptr;
    }

    void insertH(T val) {
        Node<T>* n = new Node<T>(val);
        if(head == nullptr) {
            head = n;
            return;
        }

        n->next = head;
        head = n;
    }

    void insertT(T val) {
        Node<T>* n = new Node<T>(val);
        if(head == nullptr) {
            head = n;
            return;
        }

        tail->next = n;
        tail = n;
    }

    void print() {
        while(head != nullptr) {
            cout<<head->data<<" ";
            head= head->next;
        }
        cout<<endl;
    }

};

int main() {

}