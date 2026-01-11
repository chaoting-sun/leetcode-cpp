class Solution {
private:
    int parseCount(const string& formula, int& i) {
        int n = formula.size();
        if (i >= n || !isdigit(formula[i])) return 1;
        int count = 0;
        while (i < n && isdigit(formula[i])) {
            count = count * 10 + (formula[i] - '0');
            i++;
        }
        return count;
    }

    string parseName(const string& formula, int& i) {
        int n = formula.size();
        string name;
        name += formula[i++];
        while (i < n && islower(formula[i])) {
            name += formula[i];
            i++;
        }
        return name;
    }

public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        if (n == 0) return "";

        stack<map<string, int>> stk;
        stk.push({});
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                stk.push({});
                i++;
            } else if (formula[i] == ')') {
                auto top_map = stk.top();
                stk.pop();
                i++;
                int multiplier = parseCount(formula, i);
                for (auto [name, count]: top_map) {
                    stk.top()[name] += count * multiplier;
                }
            } else {
                string name = parseName(formula, i);
                int count = parseCount(formula, i);
                stk.top()[name] += count;
            }
        }

        string result = "";
        for (auto [name, count]: stk.top()) {
            result += name;
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


