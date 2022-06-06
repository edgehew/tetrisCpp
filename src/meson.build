
helpers_inc = include_directories('helpers/inc')
game_inc = include_directories('game/inc')
# tetrominos_inc = include_directories('tetrominos/inc')

tetris_incs = [
  helpers_inc,
  game_inc,
  # tetrominos_inc,
]

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
  include_directories: tetris_incs,
  dependencies: tetris_deps,
  install: true,
)
