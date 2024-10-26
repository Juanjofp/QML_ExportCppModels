#include "gitusermodel.h"

namespace jjfp::ui {

static const char *ROLE_NAME = "name";
static const char *ROLE_EMAIL = "email";

GitUserModel::GitUserModel()
    : QAbstractListModel{}
    , gitUsers_{}
{}

int GitUserModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return gitUsers_.size();
}

QVariant GitUserModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= gitUsers_.size()) {
        return QVariant{};
    }

    const auto guser = gitUsers_.at(index.row()).get();

    switch (role) {
    case static_cast<int>(GitUserRol::Name):
        return guser->name();

    case static_cast<int>(GitUserRol::Email):
        return guser->email();

    default:
        return QVariant{};
    }
}

// Qt::ItemFlags GitUserModel::flags(const QModelIndex &index) const {}

QHash<int, QByteArray> GitUserModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[static_cast<int>(GitUserRol::Name)] = ROLE_NAME;
    roles[static_cast<int>(GitUserRol::Email)] = ROLE_EMAIL;

    return roles;
}

void GitUserModel::addGitUser(std::unique_ptr<GitUser> &gitUser)
{
    QModelIndex emptyIndex{};

    int lastIndex = rowCount(emptyIndex);

    beginInsertRows(emptyIndex, lastIndex, lastIndex);

    gitUsers_.emplace_back(std::move(gitUser));

    endInsertRows();

    emit gitUserCountChanged();
}

void GitUserModel::removeGitUser(int index)
{
    beginRemoveRows(QModelIndex{}, index, index);

    gitUsers_.erase(gitUsers_.begin() + index);

    endRemoveRows();
}

int GitUserModel::gitUserCount() const
{
    return rowCount(QModelIndex{});
}

} // namespace jjfp::ui
