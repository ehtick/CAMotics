/******************************************************************************\

  CAMotics is an Open-Source simulation and CAM software.
  Copyright (C) 2011-2019 Joseph Coffland <joseph@cauldrondevelopment.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#pragma once

#include "Dialog.h"
#include "ui_upload_dialog.h"


namespace CAMotics {
  class UploadDialog : public Dialog {
    Q_OBJECT;
    CAMOTICS_DIALOG(UploadDialog);

  public:
    UploadDialog(QWidget *parent);

    QString getFilename() const;
    void setFilename(QString filename);
    bool isAutomatic() const;

    // From Dialog
    int exec() override;

  protected slots:
    void on_uploadPushButton_clicked();
  };
}
