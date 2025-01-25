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
// int lengthOfLL(Node* head){
//     Node* temp= head;
//     int cnt=0;
//     while (temp!=NULL)
//     {
//         temp= temp->next;
//         cnt++;
//     }
//     return cnt;
// }
int checkIfPresent(Node* head, int val){
    Node* temp= head;
    while (temp!=NULL)
    {
        if(temp->data==val) return 1;
        temp= temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr= {12,5,8,7};
    Node* head= convertArrToLL(arr);
    cout<< checkIfPresent(head,5)<< endl;
}