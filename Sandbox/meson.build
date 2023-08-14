#cc = meson.get_compiler('cpp')
#lib_vl = cc.find_library('vectorlab')

source_root = meson.source_root()
include_directories = [
    '../VectorLab/src', 
    '../VectorLab/src/Core'
]

executable('sandbox-app', 
    'src/SandboxApp.cpp', 
    include_directories : include_directories,
    cpp_pch : source_root + '/VectorLab/src/PCH.h',
    link_with : lib_vl,
    install : true
)