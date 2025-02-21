
## A redo of K&r exercises with x86-64 assembly

## IDIV

### Description

Divides the (signed) value in the AX, DX:AX, or EDX:EAX (dividend) by the source operand (divisor) and stores the result in the AX (AH:AL), DX:AX, or EDX:EAX registers. The source operand can be a general-purpose register or a memory location. The action of this instruction depends on the operand size (dividend/divisor).

Non-integral results are truncated (chopped) towards 0. The remainder is always less than the divisor in magnitude. Overflow is indicated with the #DE (divide error) exception rather than with the CF flag.
In 64-bit mode, the instruction’s default operation size is 32 bits. 

Use of the REX.R prefix permits access to additional registers (R8-R15). Use of the REX.W prefix promotes operation to 64 bits. In 64-bit mode when REX.W is applied, the instruction divides the signed value in RDX:RAX by the source operand. RAX contains a 64-bit quotient; RDX contains a 64-bit remainder.

Yes, in signed multiplication, **only the negative number needs sign extension** to preserve its value correctly.

### Why Only the Negative Number?
- Positive numbers have leading `0`s in their binary representation, so extending them doesn't change their value.
- Negative numbers use **two's complement**, meaning their leading bits are `1`s. If not extended properly, the CPU might misinterpret the value.

### Sign Extension Rules:
1. **8-bit to 16-bit:** Use `CBW` (Convert Byte to Word)  
   - Sign-extends `AL` into `AX`.
  
2. **16-bit to 32-bit:** Use `CWD` (Convert Word to Doubleword)  
   - Sign-extends `AX` into `DX:AX`.

3. **32-bit to 64-bit:** Use `CDQ` (Convert Doubleword to Quadword)  
   - Sign-extends `EAX` into `EDX:EAX`.

4. **64-bit to 128-bit (x86-64 only):** Use `CQO` (Convert Quadword to Octaword)  
   - Sign-extends `RAX` into `RDX:RAX`.

### Example:
If multiplying `-5` (`0xFB` in 8-bit) with `10` (`0x0A`):

Without sign extension:

```assembly
mov al, -5       ; AL = 0xFB (incorrect if extended manually)
mov ah, 0        ; Incorrect extension (should be 0xFF)
imul ah          ; Might give an incorrect result
```

With correct sign extension:

```assembly
mov al, -5       ; AL = 0xFB
cbw              ; Sign-extends AL into AX (AX = 0xFFFB)
imul word ptr [someVar] ; Multiplies AX correctly
```

If multiplication involves different operand sizes, always ensure sign extension is applied only to **the negative number** before multiplying.