#include <vector>
#include <iostream>
#include <boost/shared_ptr.hpp>

using std::cout;
using std::endl;


enum bird_type{
	FlappyBird,
	AngryBird,
	MyBird,
};
class bird{
public:
	virtual void sing() = 0;
	static boost::shared_ptr<bird> genBird(bird_type i);
};


class flappybird:public bird{
	public:
		void sing(){cout<<"flappybird"<<endl;}

};


class angrybird:public bird{
	public:
		void sing(){cout<<"angrybird"<<endl;}

};


class mybird:public bird{
	public:
		void sing(){cout<<"mybird"<<endl;}

};


boost::shared_ptr<bird> bird::genBird(bird_type i){
	switch(i){
		case FlappyBird:
			return boost::shared_ptr<bird>(new flappybird());
			break;
		case AngryBird:
			return boost::shared_ptr<bird>(new angrybird());
			break;
		case MyBird:
			return boost::shared_ptr<bird>(new mybird());
			break;
		
	}

}


int main(){
	auto b = bird::genBird(FlappyBird);
	b->sing();
}