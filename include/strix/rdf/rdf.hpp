#ifndef RDF_RDF_HPP
#define RDF_RDF_HPP

#include <strix/identifiers.hpp>

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

  class RDFNode {
   public:
    bool operator== (const RDFNode& n) { return Equal(n); }
    bool operator!= (const RDFNode& n) { return ! Equal(n); }
    RDFNode* clone() const { return CloneImpl(); }
   private:
    virtual bool Equal(const RDFNode& n) const =0;
    virtual RDFNode* CloneImpl() const =0;
  };

  class RDFBlankNode : public RDFNode {
   public:
    RDFBlankNode(const strix::RDFDocumentID doc) : parent_document(doc) {};

    strix::RDFDocumentID document() const { return parent_document; }
   private:
    strix::RDFDocumentID parent_document;
  };

  /**
   * RDF Literal, used to store values such as strings, numbers, and dates.
   * See: https://www.w3.org/TR/2014/REC-rdf11-concepts-20140225/#section-Graph-Literal
   */
  class RDFLiteralNode : public RDFNode {
   public:
    RDFLiteralNode();
    std::string to_literal_value();
   private:
    std::string lexical_form;
    iri_t datatype_iri;
    std::string lang_tag;
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
    // RDFLiteralNode literal;
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