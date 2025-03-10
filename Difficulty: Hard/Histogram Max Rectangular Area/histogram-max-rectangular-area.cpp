//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    vector<int> prevSmaller(vector<int>& input) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());
        
        for(int i=0; i<input.size(); i++) {
            int curr = input[i];

            while(s.top() != -1 && input[s.top()] >= curr){
                s.pop();
            }
                
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int> &input) {
        stack<int> s;
        s.push(-1);
  
        vector<int> ans(input.size());

        for(int i=input.size()-1; i>=0; i--) {
            int curr = input[i];

         
            while(s.top() != -1 && input[s.top()] >= curr) {
                  s.pop();
            }
            
            ans[i] = s.top();
            s.push(i);
        }
        
        return ans;
    }

    int find(vector<int> &height) {
        
        vector<int> prev = prevSmaller(height);

        
        vector<int> next = nextSmaller(height);

        int maxArea = INT_MIN;
        int size = height.size();

        for(int i=0; i<height.size(); i++) {
                int length = height[i];
                
                if(next[i] == -1) {
                        next[i] = size;
                }

                int width = next[i] - prev[i] - 1;

                int area = length * width;
                maxArea = max(maxArea, area);
        }

        return maxArea;
    }
  
    int getMaxArea(vector<int> &arr) {
        
        return find(arr);
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends