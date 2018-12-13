open Framework;
let assertEqual = (a, b, message) => assertEquality("Tuples", a, b, message);

let tests = [
  {
    let aTuple: (int, string) = (1, "two");
    assertEqual(
      aTuple,
      __tuple__,
      "A tuple is an immutable, ordered, fix-sized, and heterogenous collection.",
    );
  },
  {
    let aTuple: (int, string) = (1, "two");

    assertEqual(
      fst(aTuple),
      __int__,
      "You can access the first element in a tuple with `fst`.",
    );
  },
  {
    let aTuple: (int, string) = (1, "two");

    assertEqual(
      snd(aTuple),
      __string__,
      "You can access the second element in a tuple with `snd`.",
    );
  },
  {
    let anotherTuple = (1, "two", 3, "four");
    let (number, _, _, _) = anotherTuple;
    assertEqual(
      number,
      __int__,
      "Elements in larger tuples are accessed by destructuring.",
    );
  },
];