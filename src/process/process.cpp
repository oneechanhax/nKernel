
/*
 * nKernel: A Magical kernel for magical needs
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

class Process {
public:
    Process(const char* file, ) {
        // Load process into memory?
        // Load the dynamic loader thing?
        // Run _start?
    }
    ~Process() {
        // What to do here?
    }
    // If the process slot is currently active
    bool active = true;
    std::vector<mem::Page> mapped_pages;// Replace this with the actual map or use something else?
private:
    // TODO: Tree/map this
    static inline std::vector<Process> list;
    static inline std::vector<Process*> active_list; // Cached list of active processes
};
