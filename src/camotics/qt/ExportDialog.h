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
#include "ui_export_dialog.h"


namespace CAMotics {
  class ExportDialog : public Dialog {
    Q_OBJECT;
    CAMOTICS_DIALOG(ExportDialog);

  public:
    ExportDialog(QWidget *parent);

    // From QDialog
    int exec() override;

    void enableSurface(bool enable);
    void enableGCode(bool enable);
    void enableSimData(bool enable);
    void enableCutSurface(bool enable);

    bool surfaceSelected() const;
    bool gcodeSelected() const;
    bool simDataSelected() const;

    bool crlfSelected() const;
    bool binarySTLSelected() const;
    bool compactJSONSelected() const;
    bool withCutSurfaceSelected() const;

  protected slots:
    void on_surfaceRadioButton_clicked();
    void on_gcodeRadioButton_clicked();
    void on_simDataRadioButton_clicked();
  };
}
