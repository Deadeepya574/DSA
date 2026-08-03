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

    for (int i = arr.size() - 1; i >= 0 ; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[i])
            {
                swap(arr[i], arr[j]);
            }
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

    bubble_sort(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}