open Framework;
let assertEqual = (a, b, message) =>
  assertEquality("Records", a, b, message);

/* The type of a record must be explicitly specified before it can be used. */
type person = {
  age: int,
  name: string,
};

type mutablePerson = {
  mutable age: int,
  name: string,
};

let morty: person = {age: 14, name: "Morty Smith"};

let tests = [
  assertEqual(
    morty,
    {age: __int__, name: __string__},
    "A record is like a tuple, but with named fields.",
  ),
  assertEqual(
    morty.age,
    __int__,
    "You can access a records fields with dot notation.",
  ),
  {
    let olderPerson: person = {...morty, age: morty.age + 1};
    assertEqual(
      olderPerson,
      {age: __int__, name: __string__},
      "Immutable updates. A new
    record is created from the old one with the ... operator.",
    );
  },
  assertEqual(
    morty,
    {age: __int__, name: __string__},
    "The old record is unchanged.",
  ),
  {
    let rick: mutablePerson = {age: 70, name: "Rick Sanchez"};
    rick.age = rick.age + 1;
    assertEqual(
      rick.age,
      __int__,
      "A record field can optionally be made mutable.",
    );
  },
  {
    let name = "Rick Sanchez from Earth dimension C-137";
    let c137: person = {age: 70, name};
    assertEqual(
      c137,
      {age: 70, name: __string__},
      "\"Punning\" is a syntax shorthand you
    can use when the name of the field matches the name of the value.",
    );
  },
];