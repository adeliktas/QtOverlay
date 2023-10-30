#include "include/QtOverlay.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel window1;

    window1.setWindowTitle("Drawing example");
    //window1.setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::X11BypassWindowManagerHint);
        //window1.setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::X11BypassWindowManagerHint|Qt::Tool|Qt::WindowTransparentForInput);
    window1.setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::WindowTransparentForInput);
    window1.setAttribute(Qt::WA_ShowWithoutActivating);
    window1.setFocusPolicy(Qt::NoFocus);
    window1.setAttribute(Qt::WA_NoSystemBackground);
    window1.setAttribute(Qt::WA_TranslucentBackground);
    window1.setGeometry(0, 0, 1920, 1080);
//    window1.resize(1920, 1080);

    for(int i=0; i<50; ++i){
        QPicture pi;
        QPainter p(&pi);
        p.setRenderHint(QPainter::Antialiasing);
        p.setPen(QPen(Qt::red, 4, Qt::SolidLine, Qt::RoundCap));
        p.drawLine(0, 0, 1920, 1080);

		p.setPen(QPen(Qt::red, 0, Qt::SolidLine, Qt::RoundCap));
		QRectF rectangle(200, 150, 20.0, 30.0);
		p.drawRect(rectangle);
		QFont font=p.font();
		font.setPointSize(12);
		p.setFont(font);
		
		p.drawText(QPoint(200, 150), "One");
		
		
		p.setPen(QPen(Qt::blue, 0, Qt::SolidLine, Qt::RoundCap));
		QRectF rectangletwo(400, 300, 20.0, 30.0);
		p.drawRect(rectangletwo);
		p.drawText(QPoint(400, 300), "Two");
		
        p.end();

        window1.setPicture(pi);
        window1.show();
        //QTime dieTime= QTime::currentTime().addSecs(1);
        //while (QTime::currentTime() < dieTime)
            //QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        delay(500);
    }
    return a.exec();
}
