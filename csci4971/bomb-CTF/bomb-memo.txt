---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___             
    /  / /  /   /  / /  /   /  / /  /             
   /__/ /__/   /__/ /__/   /__/ /__/              
     HOURS      MINUTES     SECONDS               
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+

pwndbg> checksec 
File:     bomb
Arch:     i386
RELRO:      Partial RELRO
Stack:      Canary found
NX:         NX unknown - GNU_STACK missing
PIE:        No PIE (0x8048000)
Stack:      Executable
RWX:        Has RWX segments
Stripped:   No
Debuginfo:  Yes

pwndbg> info functions 
All defined functions:

Non-debugging symbols:
0x08048674  _init
0x080486b4  srand@plt
0x080486c4  getchar@plt
0x080486d4  signal@plt
0x080486e4  __gmon_start__@plt
0x080486f4  putchar@plt
0x08048704  fgets@plt
0x08048714  __libc_start_main@plt
0x08048724  usleep@plt
0x08048734  fflush@plt
0x08048744  printf@plt
0x08048754  raise@plt
0x08048764  strcasecmp@plt
0x08048774  time@plt
0x08048784  __stack_chk_fail@plt
0x08048794  pthread_create@plt
0x080487a4  sleep@plt
0x080487b4  puts@plt
0x080487c4  rand@plt
0x080487d4  strncmp@plt
0x080487e4  strcmp@plt
0x080487f4  exit@plt
0x08048840  __do_global_dtors_aux
0x080488a0  frame_dummy
0x080488c4  gettimeleft
0x08048a4c  menu
0x08048fb4  kaboom
0x08048fc8  libc_start_main
0x080491cf  disarm_handler
0x080494ca  main
0x080496e8  yellow_preflight
0x08049719  yellow
0x080497a4  red_preflight
0x08049831  red
0x080498cc  postred
0x080498d4  green_preflight
0x08049904  green
0x080499c0  blue_preflight
0x080499f1  blue
0x08049b00  __libc_csu_fini
0x08049b10  __libc_csu_init
0x08049b6a  __i686.get_pc_thunk.bx
0x08049b70  __do_global_ctors_aux
0x08049b9c  _fini

pwndbg> disassemble yellow
Dump of assembler code for function yellow:
   0x08049719 <+0>:     push   ebp
   0x0804971a <+1>:     mov    ebp,esp
   0x0804971c <+3>:     sub    esp,0x8
   0x0804971f <+6>:     call   0x80496e8 <yellow_preflight>
   0x08049724 <+11>:    movzx  eax,BYTE PTR ds:0x804c24c
   0x0804972b <+18>:    cmp    al,0x38
   0x0804972d <+20>:    jne    0x804977c <yellow+99>
   0x0804972f <+22>:    movzx  eax,BYTE PTR ds:0x804c24d
   0x08049736 <+29>:    cmp    al,0x34
   0x08049738 <+31>:    jne    0x804977c <yellow+99>
   0x0804973a <+33>:    movzx  eax,BYTE PTR ds:0x804c24e
   0x08049741 <+40>:    cmp    al,0x33
   0x08049743 <+42>:    jne    0x804977c <yellow+99>
   0x08049745 <+44>:    movzx  eax,BYTE PTR ds:0x804c24f
   0x0804974c <+51>:    cmp    al,0x37
   0x0804974e <+53>:    jne    0x804977c <yellow+99>
   0x08049750 <+55>:    movzx  eax,BYTE PTR ds:0x804c250
   0x08049757 <+62>:    cmp    al,0x31
   0x08049759 <+64>:    jne    0x804977c <yellow+99>
   0x0804975b <+66>:    movzx  eax,BYTE PTR ds:0x804c251
   0x08049762 <+73>:    cmp    al,0x30
   0x08049764 <+75>:    jne    0x804977c <yellow+99>
   0x08049766 <+77>:    movzx  eax,BYTE PTR ds:0x804c252
   0x0804976d <+84>:    cmp    al,0x36
   0x0804976f <+86>:    jne    0x804977c <yellow+99>
   0x08049771 <+88>:    movzx  eax,BYTE PTR ds:0x804c253
   0x08049778 <+95>:    cmp    al,0x35
   0x0804977a <+97>:    je     0x804978b <yellow+114>
   0x0804977c <+99>:    mov    eax,ds:0x804c124
   0x08049781 <+104>:   shl    eax,0xa
   0x08049784 <+107>:   mov    ds:0x804c124,eax
   0x08049789 <+112>:   jmp    0x80497a1 <yellow+136>
   0x0804978b <+114>:   mov    DWORD PTR [esp],0x804a1f4
   0x08049792 <+121>:   call   0x80487b4 <puts@plt>
   0x08049797 <+126>:   mov    DWORD PTR ds:0x804c124,0x0
   0x080497a1 <+136>:   leave
   0x080497a2 <+137>:   ret
