cmake_minimum_required(VERSION 3.16)

# Incluir el toolchain de Conan si existe
include("${CMAKE_BINARY_DIR}/conan_toolchain.cmake")

project(AdvancedUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Añadir el directorio de Conan a CMAKE_PREFIX_PATH
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick QuickControls2)

qt_standard_project_setup(REQUIRES 6.5)


qt_add_executable(appAdvancedUI
  main.cpp
)

qt_add_qml_module(appAdvancedUI
  URI AdvancedUI
  VERSION 1.0
  QML_FILES
  Main.qml
  QML_FILES Tabbar.qml
  QML_FILES Pages.qml
  QML_FILES pages/PageOne.qml
  QML_FILES pages/PageTwo.qml
  SOURCES ui/gituser.h ui/gituser.cpp
  SOURCES ui/gitusermodel.h ui/gitusermodel.cpp
  SOURCES ui/uimanager.h ui/uimanager.cpp
  QML_FILES pages/pageone/InputGitUser.qml
  QML_FILES pages/pageone/ListGitUser.qml
  QML_FILES pages/pageone/GitUserDelegate.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appAdvancedUI PROPERTIES

  # MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appAdvancedUI
  MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
  MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
  MACOSX_BUNDLE TRUE
  WIN32_EXECUTABLE TRUE
)

# Encontrar el paquete github_info generado por Conan
find_package(github_info REQUIRED)

target_link_libraries(appAdvancedUI
  PRIVATE Qt6::Quick Qt6::QuickControls2 github_info::github_info
)

target_include_directories(appAdvancedUI PRIVATE ${CMAKE_BINARY_DIR}/conan_deps/include)




include(GNUInstallDirs)
install(TARGETS appAdvancedUI
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
