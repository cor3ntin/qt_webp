#include <QImageIOPlugin>
#include "webphandler.h"

class WebpPlugin : public QImageIOPlugin
{
public:
    explicit WebpPlugin(QObject *parent = 0);
    Capabilities capabilities ( QIODevice * device, const QByteArray & format ) const;
    QImageIOHandler * create ( QIODevice * device, const QByteArray & format = QByteArray() ) const;
    QStringList keys () const;
};

WebpPlugin::WebpPlugin(QObject *parent) :
    QImageIOPlugin(parent)
{
}

WebpPlugin::Capabilities WebpPlugin::capabilities ( QIODevice * device, const QByteArray & format ) const{
    if(format == "webp"){
        return Capabilities(CanRead);
    }
    return Capabilities();
    
}
QImageIOHandler * WebpPlugin::create( QIODevice * device, const QByteArray & format) const{
    QImageIOHandler *handler = new WebPHandler;
    handler->setDevice(device);
    handler->setFormat(format);
    return handler;
}
QStringList WebpPlugin::keys () const{
    return QStringList() << QLatin1String("webp");
}


Q_EXPORT_STATIC_PLUGIN(WebpPlugin)
Q_EXPORT_PLUGIN2(webp, WebpPlugin)
