#ifndef MODDATACHECKER_H
#define MODDATACHECKER_H

#include <memory>

#include <QString>

namespace MOBase {

  class IFileTree;

};

class ModDataChecker {
public:

  /**
   *
   */
  enum class CheckResult {
    VALID,
    INVALID,
    UNCERTAIN
  };

  /**
   * @brief The name of the data folder for the game.
   *
   * For instance, for GameBryo games it is simply "data'.
   *
   * @return the name of the data folder. 
   */
  virtual QString getDataFolderName() const = 0;

  /**
   * @brief Check that the given filetree representing a valid mod
   *     layout.
   *
   * @param tree The tree starting at the root of the "data" folder.
   *
   * @return whether or not the tree is valid, or if it is not possible
   *     to tell.
   */
  virtual CheckResult isDataFolder(std::shared_ptr<const MOBase::IFileTree> fileTree) const = 0;

};

#endif