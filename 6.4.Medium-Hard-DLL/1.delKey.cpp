#include<bits/stdc++.h>
using namespace std;

// tc is O(n) and sc is O(1)

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

Node* deleteKey(Node* head, int key){
    Node* temp= head;

    while (temp!=NULL)
    {
        if(temp->data == key){ //equal to key
            Node* nextNode= temp->next;
            Node* prevNode= temp->back;

            if(temp == head){
                head= nextNode;
                if(head) head->back= nullptr;
            }

            if(nextNode) nextNode->back= prevNode;
            if(prevNode) prevNode->next= nextNode;

            delete(temp);
            temp= nextNode;
        }
        else{ //not equal to key
            temp= temp->next;
        }
    }
    return head;
}

int main(){   
    vector<int> arr= {5,10,2,4,10};
    Node* head= convertArrToDLL(arr);
    head= deleteKey(head,10);
    printLL(head);
}