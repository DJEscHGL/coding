/* Описание
    Все блоки отделяются комментарием с названием и  //// длиной в 105 символов...
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
#include "qstring.h"
#include "QMessageBox"
#include "windows.h"
#include "QGraphicsDropShadowEffect"

double first_num, memorynumb;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->pushButton_plusmin, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->pushButton_min, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->pushButton_multi, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->pushButton_sqr, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_divbyone, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_pinum, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->btn_minimize, &QToolButton::clicked, this, &QWidget::showMinimized);
    connect(ui->btn_close, &QToolButton::clicked, this, &QWidget::close);

    ui->pushButton_div->setCheckable(true);
    ui->pushButton_min->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_multi->setCheckable(true);
    ui->btn_hide->setCheckable(true);
    ui->history->selectAll();
    ui->history->setAlignment(Qt::AlignRight);

    this->setMouseTracking(true);
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->extended_op->hide();

    // Тень для всего окна /////////////////////////////////////////////////////////////////////////////
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(15);
    shadowEffect->setOffset(3);
    ui->centralWidget->setGraphicsEffect(shadowEffect);
    ////////////////////////////////////////////////////////////////////////////////////////////////////
}

MainWindow::~MainWindow()
{
    delete ui;

}
// Метод ввода /////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::numbers()
{
    QPushButton *button = (QPushButton *)sender();
    QString input_str;
    double input_num;

    if(ui->screen->text().contains(".") && button->text() == "0")
    {
        input_str = ui->screen->text() + button->text();
    } else
    {
        input_num = (ui->screen->text() + button->text()).toDouble();
        input_str = QString::number(input_num, 'g', 15);
    }
    /* max_length for screen
     * ui->screen(if(toscreen().length() > 15)
    {
        screen.setText(screen.text().left(15));
    })*/

    ui->screen->setText(input_str);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->screen->text().contains('.')))
        ui->screen->setText(ui->screen->text() + '.');
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
// Все операции ////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    QString input_str;
    double input_num;

    if(button->text() == "+/-")
    {
        input_num = (ui->screen->text()).toDouble();
        input_num = input_num * -1;
        input_str = QString::number(input_num, 'g', 15);

        ui->screen->setText(input_str);
    } else if (button->text() == "%")
    {
        input_num = (ui->screen->text()).toDouble();
        input_num = input_num * 0.01;
        input_str = QString::number(input_num, 'g', 15);

        ui->screen->setText(input_str);
    } else if (button->text() == "x²") {
        input_num = (ui->screen->text()).toDouble();
        input_str = QString::number(input_num, 'g', 15);
        ui->history->append("sqr(" + input_str + ") =\n");
        input_num = input_num * input_num;
        input_str = QString::number(input_num, 'g', 15);

        ui->history->append(input_str + "\n");
        ui->screen->setText(input_str);
    } else if (button->text() == "√") {
        input_num = (ui->screen->text()).toDouble();
        input_str = QString::number(input_num, 'g', 15);
        ui->history->append("sqrt(" + input_str + ") =\n");
        input_num = sqrt(input_num);
        input_str = QString::number(input_num, 'g', 15);

        ui->history->append(input_str + "\n");
        ui->screen->setText(input_str);
    } else if (button->text() == "1/X") {
        input_num = (ui->screen->text()).toDouble();
        input_str = QString::number(input_num, 'g', 15);
        ui->history->append("1 / " + input_str + " =\n");
        input_num = 1 / input_num;
        input_str = QString::number(input_num, 'g', 15);

        ui->history->append(input_str + "\n");
        ui->screen->setText(input_str);
    } else if (button->text() == "π") {
        input_num = (ui->screen->text()).toDouble();
        input_num = 3.14159265358979323;
        input_str = QString::number(input_num, 'g', 15);

        ui->screen->setText(input_str);
    }
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_min->setChecked(false);
    ui->pushButton_div->setChecked(false);
    ui->pushButton_multi->setChecked(false);

    ui->screen->setText("0");
}

