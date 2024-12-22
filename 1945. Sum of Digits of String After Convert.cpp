class Solution {
public:
    int getLucky(string s, int k) {
        string nstr = "";

        for(char c:s){  // O(s.size())
            nstr += to_string(c-'a'+1);
        }

        cout<<"nstr: "<<nstr;

        for(int i=0; i<k; i++){ // O(k*nstr.size())
            int sum = 0;
            for(char c:nstr){
                sum += c-'0';
            }
            nstr = to_string(sum);
            cout<<"\nk: "<<i+1<<" Sum: "<<sum;
        }

        return stoi(nstr);
    }
};
