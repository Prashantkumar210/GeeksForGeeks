//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    vector<pair<int, int>>st;
    
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        
        if(st.empty()){
            pair<int, int>p = make_pair(x, x);
            st.push_back(p);
        }
        else{
            pair<int, int>p;
            p.first = x;
            p.second = max(x, st.back().second);
            st.push_back(p);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        
        if(!st.empty()){
            st.pop_back();
        }
    }

    // Returns top element of the Stack
    int peek() {
        
        if(!st.empty()){
            
            return st.back().first;
        }
        else{
            return -1;
        }
    }

    // Finds minimum element of Stack
    int getMax() {
        if(!st.empty()){
            return st.back().second;
        }
        else{
            return -1;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMax() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends