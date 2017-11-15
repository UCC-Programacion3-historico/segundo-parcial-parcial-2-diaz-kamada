cmake_minimum_required(VERSION 3.8)
project(MailManager)

set(CMAKE_CXX_STANDARD 14)


add_subdirectory(test)

set(SOURCE_FILES src/main.cpp src/MailManager.h src/email.h clases/ArbolMail.h clases/NodoArbol.h clases/ArbolDate.h clases/ArbolFrom.h clases/NodoArbolDate.h clases/NodoArbolFrom.h)
add_executable(MailManager ${SOURCE_FILES})

set(SOURCE_FILES_2 PRUEBAS/main.cpp)
add_executable(PRUEBA ${SOURCE_FILES_2})

set(SOURCE_FILES_3 src/main.cpp)
add_executable(main ${SOURCE_FILES_3})