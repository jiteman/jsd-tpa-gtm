#pragma once


#include "jsd/platform_support/common_shared_library_support.h"


#if defined( JSD_TPA_GTM_SHARED_INTERFACE_INTERNAL )
	#define JSD_TPA_GTM_SHARED_INTERFACE		JSD_SHARED_EXPORT_CONVENTION

#else
	#define JSD_TPA_GTM_SHARED_INTERFACE		JSD_SHARED_IMPORT_CONVENTION

#endif
