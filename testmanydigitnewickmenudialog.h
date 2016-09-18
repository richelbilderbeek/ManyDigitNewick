#ifndef TESTMANYDIGITNEWICKMENUDIALOG_H
#define TESTMANYDIGITNEWICKMENUDIALOG_H

#include "menudialog.h"

namespace ribi {
namespace tmdn {

struct MenuDialog : public ribi::MenuDialog
{
  MenuDialog();
  About GetAbout() const noexcept;
  Help GetHelp() const noexcept;
  std::string GetVersion() const noexcept;
  std::vector<std::string> GetVersionHistory() const noexcept;

  private:
  int ExecuteSpecific(const std::vector<std::string>& argv) noexcept;
};

} //~namespace tmdn
} //~namespace ribi

#endif // TESTMANYDIGITNEWICKMENUDIALOG_H
