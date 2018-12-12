open Framework;

let assertEquals = (a, b, message) =>
  assertEquality("LetBindings", a, b, message);

let tests = () => {
  let company = "Kantega";
  assertEquals(company, __string__, "A let binding binds a value to a name.");
  let city: string = "Bergen";
  assertEquals(
    city,
    __string__,
    "A let binding can have an optional type annotation.",
  );
  let message = "hello!";
  /* message = "bye!" <-- Mutation is not allowed. */
  let message = "bye!";
  assertEquals(
    message,
    __string__,
    "Bindings are immutable, but can be shadowed by a later binding with the same name.",
  );
  {
    let city = "Trondheim";
    ();
  };
  assertEquals(
    city,
    __string__,
    "Bindings can be scoped through {}. Bindings are not visible outside their scope.",
  );
  let greeting = {
    let salutation = "Hey ";
    let company = "Kantega";
    salutation ++ company ++ "!";
  };
  assertEquals(
    greeting,
    __string__,
    "{} are expressions, and can be used to create anonymous scopes.",
  );
};