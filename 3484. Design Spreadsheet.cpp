class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) { sheet.resize(rows + 1, vector<int>(26, 0)); }

    vector<int> getLocation(string cell) {
        int c = cell[0] - 'A';
        int r = stoi(cell.substr(1, cell.size() - 1));

        // cout<<r<<" "<<c<<"\n";

        return {r, c};
    }

    void setCell(string cell, int value) {
        vector<int> p = getLocation(cell);
        int r = p[0];
        int c = p[1];

        sheet[r][c] = value;
    }

    void resetCell(string cell) {
        vector<int> p = getLocation(cell);
        int r = p[0];
        int c = p[1];

        sheet[r][c] = 0;
    }

    int getValue(string formula) {
        string s1 = "";
        string s2 = "";

        int idx = 1;

        while (formula[idx] != '+')
            s1 += formula[idx++];
        idx++;
        while (idx < formula.size())
            s2 += formula[idx++];

        int ans = 0;

        if (isdigit(s1[0])) {
            ans = stoi(s1);
        } else {
            vector<int> p1 = getLocation(s1);
            int r1 = p1[0];
            int c1 = p1[1];
            ans = sheet[r1][c1];
        }

        if (isdigit(s2[0])) {
            ans += stoi(s2);
        } else {
            vector<int> p2 = getLocation(s2);
            int r2 = p2[0];
            int c2 = p2[1];
            ans += sheet[r2][c2];
        }

        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
