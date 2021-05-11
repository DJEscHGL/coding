#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "graph.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QPoint previousPosition READ previousPosition WRITE setPreviousPosition NOTIFY previousPositionChanged)
    enum MouseType {
            None,
            Move
        };

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPoint previousPosition() const;
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    void setPreviousPosition(QPoint previousPosition);

signals:
    void previousPositionChanged(QPoint previousPosition);

private:
    Ui::MainWindow *ui;
    graph *graphwin;
    MouseType m_leftMouseButtonPressed;
    QPoint m_previousPosition;
    MouseType checkResizableField(QMouseEvent *event);

private slots:
    void numbers();
    void on_pushButton_dot_clicked();
    void operations();
    void on_pushButton_AC_clicked();
    void on_pushButton_equall_clicked();
    void math();
    //void extmath();
    void on_history_clear_clicked();
    void on_pushButton_about_clicked();
    void on_btn_hide_clicked();
    void on_btn_gparhopen_clicked();
    void on_btn_mr_clicked();
    void on_btn_mcl_clicked();
    void on_btn_mpl_clicked();
    void on_btn_mmin_clicked();
};

#endif // MAINWINDOW_H
