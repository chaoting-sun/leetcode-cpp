class Solution {
public:
    // Approach: Two pointers. Maintain two pointers from left-most and right-most
    // index of s, comparing them and moving them toward the center
    // Time: O(n), where n is the length of s
    // Space: O(1)

    // Technical Details
    // - isalnum and tolower are both from <cctype> library
    // - as s consists only of printable ASCII characters, so it is safe to write
    //   isalnum(ch) or tolower(ch). If the constraint is not given, a safer method
    //   would be isalnum(static_cast<unsigned char>(ch), and ...(ignored)

    // bool isPalindrome(string s) {
    //     int n = s.size();
    //     int left = 0, right = n - 1;

    //     while (left < right) {
    //         while (left < n && !isalnum(s[left]))
    //             left++;
    //         while (right >= 0 && !isalnum(s[right]))
    //             right--;

    //         if (left < right && tolower(s[left]) != tolower(s[right])) {
    //             return false;
    //         }
    //         left++;
    //         right--;
    //     }
    //     return true;
    // }

    // simpler code

    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;

        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
