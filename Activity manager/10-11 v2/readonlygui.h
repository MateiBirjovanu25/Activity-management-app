#pragma once
#include <qwidget.h>
#include "service.h"
#include <qpainter.h>
#include "observer.h"
class ReadOnlyGui : public QWidget, public Observer
{
public:
	ReadOnlyGui(ServActiv& serv) : serv{ serv } { serv.addObserver(this); }
	void paintEvent(QPaintEvent* ev) override
	{
		QPainter p{this};
		for (int i = 0;i < serv.getList().size();i++)
		{
			p.drawRect(80*i, 200, 80, 80);
		}
	}
	void update() override;
private:
	ServActiv& serv;
};

