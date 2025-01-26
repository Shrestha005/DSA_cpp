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
// Node* loopStartingNode(Node* head){
//     map<Node*,int> mpp;
//     Node* temp= head;
//     while (temp!=NULL)
//     {
//         if(mpp.find(temp) != mpp.end()) return temp;
//         mpp[temp]= 1; //{temp,1}
//         temp= temp->next;
//     }
//     return NULL;
// }

//Optimal
Node* loopStartingNode(Node* head){
    Node* slow= head;
    Node* fast= head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow= slow->next;
        fast= fast->next->next;
        if(slow==fast){
            slow= head;
            while (slow!=fast)
            {
                slow= slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
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
    Node* loopStart= loopStartingNode(head);
    if (loopStart) {
        cout << "Loop starting node is "<<loopStart->data << endl;
    } else {
        cout << "No loop detected" << endl;
    }
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;
    return 0;
}