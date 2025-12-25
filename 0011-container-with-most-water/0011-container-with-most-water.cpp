// one way: iterate all possibilities of two endpoints -> O(n^2)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int line_count = height.size();
        int left = 0, right = line_count - 1;
        int max_area = 0;
        while (left < right) {
            max_area = max(max_area, (right - left) * min(height[left], height[right]));
            if (height[left] > height[right]) {
                right--;
            } else if (height[left] < height[right]) {
                left++;
            } else {
                left++;
                right--;
            }
        }
        return max_area;
    }
};
