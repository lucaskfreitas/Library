import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 1270
    height: 800
    title: qsTr("Biblioteca Kaminski e Freitas")

    Styles {
        id: styles
    }

    Rectangle {
        anchors.fill: parent
        color: "black"

        RowLayout {
            anchors.fill: parent
            spacing: 1

            LeftBar {
            }

            ColumnLayout {
                spacing: 1

                SearchBar {
                }

                SwipeView {
                    id: contentFrame
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Component.onCompleted: contentItem.interactive = false
                    clip: true

                    ViewHome {
                    }

                    Rectangle {
                        color: "white"

                        Text {
                            id: txtSearch
                            anchors.centerIn: parent
                            text: qsTr("RESULTADOS DA BUSCA")
                        }
                    }

                    ViewNewRecord {
                    }

                    Rectangle {
                        color: "white"

                        Text {
                            id: txtReports
                            anchors.centerIn: parent
                            text: qsTr("RELATÓRIOS")
                        }
                    }
                }
            }
        }
    }
}
