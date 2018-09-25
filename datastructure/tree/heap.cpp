#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <limits>

//Basic skeleton of the heap, may not be compilable

using namespace std;

#define MAX_SIZE	256     //To demonstrate the basic functionality, considered this as max

template <typename T>
struct heap {
	uint16_t size;
	T data[MAX_SIZE];

	heap():size(0) {}

	bool hasLeftChild(const int& t) {
        if (((2*t) + 1) < size)
            return true;
        return false;
    }

	bool hasRightChild(const int& t) {
        if (((2*t) + 2) < size)
            return true;
        return false;
    }

    bool hasElements() {
        if(size <= 0)
            return false;
        return true;
    }

	void insert(T element)
	{
        data[size++] = element;
		min_heapify_up();
	}

	void min_heapify_up()
	{
		uint16_t t = size;
		while (t > 0) {
		if(data[(t-1)/2] > data[t]) //root > child
			swap(data[t], data[(t-1)/2]);
		}
	}

	void min_heapify_down()
	{
		uint16_t t = 0;
		while (t < size/2)
		{
			if (hasLeftChild(t) && data[t] > data[2*t+1])
                swap(data[t], data[2*t+1]);
			if (hasRightChild(t) && data[t] > data[2*t+2])
				swap(data[t], data[2*t+2]);
		}
	}

	T delete_min()
	{
        if(!hasElements()) {throw out_of_range("No elements in the heap"); }
		T min = data[0];
		swap(data[0], data[size --]);
		swap(data[size], numeric_limits<T>::lowest());
		min_heapify_down();
		return min;
	}

    void heap_sort()
    {
        // Assume the heap is already built
        while (size > 0) {
            delete_min();
            min_heapify_down();
        }
    }
};
