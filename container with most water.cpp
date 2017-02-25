#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int> &height)
{
	if(height.size() <= 1)
		return 0;
	if(height.size() == 2)
		return min(height[0],height[1]);
	int i = 0;
	int j = height.size()-1;
	int maxAre = 0;
	while(i<j)
	{
		int AreaNow = (j-i)*min(height[i],height[j]);  //容量由短的高度决定
		if(AreaNow > maxAre)
			maxAre = AreaNow;
		if(height[i] < height[j])
			i++;
		else
			j--;
	}
	return maxAre;
}
void main()
{
	int data[] = {1,1};
	vector<int> input(data,data+2);
	cout<<maxArea(input);
}