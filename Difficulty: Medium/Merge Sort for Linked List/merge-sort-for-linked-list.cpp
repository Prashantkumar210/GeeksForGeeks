//{ Driver Code Starts
// Initial Template for C++
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

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    
    Node* find(Node* &head){
        
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* mergeList(Node* &left, Node* &right){
        
        if(!left && !right) return NULL;
        
        if(!left) return right;
        if(!right) return left;
        
        Node* head = NULL;
        Node* curr = head;
        
        while(left && right){
            
            if(left->data<=right->data){
                
                if(head==NULL){
                    head = left;
                    curr = head;
                    left = left->next;
                }
                else{
                    curr->next = left;
                    curr = left;
                    
                    left = left->next;
                }
            }
            else{
                if(head==NULL){
                    head = right;
                    curr = head;
                    right = right->next;
                }
                else{
                    curr->next = right;
                    curr = right;
                    
                    right = right->next;
                }
            }
        }
        
        if(left){
            curr->next = left;
        }
        else{
            curr->next = right;
        }
        
        return head;
    }
    
    Node* mergeSort(Node* head) {
    
        if(!head || !head->next) return head;
        
        Node* mid = find(head);
        
        Node* left = head;
        Node* right = mid->next;
        
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node* merge = mergeList(left, right);
        
        return merge;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends