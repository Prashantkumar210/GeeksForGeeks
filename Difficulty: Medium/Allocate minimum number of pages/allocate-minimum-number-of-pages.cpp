//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    
    bool Issolution(int arr[], int n, int m, int mid){
        
        int count = 0;
        int currstude = 1;
        
        int pagesum = 0;
        
        for(int i=0; i<n; i++){
            
            if(arr[i]+pagesum<=mid){
                pagesum += arr[i];
            }
            else{
                
                ++currstude;
                if(currstude>m || arr[i]>mid){
                    return false;
                }
                pagesum = arr[i];
                
            }
        }
        
        return true;
    }
    
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        
        int ans = -1;
        
        if(m>n){
            return ans;
        }
        
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum +=arr[i];    
        }
        
        int start = 0;
        int end = sum;
        
       int mid = start + (end-start)/2;
        
        while(start<=end){
            
            if(Issolution(arr, n, m,mid)){
                
                end = mid-1;
                ans = mid;
            }
            else{
                start = mid+1;
            }
            
            mid = start +(end-start)/2;
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
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends