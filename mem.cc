#include <boost/smart_ptr.hpp>
#include "fwd.h"

using namespace boost;

int main() {
	//scoped ptr usage
	scoped_ptr<string> sp(new string("text"));
	cout<<*sp<<endl;

	scoped_ptr<int> p;
	cout<<p<<endl;

	return 0;
}
