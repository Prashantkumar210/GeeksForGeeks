//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the difference between the maximum and minimum frequency of
    // elements.
    int findDiff(vector<int>& arr) {
        
        unordered_map<int,int>mp;
        
        int low = arr.size();
      
        
        int high = 0;
       
        
        for(int i=0; i<arr.size(); i++){
            
            mp[arr[i]]++;
        }
        
        for(int i=0; i<arr.size(); i++){
            
          
            if(low>mp[arr[i]]){
                low = mp[arr[i]];
                
            } 
            if(high<mp[arr[i]]){
                high = mp[arr[i]];
            }
        }
        
        return high - low;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findDiff(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends