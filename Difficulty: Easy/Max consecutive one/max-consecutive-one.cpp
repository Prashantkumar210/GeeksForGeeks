//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int maxConsecutiveCount(vector<int> &arr) {
        
        int zeroes = 1;
        int maxzero = 1;
        
        int ones = 1;
        int maxones = 1;
        
        
        for(int i=0; i<arr.size()-1; i++){
            
            if(arr[i]==arr[i+1] && arr[i]==1){
                ++ones;
                maxones = max(ones, maxones);
            }
            else{
                ones = 1;
            }
            
            if(arr[i]==arr[i+1] && arr[i]==0){
                ++zeroes;
                maxzero = max(zeroes, maxzero);
            }
            else{
                zeroes = 1;
            }
        }
        
        return max(maxzero, maxones);
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
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.maxConsecutiveCount(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends