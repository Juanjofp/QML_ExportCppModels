#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QObject>

#include "ui/gitusermodel.h"

namespace jjfp::ui {

class UIManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(GitUserModel *userModel READ userModel CONSTANT)

public:
    explicit UIManager();

    GitUserModel *userModel() const;

signals:

public slots:
    void addGitUser(const QString &name, const QString &email);
    void removeGitUser(const QString &name, const QString &email, int index);

private:
    std::unique_ptr<GitUserModel> userModel_;
};

} // namespace jjfp::ui

#endif
