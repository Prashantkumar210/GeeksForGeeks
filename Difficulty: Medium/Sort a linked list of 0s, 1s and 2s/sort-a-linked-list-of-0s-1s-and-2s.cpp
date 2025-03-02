//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        
        
        Node* temp = head;
        int zeroes = 0;
        int ones = 0;
        int twos = 0;
        
        
        while(temp!=NULL){
            
            int num = temp->data;
            
            if(num == 0) zeroes++;
            else if(num == 1) ones++;
            else twos++;
            
            temp = temp->next;
        }
        
      
        Node* temp2  = new Node(5);
        head = temp2;
        
        while(zeroes>0){
            
            Node* newNode = new Node(0);
            
            temp2->next = newNode;
            temp2 = newNode;
            --zeroes;
        }
        
        while(ones>0){
            
            Node* newNode = new Node(1);
            
            temp2->next = newNode;
            temp2 = newNode;
            --ones;
        }
        
         while(twos>0){
            
            Node* newNode = new Node(2);
            
            temp2->next = newNode;
            temp2 = newNode;
            --twos;
        }
        
        Node* cret = head->next;
        head->next = NULL;
        delete head;
        head = cret;
        return head;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends