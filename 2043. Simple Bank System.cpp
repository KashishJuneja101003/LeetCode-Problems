class Bank {
public:
    int n;
    vector<long long> balance;

    Bank(vector<long long>& bal) {
        n = bal.size();
        balance = bal;
    }

    bool isValid(int& acc){
        return acc >= 1 && acc <= n;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!isValid(account1)) return false;
        if(!isValid(account2)) return false;
        if(balance[account1-1] < money) return false;

        balance[account1-1] -= money;
        balance[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!isValid(account)) return false;
        balance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isValid(account)) return false;
        if(balance[account-1] < money) return false;
        balance[account-1] -= money;
        return true;
    }
};
