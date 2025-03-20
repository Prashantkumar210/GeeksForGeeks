//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {

        unordered_map<int, int>mp;
        
        for(int i=0; i<arr.size(); i++){
            
            mp[arr[i]]++;
        }
        
        int n = arr.size()/2;
        
        int ans = -1;
        
        for(auto it=mp.begin(); it!=mp.end(); ++it){
            
            if(it->second>n){
                ans = it->first;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends