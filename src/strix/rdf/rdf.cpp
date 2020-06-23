#include <strix/rdf/rdf.hpp>

using namespace rdf;

std::string RDFLiteralNode::to_literal_value() {
  // https://www.w3.org/TR/2014/REC-rdf11-concepts-20140225/#dfn-literal
  std::string literal_str;
  if (lang_tag.empty()) {
    literal_str += "\"";
    literal_str += this->lexical_form;
    literal_str += "\"";
    literal_str += "^^";
    literal_str += this->datatype_iri;
  } else {
    // The literal is a *language tagged string*
    literal_str += "NULL";
  }

  return literal_str;
}
