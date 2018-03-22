type state = {
  count: int,
  visible: bool,
  todos: list(TodoItem.todo)
};

let initialTodo: TodoItem.todo = {id: 0, title: "Todo Item"};

type action =
  | Click
  | Switch
  | AddTodo;

let component = ReasonReact.reducerComponent("Page");

let make = (~message, _children) => {
  ...component,
  initialState: () => {count: 0, visible: true, todos: [initialTodo]},
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Switch => ReasonReact.Update({...state, visible: !state.visible})
    | AddTodo => ReasonReact.Update({...state, todos: [{title: "Todo", id: int_of_float(Js.Date.now())}, ...state.todos]});
    },
  render: self => {
    let counterMessage: string = "you have clicked "++ string_of_int(self.state.count) ++ " times.";
    <div>
      <h1 style=(
        ReactDOMRe.Style.make(~color="#444444", ~fontSize="40px", ())
      )>(ReasonReact.stringToElement(message))</h1>
      <button onClick=(_event => self.send(Click))> (ReasonReact.stringToElement("Counter + 1")) </button>
      <button onClick=(_event => self.send(Switch))> (ReasonReact.stringToElement("Hide/Show Counter")) </button>
      <button onClick=(_event => self.send(AddTodo))> (ReasonReact.stringToElement("Add Todo")) </button>
       (
        self.state.visible ?
          <p> (ReasonReact.stringToElement(counterMessage)) </p> : ReasonReact.nullElement
       )
       <ul>
       (
          ReasonReact.arrayToElement(Array.of_list(
              List.map((todo) => <TodoItem todo/> , self.state.todos)
          ))
        )
        </ul>
    </div>
  }

};
