import QtQuick 2.12
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2
//import API.FileProcessor 1.0

Page {
    id: secpage
    width: mainwindow.width
    height: mainwindow.height
    property bool processing: false

    RowLayout {
        id: titles

//        anchors.top: toolbar.bottom
//        anchors.left: parent.left

        width: parent.width
        height: 60
//        anchors.leftMargin: 30

        Text {
            text: "监听端口"
            font.bold: Font.Bold
            font.pixelSize: 15
            Layout.preferredWidth: 12
            color: "#424242"

        }
        Text {
            text: "ipv4"
            font.bold: Font.Bold
            font.pixelSize: 15
            Layout.preferredWidth: 9
            color: "#424242"

        }
        Text {
            text: "下游服务器"
            font.bold: Font.Bold
            font.pixelSize: 15
            Layout.preferredWidth: 12
            color: "#424242"

        }
        Text {
            text: "ipv4"
            font.bold: Font.Bold
            font.pixelSize: 15
            Layout.preferredWidth: 9
            color: "#424242"

        }
    }

    Rectangle {
        id: titlesline
        anchors.top: titles.bottom
        x: 8
        width: parent.width - 16
        height: 2
        color: "#EEEEEE"
//        opacity: 0.9
    }

    Rectangle {
        id: filelistbackground
        width: parent.width
        anchors.top: titlesline.bottom
        anchors.topMargin: 5
        height: parent.height - titlesline.y
        color: "#FAFAFA"
        FileView { id: filelist }
    }
}
