#include <iostream>

#include <strix/strix.h>

#include <pugixml.h>

int main() {
  strix::Strix st();
  std::cout << "Why hello there" << std::endl;

  // Parse the Pizza ontology
  char* pizza_fname = "data/pizza.owl";
  pugi::xml_document pizza_doc;
  pugi::xml_parse_result pizza = pizza_doc.load_file(pizza_fname);

  std::cout << "Load result: " << pizza.description() << ", mesh name: " << 
  pizza_doc.child("mesh").attribute("name").value() << std::endl;

}