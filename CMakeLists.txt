project(boost_learn)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_C_FLAGS "-std=c++0x")

message("create timer binary")
add_executable(timer timer.cc)

message("create mem binary")
add_executable(mem  mem.cc)

message("create utility binary")
add_executable(utility utility.cc)

message("create smart_ptr binary")
add_executable(spt smart_ptr.cc)

message("create string_algorithm binary")
add_executable(stralgo str_algo.cc)

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
	target_link_libraries(spt ${BOOST_SYSTEM})
else(BOOST_SYSTEM)
	message("not found lib " ${BOOST_SYSTEM})
endif(BOOST_SYSTEM)

install (TARGETS timer DESTINATION /Users/will/cpp/bin)
install (TARGETS mem DESTINATION /Users/will/cpp/bin)
install (TARGETS utility DESTINATION /Users/will/cpp/bin)
install (TARGETS spt DESTINATION /Users/will/cpp/bin)

install (TARGETS stralgo DESTINATION /Users/will/cpp/bin)
