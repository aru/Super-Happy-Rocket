include(ExternalProject)

if (WIN32)
  # Get SDL2 Image dev package
  ExternalProject_Add(
    sdl2-image
    DEPENDS sdl2
    PREFIX ${DEPENDENCIES_ROOT}
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    URL https://libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.0-VC.zip
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND
      COMMAND ${CMAKE_COMMAND} -E copy_directory ${DEPENDENCIES_ROOT}/src/sdl2-image/lib ${DEPENDENCIES_ROOT}/lib
      COMMAND ${CMAKE_COMMAND} -E copy_directory ${DEPENDENCIES_ROOT}/src/sdl2-image/include ${DEPENDENCIES_ROOT}/include/SDL2
  )
else()
  # Build sdl2-image
  ExternalProject_Add(
    sdl2-image
    DEPENDS sdl2
    PREFIX ${DEPENDENCIES_ROOT}
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    URL https://libsdl.org/projects/SDL_image/release/SDL2_image-2.0.0.tar.gz
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${DEPENDENCIES_ROOT}
  )
endif()
