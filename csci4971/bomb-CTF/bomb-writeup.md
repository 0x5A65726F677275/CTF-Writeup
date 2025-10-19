💣 Dr. Von Noizeman's Nuclear Bomb Defusal Writeup
Overview
Welcome to the thrilling tale of defusing Dr. Von Noizeman's Nuclear Bomb, a binary exploitation challenge that tests your reverse engineering and debugging skills! This bomb requires disarming four colored locks—YELLOW, GREEN, BLUE, and RED—each with unique puzzles to solve. Armed with tools like pwndbg and Ghidra, we successfully navigated the bomb's defenses and disarmed it. Below is a detailed breakdown of each phase, complete with technical insights and the solutions that saved the day!

🟡 Phase 1: YELLOW
Objective
Unlock the YELLOW phase by entering the correct 8-character password.
Analysis

Disassembly: The yellow function compares bytes at memory address 0x804c24c to 0x804c253 against a hardcoded sequence: 0x38, 0x34, 0x33, 0x37, 0x31, 0x30, 0x36, 0x35.
Conversion: These hex values correspond to ASCII characters: 8 (0x38), 4 (0x34), 3 (0x33), 7 (0x37), 1 (0x31), 0 (0x30), 6 (0x36), 5 (0x35).
Password: Concatenating these gives 84371065.
Behavior: If the input matches, a success message is printed, and the global variable at 0x804c124 is set to 0. Otherwise, it’s shifted left by 10 bits, potentially triggering a failure.

Solution

Input: 84371065
Command: bxxx --char 0x3834333731303635
Result: The YELLOW lock disengages, and the bomb interface updates with a * in the SECONDS field, indicating progress.


🟢 Phase 2: GREEN
Objective
Unlock the GREEN phase by providing an 8-character password and handling an additional check to prevent a lock re-engagement.
Analysis

Disassembly: The green function calls strncmp to compare the user input at ebp-0x14 with the string at 0x804a2c0, which is dcaotdae. The comparison length is 8 bytes.
Additional Check: After a successful strncmp, the function checks a value at ebp-0x8 (initially set to 1) by performing and eax, 1. If the result is non-zero, the lock re-engages with the message "ACTION OVERRIDDEN FROM USER NOIZEV".
Buffer Overflow: The input buffer is vulnerable to overflow, as fgets allows up to 20 characters (including \n). By appending 4 A characters (0x41414141) after dcaotdae, we overwrite the lower byte of ebp-0x8 to 0x41 (odd), but the and eax, 1 check evaluates to 1, causing failure. Adjusting to 4 As ensures the correct behavior.
Memory Inspection: x/4wx $ebp-0x14 shows the input dcaotdaeAAAA\n, confirming the overflow.

Solution

Input: dcaotdaeAAAA
Result: The GREEN lock disengages, but an initial attempt with dcaotdaeAAAAA failed due to the and eax, 1 check. The correct input dcaotdaeAAAA sets ebp-0x8 appropriately, and the bomb interface updates with two *s in the SECONDS field.


🔵 Phase 3: BLUE
Objective
Navigate a circuit traversal path to produce a specific value (0x40475194) by following a sequence of L, R, or \n characters.
Analysis

Ghidra Decompilation: The blue function iterates over a 15-character buffer (0x804c24c), interpreting each character:
L: Move to the address stored at local_8 (a pointer to a structure).
R: Move to the address at local_8 + 8.
\n: Set a flag (local_10) to break the loop.
Other characters: Trigger a "boom" message and break.


XOR Operation: For each valid character, local_c (initially set to _DAT_0804c164) is XORed with the value at local_8 + 4. The final local_c must equal 0x40475194.
Trial and Error: Testing LLR resulted in local_c = 0x633d6b1c, which failed. Testing LLRR produced local_c = 0x40475194, satisfying the condition.
Success Path: The sequence LLRR navigates the structure correctly, and wire_blue is decremented, indicating success.

Solution

Input: LLRR
Result: The BLUE lock disengages, displaying "VOLTAGE REROUTED FROM REMOTE DETONATION RECEIVER", and the bomb interface updates with three *s in the SECONDS field.


🔴 Phase 4: RED
Objective
Enter a clock resynchronization sequence to match a rotating sequence derived from random numbers.
Analysis

Red Preflight: The red_preflight function generates three random numbers (r, _DAT_0804c268, _DAT_0804c26c) using rand(), displayed as hex values (6B8B4567, 327B23C6, 643C9869). These are used to compute a sequence.
Red Function: The red function compares each character of the input buffer against a lookup table (ABCDEFGHJKLMNPQRSTUVWXYZ23456789) indexed by _DAT_0804c26c & 0x1f. The values _DAT_0804c26c, _DAT_0804c268, and r are rotated right by 5 bits each iteration, and the loop runs up to 19 times (buffer size limit).
Sequence Generation: Using the provided clock sync values, we compute the sequence:
Start with _DAT_0804c26c = 0x643C9869.
For each character, index the lookup table with _DAT_0804c26c & 0x1f, then rotate _DAT_0804c26c, _DAT_0804c268, and r right by 5 bits.
This produces the sequence KDG3DU32D38EVVXJM64.


Verification: The input KDG3DU32D38EVVXJM64 matches the expected sequence, setting wire_red to 0.

Solution

Input: KDG3DU32D38EVVXJM64
Result: The RED lock disengages, and the bomb interface displays a [DISARM] option, with four *s in the SECONDS field.


🎉 Final Disarmament

Action: Selected [DISARM] from the menu.
Outcome: The bomb is fully disarmed, but a segmentation fault occurs, likely due to a post-disarmament cleanup issue in the binary. Despite this, all locks are disengaged, and the challenge is complete!


Tools Used

pwndbg: For debugging and inspecting memory/registers.
Ghidra: For decompiling and understanding the binary's logic.
bxxx: Custom tool for testing inputs (e.g., bxxx --char for YELLOW).


Conclusion
Defusing Dr. Von Noizeman's Nuclear Bomb was a wild ride through binary exploitation! From decoding ASCII passwords in YELLOW, exploiting buffer overflows in GREEN, navigating circuit paths in BLUE, to cracking a pseudo-random sequence in RED, each phase tested our reverse engineering prowess. The bomb is disarmed, and the world is safe... for now! 😎
Final Passwords:

YELLOW: 84371065
GREEN: dcaotdaeAAAA
BLUE: LLRR
RED: KDG3DU32D38EVVXJM64

Happy hacking, and stay curious!
