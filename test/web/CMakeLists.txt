SET(TEST_NAME cookie)
add_executable(${TEST_NAME} cookie.cpp)
target_link_libraries(${TEST_NAME} -lasan -lubsan)
target_link_libraries(${TEST_NAME} ${SYSLANDSCAPE_TMPL})
target_link_libraries(${TEST_NAME} ${SYSLANDSCAPE_UTIL})
target_link_libraries(${TEST_NAME} ${SYSLANDSCAPE_WEB})
target_link_libraries(${TEST_NAME} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(${TEST_NAME} gtest gtest_main)
add_test(${TEST_NAME} ${TEST_NAME})

SET(TEST_NAME web)
add_executable(${TEST_NAME} web.cpp)
target_link_libraries(${TEST_NAME} -lasan -lubsan)
target_link_libraries(${TEST_NAME} ${SYSLANDSCAPE_TMPL})
target_link_libraries(${TEST_NAME} ${SYSLANDSCAPE_UTIL})
target_link_libraries(${TEST_NAME} ${SYSLANDSCAPE_WEB})
target_link_libraries(${TEST_NAME} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(${TEST_NAME} ${OPENSSL_LIBRARIES})
target_link_libraries(${TEST_NAME} gtest gtest_main)
add_test(${TEST_NAME} ${TEST_NAME})

SET(TEST_NAME webpathsegment)
add_executable(${TEST_NAME} webpathsegment.cpp)
target_link_libraries(${TEST_NAME} -lasan -lubsan)
target_link_libraries(${TEST_NAME} ${SYSLANDSCAPE_TMPL})
target_link_libraries(${TEST_NAME} ${SYSLANDSCAPE_UTIL})
target_link_libraries(${TEST_NAME} ${SYSLANDSCAPE_WEB})
target_link_libraries(${TEST_NAME} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(${TEST_NAME} gtest gtest_main)
add_test(${TEST_NAME} ${TEST_NAME})
