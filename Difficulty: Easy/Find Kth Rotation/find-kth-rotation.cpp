//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        
        if(arr[0]<arr[arr.size()-1]) return 0;
        
        int s = 0;
        int e = arr.size()-1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid-1]>arr[mid]){
                
                return mid;
            }
            if(arr[mid]>arr[mid+1]){
                return mid+1;
            }
            
            if(arr[mid]<arr[e]) e = mid -1;
            else s = mid +1;
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends