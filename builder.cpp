#include <iostream>
#include <string>
#include <map>
#include <boost/shared_ptr.hpp>

using std::cout;
using std::endl;

using namespace std;


class food{
	public:
		void setMilk(string milk){
			foods["milk"] = milk;
		}
		void setPlate(string plate){
			foods["plate"] = plate;

		}
		void setMeal(string meal){
			foods["meal"] = meal;
		}
		void getFoods(){
			for(auto it = foods.begin();it != foods.end();it++)
			{
				cout<<it->first<<":"<<it->second<<endl; 
			}
		}
	private:
		std::map<string,string> foods;
};

class builder{
	public:
		virtual void getMilk(string) = 0;
		virtual void getPlate(string) = 0;
		virtual void getMeal(string) = 0;
		void printBuilder(){fo.getFoods();}

	protected:
		food fo;

};

class adultBuilder:public builder{
	public:
		void getMilk(string milk){fo.setMilk("adult "+milk);}
		void getPlate(string plate){fo.setPlate("adult "+plate);}
		void getMeal(string meal){fo.setMeal("adult "+meal);}
};

class childBuilder:public builder{
	public:
		void getMilk(string milk){fo.setMilk("child "+milk);}
		void getPlate(string plate){fo.setPlate("child "+plate);}
		void getMeal(string meal){fo.setMeal("child "+meal);}
};


class cook{
	public:
		void setBuilder(boost::shared_ptr<builder> b){_b = b;}
		void construct(string plate,string milk,string meal){
			_b->getMilk(milk);
			_b->getPlate(plate);
			_b->getMeal(meal);
		}
	private:
		boost::shared_ptr<builder> _b;
};


int main(){
	auto b = boost::shared_ptr<builder>(new adultBuilder());
	cook c;
	c.setBuilder(b);
	c.construct("white plate", "fuck milk", "roat meal");
	b->printBuilder();
}