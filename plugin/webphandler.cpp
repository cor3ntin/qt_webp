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
