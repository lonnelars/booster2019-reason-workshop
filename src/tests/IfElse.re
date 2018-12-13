open Framework;

let assertEqual = (a, b, message) => assertEquality("IfElse", a, b, message);

let tests = [
  {
    let flag = true;
    let x = if (flag) {"turn feature on"} else {"turn feature off"};
    assertEqual(
      x,
      __string__,
      "If-else in Reason are expressions. They are evaluated to their body's content.",
    );
  },
  /* {
       let y =
         if (false) {
           print_string("impossible");
         };
       assertEqual(
         y,
         __unit__,
         "An if-expression without else implicitly returns unit.",
       );
     }, */
  assertEqual(
    1 == 1 ? "one" : "not one",
    __string__,
    "Ternary expressions are syntactical sugar for if-else expressions.",
  ),
];