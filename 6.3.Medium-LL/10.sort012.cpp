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

//Brute
// Node* sort012(Node* head){
//     Node* temp= head;
//     int cnt0=0, cnt1=0, cnt2=0;
//     while(temp!=NULL){
//         if(temp->data==0) cnt0++;
//         else if(temp->data==1) cnt1++;
//         else if (temp->data==2) cnt2++;
//         temp= temp->next;
//     }
//     temp= head;
//     while(temp!=NULL){
//         if(cnt0>0){
//             temp->data=0;
//             cnt0--;
//         }
//         else if(cnt1>0){
//             temp->data=1;
//             cnt1--;
//         }
//         else{
//             temp->data=2;
//             cnt2--;
//         }
//         temp=temp->next;
//     }
//     return head;
// }


//Optimal
Node* sort012(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* zeroHead= new Node(-1);
    Node* oneHead= new Node(-1);
    Node* twoHead= new Node(-1);

    Node* zero= zeroHead;
    Node* one= oneHead;
    Node* two= twoHead;

    Node* temp= head;
    while (temp!=NULL)
    {
        if(temp->data==0){
            zero->next= temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next= temp;
            one=temp;
        }
        else{
            two->next= temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next= (oneHead->next) ? oneHead->next : twoHead->next;
    one->next= (twoHead->next) ? twoHead->next : NULL;
    two->next= NULL;

    Node* newHead= zeroHead->next;
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);

    return newHead;
}


int main() {
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(0);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    cout << "Original LL: ";
    printLL(head);
    head = sort012(head);
    cout << "Sorted LL: ";
    printLL(head);
    return 0;
}
   
     