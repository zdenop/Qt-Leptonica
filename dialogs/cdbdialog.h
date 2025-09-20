/**********************************************************************
 * File:        cdbdialog.h
 * Description: Parameter dialog for Clean Dark Background
 * Author:      Zdenko Podobny
 * Created:     2015-07-11
 *
 * (C) Copyright 2015, Zdenko Podobny
 **
 ** Licensed under the Apache License, Version 2.0 (the "License");
 ** you may not use this file except in compliance with the License.
 ** You may obtain a copy of the License at
 **
 **    http://www.apache.org/licenses/LICENSE-2.0
 **
 ** Unless required by applicable law or agreed to in writing, software
 ** distributed under the License is distributed on an "AS IS" BASIS,
 ** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 ** See the License for the specific language governing permissions and
 ** limitations under the License.
 *
 **********************************************************************/

#ifndef DIALOGS_CDBDIALOG_H_
#define DIALOGS_CDBDIALOG_H_

#include <QCloseEvent>

#include "ui_cdbdialog.h"

class CDBDialog : public QDialog, public Ui::CDBDialog {
    Q_OBJECT

   public:
    explicit CDBDialog(QWidget* parent = 0);
    void setValues(int blackval, int whiteval, int thresh);

   protected:
    void closeEvent(QCloseEvent* event);

   private Q_SLOTS:
    void on_treshold_valueChanged(int value);
};

#endif  // DIALOGS_CDBDIALOG_H_
