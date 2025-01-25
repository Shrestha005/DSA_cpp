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

Node* insertsHead(Node* head, int val){
    Node* newHead= new Node(val, head, nullptr);
    head->back= newHead;
    return newHead;
}

Node* insertsKthNode(Node* head, int k, int val){
    if(k==1) return insertsHead(head, val);
    Node* temp= head;
    int cnt=0;
    while (temp!=NULL)
    {
        cnt++;
        if(cnt==k) break;
        temp= temp->next;
    }
    Node* prev= temp->back;
    Node* newNode= new Node(val,temp,prev);
    prev->next= newNode;
    temp->back= newNode;
    return head;
}

int main(){   
    vector<int> arr= {2,5,8,7};
    Node* head= convertArrToDLL(arr);
    head= insertsKthNode(head,2,100);
    printLL(head);
}