//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int transitionPoint(vector<int>& arr) {
        
        bool zero = false;
        bool ones = false;
        
        int s= 0;
        int e = arr.size()-1;
        
        int index = -1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(arr[mid]==0){
                zero = true;
                s = mid +1;
            }
            else{
                ones = true;
                index = mid;
                e = mid -1;
            }
        }
        
        if(index!=-1) return index;
        
        if(zero==false) return 0;
        
        return -1;
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
        cout << ob.transitionPoint(arr) << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends