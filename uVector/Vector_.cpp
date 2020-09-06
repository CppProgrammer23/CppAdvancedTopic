#include "Vector_.h"

template<class T>
Vector_<T>::Vector_()
	:size(0)
{
	_Arr = new T[size];
}
template<class T>
Vector_<T>::Vector_(size_t s, T fillw)
{
	size = s;
	_Arr = new T[size];
	for (int i = 0; i < s; i++)
		_Arr[i] = fillw;
}
template<class T>
Vector_<T>::Vector_(std::initializer_list<T> l)
{
	size =  l.size();
	_Arr = new T[size];
	auto j = 0;
	for (auto i : l)
	{
		_Arr[j] = i;
		j++;
	}
}
template<class T>
Vector_<T>::Vector_(const Vector_& v)
{
	size = v.size;
	_Arr = new T[size];
	for (int i = 0; i < size; i++)
		_Arr[i] = v._Arr[i];
}
template<class T>
Vector_<T>::Vector_(Vector_&& v)
{
	size = v.size;
	_Arr = new T[size];
	for (int i = 0; i < size; i++)
		_Arr[i] = v._Arr[i];
	v.clear_();
}
template<class T>
Vector_<T>::~Vector_()
{
	delete[]_Arr;
}
template<class T>
[[nodiscard]] void Vector_<T>::push_back_(T _Elem)
{
	size += 1;
	T* newArr = new T[size];
	std::copy(_Arr, _Arr + (size - 1), newArr);
	delete[]_Arr;
	_Arr = new T[size];
	for (int i = 0; i < size - 1; i++)
		_Arr[i] = newArr[i];
	delete[]newArr;
	_Arr[size - 1] = _Elem;
}
template<class T>
[[nodiscard]] size_t Vector_<T>::size_()
{
	return size;
}
template<class T>
[[nodiscard]] void Vector_<T>::clear_()noexcept
{
	size = 0;
	delete[]_Arr;
	_Arr = new T[size];
}
template<class T>
[[nodiscard]] bool Vector_<T>::empty_()noexcept
{
	if (size == 0)
		return true;
	return false;
}
template<class T>
[[nodiscard]] T& Vector_<T>::at_(size_t _Elem)
{
	try
	{
		if (_Elem >= size)
			throw ("Out of range");
	}
	catch (const char* e) { std::cout << e; }
	return _Arr[_Elem];
}
template<class T>
[[nodiscard]] T& Vector_<T>::front_()
{
	if (!empty_())
		return _Arr[0];
}
template<class T>
[[nodiscard]] T& Vector_<T>::back_()
{
	if (!empty_())
		return _Arr[size-1];
}
template<class T>
[[nodiscard]] bool Vector_<T>::find_(T _Elem)
{
	/*Binary search*/
	if (!empty_())
	{
		/*here I used unsigned char because every variable is positif and I suppose that I won't depass 255 values stored in the array.
		But you can change it if necessary*/
		unsigned char low = 0;
		unsigned char high = size;
		unsigned char mid = low + (high - low) / 2;
		while (low <= high)
		{
			if (_Arr[mid] < _Elem)
			{
				low = mid + 1;
				mid = low + (high - low) / 2;
			}
			else if (_Arr[mid] > _Elem)
			{
				high = mid - 1;
				mid = low + (high - low) / 2;
			}
			else
				return true;
		}
		return false;
	}
	else
		return false;
}
template<class T>
[[nodiscard]] void Vector_<T>::sort_()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (_Arr[i] < _Arr[j])
				std::swap(_Arr[i], _Arr[j]);
		}
	}
}
template<class T>
[[nodiscard]] bool Vector_<T>::insert_(size_t _Where, T _Elem)
{
	if (_Where >= size)
		return false;
	size++;
	T* newArr = new T[size];
	std::copy(_Arr, _Arr + (size - 1), newArr);
	delete[]_Arr;
	_Arr = new T[size];
	size_t i = 0;
	while (i < _Where)
	{
		_Arr[i] = newArr[i];
		i++;
	}
	i = size - 1;
	while (i > _Where)
	{
		_Arr[i] = newArr[i-1];
		i--;
	}
	_Arr[i] = _Elem;
	delete[]newArr;
	return true;
}
template<class T>
[[nodiscard]] void Vector_<T>::pop_back_()
{
	size--;
	T* newArr = new T[size];
	std::copy(_Arr, _Arr + size , newArr);
	delete[] _Arr;
	_Arr = new T[size];
	for (int i = 0; i < size ; i++)
		_Arr[i] = newArr[i];
	delete[]newArr;
}
template<class T>
Vector_<T>& Vector_<T>::operator=(const Vector_<T>& v)
{
	size = v.size;
	delete[]_Arr;
	_Arr = new T[size];
	for (int i = 0; i < size; i++)
		_Arr[i] = v._Arr[i];
	return *this;
}


template<class T>
void Vector_<T>::contains()
{
	for (int i = 0; i < size; i++)
		std::cout << _Arr[i] << " ";
	std::cout << '\n';
}

template class Vector_<int>;
template class Vector_<long int>;
template class Vector_<unsigned int>;
template class Vector_<short>;
template class Vector_<unsigned short>;
template class Vector_<std::string>;
template class Vector_<double>;
template class Vector_<float>;
template class Vector_<char>;
template class Vector_<unsigned char>;
template class Vector_<const char*>;
