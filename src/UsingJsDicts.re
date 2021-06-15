

[@val] [@scope "Object"]
external update:
  ([@as {json|{}|json}] _, Js.Dict.t('a), Js.Dict.t('a)) => Js.Dict.t('a) =
  "assign";
// rescript
// @val @scope("Object")
// external update: (@as(json`{}`) _, Js.Dict.t<'a>, Js.Dict.t<'a>) => Js.Dict.t<'a> = "assign"

let dict1 = Js.Dict.empty()

let obj1 = {"art": "test", "gueltig": true, "id": 284}
Js.Dict.set(dict1,"y",obj1)
Js.log(dict1)
let obj2 = {"art": "test", "gueltig": true, "id": 284}
let dict2 = Js.Dict.empty()
Js.Dict.set(dict2,"x",obj2)
Js.log(dict2)
// let x = update(y, z) // Compiles to var x = Object.assign({}, a, b);
let x = update(dict1, dict2)
Js.log(x);
// let dict3 = Js.Dict.empty()

// let obj1 = {"art": "test", "gueltig": true, "id": 284}
// Js.Dict.set(dict3,"y",obj1)
// Js.log(dict3);

[%%bs.raw
  {| const val = { secret: "ley" };|}
];
[@val] external valley: 'a = "val";

Js.log(valley##secret);
[%%bs.raw
  {| const jsObject = {
      myName: "blabla",
      myMethod: (greeting) => console.log(`${greeting}, Mr.${jsObject.myName}`)
    };|}
];
[@bs.val] external jsObject : Js.t('a) = "jsObject";

// /* The type Js.t('a) doesnt provide any field or method information: */
// /* Any field is accessible: */
Js.log(jsObject##myName);

jsObject##myName#="HERBERT";
Js.log(jsObject##myName);
// /* Any method is accessible: */
// jsObject##myMethod("Hello");
 let hello = jsObject##myMethod("Hello");
// Js.log(hello)
