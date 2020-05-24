#ifndef MODDATACHECKER_H
#define MODDATACHECKER_H

#include <memory>

namespace MOBase {

  class IFileTree;

};

class ModDataChecker {
public:

  /**
   * @brief Check that the given filetree represent a valid mod layout.
   *
   * This method is mainly used during installation (to find which installer should
   * be used or to recurse into multi-level archives), or to quickly indicates to a 
   * user if a mod looks valid.
   *
   * This method does not have to be exact, it only has to indicate if the given tree
   * looks like a valid mod or not by quickly checking the structure (heavy operations
   * should be avoided).
   *
   * @param tree The tree starting at the root of the "data" folder.
   *
   * @return whether or not the tree looks valid.
   */
  virtual bool dataLooksValid(std::shared_ptr<const MOBase::IFileTree> fileTree) const = 0;

public:

  /**
   *
   */
  virtual ~ModDataChecker() { }

};

#endif