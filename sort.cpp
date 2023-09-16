#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Select minimum & swap | pushes minimum to left,by swap.
void selectionSort(int arr[], int n)
{
    for (int i = 0; i <= (n - 2); i++)
    {
        int mini = i;                    // lets assume that i is minimum.
        for (int j = i; j <= n - 1; j++) // here j = i bec we find minimum from outer loop
        {
            if (arr[j] < arr[mini]) // if assume no is not minimum then change it
            {
                mini = j;
            }
        };
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    };
};

// Pushes the maximum to the last(right), by Adjacent-Swap.
void bubbleSort(int arr[], int n)
{
    for (int k = 0; k < 5; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        cout << "This is i:" << i << endl;
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            cout << "This is j:" << j << " "
                 << "-> " << arr[j] << " " << arr[j + 1] << endl;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        cout << "didSwap :" << didSwap << endl;
        // After complete one ajjacent swap-->>
        for (int k = 0; k < 5; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
        if (didSwap == 0)
        {
            break;
        }
    }
};

// Takes an element and place it in it's correct order. || Swap till it can be possible
void insertionSort(int arr[], int n) // every item looking for at the left are you greater the swap till i can do
{
    cout << "This is a unsorted array: ";
    for (int k = 0; k < 5; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
    for (int i = 0; i <= n - 1; i++)
    {

        int j = i;
        if (j != 0)
        {
            cout << "This is i :" << i << endl;
            cout << arr[j - 1] << ">" << arr[j] << endl;
        }

        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
        for (int k = 0; k < 5; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    };
};

// Devide and marge
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    cout<<"Print vector";
    for(auto it : temp){
        cout<<it<<" ";
    }
    cout<<endl;
    // transforing all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        cout<<"Index: "<<i<<endl;
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);      // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);    // merging sorted halves
}

// Devide and conquer
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void qs(vector<int> &arr,int low,int high){
    if(low<high){
        int pIndex=partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}
void quickSort(vector<int> arr){
    qs(arr,0,arr.size()-1);
     for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

//Heapsort
void Heapify(vector<int>&arr, int n , int index) {

    int right = 2 * index + 2;
    int left = 2 * index + 1;
    int largestNode = index  ;
  

    if (left < n  && arr[left] > arr[largestNode]) {
        largestNode = left ;
    }

    if (right < n && arr[right] > arr[largestNode]) {
        largestNode = right  ;
    }

    if (largestNode != index) {
        swap(arr[index], arr[largestNode])  ;
        Heapify(arr, n, largestNode)  ;
    }
}
void createHeap(vector<int>&arr, int n) {

    int start = (n / 2) - 1 ;

    for (int index = start ; index >= 0; index--) {
        Heapify(arr, n, index)  ;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Start code from here ------>>*
    int n = 5;
    // int arr[17] = {6334 ,4098 ,7968 ,4523 ,277 ,6956 ,4560, 2062 ,5705 ,5743 ,879, 5626, 9961, 491, 2995, 741, 4827};
    // int arr[5] = {22, 11, 77, 99, 55};
    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    // Only for merge sort
    vector<int>arr={22, 11, 77, 99, 55};

    // vector<int> arr ={6334 ,4098 ,7968 ,4523 ,277 ,6956 ,4560, 2062 ,5705 ,5743 ,879, 5626, 9961, 491, 2995, 741, 4827};
    // int n = 17;

    // cout << "Before Sorting Array: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // mergeSort(arr, 0, n - 1);
    quickSort(arr);
    // cout << "After Sorting Array: " << endl;
    // cout<<"Ans Is : ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    //  createHeap(arr, n)  ;
  
    // End code here-------->>*
    return 0;
}
