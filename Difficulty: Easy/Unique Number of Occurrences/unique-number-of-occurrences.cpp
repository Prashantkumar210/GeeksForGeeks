//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int, int>mp;
        
        for(int i=0; i<n; i++){
            
            mp[arr[i]]++;
        }
        
        unordered_map<int, int>freq;
        
        for(auto it=mp.begin(); it!=mp.end(); ++it){
            freq[it->second]++;
        }
        
        for(auto it=freq.begin(); it!=freq.end(); ++it){
            
            if(it->second>1) return false;
        }
        
        return true;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends