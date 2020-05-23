# This project is a demo of how to write inline-assambly code for Cortex-Mx


** Below statements copy "C variable(val) to resister R0**
```c
        int val=50;
	__asm volatile ("MOV R0,%0": :"r"(val) );
```
