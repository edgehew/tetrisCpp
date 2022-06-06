project(
  'tetris',
  'cpp',
  default_options: [
    'cpp_std=c++17',
    'werror=true',
    'warning_level=3',
    ],
  version: '0.0.1',
)

cxx = meson.get_compiler('cpp')

subdir('src')

install_subdir('resources/images/', install_dir: 'share')
install_subdir('resources/fonts/', install_dir: 'share')
