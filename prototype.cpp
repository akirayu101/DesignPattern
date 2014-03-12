#include <iostream>
#include <map>
#include <string>
#include <boost/shared_ptr.hpp>


using std::cout;
using std::endl;
using std::map;
using std::string;


class bird{
public:
	virtual boost::shared_ptr<bird> clone() = 0;
	virtual void sing() = 0;

};


class flappybird : public bird{
public:
	boost::shared_ptr<bird> clone(){return boost::shared_ptr<bird>(new flappybird());};
	void sing(){cout<<"flappybird"<<endl;};
};

class angrybird : public bird{
public:
	boost::shared_ptr<bird> clone(){return boost::shared_ptr<bird>(new angrybird());};
	void sing(){cout<<"flappybird"<<endl;};
};

class mybird : public bird{
public:
	boost::shared_ptr<bird> clone(){return boost::shared_ptr<bird>(new mybird());};
	void sing(){cout<<"mybird"<<endl;};
};


class factory{
	public:
		static boost::shared_ptr<bird> genbird(string type);
		static void registerbird(string,boost::shared_ptr<bird>);
	private:
		static map<string,boost::shared_ptr<bird> > _bird_prototype;
};

map<string,boost::shared_ptr<bird> > factory::_bird_prototype;


boost::shared_ptr<bird> factory::genbird(string type)
{
	return factory::_bird_prototype[type];
}


void factory::registerbird(string type, boost::shared_ptr<bird> proto)
{
	factory::_bird_prototype[type] = proto;
}


int main(){
	factory::registerbird("flappybird", boost::shared_ptr<bird>(new flappybird())->clone());
	auto b = factory::genbird("flappybird");
	b->sing();


}