
/*
 * nKernel: Magical kernel for magical needs
 * Copyright (C) 2019 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <vector>

namespace threads {

class Process;
class Thread {
public:
    enum class State { kRunning, kIdle, kForcePreempt };
    State state = State::kRunning;
    Process* parent = nullptr;
    int8_t nice = 0;

    void ForcePreempt(); // Make sure you keep track of forced processes
    static void Terminate();
private:
    static std::vector<Thread> list;
};

}