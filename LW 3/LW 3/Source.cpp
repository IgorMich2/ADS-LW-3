#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
using namespace std;

template <class T>
class Heap
{
	vector <T> arr;
	void reHeapUp(int child);
	void reHeapUpMin(int child);
	void reHeapDown(int parent);
public:
	Heap() {}
	void insertKey(T date);
	T deleteKey();
	int getHeapSize();
	void display();
	void maxheap();
	void minheap();
	bool isempty();
	void Find_k_min_1(int k);
	void Find_k_min_2(int k);
	void Find_k_min_3(int k);
	int getLeftChild(int parent);
	int getRightChild(int parent);
	int getParent(int child);
};

template <class T>
int Heap<T> ::getHeapSize()
{
	return arr.size();
}

template <class T>
int Heap<T> ::getLeftChild(int parent)
{
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == parent) {
			return arr[2 * i + 1];
		}
	}
	return 0;
}

template <class T>
int Heap<T> ::getRightChild(int parent)
{
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == parent) {
			return arr[2 * i + 2];
		}
	}
	return 0;
}

template <class T>
int Heap<T> ::getParent(int child)
{
	return (child - 1) / 2;
}

template <class T>
void Heap<T> ::reHeapUp(int child)//maxheap
{
	if (child != 0)
	{
		int curr_parent = getParent(child);

		if (arr[child] > arr[curr_parent])
		{
			swap(arr[child], arr[curr_parent]);
			reHeapUp(curr_parent);
		}
	}
}

template <class T>
void Heap<T> ::reHeapUpMin(int child)//minheap
{
	if (child != 0)
	{
		int curr_parent = getParent(child);

		if (arr[child] < arr[curr_parent])
		{
			swap(arr[child], arr[curr_parent]);
			reHeapUpMin(curr_parent);
		}
	}
}

template <class T>
void Heap<T> ::reHeapDown(int parent)
{

	int left = getLeftChild(parent);

	if (left < arr.size())
	{
		int right = getRightChild(parent);

		if (right < arr.size())
		{
			if (arr[left] < arr[right])
			{
				if (arr[parent] < arr[right])
				{
					swap(arr[parent], arr[right]);
					parent = right;
					reHeapDown(parent);
				}
			}
			else
			{
				if (arr[parent] < arr[left])
				{
					swap(arr[parent], arr[left]);

					parent = left;
					reHeapDown(parent);
				}
			}
		}
		else
		{
			if (arr[parent] < arr[left])
			{
				swap(arr[parent], arr[left]);
			}
		}

	}
}

template <class T>
void Heap<T> ::insertKey(T data)
{
	arr.push_back(data);
	int child = arr.size() - 1;
	reHeapUp(child);
}

template <class T>
T Heap<T> ::deleteKey()
{
	if (arr.size() == 0)
	{
		cout << "Heap empty...returning -1";
		return -1;
	}

	int child = arr.size() - 1;
	swap(arr[0], arr[child]);

	T max_ele = arr.back();

	arr.pop_back();
	reHeapDown(0);
	return max_ele;
}

template <class T>
void Heap<T> ::display()
{
	if (arr.size() == 0)
	{
		cout << "Heap empty" << endl;
		return;
	}
	for (int i = 0; i < getHeapSize(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

template <class T>
void Heap<T> ::maxheap()
{
	sort(arr.rbegin(), arr.rend());
}

template <class T>
void Heap<T> ::minheap()
{
	sort(arr.begin(), arr.end());
}


template <class T>
bool Heap<T> ::isempty()
{
	if (arr.size() == 0)
	{
		return true;
	}
	else return false;
}
template <class T>
void Heap<T>::Find_k_min_1(int k) {
	int i, j, len = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < len - 1; i++) 
		for (j = 0; j < len - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
	cout << "k min 1: " << endl;
	for (int i = 0; i < k; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <class T>
void Heap<T>::Find_k_min_2(int k) {
	minheap();
	cout << "k min 2: " << endl;
	int l = arr.size();
	int n = min(k, l);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <class T>
void Heap<T>::Find_k_min_3(int k) {
	maxheap();
	cout << "k min 3: " << endl;
	int len = arr.size();
	for (int i = len - 1; i > len - k - 1; i--) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	Heap<int> h;


	/*h.insertKey(9);
	h.insertKey(10);
	h.insertKey(7);
	h.insertKey(6);
	h.insertKey(23);
	h.insertKey(8);
	h.insertKey(16);
	*/
	for (int i = 10; i >= 1; i--) {
		h.insertKey(i);
	}
	cout << "Heap is: " << endl;
	h.display();
	cout<<h.getLeftChild(10)<<endl;
	cout << h.getRightChild(10) << endl;

	cout << "Maxheap: " << endl;
	h.maxheap();
	h.display();

	cout << "Minheap: " << endl;
	h.minheap();
	h.display();
	int t1 = clock();
	h.Find_k_min_1(2);
	int t2 = clock();
	cout <<"Time is "<< t2-t1 <<" miliseconds"<< endl;
	t1 = clock();
	h.Find_k_min_2(2);
	t2 = clock();
	cout << "Time is " << t2 - t1 << " miliseconds" << endl;
	t1 = clock();
	h.Find_k_min_3(2);
	t2 = clock();
	cout << "Time is " << t2 - t1 << " miliseconds" << endl;


	Heap<string> h2;
	h2.insertKey("a");
	h2.insertKey("b");
	h2.insertKey("c");
	h2.insertKey("d");
	h2.insertKey("e");
	h2.display();
	cout<<h2.isempty();

	return 0;
}