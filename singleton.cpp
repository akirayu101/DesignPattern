#include <iostream>
#include <boost/shared_ptr.hpp>


template<typename T>
class singleton{

public:

	static boost::shared_ptr<T> getInstance()
	{
		if (singleton::instance == 0){
				//here we need mutex and check(double check)
			singleton::instance = boost::shared_ptr<T>(new T());
		}
		return singleton::instance;
	}

	static void setVal(T val){
		*singleton::instance = val;
	}


private:
	singleton(T param)
	{
		_para = param;
	}
	singleton()
	{

	}
	T _para;

	static boost::shared_ptr<T> instance;


};


template<typename T>
boost::shared_ptr<T> singleton<T>::instance = singleton::getInstance();


int main(){

	auto s = singleton<int>::getInstance();
	singleton<int>::setVal(10);
	std::cout<<*s<<std::endl;
}


