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

#include "PlannerCommand.h"

#include <gcode/machine/MachineEnum.h>


namespace GCode {
  class SeekCommand : public PlannerCommand {
    MachineEnum::port_t port;
    bool active;
    bool error;

  public:
    SeekCommand(MachineEnum::port_t port, bool active, bool error) :
      port(port), active(active), error(error) {}

    // From PlannerCommand
    const char *getType() const override {return "seek";}
    void insert(cb::JSON::Sink &sink) const override;
    void write(MachineInterface &machine) const override;
  };
}
