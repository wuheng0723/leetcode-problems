class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int m = num.size();
        if (m < 3)
            return 0;
        sort(num.begin(),num.end());
        int minDiff = abs(num[0]+num[1]+num[2]-target);
        int minSum = num[0] + num[1] + num[2];
        for (int i = 0; i < m - 1; i++)
        {
            //使用双指针来解决两个数的搜索问题
            int left = i + 1;
            int right = m - 1;
            while (left < right)
            {
                int sum = num[i] + num[left] + num[right];
                int diff = abs(target - sum);
                //更新最小值
                if (diff < minDiff)
                {
                    minDiff = diff;
                    minSum = sum;
                }
                //更新left和right指针
                if (sum < target)   //因为是由小到大排序所以这样更新
                    left++;
                else
                    if (sum > target)
                        right--;
                    else
                        return sum;  //相等则返回
            }
        }
        return minSum;
    }
};