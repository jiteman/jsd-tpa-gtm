cmake_minimum_required( VERSION 3.16.3 )

project( jsd-tpa-gtm )


JSD_SHOW_PROJECT_GROUP_HEADER()


set( JSD_SSC_CMAKE_PATH ${PROJECT_SOURCE_DIR}/0-tpa-cmake )
set( JSD_SSC_SOURCE_PATH ${PROJECT_SOURCE_DIR}/1-tpa-sources/sources )


add_subdirectory( 2-tpa-gtm-lib )

# tests
#add_subdirectory( tpa_gtm_test_lib )
#add_subdirectory( tpa_gtm_tests )
#~tests


JSD_SHOW_PROJECT_GROUP_FOOTER()
