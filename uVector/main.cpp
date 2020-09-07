#include "Vector_.h"


template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector_<T>& v)
{
	os << "[ ";
	for (auto i=0;i<v.size;i++)
		os << v._Arr[i] << " ";
	os << "]\n";
	return os;
}


int main()
{
	Vector_<int> myvec{ 1,8,6,7,3 };
	//Vector_<int> vec = std::move(myvec); // move c-tor
	Vector_<int> vec;
	vec = myvec; // copy assignment 
	std::cout << vec;
	vec.contains();
	myvec.contains();
	myvec.push_back_(12);
	myvec.contains();
	myvec.push_back_(15);
	myvec.push_back_(941);
	myvec.contains();
	//myvec.clear_();
	if (myvec.empty_() == true)
		std::cout << "Empty!\n";
	//myvec.contains();
	std::cout << myvec.at_(2) << '\n';
	std::cout << myvec.back_() << '\n';
	std::cout << myvec.front_() << '\n';
	myvec.sort_();
	myvec.contains();
	std::cout << std::boolalpha;
	std::cout << myvec.find_(3) << '\n';
	myvec.insert_(4, 25);
	myvec.contains();
	myvec.pop_back_();
	myvec.contains();

	Vector_<const char*> MyStr{ "Hello", "Ok" };
	MyStr.contains();
	MyStr.push_back_("Never mind");
	MyStr.contains();
	std::cout << MyStr.at_(2) << '\n';
	std::cout << MyStr.find_("Ok") << '\n';
	return 0;
}