End of assembler dump.

aov@ArtOfVector-Lab:~$ bxxx --char 0x3834333731303635
84371065

warning: Unable to find libthread_db matching inferior's thread library, thread debugging will not be available.
[New LWP 634]
---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___             
    /  / /  /   /  / /  /   /  / /  /             
   /__/ /__/   /__/ /__/   /__/ /__/              
     HOURS      MINUTES     SECONDS               
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+
  MENU SELECTION: 1
  ENTER UNLOCK PASSWORD 1: 84371065
  UNLOCK PASSWORD 1 ACCEPTED, LOCK DISENGAGED
  PRESS ENTER TO RETURN TO MENU
---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___   *         
    /  / /  /   /  / /  /   /  / /  /   .         
   /__/ /__/   /__/ /__/   /__/ /__/    .         
     HOURS      MINUTES     SECONDS     *         
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+
  MENU SELECTION:

Yellow section is complete!

Section 2: green

0x08049936 in green ()
LEGEND: STACK | HEAP | CODE | DATA | WX | RODATA
────────────────────────────────────[ REGISTERS / show-flags off / show-compact-regs off ]─────────────────────────────────────
 EAX  0xffffccf4 —▸ 0xf7fd000a ◂— and al, 0x20
 EBX  0xf7fa8000 ◂— 0x225dac
 ECX  0xffffccf4 —▸ 0xf7fd000a ◂— and al, 0x20
 EDX  0xf7fa99c0 ◂— 0
 EDI  0xf7ffcb80 (_rtld_global_ro) ◂— 0
 ESI  0xffffce14 —▸ 0xffffcf8c ◂— '/bomb'
 EBP  0xffffcd08 —▸ 0xffffcd48 —▸ 0xf7ffd020 (_rtld_global) —▸ 0xf7ffda40 ◂— 0
 ESP  0xffffccd0 —▸ 0xffffccf4 —▸ 0xf7fd000a ◂— and al, 0x20
*EIP  0x8049936 (green+50) ◂— mov dword ptr [esp], password
──────────────────────────────────────────────[ DISASM / i386 / set emulate on ]───────────────────────────────────────────────
   0x804991f <green+27>    mov    dword ptr [esp], eax       [0xffffccd0] <= 0xffffccf4 —▸ 0xf7fd8f94 ◂— pop edx
   0x8049922 <green+30>    call   green_preflight             <green_preflight>

   0x8049927 <green+35>    mov    dword ptr [esp + 8], 8        [0xffffccd8] <= 8
   0x804992f <green+43>    lea    eax, [ebp - 0x14]             EAX => 0xffffccf4 —▸ 0xf7fd000a ◂— and al, 0x20
   0x8049932 <green+46>    mov    dword ptr [esp + 4], eax      [0xffffccd4] <= 0xffffccf4 —▸ 0xf7fd000a ◂— and al, 0x20       
 ► 0x8049936 <green+50>    mov    dword ptr [esp], password     [0xffffccd0] <= 0x804a2c0 (password) ◂— arpl word ptr fs:[ecx + 0x6f], sp /* 'dcaotdae' */
   0x804993d <green+57>    call   strncmp@plt                 <strncmp@plt>

   0x8049942 <green+62>    test   eax, eax
   0x8049944 <green+64>    jne    green+138                   <green+138>

   0x8049946 <green+66>    mov    dword ptr [esp], 0x804a2fc
   0x804994d <green+73>    call   puts@plt                    <puts@plt>
───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
pwndbg> 
warning: Unable to find libthread_db matching inferior's thread library, thread debugging will not be available.
[New LWP 2720]
---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___               
    /  / /  /   /  / /  /   /  / /  /               
   /__/ /__/   /__/ /__/   /__/ /__/                
     HOURS      MINUTES     SECONDS                 
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+
  MENU SELECTION: 2
  ENTER UNLOCK PASSWORD 2:  dcaotdae

Thread 1 "bomb" hit Breakpoint 1, 0x0804990a in green ()

0xf7f10469 in ?? () from /lib32/libc.so.6
LEGEND: STACK | HEAP | CODE | DATA | WX | RODATA
─────────────────────────────────────[ REGISTERS / show-flags off / show-compact-regs off ]─────────────────────────────────────
 EAX  0xffffccf4 ◂— 'dcaotdae\n'
 EBX  0xf7fa8000 ◂— 0x225dac
 ECX  0x804d649 ◂— 0
