set(TEST_FILE CMakeFiles/create_file.dir/create_file.i)
file(READ ${TEST_FILE} CONTENTS)
if("${CONTENTS}" MATCHES "Unable to close")
  message(STATUS "${TEST_FILE} created successfully!")
else()
  message(FATAL_ERROR "${TEST_FILE} creation failed!")
endif()
