#include <boost/timer.hpp>
#include <boost/progress.hpp>

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace boost;
using std::cout;
using std::endl;
using std::vector;
using std::ofstream;
using std::string;

int main() {
	//timer t;	
	//progress_timer m;
	//std::cout<<"max timespan:"<<t.elapsed_max()<<std::endl;

	ofstream fs("test.in");
	string s("ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss");
	vector<string> v(100*100*100, s);
	progress_display pd(v.size());
	vector<string>::iterator pos;
	for(pos = v.begin();  pos != v.end(); ++pos) {
		fs<< *pos << endl;
		++pd;
	}
	return 0;
}
