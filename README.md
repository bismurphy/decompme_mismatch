1. Clone this repository
2. `git submodule update --init --recursive` (in order to get maspsx)
3. `./build.sh`. This will compile the code in src.c, and then print the objdump from it.
4. Compare this code to the scratch at https://decomp.me/scratch/4G973 and notice that what you get here does not match what is in the scratch.
 - In fact, it almost seems to be closer if you leave out -G0 on the scratch - note that asm instruction 64 is the "move a0, s0" instruction.
