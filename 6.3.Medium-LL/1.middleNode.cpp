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
// Node *findMiddle(Node *head) {
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }
//     Node* temp = head;
//     int count = 0;
//     while (temp != NULL) {
//         count++;
//         temp = temp->next;
//     }
//     int mid = count / 2 + 1;
//     temp = head;
//     while (temp != null) {
//         mid = mid - 1;
//         if (mid == 0) break;
//         temp = temp->next;
//     }
//     return temp;
// }

//Optimal(called Tortoise and Hare Algorithm)
//slow(+1) and fast(+2) ptr
//when fast is at the last node or has crossed the last node, the slow stands at mid. Return slow.
Node *findMiddle(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* slow= head;
    Node* fast= head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    Node* middleNode = findMiddle(head);
    cout << "The middle node value is: " << middleNode->data << endl;
    return 0;
}
     