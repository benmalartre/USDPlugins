set(PXR_PREFIX pxr/usdImaging)
set(PXR_PACKAGE usdNprImaging)

usd_library(usdNprImaging
    LIBRARIES
        usd
        usdImaging
        usdNpr
        work

    PUBLIC_CLASSES
        utils
        mesh
        stroke
        contourAdapter
        tokens

    PUBLIC_HEADERS
        api.h

    RESOURCE_FILES
        plugInfo.json
)

