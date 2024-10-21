#ifndef GITUSER_H
#define GITUSER_H

#include <QString>

namespace jjfp {
namespace ui {

class GitUser
{
public:
    GitUser(QString name, QString email);
    // ~GitUser() = default;

    const QString &name() const;
    const QString &email() const;

private:
    QString name_;

    QString email_;
};

} // namespace ui
} // namespace jjfp

#endif // GITUSER_H
