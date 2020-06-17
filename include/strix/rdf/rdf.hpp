#ifndef RDF_RDF_HPP
#define RDF_RDF_HPP

#include <set>
#include <string>

/**
 * Implementation of the Resource Description Framework (RDF), version 1.1.
 * (See https://www.w3.org/TR/2014/REC-rdf11-concepts-20140225/)
 * 
 * Includes RDFS (RDF Schema).
 * 
 * NOTE: This is, for now, a subset of the specification! Several components
 * are not in full conformance, e.g., language codes. Report any omissions that
 * impact the functionality of Strix to the code maintainers via a GitHub
 * issue report.
 */
namespace rdf {
  // For now, a blank node is just an empty IRI.
  // Note that IRIs are unicode-compliant, and therefore encoded as std::string.
  typedef std::string iri_t;

  /**
   * RDF Literal, used to store values such as strings, numbers, and dates.
   * See: https://www.w3.org/TR/2014/REC-rdf11-concepts-20140225/#section-Graph-Literal
   */
  class Literal {
   private:
    std::string lexical_form;
    iri_t datatype_iri;
    std::string lang_tag;
   public:
    Literal();

    std::string to_literal_value();
  };

  /**
   * Object - the third element of an RDF triple (subject, predicate, object).
   * 
   * An object can be either an IRI, a Literal, or a blank node (represented
   * as an empty IRI).
   * 
   * See: https://www.w3.org/TR/2014/REC-rdf11-concepts-20140225/#section-triples
   */
  class Object {
   public:
    Object() {};
   private:
    enum class Obj_type { IRI, LIT, BLANK_NODE };
    
    iri_t iri;
    rdf::Literal literal;
  };

  /**
   * RDFTriple - a triple value consisting of (subject, predicate, object).
   * 
   * An RDF Graph consists of an (unordered) set of triples. Triples describe
   * resources and the relationships between resources. The set of resources
   * present in an RDF document can be aggregated by iterating over the
   * triples.
   * 
   * See: https://www.w3.org/TR/2014/REC-rdf11-concepts-20140225/#section-triples
   */
  class RDFTriple {
   public:
    RDFTriple() {};

    std::set<iri_t> get_nodes();
   private:
    iri_t subj;
    iri_t pred;
    Object obj;
  };

  class RDFGraph {
   public:
    RDFGraph() {};
   private:
    std::set<RDFTriple> g;
  };

  class RDFDataset {
   public:
    RDFDataset() {};
   private:
    rdf::RDFGraph default_graph;
    std::set<std::tuple<iri_t, rdf::RDFGraph>> named_graphs;
  };

}

#endif