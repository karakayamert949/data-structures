#include <iostream>
using namespace std;

void cycleSort(int arr[], int n)
{
    // writes counts number of memory writes
    int writes = 0;
 
    /*
    This is the main loop. n is the length of the array. 
    cycle_start is the main loop's iteration variable.
    Loop starts from 0th index to n-2th index. There is no need to
    check the element in n-1th index because it is the last element and
    there is no element left to compare to last element.
    */
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        /* 
        We initialize item as arr[cycle_start]. 
        We will use item to compare elements in array. 
        */
        int item = arr[cycle_start];
 
        /*
        Firstly, pos is initialized as main loop's iteration variable.
        cycle_start is our main first swapping index. We find second index to swap them, by
        counting how many smaller elements there are in greater indices than cycle_start.
        Starting from cycle_start+1th index to the end, we iterate over the array and when we encounter
        a smaller element we increase pos.
        */
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++)
            if (arr[i] < item)
                pos++;
 
        /* 
        After previous loop calculates pos' value, if pos' value is not changed, meaning
        item is already in correct position and there are no smaller elements in greater indices,
        we stop at this point and continue with next iteration in the main loop.
        */
        if (pos == cycle_start)
            continue;
 
        /* 
        At this point pos has to be changed. Last thing to check before swapping is
        whether item is duplicate of arr[pos]. If they have the same value we increment pos.
        */
        while (item == arr[pos])
            pos += 1;

        /*
        We swap item and arr[pos]. After swapping, the element in arr[pos]
        is now situated in right index.
        */
        swap(item, arr[pos]);
        writes++;

        /*
        This while loop will work until, from cycle_start+1 to end of array, there are no duplicate
        or smaller element than the element which in position cycle_start.
        */
        while (pos != cycle_start) {
            /* 
            cycle_start is our main first swapping index. We find second index to swap them, by
            counting how many smaller elements there are in greater indices than cycle_start.
            The rest of the process is similar to previous swapping steps.

            Firstly pos is initialized as cycle_start.
            Starting from cycle_start+1th index to the end, we count how many elements there are
            smaller than item (don't forget item = arr[cycle_start]) in the array.
            When we encounter a smaller element we increase pos. 
            */
            pos = cycle_start;
            for (int i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    pos += 1;
 
            // If item is duplicate of posth element of array, we increment pos.
            while (item == arr[pos])
                pos += 1;
 
            /*
            We swap item and arr[pos]. After swapping, the element in arr[pos]
            is now situated at the right position in the array.
            */
            if (item != arr[pos]) {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
}