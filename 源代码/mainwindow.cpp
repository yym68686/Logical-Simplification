#include "mainwindow.h"
#include "ui_mainwindow.h"
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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600,470);
    this->setWindowOpacity(0.8);
    this->setWindowFlags(Qt::FramelessWindowHint);//设置窗体无边框,允许任务栏按钮右键菜单
    this->setAttribute(Qt::WA_TranslucentBackground);//设置背景透明

    tabWidget = new QTabWidget(this);
    tabWidget->addTab(widget1,"初始化");
    tabWidget->addTab(widget3,"真值表");
//    tabWidget->addTab(widget4,"表达式");
    tabWidget->addTab(widget5,"最简与或表达式");
    tabWidget->setGeometry(0,0,600,470);    //设置窗体部件大小
    tabWidget->setMovable(true);   //设置页面是否可被拖拽移动
    tabWidget->setTabShape(QTabWidget::Rounded);   //设置圆角
    tabWidget->setTabBarAutoHide(true);   //设置自动隐藏

    La1->setGeometry(20, 50, 200, 20);
//    La3->setGeometry(20, 110, 200, 20);
//    La3->setStyleSheet("background:transparent; border-width: 0; border-style: outset; font-family: Consolas; font-size: 17px; color: rgb(24,26,27);");

    SB1->setMinimum(1);  // 最小值
    SB1->setMaximum(4);  // 最大值
    SB1->setGeometry(50, 50, 40, 20);

    Sd1->setGeometry(100, 50, 200, 20);
    Sd1->setMinimum(1);  // 最小值
    Sd1->setMaximum(4);  // 最大值
    Sd1->setOrientation(Qt::Horizontal);

    La2->setGeometry(20, 70, 200, 20);

    SB2->setMinimum(1);  // 最小值
    SB2->setMaximum(3);  // 最大值
    SB2->setGeometry(50, 70, 40, 20);

    Sd2->setGeometry(100, 70, 200, 20);
    Sd2->setMinimum(1);  // 最小值
    Sd2->setMaximum(3);  // 最大值
    Sd2->setOrientation(Qt::Horizontal);
    int BoolValueChanged = 1;
    connect(SB2, QOverload<int>::of(&QSpinBox::valueChanged), Sd2, &QSlider::setValue);
    connect(Sd2, QOverload<int>::of(&QSlider::valueChanged), SB2, &QSpinBox::setValue);
    connect(SB1, QOverload<int>::of(&QSpinBox::valueChanged), Sd1, &QSlider::setValue);
    connect(Sd1, QOverload<int>::of(&QSlider::valueChanged), SB1, &QSpinBox::setValue);
    connect(SB1, QOverload<int>::of(&QSpinBox::valueChanged), [=, &BoolValueChanged]()mutable{
        BoolValueChanged = 1;
    });
    connect(SB2, QOverload<int>::of(&QSpinBox::valueChanged), [=, &BoolValueChanged]()mutable{
        BoolValueChanged = 1;
    });

    QMap<QString, QString> map;
//    map.insert("X", "0");
    map.insert("0", "1");
    map.insert("1", "0");
//    map.insert("X", "0");
//    map.insert("0", "1");
//    map.insert("1", "X");
    QTableWidget * TableWidget = new QTableWidget();
    connect(TableWidget, &QTableWidget::cellClicked, [=](int a, int b)mutable{
//        qDebug() << a << " " << b;
        if (b >= SB1->value())
            TableWidget->setItem(a, b, new QTableWidgetItem(map[TableWidget->item(a, b)->text()]));
        int RowsCount = TableWidget->rowCount();
        int ColumnCount = TableWidget->columnCount();
        for (int i = 0; i < RowsCount; i++){
            for (int j = 0; j < ColumnCount; j++){
                TableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                if (i % 2 != 0)
                    TableWidget->item(i,j)->setBackground(QColor(240,240,240));//设置单元格背景色
            }
        }
        TableWidget->clearSelection();
    });
    QString kkk = "0100100";
    QByteArray kkkk = kkk.toLatin1();
//    qDebug() << getXORresult("0100", "1000");


//    QListWidget *listWidget1 = new QListWidget(widget5);
//    listWidget1->setGeometry(20, 10, 100, 100);
//    listWidget1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);            //去掉垂直滚动条
//    listWidget1->setStyleSheet("background:transparent; border-width: 0; border-style: outset; font-family: Consolas; font-size: 17px; color: rgb(24,26,27);");

//    QLineEdit *lineEdit1 = new QLineEdit(widget5);
//    lineEdit1->setGeometry(20, 130, 400, 20);
//    lineEdit1->setEnabled(false);
//    lineEdit1->setAttribute(Qt::WA_InputMethodEnabled, false); //屏蔽输入法的QLineEdit上调用
//    lineEdit1->setStyleSheet("background:transparent; border-width: 0; border-style: outset; font-family: Consolas; font-size: 17px; color: rgb(24,26,27);");

//    FinalText->setStyleSheet("background:transparent; border-width: 0; border-style: outset; font-family: Consolas; font-size: 17px; color: rgb(24,26,27);");
//    FinalText->setGeometry(20, 200, 400, 20);
//    FinalText->adjustSize();
//    FinalText->setWordWrap(true);
//    FinalText->setAlignment(Qt::AlignTop);

//    lineEdit1->setClearButtonEnabled(1);//设置删除清空按钮

//    QPushButton * pushButton1 = new QPushButton("Add",widget1);
//    pushButton1->setGeometry(20,160,190,30); //从屏幕上（10，45）位置开始（即为最左上角的点），显示一个190*30的界面（宽190，高30）
//    connect(pushButton1, &QPushButton::clicked, [=](){
//        listWidget1->addItem(lineEdit1->text());
//        InputStr = lineEdit1->text();
//        InputEvent();
//        lineEdit1->clear();
//    });
//    connect(listWidget1, &QListWidget::itemClicked, [=](){
//        listWidget1->takeItem(listWidget1->currentRow());
//    });


    QLineEdit *lineEdit3 = new QLineEdit();
    QList<QLineEdit*> LineList;
    LineList << lineEdit3 << lineEdit3 << lineEdit3;
    BoolValueChanged = 1;
    connect(tabWidget, &QTabWidget::tabBarClicked, [=, &BoolValueChanged]()mutable{
//        if (currentIndex == 3) {
            if (BoolValueChanged == 1){//这个if里面的代码都是在渲染真值表，每一次修改变量，输出个数，都要重新渲染，BoolValueChanged == 1 说明需要渲染
                char a = 'A', nnum = '1';
                QStringList character;
                for (int i = 0; i < SB1->value(); i++)
                    character << QString(a + i);
                for (int i = 0; i < SB2->value(); i++)
                    character << "F" + QString(nnum + i);
                TableWidget->setColumnCount(SB1->value() + SB2->value());
                TableWidget->setHorizontalHeaderLabels(character);
                TableWidget->setRowCount(qPow(2, SB1->value()));

                QList<QString> sexList;
                for (int i = 0; i < qPow(2, SB1->value()); i++){
                    QString strr = "";
                    for (int j = SB1->value() - 1; j >= 0; j--){
                        if (i & (1 << j))
                            strr += "1";
                        else
                            strr += "0";
                    }
                    sexList << strr;
                }
                int RowsCount = TableWidget->rowCount();
                int ColumnCount = TableWidget->columnCount();
                for (int i = 0; i < RowsCount; i++){
                    for (int j = 0; j < ColumnCount; j++){
                        if (j < SB1->value())
                            TableWidget->setItem(i, j, new QTableWidgetItem(QString(sexList[i][j])));
                        else
                            TableWidget->setItem(i, j, new QTableWidgetItem("0"));
//                            TableWidget->setItem(i, j, new QTableWidgetItem("X"));
                        TableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                        if (i % 2 != 0)
                            TableWidget->item(i,j)->setBackground(QColor(240,240,240));
                    }
                }
                BoolValueChanged = 0;//
            }
            else {
                for (int p = 0; p < SB2->value(); p++){
                    QStringList BitList, nowList;//BitList一开始存 应变量为一的最小项，后来处理后得到合并后的最小项
                    QString strRow = "";//这个存应变量为一的最小项位数对应变量个数，如ABCD的二进制存成一个二进制字符串
                    for(int i = 0; i < qPow(2, SB1->value()); i++){//一共的行数等于 2^变量个数
                        if (TableWidget->item(i, SB1->value() + p)->text() == "1"){//当应变量为一的时候执行if里面的代码
                            for (int k = 0; k < SB1->value(); ++k) {
                                strRow += TableWidget->item(i, k)->text();//把应变量为一的哪一行的二进制组合起来，用字符串存起来
                            }
                            BitList << strRow;//处理完成就放到数组里
                            strRow = "";//字符串归零，继续下一轮
                        }
                    }
                    QMap<QString, QString> Nummap;//
                    while (BitList_can_merge(BitList)){//在BitList里面任取两个元素如果可以合并，则一直循环下去
                        while(!BitList.empty()){//为什么BitList为空？因为一旦可以合并后就把合并好的放到nowList里面去，并且把BitList里当前遍历的字符串pop掉，直到BitList为空，退出循环
                            QString strfront = BitList.first();//strfront为当前BitList最前面的字符串，用strfront去比较bitList后面的字符串，如果可以合并就合并后放到nowlist里面，并且把strfront从bitlist里面删掉
                            int flag = 0;//flag的作用就是
                            BitList.pop_front();//删掉最前面的字符串
                            for(int j = 0; j < BitList.count(); j++){//这个循环就是
                                if (getXORresult(strfront, BitList[j], nowList) == 1) {
                                    flag = 1;
                                    Nummap.insert(BitList[j], "1");//放进Nummap说明BitList[j]可以被strfront合并
                                }
                            }
                            if (flag == 0 && Nummap.find(strfront) == Nummap.end() ) {//flag == 0 说明strfront不能合并，这个时候需要单独放进nowlist，如果Nummap.find(strfront) == Nummap.end()，说明strfront不能被其他字符串合并
                                nowList << strfront;
                            }
                        }
                        for (int i = 0; i < nowList.count() - 1; i++){//这个循环的作用就是删掉nowlist里面重复的也就是一摸一样的字符串，之所以会有重复的，是因为bitlist里面每一个都有可能多次跟不同的其它字符串合并
                            for (int j = i + 1; j < nowList.count(); j++){
                                if (nowList[i] == nowList[j]) nowList.removeAt(j);
                            }
                        }
    //                    for (int i = 0; i < nowList.count(); i++) {
    //                        qDebug() << "nowList " << nowList[i];
    //                    }
    //                    qDebug() << "\n";
                        while (!nowList.empty()) {
                            BitList << nowList.first();//把所有的nowlist的字符串全部放进bitlist里面，等待下一次合并
                            nowList.pop_front();
                        }
                    }//以上完成初步的合并，下面将完成实质素项产生式,初步合并的意思就是，已经不能再合并了
                    for (int o = 0; o < BitList.count(); o++){
                        qDebug() << BitList[o];
                    }

                    QMap<QString, QStringList> BitMap;//它是一个表格QString放最最开始bitlist里面的内容也就是，一开始的所有最小项，QStringList里面放这个最小项被那些合并后的项包围了
                    QStringList BitTemp;
    //                QStringList BitTemp, FinalList;
                    for (int i = 0; i < BitList.count(); i++){//这个循环的作用就是通过BitList里面已经不能再合并的字符串推导出，它包含那些字符串，就是包含那些一开始还没有合并的最小项。
                        BitTemp << BitList[i];
                        while (!BitTemp.empty()){
                            QString TempStr = BitTemp.first();
                            QString ToNumStr1 = TempStr;
                            QString ToNumStr2 = TempStr;
                            BitTemp.pop_front();
                            int BoolFlag = 0;
                            for (int j = 0; j < TempStr.count(); j++){
                                if (TempStr[j] == "-"){
                                    ToNumStr1.replace(j, 1, "0");
                                    ToNumStr2.replace(j, 1, "1");
                                    BoolFlag = 1;
                                    break;
                                }
                            }
                            if (BoolFlag){
                                int flag = 0;
                                for (int k = 0; k < ToNumStr1.count(); k++){
                                    if (ToNumStr1[k] == "-") BitTemp << ToNumStr1, flag = 1;
                                }
                                if (!flag) BitMap[ToNumStr1] << BitList[i];
        //                        if (!flag) FinalList << ToNumStr1, BitMap[ToNumStr1] << BitList[i];
                                flag = 0;
                                for (int k = 0; k < ToNumStr2.count(); k++){
                                    if (ToNumStr2[k] == "-") BitTemp << ToNumStr2, flag = 1;
                                }
                                if (!flag) BitMap[ToNumStr2] << BitList[i];
        //                        if (!flag) FinalList << ToNumStr2, BitMap[ToNumStr2] << BitList[i];
        //                                qDebug() << ToNumStr1 << " " << ToNumStr2;
                            }
                            else {
                                BitMap[ToNumStr2] << BitList[i];
                            }
                        }
                        //上面完成了”-“的转换
                    }
                    qDebug() << "\n显示所有BitMap: ";
                    QMap<QString, QStringList>::iterator yyy = BitMap.begin();
                    for (; yyy != BitMap.end(); yyy++){
                        qDebug() << yyy.key() << " " << yyy.value();
                    }

                    QStringList FinalStringList;//这个序列用来存放最后化简出来的最小项
    //                int yyy = 0;
                    while (1){
                        QMap<QString, QStringList>::iterator y = BitMap.begin();
                        QString RightStr;
                        while (1){//删掉list只有一个的情况
                            y = BitMap.begin();
                            int ValueFlag = 0;
                            for (; y != BitMap.end(); y++){
                                if (y.value().count() == 1)
                                    RightStr = y.value().first(), ValueFlag = 1;
                            }
                            if (!ValueFlag) break;
                            FinalStringList << RightStr;
                            while (1){
                                int BitFlag = 0;
                                y = BitMap.begin();
                                for (; y != BitMap.end(); y++){
                                    if (y.value().contains(RightStr))
                                        BitMap.erase(y), BitFlag = 1;
                                }
                                if (!BitFlag) break;
                            }
                        }

                        y = BitMap.begin();
                        qDebug() << "\n删掉list只有一个的情况： ";
                        for (; y != BitMap.end(); y++){
                            qDebug() << y.key() << " " << y.value();
                        }


                        y = BitMap.begin();
                        for (; y != BitMap.end();){
                            int ValueSum = 0;
    //                        qDebug() << "wdfqwef" ;
                            for (int k = 0; k < y.value().count(); k++){
                                QString TempStr = y.value()[k];
                                int ValueFlag = 0;
                                QMap<QString, QStringList>::iterator yy = BitMap.begin();
                                for (; yy != BitMap.end(); yy++){
                                    if (yy.value().contains(TempStr))
                                        ValueFlag++;
                                }
                                ValueSum += ValueFlag;
                            }
                            if (ValueSum == y.value().count()) FinalStringList << y.value().first(), BitMap.erase(y), y = BitMap.begin();
                            else y++;

                            qDebug() << "\n删掉list全部元素只有一个，删一组后： ";
                            y = BitMap.begin();
                            for (; y != BitMap.end(); y++){
                                qDebug() << y.key() << " " << y.value();
                            }
                        }

                        if (BitMap.count() == 0) break;
                        y = BitMap.begin();
                        for (; y != BitMap.end(); y++){
                            for (int k = 0; k < y.value().count(); k++){
                                QString TempStr = y.value()[k];
                                int ValueFlag = 0;
                                QMap<QString, QStringList>::iterator yy = BitMap.begin();
                                for (; yy != BitMap.end(); yy++){
                                    if (yy.value().contains(TempStr))
                                        ValueFlag++;
                                }
                                if (ValueFlag == 1){
                                    y.value().removeAt(k--);
                                }
                            }
                        }
                        qDebug() << "\n合并单个后： ";
                        y = BitMap.begin();
                        for (; y != BitMap.end(); y++){
                            qDebug() << y.key() << " " << y.value();
                        }
                        qDebug() << "\n";

                        y = BitMap.begin();
                        if (BitMap.count() == 1 && y.value().count() == 0) break;
    //                    if (yyy++ == 5) break;
                    }
//                    listWidget1->clear();
//                    lineEdit1->clear();
                    QString CharList = "F" + QString('1' + p) + " = ";
                    for (int u = 0; u < FinalStringList.count(); u++){
                        qDebug() << "FinalStringList " << FinalStringList[u];
//                        listWidget1->addItem(FinalStringList[u]);
                        int CharFlag = 0, BoolValueFlag = 0;
                        for (int l = 0; l < FinalStringList[u].count(); l++){//这个循环将FinalStringList里面的化简好的最小项翻译成字母字符串
                            if (FinalStringList[u][l] == "0")
                                CharList.append((u == 0 ? "" : (CharFlag++ == 0 ? " + " : "")) + QString('A' + l) + "'");
                            if (FinalStringList[u][l] == "1")
                                CharList.append((u == 0 ? "" : (CharFlag++ == 0 ? " + " : "")) + QString('A' + l));
                            if (FinalStringList[u][l] == "-")
                                BoolValueFlag++;
                            qDebug() << CharList;
                        }
                        if (BoolValueFlag == FinalStringList[u].count()){
                            CharList = "F" + QString('1' + p) + " = 1";
                            break;
                        }
                    }
                    QLineEdit *lineEdit2 = new QLineEdit(widget5);
                    LineList[p]->clear();
                    LineList.replace(p, lineEdit2);
                    lineEdit2->setGeometry(20, 130 + 20 * p, 400, 20);
                    lineEdit2->setEnabled(false);//禁止编辑
                    lineEdit2->setAttribute(Qt::WA_InputMethodEnabled, false); //屏蔽输入法的QLineEdit上调用
                    lineEdit2->setStyleSheet("background:transparent; border-width: 0; border-style: outset; font-family: Consolas; font-size: 17px; color: rgb(24,26,27);");
    //                FinalText->setText(CharList);
                    lineEdit2->insert(CharList);
                }
            }
    });

    QVBoxLayout *verticalLayout = new QVBoxLayout();
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    verticalLayout->addWidget(TableWidget);
    widget3->setLayout(verticalLayout);//垂直布局
    QFont font = TableWidget->horizontalHeader()->font();
    font.setBold(true);
    TableWidget->setShowGrid(false);                  //隐藏表格线
    TableWidget->resizeRowsToContents();              //行和列的大小设为与内容相匹配
    TableWidget->resizeColumnsToContents();
    TableWidget->setFocusPolicy(Qt::NoFocus);         //取消选中虚线
    TableWidget->setFrameShape(QFrame::NoFrame);      //设置无边框
    TableWidget->horizontalHeader()->setFont(font);   //设置表头字体加粗
    TableWidget->verticalHeader()->setVisible(false); //隐藏列表头
    TableWidget->verticalHeader()->setSectionsClickable(false);                 //设置表头字体加粗
    TableWidget->horizontalHeader()->setSectionsClickable(false);               //水平方向的头不可点击
    TableWidget->horizontalHeader()->setHighlightSections(false);               //点击表时不对表头行光亮（获取焦点）
    TableWidget->horizontalHeader()->setFocusPolicy(Qt::NoFocus);               //设置表头不可选
    TableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);            //去掉水平滚动条
    TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);            //不允许编辑
    TableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //自适应
    TableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应
    TableWidget->setStyleSheet(QString("QTableWidget QHeaderView::section{background:rgb(223,221,219);font-weight:bold; border:none; height:35px; color:black;} QTableWidget::item:selected { background-color: rgb(201,202,216) }"));//改变选中颜色 表头颜色 没有凸起


    char a = 'A', nnum = '1';
    QStringList character;
    for (int i = 0; i < SB1->value(); i++)
        character << QString(a + i);
    for (int i = 0; i < SB2->value(); i++)
        character << "F" + QString(nnum + i);
    TableWidget->setColumnCount(SB1->value() + SB2->value());
    TableWidget->setHorizontalHeaderLabels(character);
    TableWidget->setRowCount(qPow(2, SB1->value()));

    QList<QString> sexList;
    for (int i = 0; i < qPow(2, SB1->value()); i++){
        QString strr = "";
        for (int j = SB1->value() - 1; j >= 0; j--){
            if (i & (1 << j))
                strr += "1";
            else
                strr += "0";
        }
        sexList << strr;
    }
    int RowsCount = TableWidget->rowCount();
    int ColumnCount = TableWidget->columnCount();
    for (int i = 0; i < RowsCount; i++){
        for (int j = 0; j < ColumnCount; j++){
            if (j < SB1->value())
                TableWidget->setItem(i, j, new QTableWidgetItem(QString(sexList[i][j])));
            else
                TableWidget->setItem(i, j, new QTableWidgetItem("0"));
//                TableWidget->setItem(i, j, new QTableWidgetItem("X"));
            TableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            if (i % 2 != 0)
                TableWidget->item(i,j)->setBackground(QColor(240,240,240));
        }
    }

