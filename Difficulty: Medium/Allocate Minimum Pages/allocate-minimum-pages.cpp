//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool is_possible(vector<int>&arr, int mid, int k){
        
        int sum = 0;
        int stud_count = 1;
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i]>mid) return false;
            
            if(arr[i]+sum>mid){
                
                sum = arr[i];
                stud_count++;
                
                if(stud_count>k) return false;
            }
            else{
                sum += arr[i]; 
            }
        }
        
        return true;
    }
  
    int findPages(vector<int> &arr, int k) {
        
        if(arr.size()<k) return -1;
        
        int s = 0;
        int e = accumulate(arr.begin(), arr.end(), 0);
        
        int ans = -1;
        
        while(s<=e){
            
            int mid = s + (e-s)/2;
            
            if(is_possible(arr, mid, k)){
                e = mid - 1;
                ans = mid;
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
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends