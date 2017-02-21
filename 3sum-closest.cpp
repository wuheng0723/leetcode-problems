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
            //ʹ��˫ָ�����������������������
            int left = i + 1;
            int right = m - 1;
            while (left < right)
            {
                int sum = num[i] + num[left] + num[right];
                int diff = abs(target - sum);
                //������Сֵ
                if (diff < minDiff)
                {
                    minDiff = diff;
                    minSum = sum;
                }
                //����left��rightָ��
                if (sum < target)   //��Ϊ����С��������������������
                    left++;
                else
                    if (sum > target)
                        right--;
                    else
                        return sum;  //����򷵻�
            }
        }
        return minSum;
    }
};