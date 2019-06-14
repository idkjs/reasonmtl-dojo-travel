[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | [] => <TravelApp />
  | ["about"] => <About />
  | _ => <Error code=404 />
  };
};
// [@react.component]
// let make = () => {
//   let url = ReasonReactRouter.useUrl();

//   let nowShowing =
//     switch (url.path) {
//     | [] => <App />
//     | ["repo", "create"] => <CreateRepo />
//     | _ => <NotFound />
//     };
//   ();
//   nowShowing;
// };