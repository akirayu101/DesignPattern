#include <iostream>
#include <boost/shared_ptr.hpp>

using std::cout;
using std::endl;
using boost::shared_ptr;


class person;

class state{
public:
	virtual void execute(person*) = 0;
	virtual ~state(){};
private:

};
class person{
public:
	explicit person(int tired):_tired(tired){};
	void update(){this->_state->execute(this);}
	void set_state(shared_ptr<state> state){this->_state = state;};
	int _tired;
private:
	shared_ptr<state> _state;

};


class workstate:public state{
public:
	void execute(person* p);

};



class reststate:public state{
public:
	void execute(person* p);

};

void workstate::execute(person* p){
	if (p->_tired > 15){
		p->set_state(shared_ptr<state>(new reststate()));
	} else{
		p->_tired += 1;
		cout<<"hey i am working"<<endl;
	}
}

void reststate::execute(person* p){
	if (p->_tired < 5){
		p->set_state(shared_ptr<state>(new workstate()));
	} else{
		p->_tired -= 1;
		cout<<"hey i am resting"<<endl;
	}
}


int main(int argc, char const *argv[])
{
	auto p = shared_ptr<person>(new person(0));
	p->set_state(shared_ptr<state>(new workstate()));
	for(int i = 0; i != 100; ++i){
		p->update();
	}
}
