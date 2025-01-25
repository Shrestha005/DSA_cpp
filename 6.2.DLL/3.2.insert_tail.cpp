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

Node* insertsTail(Node* head, int val){

    if(head==NULL){
        return new Node(val,nullptr,nullptr);
    }
    Node* temp= head;
    while (temp->next != NULL) temp= temp->next;
    Node* newTail= new Node(val, nullptr, temp);
    temp->next= newTail;
    return head;
}

Node* insertsHead(Node* head, int val){
    Node* newHead= new Node(val, head, nullptr);
    head->back= newHead;
    return newHead;
}

Node* insertsBeforeTail(Node* head, int val){
    if(head->next==NULL){
        return insertsHead(head, val);
    }
    Node* tail= head;
    while (tail->next!=NULL)
    {
        tail=tail->next;
    }
    Node* prev= tail->back;
    Node* newNode= new Node(val,tail,prev);
    prev->next= newNode;
    tail->back= newNode;
    return head;
}

int main(){   
    vector<int> arr= {2,5,8,7};
    Node* head= convertArrToDLL(arr);
    head= insertsTail(head,100);
    printLL(head);

    cout<< "\n";

    vector<int> arr1= {2,5,8,7};
    Node* head1= convertArrToDLL(arr1);
    head= insertsBeforeTail(head1,100);
    printLL(head);
}