[%bs.raw {| require ("tachyons") |}];

ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client=Client.instance>
    <Router />
  </ReasonApollo.Provider>,
  "root",
);