void MainWindow::on_pushButton_equall_clicked()
{
    double screen_num, second_num;
    QString input_str, input_str2, input_str1;

    second_num = ui->screen->text().toDouble();
    input_str2 = QString::number(second_num, 'g', 15);
    input_str1 = QString::number(first_num, 'g', 15);

    if(ui->pushButton_plus->isChecked())
    {
        screen_num = first_num + second_num;
        input_str = QString::number(screen_num, 'g', 15);

        ui->history->append(input_str1 + " + " + input_str2 + " =\n" + input_str + "\n");
        ui->screen->setText(input_str);
        ui->pushButton_plus->setChecked(false);
    } else if(ui->pushButton_min->isChecked())
    {
        screen_num = first_num - second_num;
        input_str = QString::number(screen_num, 'g', 15);

        ui->history->append(input_str1 + " - " + input_str2 + " =\n" + input_str + "\n");
        ui->screen->setText(input_str);
        ui->pushButton_min->setChecked(false);
    } else if(ui->pushButton_div->isChecked())
    {
        if (second_num == 0.0)
        {
            ui->screen->setText("Cannnot divide by zero");
        } else
        {
            screen_num = first_num / second_num;
            input_str = QString::number(screen_num, 'g', 15);

            ui->history->append(input_str1 + " / " + input_str2 + " =\n" + input_str + "\n");
            ui->screen->setText(input_str);
        }
        ui->pushButton_div->setChecked(false);
    } else if(ui->pushButton_multi->isChecked())
    {
        screen_num = first_num * second_num;
        input_str = QString::number(screen_num, 'g', 15);

        ui->history->append(input_str1 + " * " + input_str2 + " =\n" + input_str + "\n");
        ui->screen->setText(input_str);
        ui->pushButton_multi->setChecked(false);
    }
}

void MainWindow::math()
{
    QPushButton *button = (QPushButton *)sender();
    first_num = ui->screen->text().toDouble();
    ui->screen->setText("");
    button->setChecked(true);
}

// This for extmath... e. g. sin, cos and etc.
/*void MainWindow::extmath()
{

}*/

void MainWindow::on_history_clear_clicked()
{
    ui->history->clear();
    ui->history->selectAll();
    ui->history->setAlignment(Qt::AlignRight);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
// Может что-то будет для функции о разработчике ///////////////////////////////////////////////////////
void MainWindow::on_pushButton_about_clicked()
{
    QMessageBox::about(this, "About Us", "Maintainer: DJEsc\nDesigner: Alex6446\nVersion 3.6");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
// Управление окном  ///////////////////////////////////////////////////////////////////////////////////
QPoint MainWindow::previousPosition() const
{
    return m_previousPosition;
}

void MainWindow::setPreviousPosition(QPoint previousPosition)
{
    if (m_previousPosition == previousPosition)
        return;

    m_previousPosition = previousPosition;
    emit previousPositionChanged(previousPosition);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    switch (m_leftMouseButtonPressed) {
    case Move: {
            auto dx = event->x() - m_previousPosition.x();
            auto dy = event->y() - m_previousPosition.y();
            setGeometry(x() + dx, y() + dy, width(), height());
        }
        break;
    case None: {
            checkResizableField(event);
        }
        break;
    }
    return QWidget::mouseMoveEvent(event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton ) {
        m_leftMouseButtonPressed = checkResizableField(event);
        setPreviousPosition(event->pos());
    }
    return QWidget::mousePressEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_leftMouseButtonPressed = None;
    }
    return QWidget::mouseReleaseEvent(event);
}

MainWindow::MouseType MainWindow::checkResizableField(QMouseEvent *event)
{
    QPointF position = event->screenPos();
    qreal x = this->x();
    qreal y = this->y();
    qreal width = this->width();
    qreal height = this->height();
    QRectF rectInterface(x, y, width - 50, height - 486);
    if (rectInterface.contains(position)){
            setCursor(QCursor());
            return Move;
    } else {
        setCursor(QCursor());
        return None;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
// Кнопки расширенного функционала /////////////////////////////////////////////////////////////////////
void MainWindow::on_btn_hide_clicked()
{
    if(ui->btn_hide->isChecked()) {
        ui->extended_op->show();
    } else {
        ui->extended_op->hide();
        ui->btn_hide->setChecked(false);
    }
}

void MainWindow::on_btn_gparhopen_clicked()
{
    graphwin = new graph(this);
    graphwin->show();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
// Память //////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_btn_mr_clicked()
{
    QString mem;
    mem = QString::number(memorynumb, 'g', 15);
    ui->screen->setText(mem);
}

void MainWindow::on_btn_mcl_clicked()
{
    memorynumb = 0;
}

void MainWindow::on_btn_mpl_clicked()
{
    double num;
    num = (ui->screen->text()).toDouble();
    memorynumb += num;
}

void MainWindow::on_btn_mmin_clicked()
{
    double num;
    num = (ui->screen->text()).toDouble();
    memorynumb -= num;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
