//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        
        int ans = -1;
        
        for(int i=0; i<mat.size(); i++){
            
            bool check = true;
            
            // he not know anyone 
            for(int j=0; j<mat[0].size(); j++){
               
               if(mat[i][j]==1){
                   
                   if(i==j) continue;
                   else check = false;
               } 
            }
            
            // everyOne khoe him
            
            if(check==true){
                for(int j=0; j<mat[0].size(); j++){
                    
                    if(mat[j][i]==1) continue;
                    else check = false;
                }
                
                if(check == true) return i;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends