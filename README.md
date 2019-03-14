# Reason workshop

## tl;dr

Åpne `src/tests/Tutorial.re`, og følg instruksjonene i kommentaren.

## Velkommen

Velkommen! Denne workshopen skal lære dere [Reason](https://reasonml.github.io/), og vise dere hvordan dere kan starte med en enkel nettside skrevet i Reason og React.

## Editor

Vi trenger en editor-plugin for å jobbe effektivt med Reason. Prosjektet selv anbefaler VSCode. Se instrukser her: https://reasonml.github.io/docs/en/editor-plugins

## Lær språket

Reason er designet for å ligne på JavaScript, men det er et helt eget språk, og mye oppførsel er helt annerledes i Reason enn i JavaScript. For eksempel er datastrukturene immutable, med mindre du eksplisitt ber om en mutable type.

Mappa `src/tests` inneholder en mengde tester, som dere skal fikse. Tanken er å lære bort grunnelementene i språket, mens dere leser og skriver koden selv. Dette er den første delen av workshopen. I del to skal vi installere React, og prøve oss på å skrive en liten web applikasjon.

Begynn med å åpne `src/tests/Tutorial.re`, og følg instruksjonene i kommentaren.

## En liten web applikasjon

I denne andre delen av workshopen skal vi lage en liten webapplikasjon med Reason og React.

Begynn med å lage et nytt reason-react-prosjekt. Dokumentasjon finner dere her: https://reasonml.github.io/reason-react/docs/en/installation. Kort fortalt: `bsb -init my-react-app -theme react` og kjør `npm start` og `npm run webpack`.

jeg har antatt at React er rimelig kjent. Hvis det er helt fremmed, anbefaler jeg at du jobber sammen med en som kan React fra før.

### Oppgaven

Vi skal hente data from fra GitHub api-et, og vise informasjon om din bruker i en reactkomponent. Resultatet skal bli noe sånt som dette:

![lonnelars on github.com](./github-user.png)

### API

Informasjon om en bruker får dere med

```
GET https://api.github.com/users/"$username"?access_token="$token"
```

Et personlig token kan dere lage her:
https://github.com/settings/tokens

### bs-fetch og bs-json

Pakker for reason-prosjekter finner dere på https://redex.github.io/. Vi skal installere to pakker for å hente data, og dekode json.

- https://redex.github.io/package/bs-fetch/.
- https://redex.github.io/package/@glennsl/bs-json

Installer dem med npm, og legg dem til i `bs-dependencies` i `bsconfig.json`.

### Reducer components og stateless components

I Reason-React kan man lage to forskjellige komponenter: reducer components og stateless components.

_Stateless components_ er de enkleste, og burde være mest brukt i applikasjonene dere lager. De har ikke tilstand, som navnet tilsier. All data som skal brukes av disse komponentene, må sendes inn som props. En stateless component lages på denne måten:

```ocaml
let component = ReasonReact.statelessComponent("Greeting");

let make = (~name, _children) => {
  ...component, /* spread the template's other defaults into here  */
  render: _self => <div> {ReasonReact.string(name)} </div>
};
```

Se https://reasonml.github.io/reason-react/docs/en/creation-props-self for mer info om stateless components.

_Reducer components_ kan ha en egen tilstand, og håndterer dette på samme måte som redux i react. Her er et eksempel på en enkel reducer component:

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
