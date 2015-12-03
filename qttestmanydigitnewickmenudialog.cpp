#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "qttestmanydigitnewickmenudialog.h"

#include <QKeyEvent>
#include <QApplication>
#include <QDesktopWidget>

#include "testmanydigitnewickmenudialog.h"
#include "qtaboutdialog.h"
#include "qttestmanydigitnewickmaindialog.h"
#include "testtimer.h"
#include "testmanydigitnewickmenudialog.h"
#include "ui_qttestmanydigitnewickmenudialog.h"
#include "trace.h"
#pragma GCC diagnostic pop

ribi::tmdn::QtMenuDialog::QtMenuDialog(QWidget *parent) noexcept
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtTestManyDigitNewickMenuDialog)
{
  #ifndef NDEBUG
  Test();
  #endif
  ui->setupUi(this);
}

ribi::tmdn::QtMenuDialog::~QtMenuDialog() noexcept
{
  delete ui;
}

void ribi::tmdn::QtMenuDialog::keyPressEvent(QKeyEvent * e)
{
  if (e->key() == Qt::Key_Escape) { close(); }
}

void ribi::tmdn::QtMenuDialog::on_button_start_clicked() noexcept
{
  QtMainDialog d;
  this->ShowChild(&d);
}

void ribi::tmdn::QtMenuDialog::on_button_about_clicked() noexcept
{
  QtAboutDialog d(MenuDialog().GetAbout());
  d.setWindowIcon(windowIcon());
  d.setStyleSheet(styleSheet());
  ShowChild(&d);
}

void ribi::tmdn::QtMenuDialog::on_button_quit_clicked() noexcept
{
  close();
}

#ifndef NDEBUG
void ribi::tmdn::QtMenuDialog::Test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  QtMainDialog();
  const TestTimer test_timer(__func__,__FILE__,1.0);
}
#endif
