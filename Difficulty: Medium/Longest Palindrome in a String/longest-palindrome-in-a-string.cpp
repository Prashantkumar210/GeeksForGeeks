//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    string find(int i, int j, string s){
        
        while(i>=0 && j<s.length() && s[i]==s[j]){
            
            i--;
            j++;
        }
        
        return s.substr(i+1, j-1-i);
    }
  
    string longestPalindrome(string s) {
        
        string evenstr = "";        
        string oddstr = "";

        
        for(int i=0; i<s.length(); i++){
            
            string even = find(i, i, s);
            
            if(even.length()>evenstr.length()) evenstr = even;
            
            string odd = find(i, i+1, s);
            
            if(odd.length()>oddstr.length()) oddstr = odd;
        }
        
        if(oddstr.length()<evenstr.length()) return evenstr;
        
        return oddstr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends