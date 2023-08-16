runtime_sources = [
    'src/VectorLab.h',
    'src/Core/Base.h',
    'src/Core/Types.h',
    'src/Core/EntryPoint.h',
    'src/Core/Application.h', 'src/Core/Application.cpp',
    'src/Core/Log.h', 'src/Core/Log.cpp',
    'src/Core/Window.h', 'src/Core/Window.cpp'
]

include_directories = [
    'vendor/spdlog/include',
    'vendor/glad/include'
]

deps = [dependency('SDL2'), dependency('fmt')]

lib_vl = static_library('vectorlab', runtime_sources,
    include_directories : include_directories,
    dependencies : deps,
    link_args : '-DVL_PLATFORM_LINUX, -Wwrite-strings',
    install : false
)