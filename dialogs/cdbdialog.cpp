/**********************************************************************
 * File:        cdbdialog.cpp
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

#include "dialogs/cdbdialog.h"

CDBDialog::CDBDialog(QWidget* parent) : QDialog(parent) {
    setupUi(this);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void CDBDialog::setValues(int blackval, int whiteval, int thresh) {
    this->blackVal->setValue(blackval);
    this->whiteVal->setValue(whiteval);
    this->treshold->setValue(thresh);
    this->lcdNumber->display(thresh);
}

void CDBDialog::on_treshold_valueChanged(int value) {
    this->lcdNumber->display(value);
}

void CDBDialog::closeEvent(QCloseEvent* event) { event->accept(); }
