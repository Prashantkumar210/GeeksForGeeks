//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
       vector<int>ans;
       
       int stcol = 0;
       int encol = c-1;
       int strow = 0;
       int enrow = r-1;
       
       
       int count = 0;
       int total = r*c;
       
       
       while(count < total){
           
        //   for starting row
           for(int i=stcol; i<=encol && count<total; i++){
               
               ans.push_back(matrix[strow][i]);
               count++;
           }
           strow++;
           
           
        //   for ending col
           for(int i=strow; i<=enrow && count<total; i++){
               
               ans.push_back(matrix[i][encol]);
               count++;
           }
           encol--;
           
        //   for ending row
            for(int i=encol; i>=stcol && count<total; i--){
                ans.push_back(matrix[enrow][i]);
                count++;
            }
            enrow--;
            
        //  for starting col
            for(int i=enrow; i>=strow  && count<total; i--){
                ans.push_back(matrix[i][stcol]);
                count++;
            }
            stcol++;
            
       }
       
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends