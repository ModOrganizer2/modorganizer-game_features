#ifndef LOCALSAVEGAMES_H
#define LOCALSAVEGAMES_H


#include <QString>
#include <QDir>
#include "filemapping.h"


namespace MOBase {
  class IProfile;
}


class LocalSavegames {

public:

  virtual ~LocalSavegames() {}

  virtual MappingType mappings(const QDir &profileSaveDir) = 0;
  virtual void prepareProfile(MOBase::IProfile *profile) = 0;

};

#endif // LOCALSAVEGAMES_H
