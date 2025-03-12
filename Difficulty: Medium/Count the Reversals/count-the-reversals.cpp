//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    if(s.length()%2 == 1) return -1;
    
    stack<char>st;
    
    for(int i=0; i<s.length(); i++){
        
        if(st.empty()){
            st.push(s[i]);
        }
        
        else if(st.top()=='{' && s[i]=='}'){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    
    int count = 0;
    
    while(!st.empty()){
        
        char first = st.top();
        st.pop();
        char second = st.top();
        st.pop();
        
       if(first == '{'){
           if(second=='{'){
               ++count;
           }
           else{
               count +=2;
           }
       }
       else if(first=='}'){
           if(second=='}'){
               count++;
           }
           else{
               count += 2;
           }
       }
    }
    
    return count;
    
}