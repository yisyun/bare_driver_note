
.global _start

_start:

	mrs r0, cpsr
	bic r0, r0, #0x1f
	msr cpsr, r0

	ldr sp, =0X80200000
	b main
