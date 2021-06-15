// Sets up a function that takes four integers that declares a flag and a character buffer.
// Shows that the memory for the flag and buffer are stored on the stack, contained within a stack frame.
// A stack frame is a set of information: local vars, copies of registers, argument parameters, return address.
// Each stack frame refers to a sub-program call (e.g. a function).
// To return to the main program from a stack frame, the IP (Instruction Pointer) and the BP (Base/frame Pointer) have to be restored to their previous state (before sub-program execution).

// So, the current value of the BP is pushed to the stack. This is known as the SFP (Saved Frame Pointer).
// It will be used to restore the BP to its original state.
// The value of the SP (Stack Pointer) is then copied into the BP to set the new frame pointer.
// In this case, the frame pointer references the local variables flag and buffer.
// The memory allocated to flag and buffer is denoted by subtracting from the SP.

// The IP is restored by the return address (ret).
// At this point (after execution of the sub-program), the entire stack frame is popped.
// If there was a nested function, another stack frame would be pushed onto the stack to cover it.
// As each function completes, its equivalent stack frame is popped.
// So that execution can return to the program/function next in the stack's hierarchy. 

#include <stdio.h>

void testFunction(int a, int b, int c, int d)
{
    int flag;
    char buffer[10];

    flag = 31337;
    buffer[0] = 'A';
}

int main(void)
{
    testFunction(1, 2, 3, 4);
}
