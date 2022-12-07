#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter(T* arr_ptr, unsigned int length, void (*fn)(T &el)) {
	for (unsigned int i = 0; i < length; i++) {
		fn(arr_ptr[i]);
	}
}

template<typename T>
void iter(T* const arr_ptr, unsigned int length, void (*fn)(T const &el)) {
	for (unsigned int i = 0; i < length; i++) {
		fn(arr_ptr[i]);
	}
}

#endif