*EDX  0x804a2c0 (password) ◂— arpl word ptr fs:[ecx + 0x6f], sp /* 'dcaotdae' */
 EDI  0xf7ffcb80 (_rtld_global_ro) ◂— 0
 ESI  0xffffce14 —▸ 0xffffcf8c ◂— '/bomb-CTF/bombs/bomb'
 EBP  0xffffcd08 —▸ 0xffffcd48 —▸ 0xf7ffd020 (_rtld_global) —▸ 0xf7ffda40 ◂— 0
 ESP  0xffffccc8 —▸ 0xffffcd08 —▸ 0xffffcd48 —▸ 0xf7ffd020 (_rtld_global) —▸ 0xf7ffda40 ◂— ...
*EIP  0xf7f10469 ◂— mov eax, dword ptr [esp + 0xc]
───────────────────────────────────────────────[ DISASM / i386 / set emulate on ]───────────────────────────────────────────────
   0xf7fd8f9b    mov    eax, dword ptr [esp + 4]
   0xf7fd8f9f    ret    0xc

   0xf7f10460    endbr32
   0xf7f10464    push   ebp
   0xf7f10465    mov    edx, dword ptr [esp + 8]        EDX, [0xffffccd0] => 0x804a2c0 (password) ◂— arpl word ptr fs:[ecx + 0x6f], sp /* 'dcaotdae' */
 ► 0xf7f10469    mov    eax, dword ptr [esp + 0xc]      EAX, [0xffffccd4] => 0xffffccf4 ◂— 'dcaotdae\n'
   0xf7f1046d    mov    ebp, dword ptr [esp + 0x10]     EBP, [0xffffccd8] => 8
   0xf7f10471    test   ebp, ebp                        8 & 8     EFLAGS => 0x202 [ cf pf af zf sf IF df of ]
   0xf7f10473    je     0xf7f10672                  <0xf7f10672>

   0xf7f10479    mov    cx, dx        CX => 0xa2c0
   0xf7f1047c    and    cx, 0xfff     CX => 0x2c0 (0xa2c0 & 0xfff)

aov@ArtOfVector-Lab:~$ bxxx --dec 0xc
12

pwndbg> 
  ENTER UNLOCK PASSWORD 2: dcaotdaeAAAAA
   0x8049942 <green+62>    test   eax, eax                      0 & 0     EFLAGS => 0x246 [ cf PF af ZF sf IF df of ]
   0x8049944 <green+64>    jne    green+138                   <green+138>

   0x8049946 <green+66>    mov    dword ptr [esp], 0x804a2fc     [0xffffcc80] <= 0x804a2fc ◂— sbb ebx, dword ptr [ebx + 0x34]      
   0x804994d <green+73>    call   puts@plt                    <puts@plt>

   0x8049952 <green+78>    mov    eax, dword ptr [ebp - 8]       EAX, [0xffffccb0] => 0xa41
 ► 0x8049955 <green+81>    and    eax, 1                         EAX => 1 (0xa41 & 0x1)
   0x8049958 <green+84>    test   eax, eax                       1 & 1     EFLAGS => 0x202 [ cf pf af zf sf IF df of ]
   0x804995a <green+86>    sete   al
   0x804995d <green+89>    movzx  eax, al                        EAX => 0
   0x8049960 <green+92>    mov    dword ptr [ebp - 8], eax       [0xffffccb0] <= 0
   0x8049963 <green+95>    mov    dword ptr [esp], 0x7a120       [0xffffcc80] <= 0x7a120
─────────────────────────────────────────────────────────────[ STACK ]─────────────────────────────────────────────────────────────
00:0000│ esp 0xffffcc80 —▸ 0x804a2fc ◂— sbb ebx, dword ptr [ebx + 0x34]
01:0004│-034 0xffffcc84 —▸ 0xffffcca4 ◂— 'dcaotdaeAAAAA\n'
02:0008│-030 0xffffcc88 ◂— 8
───────────────────────────────────────────────────────────[ BACKTRACE ]───────────────────────────────────────────────────────────
 ► 0 0x8049955 green+81
   1 0x80495c8 main+254
   2 0xf7da3519 None
───────────────────────────────────────────────────────[ THREADS (2 TOTAL) ]───────────────────────────────────────────────────────
  ► 1   "bomb" stopped: 0x8049955 <green+81>
    2   "bomb" stopped: 0xf7fc4569 <__kernel_vsyscall+9>
───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___               
    /  / /  /   /  / /  /   /  / /  /               
   /__/ /__/   /__/ /__/   /__/ /__/              
     HOURS      MINUTES     SECONDS               
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+
  MENU SELECTION: 2
  ENTER UNLOCK PASSWORD 2: dcaotdaeAAAA
  UNLOCK PASSWORD 2 ACCEPTED, LOCK DISENGAGED
  ACTION OVERRIDDEN FROM USER NOIZEV, LOCK RE-ENGAGED
  PRESS ENTER TO RETURN TO MENU
---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___             
    /  / /  /   /  / /  /   /  / /  /               
   /__/ /__/   /__/ /__/   /__/ /__/              
     HOURS      MINUTES     SECONDS               
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+
  MENU SELECTION:

password 2 is incorrect 

debug again

pwndbg> 
0x0804992f in green ()
LEGEND: STACK | HEAP | CODE | DATA | WX | RODATA
──────────────────────────────────────────────────────────[ REGISTERS / show-flags off / show-compact-regs off ]──────────────────────────────────────────────────────────
 EAX  0xffffcca4 ◂— 'dcaotdaeAAAA\n'
 EBX  0xf7fa8000 ◂— 0x225dac
 ECX  0x804d64d ◂— 0
 EDX  0xf7fa99c0 ◂— 0
 EDI  0xf7ffcb80 (_rtld_global_ro) ◂— 0
 ESI  0xffffcdc4 —▸ 0xffffcf3a ◂— '/bomb-CTF/bombs/bomb'
 EBP  0xffffccb8 —▸ 0xffffccf8 —▸ 0xf7ffd020 (_rtld_global) —▸ 0xf7ffda40 ◂— 0
 ESP  0xffffcc80 —▸ 0xffffcca4 ◂— 'dcaotdaeAAAA\n'
*EIP  0x804992f (green+43) ◂— lea eax, [ebp - 0x14]
────────────────────────────────────────────────────────────────────[ DISASM / i386 / set emulate on ]────────────────────────────────────────────────────────────────────
   0x8049915 <green+17>    mov    dword ptr [ebp - 8], 1     [0xffffccb0] <= 1
   0x804991c <green+24>    lea    eax, [ebp - 0x14]          EAX => 0xffffcca4 —▸ 0xf7fd8f94 ◂— pop edx
   0x804991f <green+27>    mov    dword ptr [esp], eax       [0xffffcc80] <= 0xffffcca4 —▸ 0xf7fd8f94 ◂— pop edx
   0x8049922 <green+30>    call   green_preflight             <green_preflight>

   0x8049927 <green+35>    mov    dword ptr [esp + 8], 8        [0xffffcc88] <= 8
 ► 0x804992f <green+43>    lea    eax, [ebp - 0x14]             EAX => 0xffffcca4 ◂— 'dcaotdaeAAAA\n'
   0x8049932 <green+46>    mov    dword ptr [esp + 4], eax      [0xffffcc84] <= 0xffffcca4 ◂— 'dcaotdaeAAAA\n'
   0x8049936 <green+50>    mov    dword ptr [esp], password     [0xffffcc80] <= 0x804a2c0 (password) ◂— arpl word ptr fs:[ecx + 0x6f], sp /* 'dcaotdae' */
   0x804993d <green+57>    call   strncmp@plt                 <strncmp@plt>

   0x8049942 <green+62>    test   eax, eax
   0x8049944 <green+64>    jne    green+138                   <green+138>
────────────────────────────────────────────────────────────────────────────────[ STACK ]─────────────────────────────────────────────────────────────────────────────────
00:0000│ esp 0xffffcc80 —▸ 0xffffcca4 ◂— 'dcaotdaeAAAA\n'
01:0004│-034 0xffffcc84 —▸ 0xf7f11350 ◂— endbr32
02:0008│-030 0xffffcc88 ◂— 8
03:000c│-02c 0xffffcc8c —▸ 0xf7fa8000 ◂— 0x225dac
04:0010│-028 0xffffcc90 —▸ 0xffffcdc4 —▸ 0xffffcf3a ◂— /bomb-CTF/bombs/bomb'
05:0014│-024 0xffffcc94 —▸ 0xf7fa8000 ◂— 0x225dac
06:0018│-020 0xffffcc98 —▸ 0xffffcdc4 —▸ 0xffffcf3a ◂— '/bomb-CTF/bombs/bomb'
07:001c│-01c 0xffffcc9c —▸ 0xf7ffcb80 (_rtld_global_ro) ◂— 0
──────────────────────────────────────────────────────────────────────────────[ BACKTRACE ]───────────────────────────────────────────────────────────────────────────────
 ► 0 0x804992f green+43
   1 0x80495c8 main+254
   2 0xf7da3519 None
──────────────────────────────────────────────────────────────────────────[ THREADS (2 TOTAL) ]───────────────────────────────────────────────────────────────────────────
  ► 1   "bomb" stopped: 0x804992f <green+43>
    2   "bomb" stopped: 0xf7fc4569 <__kernel_vsyscall+9>
