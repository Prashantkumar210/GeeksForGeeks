//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        
        int lar = 0;
        
        for(int i=0; i<arr.size(); i++){
            
            if(lar<arr[i]){
                lar = arr[i];
            }
        }
        
        int seconlar = -1;
        
        for(int i=0; i<arr.size(); i++){
            
            if(seconlar<arr[i] && arr[i]<lar){
                seconlar = arr[i];
            }
        }
        
        return seconlar;
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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends