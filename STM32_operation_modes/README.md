# configuration setup for project

#### IDE:- STM32cubeIDE
#### Setup configuration according to SWV setup
#### copy code from
    https://github.com/niekiran/Embedded-C/blob/master/All_source_codes/target/itm_send_data.c
#### copy above code to this file
    /src/syscalls.c
#### call this function in same file (syscalls.c) under write function
```c
__attribute__((weak)) int _write(int file, char *ptr, int len)
                {
                 int DataIdx;

	             for (DataIdx = 0; DataIdx < len; DataIdx++)
	                 {
		             // __io_putchar(*ptr++);
		             ITM_SendChar(*ptr++);
	                 }
	                 return len;
                }
```
#### Don't forget to provide function prototype (syscalls.c)
    void ITM_SendChar(uint8_t ch);
#### Do following setting under debug conf setting in project
  1. **Debug probe:- ST-LINK(GDB)**
  2. **Interface :-  SWD**
  3. **Enable SWV**
#### In Debug Perspective
> window -> show view -> SWV -> SWV ITM Data console

#### In SWV ITM data console
> configure trace -> Enable ITM stimulus port -port 0
#### enable resister view
1. monitor xpsr binary value.
2. when processor enters handler mode binary value of XPSR will change.
#### Hit Run
#### See output in SWV ITM data console.
:+1: