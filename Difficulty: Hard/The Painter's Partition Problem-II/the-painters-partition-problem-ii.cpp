//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    bool is_possible(vector<int>&arr, int mid, int k){
        
        int sum = 0;
        int count = 1;
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i]>mid) return false;
            
            if(arr[i] + sum > mid){
                
                sum = arr[i];
                count++;
                
                if(count>k){
                    return false;
                }
            }
            else{
                sum += arr[i]; 
            }
        }
        return true;
    }
  
    int minTime(vector<int>& arr, int k) {
        
        
       
        
        int ans = -1;
        
        int s = 0;
        int e = accumulate(arr.begin(), arr.end(), 0);
        
        while(s<=e){
            
            int mid = s + (e-s)/2;
            
            if(is_possible(arr, mid, k)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends