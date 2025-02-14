//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findIndex(vector<int>& arr, int key) {
        
        int first = -1;
        int second = -1;
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i]==key){
                
                if(first == -1) first = i;
                second = i;
            }
        }
        
        vector<int>ans;
        ans.push_back(first);
        ans.push_back(second);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> res;
        vector<int> arr;
        string s;
        getline(cin, s);
        stringstream ss(s);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int key;
        cin >> key;
        cin.ignore();
        Solution ob;
        res = ob.findIndex(arr, key);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << "\n";
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends