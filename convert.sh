arm-none-eabi-strip sfil_sample.elf
makerom -f cci -o sfil_sample.3ds -rsf gw_workaround.rsf -target d -exefslogo -elf sfil_sample.elf -icon icon.bin -banner banner.bin