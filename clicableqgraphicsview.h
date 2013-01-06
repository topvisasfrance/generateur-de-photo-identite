/**
 * \file clicableqgraphicsview.h
 * \brief Objet permetant d'afficher les images d'opencv et de récupérer les évenements de clic.
 * \author Clément.R
 * \version 0.1
 * \date 11 Juillet 2012
 *
 * Objet permetant d'afficher les images d'opencv et de récupérer les évenements de clic.
 *
 */

#ifndef CLICABLEQGRAPHICSVIEW_H
#define CLICABLEQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QObject>
#include <QGraphicsScene>
#include <QImage>
#include <QDebug>
#include <QPoint>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QGraphicsItem>
#include <QColor>
#include <QGraphicsItemGroup>

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>

#include "refait.h"


#define TAILLE_DE_LIGNE 15


/**
  * \brief Ligne de l'aide.
  * \var couleur Pointeur vers la couleur du carré que l'on veut afficher sur la ligne.
  * \var chaine Chaine de caractère du message à afficher sur la ligne.
  *
  * Il s'agit d'une ligne de l'aide. Si le pointeur couleur vaut NULL, il n'y aura pas de
  * carre affiché, seulement le text.
 */
typedef struct Aide{

    QColor *couleur;
    QString chaine;
}Aide;


class ClicableQGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    ClicableQGraphicsView(QWidget * = 0);
    ~ClicableQGraphicsView();
    void display(IplImage *src);
    void append_aide(QString msg, QColor *couleur = NULL);

public slots:
    /** \brief Setter de s'il faut conserver le ratio de l'image ou non. */
    void keep_image_ratio(bool val){ keep_ratio = val; refresh(); }
    /** \brief Setter de s'il faut activer le curseur ou non. */
    void set_cursor_activated(bool val){ cursor = val; }
    /** \brief Setter de s'il faut zoomer sur l'image ou non. */
    void set_zoom_enable(bool val){ zoom = val; }
    /** \brief Setter de s'il faut redimentionner l'image ou non. */
    void set_resize(bool val){ resize = val; }
    /** \brief Setter de s'il faut afficher l'aide ou non. */
    void set_afficher_aide(bool val){ afficher_aide = val; refresh(); }
    /** \brief Fonction permetant d'effacer l'aide. */
    void clear_aide(void){ if(aide != NULL) aide->clear(); refresh(); }

    /** \brief Getter de la position de l'image dans la fenètre. */
    QPoint get_position_image(void){ return position_image; }
    /** \brief Getter de la taille de l'image dans la fenètre. */
    CvSize get_taille_image(void){ return taille_image; }
    /** \brief Getter de la scene dans la fenètre. */
    QGraphicsScene *get_scene(void){ return scene; }
    bool get_resize(void){ return resize; }

    void refresh(void);



signals:
    void mousePressEventEvent(QMouseEvent *event);
    void mouseMoveEventEvent(QMouseEvent *event);
    void mouseReleaseEventEvent(QMouseEvent *event);
    void mouseDoubleEventEvent(QMouseEvent *event);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *);

private:
    QImage IplImage2QImage(const IplImage *iplImage);

    /** \brief Image affichée. */
    IplImage *displayed_image;
    /** \brief Image que l'on a demandé d'afficher (avant redimentionnement). */
    IplImage *source_image;
    /** \brief scene affichée. */
    QGraphicsScene *scene;
    /** \brief Position de l'image dans la fenètre. */
    QPoint position_image;
    /** \brief Taille de l'image dans la fenètre. */
    CvSize taille_image;

    /** \brief Si on doit garder le ratio de l'image ou non. */
    bool keep_ratio;
    /** \brief S'il faut afficher le curseur ou non. */
    bool cursor;
    /** \brief S'il faut zoomer sur l'image ou non. */
    bool zoom;
    /** \brief S'il faut redimentionner l'image ou non. */
    bool resize;
    /** \brief S'il faut afficher l'aide ou non. */
    bool afficher_aide;

    /** \brief Liste des différentes entrées de l'aide. */
    QList<Aide> *aide;
};

#endif // CLICABLEQGRAPHICSVIEW_H
