type todo = string;

type state = {
  title: string,
};

type action =
  | Edit;

let component = ReasonReact.reducerComponent("TodoItem");

let make = (~todo, _children) => {
  ...component,
  reducer: action =>
      switch (action) {
      | Edit => (
          state => ReasonReact.Update({...state, title: "test"});
        )
      },
  initialState: () => {title: "test"},
  render: self => {
    <li onClick=(_event => self.send(Edit))>(ReasonReact.stringToElement(todo))</li>
  }

};
