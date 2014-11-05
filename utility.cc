#include <boost/noncopyable.hpp>
#include <boost/utility.hpp>
#include <boost/operators.hpp>
#include <boost/assign.hpp>
#include <boost/exception/all.hpp>

#include "fwd.h"

using namespace boost;
using namespace boost::assign;

struct my_exception: 
	virtual std::exception,
	virtual boost::exception {};

typedef boost::error_info<struct tag_err_no, int> err_no;
typedef boost::error_info<struct tag_err_str, string> err_str;

int main() {

try {
	try {
		throw my_exception() << err_no(10);	
	} catch (my_exception& e) {
		printf("%d\n", *get_error_info<err_no>(e));
		printf("%s\n", e.what());
		e << err_str("other info");
		throw;
	}
}catch (my_exception& e) {
	printf("%s\n", get_error_info<err_str>(e)->c_str());
}
	return 0;
}

class empty_class {
public:
	empty_class() {}
	empty_class (const empty_class &) {}
	//empty_class & operator=(const empty_class &) {}
};

class do_not_copy : boost::noncopyable {
};

class demo {
public:
	demo(int n): x(n) {}
	int x;
	friend bool operator<(const demo& l, const demo& r){
		return l.x < r.x;
	}

	friend bool operator==(const demo& l, const demo& r) {
		return l.x == r.x;
	}
};

//class point : boost::less_than_comparable<point> 
//	,boost::equality_comparable<point>{
class point : totally_ordered<point, additive<point> >{
private:
	int x, y, z;
public:
	explicit point(int a = 0, int b = 0, int c = 0): x(a), y(b), z(c){}
	void print() const {
		printf("%d, %d, %d\n", x, y, z);
	}

	friend bool operator<(const point& l, const point& r) {
		return l.x < r.x;
	}

	friend bool operator==(const point& l, const point& r) {
		return l.x == r.x;
	}

	point& operator+=(const point& r) {
		x += r.x;	
		y += r.y;
		z += r.z;
		return *this;
	}

	point& operator-=(const point& r) {
		x -= r.x;
		y -= r.y;
		z -= r.z;
		return *this;
	}
};

int operator_f() {
	demo a(10), b(20);

	printf("a < b is : %d\n", a<b);

	printf("b >= a is: %d\n", b >= a);

	printf("a > b is: %d\n", a > b);

	printf("a = b is: %d\n", a == b);

	point p0, p1(1,2,3), p2(3, 0, 5), p3(3, 2, 1);

	vector<point> v = (list_of(p0), p1, p2, p3);

	auto pos = std::find(v.begin(), v.end(), point(1,2,3));
	printf("find it\n");
	pos->print();
	printf("--------------------\n");

	assert(p0 < p1);
	//assert(p0 > p1);
	assert(p2 >= p3);
	assert(p2 == p3);
	assert(p1 != p3);
	//assert(p1 == p3);

	p1.print();
	p2.print();
	(p1 + p2).print();
	p3.print();
	p1.print();
	(p3 - p1).print();

	printf("p2 - p2 is p0\n");
	assert((p2 - p2) == p0);
	return 0;
}

int noncopyable_f () {
	empty_class e1;
	empty_class e2(e1);

	do_not_copy d1;
//	do_not_copy d2(d1);
//	do_not_copy d3; 
//	d3 = d1;
	return 0;
}
