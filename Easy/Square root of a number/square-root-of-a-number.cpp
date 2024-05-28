//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int start = 0;
        long long int end  = x;
        
        long long int mid = (end-start)/2 + start;
        
        long long int ans = -1;
        while(start<=end){
            
            if(mid*mid == x){
                
                return mid;
            }
            else if(mid*mid<x){
                
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            
            mid = (end-start)/2 +start;
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
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends