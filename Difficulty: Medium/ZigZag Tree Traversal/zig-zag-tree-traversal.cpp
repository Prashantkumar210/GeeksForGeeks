//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    
     void find(Node* root, vector<int>&ans, int count){

        if(!root) return;

        queue<Node*>Q;
        Q.push(root);
        Q.push(NULL);

        vector<int>path;

        while(!Q.empty()){
            
            Node* temp = Q.front();
            Q.pop();

            if(!temp){
                if(count%2!=0){
                    for(int i=path.size()-1; i>=0; i--){
                        ans.push_back(path[i]);
                    }   
                }
                else{
                     for(int i=0; i<path.size(); i++){
                        ans.push_back(path[i]);
                    }   
                }
                
                ++count;
                path.clear();

                if(!Q.empty()) Q.push(NULL);
            }
            else{
                path.push_back(temp->data);

                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);
            }
        }

    }
    
    vector <int> zigZagTraversal(Node* root)
    {
    	  
    	vector<int>ans;
    	 
    	find(root, ans, 0);
    	
    	return ans;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends