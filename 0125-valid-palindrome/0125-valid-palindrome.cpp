class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;

        while (left < right) {
            while (left < n && !isalnum(static_cast<unsigned char>(s[left])))
                left++;
            while (right >= 0 && !isalnum(static_cast<unsigned char>(s[right])))
                right--;

            if (left < right && tolower(static_cast<unsigned char>(s[left])) != tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
