#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>
class Array {
	public:
		Array<T>() : content(new T[0]), n(0) {};
		Array<T>(unsigned int n) : content(new T[n]), n(n) {};

		virtual ~Array<T>() { delete[] content; };

		Array<T>(Array<T>& src) : n(src.size()) {
			content = new T[n];
			for (unsigned int i = 0; i < n; i++) {
				content[i] = src[i];
			}
		};

		Array<T>& operator=(Array<T>& rhs) {
			delete[] content;
			n = rhs.size();
			content = new T[n];
			for (unsigned int i = 0; i < n; i++) {
				content[i] = rhs[i];
			}
			return *this;
		};

		T& operator[](unsigned int i) {
			if (i >= n)
				throw std::exception();
			return content[i];
		};

		T const & operator[](unsigned int i) const {
			if (i >= n)
				throw std::exception();
			return content[i];
		};

		unsigned int size() const { return n; };

	protected:
		T* content;
		unsigned int n;
};

// NOTE: you can use tpp files, if you include them here after the class, then implement them like in .cpp files, but remember to do header protection

#endif
