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
Node* convertArrToDLL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* prev= head;
    for(int i= 1; i< arr.size(); i++){
        Node* temp= new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=prev->next; //or prev=temp
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

Node* reverseLL(Node* head){  //Optimal 2(Recursive)
    if(head==NULL||head->next==NULL) return head;
    Node* newHead= reverseLL(head->next);
    Node* front= head->next;
    front->next= head;
    head->next= NULL;
    return newHead;
}

//Brute : tc = O(3n)
// Node* add1(Node* head){
//     head= reverseLL(head);
//     Node* temp= head;
//     int carry= 1;
//     while(temp!=NULL){
//         temp->data= temp->data + carry;
//         if(temp->data < 10){
//             carry= 0;
//             break;
//         }
//         else{
//             temp->data= 0;
//             carry= 1;
//         }
//         if(temp->next==NULL && carry==1){
//             temp->next= new Node(1);
//             break;
//         }
//         temp= temp->next;
//     }
//     return reverseLL(head);
// }

//Optimal
int adder(Node* temp){
    if(temp==NULL){
        return 1;
    }
    int carry= adder(temp->next);
    temp->data += carry;
    if(temp->data < 10) return 0;
    return 1;
}

Node* add1(Node* head){
    int carry= adder(head);
    if(carry==1){
        Node* newNode= new Node(1);
        newNode->next= head;
        head= newNode;
    }
    return head;
}

int main(){   
    vector<int> arr= {9,9,9,8};
    Node* head= convertArrToDLL(arr);
    cout<<"Original LL: "<< endl;
    printLL(head);
    cout<< endl;

    head = add1(head);
    cout<<"LL after adding 1: "<< endl;
    printLL(head);
    cout<< endl;

    return 0;
}