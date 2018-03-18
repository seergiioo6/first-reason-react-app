type todo = string;

type state = {
  count: int,
  visible: bool,
  todos: list(todo)
};

type action =
  | Click
  | Switch
  | AddTodo;

let component = ReasonReact.reducerComponent("Page");

let make = (~message, _children) => {
  ...component,
  initialState: () => {count: 0, visible: true, todos: []},
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Switch => ReasonReact.Update({...state, visible: !state.visible})
    | AddTodo => ReasonReact.Update({...state, todos: ["test", ...state.todos]});
    },
  render: self => {
    let counterMessage: string = "you have clicked "++ string_of_int(self.state.count) ++ " times.";
    <div>
      <h1>(ReasonReact.stringToElement(message))</h1>
      <button onClick=(_event => self.send(Click))> (ReasonReact.stringToElement("+1")) </button>
      <button onClick=(_event => self.send(Switch))> (ReasonReact.stringToElement("Hide/Show")) </button>
      <button onClick=(_event => self.send(AddTodo))> (ReasonReact.stringToElement("AddTodo")) </button>
       (
        self.state.visible ?
          <p> (ReasonReact.stringToElement(counterMessage)) </p> : ReasonReact.nullElement
       )
    </div>
  }

};
