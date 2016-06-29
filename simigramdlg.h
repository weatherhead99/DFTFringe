/******************************************************************************
**
**  Copyright 2016 Dale Eason
**  This file is part of DFTFringe
**  is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation version 3 of the License

** DFTFringe is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with DFTFringe.  If not, see <http://www.gnu.org/licenses/>.

****************************************************************************/
#ifndef SIMIGRAMDLG_H
#define SIMIGRAMDLG_H

#include <QDialog>
#include <QAbstractTableModel>
class zTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    zTableModel(QObject *parent,  std::vector<bool> *enables, bool editEnable = false);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void setValues(std::vector<double> *vals);
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const ;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    std::vector<double> *values;
    std::vector<bool> *m_enables;
    void update();
signals:
    void zernChanged();
private:
    bool canEdit;

};
namespace Ui {
class simIgramDlg;
}

class simIgramDlg : public QDialog
{
    Q_OBJECT

public:
    explicit simIgramDlg(QWidget *parent = 0);
    ~simIgramDlg();
    static simIgramDlg*get_instance();
    double xtilt;
    double ytilt;
    double defocus;
    double correction;
    double xastig;
    double yastig;
    double star;
    double ring;
    double noise;
    int size;
    bool doCorrection;
    std::vector<double> zernikes;
    std::vector<bool> enables;
protected:
    void showEvent(QShowEvent *);

private slots:
    void on_buttonBox_accepted();

    void on_importPb_clicked();

    void on_correctionPb_clicked(bool checked);

    void on_Z8Pb_clicked(bool checked);

private:
    Ui::simIgramDlg *ui;
    static simIgramDlg *m_instance;
    zTableModel *tableModel;

};

#endif // SIMIGRAMDLG_H
