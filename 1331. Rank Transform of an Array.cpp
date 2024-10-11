class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 0) return {};

        vector<int>temp = arr;
        ranges::sort(temp);

        unordered_map<int, int> myMap;
        int rank = 1;
        int i = 0;
        int curr = temp[i];
        
        while(i<n){
            myMap[temp[i]] = rank++;
            curr = temp[i];
            while(i < n && temp[i] == curr)i++;
        }

        // for(auto& i : myMap)cout<<"key: "<<i.first<<", value: "<<i.second<<endl;
        
        for(i = 0; i<n; i++) arr[i] = myMap[arr[i]];

        return arr;
    }
};
