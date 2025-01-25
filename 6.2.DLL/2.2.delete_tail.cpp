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

Node* removesTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* prev= head;
    while (prev->next->next != nullptr)
    {
        prev= prev->next;
    }
    delete(prev->next);
    prev->next=nullptr;
    return head;
}

int main(){   
    vector<int> arr= {2,5,8,7};
    Node* head= convertArrToDLL(arr);
    head= removesTail(head);
    printLL(head);
}