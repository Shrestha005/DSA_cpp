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

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// bool pallindrome(Node* head){
//     stack<int> st;
//     Node* temp= head;
//     while(temp!=NULL){
//         st.push(temp->data);
//         temp= temp->next;
//     }
//     temp= head;
//     while(temp!=NULL){
//         if(temp->data != st.top()) return false;
//         st.pop();
//         temp= temp->next;
//     }
//     return true;
// }

Node* reverseLL(Node* head){
    if(head==NULL||head->next==NULL) return head;
    Node* newHead= reverseLL(head->next);
    Node* front= head->next;
    front->next= head;
    head->next= NULL;
    return newHead;
}


bool pallindrome(Node* head){
    Node* slow= head;
    Node* fast= head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;
    }
    Node* newHead= reverseLL(slow->next);
    Node* first= head;
    Node* second= newHead;
    while(second!=NULL){
        if(first->data != second->data){
            reverseLL(newHead); //re-reversing so that it comes back to original LL
            return false;
        }
        first= first->next;
        second= second->next;
    }
    reverseLL(newHead); //re-reversing so that it comes back to original LL
    return true;
}


int main() {
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original LL: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (pallindrome(head)) {
        cout << "LL is a palindrome" << endl;
    } else {
        cout << "LL is not a palindrome" << endl;
    }

    return 0;
}

