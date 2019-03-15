# Reason workshop

## tl;dr

Open `src/tests/Tutorial.re`, and follow the instructions in the comment. 

## Welcome

Welcome! This workshop will teach you [Reason](https://reasonml.github.io/), and show you how to create a simple webpage written with Reason and React. 

## Editor

We'll need an editor plugin to work effectively with Reason. The project itself recommends VSCode. Follow the instructions here: https://reasonml.github.io/docs/en/editor-plugins

## Learn the language

Reason is designed to look like JavaScript, but it is a completely different language, and some behaviour is radically different. As an example, all datastructures in Reason are immutable, unless you explicitly ask for a mutable type. 

The folder `src/tests` contains a set of tests, which you will fix. The idea is to teach the elements of the language, while you read and write code. This will be the first part of the workshop. In part two, we will install React, and try to write a small web application. 

Start by opening `src/tests/Tutorial.re`, and follow the instructions in the comment. 

## A small web application

In this second part of the workshop, we will make a small web application with Reason and React. 

Start by making a new reason-react project. The documentation is here: https://reasonml.github.io/reason-react/docs/en/installation. It boils down to running `bsb -init my-react-app -theme react`, `npm start`, and `npm run webpack`. 

I have assumed that React is somewhat familiar. If it is not, I recommend you pair with someone who knows React. 

### The task

We will fetch data from the GitHub API, and show information about your user in a react compnent. The result should be something like this:

![lonnelars on github.com](./github-user.png)

### API

Information about a user is fetched like this:

```
GET https://api.github.com/users/"$username"?access_token="$token"
```

You can make a personal token here:
https://github.com/settings/tokens

### bs-fetch og bs-json

Packages for Reason projects is found on https://redex.github.io/. We will install two packages, one for fetching data, and one for decoding json. 

- https://redex.github.io/package/bs-fetch/.
- https://redex.github.io/package/@glennsl/bs-json

Install them with npm/yarn, and add the in `bs-dependencies` i `bsconfig.json`. Make sure you install `@glennsl/bs-json`, and not `bs-json`. The are not the same package.

### Reducer components and stateless components

Reason-React has two types of components: reducer components, and stateless components. 

_Stateless components_ are the simplest, and should be the type of component you use the most. They have no state, and all data must be passed in as props. A stateless component is made like this:

```ocaml
let component = ReasonReact.statelessComponent("Greeting");

let make = (~name, _children) => {
  ...component, /* spread the template's other defaults into here  */
  render: _self => <div> {ReasonReact.string(name)} </div>
};
```

See https://reasonml.github.io/reason-react/docs/en/creation-props-self for more information on stateless components. 

_Reducer components_ have their own state, and handles this much the same way as redux. Here is an example of a simple reducer component:

```ocaml
/* State declaration */
type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | Click
  | Toggle;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Example");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (~greeting, _children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {count: 0, show: true},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: !state.show})
    },

  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    <div>
      <button onClick=(_event => self.send(Click))>
        (ReasonReact.string(message))
      </button>
      <button onClick=(_event => self.send(Toggle))>
        (ReasonReact.string("Toggle greeting"))
      </button>
      (
        self.state.show
          ? ReasonReact.string(greeting)
          : ReasonReact.null
      )
    </div>;
  },
};
```
