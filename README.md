![push_swap_banner](https://user-images.githubusercontent.com/86076158/206034679-45963924-cf29-4fcd-ba1e-27e98545497f.gif)

# Description

The Push_swap project is a simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

# Goal

Write two programs in C:

- The first, named `checker` which takes integer arguments and reads instructions on
the standard output. Once read, checker executes them and displays `OK` if integers
are sorted. Otherwise, it will display `KO`.
- The second one called `push_swap` which calculates and displays on the standard
output  the smallest program using Push_swap instruction language that sorts integer received as an argument.

# Game rules

- The game is made out of two stacks `A` and `B`
- Beginning:
    - `Stack A` contains all  the numbers in order they were given.
    - `Stack B` is empty.
- The goal is to get all the numbers into stack `A` in ascending order.
- Allowed operations:

| Operations | Desciption           |
|:-------------:|:-------------|
|      `pa`     | *push a* - take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
|      `pb`      | *push b* - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.|
|      `sa`| *swap a* - swap the first 2 elements at the top of stack a. (Do nothing if there is only one or no elements).  | 
| `sb` | *swap b* - swap the first 2 elements at the top of stack b. (Do nothing if there is only one or no elements).|
| `ss`|`sa` and `sb` at the same time. |
| `ra`|*rotate a* - shift up all elements of stack a by 1. The first element becomes the last one. |
| `rb`| *rotate b* - shift up all elements of stack b by 1. The first element becomes the last one.|
| `rr`| `ra` and `rb` at the same time|
| `rra`| *reverse rotate a* - shift down all elements of stack a by 1. The last element becomes the first one.|
| `rrb`| *reverse rotate a* - shift down all elements of stack b by 1. The last element becomes the first one.|
| `rrr`| `rra` and `rrb` at the same time|

# Algorithm
On this project programs *efficiency* is only measured by number of `instructions`. This allows us to make multiple checks before deciding which operation to execute next.

- First part:
  - `Push_swap` starts by pushing top two numbers from `a` to `b` no matter what they are. Reason for this is that two numbers are always *sorted*. What *sorted* means
in this context is that numbers can be ordered by only rotating the stack no matter how many numbers are in the stack.
  - Now we can start to calculate which number on `stack a` can we get to `stack b` using the least amount of operations. 
  In case of the number after we have done the first two `pb` operations only possible places are *on top* the stack or *between* the two numbers on 
  `stack b`.
  - The logic behind this approach is that we don't have to push the numbers to `stack b` in any specific order and we can make use of `rrr` and `rr`. Only thing
  we must check is the number goes between the right two numbers. Now we don't have to waste operations trying to get to a number that is somewhere in the middle of the `stack`.
  - This logic is repeated until there is `15`(this can be changed) numbers left on `stack a`.
 - Second part:
   - By now most numbers are *sorted* on `stack b`. We rotate `stack b` until the biggest number is on top.
   - Numbers left on `stack a` are now sorted in ascending order.
   - At this point `stack a` is in ascending order and `stack b` is in descending order.
   - Now numbers are pushed from `stack b` to `stack a` and if `stack a`'s *bottom* number is bigger than the number on *top* of `stack b`
   operation `rra` is used to get that number to it's right place on `stack a`.
   - Reason for this becomes clear if we use as an example case where we have 500 numbers. 499 of those are already pushed to `stack b` and the last numbers place is in the middle of that stack and the stack happens to be rotated in a way that 
   you would have to first rotate the stack 250 times then push the number and then rotate the stack back 250 times to get the biggest number on *top* of the stack.
   - After all number are pushed from `stack b` to `stack a` numbers are now in ascending order in `stack a `.
# Usage
- Run `make` to compile both programs.
- Push_swap:
  ```
  ./push_swap <set of random numbers>
  ```
    - No duplicates
    - Separated by space
- Checker:
  ```
  ./checker <set of random numbers>
  ```
    - No duplicates
    - Separated by space
  
# Visualizer
Takes instructions from `push_swap` and displays the moves and checks if the numbers are in order when all instruction are done.
  - Controls:
    - `space` start/stop
    - `up` increase speed
    - `down` decrease speed
  - To run:
  ```
  python3 visualizer <amount of numbers>
  ```

  ![](https://github.com/atenhune/push_swap/blob/main/push_swap_visualizer.gif)
  
# Tester
  Tests given set sizes and given number of times those sets. Result shows best and worst cases and in case of a failure prints out set of numbers that caused the failure.
  ```
  python3 validate_results.py <sets size> <number of sets>
  ```
  
  <img width="363" alt="Näyttökuva 2022-12-6 kello 23 42 57" src="https://user-images.githubusercontent.com/86076158/206030964-74f217ea-bf5f-4f79-9e39-8fafe361d8ef.png">

