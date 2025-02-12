//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        
        if(arr.size()<3) return -1;
        
        int thirdlar = INT_MIN;
        int index = -1;
        
        for(int i=0; i<arr.size(); i++){
            if(thirdlar<arr[i]){
                thirdlar = arr[i];
                index = i;
            }
        }
        
        arr[index] = -1;
        
        thirdlar = INT_MIN;
        index = -1;
        
        for(int i=0; i<arr.size(); i++){
            if(thirdlar<arr[i]){
                 thirdlar = arr[i];
                 index = i;
            }
        }
        
        arr[index] = -1;
        
        thirdlar = INT_MIN;
        
        for(int i=0; i<arr.size(); i++){
            if(thirdlar<arr[i]) thirdlar = arr[i];
        }
        
        return thirdlar;
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
        cout << ob.thirdLargest(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends