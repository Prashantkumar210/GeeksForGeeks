//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  
    int find(string &s, int i, int j){
        
        int count = 0;
        
        while(i>=0 && j<s.length() && s[i]==s[j]){
            
            if(j-i>0){
                count++;
            }
            
            ++j;
            --i;
        }
        
        return count;
    }
  
    int countPS(string &s) {
        
        
        int count = 0;
        
        for(int i=0; i<s.length(); i++){
            
            
            int even = find(s, i, i);
            count = count+even;
            
            int odd = find(s, i, i+1);
            count = count+odd;
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends