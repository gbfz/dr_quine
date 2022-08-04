# dr-quine project at École 42
Quines in C and possibly ASM

A quine is a program whose output is identical to its source code. That's it :)

The goal of dr-quine is to create three quines with different constrains.

# First part: Colleen
A simple one. Just store the source code as a string inside the program.

# Second part: Grace
A bit more tough. Self-replication must be done with C macros.

# Third part: Sully
This one does not require the source and its output to be identical.

Instead, a Sully creates a Sully_X.c, where X is the integer in its main() - 1. If the resulting X is greater than 0, it compiles and runs the new file.

Altogether, launching the original Sully produces 5 new files.
