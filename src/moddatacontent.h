#ifndef MODDATACONTENT_H
#define MODDATACONTENT_H

#include <algorithm>
#include <memory>
#include <vector>

#include <QString>

namespace MOBase {

  class IFileTree;

};

/**
 * The ModDataContent feature is used (when available) to indicate to users the content
 * of mods in the "Content" column.
 *
 * The feature exposes a list of possible content types, each associated with an ID, a name
 * and an icon. The icon is the path to either:
 *   - A Qt resource or;
 *   - A file on the disk.
 *
 * In order to facilitate the implementation, MO2 already provides a set of icons that can
 * be used. Those icons are all under :/MO/gui/content (e.g. :/MO/gui/content/plugin or :/MO/gui/content/music). 
 *
 * The list of available icons is:
 *  - plugin: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/jigsaw-piece.png
 *  - skyproc: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/hand-of-god.png
 *  - texture: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/empty-chessboard.png
 *  - music: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/double-quaver.png
 *  - sound: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/lyre.png
 *  - interface: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/usable.png
 *  - skse: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/checkbox-tree.png
 *  - script: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/tinker.png
 *  - mesh: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/breastplate.png
 *  - string: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/conversation.png
 *  - bsa: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/locked-chest.png
 *  - menu: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/config.png
 *  - inifile: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/feather-and-scroll.png
 *  - modgroup: https://github.com/ModOrganizer2/modorganizer/blob/master/src/resources/contents/xedit.png
 */
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

public:

  /**
   *
   */
  virtual ~ModDataContent() { }

};

#endif