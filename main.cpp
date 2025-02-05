/***********************************************************************
*
* Copyright (c) 2021-2022 Barbara Geller and Ansel Sermersheim
*
* This example is free software, released under the BSD 2-Clause license.
* For license details refer to LICENSE provided with this project.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

#include <QtCore>
#include <QtGui>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget *mainWindow = new QWidget();
   mainWindow->setMinimumSize(700, 350);

   QPushButton *pb_1 = new QPushButton();
   pb_1->setText("Show Colors");

   QPushButton *pb_2 = new QPushButton();
   pb_2->setText("Close");

   QHBoxLayout *layout = new QHBoxLayout(mainWindow);
   layout->addStretch();
   layout->addWidget(pb_1);
   layout->addSpacing(10);
   layout->addWidget(pb_2);
   layout->addStretch();

   QObject::connect(pb_1, &QPushButton::clicked, pb_1, []() { QColorDialog::getColor(Qt::green);  } );
   QObject::connect(pb_2, &QPushButton::clicked, mainWindow, &QWidget::close);

   mainWindow->show();

   return app.exec();
}

