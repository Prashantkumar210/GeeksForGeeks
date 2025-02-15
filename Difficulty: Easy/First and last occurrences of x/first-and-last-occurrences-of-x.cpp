//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> firstAndLast(int x, vector<int> &arr) {
        
        int i = 0;
        int j = arr.size()-1;
        
        vector<int>ans;
        
        while(i<=j){
            
            if(arr[i]!=x) i++;
            if(arr[j]!=x) j--;
            
            if(arr[i]==x && arr[j]==x){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
        
        ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> ans = obj.firstAndLast(x, arr);
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends