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

//Brute, tc is O(n^2) and sc is O(1)
// void findPair(Node* head, int sum){
//     vector<pair<int,int>> pairs;
//     Node* temp1= head;
//     while (temp1 != NULL)
//     {
//         Node* temp2= temp1->next;
//         while (temp2 != NULL)
//         {
//             if(temp1->data + temp2->data == sum){
//                 pairs.push_back({temp1->data , temp2->data});
//             }
//             temp2= temp2->next;
//         }
//         temp1= temp1->next;
//     }
//     if(pairs.empty()){
//         cout << "no pairs found." << endl;
//     }
//     else{
//         cout << "pairs with sum " << sum << ": ";
//         for(auto it: pairs){
//             cout << "(" << it.first << "," << it.second << ") ";
//         }
//         cout << endl;
//     }
// }
// int main(){   
//     vector<int> arr= {5,2,1,4,10,3};
//     Node* head= convertArrToDLL(arr);
//     // printLL(head);
//     findPair(head,5);
//     return 0;
// }

//Optimal, tc is O(2n) 
Node* findTail(Node* head){
    if(!head) return nullptr;
    Node* tail= head;
    while(tail->next != NULL) tail=tail->next;
    return tail;
}
vector<pair<int,int>> findPair(Node* head, int sum){
    vector<pair<int,int>> pairs;

    if (!head) return pairs;

    Node* left= head;
    Node* right= findTail(head);

    while (left != NULL && right != NULL && left != right && left->back != right)
    {
        int currSum= left->data + right->data;
        if(currSum == sum){
            pairs.push_back({left->data,right->data});
            left= left->next;
            right= right->back;
        }
        else if(currSum < sum) left=left->next;
        else right=right->back;
    }
    return pairs;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 10};
    Node* head = convertArrToDLL(arr);

    vector<pair<int, int>> result = findPair(head, 5);

    if (result.empty()) {
        cout << "No pairs found." << endl;
    } else {
        cout << "Pairs with sum 5: ";
        for (auto p : result) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    return 0;
}