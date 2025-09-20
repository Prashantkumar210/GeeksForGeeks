// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        
        map<string,vector<string>>mp;
        
        for(auto s:arr){
            
            string str = s;
            sort(str.begin(), str.end());
            
            mp[str].push_back(s);
        }
        
        vector<vector<string>>ans;
        
        for(auto it = mp.begin(); it!=mp.end(); it++){
            ans.push_back(it->second);
            
        }
        
        return ans;
    }
};