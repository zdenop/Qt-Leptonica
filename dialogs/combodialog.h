#ifndef COMBOBOXDIALOG_H
#define COMBOBOXDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "ui_combodialog.h"

class ComboBoxDialog : public QDialog, public Ui::ComboBoxDialog {
    Q_OBJECT

  public:
    explicit ComboBoxDialog(QWidget *parent = 0);
    ~ComboBoxDialog();

};

#endif // COMBOBOXDIALOG_H

