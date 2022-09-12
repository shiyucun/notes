
# ARM汇编

- [ARM汇编](#arm汇编)
  - [条件码及标志位](#条件码及标志位)
  - [分支指令](#分支指令)
  - [数据处理指令](#数据处理指令)
    - [地址模式](#地址模式)
    - [移位操作](#移位操作)
    - [指令详解](#指令详解)
  - [加载/存储指令](#加载存储指令)
    - [单寄存器加载指令](#单寄存器加载指令)
    - [单寄存器存储指令](#单寄存器存储指令)
    - [多寄存器加载/存储](#多寄存器加载存储)
  - [栈操作](#栈操作)
  - [状态寄存器访问指令](#状态寄存器访问指令)
    - [MRS程序状态寄存器读指令](#mrs程序状态寄存器读指令)
    - [MSR程序状态寄存器写指令](#msr程序状态寄存器写指令)
    - [ARM寄存器到协处理器寄存器](#arm寄存器到协处理器寄存器)
    - [协处理器寄存器到ARM寄存器](#协处理器寄存器到arm寄存器)
  - [伪指令](#伪指令)
    - [ADR](#adr)
    - [ADRL](#adrl)
    - [LDR](#ldr)
    - [NOP](#nop)

ARM汇编指令为单周期指令，可条件执行(CPSR寄存器NZCV位)。

## 条件码及标志位

| 操作码 | 条件助记符 | 标志     | 含义                      |
| ------ | ---------- | -------- | ------------------------- |
| 0000   | EQ         | Z=1      | 相等                      |
| 0001   | NE         | Z=0      | 不相等                    |
| 0010   | CS/HS      | C=1      | 无符号数大于或等于        |
| 0011   | CC/LO      | C=0      | 无符号数小于              |
| 0100   | MI         | N=1      | 负数                      |
| 0101   | PL         | N=0      | 正数或零                  |
| 0110   | VS         | V=1      | 溢出                      |
| 0111   | VC         | V=0      | 没有溢出                  |
| 1000   | HI         | C=1,Z=0  | 无符号数大于              |
| 1001   | LS         | C=0,Z=1  | 无符号数小于或等于        |
| 1010   | GE         | N=V      | 有符号数大于或等于        |
| 1011   | LT         | N!=V     | 有符号数小于              |
| 1100   | GT         | Z=0,N=V  | 有符号数大于              |
| 1101   | LE         | Z=1,N!=V | 有符号数小于或等于        |
| 1110   | AL         | 任何     | 无条件执行 (指令默认条件) |
| 1111   | NV         | 任何     | 从不执行(不要使用)        |

## 分支指令

ARM跳转方式：

- 异常
- 使用分支指令
- 直接向PC赋值

ARMv4T 支持3条分支指令：B、BL、BX；ARMv5以后开始支持支持：BLX。

- B：跳转指令
- BL：带返回的跳转指令
- BX：带状态切换的跳转指令
- BLX：带返回和状态切换的跳转指令

<table>
  <tr>
    <td>指令</td>
    <td>格式: {cond}为条件助记符</td>
    <td>跳转范围</td>
    <td>代码</td>
  </tr>
  <tr>
    <td>B</td>
    <td>B{cond} label;</td>
    <td>PC±32M</td>
    <td>
<pre><code>start:
    cmp r0, r1
    beq not_copy
    mov r0, r1
not_copy:
    b .</code></pre>
    </td>
  </tr>
  <tr>
    <td>BL</td>
    <td>BL{cond} label;
    </td>
    <td>PC±32M</td>
    <td>
<pre><code>START:
    MOV R0, #1
    MOV R1, #2
    BL DoAdd
    B .
    …
DoAdd:
    ADD R0, R0, R1
    MOV PC, LR
    …</code></pre>
    </td>
  </tr>
  <tr>
    <td>BX</td>
    <td>BX{cond} adderss;</td>
    <td>绝对地址，4G范围</td>
    <td>
<pre><code>.CODE 32
ARM_code:
    ADR R0, THUMB_code + 1
    BX R0
    ……
.CODE 16
THUMB_code:
    ADR R0, ARM_code
    BX R0
    ……</code></pre>
    </td>
  </tr>
</table>

BL指令相较于B指令，在转移到子程序前会将下一条指令的地址拷贝到r14寄存器。

因此使用指令`MOV PC, LR`即可实现子程序返回。

## 数据处理指令

数据处理指令可细分为4类

- 数据传送指令（MOV、MVN）
- 算术运算指令（ADD、ADC、SUB、SBC、RSB、RSC）
- 位运算指令（AND、ORR、EOR、BIC）
- 比较指令（CMP、CMN、TST、TEQ）

数据处理指令的一般格式：

```text
<opcode>{cond}{S} <Rd>, <Rn>, <shifter_operand>
```

### 地址模式

第1操作数恒为寄存器Rn，shifter_operand即第2操作数，是一个移位操作数，共有11种形式：

| 格式                     | 说明                  |
| ------------------------ | --------------------- |
| #\<immediate\>           | 立即数方式            |
| \<Rm\>                   | 寄存器                |
| \<Rm\>, LSL #<shift_imm> | Rm逻辑左移shift_imm位 |
| \<Rm\>, LSL \<Rs\>       | Rm逻辑左移Rs位        |
| \<Rm\>, LSR #<shift_imm> | Rm逻辑右移shift_imm位 |
| \<Rm\>, LSR \<Rs\>       | Rm逻辑右移Rs位        |
| \<Rm\>, ASR #<shift_imm> | Rm算术右移shift_imm位 |
| \<Rm\>, ASR \<Rs\>       | Rm算术右移Rs位        |
| \<Rm\>, ROR #<shift_imm> | Rm循环右移shift_imm位 |
| \<Rm\>, ROR \<Rs\>       | Rm循环右移Rs位        |
| \<Rm\>, RRX              | Rm扩展的循环右移一位  |

### 移位操作

- LSL移位：逻辑左移，右侧补0
- LSR移位：逻辑右移，左侧补0
- ASR移位：算术右移，左侧补最高位
- ROR移位：循环右移
- RRX移位：带扩展的循环右移

### 指令详解

数据传送指令：

| 指令 | 格式                                   | 说明         |
| ---- | -------------------------------------- | ------------ |
| MOV  | MOV{cond}{S} \<Rd\>, <shifter_operand> | 数据传送     |
| MVN  | MVN{cond}{S} \<Rd\>, <shifter_operand> | 数据取反传送 |

算数运算指令：

| 指令 | 格式                                           | 说明                 |
| ---- | ---------------------------------------------- | -------------------- |
| ADD  | ADD{cond}{S} \<Rd\>, \<Rn\>, <shifter_operand> | 加法                 |
| ADC  | ADC{cond}{S} \<Rd\>, \<Rn\>, <shifter_operand> | 带进位的加法         |
| SUB  | SUB{cond}{S} \<Rd\>, \<Rn\>, <shifter_operand> | 减法                 |
| SBC  | SBC{cond}{S} \<Rd\>, \<Rn\>, <shifter_operand> | 带借位的减法         |
| RSB  | RSB{cond}{S} \<Rd\>, \<Rn\>, <shifter_operand> | 反向减法指令         |
| RSC  | RSC{cond}{S} \<Rd\>, \<Rn\>, <shifter_operand> | 带借位的反向减法指令 |

位运算指令：

| 指令 | 格式                                           | 说明   |
| ---- | ---------------------------------------------- | ------ |
| AND  | AND{cond}{S} \<Rd\>, \<Rn\>, <shifter_operand> | 位与   |
| ORR  | ORR{cond}{S} \<Rd\>, \<Rn\>, <shifter_operand> | 位或   |
| EOR  | EOR{cond}{S} \<Rd\>, \<Rn\>, <shifter_operand> | 异或   |
| BIC  | BIC{cond}{S} \<Rd\>, \<Rn\>, <shifter_operand> | 位清除 |

比较测试指令：

| 指令 | 格式                                | 说明     |
| ---- | ----------------------------------- | -------- |
| CMP  | CMP{cond} \<Rn\>, <shifter_operand> | 比较     |
| CMN  | CMN{cond} \<Rn\>, <shifter_operand> | 负值比较 |
| TST  | TST{cond} Rn, shifter_operand       | 位测试   |
| TEQ  | TEQ{cond} \<Rn\>, <shifter_operand> | 相等测试 |

## 加载/存储指令

数据处理指令只处理寄存器和立即数，因此与存储器交互需要使用加载/存储指令。

加载/存储指令可以访问存储器缓冲区中的数据、访问处理器外设、加载函数地址到PC寄存器实现程序跳转等功能。

加载/存储指令可以分为单寄存器加载/存储指令和多寄存器加载/存储指令。

### 单寄存器加载指令

| 指令语法格式                 | 说明               |
| ---------------------------- | ------------------ |
| LDR{{cond}} Rd, addressing   | 加载字数据         |
| LDR{{cond}}B Rd, addressing  | 加载无符号字节数据 |
| LDR{{cond}}H Rd, addressing  | 加载无符号半字数据 |
| LDR{{cond}}SB Rd, addressing | 加载有符号字节数据 |
| LDR{{cond}}SH Rd, addressing | 加载有符号半字数据 |

### 单寄存器存储指令

| 指令语法格式                | 说明         |
| --------------------------- | ------------ |
| STR{{cond}} Rd, addressing  | 存储字数据   |
| STR{{cond}}B Rd, addressing | 存储字节数据 |
| STR{{cond}}H Rd, addressing | 存储半字数据 |

### 多寄存器加载/存储

```text
多寄存器加载指令：LDM
    LDM{cond} {addressing_mode} Rb{!}, < Reglist >{^}
多寄存器存储指令：STM
    STM{cond} {addressing_mode} Rb{!}, < Reglist >{^}

参数说明：
    cond : 条件域
    addressing_mode：
        LDMIA / STMIA Increment After（先操作，后增加）
        LDMIB / STMIB Increment Before（先增加，后操作）
        LDMDA / STMDA Decrement After （先操作，后递减）
        LDMDB / STMDB Decrement Before （先递减，后操作）
    Rb : 基址寄存器
    ! : 更新基址寄存器
    Reglist: 源/目标寄存器列表（可以是16个寄存器的任何子集）
    ^ : 有两种作用，特权模式下使用用户模式下的寄存器，CPSR=SPSR
```

## 栈操作

栈的种类：

- Descending stacks（减栈）：栈向内存地址减小的方向变化
- Ascending stacks（加栈）：栈向内存地址增加的方向变化
- Full stacks（满栈）：栈指针指向的栈顶保存有效元素
- Empty stacks（空栈）：栈指针指向的栈顶未保存有效元素

栈操作指令：

ARM的栈操作指令是通过块传输指令实现的（多寄存器传输指令）

```text
STMFD (Push) Full Descending stack [多寄存器存储 - STMDB]
LDMFD (Pop) Full Descending stack [多寄存器加载 - LDMIA]
```

## 状态寄存器访问指令

### MRS程序状态寄存器读指令

```text
语法格式：
    MRS{cond} Rd,psr
参数说明：
    cond 条件码
    Rd目标寄存器（不能是R15）
    Psr 程序状态寄存器（CPSR，SPSR）
    MRS{<cond>} <Rd>, CPSR
    MRS{<cond>} <Rd>, SPSR
```

### MSR程序状态寄存器写指令

```text
语法格式：
    MSR{<cond>} CPSR_<fields>, #<immediate_8>
    MSR{<cond>} CPSR_<fields>, <Rm>
    MSR{<cond>} SPSR_<fields>, #<immediate_8>
    MSR{<cond>} SPSR_<fields>, <Rm>
参数说明：
    fields：域可以为以下字母（必须小写）的一个或组合
        c 控制域屏蔽字节(psr[7..0])
        x 扩展域屏蔽字节(psr[15..8])
        s 状态域屏蔽字节(psr[23..16])
        f 标志域屏蔽字节(psr[31..24])
    immediate_8：8位立即数
```

### ARM寄存器到协处理器寄存器

指令格式：`MCR{cond} <coproc>, <opcode_1>, <Rd>, <CRn>, <CRm> {, opcode_2}`

代码示例：

```text
MCR  p15, 0, r0, c1, c0, 0 ;写CP15的C1寄存器的0号物理寄存器（Control Register）
; ARM register transfer to Coproc 15
; opcode 1 = 0, opcode 2 = 0
; ARM source register = r0
; coproc dest registers are 1 and 0
```

### 协处理器寄存器到ARM寄存器

指令格式：`MRC{cond} <coproc>, <opcode_1>, <Rd>, <CRn>, <CRm> {, opcode_2}`

代码示例：

```text
MRC p15, 0, R0, c1, c0, 0 ;读CP15的C1寄存器的0号物理寄存器（Control Register）
; Coproc 15 transfer to ARM register
; opcode 1 = 0, opcode 2 = 0
; ARM destination register = R0
; coproc source registers are 1 and 0
```

## 伪指令

伪指令不属于 ARM 指令集中的指令，定义这些指令可以使ARM汇编程序设计变得更方便。

伪指令可以像其他 ARM 指令一样使用，汇编器会自动用一条 ARM 指令替换 ARM 伪指令。

ARM的伪指令包括：ADR、ADRL、LDR、NOP。

### ADR

```text
语法格式：
    ADR{cond} register, expr
参数说明：
    cond：条件码
    register：目标寄存器，如：R0等
    expr：地址表达式（相对于pc或寄存器）
加载地址范围：
    地址字对齐时： +/-1020 bytes（255×4）
    地址非字对齐时：+/-255bytes
```

### ADRL

```text
语法格式：
    ADRL{cond} register, expr
参数说明：
    cond：条件码
    register：目标寄存器，如：R0等
    expr：地址表达式（相对于pc或寄存器）
加载地址范围：
    地址字对齐时： -256K～256K
    地址非字对齐时： -64K～64K
```

### LDR

```text
语法格式：
    LDR{cond} register,=[expr | label_expr]
    从指令位置到文字池的偏移量必须小于4KB
```

代码示例：

```text
    ...
    LDR R1, =TestData
    LDR R0, [R1]
    ...
TestData:
    .word 0x12345678
```

```text
    LDR pc, =label
```

### NOP

NOP 伪指令在汇编时将会被代替成 ARM 中的空操作，可用于延时操作。
