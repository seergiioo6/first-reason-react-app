type state = {
  count: int
};

type action =
  | Click;

let component = ReasonReact.reducerComponent("Page");

let make = (~message, _children) => {
  ...component,
  initialState: () => {count: 0},
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    },
  render: self => {
    let counterMessage: string = "you have clicked "++ string_of_int(self.state.count) ++ " times.";
    <div>
      <h1>(ReasonReact.stringToElement(message))</h1>
      <button onClick=(_event => self.send(Click))> (ReasonReact.stringToElement("Button")) </button>
      <p> (ReasonReact.stringToElement(counterMessage))  </p>
    </div>
  }

};
