module Style = {
  open Css;

  let title = style([textAlign(center), color(hex("666"))]);
  let pokelist =
    style([display(flexBox), flexWrap(wrap), width(pct(100.0))]);

  let pokemon =
    style([
      height(px(300)),
      width(px(300)),
      backgroundColor(rgba(50, 20, 100, 1.0)),
      margin(px(20)),
      padding(px(20)),
      color(white),
    ]);

  let pokemonImg = style([width(px(200))]);
};

// module PokemonQuery = [%graphql
//   {|
//     query {
//       pokemons(offset: 0) {
//         id
//         name
//         sprites {
//           default {
//             front
//             back
//           }
//         }
//       }
//     }
//   |}
// ];

// module GetPokemonQuery = ReasonApollo.CreateQuery(PokemonQuery);
module GetPackages = [%graphql
  {|
  query {
      packages {
        id
        destination
        tagLine
        description
        image
        footerText
      }
    }
  |}
];

module GetPackagesQuery = ReasonApollo.CreateQuery(GetPackages);

let getPackageImage = package =>
  Belt.Option.getWithDefault(
    [%get_in package##image],
    "",
  );
[@react.component]
let make = () => {
  // let getPackagesQuery = GetPackages.make();
  <div className="vh-100 vw-100 flex flex-column justify-start items-center">
    <h1 className=Style.title> {React.string({j|My Pokédex|j})} </h1>
    <GetPackagesQuery>
      ...{({result}) =>
        switch (result) {
        | Loading => <div> {React.string("Loading")} </div>
        | Error(error) => <div> {React.string(error##message)} </div>
        | Data(response) =>
          Js.log(response);
          // the graphql query returns a Js.Option so to deal with that we use keepMap which iterates over each package and returns it if it exists. Then we can use this array to work with each package.
          let packages = Belt.Array.keepMap(response##packages, package => package);
          Js.log2("PACKAGES: ", packages);
          <div className=Style.pokelist>
        {React.array(
           Belt.Array.map(packages, package =>
             <div className=Style.pokemon key=package##id>
              {React.string(package##destination)}
              <img src={getPackageImage(package)} className=Style.pokemonImg />
              </div>
           ),
         )}
                   </div>;

        }
      }
    </GetPackagesQuery>
  </div>;
};