class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        // If there are only 2 elements, return their product
        if(n==2) return skill[0]*skill[1];

        ranges::sort(skill);
      
        long long current = skill[0]+skill[n-1];
        long long result = 0;

        // i works as a pointer from LHS and n-i-1 works as a pointer from RHS
        for(int i=0; i<n/2; i++){
            // If the sum does not match the current value, it implies a difference in skill set. Hence, return -1.
            if((skill[i]+skill[n-i-1]) != current) return -1;

            // If the skill set is valid, add the product of the skills to the "result".
            result += (long long)(skill[i]*skill[n-i-1]);
        }

        return result;
    }
};
