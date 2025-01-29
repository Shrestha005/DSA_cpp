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

//Brute
// int loopLen(Node* head){
//     map<Node*,int> mpp;
//     Node* temp= head;
//     int length= 0;
//     while (temp!=NULL){
//         if(mpp.find(temp) != mpp.end()){
//             int loopLength= length-mpp[temp];
//             return loopLength;
//         } 
//     mpp[temp]= length;
//     temp= temp->next;
//     length++;
//     }
//     return 0;
// }

//Optimal
int loopLen(Node* head){
    Node* slow= head;
    Node* fast= head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow= slow->next;
        fast= fast->next->next;
        if(slow==fast){
            int length= 1;
            Node* current= slow;
            while (current->next != slow)
            {
                current= current->next;
                length++;
            }
            return length;
        }   
    }
    return 0;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; 
    
    int loopLength = loopLen(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }
    return 0;
}