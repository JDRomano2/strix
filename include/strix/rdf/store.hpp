#ifndef STORE_HPP
#define STORE_HPP

#include <strix/identifiers.hpp>

#include <string>
#include <vector>


namespace rdf {

  class StoreEngine {
   public:
    StoreEngine() {};
   private:
    strix::IDManager id_manager;
  };

  class NodeKey {
   protected:
    strix::RDFNodeID node_id;
   public:
    rdf::NodeKey() {};
  };

  /**
   * Abstract base class for a triplestore implementation.
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
    virtual NodeKey findNodeByLabel(std::string label_str) =0;
    virtual void addNodeByLabel(std::string label_str) =0;
  };

  template<typename T>
  class BTreeNode {
  public:
    BTreeNode() {};
  private:
    uint8_t n; // number of keys stored in this node
    std::vector<T> keys; // keys, in nondecreasing order
    bool leaf; // Is this node a leaf, or is it an internal node?
    std::vector<T*> children;
  };

  class BTree {
  public:
    rdf::BTree() {}; // Create an empty b-tree
    rdf::BTree(std::vector<std::string> init_nodes) {}; // `B-TREE-CREATE` in CLRS
    void addKey(NodeKey k);
  private:
    rdf::BTreeNode<strix::RDFNodeID>* root;
    uint8_t h; // All leaves are at the same depth, which is equal to its height h
    uint16_t t; // Minimum degree of each node (t \geq 2)

    rdf::BTreeNode<strix::RDFNodeID>* bTreeSearch();
    void bTreeInsert(std::string newNode);

  };

}

#endif
