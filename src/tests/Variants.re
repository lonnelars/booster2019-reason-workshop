open Framework;

let assertEqual = (a, b, message) =>
  assertEquality("Variants", a, b, message);

/* A variant is a type with a finite number of possible values. */
type office =
  | Trondheim
  | Oslo
  | Bergen;

type language =
  | JavaScript
  | Reason
  | Elm;

type expression =
  | Number(int)
  | Sum(expression, expression)
  | Product(expression, expression);

let anOffice: office = Trondheim;

let manager = office =>
  switch (office) {
  | Oslo => "Abid"
  };

let maybeOne = None;
let maybeTwo = Some(2);

let tests = [
  {
    let address =
      switch (anOffice) {
      | Trondheim => "Bassengbakken 4"
      | Oslo => "Kirkegata 5"
      | Bergen => "Statsminister Michelsens veg 38"
      };
    assertEqual(
      address,
      __string__,
      "We can access a variants value with the switch expression.",
    );
  },
  {
    assertEqual(
      try (manager(Trondheim)) {
      | _ => ""
      },
      "Camilla",
      "The compiler will warn us if we have not covered all possible options.\n\nOpen the terminal window where you have `yarn start` running, and notice the warning that says \"You forgot to handle a possible value here\". \n\nFix this and the next test by adding the missing values to the `manager` function on line 24.",
    );
  },
  assertEqual(
    try (manager(Bergen)) {
    | _ => ""
    },
    "Frode",
    "Fix these tests by adding the missing cases to the switch expression above.",
  ),
  {
    let compiledLanguage = lang =>
      switch (lang) {
      | JavaScript => false
      | _ => true
      };
    assertEqual(
      compiledLanguage(Reason),
      __bool__,
      "An underscore will match any value.",
    );
  },
  {
    let aNumber = Number(1);
    assertEqual(
      switch (aNumber) {
      | Number(x) => x
      | _ => 0
      },
      __int__,
      "A variant's constructors can hold extra data. Access that data with pattern matching in the switch expression.",
    );
  },
  {
    let anExpression = Product(Number(2), Sum(Number(3), Number(4)));
    let rec evaluate = expr =>
      switch (expr) {
      | Number(x) => x
      | Sum(e1, e2) => evaluate(e1) + evaluate(e2)
      | Product(e1, e2) => evaluate(e1) * evaluate(e2)
      };
    assertEqual(
      evaluate(anExpression),
      __int__,
      "A variant's extra data can be of the same type as the variant itself.",
    );
  },
  {
    assertEqual(
      switch (maybeOne) {
      | None => (-1)
      | Some(x) => x
      },
      __int__,
      "The option type from the standard library is a variant.",
    );
  },
  assertEqual(
    switch (maybeTwo) {
    | None => 0
    | Some(x) => x
    },
    __int__,
    "It is accessed with a switch expression, just like other variants.",
  ),
  {
    let myList = [1, 2, 3];
    let rec length = list =>
      switch (list) {
      | [] => 0
      | [hd, ...tl] => 1 + length(tl)
      };
    assertEqual(
      length(myList),
      __int__,
      "A list is also a variant, hidden behind some syntactic sugar. It is either the empty list ([]), or a head and a tail.",
    );
  },
  {
    let myString = "Hello variants!";
    let isEmpty = str =>
      switch (str) {
      | "" => true
      | _ => false
      };
    assertEqual(
      isEmpty(myString),
      ___bool___,
      "A string can be treated like a variant. It is either empty, or not empty.",
    );
  },
];