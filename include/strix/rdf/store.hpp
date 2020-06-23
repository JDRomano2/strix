#ifndef STORE_HPP
#define STORE_HPP

#include <strix/identifiers.hpp>

class RTree {
 public:
  RTree() {};
 private:
  
};

namespace rdf {

  class StoreEngine {
   public:
    StoreEngine() {};
   private:
    strix::IDManager id_manager;
  };

  /**
   * Basic Triplestore class
   * 
   * Essentially, every RDF triple is stored in a (TBD) collection, but IRIs
   * and other RDF identifiers are replaced by nuemric placeholders that point
   * to indexes in a list of identifiers. This is meant to vastly improve
   * element accession speed, and moderately improve the memory footprint of
   * the ontology's internal representation.
   * 
   * Some of the architecture considerations here are inspired by those used in
   * owlcpp - see http://dx.doi.org/10.1186/s13326-015-0035-z
   * 
   * Considerations for choosing a fast, efficient internal collection should
   * consult http://ceur-ws.org/Vol-1343/paper19.pdf. B-trees might not be the
   * best option, because accession may be multidimensional - if a triple is
   * represented by (s, p, o), and we index a B-tree on s, then we can't take
   * advantage of the performance boost of a B-tree when performing accession
   * on p or o.
   */
  class Store {
   public:
    Store() {};
   private:
    triples
  };

}

#endif
