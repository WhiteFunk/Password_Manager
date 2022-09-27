/******************************************************************************************/
/*                                                                                        */
/*    Password local storage/manager                                                      */
/*                                                                                        */
/*    ----------------------------------------------------------                          */
/*                                                                                        */
/*                                                                                        */
/*    This program is free software: you can redistribute it and/or modify                */
/*    it under the terms of the GNU General Public License as published by                */
/*    the Free Software Foundation, either version 3 of the License, or                   */
/*    (at your option) any later version.                                                 */
/*                                                                                        */
/*                                                                                        */
/*                                                                                        */
/*    Contact:   odinets.ilya.careers@gmail.com                                           */
/*               www.linkedin.com/in/ilya-odinets-238ba124a                               */
/*                                                                                        */
/*                                                                                        */
/******************************************************************************************/


#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
