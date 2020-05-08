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
   * @brief Enumeration indicating the severity level of information.
   */
  enum class ModDataSeverity {

    /**
     * @brief Used for mostly informative message that do not have impact on
     *     the mod behavior (e.g., a .txt files in an unlikely folder).
     */
    INFORMATIVE,

    /**
     * @brief Used to indicate that something does not look right and might 
     *     impact the mod behavior.
     */
    WARNING,

    /**
     * @brief Indicates that this mods cannot work if this issue is not fixed.
     */
    ERROR
  };

  /**
   * @brief Small class encapsulating information about mod data returned by 
   * methods from MoDataChecker.
   *
   */
  class ModDataInformation {

    /**
     *
     */
    ModDataInformation(ModDataSeverity severity, QString message) : 
      m_Severity(severity), m_Message(message) { }

    /**
     * @return the severity of this information.
     */
    ModDataSeverity severity() const { return m_Severity; }

    /**
     * @return the message corresponding to this information.
     */
    QString message() const { return m_Message; }

  private:

    ModDataSeverity m_Severity;
    QString m_Message;

  };

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
   * @brief Check that the given filetree representing a valid mod layout.
   *
   * This methods is mainly used during installation to find which installer should
   * be used or to recurse into multi-level archives, and to quickly indicates to a 
   * user if a mod looks valid. Heavy operations should be avoided in this method.
   *
   * @param tree The tree starting at the root of the "data" folder.
   *
   * @return whether or not the tree is valid, or if it is not possible
   *     to tell.
   */
  virtual CheckResult dataLooksValid(std::shared_ptr<const MOBase::IFileTree> fileTree) const = 0;

  /**
   * @brief Indicates if this feature can list issues for a mod.
   *
   * This method indicates whether `listPotentialIssues` can be used or not.
   *
   * @return true if this subfeature is implemented, or false otherwize.
   */
  virtual bool canListPotentialIssues() const = 0;

  /**
   * @brief List potential issues with the given mod layout.
   *
   * If this method cannot be used (`canListPotentialIssues()` returns `false`), then an
   * empty vector should be returned.
   *
   * @param tree The tree starting at the root of the "data" folder.
   *
   * @returns a list of information about the mod data.
   *
   * @see canListPotentialIssues 
   */
  virtual std::vector<ModDataInformation> listPotentialIssues(std::shared_ptr<const MOBase::IFileTree> fileTree) const = 0;

};

#endif