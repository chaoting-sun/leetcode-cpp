class Solution {
public:
    // digits = [3]
    // operators = [+]

    int calculate(string s) {
        deque<int> digits;
        deque<char> operators;
        int p = 0;
        int n = s.size();
        while (p < n) {
            if (isdigit(s[p])) {
                int start = p;
                while (p < n - 1 && isdigit(s[p + 1])) {
                    p++;
                }
                int curr = stoi(s.substr(start, p - start + 1));
                if (operators.empty() || !(operators.back() == '*' || operators.back() == '/')) {
                    digits.push_back(curr);
                } else {
                    int prev = digits.back();
                    digits.pop_back();
                    int res = operators.back() == '*' ? prev * curr : prev / curr;
                    operators.pop_back();
                    digits.push_back(res);
                }
            } else if (s[p] != ' ') {
                operators.push_back(s[p]);
            }
            p++;
        }

        while (!operators.empty()) {
            int curr = digits.front();
            digits.pop_front();
            int next = digits.front();
            digits.pop_front();
            int res = operators.front() == '+' ? curr + next : curr - next;
            digits.push_front(res);
            operators.pop_front();
        }

        return digits.front();
    }
};