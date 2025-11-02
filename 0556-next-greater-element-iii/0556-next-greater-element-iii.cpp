class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.size();
        int pivot = len - 2;
        while (pivot >= 0 && s[pivot] >= s[pivot + 1]) {
            pivot--;
        }
        if (pivot == -1) {
            return -1;
        }
        int nextGreaterIdx = len - 1;
        while (pivot < nextGreaterIdx && s[pivot] >= s[nextGreaterIdx]) {
            nextGreaterIdx--;
        }
        swap(s[pivot], s[nextGreaterIdx]);
        reverse(s.begin() + pivot + 1, s.end());
        return stoll(s) > INT_MAX ? -1 : stoi(s);
    }
};
