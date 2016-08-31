include(../RibiLibraries/DesktopApplicationNoWeffcpp.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/BigInteger.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralDesktop.pri)

include(../RibiClasses/CppBinaryNewickVector/CppBinaryNewickVector.pri)
include(../RibiClasses/CppFuzzy_equal_to/CppFuzzy_equal_to.pri)
include(../RibiClasses/CppManyDigitNewick/CppManyDigitNewick.pri)
include(../RibiClasses/CppMultiVector/CppMultiVector.pri)
include(../RibiClasses/CppNewick/CppNewick.pri)
include(../RibiClasses/CppNewickVector/CppNewickVector.pri)
include(../RibiClasses/CppRibiRandom/CppRibiRandom.pri)
include(../RibiClasses/CppTwoDigitNewick/CppTwoDigitNewick.pri)

include(TestManyDigitNewickDesktop.pri)

SOURCES += qtmain.cpp

# Thanks to Qt
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

