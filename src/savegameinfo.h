#ifndef SAVEGAMEINFO_H
#define SAVEGAMEINFO_H

namespace MOBase { class ISaveGame; }

class QString;

/** Feature to get hold of stuff to do with save games */
class SaveGameInfo
{
public:
  virtual ~SaveGameInfo() {}

  /* Get the information about the supplied save game */
  virtual MOBase::ISaveGame const *getSaveGameInfo(QString const &file) const = 0;

};

#endif // SAVEGAMEINFO_H

