#ifndef WEBPHANDLER_H
#define WEBPHANDLER_H

#include <QImageIOHandler>

class WebPHandler : public QImageIOHandler
{
public:
    WebPHandler();
    bool canRead () const;
    bool read ( QImage * image );
};

#endif // WEBPHANDLER_H
