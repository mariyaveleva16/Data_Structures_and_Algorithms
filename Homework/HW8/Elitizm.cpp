//https://www.hackerrank.com/contests/sda-homework-8/challenges/elitism
#include <bits/stdc++.h>
using namespace std;
class MinHeap
{
    double* harr;
    int capacity; 
    int heap_size; 
public:
    MinHeap(int capacity);
    void MinHeapify(int);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    double extractMin();
    double getMin() { return harr[0]; }
    int getSize() {
        return heap_size;
    }
    void insertKey(double k);
};
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new double[cap];
}
void MinHeap::insertKey(double k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    heap_size++;
    int i = heap_size-1;
    harr[i] = k;
    
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
    
}
double MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
    double root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
void swap(double& x, double& y)
{
    double temp = x;
    x = y;
    y = temp;
}
class MaxHeap
{
    double* harr;
    int capacity;
    int heap_size;
public:
    MaxHeap(int capacity);
    void MaxHeapify(int);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    double extractMax();
    double getMax() { return harr[0]; }
    int getSize() {
        return heap_size;
    }
    void insertKeyMax(double k);
};
MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new double[cap];
}
void MaxHeap::insertKeyMax(double k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    heap_size++;
    int i = heap_size -1;
    harr[i] = k;
    
    while (i != 0 && harr[parent(i)] < harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}
double MaxHeap::extractMax()
{
    if (heap_size <= 0)
        return INT_MIN;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
    double root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MaxHeapify(0);

    return root;
}
void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int biggest = i;
    if (l < heap_size && harr[l] > harr[i])
        biggest = l;
    if (r < heap_size && harr[r] > harr[biggest])
        biggest = r;
    if (biggest != i)
    {
        swap(harr[i], harr[biggest]);
        MaxHeapify(biggest);
    }
}
void printMedians(double arr[], int n)
{
    MaxHeap s(n);
    MinHeap g(n);
    double med = arr[0];
    s.insertKeyMax(arr[0]);
    cout << med << "\n";
    for (int i = 1; i < n; i++)
    {
        double x = arr[i];
        if ( s.getSize() > g.getSize())
        {
            if (x < med)
            {
                g.insertKey(s.getMax());
                s.extractMax();
                s.insertKeyMax(x);
            }
            else
            {
                g.insertKey(x);
            }

            med = (s.getMax() + g.getMin()) / 2.0;
        }
        else if (s.getSize() == g.getSize())
        {
            if (x < med)
            {
                s.insertKeyMax(x);
                med = (double)s.getMax();
            }
            else
            {
                g.insertKey(x);
                med = (double)g.getMin();
            }
        }
        else
        {
            if (x > med)
            {
                s.insertKeyMax(g.getMin());
                g.extractMin();
                g.insertKey(x);
            }
            else
            {
                s.insertKeyMax(x);
            }

            med = (s.getMax() + g.getMin()) / 2.0;
        }
        cout << med << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  	cout << fixed << setprecision(1);
  	int N;
    cin >> N;
    double* arr;
    arr = new double[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    printMedians(arr, N);
    return 0;
}
