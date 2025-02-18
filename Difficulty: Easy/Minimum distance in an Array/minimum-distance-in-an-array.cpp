//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minDist(vector<int>& arr, int x, int y) {
        
        int diff = INT_MAX;
        
        int first = -1;
        int second = -1;
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i]==x){
                first = i;
            }
            if(arr[i]==y){
                second = i;
            }
            
            if(first!=-1 && second!=-1){
                
                if(abs(first-second)<diff) diff = abs(first-second);
            }
        }
        
        if(first==-1 || second==-1) return -1;
        
        return diff;
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
        int x, y;
        cin >> x >> y;
        cin.ignore();
        Solution obj;
        cout << obj.minDist(arr, x, y) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends