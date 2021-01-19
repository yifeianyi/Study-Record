SET PATH=D:\Keil_stm32\ARM\ARMCC\Bin;C:\windows\system32;C:\windows;C:\windows\System32\Wbem;C:\windows\System32\WindowsPowerShell\v1.0\;C:\windows\System32\OpenSSH\;D:\Git\bin;D:\Node.js\;C:\Program Files\MySQL\MySQL Shell 8.0\bin\;C:\Users\YiFeiAnYi\AppData\Roaming\npm;D:\Microsoft VS Code\bin
SET CPU_TYPE=STM32F103VE
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x00B71B00
"D:\Keil_stm32\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\main.__i"
"D:\Keil_stm32\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f10x.__i"
"D:\Keil_stm32\ARM\ARMCC\Bin\ArmAsm" --Via ".\objects\startup_stm32f10x_hd._ia"
"D:\Keil_stm32\ARM\ARMCC\Bin\ArmLink" --Via ".\Objects\CreateFunByMyself.lnp"
"D:\Keil_stm32\ARM\ARMCC\Bin\fromelf.exe" ".\Objects\CreateFunByMyself.axf" --i32combined --output ".\Objects\CreateFunByMyself.hex"
