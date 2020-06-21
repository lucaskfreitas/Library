import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

Rectangle {
    color: "#a877bf"
    Layout.preferredWidth: 270
    Layout.fillHeight: true

    ColumnLayout {
        id: barraLateral
        anchors.fill: parent
        anchors.margins: 30
        spacing: 20

        Image {
            id: imgLogo
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop
            Layout.bottomMargin: 20

            source: "images/home-button.jpg"
            sourceSize.width: imgLogo.width
            fillMode: Image.PreserveAspectFit

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: contentFrame.currentIndex = 0
            }
        }

        Button {
            id: btCriarRegistro
            Layout.alignment: Qt.AlignCenter
            Layout.preferredHeight: 50
            Layout.fillWidth: true
            text: qsTr("Criar novo registro")
            font: styles.buttonFont
            onClicked: contentFrame.currentIndex = 2
        }

        Button {
            id: btRelatorios
            Layout.alignment: Qt.AlignCenter
            Layout.preferredHeight: 50
            Layout.fillWidth: true
            text: qsTr("Relatórios")
            font: styles.buttonFont
            onClicked: contentFrame.currentIndex = 3
        }

        Item {
            Layout.fillHeight: true
        }
    }
}
