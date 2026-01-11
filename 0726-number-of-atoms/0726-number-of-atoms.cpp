class Solution {
private:
    int parseCount(const string& s, int& i) {
        if (i >= s.size() || !isdigit(s[i])) return 1;
        int count = 0;
        while (i < s.size() && isdigit(s[i])) {
            count = count * 10 + (s[i] - '0');
            i++;
        }
        return count;
    }

    string parseName(const string& s, int& i) {
        string name;
        name += s[i++];
        while (i < s.size() && islower(s[i])) {
            name += s[i];
            i++;
        }
        return name;
    }

    string mapToString(const map<string,int>& mp) {
        string result = "";
        for (auto [name, count]: mp) {
            result += name;
            if (count > 1) result += to_string(count);
        }
        return result;
    }

public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        if (n == 0) return "";

        stack<map<string,int>> stk;
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

        return mapToString(stk.top());
    }
};

// H2O
// stk = [{ H:2, O:1 }]
// Mg(OH)2
// stk = [{ Mg:1, O:2, H:2 }]
// K4(ON(SO3)2)2
// stk = [{ K:4, O:14, N:2, S:4 }]


