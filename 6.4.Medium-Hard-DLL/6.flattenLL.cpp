#include<bits/stdc++.h>
using namespace std;

//brute
class Node {
public:
    int data;
    Node *next;
    Node *child;

    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) :
                    data(x), next(nextNode), child(childNode) {}
};

Node* convertArrToLinkedList(vector<int>& arr){
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next; 
    }
    return head;
}


Node* flattenLinkedList(Node* head) {
    vector<int> arr;
    while (head != nullptr) {
        Node* t2 = head;
        while (t2 != nullptr) {
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        head = head->next;
    }

    sort(arr.begin(), arr.end());

    return convertArrToLinkedList(arr);
}
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void printOriginalLinkedList(Node* head, int depth) {
    while (head != nullptr) {
        cout << head->data;
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {
    Node* head = new Node(5);
    head->child = new Node(14); 
    head->next = new Node(10);
    head->next->child = new Node(4);
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);
    Node* flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}
                                
                            