cmake_minimum_required(VERSION 3.16)
project(pypilot_data_model LANGUAGES CXX)

option(PYPILOT_DATA_MODEL_BUILD_TESTS "Build tests" ON)
option(PYPILOT_DATA_MODEL_BUILD_EXAMPLES "Build examples" ON)

add_library(pypilot_data_model INTERFACE)
target_include_directories(pypilot_data_model INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(pypilot_data_model INTERFACE cxx_std_11)

if(PYPILOT_DATA_MODEL_BUILD_EXAMPLES)
  add_executable(print_model examples/linux/print_model.cpp)
  target_link_libraries(print_model PRIVATE pypilot_data_model)
endif()

if(PYPILOT_DATA_MODEL_BUILD_TESTS)
  enable_testing()
  add_executable(test_model tests/test_model.cpp)
  target_link_libraries(test_model PRIVATE pypilot_data_model)
  add_test(NAME test_model COMMAND test_model)

  add_executable(test_field_map tests/test_field_map.cpp)
  target_link_libraries(test_field_map PRIVATE pypilot_data_model)
  add_test(NAME test_field_map COMMAND test_field_map)
endif()
