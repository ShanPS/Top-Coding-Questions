/*
Problem: There is one meeting room in a firm.
There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i 
and F[i] is finish time of meeting i.
Find the maximum number of meetings that can be accommodated in the meeting room.

link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0
*/

#include <bits/stdc++.h>
using namespace std;

struct meeting {
    int startTime;
    int endTime;
    int meetingID;
};

bool cmp(meeting m1, meeting m2) {
    if(m1.endTime == m2.endTime)
    	return m1.startTime < m2.startTime;
    return m1.endTime < m2.endTime;
}

void nMeetings(meeting m[], int n) {
    sort(m, m+n, cmp);
    int curEndingTime = m[0].endTime;
    cout << m[0].meetingID << " ";
    for(int i=1; i<n; i++) {
        if(curEndingTime < m[i].startTime) {
            cout << m[i].meetingID << " ";
            curEndingTime = m[i].endTime;
        }
    }
    cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    meeting m[n];
	    for(int i=0; i<n; i++)
	        cin >> m[i].startTime;
	    for(int i=0; i<n; i++) {
	        cin >> m[i].endTime;
	        m[i].meetingID = i+1;
	    }
	    
	    nMeetings(m, n);
	}
	return 0;
}