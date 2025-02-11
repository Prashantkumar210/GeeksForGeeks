//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int>ans;
        
        vector<bool>nums(n, false);
        
        int twice;
        
        for(int i=0; i<n; i++){
            
            if(nums[arr[i]-1] == false) {
                nums[arr[i]-1] = true;
            }
            else{
                twice = arr[i];
            }
        }
         
        int missing = -1;
        
        for(int i=0; i<n; i++){
            if(nums[i] == false){
                missing = i+1;
                break;
            }
        }
        
        ans.push_back(twice);
        ans.push_back(missing);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends