#ifndef RDF_PARSE_HPP
#define RDF_PARSE_HPP

#include <filesystem>

#include <strix/rdf/rdf.hpp>
#include <pugixml.hpp>

namespace rdf {
  class RDFParser {
   public:
    RDFParser() {};
    rdf::RDFDataset ParseRdfDocument(std::string full_path);
    void addRDFTriple(pugi::xml_node);
   private:
    std::string local_path;
    pugi::xml_document xml_doc;
    pugi::xml_parse_result xml_parse_object;
  };
}

#endif