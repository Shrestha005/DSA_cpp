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

Node* insertskTH(Node* head, int val, int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new Node(val,head);

    }
    int cnt= 0;
    Node* temp= head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* newNode= new Node(val,temp->next);
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
    head= insertskTH(head,100,3);
    printLL(head);
}