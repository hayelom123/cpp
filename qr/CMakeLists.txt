cmake_minimum_required(VERSION 3.10)
project(qr)

set(CMAKE_CXX_STANDARD 11)

add_executable(qr
    main.cpp
    qrcodegen.cpp
)

# cmake_minimum_required(VERSION 3.5)
# project(qrcode)

# add_executable(myqr QrCodeGeneratorDemo.cpp qrcodegen.cpp)
# set_target_properties(myqr PROPERTIES CXX_STANDARD 11)
