#include <iostream>
#include <boost/shared_ptr.hpp>

using std::endl;
using std::cout;
using boost::shared_ptr;


class soldierinterface{
public:
	virtual void move(int preposx, int preposy, int posx, int posy)=0;
	virtual ~soldierinterface(){};

};

class soldierimp:public soldierinterface{

public:
	void move(int preposx, int preposy, int posx, int posy){}

private:
	int soldtexture;//represent real texture 

};

class soldierfactory{
public:
	static shared_ptr<soldierimp> getsoldier(){cout<<"get proto"<<endl;return _soldier_instance;};
private:
	static shared_ptr<soldierimp> _soldier_instance;
};

shared_ptr<soldierimp> soldierfactory::_soldier_instance = shared_ptr<soldierimp>(new soldierimp());

class soldierclient{
public:
	soldierclient(){
		_soldier = soldierfactory::getsoldier();
	}

	void move(int xpos, int ypos){
		_soldier->move(_xpos,_ypos,xpos,ypos);
		_xpos += xpos;
		_ypos += ypos;
	}

	void printpos(){
		cout<<"x:"<<_xpos<<endl;
		cout<<"y:"<<_ypos<<endl;

	}
private:
	int _xpos;
	int _ypos;
	shared_ptr<soldierimp> _soldier;

};


int main(){
	auto c = shared_ptr<soldierclient>(new soldierclient());
	c->move(10,10);
	c->printpos();

}
