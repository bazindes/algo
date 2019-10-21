cxx_test(
  name = 'algo',
  srcs = glob(['src/**/*.cpp']),
  deps = glob(['external/googletest:gtest']),
  headers = subdir_glob([('include', '**/*.h')]),
  compiler_flags = [
  '-Wall', '-std=c++17'
  ],
)