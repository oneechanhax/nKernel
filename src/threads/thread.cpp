
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

// should threads be split from kernel threads???
// Avoid all kernel threads to allow all the cpu time in userland or will IO eat us alive???

class Thread {
public:
    enum class State { kRunning, kIdle, kHung, kBlocked } state;
    Process* parent = nullptr;
    int8_t nice = 0;

    // Holds the context for later for io to take its place and the thread can run elsewhere
    template<class T>
    void Unblock(T arg) {
        assert(state == State::kBlocked);
    }
    void Block() {

    }
};
