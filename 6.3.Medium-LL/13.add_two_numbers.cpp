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
Node* addTwoNumbers(Node* head1, Node* head2){
    Node* temp1= head1;
    Node* temp2= head2;
    Node* dummy= new Node(-1);
    Node* current= dummy;
    int carry= 0;
    while((temp1!=NULL || temp2!=NULL) || carry){
        int sum= carry;
        if(temp1) sum+= temp1->data;
        if(temp2) sum+= temp2->data;
        Node* newNode= new Node(sum%10);
        carry= sum/10;
        current->next= newNode;
        current= current->next;

        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next;
    }
    if(carry){
        Node* newN= new Node(carry);
        current->next= newN;
    }
    return dummy->next; //head
}

int main(){   
    vector<int> arr1= {5,0,0,1};
    vector<int> arr2= {5,5,5,0};
    Node* head1= convertArrToDLL(arr1);
    Node* head2= convertArrToDLL(arr2);

    Node* head = addTwoNumbers(head1, head2);
    cout<<"LL after addition: "<< endl;
    printLL(head);
    cout<< endl;

    return 0;
}