For this lab, your tasks are as follows.  Provide the answers after each number.  Show your work for each step.

1a. Convert the decimal number 1,904,803,840 to 32-bit two's complement binary representation.
divide by 2 and check remainder each time
1,904,803,840/2 = 952401920 = 0
952401920/2 = 476200960 = 0
476200960/2 = 238100480 = 0
238100480/2 = 119050240 = 0
119050240/2 = 59525120 = 0
skipped a few....... repeat until you get to 0
29065/2 = 14532 = 1
14532/2 = 7266 = 0
7266/2 = 3633 = 0
3633/2 = 1816 = 1	
1816/2 = 908 = 0	
908/2 = 454 = 0	
454/2 = 227 = 0	
227/2 = 113 = 1	
113/2 = 56 = 1	
56/2 = 28 = 0	
28/2 = 14 = 0	
14/2 = 7 = 0	
7/2 = 3 = 1	
3/2	= 1 = 1	
1/2 = 1 
then flip it around and extra zero if needed to get to 32 bits
01110001100010010000000000000000

1b. Represent the value in hexadecimal. 
split binary number into groups of 4
0111 0001 1000 1001 0000 0000 0000 0000
convert each group to decimal and if it's over 9 convert to A-F
0x71890000

2a. Convert the decimal number -1,047,986,176 to 32-bit two's complement binary representation.
Same thing you do in the first except once you get the answer you flip the bits and add 1
11000001100010010000000000000000

2b. Represent the value in hexadecimal.
split into groups of four once again and convert to decimal equivalent or A-E
1100 0001 1000 1001 0000 0000 0000 0000
-0xC1890000

3a. Convert the decimal number 17.125 to 32-bit floating point precsision.
Make sure first bit is 0 because it's not negative
the mantisa is represented by 1.001 then convert it with the exponent 100000011
fill in what needs to be zero
01000001100010010000000000000000

3b. Represent the value in hexadecimal.
Same idea as before split into 4 then convert to decimal or A-E 
0100 0001 1000 1001 0000 0000 0000 0000
0x41890000

4a. Convert the decimal number -17.125 to 32-bit floating point precision.
same value from before just flip the front bit
11000001100010010000000000000000

4b. Represent the value in hexadecimal.
Same idea as before split into 4 then convert to decimal or A-E 
1100 0001 1000 1001 0000 0000 0000 0000
-0xC1890000

5a. Convert the hexadecimal value 0xC3890000 to binary.
find binary representation of each hex digit to get 4 bit representation of each digit then combine into the binary representation
i.e c = 1100, 3 = 0011, 8 = 1000, 9 = 1001 rest are zeroes
11000011100010010000000000000000

5b. Convert the binary to a signed decimal integer value using two's complement.
convert leftmost bit to a negative number which is -2147483648
then add all other bits up to the negative
-2147483648 + 1073741824 + 33554432 + 16777216 + 8388608 + 524288 + 65536
-1,014,431,744

5c. Convert the binary to a floating point decimal value.
We know it's a negative number from left most bit
The maount we move the binary point is 8 bits given by the exponent and then we figure out the mantissa from what is left which is 00010010.0000....
Resulting in 
-274

6.  Using a terminal, perform the following steps.  List the commands used to perform the tasks:

- print the current directory you are in when the terminal opens
pwd

- move into the lab1b_folder directory
cd .\lab1b_folder\

- list the contents of the directory
ls

- move into the data directory
cd .\data\

- rename the misspelled file fil2.txt to be file2.txt
mv fil2.txt file2.txt

- copy file1.txt to be file3.txt
cp file1.txt file3.txt

- make a new file named file4.txt
ni fil4.txt

- move to the parent directory
cd ..

- make a directory named bin
mkdir bin

- compile main.cpp into an executable
g++ main.cpp

- move the generated executable into the bin folder and rename it to be lab1b
mv a.exe .\bin\

- print the current directory you are currently in
pwd

- run the new executable from your current directory
.\bin\a.exe

What to submit?
Submit this README.txt with the completed responses.
