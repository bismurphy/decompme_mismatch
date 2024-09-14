mipsel-linux-gnu-cpp -Iinclude -undef -Wall -fno-builtin -Dmips -D__GNUC__=2 -D__OPTIMIZE__ -D__mips__ -D__mips -Dpsx -D__psx__ -D__psx -D_PSYQ -D__EXTENSIONS__ -D_MIPSEL -D_LANGUAGE_C -DLANGUAGE_C -DNO_LOGS -DHACKS -DUSE_INCLUDE_ASM -lang-c src.c > preproc.c


cat preproc.c | ./cc1-gcc2.8.1-psx -G0 -w -O2 -quiet -mcpu=3000 -fgnu-linker -mgas -gcoff > gcc_asm.s

cat gcc_asm.s | python3 maspsx/maspsx.py > menos_asm.s

cat menos_asm.s | mipsel-linux-gnu-as -G0 -O2 -march=r3000 -mtune=r3000 -o compiled.o

mips-linux-gnu-objdump --disassemble compiled.o


