//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
         if (N <= K) return GeekNum[N - 1];

        vector<long long> geeky_series(GeekNum.begin(), GeekNum.end());
        long long current_sum = 0;

        for (int num : GeekNum) {
            current_sum += num;
        }
        
        for (int i = K; i < N; i++) {
            geeky_series.push_back(current_sum);
            current_sum += geeky_series[i];       
            current_sum -= geeky_series[i - K];   
        }

        return geeky_series[N - 1];
    }
};



//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends