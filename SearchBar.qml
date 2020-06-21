import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

Rectangle {
    color: "#a877bf"
    Layout.alignment: Qt.AlignTop
    Layout.preferredHeight: 50
    Layout.fillWidth: true

    RowLayout {
        anchors.fill: parent
        spacing: 10

        Text {
            Layout.preferredHeight: 30
            Layout.leftMargin: 30
            Layout.topMargin: 15
            font: styles.mainFont
            text: "Buscar por"
        }

        ComboBox {
            id: cbSearchBy
            Layout.preferredHeight: 30
            Layout.preferredWidth: 150
            Layout.alignment: Qt.AlignCenter
            model: [ "Todos os campos", "Título", "Assunto", "Autor", "Coleção ou série" ]
        }

        CustomTextField {
            Layout.preferredHeight: 30
            Layout.fillWidth: true
            placeholderText: "Digite aqui a sua busca..."

            Keys.onEnterPressed: contentFrame.currentIndex = 1
        }

        Button {
            id: btSearch
            Layout.preferredHeight: 30
            Layout.preferredWidth: 30
            icon.source: 'qrc:///images/magnifying-glass.png'
            onClicked: contentFrame.currentIndex = 1
        }

        Button {
            id: btClear
            Layout.preferredHeight: 30
            Layout.preferredWidth: 60
            Layout.rightMargin: 30
            font: styles.mainFont
            text: qsTr("Limpar")
        }
    }
}
