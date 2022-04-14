# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "yh_tutorial_5: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(yh_tutorial_5_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/aaa/catkin_ws/src/yh_tutorial_5/srv/yh_srv_5.srv" NAME_WE)
add_custom_target(_yh_tutorial_5_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "yh_tutorial_5" "/home/aaa/catkin_ws/src/yh_tutorial_5/srv/yh_srv_5.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(yh_tutorial_5
  "/home/aaa/catkin_ws/src/yh_tutorial_5/srv/yh_srv_5.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/yh_tutorial_5
)

### Generating Module File
_generate_module_cpp(yh_tutorial_5
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/yh_tutorial_5
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(yh_tutorial_5_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(yh_tutorial_5_generate_messages yh_tutorial_5_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aaa/catkin_ws/src/yh_tutorial_5/srv/yh_srv_5.srv" NAME_WE)
add_dependencies(yh_tutorial_5_generate_messages_cpp _yh_tutorial_5_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(yh_tutorial_5_gencpp)
add_dependencies(yh_tutorial_5_gencpp yh_tutorial_5_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS yh_tutorial_5_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(yh_tutorial_5
  "/home/aaa/catkin_ws/src/yh_tutorial_5/srv/yh_srv_5.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/yh_tutorial_5
)

### Generating Module File
_generate_module_eus(yh_tutorial_5
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/yh_tutorial_5
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(yh_tutorial_5_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(yh_tutorial_5_generate_messages yh_tutorial_5_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aaa/catkin_ws/src/yh_tutorial_5/srv/yh_srv_5.srv" NAME_WE)
add_dependencies(yh_tutorial_5_generate_messages_eus _yh_tutorial_5_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(yh_tutorial_5_geneus)
add_dependencies(yh_tutorial_5_geneus yh_tutorial_5_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS yh_tutorial_5_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(yh_tutorial_5
  "/home/aaa/catkin_ws/src/yh_tutorial_5/srv/yh_srv_5.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/yh_tutorial_5
)

### Generating Module File
_generate_module_lisp(yh_tutorial_5
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/yh_tutorial_5
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(yh_tutorial_5_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(yh_tutorial_5_generate_messages yh_tutorial_5_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aaa/catkin_ws/src/yh_tutorial_5/srv/yh_srv_5.srv" NAME_WE)
add_dependencies(yh_tutorial_5_generate_messages_lisp _yh_tutorial_5_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(yh_tutorial_5_genlisp)
add_dependencies(yh_tutorial_5_genlisp yh_tutorial_5_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS yh_tutorial_5_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(yh_tutorial_5
  "/home/aaa/catkin_ws/src/yh_tutorial_5/srv/yh_srv_5.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/yh_tutorial_5
)

### Generating Module File
_generate_module_nodejs(yh_tutorial_5
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/yh_tutorial_5
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(yh_tutorial_5_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(yh_tutorial_5_generate_messages yh_tutorial_5_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aaa/catkin_ws/src/yh_tutorial_5/srv/yh_srv_5.srv" NAME_WE)
add_dependencies(yh_tutorial_5_generate_messages_nodejs _yh_tutorial_5_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(yh_tutorial_5_gennodejs)
add_dependencies(yh_tutorial_5_gennodejs yh_tutorial_5_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS yh_tutorial_5_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(yh_tutorial_5
  "/home/aaa/catkin_ws/src/yh_tutorial_5/srv/yh_srv_5.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/yh_tutorial_5
)

### Generating Module File
_generate_module_py(yh_tutorial_5
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/yh_tutorial_5
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(yh_tutorial_5_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(yh_tutorial_5_generate_messages yh_tutorial_5_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aaa/catkin_ws/src/yh_tutorial_5/srv/yh_srv_5.srv" NAME_WE)
add_dependencies(yh_tutorial_5_generate_messages_py _yh_tutorial_5_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(yh_tutorial_5_genpy)
add_dependencies(yh_tutorial_5_genpy yh_tutorial_5_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS yh_tutorial_5_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/yh_tutorial_5)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/yh_tutorial_5
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(yh_tutorial_5_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/yh_tutorial_5)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/yh_tutorial_5
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(yh_tutorial_5_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/yh_tutorial_5)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/yh_tutorial_5
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(yh_tutorial_5_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/yh_tutorial_5)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/yh_tutorial_5
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(yh_tutorial_5_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/yh_tutorial_5)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/yh_tutorial_5\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/yh_tutorial_5
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(yh_tutorial_5_generate_messages_py std_msgs_generate_messages_py)
endif()
