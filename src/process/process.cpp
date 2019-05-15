
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

    // Memory
    mem::Map memory_map;// Replace this with the actual map or use something else?

    // Syscall utils
    std::vector<std::string> syscall_strings;

    // Global process utils
    static int ClaimOpen();
    void Close();
private:
    // TODO: Tree/map this
    static std::mutex list_lock;
    static std::vector<Process> list;
    static std::vector<Process*> active_list; // Cached list of active processes
};

void Process::Close() {
    std::lock_guard<std::mutex> guard(list_lock);

    // Remove from active cache
    auto find = std::find(active_list.begin(), active_list.end(), this);
    assert(find != active_list.end());
    active_list.erase(find);

    // Ensure all threads are closed
    Thread::Terminate(this);

    // TODO, need to do something with the memory map???

    // Free unused memory
    if (&list.back() == this) {
        list.pop_back();
    } else {
        // Clear out all of our strings since its unused
        syscall_strings.clear();
        
    }
}
