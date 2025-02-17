//{ Driver Code Starts
// C++ program to check if two strings are isomorphic

#include <bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256


// } Driver Code Ends
class Solution {
  public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string &s1, string &s2) {

                
        int hash1[256] = {0};
        int hash2[256] = {0};

        for(int i=0; i<s1.length(); i++){

            if(hash1[s1[i]] == 0 && hash2[s2[i]] == 0){
                hash1[s1[i]] = s2[i];
                hash2[s2[i]] = 1;
            }
        }

        for(int i=0; i<s1.length(); i++){
            
            if(hash1[s1[i]]!= s2[i]){
                return false;
            }
        }

        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    string s1, s2;
    while (t--) {
        cin >> s1;
        cin >> s2;
        Solution obj;
        int r = obj.areIsomorphic(s1, s2);
        if (r) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends