#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDebug>
#include <QString>
#include <QSlider>
#include <QMenuBar>
#include <QSpinBox>
#include <QLineEdit>
#include <QKeyEvent>
#include <QTabWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QPushButton>
#include <QMouseEvent>
#include <QTableWidget>
#include <QtCore/qmath.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QStringList nameList2;
    QString InputStr;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);
    void setAreaMovable(const QRect);
    int getXORresult(QString &, QString &, QStringList &);
    int BitList_can_merge(QStringList);
    void keyPressEvent(QKeyEvent *);

private:
    Ui::MainWindow *ui;
    QTabWidget * tabWidget;
    QRect m_areaMovable;//可移动窗口的区域，鼠标只有在该区域按下才能移动窗口
    bool m_bPressed;//鼠标按下标志（不分左右键）
    QPoint m_ptPress;//鼠标按下的初始位置
    QWidget * widget1 = new QWidget(); //新建一个页面的部件
    QWidget * widget3 = new QWidget();
    QWidget * widget4 = new QWidget();
    QWidget * widget5 = new QWidget();
    QLabel *La1 = new QLabel("输入", widget1);
    QLabel *La2 = new QLabel("输出", widget1);
//    QLabel *La3 = new QLabel("最简与或表达式 ", widget5);
    QLabel *FinalText = new QLabel(widget5);
    QSpinBox *SB1 = new QSpinBox(widget1);
    QSlider *Sd1 = new QSlider(widget1);
    QSpinBox *SB2 = new QSpinBox(widget1);
    QSlider *Sd2 = new QSlider(widget1);
};
#endif // MAINWINDOW_H
