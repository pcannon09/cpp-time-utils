#pragma once

#include "macros.hpp"

// Versioning
#define STT_VERSION_MAJOR          1
#define STT_VERSION_MINOR          0
#define STT_VERSION_PATCH          0

// Version states:
// dev - develoment (Before Beta version)
// beta - Beta (Testing)
// snap - Snapshot (Future update)
// build - Built version
#define STT_VERSION_STATE          "build"

#define STT_VERSION                ((STT_VERSION_MAJOR<<16)|(STT_VERSION_MINOR<<8)|(STT_VERSION_PATCH)|(STT_VERSION_STATE << 24))

#define STT_VERSION_CHECK(STT_VERSION_MAJOR, STT_VERSION_MINOR, STT_VERSION_PATCH, STT_VERSION_STATE) \
    ((STT_VERSION_MAJOR<<16)|(STT_VERSION_MINOR<<8)|(STT_VERSION_PATCH)|(STT_VERSION_STATE << 24))

