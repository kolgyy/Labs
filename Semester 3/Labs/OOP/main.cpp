#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Three_Dimensional_Array {
public:
	Three_Dimensional_Array(int x, int y, int z) { // Basic constructor
		size_x = x;
		size_y = y;
		size_z = z;
		array_data.resize(size_x * size_y * size_z); // Changing the array's size
	}

	void set_value(int x, int y, int z, int value) {
		int index = x * size_y * size_z + y * size_z + z; // Calculating the index of the element
		array_data[index] = value;
	}

	int get_value(int x, int y, int z) {
		int index = x * size_y * size_z + y * size_z + z;
		return array_data[index];
	}

	int get_size_x() {
		return size_x;
	}
	int get_size_y() {
		return size_y;
	}
	int get_size_z() {
		return size_z;
	}
private:
	int size_x, size_y, size_z;
	vector<int> array_data;
};

int main() {
	Three_Dimensional_Array array(5, 5, 5); // Creating a 5*5*5 array
	
	for (int x = 0; x < array.get_size_x(); ++x) { // Filling the array with numbers
		for (int y = 0; y < array.get_size_y(); ++y) {
			for (int z = 0; z < array.get_size_z(); ++z) {
				array.set_value(x, y, z, x * 100 + y * 10 + z);
			}
		}
	}

	int x = 3, y = 5, z = 1;
	int value = array.get_value(x, y, z);
	cout << "The element with the following coordinates : x = 3, x = 5, z = 1" << endl;
	cout << value << endl;

	return 0;
}