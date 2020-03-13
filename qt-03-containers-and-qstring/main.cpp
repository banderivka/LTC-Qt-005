#include <QCoreApplication>
#include <QDebug>
#include <QStack>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> names;
    names << "Mary" << "Ann" << "Charlynn" << "Marylynn" << "Margaret"
          << "Kate" << "Rose" << "Gwendolyn";


    qDebug() << "Task 1\n"
             << "using Java-style iterators print the longest name from the list"
             << "use QString::arg to output message with this name\n";
    QString longestName, shortestName = names[0];

    QListIterator<QString> javaIterator(names);
    while(javaIterator.hasNext()) {
        QString currentName = javaIterator.next();
        if (currentName.size() > longestName.size())
            longestName = currentName;
    }

    QString output("Longest name: %1");
    qDebug() << output.arg(longestName);


    qDebug() << "\n\nTask 2\n"
             << "using STL-style iterators print the shortest name from the list"
             << "use QString::prepend and append to output message with this name\n";
    for (QList<QString>::iterator i = names.begin(); i != names.end(); ++i) {
        if (i->size() < shortestName.size())
            shortestName = *i;
    }

    qDebug() << shortestName.prepend("Shortest name: ");


    qDebug() << "\n\nTask 3\n"
             << "using foreach and QStringList show all names with \"lynn\" suffix"
             << "and print it separated by ',' as one string\n";

    QStringList myStringList;
    foreach(QString name, names) {
        myStringList << name.append("lynn");
    }
    qDebug() << myStringList.join(", ");


    qDebug() << "\n\nTask 4.1\n"
             << "print all names in reverse order"
             << "Using QStack\n";
    QStack<QString> reverseStack;

    foreach(QString name, names) {
        reverseStack.push(name);
    }

    while(!reverseStack.isEmpty()) {
        qDebug() << reverseStack.pop();
    }


    qDebug() << "\n\nTask 4.2\n"
             << "print all names in reverse order"
             << "Using other QList\n";
    QList<QString> reverseList(names.rbegin(), names.rend());
    foreach(QString name, reverseList) {
        qDebug() << name;
    }


    qDebug() << "\n\nTask 4.3\n"
             << "print all names in reverse order"
             << "Without other containers\n";
    for (auto i = names.size()-1; i >=0; --i) {
        qDebug() << names[i];
    }

    //return a.exec();
}
