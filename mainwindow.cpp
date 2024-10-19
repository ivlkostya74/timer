#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(new QTimer(this))
{
    ui->setupUi(this);

    // Подключаем таймер к функции обновления дисплея
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDisplay);

    // Изначально кнопка кругов неактивна
    ui->lapButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Старт/Стоп кнопка
void MainWindow::on_startStopButton_clicked()
{
    if (stopwatch.isRunning()) {
        // Останавливаем секундомер
        stopwatch.stop();
        timer->stop();
        ui->startStopButton->setText("Старт");
        ui->lapButton->setEnabled(false);  // Отключаем кнопку кругов
    } else {
        // Запускаем секундомер
        stopwatch.start();
        timer->start(100); // Обновляем каждую 0.1 сек
        ui->startStopButton->setText("Стоп");
        ui->lapButton->setEnabled(true);   // Включаем кнопку кругов
    }
}

// Кнопка "Круг"
void MainWindow::on_lapButton_clicked()
{
    int lapNumber = stopwatch.lap();
    QString lapText = QString("Круг %1, время: %2 сек").arg(lapNumber).arg(stopwatch.lastLapTime());
    ui->textBrowser->append(lapText); // Добавляем информацию о круге
}

// Кнопка "Очистить"
void MainWindow::on_clearButton_clicked()
{
    // Сбрасываем состояние секундомера
    stopwatch.reset();

    // Сбрасываем отображаемое время на 0
    ui->timeLabel2->setText("0.0");

    // Очищаем текстовый браузер (список кругов)
    ui->textBrowser->clear();

    // Отключаем кнопку для записи кругов
    ui->lapButton->setEnabled(false);

    // Возвращаем кнопку "Старт/Стоп" в начальное состояние "Старт"
    ui->startStopButton->setText("Старт");

    // Останавливаем таймер
    timer->stop();
}

// Обновление дисплея времени
void MainWindow::updateDisplay()
{
    // Обновляем метку времени
    ui->timeLabel2->setText(QString::number(stopwatch.elapsedTime(), 'f', 1));
}
