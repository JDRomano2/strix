#include <iostream>

#include <strix/rdf/parse.hpp>

#include <pugixml.hpp>

int main() {
  std::cout << "Why hello there." << std::endl;
  std::cout << "This is a quick demo, where we parse the Pizza OWL ontology." << std::endl;

  auto pizza = rdf::RDFParser("data/pizza.owl");
}