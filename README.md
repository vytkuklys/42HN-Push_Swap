# 42HN-Push_Swap

This project sorts a list of non-duplicate numbers in an ascending order under a set of limitations.
### Limiting factors of sorting numbers:
* Numbers can only be sorted between two linked list stacks (a and b).
* Position of numbers on top of the stack can be altered by the following operations:
  * ```pushing``` top number from one linked list stack to another (e.g. pa, pb).
  * ```swapping``` top number with the second number of the stack (e.g. sa, sb).
  * ```rotating``` top number to the bottom of the stack (e.g. ra, rb).
* Position of numbers in the bottom of the stack can be altered by the following operation:
  * ```reversing``` stack by placing number in the bottom of the stack to the top(rra, rrb).
## Run Project on Mac
* Clone or fork this repository
* Type ```make``` command in the terminal
* Create a variable with random non-repeating numbers ```arg="3 2 1 0 55"```
* Execute program with the created variable: ```./push_swap $arg```
* To check if numbers were sorted correctly, redirect output to the checker: ```./push_swap $arg | ./checker $arg```
