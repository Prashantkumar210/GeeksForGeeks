//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> rowSum(vector<vector<int>>& mat) {
        
        if(mat.empty()) return {};
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int>ans(row, 0);
        
        for(int i=0; i<row; i++){
            
            int sum = 0;
            for(int j=0; j<col; j++){
                
                sum += mat[i][j];                
            }
            
            ans[i] = sum;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc-- > 0) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        }
        Solution sln;
        vector<int> ans = sln.rowSum(mat);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends