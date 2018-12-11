let tests = [
  Tutorial.tests,
  Basics.tests,
  LetBindings.tests,
  SimpleTypes.tests,
  Tuples.tests,
  Records.tests,
];

List.iter(f => f(), tests);

print_string({js|Congratulations, you have completed all the tests 🙌|js});