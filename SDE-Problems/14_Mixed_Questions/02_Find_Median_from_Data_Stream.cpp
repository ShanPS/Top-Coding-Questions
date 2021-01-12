/*
Problem: Median is the middle value in an ordered integer list.
         If the size of the list is even, then the median is the mean of the two middle value.
For example,
[2,3,4], the median is 3
[2,3], the median is (2 + 3)/2 = 2.5

Design a data structure that supports the following two operations:
    void addNum(int num) - Add an integer number from the data stream to the data structure.
    double findMedian()  - Return the median of all elements so far.


link: https://leetcode.com/problems/find-median-from-data-stream/
*/

class MedianFinder {
	double median;                                         //Stores current median
	priority_queue<int> max;                               //Max heap for lower values
	priority_queue<int, vector<int>, greater<int>> min;    //Min heap for greater values

public:
	MedianFinder() {
		median = -1;
	}

	void addNum(int num) {
		if(max.empty()) {
			max.push(num);
			median = num;
			return;
		}

		if(max.size() > min.size()) {
			if(max.top() > num) {
				min.push(max.top());
				max.pop();
				max.push(num);
			}
			else {
				min.push(num);
			}
			median = (max.top() + min.top())/2.0;
		}
		else if(max.size() < min.size()) {
			if(min.top() < num) {
				max.push(min.top());
				min.pop();
				min.push(num);
			}
			else {
				max.push(num);
			}
			median = (max.top() + min.top())/2.0;
		}
		else {
			if(num < median) {
				max.push(num);
				median = max.top();
			}
			else {
				min.push(num);
				median = min.top();
			}
		}
	}

	double findMedian() {
		return median;
	}
};

/**
 * MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */