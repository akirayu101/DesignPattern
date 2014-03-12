#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>

class shape{
	public:
		shape(){id = total++;}
		virtual void draw() = 0;
	protected:
		int id;
		static int total;
};

class rectangle: public shape{
	public:
		void draw(){std::cout<<"rectangle "<<id<<std::endl;}
};

class eclipse: public shape{
	public:
		void draw(){std::cout<<"eclipse "<<id<<std::endl;}
};

class circle: public shape{
	public:
		void draw(){std::cout<<"circle "<<id<<std::endl;}
};


class factory{
	public:
		virtual boost::shared_ptr<shape> getShapeOne() = 0;
		virtual boost::shared_ptr<shape> getShapeTwo() = 0;

};


class FactoryOne:public factory{
	public:

		boost::shared_ptr<shape> getShapeOne(){return boost::shared_ptr<shape>(new rectangle());}
		boost::shared_ptr<shape> getShapeTwo(){return boost::shared_ptr<shape>(new circle());}


};


class FactoryTwo:public factory{
	public:
		boost::shared_ptr<shape> getShapeOne(){return boost::shared_ptr<shape>(new eclipse());}
		boost::shared_ptr<shape> getShapeTwo(){return boost::shared_ptr<shape>(new circle());}

};


int shape::total = 0;

int main(){
	boost::shared_ptr<factory> fac = boost::shared_ptr<factory>(new FactoryOne());
	boost::shared_ptr<shape> sh[2] = {fac->getShapeOne(),fac->getShapeTwo()};

	for(int i = 0;i<2;i++){
		sh[i]->draw();

	}
}

