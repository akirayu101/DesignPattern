#include <iostream>


using std::cout;
using std::endl;

class rectangle{
public:
	virtual void draw() const = 0;
};


class render_rectangle{
public:
	render_rectangle(int width, int height):_width(width),_height(height){}

	void render() const{cout<<"width:"<<_width<<"\nheight:"<<_height<<endl; }

private:
	int _width;
	int _height;

};


class render_adapter: public rectangle, private render_rectangle{
public:
	render_adapter(int width, int height):render_rectangle(width,height){}
	void draw() const{render();}
};


int main()
{
	auto rec = render_adapter(10,15);
	rec.draw();
}