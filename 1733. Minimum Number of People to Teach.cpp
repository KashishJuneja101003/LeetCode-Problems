class Solution {
public:
    bool canTalk(vector<int>& a, vector<int>& b){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i=0; int j=0;
        int n1=a.size(), n2 = b.size();

        while(i < n1 && j < n2){
            if(a[i] < b[j]){ i++; continue;}
            if(b[j] < a[i]){ j++; continue;}

            if(a[i] == b[j]) return true;
        }

        return false;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // Get the friends who can't talk
        unordered_set<int> cantTalk;

        for(auto& f:friendships){
            int u1 = f[0]-1;
            int u2 = f[1]-1;

            if(!canTalk(languages[u1], languages[u2])){
                cantTalk.insert(u1);
                cantTalk.insert(u2);
            }
        }

        // If all can talk, we dont need to teach the language, return 0
        if(cantTalk.size() == 0) return 0;

        // Check the most known language
        vector<int> language(n+1, 0);
        for(int user:cantTalk){
            for(int lang:languages[user]){
                language[lang]++;
            }
        }
        int maxKnownLang = *max_element(language.begin(), language.end());

        // Pick the most common language and teach it to all others
        return cantTalk.size() - maxKnownLang;
    }
};