──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
pwndbg> x/4wx $ebp-0x14
0xffffcca4:     0x6f616364      0x65616474      0x41414141      0x0000000a
pwndbg>

   0x8049942 <green+62>    test   eax, eax                      0 & 0     EFLAGS => 0x246 [ cf PF af ZF sf IF df of ]
   0x8049944 <green+64>    jne    green+138                   <green+138>

   0x8049946 <green+66>    mov    dword ptr [esp], 0x804a2fc     [0xffffcc80] <= 0x804a2fc ◂— sbb ebx, dword ptr [ebx + 0x34]
   0x804994d <green+73>    call   puts@plt                    <puts@plt>

   0x8049952 <green+78>    mov    eax, dword ptr [ebp - 8]       EAX, [0xffffccb0] => 0xa
 ► 0x8049955 <green+81>    and    eax, 1                         EAX => 0 (0xa & 0x1)
   0x8049958 <green+84>    test   eax, eax                       0 & 0     EFLAGS => 0x246 [ cf PF af ZF sf IF df of ]
   0x804995a <green+86>    sete   al
   0x804995d <green+89>    movzx  eax, al                        EAX => 1
   0x8049960 <green+92>    mov    dword ptr [ebp - 8], eax       [0xffffccb0] <= 1
   0x8049963 <green+95>    mov    dword ptr [esp], 0x7a120       [0xffffcc80] <= 0x7a120

---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___             
    /  / /  /   /  / /  /   /  / /  /             
   /__/ /__/   /__/ /__/   /__/ /__/              
     HOURS      MINUTES     SECONDS               
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+
  MENU SELECTION: 2
  ENTER UNLOCK PASSWORD 2: dcaotdaeAAAA
  UNLOCK PASSWORD 2 ACCEPTED, LOCK DISENGAGED
  ACTION OVERRIDDEN FROM USER NOIZEV, LOCK RE-ENGAGED
  PRESS ENTER TO RETURN TO MENU
---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___   *  *      
    /  / /  /   /  / /  /   /  / /  /   .  .      
   /__/ /__/   /__/ /__/   /__/ /__/    .  .      
     HOURS      MINUTES     SECONDS     *  *      
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+

pass password 2 = dcaotdaeAAAA 
complete green!!!

