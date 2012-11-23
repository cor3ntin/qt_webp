TEMPLATE = lib
CONFIG += qt plugin

WEBP_PATH = ../libwebp/src/

CFLAGS += -OS
CXXFLAGS += -OS
CONFIG += hide_symbols


INCLUDEPATH = ../libwebp/src/
SOURCES += \
    webpioplugin.cpp \
    webphandler.cpp \
    $$files($$WEBP_PATH/dec/*.c)\
    $$files($$WEBP_PATH/utils/*.c) \
    $$files($$WEBP_PATH/dsp/*.c)
   

TARGET = webp
target.path += ../test/plugins/imageformats
INSTALLS += target

HEADERS += \
    webphandler.h
