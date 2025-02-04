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

//Brute(map-hashing)
// Node *intersectionInYLL(Node *head1, Node *head2) {
//     map<Node*,int> mpp;
//     Node* temp= head1;
//     while(temp!=NULL){
//         mpp[temp]=1;
//         temp=temp->next;
//     }
//     temp= head2;
//     while(temp!=NULL){
//         if(mpp.find(temp) != mpp.end()) return temp;
//         temp=temp->next;
//     }
//     return NULL;
// }

//Better(difference in length)
// int difference(Node* head1, Node* head2){
//     int len1=0, len2=0;
//     while(head1!=NULL || head2!=NULL){
//         if(head1!=NULL){
//             len1++;
//             head1= head1->next;
//         }
//         if(head2!=NULL){
//             len2++;
//             head2= head2->next;
//         }
//     }
//     return len1-len2;
// }
// Node *intersectionInYLL(Node *head1, Node *head2) {
//     int diff= difference(head1,head2);
//     if(diff<0){
//         while(diff++ != 0) head2=head2->next;
//     }
//     else while(diff-- != 0) head1=head1->next;
//     while(head1 != NULL){
//         if(head1==head2) return head1;
//         head1= head1->next;
//         head2= head2->next;
//     }
//     return NULL;
// }

//Optimal (tc is O(n+m), sc is O(1))
Node *intersectionInYLL(Node *head1, Node *head2) {
    Node* temp1= head1;
    Node* temp2= head2;
    while (temp1!=temp2)
    {
        temp1= (temp1==NULL) ? head2 : temp1->next;
        temp2= (temp2==NULL) ? head1 : temp2->next;
    }
    return temp1;
}


int main() {
    //first LL
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    //second LL
    Node* head2 = new Node(9);
    head2->next = new Node(8);

    head2->next->next = head1->next->next; // Intersection

    Node* intersection = intersectionInYLL(head1, head2);

    // Output the result
    if (intersection != nullptr) {
        cout << "Intersection at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection found" << endl;
    }

    return 0;
}