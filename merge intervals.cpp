/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval a, Interval b)
{
	if (a.start == b.start)           //如果第一个元素相同，就按照第二个元素排序；升序；主要是第一个元素来排序
		return a.end < b.end;
	else
		return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
		if (intervals.size() <= 1)
			return intervals;
        sort(intervals.begin(),intervals.end(),comp);
        vector<Interval> res;
        int start = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (start == 0)
            {
                Interval *p = new Interval();
                p->start = intervals[i].start;
                res.push_back(*p);
                start = 1;
            }
            if (start == 1)
            {
                if (i == intervals.size() - 1)
                {
                    res[res.size()-1].end = intervals[i].end;
                    break;
                }
                if (intervals[i].end >= intervals[i + 1].end)
                {
                    intervals[i + 1].end = intervals[i].end;
                    continue;
                }
                else
                    if (intervals[i].end >= intervals[i + 1].start)
                        continue;
                    else
                    {
                        res[res.size()-1].end = intervals[i].end;
                        start = 0;
                    }
            }
        }
        return res;
    }
};