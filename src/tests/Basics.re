open Framework;

let assertEqual = (a, b, message) => assertEquality("Basics", a, b, message);
/* let assertEqual: ('a, 'a, string) => unit = assertEquality("Basics"); */

let tests = () => {
  assertEqual(
    "Hello Reason!",
    __string__,
    "A string is a sequence of characters between double quotes.",
  );
  assertEqual(
    "Hello Reason!",
    "Hello " ++ __string__,
    "++ concatenates two strings.",
  );
  assertEqual(99, __int__, "An integer is a sequence of digits.");
  assertEqual(23.0, __float__, "A floating point number has decimal marker.");
  assertEqual(
    100,
    99 + __int__ - __int__,
    "+ and - does integer addition and subtraction.",
  );
  assertEqual(
    100,
    50 * __int__ / __int__,
    "* and / does integer multiplication and division.",
  );
  assertEqual(
    24.0,
    23.9 +. __float__ -. __float__,
    "+. and -. does floating point addition.",
  );
  assertEqual(
    100.0,
    50.0 *. __float__ /. __float__,
    "*. and /. does floating point multiplication and division.",
  );
  assertEqual(
    9.0,
    3.0 ** __float__,
    "** does floating point exponentiation.",
  );
  assertEqual(
    'c',
    __char__,
    "A character is a single character between single quotes.",
  );
  assertEqual(
    1 < 2 && 3 > 2,
    3 >= 3 || 4 <= __int__,
    "Boolean operators are the same as in JavaScript, and many other languages.",
  );
};