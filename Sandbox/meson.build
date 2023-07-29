#cc = meson.get_compiler('cpp')
#lib_vl = cc.find_library('vectorlab')

source_root = meson.source_root()
include_directories = [
    '../VectorLab/src', 
    '../VectorLab/src/Core'
]

deps = [dependency('SDL2'), dependency('spdlog'), dependency('fmt')]

executable('sandbox-app', 
    'src/SandboxApp.cpp', 
    include_directories : include_directories,
    cpp_pch : source_root + '/VectorLab/src/PCH.h',
    dependencies : deps,
    link_with : lib_vl,
    link_args : '-DVL_PLATFORM_LINUX, -Wwrite-strings',
    install : true
)