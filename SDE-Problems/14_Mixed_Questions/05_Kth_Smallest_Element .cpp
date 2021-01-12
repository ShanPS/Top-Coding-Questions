/*
Problem: Given an array arr[] and a number K where K is smaller than size of array.
The task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Note: 
Expected Time Complexity is O(n)

Link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#
*/

// partitions the array taking last element as the pivot
// l = array lower index and r = array upper index
int partition(int arr[], int l, int r) {
    int i = l;
    int j = l;
    
    while(j != r) {
        if(arr[j] < arr[r]) {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    
    swap(arr[i], arr[j]);
    return i;
}

// l = array lower index (initially 0)
// r = array upper index (initially arr.size()-1)
// k = Kth smallest element that we need to find (1 based index value)
int kthSmallest(int arr[], int l, int r, int k) {
    int random_index = (rand() % (r-l+1)) + l ;  // to get a random number in range: [l, r]
    
    swap(arr[random_index], arr[r]);
    int pivot_pos = partition(arr, l, r);
    
    if(pivot_pos == k-1) return arr[pivot_pos];
    else if(k-1 < pivot_pos) return kthSmallest(arr, l, pivot_pos-1, k);
    else return kthSmallest(arr, pivot_pos+1, r, k);
}