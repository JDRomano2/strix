# Strix

![CI](https://github.com/JDRomano2/strix/workflows/CI/badge.svg)

A (modern) library and command line tool for interacting with OWL2 ontologies

## What is Strix?

Strix is a command-line application and library for interacting with OWL ontologies, written in C++ and designed to be fast, correct, and optimized for artificial intelligence and translational bioinformatics applications.

We are still in the early stages of development, but as features are implemented we will update this README accordingly.

## What about other ontology tools?

There are other tools out there that may also solve your specific needs. When we decided to write this, we did so because none of the existing tools really fit our specific requirements. We found that none of the alternatives solve all of the following needs:

- Fast
- Modern (esp. in terms of managing dependencies, installing, using, performing CI, etc.)
- Transparent and open-source
- Includes an interactive (REPL) application for interacting with ontologies from the command line

Some alternatives that might be worth checking out, as well:

- [owlcpp](http://owl-cpp.sf.net/)
- [semtk](https://github.com/ge-semtk/semtk)

## How do I contribute to Strix's development?

Strix is open-source, and you are free to modify and reuse it. Check out [LICENSE](./LICENSE) for more details.

Once we get an initial release out we will start to accept contributions via GitHub pull requests - stay tuned for more info as we go through the development process!

## Licensing info

Strix is released as open-source softwware under the MIT license. Please see [LICENSE](./LICENSE) for further details.

Code from several other open-source projects are included in this repository. They are reproduced in their entirety, with their own license details left intact. These include [pugixml](http://pugixml.org/) (for XML parsing) and [CPM.cmake](https://github.com/TheLartians/CPM.cmake) (for loading some dependencies). Any derivations of Strix should not modify these files unless their license details permit doing otherwise.

## Contact us

You can reach us by [filing an issue on GitHub](https://github.com/jdromano2/strix/issues). The software is developed and maintained by Joseph D. Romano, PhD, currently at the University of Pennsylvania, and a member of the [Computational Genetics Lab](epistasis.org).