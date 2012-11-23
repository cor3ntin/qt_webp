#include "webphandler.h"
#include "webp/decode.h"
#include <QImage>
#include <QDebug>

WebPHandler::WebPHandler()
{
}

bool WebPHandler::canRead () const{
    return true;
}
bool WebPHandler::read ( QImage * image ){
    if(!canRead()) {
        return false;
    }
    QByteArray data = device()->readAll();
    int width = 0, height =0;
    uint8_t* out = WebPDecodeRGBA((uint8_t*)(data.constData()), data.size(), &width, &height);
    qDebug() << width << height;
    
    QImage result(width, height, QImage::Format_ARGB32);
    int i = 0;
    for (qint32 y = 0; y < height; ++y) {
        QRgb* line = (QRgb*)result.scanLine(y);
        for (qint32 x = 0; x < width; ++x){
            line[x] = qRgba(out[i], out[i+1], out[i+2], out[i+3]);
            i+=4;
        }
    }
    
    *image = result;
    return true;
}
