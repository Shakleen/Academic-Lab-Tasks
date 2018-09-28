#include <iostream>

using namespace std;

int main()
{
    // input variables
    int n=5;

    cout << "Enter number of elements:\n";
    cin >> n;

    int a[n];

    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    // Insertion sort
    for(int i=1; i<n; i++)
    {
        int k = i;

        for(int j=i-1; j>=0; j--)
        {
            if (a[j] > a[k])
            {
                swap(a[j], a[k]);

                k = j;
            }
            else
            {
                break;
            }
        }
    }

    // Printing the array
    for(int i=0; i<n; i++)
    {
        cout << a[i] << "\n";
    }

    return 0;
}
