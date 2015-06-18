option(BUILD_STATIC
    "Link statically against most libraries, if possible" OFF)

include(common-sense)

if(BUILD_STATIC)
	AddCompileFlags("-static-libgcc -static-libstdc++")
endif()
