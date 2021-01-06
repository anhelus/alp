=== "C"

	``` c
	void swap(int vector[], int swap_l_idx, int swap_r_idx, int swap_val) {
		vector[swap_l_idx] = vector[swap_r_idx];
		vector[swap_r_idx] = swap_val;
	}
	```

=== "C++"

	``` cpp
	void swap(vector& vect, int swap_l_idx, int swap_r_idx, int swap_val) {
		vect.at(swap_l_idx) = vect.at(swap_r_idx);
		vect.swap_r_idx = swap_val;
	}
	```

=== "Python"

	``` python
	def swap(vect, left, right, val):
		vect[left] = vect[right]
		vect[right] = val
	```

pippo pippa

=== "C"

	``` c
	void selection_sort(int vector[], int length) {
		for (int i = 0; i < length; i++) {
			int current = vector[i];
			int swap_index = i + 1;
			bool swapped = false;
			for (int j = i + 1; j < length; j++) {
				if (vector[j] < current) {
					current = vector[j];
					swap_index = j;
					swapped = true;
				}
			}
			if (swapped) {
				swap(vector, swap_index, i, current);
			}
		}
	}
	```

	``` cpp
	void selection_sort(vector& vect) {
		vector<int> l_vect;
		vector<int> r_vect;
		// Init left vector
		l_vect.assign(vect.at(0));
		// Init right vector
		vector<int>::iterator it;
		it = l_vect.begin() + 1;
		r_vect.assign(it, r_vect.end());
		while (r_vect.size() == 0) {
			int current = l_vect.end() - 1;
			int swap_idx = -1;
			for(vector<int>::iterator it = r_vect.begin(); it != r_vect.end(); ++it) {
				if (*it < current) {
					current = *it;
					swap_idx = it - r_vect.begin();		
				}
			}
			if (swap_idx > -1) {
				swap(vect, swap_index, current, *current);
			}
		}
	}
	```

	``` python
	def selection_sort(vect):
		l_vect = vect[0]
		r_vect = vect[1:]
		for i in range l_vect.len():
			
	```
