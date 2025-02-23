//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> colSum(vector<vector<int>>& mat) {
      
        if (mat.empty()) return {};

        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<int> ans(cols, 0);

        for (int j = 0; j < cols; j++){
            for (int i = 0; i < rows; i++){
                ans[j] += mat[i][j]; 
            }
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
        vector<int> ans = sln.colSum(mat);
        for (int i = 0; i < m; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends