class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++){
            int first = nums[i];
            int second = target - first;

            if(hash.find(second) != hash.end()){
                result.push_back(i);
                result.push_back(hash[second]);
                break;
            }
            else{
                hash[first] = i;
            }
        }
        return result;
    }
};
