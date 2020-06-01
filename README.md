# CMake template: interface library
A small template for a cmake/conan based interface library.

## Installation
To not inherit git commits from this template, download the project as a zip file and manually initialize the git repository. Zip file can be downloaded through github interface or via `wget` on Linux:
```
wget https://github.com/andreasxp/template_interface_library/archive/master.zip
```
After downloading, unzip the folder and initialize the repository using
```
git init
```

## Usage
This project supports building with [CMake](https://cmake.org/) and packaging with [Conan](https://conan.io/). The easiest way to build it is using Conan commands:
```
conan install . -if build -b outdated
conan build . -bf build
```

The template project supports two options to control the way it's built:
| Option (Conan) | Option (CMake)                 | Default |
| -------------- | ------------------------------ | ------- |
| tests          | ${PROJECT_NAME}_BUILD_TESTS    | False   |
| examples       | ${PROJECT_NAME}_BUILD_EXAMPLES | False   |

These control whether tests and examples are built. To build everything using conan, use the following commands:
```
conan install . -if build -b outdated -o tests=True -o examples=True
conan build . -bf build
```

Test executable is called `${PROJECT_NAME}_tests`, example executable is called `${PROJECT_NAME}_example` and both are located in the `bin` folder inside cmake build directory (usually the full path is `<project root>/build/bin`).

The tools folder includes a collection of CMake scripts that can be useful for further configuration, such as clang tidy analysis and include-what-you-use. These are taken from the [cmake scripts repo](https://github.com/mpusz/cmake-scripts), with thanks to Mateusz Pusz.

## Customization
This template is designed to be as easy in handling as possible. For example, the project name and version only need to be defined in one place:
```cmake
# CMakeLists.txt
project(template_interface_library LANGUAGES CXX VERSION 0.1.0)
```

By updating the name here it will automatically be picked up both by Conan, target names, and option names. In the same file just below, the CMake targets can be further configured:
```cmake
set(target_name ${PROJECT_NAME})
set(namespace zh)
```
`target_name` will be used for the main target, test target (`${target_name}_tests`) and example target (`${target_name}_example`).  
`namespace` is the text befire `::` when importing the target in another cmake project.

Users of your library will be able to link against your library by accessing target `${namespace}::${target_name}` (Default would be `zh::template_interface_library`).
