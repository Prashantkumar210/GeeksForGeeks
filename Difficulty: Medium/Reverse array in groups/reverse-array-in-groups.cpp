class Solution {
  public:
    void reverseInGroups(vector<int> &arr, int k) {
        
        int n= arr.size()-1;
        for(int i=0; i<=n; i+=k){
            
            int l = i;
            int r = min(i+k-1, n);
            
            while(l<=r){
                swap(arr[l], arr[r]);
                l++;
                r--;
            }
            
        }
    }
};