pwndbg> disassemble blue
Dump of assembler code for function blue:
   0x080499f1 <+0>:     push   ebp
   0x080499f2 <+1>:     mov    ebp,esp
   0x080499f4 <+3>:     sub    esp,0x18
   0x080499f7 <+6>:     call   0x80499c0 <blue_preflight>
   0x080499fc <+11>:    mov    DWORD PTR [ebp-0x4],0x804c160
   0x08049a03 <+18>:    mov    eax,DWORD PTR [ebp-0x4]
   0x08049a06 <+21>:    mov    eax,DWORD PTR [eax+0x4]
   0x08049a09 <+24>:    mov    DWORD PTR [ebp-0x8],eax
   0x08049a0c <+27>:    mov    DWORD PTR [ebp-0xc],0x0
   0x08049a13 <+34>:    jmp    0x8049a84 <blue+147>
   0x08049a15 <+36>:    mov    DWORD PTR [ebp-0x10],0x0
   0x08049a1c <+43>:    mov    eax,DWORD PTR [ebp-0xc]
   0x08049a1f <+46>:    movzx  eax,BYTE PTR [eax+0x804c24c]
   0x08049a26 <+53>:    movsx  eax,al
   0x08049a29 <+56>:    mov    DWORD PTR [ebp-0x14],eax
   0x08049a2c <+59>:    cmp    DWORD PTR [ebp-0x14],0x4c
   0x08049a30 <+63>:    je     0x8049a40 <blue+79>
   0x08049a32 <+65>:    cmp    DWORD PTR [ebp-0x14],0x52
   0x08049a36 <+69>:    je     0x8049a4a <blue+89>
   0x08049a38 <+71>:    cmp    DWORD PTR [ebp-0x14],0xa
   0x08049a3c <+75>:    je     0x8049a55 <blue+100>
   0x08049a3e <+77>:    jmp    0x8049a5e <blue+109>
   0x08049a40 <+79>:    mov    eax,DWORD PTR [ebp-0x4]
   0x08049a43 <+82>:    mov    eax,DWORD PTR [eax]
   0x08049a45 <+84>:    mov    DWORD PTR [ebp-0x4],eax
   0x08049a48 <+87>:    jmp    0x8049a71 <blue+128>
   0x08049a4a <+89>:    mov    eax,DWORD PTR [ebp-0x4]
   0x08049a4d <+92>:    mov    eax,DWORD PTR [eax+0x8]
   0x08049a50 <+95>:    mov    DWORD PTR [ebp-0x4],eax
   0x08049a53 <+98>:    jmp    0x8049a71 <blue+128>
   0x08049a55 <+100>:   mov    DWORD PTR [ebp-0x10],0x1
   0x08049a5c <+107>:   jmp    0x8049a71 <blue+128>
   0x08049a5e <+109>:   mov    DWORD PTR [ebp-0x10],0x1
   0x08049a65 <+116>:   mov    DWORD PTR [esp],0x804a3bb
   0x08049a6c <+123>:   call   0x80487b4 <puts@plt>
   0x08049a71 <+128>:   cmp    DWORD PTR [ebp-0x10],0x0
   0x08049a75 <+132>:   jne    0x8049a8a <blue+153>
   0x08049a77 <+134>:   mov    eax,DWORD PTR [ebp-0x4]
   0x08049a7a <+137>:   mov    eax,DWORD PTR [eax+0x4]
   0x08049a7d <+140>:   xor    DWORD PTR [ebp-0x8],eax
   0x08049a80 <+143>:   add    DWORD PTR [ebp-0xc],0x1
   0x08049a84 <+147>:   cmp    DWORD PTR [ebp-0xc],0xe
   0x08049a88 <+151>:   jle    0x8049a15 <blue+36>
   0x08049a8a <+153>:   mov    DWORD PTR [esp],0x804a3c0
   0x08049a91 <+160>:   call   0x8048744 <printf@plt>
   0x08049a96 <+165>:   mov    eax,ds:0x804c240
   0x08049a9b <+170>:   mov    DWORD PTR [esp],eax
   0x08049a9e <+173>:   call   0x8048734 <fflush@plt>
   0x08049aa3 <+178>:   mov    DWORD PTR [esp],0x1
   0x08049aaa <+185>:   call   0x80487a4 <sleep@plt>
   0x08049aaf <+190>:   mov    DWORD PTR [esp],0x804a3eb
   0x08049ab6 <+197>:   call   0x80487b4 <puts@plt>
   0x08049abb <+202>:   mov    DWORD PTR [esp],0x7a120
   0x08049ac2 <+209>:   call   0x8048724 <usleep@plt>
   0x08049ac7 <+214>:   mov    eax,ds:0x804a384
   0x08049acc <+219>:   cmp    DWORD PTR [ebp-0x8],eax
   0x08049acf <+222>:   jne    0x8049aec <blue+251>
   0x08049ad1 <+224>:   mov    DWORD PTR [esp],0x804a3fc
   0x08049ad8 <+231>:   call   0x80487b4 <puts@plt>
   0x08049add <+236>:   mov    eax,ds:0x804c140
   0x08049ae2 <+241>:   sub    eax,0x1
   0x08049ae5 <+244>:   mov    ds:0x804c140,eax
   0x08049aea <+249>:   jmp    0x8049af9 <blue+264>
   0x08049aec <+251>:   mov    eax,ds:0x804c140
   0x08049af1 <+256>:   add    eax,0x1
   0x08049af4 <+259>:   mov    ds:0x804c140,eax
   0x08049af9 <+264>:   leave
   0x08049afa <+265>:   ret
End of assembler dump.

ghidra decomplied code

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void blue(void)

{
  char cVar1;
  bool bVar2;
  int local_10;
  uint local_c;
  undefined **local_8;
  
  blue_preflight();
  local_8 = &graph;
  local_c = _DAT_0804c164;
  for (local_10 = 0; local_10 < 0xf; local_10 = local_10 + 1) {
    bVar2 = false;
    cVar1 = (&buffer)[local_10];
    if (cVar1 == 'L') {
      local_8 = (undefined **)*local_8;
    }
    else if (cVar1 == 'R') {
      local_8 = (undefined **)local_8[2];
    }
    else if (cVar1 == '\n') {
      bVar2 = true;
    }
    else {
      bVar2 = true;
      puts("boom");
    }
    if (bVar2) break;
    local_c = local_c ^ (uint)local_8[1];
  }
  printf("\x1b[46m \x1b[0m\x1b[36m PROGRAMMING GATE ARRAY... ");
  fflush(stdout);
  sleep(1);
  puts("SUCCEEDED\x1b[0m");
  usleep(500000);
  if (local_c == 0x40475194) {
    puts("\x1b[46m \x1b[0m\x1b[36m VOLTAGE REROUTED FROM REMOTE DETONATION RECEIVER \x1b[0m");
    wire_blue = wire_blue + -1;
  }
  else {
    wire_blue = wire_blue + 1;
  }
  return;
}

---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___             
    /  / /  /   /  / /  /   /  / /  /             
   /__/ /__/   /__/ /__/   /__/ /__/              
     HOURS      MINUTES     SECONDS               
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+
  MENU SELECTION: 3
  ENTER CIRCUIT TRAVERSAL PATH: LLR
