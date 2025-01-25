#include<bits/stdc++.h>
using namespace std;

//Brute
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node* back;
//     public:
//     Node(int data1, Node*next1, Node*back1){
//         data= data1;
//         next= next1;
//         back= back1;
//     }
//     Node(int data1){
//         data= data1;
//         next= nullptr;
//         back= nullptr;
//     }
// };
// Node* convertArrToDLL(vector<int> &arr){
//     Node* head= new Node(arr[0]);
//     Node* prev= head;
//     for(int i= 1; i< arr.size(); i++){
//         Node* temp= new Node(arr[i],nullptr,prev);
//         prev->next=temp;
//         prev=prev->next; //or prev=temp
//     }
//     return head;
// }
// void printLL(Node* head){
//     while (head!=NULL)
//     {
//         cout<< head->data<< " ";
//         head= head->next;
//     }
// }
// Node* reverseLL(Node* head){
//     if(head==NULL||head->next==NULL) return head;
//     Node* temp= head;
//     stack<int> st;
//     while (temp!=NULL)
//     {
//         st.push(temp->data);
//         temp= temp->next;
//     }
//     temp= head;
//     while (temp!=NULL)
//     {
//         temp->data= st.top();
//         st.pop();
//         temp= temp->next;
//     }
//     return head;
// }
// int main(){   
//     vector<int> arr= {1,2,3,4};
//     Node* head= convertArrToDLL(arr);
//     cout<<"original LL: "<< endl;
//     printLL(head);
//     cout<< endl;
//     head= reverseLL(head);
//     cout<<"reversed LL: "<< endl;
//     printLL(head);
//     return 0;
// }

//Optimal
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
Node* reverseLL(Node* head){
    if(head==NULL||head->next==NULL) return head;
    Node* prev= NULL; 
    Node* current= head;
    while (current!=NULL)
    {
        prev= current->back;
        current->back= current->next;
        current->next= prev;
        
        current= current->back;
    }    
    return prev->back;
}
int main(){   
    vector<int> arr= {1,2,3,4};
    Node* head= convertArrToDLL(arr);
    cout<<"original LL: "<< endl;
    printLL(head);
    cout<< endl;
    head= reverseLL(head);
    cout<<"reversed LL: "<< endl;
    printLL(head);
    return 0;
}
