#ifndef MODDATACHECKER_H
#define MODDATACHECKER_H

#include <memory>
#include <vector>

#include <QString>

namespace MOBase {

  class IFileTree;

};

class ModDataChecker {
public:

  /**
   * @brief The name of the data folder for the game.
   *
   * For instance, for GameBryo games it is simply "data'.
   *
   * @return the name of the data folder. 
   */
  virtual QString getDataFolderName() const = 0;

  /**
   * @brief Check that the given filetree representing a valid mod layout.
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

};

#endif