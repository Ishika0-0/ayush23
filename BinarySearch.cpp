#include <iostream>  
using namespace std;  
int bin_search (int arr[], int num, int tgt)  
{  
    int beg = 0, end = num - 1;  
    while (beg <= end)  
    { 
        int mid = (beg + end) /2;         
        if (tgt == arr[mid])  
        {  
            return mid; 
        }         
        else if (tgt < arr[mid])  
        {  
            end = mid - 1;  
        }         
        else {  
            beg = mid + 1;  
        }  
    }  
    return -1;  
}  
int main ()  
{  
    int arr[] = { 5, 10, 15, 20, 25, 30, 37, 40};  
    int tgt = 25;                                                    // specified the target element     
    int num = sizeof (arr) / sizeof (arr[0]);  
    int pos = bin_search (arr, num, tgt);     
    if (pos != 1)  
    {  
        cout << " Element is found at position " << (pos + 1)<< endl;  
    }  
    else  
    {  
        cout << " Element is not found in the array" << endl;  
    }  
    return 0;  
}  
