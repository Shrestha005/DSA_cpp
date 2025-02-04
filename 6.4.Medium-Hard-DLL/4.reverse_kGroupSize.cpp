#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};
Node* convertArrToDLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp; 
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
Node* reverseLL(Node *head)
{
   Node* temp = head;  
   Node* prev = NULL;  
   while(temp != NULL){  
       Node* front = temp->next;  
       temp->next = prev;  
       temp->back = front;
       prev = temp;  
       temp = front; 
   }
   return prev;  
}

//tc is O(2n)
Node* getKthNode(Node* temp, int k){
    while (temp!=NULL && k>1)
    {
        temp=temp->next;
        k--;
    }
    return temp;
}

Node* kReverse(Node* head, int k){
    Node* temp= head;
    Node* prevLast= NULL;
    while (temp!=NULL)
    {
        Node* kThNode= getKthNode(temp,k);
        if(kThNode == NULL){
            if(prevLast) prevLast->next= temp;
            break;
        }
        Node* nextNode= kThNode->next;
        kThNode->next= NULL;
        reverseLL(temp);
        if(temp==head) head= kThNode;
        else prevLast->next= kThNode;

        prevLast= temp;
        temp= nextNode;
    }
    return head;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);
    cout << "Original Linked List: ";
    printLL(head);
    head = kReverse(head, 4);

    cout << "Reversed Linked List: ";
    printLL(head);

    return 0;
}