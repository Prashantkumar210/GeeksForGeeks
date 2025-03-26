//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        
        if(arr.size()==0) return arr[0];
        
        string ans = arr[0];
        
        for(int i=1; i<arr.size(); i++){
            
            string temp = arr[i];
            
            int n = 0;
            int m = 0;
            
            string str = "";
            
            while(ans[n]==temp[m] && (n<ans.length() && m<temp.length())){
                
                str += ans[n];    
                m++;
                n++;
            }
            
            if(str.size()<ans.size()) ans = str; 
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
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        string ans = ob.longestCommonPrefix(arr);
        if (ans.empty())
            cout << "\"\"";
        else
            cout << ans;
        cout << endl;
    }
}

// } Driver Code Ends