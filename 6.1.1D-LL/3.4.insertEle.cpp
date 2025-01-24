#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;         
    Node* next;       
    Node(int data1, Node* next1) {
        data= data1;
        next= next1;
    }
    Node(int data1){
        data= data1;
        next= nullptr;
    }
};

void printLL(Node* head){
    while (head!=NULL)
    {
        cout<< head->data<< " ";
        head= head->next;
    }
    cout<< endl;
}

Node* convertArrToLL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* mover= head;
    for(int i= 1; i< arr.size(); i++){
        Node* temp= new Node(arr[i]);
        mover->next= temp;
        mover= temp;
    }
    return head;
}

Node* insertsBeforeValue(Node* head, int ele, int val){
    if(head==NULL){
        return NULL;
    }
    if(head->data==val){
        return new Node(ele,head);

    }
    Node* temp= head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            Node* newNode= new Node(ele,temp->next);
            temp->next= newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int> arr= {12,5,8,7};
    Node* head= convertArrToLL(arr);
    head= insertsBeforeValue(head,100,7);
    printLL(head);
}