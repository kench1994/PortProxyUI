import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15
import QtQuick.Dialogs 1.3
import API.Model 1.0

ApplicationWindow {
    id: mainwindow
    visible: true
    width: 640
    height: 550
    minimumWidth: 640
    minimumHeight: 350

    title: qsTr("嘿，别来无恙！")
    Model { id: mainmodel }

    Plane {
    }
}
