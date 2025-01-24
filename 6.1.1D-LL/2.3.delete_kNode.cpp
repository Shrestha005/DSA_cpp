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

Node* removeskTh(Node* head, int k){
    if(head==NULL) return NULL;
    if(k==1){
        Node* temp= head;
        head= head->next;
        delete(temp);
        return head;
    }
    int cnt= 0;
    Node* temp= head;
    Node* prev= NULL;
    while (temp!=NULL)
    {
        cnt++;
        if(cnt==k){
            prev->next= prev->next->next;
            delete(temp);
            break;
        }
        prev= temp;
        temp= temp->next;
    }
    return head;
}
int main(){
    vector<int> arr= {12,5,8,7};
    Node* head= convertArrToLL(arr);
    head= removeskTh(head,3);
    printLL(head);
}