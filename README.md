# reasonmtl-dojo-travel

see: <https://github.com/ReasonMTL/reasonmtl-dojo-3>

## TIL

Refreshed on Belt.Array.keepMap to get a workable value when graphql is returning and optional array of json.

Also used `get_in_ppx` to get a value back for an optional field on each item.

### Router
see: <https://reasonml.github.io/reason-react/docs/en/router#match-a-route>

ReasonReactRouter.useUrl(~serverUrl): get access to the current url as a hook in your React component. No need to setup watch, unwatch, and dangerouslyGetInitialUrl yourself.

`ReasonReactRouter.useUrl();` lets us use the route url to pattern match against. What is the differnce between `url` and `hash` on ReasonReactRouter?

This is `type url`:
Basically, `path` is the `url` and `hash` is any value with a `#` before it which gets stripped out. `search` are any query params that are on the url string which would come after the `?` symbol (which gets stripped out).

```reason
type url = {
  /* path takes window.location.pathname, like "/book/title/edit" and turns it into `["book", "title", "edit"]` */
  path: list(string),
  /* the url's hash, if any. The # symbol is stripped out for you */
  hash: string,
  /* the url's query params, if any. The ? symbol is stripped out for you */
  search: string
};

```

Example from docs:
So the url <www.hello.com/book/10/edit?name=Jane#author> is given back as:

```reason
{
  path: ["book", "10", "edit"],
  hash: "author",
  search: "name=Jane"
}
```

```reason
[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | [] => <TravelApp />
  | ["about"] => <About />
  | _ => <Error code=404 />
  };
};
```

## Installing / Getting started

All the dependencies can be install via your favorite package manager:

```shell
yarn install
```

That's it! You're up and running, you can start the project with:

```shell
yarn start
```

## Developing

Assuming you're developing with Visual Studio Code (if you're not, you should definitely give it a shot, it's awesome), all you need to develop is this extension: [vscode-reasonml](https://github.com/reasonml-editor/vscode-reasonml).

This will give you compilation errors in the editor and code intelliscence.

## Built With

Here's the list of the frameworks or libraries we use in the project:

- [ReasonML](https://reasonml.github.io/en/) - Fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems.
- [Reason-React](https://github.com/reasonml/reason-react) - Reason bindings for ReactJS.
- [graphql_ppx](https://github.com/mhallin/graphql_ppx) - GraphQL PPX rewriter for Bucklescript/ReasonML.
- [reason-apollo](https://github.com/apollographql/reason-apollo) - React-apollo with Reason.
