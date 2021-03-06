
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

#include "ipc.hpp"

// A thread listening for input
class Listener {
public:
    // Register a new listener
    void Register(std::string_view, Thread*)
 private:
    // Multiple threads can listen to the same connection for multi-threading
    std::queue<Thread*> waiting;
};

// Servers
static inline std::unordered_map<std::string, Listener> servers;

// 
int ipc_connect(std::string_view);

int ipc_send(std::string);
std::string ipc_recieve();
