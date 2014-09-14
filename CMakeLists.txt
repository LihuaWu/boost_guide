project(boost_learn)
cmake_minimum_required(VERSION 2.6)

message("create timer binary")
add_executable(timer timer.cc)

include_directories(/opt/local/include)

find_library(BOOST_DATE names boost_date_time-mt paths /opt/local/lib)
if(BOOST_DATE)
	message("found lib" ${BOOST_DATE})
	target_link_libraries(timer  ${BOOST_DATE})
endif(BOOST_DATE)

install (TARGETS timer DESTINATION /Users/will/cpp/bin)
