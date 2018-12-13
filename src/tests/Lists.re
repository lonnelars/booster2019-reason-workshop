open Framework;

let assertEqual = (a, b, message) => assertEquality("Lists", a, b, message);

let list: list(int) = [1, 2, 3];
let array: array(int) = [|1, 2, 3|];

let addOne = x => x + 1;
let even = x => x mod 2 == 0;
let sum = (a, b) => a + b;
let tests = [
  assertEqual(list, __list__, "Lists are immutable, homogenous collections."),
  assertEqual(
    [0, ...list],
    __list__,
    "Lists are very fast at prepending items.",
  ),
  {
    let hd =
      switch (list) {
      | [] => 0
      | [hd, ...tl] => hd
      };
    assertEqual(
      hd,
      __int__,
      "You can access the head of a list by pattern matching.",
    );
  },
  assertEqual(
    List.hd(list),
    __int__,
    "You can also access the head with the hd function from the List module.",
  ),
  assertEqual(
    List.nth(list, 2),
    __int__,
    "You can access the nth item in the list with List.nth, in O(n) time.",
  ),
  assertEqual(
    List.map(addOne, list),
    __list__,
    "Map a function over a list with List.map.",
  ),
  assertEqual(
    List.filter(even, list),
    __list__,
    "Filter a list with List.filter.",
  ),
  assertEqual(
    List.fold_left(sum, 0, list),
    __int__,
    "Fold over a list with List.fold_left.",
  ),
  assertEqual(
    List.fold_right(sum, list, 0),
    __int__,
    "Right fold over a list with fold_right.",
  ),
  assertEqual(
    array,
    __array__,
    "Arrays are mutable collections, which are fast at random access and updates.",
  ),
  {
    let firstItem = array[0];
    assertEqual(
      firstItem,
      __int__,
      "You can access an item in an array with square brackets notation.",
    );
  },
  {
    array[1] = 4;
    assertEqual(
      array,
      __array__,
      "Arrays are mutable, and the notation is the same as in JavaScript.",
    );
  },
];