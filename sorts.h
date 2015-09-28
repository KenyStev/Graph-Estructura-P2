#ifndef SORTS_H
#define SORTS_H

#include <QMainWindow>
#include <QTime>

namespace Ui {
class Sorts;
}

class Sorts : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sorts(QWidget *parent = 0);
    ~Sorts();

    void gen_random();
    void swap(int *m, int *n);
    void quicksort(int *arr, int izq, int der);
    void heapsort(int *arr, int N);
    void binsort(int *arr, int n);
    void bubbleSort(int *arr, int n);
    void mergeSort(int *arr, int l, int r);
    void merge(int *arr, int l, int m, int r);
    void siftDown(int *arr, int k, int N);

private slots:
    void on_btnRandom_clicked();

    void on_btnQuick_clicked();

    void on_btnMerge_clicked();

    void on_btnBin_clicked();

    void on_btnHeap_clicked();

    void on_btnBubble_clicked();

private:
    Ui::Sorts *ui;

    int size=100000;
    int max=500;
    int *arr_rand,*arr_quick,*arr_merge,*arr_heap,*arr_bin,*arr_bubble;
};

#endif // SORTS_H
