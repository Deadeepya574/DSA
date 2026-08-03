#include <bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int p = i;
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[j] < arr[p])
            {

                p = j;
            }
        }
        swap(arr[p], arr[i]);
    }
}

void bubble_sort(vector<int> &arr)
{

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int swapdid = 0;
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapdid = 1;
            }
        }

        if (swapdid == 0)
        {
            break;
        }
    }
}

void inserion_sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    inserion_sort(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}