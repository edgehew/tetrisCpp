
tetris_deps = [
  cxx.find_library('sfml-graphics'),
  cxx.find_library('sfml-window'),
  cxx.find_library('sfml-system'),
]

tetris_src = [
  'main.cpp',
]

executable(
  'tetris',
  tetris_src,
  dependencies: tetris_deps,
  install: true,
)
