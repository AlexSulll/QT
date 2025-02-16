#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QMovie>
#include <QVBoxLayout>
#include <QWidget>
int main(int argc, char *argv[]) {
 QApplication a(argc, argv);
 QWidget window;
 window.setWindowTitle("Лаба 0");
 QPushButton button("MB FUCK U?");
 QLabel gifLabel;
 gifLabel.setAlignment(Qt::AlignCenter);
 QObject::connect(&button, &QPushButton::clicked, [&]() {
    QMovie *movie = new QMovie("C:\\Users\\Acer\\Downloads\\qqqq.gif");
    gifLabel.setMovie(movie);
    movie->start();
 });
 QVBoxLayout *layout = new QVBoxLayout;
 layout->addWidget(&button);
 layout->addWidget(&gifLabel);
 window.setLayout(layout);
 window.show();
 return a.exec();
}
