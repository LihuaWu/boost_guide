#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

#include "fwd.h"

using namespace boost;

int main() {
	
	cout<< format("%s:%d+%d=%d\n") % "sum" % 1 % 2 % (1 + 2);

	format fmt("(%1% + %2%) + %2% = %3%\n ");
	fmt % 2 % 5;
	fmt % ((2+5)*5);

	cout << fmt.str();

	return 0;
}

class demo {
	friend std::ostream&  operator<<(std::ostream& os, const demo& x){
		os << "demo class's name";
		return os;
	}
};

template <typename T>
struct outable {
	friend std::ostream& operator<<(std::ostream& os, const T& x) {
		os << typeid(T).name();
		return os;
	}
};

class demo1 : outable<demo1> {};
int lexical_cast_f() {
	int x = lexical_cast<int>("1000");
	printf("x is : %d, %lu\n", x, sizeof(x));

	long y = lexical_cast<long>(20000);
	printf("y is : %ld, %lu\n", y, sizeof(y));

	float pi = lexical_cast<float>("3.14159e5");
	printf("pi is : %f, %lu\n", pi, sizeof(pi));

	string s = lexical_cast<string>(456);
	printf("s is : %s\n", s.c_str());
	printf("s is: %s\n", lexical_cast<string>(0.618).c_str());
	printf("s is: %s\n", lexical_cast<string>(0x10).c_str());

	//lexical_cast<int>("0x1000");
	//lexical_cast<double>("HelloWorld");

	printf("demo is : %s\n", lexical_cast<string>(demo()).c_str());

	printf("class is: %s\n", lexical_cast<string>(demo1()).c_str());
	return 0;
}