─────────────────────────────────────────────────────[ DISASM / i386 / set emulate on ]──────────────────────────────────────────────────────
   0x8049ab6 <blue+197>    call   puts@plt                    <puts@plt>

   0x8049abb <blue+202>    mov    dword ptr [esp], 0x7a120         [0xffffcca0] <= 0x7a120
   0x8049ac2 <blue+209>    call   usleep@plt                  <usleep@plt>

   0x8049ac7 <blue+214>    mov    eax, dword ptr [0x804a384]       EAX, [solution] => 0x40475194
   0x8049acc <blue+219>    cmp    dword ptr [ebp - 8], eax         0x633d6b1c - 0x40475194     EFLAGS => 0x206 [ cf PF af zf sf IF df of ]   
 ► 0x8049acf <blue+222>  ✔ jne    blue+251                    <blue+251>
    ↓
   0x8049aec <blue+251>    mov    eax, dword ptr [0x804c140]       EAX, [wire_blue] => 1
   0x8049af1 <blue+256>    add    eax, 1                           EAX => 2 (1 + 1)
   0x8049af4 <blue+259>    mov    dword ptr [0x804c140], eax       [wire_blue] <= 2
   0x8049af9 <blue+264>    leave
   0x8049afa <blue+265>    ret                                <main+310>
────────────────────────────────────────────────────────────────[ BACKTRACE ]────────────────────────────────────────────────────────────────
 ► 0 0x8049acf blue+222
   1 0x8049600 main+310
   2 0xf7da3519 None
────────────────────────────────────────────────────────────[ THREADS (2 TOTAL) ]────────────────────────────────────────────────────────────
  ► 1   "bomb" stopped: 0x8049acf <blue+222>
    2   "bomb" stopped: 0xf7fc4569 <__kernel_vsyscall+9>
─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

I checked value of 0x40475194.

   0x8049acc <blue+219>    cmp    dword ptr [ebp - 8], eax         0x633d6b1c - 0x40475194     EFLAGS => 0x206 [ cf PF af zf sf IF df of ]   


pwndbg> x/4x $ebp - 8
0xffffccb0:     0x633d6b1c      0x0804c184      0xffffccf8      0x08049600

---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___             
    /  / /  /   /  / /  /   /  / /  /             
   /__/ /__/   /__/ /__/   /__/ /__/              
     HOURS      MINUTES     SECONDS               
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+
  MENU SELECTION: 3
  ENTER CIRCUIT TRAVERSAL PATH: LLRR

─────────────────────────────────────────────────────[ DISASM / i386 / set emulate on ]──────────────────────────────────────────────────────
   0x8049aaf <blue+190>    mov    dword ptr [esp], 0x804a3eb       [0xffffcca0] <= 0x804a3eb ◂— push ebx
   0x8049ab6 <blue+197>    call   puts@plt                    <puts@plt>

   0x8049abb <blue+202>    mov    dword ptr [esp], 0x7a120         [0xffffcca0] <= 0x7a120
   0x8049ac2 <blue+209>    call   usleep@plt                  <usleep@plt>

   0x8049ac7 <blue+214>    mov    eax, dword ptr [0x804a384]       EAX, [solution] => 0x40475194
 ► 0x8049acc <blue+219>    cmp    dword ptr [ebp - 8], eax         0x40475194 - 0x40475194     EFLAGS => 0x246 [ cf PF af ZF sf IF df of ]   
   0x8049acf <blue+222>    jne    blue+251                    <blue+251>

   0x8049ad1 <blue+224>    mov    dword ptr [esp], 0x804a3fc       [0xffffcca0] <= 0x804a3fc ◂— sbb ebx, dword ptr [ebx + 0x34]
   0x8049ad8 <blue+231>    call   puts@plt                    <puts@plt>

   0x8049add <blue+236>    mov    eax, dword ptr [0x804c140]       EAX, [wire_blue]
   0x8049ae2 <blue+241>    sub    eax, 1
────────────────────────────────────────────────────────────────[ BACKTRACE ]────────────────────────────────────────────────────────────────
 ► 0 0x8049acc blue+219
   1 0x8049600 main+310
   2 0xf7da3519 None
────────────────────────────────────────────────────────────[ THREADS (2 TOTAL) ]────────────────────────────────────────────────────────────
  ► 1   "bomb" stopped: 0x8049acc <blue+219>
    2   "bomb" stopped: 0xf7fc4569 <__kernel_vsyscall+9>
