open Utils;

open Materialui;

/* type */
type state = {expanded: bool};

/* state */
let initialState = {expanded: true};

/* actions */
type actions =
  | Open
  | Close;

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~message="hello", [||]))` */
[@react.component]
let make = (~message) => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Open => {expanded: true}
        | Close => {expanded: false}
        },
      initialState,
    );
  // let handleClick = _event => Js.log("clicked!");
  <AppBar>
    <Toolbar>
      <IconButton
        color="contrast"
        ariaLabel="Menu"
        // onClick={e => {
        //   handleClick(e);
        //   dispatch(Open);
        // }}
        >
        {React.string("face")}
      </IconButton>
      <Button
        raised=true
        // onClick={e => {
        //   handleClick(e);
        //   dispatch(Open);
        // }}
        >
        {React.string("Click")}
      </Button>
      {React.string(message)}
    </Toolbar>
  </AppBar>;
};
