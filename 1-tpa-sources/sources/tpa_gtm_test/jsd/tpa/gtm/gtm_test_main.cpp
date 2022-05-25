#include "gtm_test_main.h"

#include "jsd/tpa/gtm/gtm_main.h"


namespace jsd {
namespace tpa {
namespace gtm {


int run_all_gtm_tests( int argc, char const *const argv[] ) {
	return gmock_main( argc, argv, false );
}


} // namespace gtm
} // namespace tpa
} // namespace jsd
