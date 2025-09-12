// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        
        int s = 0;
        int e = arr.size()-1; 
        int mid = s +(e-s)/2;
        while(s<=e){
            if(arr[mid-1]==target) return mid-1;
            else if(arr[mid+1]==target) return mid+1;
            else if(arr[mid]==target) return mid;
            else if(arr[mid]<target) s = mid + 2;
            else e = mid -2;
            mid = s +(e-s)/2;
        }
        
        return -1;
    }
};