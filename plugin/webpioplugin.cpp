/* Copyright (c) 2012, Corentin Jabot. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

  * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

  * Neither the name of the author nor the names of its contributors may
    be used to endorse or promote products derived from this software
    without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


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