─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___   *  *      
    /  / /  /   /  / /  /   /  / /  /   .  .      
   /__/ /__/   /__/ /__/   /__/ /__/    .  .      
     HOURS      MINUTES     SECONDS     *  *      
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+
  MENU SELECTION: 3
  ENTER CIRCUIT TRAVERSAL PATH: LLRR
  PROGRAMMING GATE ARRAY... SUCCEEDED
  VOLTAGE REROUTED FROM REMOTE DETONATION RECEIVER 
  PRESS ENTER TO RETURN TO MENU 
  complete blue!!!
---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___   *  *  *     
    /  / /  /   /  / /  /   /  / /  /   .  .  .     
   /__/ /__/   /__/ /__/   /__/ /__/    .  .  .   
     HOURS      MINUTES     SECONDS     *  *  *   
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+
  MENU SELECTION: 4
  CLOCK SYNC 6B8B4567
  CLOCK SYNC 327B23C6
  CLOCK SYNC 643C9869
  ENTER CLOCK RESYNCHRONIZATION SEQUENCE: ?
  PRESS ENTER TO RETURN TO MENU 
KABOOM

         .-^^---....,,--_
     _--/                \--_
    <                        >)
    |                         |
     \._                   _./
        ```--. . , ; .--'''
              | |   |
           .-=||  | |=-.
           `-=#$%&%$#=-'
              | ;  :|
     _____.,-#%&$@%#&#~,._____
Segmentation fault (core dumped)

red_preflight function decompiled code


void red_preflight(void)

{
  uint uVar1;
  int local_8;
  
  uVar1 = rand();
  r = uVar1 & 0x7fffffff;
  _DAT_0804c268 = rand(); The rand() function is a pseudo-random number generator available in both C and C++ through the <stdlib.h> (C) or <cstdlib> (C++) header.
  _DAT_0804c26c = rand();
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    printf("\x1b[41m \x1b[0m\x1b[31m CLOCK SYNC \x1b[0m%08X\n",(&r)[local_8]);
    usleep(500000);
  }
  printf("\x1b[41m \x1b[0m\x1b[31m ENTER CLOCK RESYNCHRONIZATION SEQUENCE: \x1b[0m");
  fgets(&buffer,0x15,stdin);
  return;
}


RED function decompiled code
void red(void)

{
  int local_c;
  
  red_preflight();
  local_c = 0;
  while( true ) {
    if (0x12 < local_c) {
      wire_red = 0;
      return;
    }
    if ((&buffer)[local_c] != "ABCDEFGHJKLMNPQRSTUVWXYZ23456789"[_DAT_0804c26c & 0x1f]) break;
    _DAT_0804c26c = _DAT_0804c268 << 0x1b | _DAT_0804c26c >> 5;
    _DAT_0804c268 = r << 0x1b | _DAT_0804c268 >> 5;
    r = r >> 5;
    local_c = local_c + 1;
  }
  wire_red = wire_red + 1;
  return;
}

  PRESS ENTER TO RETURN TO MENU ---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___   *  *  *   
    /  / /  /   /  / /  /   /  / /  /   .  .  .   
   /__/ /__/   /__/ /__/   /__/ /__/    .  .  .   
     HOURS      MINUTES     SECONDS     *  *  *   
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|       [1] YELLOW [2] GREEN [3] BLUE [4] RED       |
|                                                   |
+---------------------------------------------------+
  MENU SELECTION: 4
  CLOCK SYNC 6B8B4567
  CLOCK SYNC 327B23C6
  CLOCK SYNC 643C9869
  ENTER CLOCK RESYNCHRONIZATION SEQUENCE: KDG3DU32D38EVVXJM64
  PRESS ENTER TO RETURN TO MENU 
---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___   *  *  *  *
    /  / /  /   /  / /  /   /  / /  /   .  .  .  .
   /__/ /__/   /__/ /__/   /__/ /__/    .  .  .  .
     HOURS      MINUTES     SECONDS     *  *  *  *
+--------------------------------------- -- -- -- --+
|                                                   |
|      ,   DR. VON NOIZEMAN'S NUCLEAR BOMB   ,      |
|     /!\ AUTHORIZED ACCESS ONLY - KEEP OUT /!\     |
|                                                   |
|                     [DISARM]                      |
|                                                   |
+---------------------------------------------------+

KDG3DU32D38EVVXJM64
complete Red!!

  MENU SELECTION: DISARM
---------------------------------------- -- -- -- ---
     ___  ___    ___  ___    ___  ___   *  *  *  *
    /__  /__    /__  /__    /__  /__    .  .  .  .
   /    /      /    /      /    /       .  .  .  .
     HOURS      MINUTES     SECONDS     *  *  *  *
---------------------------------------- -- -- -- ---
Segmentation fault (core dumped)

yo~ finished at all!!