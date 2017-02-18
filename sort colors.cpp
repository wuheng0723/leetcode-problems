class Solution {
public:
    void sortColors(int A[], int n) {
        if(n<=1) return;
        int Pos0 = 0;
        int Pos2 = n-1;
        int i = 0;
        while(i<Pos2+1)      //��Pos2+1��ʼ����λ�ö����Ѿ��������λ�ã�����ѭ����Pos2����
        {
            if(A[i] == 0)
            {
                swap(A[i++],A[Pos0++]);   //��ǰλ�ü�����ǰ�Ķ���0��˵����ǰλ���Ѵ���ã�������������һ��λ��
            }
            else
                if(A[i] == 2)
                    swap(A[i],A[Pos2--]);  //Pos2��λ�ý�������ǰδ֪������֪Ϊʲô������Ҫ�������i����1
                else
                    i++;    //��iΪ���������0��ͷ���2��β��ǰ�ţ�1��Ȼ���м�
        }
    }
};