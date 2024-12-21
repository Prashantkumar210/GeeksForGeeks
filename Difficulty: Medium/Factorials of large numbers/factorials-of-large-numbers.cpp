//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> factorial(int n) {
        
        vector<int>ans;
        
        ans.push_back(1);
        
        for(int i=n; i>=1; i--){
            
            int len = 0;
            int carry = 0;
            
            while(len<ans.size()){
                
                int val = ans[len]*i + carry;
                
                int digit = val % 10;
                
                carry = val / 10;
                
                
                ans[len] = digit;
                len++;
                
            }
            
             while (carry > 0) {
                ans.push_back(carry % 10);
                carry /= 10;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends