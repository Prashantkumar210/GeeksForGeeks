// User function Template for C++
class Solution {
  public:
    int sumOfSquares(int n) {
        
        int sum = 0;
        
        for(int i=1; i<=n; i++){
            
            sum += i*i;
        }
        return sum;
    }
};