// #include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

// Time Complexity : O(nlog n)
// Space Complexity : O(1)

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function is same in both iterative and recursive*/
int partition(int arr[], int l, int h)
{
    //Do the comparison and swapping here
    int pivot = arr[h];
    int partition = l;
    for(int i = l; i < h; i++) {
        if(arr[i] <= pivot)
            swap(arr[i], arr[partition++]);
    }
    swap(arr[h], arr[partition]);
    return partition;
}

/* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
void quickSortIterative(int arr[], int l, int h)
{
    //Try to think that how you can use stack here to remove recursion.
    stack<pair<int, int>> st;
    st.push(make_pair(l, h));
    while(!st.empty()) {
        l = st.top().first;
        h = st.top().second;
        st.pop();

        int pivot = partition(arr, l, h);
        if(pivot - 1 > l) st.push(make_pair(l, pivot - 1));
        if(pivot + 1 < h) st.push(make_pair(pivot + 1, h));
    }
}

// An utility function to print contents of arr
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

// Driver code
int main()
{
    int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 };
    int n = sizeof(arr) / sizeof(*arr);
    quickSortIterative(arr, 0, n - 1);
    printArr(arr, n);
    return 0;
}