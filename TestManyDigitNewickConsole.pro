include(../RibiLibraries/ConsoleApplicationNoWeffcpp.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/BigInteger.pri)
include(../RibiLibraries/GeneralConsole.pri)

include(../RibiClasses/CppFuzzy_equal_to/CppFuzzy_equal_to.pri)
include(../RibiClasses/CppMultiVector/CppMultiVector.pri)
include(../RibiClasses/CppRibiRandom/CppRibiRandom.pri)

include(ManyDigitNewick.pri)
include(../Newick/Newick.pri)
include(../NewickVector/NewickVector.pri)
include(../TwoDigitNewick/TwoDigitNewick.pri)
include(../BinaryNewickVector/BinaryNewickVector.pri)
include(TestManyDigitNewickConsole.pri)

SOURCES += main.cpp

# Thanks to Qt
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
