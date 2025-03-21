//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int maxProduct(vector<int> arr) {
        
        int firstmax = INT_MIN;
        int secondmax = INT_MIN;
        int thirdmax = INT_MIN;
        
        int firstmin = INT_MAX;
        int secondmin = INT_MAX;
        
        
        for(int i=0; i<arr.size(); i++){
            
            // for first max
            if(arr[i]>=firstmax){
                thirdmax = secondmax;
                secondmax = firstmax;
                firstmax = arr[i];
            }
            // for second max
            else if(arr[i]>=secondmax){
                thirdmax = secondmax;
                secondmax = arr[i];
            }
            // for thirdmax 
            
            else if(arr[i]>=thirdmax){
                thirdmax = arr[i];
            }
            
            if(firstmin>arr[i]){
                secondmin = firstmin;
                firstmin = arr[i];
            }
            else if(secondmin>arr[i]){
                secondmin = arr[i];
            }
        }
        
        return max(firstmax*secondmax*thirdmax, firstmin*secondmin*firstmax);
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends