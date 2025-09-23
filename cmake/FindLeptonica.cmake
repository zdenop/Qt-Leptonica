# - Try to find Leptonica
# Once done this will define
#
#  LEPTONICA_FOUND - system has Leptonica
#  LEPTONICA_INCLUDE_DIRS - the Leptonica include directories
#  LEPTONICA_LIBRARIES - The libraries needed to use Leptonica

find_path(LEPTONICA_INCLUDE_DIR leptonica/allheaders.h)

find_library(LEPTONICA_LIBRARY NAMES lept)

set(LEPTONICA_INCLUDE_DIRS ${LEPTONICA_INCLUDE_DIR})
set(LEPTONICA_LIBRARIES ${LEPTONICA_LIBRARY})

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LEPTONICA_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(Leptonica DEFAULT_MSG
                                  LEPTONICA_LIBRARY LEPTONICA_INCLUDE_DIR)

mark_as_advanced(LEPTONICA_INCLUDE_DIR LEPTONICA_LIBRARY)
