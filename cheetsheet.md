# 🛠 **x86/x86-64 Assembly Cheat Sheet**  

### ** 1. General-Purpose Registers**
#### **x86 (32-bit) Registers**  
| Register | Purpose |
|----------|---------|
| `EAX`  | Return values, general-purpose |
| `EBX`  | General-purpose |
| `ECX`  | Counter (used in loops) |
| `EDX`  | General-purpose, multiplication/division |
| `ESI`  | Source index for memory operations |
| `EDI`  | Destination index for memory operations |
| `ESP`  | Stack pointer (points to top of stack) |
| `EBP`  | Base pointer (used in function stack frames) |

#### **x86-64 (64-bit) Registers**  
| Register | Purpose |
|----------|---------|
| `RAX`  | Return values |
| `RBX`  | General-purpose |
| `RCX`  | Counter |
| `RDX`  | General-purpose, multiplication/division |
| `RSI`  | Source index |
| `RDI`  | Destination index |
| `RSP`  | Stack pointer (top of stack) |
| `RBP`  | Base pointer |
| `R8`-`R15`  | Extra general-purpose registers |

### **📌 2. Calling Conventions (Function Arguments)**
#### **32-bit (cdecl, stdcall, fastcall)**
- Function arguments are **pushed onto the stack** (right to left).  
- Return value stored in **EAX**.  

#### **64-bit (System V ABI - Linux/macOS)**
- **First six function arguments:** `RDI`, `RSI`, `RDX`, `RCX`, `R8`, `R9`.  
- **Remaining arguments:** Passed on the stack.  
- **Return value stored in `RAX`**.  

---

### **📌 3. Common Instructions**
| Instruction | Description |
|------------|-------------|
| `mov dest, src` | Move data from `src` to `dest` |
| `push value` | Push value onto stack |
| `pop dest` | Pop value from stack into `dest` |
| `call addr` | Call function at `addr` |
| `ret` | Return from function |
| `cmp op1, op2` | Compare two values (sets flags) |
| `jmp addr` | Jump to `addr` (unconditional) |
| `je addr` / `jne addr` | Jump if equal / not equal |
| `jg addr` / `jl addr` | Jump if greater / less |
| `add dest, src` | Add `src` to `dest` |
| `sub dest, src` | Subtract `src` from `dest` |
| `mul src` / `div src` | Multiply / divide |
| `and` / `or` / `xor` | Bitwise operations |
| `shl` / `shr` | Bit shifts (multiply/divide by 2) |
| `lea dest, [src]` | Load effective address (pointer math) |
| `nop` | No operation (used for padding) |

---

### **📌 4. Stack Operations**
| Instruction | Description |
|------------|-------------|
| `push eax` | Push `eax` onto the stack |
| `pop eax` | Pop top of stack into `eax` |
| `call func` | Call function (pushes return address) |
| `ret` | Return from function (pops return address) |

**Function Prologue (stack setup):**
```assembly
push ebp         ; Save old base pointer
mov ebp, esp     ; Set new base pointer
sub esp, 0x10    ; Allocate local variables
```

**Function Epilogue (stack cleanup):**
```assembly
mov esp, ebp     ; Restore stack pointer
pop ebp          ; Restore base pointer
ret              ; Return to caller
```

---

### **📌 5. Conditional Jumps (Based on `cmp`)**
| Instruction | Condition |
|------------|-----------|
| `je` (jump if equal) | `ZF == 1` |
| `jne` (jump if not equal) | `ZF == 0` |
| `jg` (jump if greater) | `ZF == 0 && SF == OF` |
| `jl` (jump if less) | `SF != OF` |
| `jge` (jump if greater or equal) | `SF == OF` |
| `jle` (jump if less or equal) | `ZF == 1 || SF != OF` |

**Example:**
```assembly
cmp eax, ebx  ; Compare EAX and EBX
je equal_label ; Jump if EAX == EBX
jne not_equal  ; Jump if EAX != EBX
```

---

### **📌 6. Memory Addressing Modes**
| Mode | Example | Meaning |
|------|--------|---------|
| Direct | `mov eax, [0x1000]` | Load from memory address `0x1000` |
| Register | `mov eax, ebx` | Copy value of `ebx` into `eax` |
| Indexed | `mov eax, [ebx+4]` | Load from address `(ebx + 4)` |
| Scaled | `mov eax, [ebx + ecx*4]` | Load from `(ebx + ecx*4)` |

---

### **📌 7. Useful Debugging Commands**
#### **GDB Commands**
| Command | Description |
|---------|-------------|
| `gdb ./program` | Start debugging `program` |
| `break main` | Set breakpoint at `main()` |
| `run` (`r`) | Run the program |
| `next` (`n`) | Step over instructions |
| `step` (`s`) | Step into function calls |
| `info registers` | View register values |
| `x/10x $esp` | Examine 10 hex values at stack pointer |
| `disassemble main` | View assembly of `main()` |

---

### **📌 8. Example: Reverse Engineering a Simple Function**
C code:
```c
int add(int a, int b) {
    return a + b;
}
```
Compiled x86-64 assembly:
```assembly
add:
    mov eax, edi    ; Move first argument into EAX
    add eax, esi    ; Add second argument
    ret             ; Return result in EAX
```

---

### **📌 9. Resources for Further Learning**
📌 **Assembly Basics:**  
- [Intel x86 Instruction Reference](https://www.felixcloutier.com/x86/)  
- [Practical Reverse Engineering (Book)](https://www.nostarch.com/ReverseEngineering.htm)  

📌 **Reverse Engineering Practice:**  
- [Crackmes.one](https://crackmes.one/)  
- [OverTheWire (Wargames)](https://overthewire.org/wargames/)  
- [Radare2 Cheatsheet](https://github.com/radareorg/radare2/blob/master/doc/cheatsheet.md)  
