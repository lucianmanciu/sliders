HEADERS     = \
              window.h \
    cylinder.h
SOURCES     = main.cpp \
              window.cpp \
    cylinder.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/sliders
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS sliders.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/widgets/sliders
INSTALLS += target sources

symbian: include($$PWD/../../symbianpkgrules.pri)
maemo5: include($$PWD/../../maemo5pkgrules.pri)
contains(MEEGO_EDITION,harmattan): include($$PWD/../../harmattanpkgrules.pri)

symbian: warning(This example might not fully work on Symbian platform)
maemo5: warning(This example might not fully work on Maemo platform)
contains(MEEGO_EDITION,harmattan): warning(This example might not fully work on Harmattan platform)
simulator: warning(This example might not fully work on Simulator platform)

OTHER_FILES += \
    images/cheese.jpg
