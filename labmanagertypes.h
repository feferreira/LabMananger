#ifndef LABMANAGERTYPES_H
#define LABMANAGERTYPES_H
#include<QString>

typedef struct supplierModel{
    QString name;
    QString website;
    QString address;
    QString phone;
    QString email;
}SUPPLIER_MODEL;

typedef struct componentModel{
    QString description;
    QString localization;
    QString type;
    int quantity;
    double price;
    QString partNumberMFR;
    QString partNumberSupplier;
    QString supplier;
    QString dataSheet;
    QString QrCode;
}COMPONENT_MODEL;

#endif // LABMANAGERTYPES_H
