cmake_minimum_required(VERSION 3.2)

project(dr_quine)

add_compile_options(-Wall -Wextra -Werror)

add_executable(Colleen
	Colleen/Colleen.c
)

add_executable(Grace
	Grace/Grace.c
)

add_executable(Sully
	Sully/Sully.c
)

set(GRACE_DIR "${CMAKE_SOURCE_DIR}/Grace")
set(SULLY_DIR "${CMAKE_SOURCE_DIR}/Sully")

set_target_properties(Colleen PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Colleen
)

set_target_properties(Grace PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${GRACE_DIR}
	ADDITIONAL_CLEAN_FILES ${GRACE_DIR}/Grace_kid.c
)

set(SULLY_KIDS
	"${SULLY_DIR}/Sully_0.c"
	"${SULLY_DIR}/Sully_1.c"
	"${SULLY_DIR}/Sully_2.c"
	"${SULLY_DIR}/Sully_3.c"
	"${SULLY_DIR}/Sully_4.c"
	"${SULLY_DIR}/Sully_5.c"
)

set_target_properties(Sully PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${SULLY_DIR}
	ADDITIONAL_CLEAN_FILES "${SULLY_KIDS}"
)
