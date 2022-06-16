#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter(T* arr_ptr, int length, void (*fn)(T &el)) {
	for (int i = 0; i < length; i++) {
		fn(arr_ptr[i]);
	}
}

#endif
