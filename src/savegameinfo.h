#ifndef SAVEGAMEINFO_H
#define SAVEGAMEINFO_H

namespace MOBase { class ISaveGame; }

#include <QMap>

class QString;
class QStringList;
class QWidget;

/**
 * @brief Feature to get hold of stuff to do with save games.
 */
class SaveGameInfo
{
public:
  virtual ~SaveGameInfo() {}

  using ProvidingModules = QStringList;
  using MissingAssets = QMap<QString, ProvidingModules>;

  /** 
   * @brief Get the information about the supplied save game.
   */
  virtual MOBase::ISaveGame const *getSaveGameInfo(QString const &file) const = 0;

  /** 
   * @brief Get items missing from save
   *
   * @return a collection of missing assets and the modules that can supply those
   * assets.
   *
   * Note that in the situation where 'module' and 'asset' are indistinguishable,
   * both still have to be supplied.
   */
  virtual MissingAssets getMissingAssets(QString const &file) const = 0;

  /**
   * @return whether or not the save has a paired script extender save.
   */
  virtual bool hasScriptExtenderSave(QString const &file) const = 0;

  /**
   * Get a widget to display over the save game list.
   *
   * @param parent The parent widget.
   *
   * @return a QT Widget.
   *
   * @note It is permitted to return a null pointer to indicate you don't have a
   * nice visual way of displaying save game contents.
   */
  virtual QWidget* getSaveGameWidget(QWidget* parent = 0) const = 0;

  /**
   * @brief Update the save game widget with the corresponding save.
   *
   * @param widget The save game widget initially returned by `getSaveGameWidget()`.
   * @param save The save game to display in the widget.
   *
   */
  virtual void updateSaveGameWidget(QWidget* widget, QString const& file) const = 0;
};

#endif // SAVEGAMEINFO_H

