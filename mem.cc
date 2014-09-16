#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/pool/pool.hpp>

#include <algorithm>

#include "fwd.h"

using namespace boost;

struct File {
	File(const char* file_name) {
		cout<<"open file:"<<file_name<<endl;
	}
	~File() {
		cout<<"close file" <<endl;
	}
};

class Shared{
private:
	shared_ptr<int> p;
public:
	Shared(shared_ptr<int> pp) : p(pp) {}
	void print() {
		cout << "count:" << p.use_count() << "v = " << *p <<endl;
	}
};

void print_func(shared_ptr<int> p) {
	cout << "count:" << p.use_count() << "v = " << *p <<endl;
}

class self_shared : public enable_shared_from_this<self_shared> {
public:
	self_shared(int n): x(n) {}
	int x;
	void print() {
		cout << "self_shared:" << x << endl;
	}
};

class abstract {
public:
	virtual void f() = 0;
	virtual void g() = 0;
protected:
	virtual ~abstract() {}
};

class impl: public abstract {
public:
	virtual void f() {
		cout << "class impl f" << endl;
	}
	virtual void g() {
		cout << "class impl g" << endl;
	}
};

shared_ptr<abstract> create() {
	return shared_ptr<abstract>(new impl);
}

class socket_t {};
socket_t* open_socket() {
	cout << "open socket" << endl;
	return new socket_t;
}
void close_socket(socket_t *s) {
	cout << "closing socket" << endl;
	delete s;
}

int main() {
	//scoped ptr usage
	//scoped_ptr<File> fp(new File("./mem.cc"));

	//scoped_ptr<string> sp(new string("text"));
	//cout<<*sp<<endl;

	//scoped_ptr<int> p;
	//cout<<p<<endl;

	//cout<<sp->size()<<endl;

	//using std::auto_ptr;
	//auto_ptr<int> ap(new int(10));
	//scoped_ptr<int> spi(ap);
	//assert(ap.get() == 0);

	//ap.reset(new int(20));
	//cout<<*ap << "," << *spi <<endl;
	//cout<<ap.get()<<endl;

	//scoped_array<int> sa(new int[100]);
	//sa[0] = 10;

	//std::fill_n(&sa[0], 100, 5);
	//for(int i = 0; i < 100; ++i) {
	//	cout << sa[i] << "\t";	
	//}
	//cout<<endl;

//	shared_ptr<int> spi(new int);
//
//	assert(spi);
//	*spi = 253;
//
//	shared_ptr<string> sps(new string("smart"));
//	assert(sps->size() == 5);
//
//	typedef shared_ptr<string> sp_t;
//	map<sp_t, int> m;
//	sp_t sp(new string("one"));
//	m[sp] = 111;
//	cout<<m[sp]<<endl;

//	shared_ptr<int> sp(new int(10));
//
//	assert(sp.unique());
//
//	shared_ptr<int> sp2 = sp;
//	cout << sp.use_count()  <<" " << sp2.use_count() <<endl;
//
//	assert(sp == sp2);
//
//	*sp2 = 100;
//	assert(*sp == 100);
//	sp.reset();
//	assert(!sp);
//	assert(sp2.unique());

//	shared_ptr<int> p(new int(100));
//
//	Shared s1(p), s2(p);
//
//	s1.print();
//	s2.print();
//
//	*p = 20;
//
//	print_func(p);
//	s1.print();

	//shared_ptr<string> sp = make_shared<string>("make shared");
	//shared_ptr<vector<int> > spv = make_shared<vector<int> >(10, 2);
	//assert(spv->size() == 10);
	//cout<<*sp<<endl;

	//shared_ptr<abstract> p = create();
	//p->f();
	//p->g();

	//even get raw pointer, q can not be deleted, sinice destructor can only be called by the class and its sub-classes.
	//abstract *q = p.get();
	//cout<<q<<endl;
	//delete q;

//	shared_ptr<socket_t> p(open_socket(), close_socket);

	//shared_ptr<int> sp(new int(10));
	//assert(sp.use_count() == 1);

	//weak_ptr<int> wp(sp);
	//assert(wp.use_count() == 1);

	//if(!wp.expired()) {
	//	shared_ptr<int> sp2 = wp.lock();
	//	*sp2 = 100;
	//	assert(wp.use_count() == 2);
	//}
	//assert(wp.use_count() == 1);
	//sp.reset();
	//assert(wp.expired());
	//assert(!wp.lock());
	//shared_ptr<self_shared> sp = make_shared<self_shared>(314);
	//sp->print();
	//assert(sp.use_count() == 1);

	//shared_ptr<self_shared> p = sp->shared_from_this();
	//assert(sp.use_count() == 2);
	//p->x = 1000;
	//p->print();
	return 0;
}
