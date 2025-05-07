#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cout << "Enter no of elements : ";
    cin >> n;

    int arr[n];

    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {

        int minIdx = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[minIdx] > arr[j])
            {
                minIdx = j;
            }
        }

        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}