#include<iostream>
#include<fstream>
using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");


int partition(int a[], int left, int right)
{
    int pivot = a[right];
    int vt = left - 1;
    for (int i = left; i < right; i++)
    {
        if (a[i] < pivot)
        {
            vt++;
            swap(a[i], a[vt]);
        }
    }
    vt++;
    swap(a[vt], a[right]);
    return vt;
}

void quickSort(int a[], int left, int right) {
    if (left < right)
    {
        int pi = partition(a, left, right);
        quickSort(a, left, pi - 1);
        quickSort(a, pi + 1, right);
    }
}

int main()
{
    int n;
    int a[100];
    input >> n;
    for (int i = 0; i < n; i++)
    {
        input >> a[i];
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        output << a[i] << " ";
    }
}
