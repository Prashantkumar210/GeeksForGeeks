class Solution {
  public:
    int minDifference(vector<string> &arr) {
        
        vector<int>store;
        
        for(int i=0; i<arr.size(); i++){
            
            string time = arr[i];
            
            int hourse = stoi(time.substr(0,2));
            int minutes = stoi(time.substr(3,2));
            int second = stoi(time.substr(6,2));
            
            int total_time = (hourse*60*60)+(minutes*60) +second;
            
            store.push_back(total_time);
        }
        
        sort(store.begin(), store.end());
        
        int minimum = INT_MAX;
        for(int i=0; i<store.size()-1; i++){
            int diff = store[i+1]-store[i];
            minimum = min(diff, minimum);
        }
        
        int temp = 86400+store[0];
        int diff = temp - store[store.size()-1];
        
        minimum = min(minimum, diff);
        return minimum;
    }
};
