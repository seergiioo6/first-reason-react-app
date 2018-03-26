type completed = bool;

type todo = {
  id: int,
  title: string,
  completed: completed
};

type state = {
  editing: bool,
  text: string,
  completed: completed
};

type action =
  | Edit
  | Update(string)
  | Complete;

let component = ReasonReact.reducerComponent("TodoItem");

let make = (~todo, _children) => {
  ...component,
  reducer: action =>
      switch (action) {
      | Edit => (
          state => ReasonReact.Update({...state, editing: !state.editing})
        )
      | Update(text) => (
          state => ReasonReact.Update({...state, text: text})
        )
      | Complete => (
          state => ReasonReact.Update({...state, completed: true})
        )
      },
  initialState: () => {
    editing: false,
    text: todo.title,
    completed: false
  },
  render: self =>
    switch (self.state.editing) {
    | false =>
      <li onClick=(_event => self.send(Edit))>
        (ReasonReact.stringToElement(self.state.text))
      </li>
    | true => <div>
                <input
                  value=(self.state.text)
                  onChange=(_event => self.send(Update(ReactDOMRe.domElementToObj(ReactEventRe.Form.target(_event))##value)))
                />
                <button onClick=(_event => self.send(Edit))> (ReasonReact.stringToElement("Guardar")) </button>
                <button onClick=(_event => self.send(Complete))> (ReasonReact.stringToElement("Completar")) </button>
              </div>
    }

}
