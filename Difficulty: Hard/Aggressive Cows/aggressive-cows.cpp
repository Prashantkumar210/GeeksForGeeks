//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    bool Issolution(int n, int k, vector<int> &stalls, int mid){
        
        int count = 1;
        int lastpos = stalls[0];
        
        
        
        for(int i=0; i<n; i++){
            
            if(stalls[i]-lastpos>=mid){
                
                count++;
                if(count==k){
                    return true;
                }
                
                lastpos = stalls[i];
            }
        }
        
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        
        sort(stalls.begin(), stalls.end());
        
        int end = -1;
        
        for(int i=0; i<n; i++){
            
            if(end<=stalls[i]){
                end = stalls[i];
            }    
        }
        
        int start = 0;
        int mid = start + (end-start)/2;
        
        int ans = 1;
        
        while(start<=end){
            
            if(Issolution(n, k, stalls, mid)){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            
            mid = start +(end-start)/2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends