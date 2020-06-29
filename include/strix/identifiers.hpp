#ifndef IDENTIFIERS_HPP
#define IDENTIFIERS_HPP

#include <cstdint>

namespace strix {

  /**
   * Allocate new IDs and keep track of existing ones.
   */
  class IDManager {
   public:
    IDManager() {};
  };

  /**
   * Base ID class.
   * 
   * Lots of IDs are used in RDF and OWL documents. This is a base class that
   * provides the key functionality needed to support all of them.
   */
  template<class SuperID, class TypeOfVal = uint32_t>
  class BaseID {
   protected:
    typedef BaseID baseId;
   public:
    typedef TypeOfVal ValueType;
    explicit BaseID(const ValueType val) : value(val) {};
    BaseID(SuperID const& c) : value(c.value) {};
    ValueType operator()() const { return value; }
   private:
    ValueType value;
  };

  /**
   * RDF Document ID class
   * 
   * Note storage as uint8_t - you shouldn't be working with THAT many RDF
   * documents at once.
   */
  class RDFDocumentID : public strix::BaseID<RDFDocumentID> {
   public:
    explicit RDFDocumentID(const uint8_t val) : baseId(val) {};
    RDFDocumentID() : baseId(0) {};
  };

  class RDFNodeID : public strix::BaseID<RDFNodeID> {
   public:
    explicit RDFNodeID(const uint32_t val) : baseId(val) {};
    RDFNodeID() : baseId(0) {};
  };

  class RDFNamespaceID : public strix::BaseID<RDFNamespaceID> {
   public:
    explicit RDFNamespaceID(const uint32_t val) : baseId(val) {};
    RDFNamespaceID() : baseId(0) {};
  };

}

#endif