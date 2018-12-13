type result =
  | Ok
  | Error(string);

let assertEquality =
    (path: string, expected: 'a, actual: 'a, message: string): result =>
  if (expected != actual) {
    Error("src/koans/" ++ path ++ ".re: " ++ message ++ "\n");
  } else {
    Ok;
  };

let __string__ = "";

let __int__ = 0;

let __float__ = 0.0;

let __bool__ = false;

let ___bool___ = true;

let __char__ = 'a';

let __tuple__ = (0, "0");

let __unit__ = ();

let __option__ = Some(0);

let __list__ = [];

let __array__ = [||];