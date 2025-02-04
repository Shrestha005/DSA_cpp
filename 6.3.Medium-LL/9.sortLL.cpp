#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1, Node*next1, Node*back1){
        data= data1;
        next= next1;
        back= back1;
    }
    Node(int data1){
        data= data1;
        next= nullptr;
        back= nullptr;
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

//BRUTE
// Node* sortLL(Node* head){
//     vector<int> arr;
//     Node* temp=head;
//     while (temp!=NULL)
//     {
//         arr.push_back(temp->data);
//         temp=temp->next;
//     }
//     sort(arr.begin(),arr.end());
//     temp=head;
//     for (int i=0; i<arr.size(); i++)
//     {
//         temp->data=arr[i];
//         temp=temp->next;
//     }
//     return head;
// }


//OPTIMAl (using merge sort)
Node* mergeSortedLL(Node* low, Node* high){
    Node* dummy= new Node(-1);
    Node* temp= dummy;
    while (low!=NULL && high!=NULL)
    {
        if(low->data <= high->data){
            temp->next= low;
            low= low->next;
        } else{
            temp->next= high;
            high= high->next;
        }
        temp= temp->next;
    }
    if(low!=NULL) temp->next= low;
    else temp->next= high;
    return dummy->next;
}

Node *findMiddle(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* slow= head;
    Node* fast= head->next;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
}
Node* sortLL(Node* head){
    if(head==NULL||head->next==NULL) return head;
    Node* middle= findMiddle(head);
    Node* left= head;
    Node* right= middle->next;
    middle->next= NULL; 
    left= sortLL(left);
    right= sortLL(right);
    return mergeSortedLL(left,right);
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);
    cout << "Original LL: ";
    printLL(head);
    head = sortLL(head);
    cout << "Sorted LL: ";
    printLL(head);
    return 0;
}
   
     