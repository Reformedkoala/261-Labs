/* CSCI 261: Errors
 *
 * Author: Garrett Thompson
 *
 *    This program illustrates a variety of common errors.
 *    Fix the errors in each section.

Copyright 2022 Dr. Jeffrey Paone

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

 */

#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to Loop World" << endl;

// SECTION I: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = Fixing the syntax error of ci instead of cin and fixing the fact that it has to be less then or equal to because otherwise it won't
// add the final value it needs to give the correct output.  Tested 1-5 and it gave 15 which is correct now.
// TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section I" << endl;
    cout << "******************" << endl;

    int sum;      // Accumulates the total
    int i;        // Used as loop control variable
    int numIter;  // The number of times to iterate
    cout << "Enter a number greater than 1 to sum up to: ";
    cin >> numIter;
    for (i = 1; i <= numIter; i++) {
         sum += i;
     }
    cout << "The sum of the numbers from 1 to " << numIter << " (inclusive) is: " << sum << endl;

// SECTION II: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = Fixed syntax error on cot instead of cout.  Fixed stream direction error of the cout being >> instead of <<.  Fixed the fact that total
// was being reset everytime in the while loop instead of being added to.  Tested with number of items being 5 and the price of them being
// different each time to check if they add up correctly now.
// TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section II" << endl;
    cout << "******************" << endl;

    double total = 0;     // Accumulates total
    double price;     // Gets next price from user
    int numItems;     // Number of items
    int counter = 1;  // Loop control counter

    cout << "How many items do you have? ";
    cin >> numItems;
    cout << endl;

    while (counter <= numItems) {
        cout << "Enter the price of item " << counter << ": ";
        cin >> price;
        cout << endl;
        total += price;
        counter++;
    }
    cout << "The total price of all items is: " << total << endl;

// SECTION III: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = No semicolon on what was line 105 so I added it.  Sum2 was never actually intialized as 0 so you can't add anything to it.  I added an
// intialization to sum2.  Counter2 was never initialized nor was it being iterated as it increased each time in the loop.  Also the conditional
// for the do-while loop was wrong and would result in it always stopping after 1 time.  Changed conditional to compare to numIter2 instead.
// Just a formatting thing but instead of the user input being on a seperate line I changed it to be on the same line.  Tested the loop
// with random values to make sure it was correctly outputting.
// TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section III" << endl;
    cout << "******************" << endl;

    int sum2 = 0;
    int counter2 = 1;
    int numIter2;

    cout << "What number do you wish me to sum from 1 to? ";
    cin >> numIter2;

    do {
        sum2 += counter2;
        cout << "Sum so far: " << sum2 << endl;
        counter2++;
    } while (counter2 <= numIter2);

    cout << endl << "Section III Recap" << endl;

    cout << "I calculated the sum of numbers from 1 to " << numIter2 << " (inclusive) as " << sum2 << endl;


// SECTION IV: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = Mainly a logic error in the for loop causing it to add up all numbers greater then 0 essentially starting at where you enter though.
// Fixed it so that it now iterates from 1 squared which is just 1 to the number you give it but squared like it should.  Fixed a logic error
// that would cause it to not be inclusive as well.  Tested the loop with random values that gave the correct output.
// TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section IV" << endl;
    cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum of 1 squared to ? squared (inclusive): ";
    int numIter3;
    cin >> numIter3;

    int sum3 = 0;
    for (int i3 = 1; i3 <= numIter3*numIter3; i3++) {
        sum3 += i3*i3;
    }

    cout << "The sum of squares from 1 to " << numIter3 << " is: " << sum3 << endl;

// SECTION V: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = Fixed comment syntax error.  Fixed the fact some variables were not initialized.  Fixed a logic error in the fact the loop would only 
// iterate from 1 to 10.  Fixed another logic error in the it was incrementing the loop outside of itself.  Tested the loop with random values that
// were correct.
// TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section V" << endl;
    cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum from 1 cubed to ? cubed (inclusive): ";

    int numIter4;
    int counter4 = 1;
    int sum4 = 0;
    cin >> numIter4;

    while (counter4 <= numIter4) {
        sum4 += (counter4 * counter4 * counter4);
        counter4++;
    }

    cout << "The sum of cubes from 1 to " << numIter4 << " is: " << sum4 << endl;

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;
    return 0;
}
