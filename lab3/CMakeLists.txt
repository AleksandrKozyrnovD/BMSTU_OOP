cmake_minimum_required(VERSION 3.5)

project(code VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(code
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        object/abstractobject.h object/abstractobject.cpp
        modelvisitor/modelvisitor.h
        modelvisitor/movevisitor.h modelvisitor/movevisitor.cpp
        modelvisitor/rotatevisitor.h modelvisitor/rotatevisitor.cpp
        modelvisitor/scalevisitor.h modelvisitor/scalevisitor.cpp
        object/carcas/carcas.h object/carcas/carcas.cpp
        object/model.h object/model.cpp
        object/carcas/AbstractCarcas.h


        builder/carcasbuilder.h builder/carcasbuilder.cpp


        builder/BaseCarcasBuilder.h
        loader/loader.h loader/loader.cpp
        loader/abstractreader.h loader/abstractreader.cpp

        loader/filereader.h loader/filereader.cpp
        solution/basesolution.h solution/basesolution.cpp
        solution/solutiontransform.h solution/solutiontransform.cpp
        solution/solutionloader.h solution/solutionloader.cpp
        object/camera/camera.h object/camera/camera.cpp
        scene/scene.h scene/scene.cpp
        builder/basedirector.h builder/basedirector.cpp
        builder/carcasdirector.h builder/carcasdirector.cpp
        builder/directorcreator.h builder/directorcreator.cpp
        draw/abstractgraphicfactory.h draw/abstractgraphicfactory.cpp
        draw/abstractdrawer.h draw/abstractdrawer.cpp
        draw/qtdrawer.h draw/qtdrawer.cpp
        draw/qtfactory.h draw/qtfactory.cpp
        draw/drawvisitor.h draw/drawvisitor.cpp
        draw/drawall.h draw/drawall.cpp
        solution/solutionscene.h solution/solutionscene.cpp
        solution/solutiondraw.h solution/solutiondraw.cpp
        facade/facade.h facade/facade.cpp
        command/basecommand.h command/basecommand.cpp
        command/modelcommand.h command/modelcommand.cpp
        command/cameracommand.h command/cameracommand.cpp
        command/scenecommand.h command/scenecommand.cpp
        command/drawcommand.h command/drawcommand.cpp
        Exception.h
        visitor/abstractvisitor.h visitor/abstractvisitor.cpp
        draw/drawcomplex.h draw/drawcomplex.cpp

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET code APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(code SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(code
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(code PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.code)
endif()
set_target_properties(code PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS code
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(code)
endif()
