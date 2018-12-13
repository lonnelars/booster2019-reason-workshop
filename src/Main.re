let results =
  [
    Tutorial.tests,
    Basics.tests,
    LetBindings.tests,
    SimpleTypes.tests,
    Tuples.tests,
    Records.tests,
    Variants.tests,
    Lists.tests,
    Functions.tests,
    IfElse.tests,
  ]
  |> List.concat;

let count = List.fold_left((acc, _) => acc + 1, 0);
let isOk = result =>
  Framework.(
    switch (result) {
    | Ok => true
    | Error(_) => false
    }
  );
let isError = result =>
  Framework.(
    switch (result) {
    | Ok => false
    | Error(_) => true
    }
  );

let resultCount = count(results);
let okCount = List.filter(isOk, results) |> count;
let nextTestMessage =
  List.fold_left(
    (message, result) =>
      switch (message, result) {
      | ("", Framework.Error(s)) => s
      | _ => message
      },
    "",
    results,
  );
let progressBar =
  "["
  ++ String.make(okCount, '=')
  ++ String.make(resultCount - okCount, '.')
  ++ "] "
  ++ string_of_int(okCount)
  ++ "/"
  ++ string_of_int(resultCount);

if (okCount == resultCount) {
  print_endline(progressBar);
  print_endline("Well done!");
} else {
  print_endline(progressBar);
  print_endline("Now have a look at " ++ nextTestMessage);
};