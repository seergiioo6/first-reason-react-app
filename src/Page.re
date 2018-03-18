type state = {
  count: int,
  visible: bool
};

type action =
  | Click
  | Switch;

let component = ReasonReact.reducerComponent("Page");

let make = (~message, _children) => {
  ...component,
  initialState: () => {count: 0, visible: true},
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Switch => ReasonReact.Update({...state, visible: !state.visible});
    },
  render: self => {
    let counterMessage: string = "you have clicked "++ string_of_int(self.state.count) ++ " times.";
    <div>
      <h1>(ReasonReact.stringToElement(message))</h1>
      <button onClick=(_event => self.send(Click))> (ReasonReact.stringToElement("+1")) </button>
      <button onClick=(_event => self.send(Switch))> (ReasonReact.stringToElement("Hide/Show")) </button>
       (
        self.state.visible ?
          <p> (ReasonReact.stringToElement(counterMessage)) </p> : ReasonReact.nullElement
      )
    </div>
  }

};
