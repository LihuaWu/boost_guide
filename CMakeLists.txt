project(boost_learn)
cmake_minimum_required(VERSION 2.6)

message("create timer binary")
add_executable(timer timer.cc)

message("create mem binary")
add_executable(mem  mem.cc)

include_directories(/opt/local/include .)

find_library(BOOST_DATE names boost_date_time-mt  paths /opt/local/lib)

if(BOOST_DATE)
	message("found lib " ${BOOST_DATE})
	target_link_libraries(timer  ${BOOST_DATE})
endif(BOOST_DATE)

find_library(BOOST_SYSTEM boost_system-mt  paths /opt/local/lib)

if(BOOST_SYSTEM)
	message("found lib " ${BOOST_SYSTEM})
	target_link_libraries(mem ${BOOST_SYSTEM})
else(BOOST_SYSTEM)
	message("not found lib " ${BOOST_SYSTEM})
endif(BOOST_SYSTEM)

install (TARGETS timer DESTINATION /Users/will/cpp/bin)
install (TARGETS mem DESTINATION /Users/will/cpp/bin)

