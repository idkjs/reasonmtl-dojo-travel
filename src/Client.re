// let serverUri = "https://reasonable-pokedex-git-cors.davidcorticchiato.now.sh/graphql";
let serverUri = "https://care-to-travel-bf8357556e.herokuapp.com/CareToTravel/dev";
let instance =
  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.createHttpLink(~uri=serverUri, ()),
    ~cache=ApolloInMemoryCache.createInMemoryCache(),
    (),
  );