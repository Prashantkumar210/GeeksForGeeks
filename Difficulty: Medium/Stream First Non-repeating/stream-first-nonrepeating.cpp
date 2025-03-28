//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        
        
        string ans = "";
        
        queue<char>q;
        
        int freq[26]= {0};
        
        for(int i=0; i<s.length(); i++){
            
            
            char ch = s[i];
            
            freq[ch-'a']++;
            
            q.push(ch);
            
            while(!q.empty()){
                
                if(freq[q.front()-'a']>1){
                    q.pop();
                }
                else{
                    ans.push_back(q.front());
                    break;
                }
            }
            
            if(q.empty()){
                ans.push_back('#');
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends