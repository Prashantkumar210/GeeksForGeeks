//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        
        int carry = 0;
        
        for(int i=N-1; i>=0; i--){
                
            if(i==N-1){
                int sum = arr[i]+1;
                carry = sum/10;
                arr[i] = sum%10;
                if(carry == 0) return arr;
            }
            else{
                int sum = arr[i] + carry;
                carry = sum /10;
                arr[i] = sum %10;
            
                if(carry ==0) return arr;    
            }
        }
        
        arr.insert(arr.begin(), carry);
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends