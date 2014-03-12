#include <iostream>
#include <boost/shared_ptr.hpp>

using std::cout;
using std::endl;
using boost::shared_ptr;


class attacker{
	public:
		attacker(int basic_attr):_basic_attr(basic_attr){}
		virtual void attack() const {cout<<"attack "<<_basic_attr<<" point"<<endl;};
		virtual ~attacker(){};
	protected:
		int _basic_attr;

};


class ride_attacker:public attacker{
	public:
		ride_attacker(int basic_attr, int bonus):attacker(basic_attr),_bonus(bonus){}
		void attack() const {cout<<"ride attack "<<_basic_attr+_bonus<<" point"<<endl;}
	private:
		int _bonus;
};


class magic_attacker:public attacker{
	public:
		magic_attacker(int basic_attr, int bonus):attacker(basic_attr),_bonus(bonus){}
		void attack() const {cout<<"magic attack "<<_basic_attr*_bonus<<" point"<<endl;}
	private:
		int _bonus;
};


class warrior{
	public:
		explicit warrior(int basic_attr){_attacker = shared_ptr<attacker>(new attacker(basic_attr));}
		void attack(){_attacker->attack();}
		virtual ~warrior(){};
	protected:
		shared_ptr<attacker> _attacker;

};


class mage:public warrior{
	public:
		mage(int basic_attr, int bonus):warrior(basic_attr){_attacker = shared_ptr<attacker>(new magic_attacker(basic_attr, bonus));}
};


int main()
{
	auto role = std::auto_ptr<warrior>(new mage(10,15));
	role->attack();
}