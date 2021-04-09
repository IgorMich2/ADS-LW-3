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
	void reHeapUp(int);
	void reHeapUpMin(int);
	void reHeapDown(int);
	int getLeftChild(int) const;
	int getRightChild(int) const;
	int getParent(int) const;

public:
	Heap() {}
	void insertKey(T);
	T deleteKey();
	int getHeapSize() const;
	void display() const;
	void maxheap();
	void minheap();
	bool isempty();
	bool isfull();
	void Find_k_min_1(int k);
	void Find_k_min_2(int k);
	void Find_k_min_3(int k);
};

template <class T>
int Heap<T> ::getHeapSize() const
{
	return arr.size();
}

template <class T>
int Heap<T> ::getLeftChild(int parent) const
{
	return 2 * parent + 1;
}

template <class T>
int Heap<T> ::getRightChild(int parent) const
{
	return 2 * parent + 2;
}

template <class T>
int Heap<T> ::getParent(int child) const
{
	return (child - 1) / 2;
}

template <class T>
void Heap<T> ::reHeapUp(int child)//maxheap
{
	// if child is not root then continue
	if (child != 0)
	{
		// get parent of the child
		int curr_parent = getParent(child);
		//if data at child index is more than at
		//parent index then swap and continue again
		//till the condition gets false
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
	// if child is not root then continue
	if (child != 0)
	{
		// get parent of the child
		int curr_parent = getParent(child);
		//if data at child index is more than at
		//parent index then swap and continue again
		//till the condition gets false
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

	// if there exists a left subtree
	if (left < arr.size())
	{
		//cout<<"left: "<<left<<endl;
		int right = getRightChild(parent);

		// if there exists a right subtree
		if (right < arr.size())
		{
			//cout<<"right: "<<right<<endl;
			if (arr[left] < arr[right])
			{
				if (arr[parent] < arr[right])
				{
					swap(arr[parent], arr[right]);
					/*cout<<"in left < right: "<<endl;
					display()*/;
					parent = right;
					reHeapDown(parent);
				}
			}
			else
			{
				if (arr[parent] < arr[left])
				{
					swap(arr[parent], arr[left]);
					/*cout<<"in left > right: "<<endl;
					display();*/
					parent = left;
					reHeapDown(parent);
				}
			}
		}
		// if no right subtree
		else
		{
			if (arr[parent] < arr[left])
			{
				swap(arr[parent], arr[left]);
				/*cout<<"No right subtree: "<<endl;
				display();	*/
			}
		}

	}
}

template <class T>
void Heap<T> ::insertKey(T data)
{
	// data is always added at the leaf
	arr.push_back(data);
	int child = arr.size() - 1;
	reHeapUp(child);
	//reHeapUpMin(child);
}

template <class T>
T Heap<T> ::deleteKey()
{
	// For Heaps delete function is used to return
	// max value from the heap
	if (arr.size() == 0)
	{
		cout << "Heap empty...returning -1";
		return -1;
	}

	int child = arr.size() - 1;
	// swap root value with last element
	swap(arr[0], arr[child]);

	// since root is swapped with last element it is
	// max and get that element
	T max_ele = arr.back();
	// dec the size of array
	arr.pop_back();
	reHeapDown(0);
	return max_ele;
}

template <class T>
void Heap<T> ::display() const
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
bool Heap<T> ::isfull()
{
	return false;
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
	cout << "k min: " << endl;
	for (int i = 0; i < k; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <class T>
void Heap<T>::Find_k_min_2(int k) {
	minheap();
	cout << "k min: " << endl;
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
	cout << "k min: " << endl;
	int len = arr.size();
	for (int i = len - 1; i > len - k - 1; i--) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	Heap<int> h;
	int k = 7;
	int a[] = { 9,10,7,6,23,8,16 };

	for (int i = 0; i < 7; i++)
		h.insertKey(a[i]);
	h.display();

	cout << "Current heap is: " << endl;

	cout << "Maxheap: " << endl;
	h.maxheap();
	h.display();

	cout << "Minheap: " << endl;
	h.minheap();
	h.display();

	h.Find_k_min_1(2);
	h.Find_k_min_2(2);
	h.Find_k_min_3(2);

	return 0;
}