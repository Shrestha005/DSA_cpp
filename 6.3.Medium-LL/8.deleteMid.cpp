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

void printLL(Node* head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
 }

//BRUTE
// Node* delMid(Node* head){
//     if (head == NULL || head->next == NULL) {
//         delete(head);
//         return NULL;
//     }
//     Node* temp= head;
//     int cnt=0;
//     while (temp!=NULL)
//     {
//         cnt++;
//         temp=temp->next;
//     }
//     int count= cnt/2;
//     temp=head;
//     while(temp!=NULL){
//         count--;
//         if(count==0){
//             Node* middle= temp->next;
//             temp->next= temp->next->next;
//             delete(middle);
//             break;
//         }
//         temp=temp->next;
//     }
//     return head;
// }

//OPTIMAL
Node* delMid(Node* head){
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* slow= head;
    Node* fast= head;
    fast=head->next->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=slow->next->next;
    return head;
}



int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Orginal LL: ";
    printLL(head);

    head = delMid(head);

    cout << "LL with mid deleted: ";
    printLL(head);

    return 0;
}