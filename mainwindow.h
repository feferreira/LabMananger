#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <array>

class QWidget;
class QTreeWidgetItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void validUser(QString user);

private slots:



    void on_actionRegisterSupplier_triggered();

    void on_actionRegisterPart_triggered();

    void on_actionExit_triggered();

private:
    enum class widgetId{
        SUPPLIER_VIEW,
        PART_VIEW,
        NULL_WIDGET
    };
    widgetId currentWidget{widgetId::NULL_WIDGET};
    std::array<QWidget *, 2> widgetsViews;
    void createChildWidgets();
    void hideAllChildWidgets();
    void hideLastChildWidget();
    void showChildWidget(widgetId id);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
