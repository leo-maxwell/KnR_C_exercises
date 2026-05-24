# KnR_C_exercises
My approach to K&amp;R C book exercises

## Usage
Under project root:
`make exercise_x-x` builds the executable `exercise_x-x.out` under project root under corresponding chapter folders.

Every exercise, as long as put under the right chapter, could be `exercise_x-x.c` file or `exercise_x-x/` folder, and the building system will automatically build the executable using single file or all files under the folder. For an exercise those two forms should not exist together.

Add option `ASM=1` to also generate assembly files for inspection. For example, `make exercise_4-12 ASM=1`.

After finishing testing, use `make clean` to clean all generated artifacts.
