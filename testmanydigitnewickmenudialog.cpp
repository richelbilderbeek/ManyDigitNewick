#include "testmanydigitnewickmenudialog.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <boost/lexical_cast.hpp>

#include "newickvector.h"
#include "manydigitnewick.h"
#include "testtimer.h"
#include "trace.h"
#pragma GCC diagnostic pop

ribi::tmdn::MenuDialog::MenuDialog()
{
  #ifndef NDEBUG
  Test();
  #endif
}

int ribi::tmdn::MenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc > 3)
  {
    std::cout << GetHelp() << '\n';
    return 1;
  }
  return 0;
}

ribi::About ribi::tmdn::MenuDialog::GetAbout() const noexcept
{
  About about(
    "Richel Bilderbeek",
    "TestManyDigitNewick",
    "tool to test the two-digit-Newick architecture",
    "the 8th of May 2014",
    "2010-2015",
    "http://www.richelbilderbeek.nl/ToolTestManyDigitNewick",
    GetVersion(),
    GetVersionHistory());

  about.AddLibrary("BigInt: version 2010.04.30");
  about.AddLibrary("NewickVector: version " + NewickVector::GetVersion());
  about.AddLibrary("ManyDigitNewick: version " + ManyDigitNewick::GetVersion());
  return about;
}

ribi::Help ribi::tmdn::MenuDialog::GetHelp() const noexcept
{
  return Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {
    },
    {
    }
  );
}

std::string ribi::tmdn::MenuDialog::GetVersion() const noexcept
{
  return "2.0";
}

std::vector<std::string> ribi::tmdn::MenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2011-03-02: version 1.0: initial version copied and from TestTwoDigitNewick",
    "2014-05-08: version 1.1: conformized with ProjectRichelBilderbeek",
    "2015-12-03: version 2.0: moved to own GitHub",
  };
}

#ifndef NDEBUG
void ribi::tmdn::MenuDialog::Test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  {
    NewickVector::Test();
    ManyDigitNewick();
  }
  const TestTimer test_timer(__func__,__FILE__,1.0);
}
#endif
