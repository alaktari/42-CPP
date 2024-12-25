// multilevel class

#include <iostream>
#include <string>

using namespace std;

class R
{
	private:
		char r;
	public:
		R(char r) : r(r) {};
		void print_r(void) { cout << "R: " << (int)r; }
		int get_r(void) {  return (int)r; }
};

class RG : public R
{
	private:
		char g;
	public:
		RG(char r, char g) : R(r), g(g) {};
		void	print_rg(void) { print_r(); cout << ", G: " << (int)g; }
		int	get_g(void) { return (int)g; }
};

class RGB : public RG
{
	private:
		char b;
	public:
		RGB(char r, char g, char b) : RG(r, g), b(b) {};
		void print_rgb(void)	{ print_rg(); cout << ", b: " << (int)b << "\n"; }
		int	get_b(void) { return (int)b; }
};

class Color : public RGB
{
	private:
		int color;
	public:
		Color(char r, char g, char b) : RGB(r, g, b) {};
		void print_color(void)
		{
			color = (int)get_r();
			color <<= 8;
			color |= (int)get_g();
			color <<= 8;
			color |= (int)get_b();
			cout << "color ==> " << color << "\n";
		}
};

int main()
{
	int r = 23;
	int g = 89;
	int b = 122;

	Color color(r, g, b);
	color.print_rgb();
	color.print_color();

}