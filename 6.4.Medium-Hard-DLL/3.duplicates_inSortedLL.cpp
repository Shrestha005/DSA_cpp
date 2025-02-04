#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

Node* convertArrToDLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp; 
    }
    return head;
}

void printLL(Node* head){
    while (head!=NULL)
    {
        cout<< head->data<< " ";
        head= head->next;
    }
}



//tc is O(n)
Node* removeDuplicates(Node* head) {
    Node* temp= head;
    while(temp != NULL && temp->next != NULL){
        Node* nextNode= temp->next;
        while(nextNode != NULL && nextNode->data == temp->data){
            Node* duplicate= nextNode;
            nextNode= nextNode->next;
            delete(duplicate);
        }
        temp->next= nextNode;
        if(nextNode) nextNode->back= temp;
        temp=temp->next;
    }
    return head;
}
int main() {
    vector<int> arr = {2, 2, 3, 3, 4, 4, 5, 10}; // Example with duplicates
    Node* head = convertArrToDLL(arr);

    cout << "Original List: ";
    printLL(head);

    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printLL(head);

    return 0;
}
