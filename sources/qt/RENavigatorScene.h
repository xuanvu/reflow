#ifndef RENAVIGATORSCENE_H
#define RENAVIGATORSCENE_H

#include "RETypes.h"

#include <QGraphicsScene>

class REDocumentView;

class RENavigatorScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit RENavigatorScene(QObject *parent = 0);

    void SetDocumentView(REDocumentView*);
    const REDocumentView* DocumentView() const {return _documentView;}

    float RowHeight() const {return _rowHeight;}

    int TickAtX(float x) const;
    float XOfTick(int tick) const;
    RERect RectOfBar(int barIndex, int trackIndex) const;
    int BarIndexAtX(float x) const;
    int TrackIndexAtY(float y) const;
    int TotalWidth() const;
    int TotalHeight() const;

    void TapAtPoint(const REPoint& pt, bool extending);

    void Refresh();

protected:
    void drawBackground(QPainter * painter, const QRectF & rect);
    void drawForeground(QPainter *painter, const QRectF &rect);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    REDocumentView* _documentView;
    float _headerHeight;
    float _rowHeight;
};

#endif // RENAVIGATORSCENE_H
