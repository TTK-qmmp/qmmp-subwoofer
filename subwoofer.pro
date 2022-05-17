include($$PWD/../../plugins.pri)

TARGET = $$PLUGINS_PREFIX/Effect/subwoofer

HEADERS += subwooferplugin.h \
           effectsubwooferfactory.h \
           settingsdialog.h

SOURCES += subwooferplugin.cpp \
           effectsubwooferfactory.cpp \
           settingsdialog.cpp

FORMS += settingsdialog.ui

unix{
    target.path = $$PLUGIN_DIR/Effect
    INSTALLS += target
}
