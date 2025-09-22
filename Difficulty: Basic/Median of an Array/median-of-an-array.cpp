class Solution {
  public:
    double findMedian(vector<int> &arr) {
       
       sort(arr.begin(), arr.end());
       int n = arr.size();
       
       if(n%2==0){
           
           int i = n/2;
           double mid;
           mid = (arr[i-1]+arr[i])/2.0;
           return mid;
       }
     
        int i = n/2;
        return (double)arr[i];
       
    }
};