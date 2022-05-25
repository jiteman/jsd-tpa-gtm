cmake_minimum_required( VERSION 3.16.3 )

project( jsd-tpa-gtm-test-lib C CXX )


JSD_SHOW_PROJECT_HEADER()


include( ${JSD_SSC_CMAKE_PATH}/tpa-gtm-test-lib-set-compiler-settings.cmake )
set( JSD_THIS_PROJECT_SOURCE_PATH ${JSD_SSC_SOURCE_PATH}/tpa_gtm_test )


## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JSD_PLATFORM_SOURCES}
	${jsd-tpa-gtm_DEPENDENCY_DIRS}
	${JSD_THIS_PROJECT_SOURCE_PATH} )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR )
include_directories( ${${PROJECT_NAME}_DEPENDENCY_DIRS_VAR} )


## this project headers and sources enumeration section
foreach( source_directory ${jsd-tpc-googletestmock_TEST_SOURCE_DIRS} )
	include_directories( ${source_directory}/.. )
	list( APPEND test_header_and_source_files ${source_directory}/*.h* )
	list( APPEND test_header_and_source_files ${source_directory}/*.c* )
endforeach()

file( GLOB_RECURSE header_and_source_files
	${JSD_THIS_PROJECT_SOURCE_PATH}/*.h*
	${JSD_THIS_PROJECT_SOURCE_PATH}/*.c*
	${test_header_and_source_files} )

set( JSD_THIS_PROJECT_FILES_TO_REMOVE
	"gtest_all_test.cc"
	"gtest-unittest-api_test.cc"
	"gtest_assert_by_exception_test.cc"
	"gtest_environment_test.cc"
	"gtest_list_output_unittest_.cc"
	"gtest_no_test_unittest.cc"
	"gtest_premature_exit_test.cc"
	"gtest_repeat_test.cc"
	"gtest_skip_in_environment_setup_test.cc"
	"gtest_stress_test.cc"
	"gtest_test_macro_stack_footprint_test.cc"
	"gtest_throw_on_failure_ex_test.cc"
	"gtest_xml_output_unittest_.cc"
	"googletest-break-on-failure-unittest_.cc"
	"googletest-catch-exceptions-test_.cc"
	"googletest-color-test_.cc"
	"googletest-death-test-test.cc"
	"googletest-env-var-test_.cc"
	"googletest-filter-unittest_.cc"
	"googletest-global-environment-unittest_.cc"
	"googletest-list-tests-unittest_.cc"
	"googletest-listener-test.cc"
	"googletest-output-test_.cc"
	"googletest-param-test-invalid-name1-test_.cc"
	"googletest-param-test-invalid-name2-test_.cc"
	"googletest-param-test-test.cc"
	"googletest-shuffle-test_.cc"
	"googletest-throw-on-failure-test_.cc"
	"googletest-uninitialized-test_.cc"
	"gmock_all_test.cc"
	"googletest-death-test_ex_test.cc"
	"gmock_leak_test_.cc"
	"gmock_link_test.h"
	"gmock_link_test.cc"
	"gmock_link2_test.cc"
	"gmock-spec-builders_test.cc"
	"gmock_output_test_.cc"
	"gmock_stress_test.cc" )
JSD_REMOVE_FILES_FROM_THE_LIST( header_and_source_files JSD_THIS_PROJECT_FILES_TO_REMOVE )

add_library( ${PROJECT_NAME} SHARED ${header_and_source_files} )


## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	${jsd-tpa-gtm_LINK_DEFINITIONS}
	-DJSD_TPA_GTM_TEST_SHARED_INTERFACE_INTERNAL )
JSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	${jsd-tpa-gtm_LINK_DEFINITIONS} )
JSD_LIST_TO_STRING( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
JSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
add_definitions( "${${PROJECT_NAME}_BUILD_DEFINITIONS_VAR}" )


## required to be able to be linked into shared libraries.
set_target_properties( ${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION 0.1.0 )
set_target_properties( ${PROJECT_NAME} PROPERTIES SOVERSION 0.1 )


## project target section
set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
	${jsd-tpa-gtm_DEPENDENCY_LIBS}
	jsd-tpa-gtm )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} )


## Expose public includes to other subprojects through cache variable.
include( ${JSD_CMAKE_PATH}/set-expose-dependencies.cmake )
JSD_SHOW_PROJECT_FOOTER()
