#ifndef __VECTOR__
#define __VECTOR__

#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include<string>
#include <iterator>


template<class T>
class Vector_
{
	size_t size;
	T* _Arr;
public:
	Vector_();
	Vector_(size_t, T);
	Vector_(std::initializer_list<T>);
	Vector_(const Vector_&); //cpy c-tor
	Vector_(Vector_&&); //move c-tor
	~Vector_();

	[[nodiscard]] void push_back_(T);
	[[nodiscard]] size_t size_();
	[[nodiscard]] void clear_()noexcept;
	[[nodiscard]] bool empty_()noexcept;
	[[nodiscard]] T& at_(size_t);
	[[nodiscard]] T& front_();
	[[nodiscard]] T& back_();
	[[nodiscard]] bool find_(T);
	[[nodiscard]] void sort_();
	[[nodiscard]] bool insert_(size_t, T);
	[[nodiscard]] void pop_back_();
 	void contains();

	Vector_& operator=(const Vector_&);

	template<typename Y>
	friend std::ostream& operator<<(std::ostream&, const Vector_<Y>&);
};
#endif
