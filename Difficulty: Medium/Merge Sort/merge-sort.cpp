//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void merge(vector<int>&arr, int l, int r){
        
        int mid = (l + r)/2;
        
        int len1 = mid-l+1;
        int len2 = r-mid;
        
       
        vector<int>left(len1,0);
        vector<int>right(len2,0);
        
        int k = l;
        
        for(int i=0; i<len1; i++){
            left[i] = arr[k];
            ++k; 
        }
        
        k = mid + 1;
        
        for(int i=0; i<len2; i++){
            right[i] = arr[k];
            ++k;
        }
        
        int leftIndex = 0;
        int rightIndex = 0;

        int mainIndexArray = l; 
        
        while(leftIndex<len1 && rightIndex<len2){

            if(left[leftIndex]<right[rightIndex]){
                arr[mainIndexArray++] = left[leftIndex++];  
            }
            else{
                arr[mainIndexArray++] = right[rightIndex++];
            }
        }
        
        while(leftIndex<len1){
            arr[mainIndexArray++] = left[leftIndex++];
        }
    
        while(rightIndex<len2){
            arr[mainIndexArray++] = right[rightIndex++];
        }
        
    }
    
    void merge_Sort(vector<int>&arr, int l, int r){
        
        if(l>=r) return;
        
        int mid = (l + r)/2;
        
        // Left side
        merge_Sort(arr, l, mid);
        
        // Right side
        merge_Sort(arr, mid+1, r);
        
        // merging arrays
        merge(arr, l, r);
    }
  
    void mergeSort(vector<int>& arr, int l, int r) {
        
        merge_Sort(arr, l, r);
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
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends