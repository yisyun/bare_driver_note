/* 4-2 */
.global _start

_start:

/* 1.啟動所有時鐘 */
ldr r0, =0X020C4068
ldr r1, =0xFFFFFFFF
str r1, [r0]

ldr r0, =0X020C406C
str r1, [r0]

ldr r0, =0X020C4070
str r1, [r0]

ldr r0, =0X020C4074
str r1, [r0]

ldr r0, =0X020C4078
str r1, [r0]

ldr r0, =0X020C407C
str r1, [r0]

ldr r0, =0X020C4080
str r1, [r0]


/* 2.設定GPIO1_IO03復用為GPIO1_IO03 */
ldr r0, =0X020C4068
ldr r1, =0xFFFFFFFF
str r1, [r0]

/* 3.設定GPIO1_IO03屬性 
*bit [16]:0 HYS關閉
*bit [15:14]:00 下拉
*bit [13]:0 keeper功能
*bit [12]:1 pull/keeper啟動
*bit [11]:0 關閉開路輸出 
*bit [7:6]:10 速度100MHz
*bit [5:3]:110 R0/R6 驅動程式能力
*bit [0]:0 低轉換率
*/

ldr r0, =0x020E02F4 /* SW_PAD_GPIO1_IO03_BASE */
ldr r1, =0x10B0
str r1,[r0]

/* 4.設定GPIO1_IO03為輸出*/
ldr r0, =0x0209C004 /* GPIO1_GDIR */
ldr r1, =0x0000008
str r1,[r0]

/* 5.開啟LED0, 設定GPIO1_IO03輸出低電位 */

ldr r0, =0x0209C000
ldr r1, =0
str r1,[r0]

loop:
    b loop



