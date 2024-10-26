#include "uimanager.h"

namespace jjfp::ui {

UIManager::UIManager()
    : QObject{nullptr}
    , userModel_{std::make_unique<GitUserModel>()}
{

    auto userJuanjo = std::make_unique<ui::GitUser>("Juanjo", "juanjo@juanjofp.com");
    auto userMari = std::make_unique<ui::GitUser>("Mari", "mari@juanjofp.com");

    userModel_->addGitUser(userJuanjo);

    userModel_->addGitUser(userMari);

    qmlRegisterType<GitUserModel>("jjfp", 1, 0, "GitUserModel");
}

GitUserModel *UIManager::userModel() const
{
    return userModel_.get();
}

void UIManager::addGitUser(const QString &name, const QString &email)
{

    auto newUser = std::make_unique<GitUser>(name, email);

    userModel_->addGitUser(newUser);
}

void UIManager::removeGitUser(const QString &name, const QString &email, int index)
{
    qDebug() << "From UIManager: Delete" << name << email << index;

    userModel_->removeGitUser(index);
}

} // namespace jjfp::ui
