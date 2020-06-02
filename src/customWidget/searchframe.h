﻿#ifndef SEARCHFRAME_H
#define SEARCHFRAME_H

#include <QFrame>

class QPropertyAnimation;

namespace Ui {
class SearchFrame;
}

class SearchFrame : public QFrame
{
    Q_OBJECT

public:
    explicit SearchFrame(QWidget *parent = nullptr);
    ~SearchFrame() Q_DECL_OVERRIDE ;

private slots:
    void on_OpenBtn_clicked();

    void on_CloseBtn_clicked();

signals:
    void finished();
    void callTextSearch(QString,    // 搜索文本
                        bool,       // 搜索方向;true:向前;false:向后
                        bool);      // 是否区分大小写
    void callTextDisplace(QString,  // 搜索文本
                          QString,  // 替换文本
                          bool);    // 模式;true:替换全部;false:替换

private:
    Ui::SearchFrame *ui;

    bool isOpen=false;      // 是否展开
    QPropertyAnimation *animation=nullptr;

    inline void initUI();
    inline void initSignalSlots();

    inline void startAnimation();
    inline void endAnimation();

    void showEvent(QShowEvent *event)   Q_DECL_OVERRIDE;
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
};

#endif // SEARCHFRAME_H