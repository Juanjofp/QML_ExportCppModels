#include "gituser.h"

namespace jjfp::ui {

GitUser::GitUser(QString name, QString email)
    : name_{name}
    , email_{email}
{}

const QString &GitUser::name() const
{
    return name_;
}

const QString &GitUser::email() const
{
    return email_;
}

} // namespace jjfp::ui
