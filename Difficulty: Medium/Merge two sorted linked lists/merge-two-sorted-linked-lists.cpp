//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}


// } Driver Code Ends

/* Link list Node
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
    Node* sortedMerge(Node* head1, Node* head2) {
        
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        
        // for New Sort List
        Node* head = NULL;
        Node* curr = head;
        
        
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while(temp1!=NULL && temp2!=NULL){
            
            if(temp1->data<=temp2->data){
                
                Node* forward = temp1->next;
                
                temp1->next = NULL;
                
                if(head==NULL){
                    head = temp1;
                    curr = head;
                }
                else{
                    curr->next = temp1;
                    curr = curr->next;
                }
                
                temp1 = forward;
            }
            else{
                Node* forward = temp2->next;
                
                temp2->next = NULL;
                
                if(head==NULL){
                    head = temp2;
                    curr = head;
                }
                else{
                    curr->next = temp2;
                    curr = curr->next;
                }
                
                temp2 = forward;
            }
        }
        
        while(temp1!=NULL){
            
            Node* forward = temp1->next;
                
                temp1->next = NULL;

                curr->next = temp1;
                curr = curr->next;
                
                temp1 = forward;
        }
        
        while(temp2!=NULL){
            
            Node* forward = temp2->next;
                
                temp2->next = NULL;

                curr->next = temp2;
                curr = curr->next;
                
                temp2 = forward;
        }
        
        return head;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends