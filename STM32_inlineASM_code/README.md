# This project is a demo of how to write inline-assambly code for Cortex-Mx


**Below statements copy "C variable(val) to resister R0**
```c
        int val=50;
	__asm volatile ("MOV R0,%0": :"r"(val) );
```

**Below statements read CONTROL resister value to C varable(control_reg)**
```c
        int control_reg;
	//read CONTROL register to control_reg
	__asm volatile ("MRS %0,CONTROL":"=r"(control_reg));
```

**Below statements copy the content of pointer into another variable**
```c
        int p1 ,*p2 ;
	p2= (int*)0x20000008 ;
	__asm volatile ("LDR %0,[%1]":"=r"(p1):"r"(p2) ); //p1 = *p2
```

> Use disassembly and resister view in debug mode
> to visualize asm code and resister values
