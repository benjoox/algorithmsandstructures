// Implementation of an Array in C++
#include <iostream>
#include <string>

using namespace std;

template<typename T>

class Array {
	private: 
	int length;
	int capacity;
	T* ptr; 	

	public: 

	Array(int size) { 
		length = size;
	}

	Array(T arr[], int s) {
		ptr = new T[s]; 
		length = s; 
		for (int i = 0; i < length; i++) 
        ptr[i] = arr[i]; 
	}

	T& get() {
		return *ptr;
	} 

	void set(int index, T element) {
		if( index > length - 1) throw 20;
		ptr[index] = element;
	}
	void add(T element) {
		T* newPtr = new T[length];
		for(int i = 0; i < length; i++) {
			newPtr[i] = ptr[i];
		}
		newPtr[length] = element;
		ptr = newPtr;
		length++;
	}

	void removeAt(int index) {
		if( index > length - 1 || index < 0) throw 20;
		for(int i = 0, j = 0; i < length; i++, j++) {
			if(i != index) {
				ptr[j] = ptr[i];
			} else {
				j--;
			}
		}
		length --;
	}

	bool remove(T obj) {
		int removed = false;

		for(int k = 0; k < size(); k++) {
			if(ptr[k] == obj) {
				removeAt(k);
				removed = true;
				// Check from the same index in the next iteration
				// to compensate for the decrease in the length of 
				// the original array
				k--; 
			}
		}

		return removed;
	}

	int size() { return length; }
	bool isEmpty() { return size() == 0; }
	void clear() {
		for (int i = 0; i < length; i++) {
			(*ptr)[i] = 0;
		}
		length = 0;
	}

 	void setLength (int myLength) {  length = myLength; }  	
	void toString() {
		for(int i = 0; i < length; i++) {
			cout << ptr[i] << "\n";
		}
	}
};


int main() {
	try {
		cout << "Test the implementation of an Array in C++" << "\n";
		string animals[4] = {"Elephant", "Lion", "Deer", "Tiger"};
		Array<string> newArr(animals, 4);
		
		newArr.removeAt(3);
		newArr.add("soosk");
		newArr.add("soosk");
		newArr.toString();
		newArr.remove("soosk");
		newArr.toString();
		newArr.clear();
		newArr.toString();

	} catch(int e) {
		 if(e == 20) {
			cout << "The index is out of range";
			cout << "\nEnd of the process\n";
			return 0;
		 }
		 
	} 
        
	cout << "\n End of the process";
	return 0;
};
