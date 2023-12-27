/**********************************************************************
 * File:        dpidialog.cpp
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

#include "dialogs/dpidialog.h"

DPIDialog::DPIDialog(QWidget* parent, int x_dpi, int y_dpi) : QDialog(parent) {
    setupUi(this);
    xDPI->setValue(x_dpi);
    yDPI->setValue(y_dpi);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void DPIDialog::closeEvent(QCloseEvent* event) { event->accept(); }