//    QListWidget *listWidget1 = new QListWidget(widget1);
//    listWidget1->setGeometry(20, 10, 100, 100);
//    QLineEdit *lineEdit1 = new QLineEdit(widget5);
//    lineEdit1->setGeometry(20, 130, 100, 20);
//    lineEdit1->setClearButtonEnabled(1);//设置删除清空按钮
//    lineEdit1->setAttribute(Qt::WA_InputMethodEnabled, false); //屏蔽输入法的QLineEdit上调用
//    QPushButton * pushButton1 = new QPushButton("Add",widget1);
//    pushButton1->setGeometry(20,160,190,30); //从屏幕上（10，45）位置开始（即为最左上角的点），显示一个190*30的界面（宽190，高30）
//    connect(pushButton1, &QPushButton::clicked, [=](){
//        listWidget1->addItem(lineEdit1->text());
//        InputStr = lineEdit1->text();
//        //        InputEvent();
//        lineEdit1->clear();
//    });
//    connect(listWidget1, &QListWidget::itemClicked, [=](){
//        listWidget1->takeItem(listWidget1->currentRow());
//    });


//    connect(pushButton1, &QPushButton::clicked, this, &MainWindow::InputEvent);

//    QListWidget *listWidget2 = new QListWidget(widget2);
//    listWidget2->setGeometry(20, 10, 100, 100);
//    QLineEdit *lineEdit2 = new QLineEdit(widget2);
//    lineEdit2->setGeometry(20, 130, 100, 20);
//    lineEdit2->setClearButtonEnabled(1);
//    lineEdit2->setAttribute(Qt::WA_InputMethodEnabled, false); //屏蔽输入法的QLineEdit上调用
//    QPushButton * pushButton2 = new QPushButton("Add",widget2);
//    pushButton2->setGeometry(20,160,190,30); //从屏幕上（10，45）位置开始（即为最左上角的点），显示一个190*30的界面（宽190，高30）
//    connect(pushButton2, &QPushButton::clicked, [=](){
//        listWidget2->addItem(lineEdit2->text());
//        InputStr = lineEdit2->text();
//        InputEvent();
//        lineEdit2->clear();
//    });
//    connect(listWidget2, &QListWidget::itemClicked, [=](){
//        listWidget2->takeItem(listWidget2->currentRow());//获取当前鼠标所选行,并删除
//    });

    m_bPressed = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setAreaMovable(const QRect rt)
{
    if(m_areaMovable != rt)
    {
        m_areaMovable = rt;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    //鼠标左键
    if(e->button() == Qt::LeftButton)
    {
        m_ptPress = e->pos();
        m_bPressed = m_areaMovable.contains(m_ptPress);
        setAreaMovable(this->rect());
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(m_bPressed)
    {
        move(pos() + e->pos() - m_ptPress);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    m_bPressed = false;
}


int MainWindow::getXORresult(QString &str1, QString &str2, QStringList &nowList)//判断是否可以合并，注意这里是引用，因为我要修改传过来的nowlist
{
    int sum = 0;//sum表示两个字符串一共有几位不一样
    QByteArray bs1 = str1.toLatin1(); //字符串转QByteArray
    QByteArray bs2 = str2.toLatin1(); //这样的转换让我们可以一位一位的比较二进制
    QString str3 = str1;//不能把修改后的str1传到nowlist里面，我们要保证原来的字符串不受影响
    int size = bs1.size(), flag = -1;
    for(int i = 0; i < size; i++){
        if (int(bs1[i] ^ bs2[i]) == 1)
            flag = i;//flag记录哪一位不一样，如果两个字符串只有一位不一样，那就刚好是我们要换的位置
        sum += bs1[i] ^ bs2[i];//异或运算，如果不一样结果为1，一样结果为0，最后的结果就是一共有几位不一样
    }
    if (sum == 1 && flag >= 0) {//如果只有一位不一样，并且flag大于=零，等于零就是第一位不一样
        str3.replace(flag, 1, "-");//把不一样的哪一位换成-
        nowList << str3;//并且把换好的字符串放到nowlist里面
    }
    return sum;//返回一共有多少位不一样
}

int MainWindow::BitList_can_merge(QStringList BitList){//判断这个序列是否可以合并
    QStringList nowList;//这个是没有作用的，因为我要用getXORresult只需要返回值，不需要存到nowlist里面，所以这个声明一个没用的nowlist放在这里
    for(int i = 0; i < BitList.count(); i++){//判断能不能合并就是判断序列里面有没有只有一位不一样的字符串，比如0100，0101就是可以合并，-011，-010，也是可以合并
        for(int j = 0; j < BitList.count(); j++){
            if (getXORresult(BitList[i], BitList[j], nowList) == 1) return 1;
        }
    }
    return 0;
}

void MainWindow::keyPressEvent(QKeyEvent *e)//用键盘控制滑块运动
{
   switch (e->key())
   {
       case Qt::Key_W : SB1->setValue(SB1->value() + 1); break;
       case Qt::Key_S : SB1->setValue(SB1->value() - 1); break;
       case Qt::Key_A : SB2->setValue(SB2->value() - 1); break;
       case Qt::Key_D : SB2->setValue(SB2->value() + 1); break;
   }
}
