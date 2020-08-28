/*
Problem: Given a set of N jobs where each job i has a deadline and profit associated to it. 
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit if and only if the job is completed by its deadline. 
The task is to find the maximum profit and the number of jobs done.

link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0
*/

#include <bits/stdc++.h>
using namespace std;

struct job {
    int ID;
    int deadline;
    int profit;
};

bool cmp(job j1, job j2) {
    return j1.profit > j2.profit;
}

void jobSequencing(job jobs[], int n) {
    int maxProfit = 0, jobsDone = 0;
    bool taken[n];
    memset(taken, 0, sizeof(taken));
    sort(jobs, jobs+n, cmp);
    
    for(int i=0; i<n; i++) {
        for(int j=min(jobs[i].deadline-1, n-1); j>=0; j--) {
            if(!taken[j]) {
                maxProfit += jobs[i].profit;
                jobsDone++;
                taken[j] = true;
                break;
            }
        }
    }
    
    cout << jobsDone << " " << maxProfit << "\n";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    job jobs[n];
	    for(int i=0; i<n; i++)
	        cin >> jobs[i].ID >> jobs[i].deadline >> jobs[i].profit;
	    
	    jobSequencing(jobs, n);
	}
	return 0;
}