#ifndef SAVEGAMEINFO_H
#define SAVEGAMEINFO_H

namespace MOBase { class ISaveGame; }

#include <QMap>

class QString;
class QStringList;

/** Feature to get hold of stuff to do with save games */
class SaveGameInfo
{
public:
  virtual ~SaveGameInfo() {}

  /** Get the information about the supplied save game */
  virtual MOBase::ISaveGame const *getSaveGameInfo(QString const &file) const = 0;

  typedef QStringList ProvidingModules;
  typedef QMap<QString, ProvidingModules> MissingAssets;

  /** Get items missing from save
   *
   * @returns a collection of missing assets and the modules that can supply those
   * assets.
   *
   * Note that in the situation where 'module' and 'asset' are indistinguishable,
   * both still have to be supplied.
   */
  virtual MissingAssets getMissingAssets(QString const &file) const = 0;
};

#endif // SAVEGAMEINFO_H

