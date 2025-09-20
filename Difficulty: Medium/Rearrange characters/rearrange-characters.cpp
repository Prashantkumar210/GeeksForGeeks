class Solution {
  public:
    string rearrangeString(string s){
        
        int hash[26] = {0};
        
        for(int i=0; i<s.length(); i++){
            
            hash[s[i]-'a']++;
        }
        
        int max_char = INT_MIN;
        char maxi_char;
        
        for(int i=0; i<26; i++){
            
            if(hash[i]>max_char){
                max_char = hash[i];
                maxi_char = i+'a';
            }
        }
        
        int index = 0;
        
        while(max_char>0 && index<s.size()){
            s[index] = maxi_char;
            index += 2; 
            --max_char;
        }
        
        if(max_char!=0) return "";
        hash[maxi_char-'a'] = 0;
        
        for(int i=0; i<26; i++){
            
            while(hash[i]>0){
                index = index >= s.length() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index = index + 2;
            }
        }
        
        return s;
    }
};