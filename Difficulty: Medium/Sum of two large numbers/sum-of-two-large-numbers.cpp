//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string &num1, string &num2) {
        
        vector<int>arr1(num1.length(), 0);
        vector<int>arr2(num2.length(), 0);

        for(int i=0; i<arr1.size(); i++){

            arr1[i] = num1[i]-'0';
        }

        for(int i=0; i<arr2.size(); i++){

            arr2[i] = num2[i]-'0';
        }

        int i = arr1.size()-1;
        int j = arr2.size()-1;

        int carry = 0;

        string ans = "";

        while(i>=0 && j>=0){

            int temp = arr1[i] + arr2[j] + carry;

            int digit = temp % 10;

            carry = temp /10;
            ans += digit +'0';
            i--;
            j--;
        }

        while(i>=0){

            int temp = arr1[i] + carry;
            int digit = temp%10;

            carry = temp /10;
            ans += digit +'0';
            i--;
        }

         while(j>=0){

            int temp = arr2[j] + carry;
            int digit = temp%10;

            carry = temp /10;
            ans += digit +'0';
            j--;
        }
    
        if(carry!=0)  ans += carry +'0';
        reverse(ans.begin(), ans.end());
        
        
        while(ans[0]=='0'){
            ans.erase(0,1);
        }
        
        if(ans.size()==0) return "0";
        
        return ans; 
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends