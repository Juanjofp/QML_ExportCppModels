#ifndef GITUSERMODEL_H
#define GITUSERMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QQmlEngine>
#include <vector>

#include "gituser.h"

namespace jjfp::ui {

class GitUserModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int gitUserCount READ gitUserCount NOTIFY gitUserCountChanged CONSTANT)

public:
    enum class GitUserRol { Name = Qt::UserRole + 1, Email };
    Q_ENUM(GitUserRol);

public:
    explicit GitUserModel();

signals:
    void gitUserCountChanged();

public:
    // QAbstractItemModel interface

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    // virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    // Manage users

    void addGitUser(std::unique_ptr<GitUser> &gitUser);

    void removeGitUser(int index);

    int gitUserCount() const;

private:
    std::vector<std::unique_ptr<GitUser>> gitUsers_;
};

} // namespace jjfp::ui

#endif // GITUSERMODEL_H
