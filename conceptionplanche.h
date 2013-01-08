#ifndef CONCEPTIONPLANCHE_H
#define CONCEPTIONPLANCHE_H

#include <QFrame>
#include <QDebug>
#include <QTimer>
#include <QFileDialog>
#include <QApplication>

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "clicableqgraphicsview.h"



#define TAILLE_VISAGE   34
#define OFFSETHAUTEUR   -3     //TAILLE_VISAGE-OFFSETHAUTEUR < 45       On décale vers le haut le cadre du visage pour prendre en compte les cheuveux

#define TAILLE_MIN_VISAGE   32
#define TAILLE_MAX_VISAGE   36

using namespace std;
using namespace cv;

namespace Ui {
class ConceptionPlanche;
}

class ConceptionPlanche : public QFrame
{
    Q_OBJECT
    
public:
    explicit ConceptionPlanche(Mat image, Rect visage, QWidget *parent = 0);
    ~ConceptionPlanche();


private slots:
    void actualiser(void);

    
    void on_boutonSauvegarder_clicked();

signals:
    void finit(void);

private:
    Ui::ConceptionPlanche *ui;




    ClicableQGraphicsView *photo;
    Mat image;
    Mat imageSortie;
    Rect visage;
};

#endif // CONCEPTIONPLANCHE_H