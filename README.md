# Advent2022
A repository for my Advent of Code 2022 Solutions in C++. Feel free to ask questions or provide advice or suggestions!

In order to apply the code to your input, simply copy-paste the input from your Advent of Code challenge into a .txt file in the same directory as the code for that challenge (e.g. create an input.txt file with your input for the day 2 challenge in the directory advent2). After that, you can compile the code using the Makefile I provided: on the command line, while in the applicable directory (e.g. advent2 for the day 2 challenge), type in 
```
make 
```
and the code for both parts of that day's challenge will compile. To pass your input to the compiled program, type the following in bash: 
```
cat <your input file name> | ./advent<day>_<part 1 or 2> 
```
To remove the compiled programs, type 
```
make clean
```
on the command line.
