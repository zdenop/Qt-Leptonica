/**********************************************************************
* File:        dpidialog.h
* Description: Set DPI dialog
* Author:      Zdenko Podobny
* Created:     2015-07-01
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

#ifndef DIALOGS_DPIDIALOG_H_
#define DIALOGS_DPIDIALOG_H_

#include <QCloseEvent>

#include "ui_dpidialog.h"

class DPIDialog : public QDialog, public Ui::DPIDialog {
    Q_OBJECT

  public:
    explicit DPIDialog(QWidget* parent = 0, int x_dpi=0, int y_dpi=0);

  protected:
    void closeEvent(QCloseEvent* event);
};

#endif  // DIALOGS_DPIDIALOG_H_
