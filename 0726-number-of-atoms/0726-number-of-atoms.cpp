class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        if (n == 0) return "";

        stack<map<string, int>> stk;
        stk.push({});
        int idx = 0;

        while (idx < n) {
            if (isupper(formula[idx])) {
                string curr = "";
                curr += formula[idx];
                while (idx + 1 < n && islower(formula[idx + 1])) {
                    curr += formula[idx + 1];
                    idx++;
                }
                int count = 1;
                if (idx + 1 < n && isdigit(formula[idx + 1])) {
                    count = 0;
                    while (idx + 1 < n && isdigit(formula[idx + 1])) {
                        count = count * 10 + (formula[idx + 1] - '0');
                        idx++;
                    }
                }
                stk.top()[curr] += count;
            } else if (formula[idx] == '(') {
                stk.push({});
            } else if (formula[idx] == ')') {
                int group_count = 1;
                if (idx + 1 < n && isdigit(formula[idx + 1])) {
                    group_count = 0;
                    while (idx + 1 < n && isdigit(formula[idx + 1])) {
                        group_count = group_count * 10 + (formula[idx + 1] - '0');
                        idx++;
                    }
                }
                map<string, int> top_group = stk.top();
                stk.pop();
                for (auto [ch, count]: top_group) {
                    stk.top()[ch] += count * group_count;
                }
            }
            idx++;
        }

        string result = "";
        for (auto [ch, count]: stk.top()) {
            result += ch;
            if (count > 1) result += to_string(count);
        }
        return result;
    }
};

// H2O
// stk = [{ H:2, O:1 }]
// Mg(OH)2
// stk = [{ Mg:1, O:2, H:2 }]
// K4(ON(SO3)2)2
// stk = [{ K:4, O:14, N:2, S:4 }]


