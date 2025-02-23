//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
       
       
       for(int i=0; i<arr.size()-1; i++){
           
           if(arr[i]==arr[i+1]) return arr[i];
       }
       
       return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr;
        for (int i = 0; i < 10; i++) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        Solution obj;
        int ans = obj.findDuplicate(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends