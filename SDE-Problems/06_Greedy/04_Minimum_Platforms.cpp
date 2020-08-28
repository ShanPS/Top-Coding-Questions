/*
Problem: Given arrival and departure times of all trains that reach a railway station.
Your task is to find the minimum number of platforms required for the railway station so that 
no train waits.

Note:
1. Consider that all the trains arrive on the same day and leave on the same day. 
2. Arrival and departure times will not be same for a train, but we can have arrival time of one train 
equal to departure of the other. In such cases, we need different platforms.

link: https://practice.geeksforgeeks.org/problems/minimum-platforms/0
*/

#include<iostream>
#include<map>

using namespace std;

int main() {
	int t, n;
	cin >> t;
	while(t--) {
	    cin >> n;
	    multimap<int, char> m;
	    int temp;
	    for(int i=0; i<n; i++) {
	        cin >> temp;
	        m.insert(make_pair(temp, 'a'));
	    }
	    for(int i=0; i<n; i++) {
	        cin >> temp;
	        m.insert(make_pair(temp, 'd'));
	    }
	    int value = 0, platforms = 0;
	    for(auto it=m.begin(); it!=m.end(); it++) {
	        if(it->second=='a')
	            value++;
	        else
	            value--;
	        platforms = max(platforms, value);
	    }
	    cout << platforms << "\n";
	}
	return 0;
}