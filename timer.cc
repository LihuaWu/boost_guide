#include <boost/timer.hpp>
#include <boost/progress.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <assert.h>

using namespace boost;
using namespace boost::gregorian;
using namespace boost::posix_time;

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ofstream;
using std::string;

int main() {
	//timer t;	
	//progress_timer m;
	//std::cout<<"max timespan:"<<t.elapsed_max()<<std::endl;

	//ofstream fs("test.in");
	//string s("ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss");
	//vector<string> v(100*100*100, s);
	//progress_display pd(v.size());
	//vector<string>::iterator pos;
	//for(pos = v.begin();  pos != v.end(); ++pos) {
	//	fs<< *pos << endl;
	//	++pd;
	//}
	//date d1;
	//date d2(2010, 1, 1);
	//date d3(2000, Jan, 1);
	//date d4(d2);
	//assert(d1 == date(not_a_date_time));
	//assert(d2 == d4);
	//assert(d3 < d4);

	//date d1 = from_string("1999-12-31");
	//date d2(from_string("2005/1/1"));
	//date d3 = from_undelimited_string("20011118");
	//assert(d2 < d3);
	//date d1(neg_infin);
	//date d2(pos_infin);
	//date d3(not_a_date_time);
	//date d4(max_date_time);
	//date d5(min_date_time);	
	//cout<<d1<<endl;
	//cout<<d2<<endl;
	//cout<<d3<<endl;
	//cout<<d4<<endl;
	//cout<<d5<<endl;
	//cout<<day_clock::local_day()<<endl;
	//cout<<day_clock::universal_day()<<endl;
	//date d(1499, 12, 1);
	//assert(d.year() == 1499);
	//assert(d.month() == 12);
	//assert(d.day() == 1);
	//assert(d.day_of_week() == 5);
	//assert(date(pos_infin).is_pos_infinity());

	//date d(2008,11, 20);

	//cout<<to_simple_string(d)<<endl;
	//cout<<to_iso_string(d)<<endl;
	//cout<<to_iso_extended_string(d)<<endl;
	//cout<<d<<endl;

	//cin >>d;
	//cout<<d<<endl;

	//weeks w(3);
	//assert(w.days() == 21);

	//date d(2006, 11, 26);

	//day_iterator d_iter(d);
	//for(int i = 0; i < 10; ++i) {
	//	cout<<to_iso_string(*d_iter)<<"\t";
	//	++d_iter;
	//}
	//cout<<endl;

	ptime p(date(2010, 3, 5), hours(1));
	cout<<p<<endl;

	time_duration td = hours(1);
	time_duration td1(1, 10, 30, 1000);

	cout<<to_simple_string(td)<<endl;
	cout<<to_simple_string(td1)<<endl;

	return 0;
}
