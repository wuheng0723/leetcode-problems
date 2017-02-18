class Solution {
public:
    void sortColors(int A[], int n) {
        if(n<=1) return;
        int Pos0 = 0;
        int Pos2 = n-1;
        int i = 0;
        while(i<Pos2+1)      //从Pos2+1开始向后的位置都是已经处理过的位置，所以循环到Pos2就行
        {
            if(A[i] == 0)
            {
                swap(A[i++],A[Pos0++]);   //当前位置及其以前的都是0，说明当前位置已处理好，接下来处理下一个位置
            }
            else
                if(A[i] == 2)
                    swap(A[i],A[Pos2--]);  //Pos2的位置交换到当前未知的数不知为什么数，需要处理，因此i不加1
                else
                    i++;    //当i为的情况；将0从头向后，2从尾向前放，1自然在中间
        }
    }
};