//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        
        
        queue<int>q;
        
        for(int i=0; i<k; i++){
            
            if(arr[i]<0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        
        for(int i=k; i<arr.size(); i++){
            
            if(!q.empty()){
                
                ans.push_back(arr[q.front()]);
            }
            else{
                ans.push_back(0);
            }
            
            while(!q.empty() && (i-q.front()>=k)){
                    q.pop();
            }
            
            if(arr[i]<0){
                q.push(i);
            }
        }
        
        if(q.size()>0){
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.firstNegInt(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends