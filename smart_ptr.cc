#include <boost/smart_ptr.hpp>
#include "fwd.h"

using namespace boost;

struct PosixFile {
	PosixFile(const char* file_name){
		printf("open file: %s\n", file_name);
	}
	~PosixFile() {
		printf("close file\n");
	}
};

int main() {
	shared_ptr<int> spi(new int);
	assert(spi);
	*spi = 253;
	printf("spi: %d %ld\n", *spi, spi.use_count());

	shared_ptr<string> sps(new string("smart"));
	printf("sps %s %lu\n", sps->c_str(), sps->size());

	return 0;
}
int scoped_ptr_f() {
	scoped_ptr<string> sp(new string("text"));
	cout<< *sp << endl;
	cout<<sp->size()<<endl;
	if (sp) {
		*sp =  string("hello");
		cout<< *sp << endl;
	}
	sp.reset();
	assert(sp == 0);
	if (!sp) {
		printf("scoped ptr == NULL\n");
	}
	scoped_ptr<PosixFile> fp(new PosixFile("./tex.txt"));
	return 0;
}

