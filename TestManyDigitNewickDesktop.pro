include(../RibiLibraries/DesktopApplicationNoWeffcpp.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/BigInteger.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralDesktop.pri)

include(../RibiClasses/CppFuzzy_equal_to/CppFuzzy_equal_to.pri)
include(../RibiClasses/CppMultiVector/CppMultiVector.pri)
include(../RibiClasses/CppRibiRandom/CppRibiRandom.pri)


include(../Newick/Newick.pri)
include(../NewickVector/NewickVector.pri)
include(../ManyDigitNewick/ManyDigitNewick.pri)
include(../BinaryNewickVector/BinaryNewickVector.pri)
include(../TwoDigitNewick/TwoDigitNewick.pri)
include(TestManyDigitNewickDesktop.pri)

SOURCES += qtmain.cpp

# Thanks to Qt
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

