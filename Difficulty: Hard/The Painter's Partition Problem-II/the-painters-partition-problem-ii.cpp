//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    
    bool Issolution(int arr[], int n , int k , long long mid){
        
        long long timesum = 0;
        int count = 1;
        
        for(int i=0; i<n; i++){
            
            if(arr[i]+timesum<=mid){
                timesum += arr[i];
            }
            else{
                ++count;
                if(arr[i]>mid || count>k){
                    return false;
                }
                
                timesum = arr[i];
            }
        }
        
        return true;
    }
    
  
    long long minTime(int arr[], int n, int k)
    {   
        
        long long ans = -1;
        
        long long start = 0;
        long long sum = 0;
        
        for(int i=0; i<n; i++){
            sum +=arr[i]; 
        }
        
        long long end = sum;
        
        int mid = start +(end-start)/2;
        
        while(start<=end){
            
            if(Issolution(arr, n, k, mid)){
                
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            
            mid = start + (end-start)/2;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends