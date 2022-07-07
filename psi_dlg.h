#ifndef PSI_DLG_H
#define PSI_DLG_H

#include <QDialog>

//note: new opencv doesn't include this
#include <opencv2/opencv.hpp>
class PSITiltOptions;
namespace Ui {
class PSI_dlg;
}

class PSI_dlg : public QDialog
{
    Q_OBJECT

public:
    PSITiltOptions *m_tiltOptionsDlg;
    explicit PSI_dlg(QWidget *parent = 0);
    ~PSI_dlg();
    QStringList files();
    QVector<double> phases();
    bool m_knownPhase;
    bool m_doTiltPSI;
    void setPhases(QVector<double> phases);
    int maxIter();
    double tolerance();
    void setStatusText(const QString &txt);

signals:
    void computePhase();
private slots:
    void on_browse_clicked();

    void on_help_clicked();

    void on_clear_clicked();

    void on_PhaseKnown_clicked(bool checked);

    void on_PhaseApproximate_clicked(bool checked);

    void on_PSIPhaseValue_valueChanged(const QString &arg1);

    void on_computePhase_clicked();

    void on_maxiter_valueChanged(int arg1);

    void on_tolerance_valueChanged(double arg1);

    void on_VaryingRB_clicked(bool checked);

    void on_showVariationPb_clicked();

private:
    Ui::PSI_dlg *ui;
};

#endif // PSI_DLG_H
