type todo = {
  id: int,
  title: string
};

type state = {
  editing: bool,
  text: string
};

type action =
  | Edit;

let component = ReasonReact.reducerComponent("TodoItem");

let make = (~todo, _children) => {
  ...component,
  reducer: action =>
      switch (action) {
      | Edit => (
          state => ReasonReact.Update({...state, editing: true, text: "clicked!"})
        )
      },
  initialState: () => {
    editing: false,
    text: todo.title
  },
  render: self => {
    <li onClick=(_event => self.send(Edit))>
      (ReasonReact.stringToElement(self.state.text))
    </li>
  }

};
