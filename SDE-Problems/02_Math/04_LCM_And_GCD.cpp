/*
Problem: Given two numbers A and B. The task is to find out their LCM and GCD

link: https://practice.geeksforgeeks.org/problems/lcm-and-gcd/0
*/

#include <iostream>
using namespace std;

long long find_gcd(long long a, long long b)
{
    if(a%b == 0)
        return b;
    return find_gcd(b%a, a);
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    long long a, b, lcm, gcd;
	    cin >> a >> b;
	    gcd = find_gcd(a, b);
	    lcm = (a * b) / gcd;
	    cout << lcm << " " << gcd << "\n";
	}
	return 0;
}