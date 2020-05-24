#ifndef MODDATACONTENT_H
#define MODDATACONTENT_H

#include <algorithm>
#include <memory>
#include <vector>

#include <QString>

namespace MOBase {

  class IFileTree;

};

class ModDataContent {
public:

  struct Content {

    /**
     * @param id ID of this content.
     * @param name Name of this content.
     * @param icon Path to the icon for this content. Can be either a path 
     *     to an image on the disk, or to a resource.
     */
    Content(int id, QString name, QString icon) : m_Id{ id }, m_Name { name }, m_Icon{ icon } { }

    int id() const { return m_Id; }
    QString name() const { return m_Name; }
    QString icon() const { return m_Icon; }
  
  private:

    int m_Id;
    QString m_Name;
    QString m_Icon;
  };

  /**
   * @return the list of all possible contents for the corresponding game.
   */
  virtual std::vector<Content> getAllContents() const = 0;

  /**
   * @brief Retrieve the list of contents in the given tree.
   *
   * @param fileTree The tree corresponding to the mod to retrieve contents for.
   *
   * @return the IDs of the content in the given tree.
   */
  virtual std::vector<int> getContentsFor(std::shared_ptr<const MOBase::IFileTree> fileTree) const = 0;

  /**
   * @brief Check if the given tree contain the given content.
   *
   * @param fileTree The tree corresponding to the mod to check.
   * @param contentId The ID of the content to lookup.
   *
   * @return true if the given tree contains the given content, false otherwize.
   */
  virtual bool hasContent(std::shared_ptr<const MOBase::IFileTree> fileTree, int contentId) const {
    auto contents = getContentsFor(fileTree);
    return std::find(std::begin(contents), std::end(contents), contentId) != std::end(contents);
  }

public:

  /**
   *
   */
  virtual ~ModDataContent() { }

};

#endif