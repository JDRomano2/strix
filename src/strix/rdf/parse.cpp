#include <strix/rdf/parse.hpp>

#include <filesystem>
#include <iostream>

// For the following block, see https://stackoverflow.com/a/20170989/1730417
#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>
#define typename(x) (type_name<decltype(x)>())
template <class T>
std::string type_name() {
  typedef typename std::remove_reference<T>::type TR;
  std::unique_ptr<char, void(*)(void*)> own
       (
#ifndef _MSC_VER
        abi::__cxa_demangle(typeid(TR).name(), nullptr,
                       nullptr, nullptr),
#else
        nullptr,
#endif
        std::free
       );
  std::string r = own != nullptr ? own.get() : typeid(TR).name();
  if (std::is_const<TR>::value)
    r += " const";
  if (std::is_volatile<TR>::value)
    r += " volatile";
  if (std::is_lvalue_reference<T>::value)
    r += "&";
  else if (std::is_rvalue_reference<T>::value)
    r += "&&";
  return r;
}

using namespace rdf;
using namespace pugi;

rdf::RDFDataset RDFParser::ParseRdfDocument(std::string full_path) {
  rdf::RDFDataset parsed_dataset = RDFDataset();

  this->local_path = full_path;
  this->xml_parse_object = this->xml_doc.load_file(full_path.c_str());

  xml_node rdf_top_node = this->xml_doc.first_child();

  xml_node ontology_node = rdf_top_node.first_child();
  
  if (true) {
    std::cout << "  DEBUG INFO - RDF PARSER" << std::endl;
    std::cout << "  Load result: " << this->xml_parse_object.description() << std::endl;
    std::cout << "  XML Namespace: " << this->xml_doc.child("rdf:RDF").attribute("xmlns").value() << std::endl;
    std::cout << "  this->xml_doc type: " << typename(this->xml_doc) << std::endl;
    std::cout << "  Number of child nodes (XML): " << this->xml_doc.child("rdf:RDF") << std::endl;
    std::cout << std::endl;
    std::cout << "  RDF top node name: " << rdf_top_node.name() << std::endl;
    std::cout << "  RDF top node value: " << rdf_top_node.value() << std::endl;
    std::cout << "  RDF top node first attribute: " << rdf_top_node.first_attribute().name() << std::endl;
    std::cout << std::endl;
    std::cout << "  Ontology node name: " << ontology_node.name() << std::endl;
    std::cout << "  Ontology node value: " << ontology_node.value() << std::endl;
    std::cout << "  Ontology node first attribute: " << ontology_node.first_attribute().name() << std::endl;
  }

  return parsed_dataset;
};