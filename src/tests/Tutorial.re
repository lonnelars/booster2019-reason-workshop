include Framework;

let assertEqual = assertEquality("Tutorial");

/* The purpose of these tests is to teach you ReasonML while fixing tests and
   writing code. This first file is very simple, and its sole purpose is to
   demonstrate the testing framework.

   Run the tests by opening a terminal and running `yarn start` from the project
   root. Open another terminal, and run `yarn watch-tests`. The tests will now
   run every time one of the .re files is changed.

   Find the test below which says "true should be true". Fill in `true` for
   `__bool__`, and run the tests again. You'll know the first test has passed,
   because a new problem is displayed in the terminal: "false should be false".
   Find this problem below, and repeat. When you are done with the problems in
   this file, move on to Basics.re. */

let tests = () => {
  assertEqual(true, __bool__, "true should be true");
  assertEqual(false, ___bool___, "false should be false");
};