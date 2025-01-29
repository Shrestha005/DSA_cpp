#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;   
    Node* next;      

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void printLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* oddEven(Node* head){
    if(head==NULL || head->next==NULL) return head;
    vector<int> arr;
    Node* temp= head;
    //odd
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp= temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    //even
    temp= head->next;
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp= temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    //arr to LL
    int i=0;
    temp= head;
    while(temp!=NULL){
        temp->data= arr[i];
        i++;
        temp= temp->next;
    }
    return head;
}

// Helper function to create a linked list from a vector
Node* createLL(vector<int> values) {
    if (values.empty()) return nullptr;

    Node* head = new Node(values[0]);
    Node* temp = head;
    for (size_t i = 1; i < values.size(); ++i) {
        temp->next = new Node(values[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6, 7};
    Node* head = createLL(values);

    cout << "Original List: ";
    printLL(head);

    head = oddEven(head);

    cout << "Modified List: ";
    printLL(head);

    return 0;
}
