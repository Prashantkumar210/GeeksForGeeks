//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void segregateElements(vector<int>& arr) {
       
       if(arr.size()==1) return;
       
       vector<int>copy(arr.size(), 0);
       
       for(int i=0; i<arr.size(); i++){
           
           copy[i] = arr[i];
       }
    
       int i = 0;
       int j = 1;
       
       while(j<arr.size()){
           
           if(arr[i]>=0 && arr[j]>=0){
               i++;
               j++;
           }
           else if(arr[i]>=0 && arr[j]<0){
                i++;
                j++;
           }
           else if(arr[i]<0 && arr[j]>=0){
               swap(arr[i], arr[j]);
               i++;
               j++;
           }
           else{
               j++;
           }
       }
       
        for(int k=0; k<arr.size(); k++){
            if(copy[k]<0){
                arr[i] = copy[k];
                i++;
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << "\n~\n";
    }
}
// } Driver Code Ends