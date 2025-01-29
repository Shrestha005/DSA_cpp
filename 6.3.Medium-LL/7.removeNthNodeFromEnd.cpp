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
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

//BRUTE
// Node* nThNodeFromEnd(Node* head, int n){
//     if(head==NULL) return NULL;
//     int cnt=0;
//     Node* temp= head;
//     while(temp!=NULL){
//         cnt++;
//         temp=temp->next;
//     }
//     // if (n > cnt || n <= 0) {
//     //     cout << "Invalid value of n" << endl;
//     //     return head;
//     // }
//     if(cnt==n){
//         Node* newhead= head->next;
//         delete(head);
//         return newhead;
//     }
//     temp=head;
//     int res=cnt-n;
//     while(temp!=NULL){
//         res--;
//         if(res==0) break;
//         temp=temp->next;
//     }
//     Node* nodeToBeDeleted= temp->next;
//     temp->next= temp->next->next;
//     delete(nodeToBeDeleted);
//     return head;
// }


//OPTIMAL
Node* nThNodeFromEnd(Node* head, int k){
    Node* fast= head;
    Node* slow= head;
    for(int i=0; i<k; i++) fast=fast->next;
    if(fast==NULL) return head->next;
    while (fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    Node* delNode= slow->next;
    slow->next= slow->next->next;
    delete(delNode);
    return head;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 4;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    head = nThNodeFromEnd(head, N);
    printLL(head);
} 