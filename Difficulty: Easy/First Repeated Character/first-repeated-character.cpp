//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string firstRepChar(string s) {
        
        vector<bool>nums(26, false);
        
        string ans = "-1";
        
        for(int i=0; i<s.length(); i++){
            int index = s[i]-'a';
            if(nums[index] == true){
                ans = s[i];
                return ans;
            }
            else{
                nums[index] = true;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
//    Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.firstRepChar(str) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends