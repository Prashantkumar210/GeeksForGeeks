//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    
    void merge(vector<int>&arr, int s, int end, int &count){
        
        int mid = (s + end)/2;
        
        // Store code
        
        int len1 = mid-s+1;
        int len2 = end-mid;
        
        vector<int>left(len1,0);
        vector<int>right(len2, 0);
        
        int temp = s;
        
        for(int i=0; i<left.size(); i++){
            left[i] = arr[temp];
            temp++;
        }
        
        temp = mid+1;
        
        for(int i=0; i<right.size(); i++){
            right[i] = arr[temp];
            temp++;
        }
        
        // Merge code 
        
        int leftindex = 0;
        int rightindex = 0;
        
        int mainindex = s;
        
        while(leftindex<len1 && rightindex<len2){
            
            if(left[leftindex]>right[rightindex]){
                arr[mainindex++] = right[rightindex++];
                count += (len1 - leftindex);
            }
            else{
                arr[mainindex++] = left[leftindex++];
            }
        }
        
        while(leftindex<len1){
          
            arr[mainindex++] = left[leftindex++];
           
        }
        
        while(rightindex<len2){
            arr[mainindex++] = right[rightindex++];
        }
        
        return;
    }
    
    void find(vector<int>&arr, int s, int end, int &count){
        
        int mid = (s + end)/2;
        
        if(s>=end){
            return;
        }
        
        find(arr, s, mid, count);
        find(arr, mid+1, end, count);
        
        merge(arr, s, end, count);
        
    }
    
    int inversionCount(vector<int> &arr) {
        
        int count = 0;
        
        find(arr, 0, arr.size()-1, count);
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends