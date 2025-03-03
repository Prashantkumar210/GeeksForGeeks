//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        
        
        Node* prev1 = NULL;
        Node* curr = num1;
        
        while(curr!=NULL){
            
            Node* forward = curr->next;
            curr->next = NULL;
            
            curr->next = prev1;
            
            prev1 = curr;
            curr= forward;
        }
        
        Node* prev2 = NULL;
        curr = num2;
        while(curr!=NULL){
            
            Node* forward = curr->next;
            curr->next = NULL;
            
            curr->next = prev2;
            
            prev2 = curr;
            curr= forward;
        }
        
        
        Node* head = NULL;
        Node* temp = head;
        
        int num = 0;
        
        while(prev1!=NULL && prev2!=NULL){
            
            int val1 = prev1->data;
            int val2 = prev2->data;
            
            int sum = val1 + val2 + num;
            
            int digit = sum%10;
            
            num = sum /10;
            
            Node* newNode = new Node(digit);
            
            if(head==NULL){
                head = newNode;
                temp = head;
            }
            else{
                temp->next = newNode;
                temp = newNode;
            }
            
            prev1 = prev1->next;
            prev2 = prev2->next;
        }
        
        while(prev1!=NULL){
            
            int val = prev1->data;
            
            int sum = num +val;
            
            int digit = sum %10;
            
            num = sum / 10;
            
            Node* newNode = new Node(digit);
            
            if(head==NULL){
                head = newNode;
                temp = head;
            }
            else{
                temp->next = newNode;
                temp = newNode;
            }
            
            prev1 = prev1->next;
        }
        
        while(prev2!=NULL){
            
            int val = prev2->data;
            
            int sum = num +val;
            
            int digit = sum %10;
            
            num = sum / 10;
            
            Node* newNode = new Node(digit);
            
            if(head==NULL){
                head = newNode;
                temp = head;
            }
            else{
                temp->next = newNode;
                temp = newNode;
            }
            
            prev2 = prev2->next;
        }
        
        if(num>0){
            
            Node* NewNode = new Node(num);
            temp->next = NewNode;
            num = 0;
        }
        
        
        
        Node* prev = NULL;
        curr = head;
        
        while(curr!=NULL){
            
            Node* forward = curr->next;
            curr->next = NULL;
            
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        if(prev==NULL) return prev;
        
        Node* New = prev;
        
        Node* forward = prev->next;
        
        while(New!=NULL){
            
            if(New->data==0){
                
                New->next = NULL;
                delete New;
                New = forward;
                forward = forward->next;
            }
            else{
                break;
            }
        }
        
        return New;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends