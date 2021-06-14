// let x = (x) =>   Js.Nullable.fromOption(
//             Js.Option.map([@bs] (x => (x )), raised)
// );
[@bs.deriving jsConverter]
type color = [
  | `red
  | `orange
  | `yellow
  | `olive
  | `green
  | `teal
  | `blue
  | `violet
  | `purple
  | `pink
  | `brown
  | `grey
  | `black
  | `facebook
  | [@bs.as "google plus"] `googleplus
  | `instagram
  | `linkedin
  | `twitter
  | `vk
  | `youtube
];
let makeJsOptionMap = (f, b) => Js.Option.map((. a) => f(a), b);
let fromColor = makeJsOptionMap(colorToJs);
module IconButton = {
  [@bs.module "material-ui"][@react.component]
  external make:
    (
      ~classes: option(string)=?,
      ~color: option(string)=?,
      ~disabled: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~rootRef: option(string)=?,
      ~ariaLabel: option(string)=?,
      ~children: React.element
    ) =>
    React.element =
    "IconButton";
};

module Button = {
  [@bs.module "material-ui"][@react.component]
  external make:
    (
      ~raised: option(bool)=?,
      ~color: option(string)=?,
      ~className: option(string)=?,
      ~dense: option(bool)=?,
      ~children: React.element
    ) =>
    React.element =
    "Button";
};

module AppBar = {
  type position =
    | Static
    | Fixed
    | Absolute;
  let toString: option(position) => option(string) =
    position =>
      switch (position) {
      | Some(Static) => Some("static")
      | Some(Fixed) => Some("fixed")
      | Some(Absolute) => Some("absolute")
      | None => None
      };
  [@bs.module "material-ui"][@react.component]
  external make:
    (
      ~color: option(string)=?,
      ~iconElementLeft: option(string)=?,
      ~position: option(position)=?,
      ~children: React.element
    ) =>
    React.element =
    "AppBar";
};

module Toolbar = {
  [@bs.module "material-ui"][@react.component]
  external make:
    (~className: option(string)=?, ~children: React.element) => React.element =
    "Toolbar";
};

module Table = {
  [@bs.module "material-ui"][@react.component]
  external make:
    (~className: option(string)=?, ~children: React.element) => React.element =
    "Table";
};

module TableBody = {
  [@bs.module "material-ui"][@react.component]
  external make:
    (~className: option(string)=?, ~children: React.element) => React.element =
    "TableBody";
};

module TableCell = {
  type padding =
    | Default
    | Checkbox
    | Dense
    | None;
  let paddingToString: option(padding) => option(string) =
    padding =>
      switch (padding) {
      | Some(Default) => Some("default")
      | Some(Checkbox) => Some("checkbox")
      | Some(Dense) => Some("dense")
      | None => None
      | Some(None) => Some("none")
      };
  [@bs.module "material-ui"][@react.component]
  external make:
    (
      ~numeric: option(bool)=?,
      ~padding: option(padding)=?,
      ~classes: option(string)=?,
      ~children: React.element
    ) =>
    React.element =
    "TableCell";
};
