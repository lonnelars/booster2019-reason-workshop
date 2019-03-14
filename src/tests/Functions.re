open Framework;

let assertEqual = (a, b, message) =>
  assertEquality("Functions", a, b, message);

type tree('a) =
  | Node('a, tree('a), tree('a))
  | Leaf('a);

let add = (a, b) => 0;
let add3 = (a, b, c) => a + b + c;
let sub = (~x, ~y) => x - y;

let tests = [
  {
    let greet = name => "Hello, " ++ name ++ "!";
    assertEqual(
      greet("Booster"),
      __string__,
      "A function is declared with a fat arrow (=>), and returns the value of the expression to the right of the arrow.",
    );
  },
  assertEqual(
    add(7, 6),
    13,
    "Fix the add function such that it returns the sum of its two arguments.",
  ),
  assertEqual(
    add3(4, 5, 6),
    __int__,
    "Multiple arguments are separated by commas.",
  ),
  {
    let reverseName = (name: (string, string)) => {
      let (first, last) = name;
      last ++ ", " ++ first;
    };
    assertEqual(
      reverseName(("Bernie", "Sanders")),
      __string__,
      "Longer function bodies require curly braces.",
    );
  },
  /* {
       let printHello = () => print_string("hello");
       assertEqual(
         printHello(),
         __unit__,
         "Side-effect functions conventionally take unit as argument, and returns unit. unit has only one value: ().",
       );
     }, */
  assertEqual(
    sub(~x=10, ~y=7),
    __int__,
    "Functions can have labelled arguments.",
  ),
  assertEqual(
    sub(~y=7, ~x=10),
    __int__,
    "Labelled arguments can be applied in any order.",
  ),
  {
    let add = (a, b) => a + b;
    let add5 = add(5);
    assertEqual(
      add5(6),
      __int__,
      "Functions are curried, and can be partially applied.",
    );
  },
  {
    let myTree = Node(1, Node(2, Leaf(3), Leaf(4)), Leaf(5));
    let rec treeSum = tree =>
      switch (tree) {
      | Leaf(value) => value
      | Node(value, left, right) => value + treeSum(left) + treeSum(right)
      };
    assertEqual(
      treeSum(myTree),
      __int__,
      "A recursive function must be declared with `let rec`.",
    );
  },
];