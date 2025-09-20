class Solution {
public:
    // Approach: Stack
    // Time: O(n)
    // Space: O(n)

    string simplifyPath(string path) {
        int n = path.size();
        vector<string> parts;

        int left = 0;
        while (left < n) {
            while (left < n && path[left] == '/') left++;
            if (left == n) break;
            int right = left;
            while (right < n && path[right] != '/') right++;
            
            string segment = path.substr(left, right - left);
            if (segment == "..") {
                if (parts.size() > 0) parts.pop_back();
            } else if (segment != ".") {
                parts.push_back(segment);
            }
            left = right;
        }

        if (parts.size() == 0) return "/";

        string ans;
        for (int i = 0; i < parts.size(); i++) {
            ans += "/" + parts[i];
        }
        return ans;
    }
};