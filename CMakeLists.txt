cmake_minimum_required(VERSION 3.8)
project(MailManager)

set(CMAKE_CXX_STANDARD 14)


add_subdirectory(test)

set(SOURCE_FILES src/main.cpp src/MailManager.cpp src/MailManager.h src/email.cpp src/email.h clases/Lista.h clases/Nodo.h clases/ListaMail.h clases/NodoMail.h)
add_executable(MailManager ${SOURCE_FILES})