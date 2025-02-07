
## **Basic Commands**
| Command | Description |
|---------|-------------|
| `gdb <program>` | Start GDB with a program |
| `gdb -q <program>` | Start GDB without the startup message |
| `run (r)` | Start program execution |
| `quit (q)` | Exit GDB |
| `help <command>` | Get help on a specific command |

---

## **Breakpoints & Execution Control**
| Command | Description |
|---------|-------------|
| `break (b) <func>` | Set a breakpoint at a function |
| `b *<address>` | Set a breakpoint at a specific address |
| `info breakpoints (i b)` | List all breakpoints |
| `delete <num>` | Delete a breakpoint |
| `disable <num>` | Disable a breakpoint |
| `enable <num>` | Enable a breakpoint |
| `continue (c)` | Continue execution until the next breakpoint |
| `step (s)` | Step into a function (execute the next instruction) |
| `next (n)` | Step over a function (execute without entering it) |
| `finish` | Run until function returns |
| `until <address>` | Run until reaching a specific address |

---

## **Memory & Registers**
| Command | Description |
|---------|-------------|
| `info registers (i r)` | Show register values |
| `set $<register> = <value>` | Modify a register |
| `x/<n> <addr>` | Examine memory (`n` = number of units) |
| `x/s <addr>` | Examine memory as a string |
| `x/x <addr>` | Examine memory as hex |
| `x/i <addr>` | Examine memory as an instruction |
| `print (p) $<register>` | Print the value of a register |
| `p *(int*)<addr>` | Print value at an address |

---

## **Disassembly & Code Inspection**
| Command | Description |
|---------|-------------|
| `disassemble (disas) <func>` | Disassemble a function |
| `disas /r <func>` | Disassemble with raw opcodes |
| `layout asm` | Show assembly view |
| `layout regs` | Show register view |
| `set disassembly-flavor intel` | Set Intel assembly syntax |

---

## **Stack & Function Calls**
| Command | Description |
|---------|-------------|
| `backtrace (bt)` | Show function call stack |
| `frame <num>` | Select a stack frame |
| `info frame` | Show details about the current frame |
| `info args` | Show function arguments |
| `info locals` | Show local variables |

---

## **Modifying Execution**
| Command | Description |
|---------|-------------|
| `set {int}<addr> = <value>` | Modify memory at an address |
| `set $eax = 0` | Modify a register (e.g., set `eax` to `0`) |
| `jump (j) <address>` | Jump to an address and continue execution |

---

## **Debugging a Running Process**
| Command | Description |
|---------|-------------|
| `gdb -p <pid>` | Attach GDB to a running process |
| `detach` | Detach GDB from the process |
| `attach <pid>` | Reattach to a process |

---

## **Debugging Core Dumps**
| Command | Description |
|---------|-------------|
| `ulimit -c unlimited` | Enable core dumps |
| `gdb <binary> <core>` | Debug a core dump |
| `bt` | Get a backtrace from the dump |

---

## **TUI (Text User Interface) Mode**
| Command | Description |
|---------|-------------|
| `layout split` | Show source + assembly |
| `layout asm` | Show assembly only |
| `layout regs` | Show registers |

---

## **Shortcuts**
| Shortcut | Description |
|---------|-------------|
| `Ctrl + x a` | Enter/exit TUI mode |
| `Ctrl + l` | Refresh screen |
| `Ctrl + p` | Previous command in history |
| `Ctrl + n` | Next command in history |