#ifndef RDF_PARSE_HPP
#define RDF_PARSE_HPP

#include <filesystem>

#include <strix/rdf/rdf.hpp>
#include <pugixml.hpp>

namespace rdf {
  class RDFParser {
   public:
    RDFParser(std::string full_path);
   private:
    std::string local_path;
    pugi::xml_document xml_doc;
    pugi::xml_parse_result xml_parse_object;
    rdf::RDFDataset dataset;
  };
}

#endif