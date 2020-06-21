import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

Item {
    Styles {
        id: styles
    }

    Rectangle {
        id: mainRectangle
        color: "#ccbae7"
        anchors.fill: parent

        Rectangle {
            id: marginRectangle
            color: "transparent"

            anchors.fill: parent
            anchors.margins: 30

            ColumnLayout {
                anchors.fill: parent

                RowLayout {
                    spacing: 10

                    Text {
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Tipo"
                    }

                    ComboBox {
                        Layout.fillWidth: true
                        model: [ "Livro autoral", "Livro organizado", "Revista", "Anais de evento", "Catálogo", "Dicionário", "Quadrinhos", "Monografia", "Dissertação", "Tese", "Atlas", "Outro" ]
                    }
                }

                RowLayout {
                    spacing: 10

                    Text {
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Autor"
                    }

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: "Insira o autor (SOBRENOME, Nome) - separar com ponto e vírgula caso houver mais do que um"
                    }
                }

                RowLayout {
                    spacing: 10

                    Text {
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Título"
                    }

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: "Insira o título completo"
                    }
                }

                RowLayout {
                    spacing: 10

                    Text {
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Cidade"
                    }

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: "Insira a cidade da editora ou instituição"
                    }
                }

                RowLayout {
                    spacing: 10

                    Text {
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Editora"
                    }

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: "Insira a editora ou instituição - separar com ponto e vírgula caso houver mais do que uma"
                    }
                }

                RowLayout {
                    spacing: 10

                    Text {
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Data"
                    }

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: "Insira a data de publicação"
                        inputMask: "99/99/9999;_"
                    }

                    Text {
                        Layout.leftMargin: 50
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Nº de páginas"
                    }

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: "Insira o número total de páginas"
                    }
                }

                RowLayout {
                    spacing: 10

                    Text {
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Volume"
                    }

                    TextField {
                        id: txVolume
                        Layout.fillWidth: true
                        placeholderText: "Insira o volume (para publicações periódicas)"
                    }

                    Text {
                        Layout.leftMargin: 50
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Número"
                    }

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: "Insira o número (para publicações periódicas)"
                    }
                }

                RowLayout {
                    spacing: 10

                    Text {
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Coleção ou série"
                    }

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: "Insira o título da coleção ou série, se for o caso"
                    }
                }

                RowLayout {
                    spacing: 10

                    Text {
                        id: txNumeroChamada
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: 120
                        font: styles.mainFont
                        text: "Número de chamada"
                    }

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: "Insira o número de chamada (para catálogo sistemático)"
                    }
                }

                RowLayout {
                    spacing: 10

                    Text {
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Assuntos"
                    }

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: "Insira os assuntos, separados por ponto e vírgula"
                    }
                }

                RowLayout {
                    spacing: 10

                    Text {
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Língua"
                    }

                    ComboBox {
                        Layout.preferredWidth: txVolume.width
                        model: [ "Português", "Inglês", "Espanhol", "Francês", "Outros" ]
                    }

                    Text {
                        Layout.leftMargin: 50
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Exemplares"
                    }

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: "Insira o número de exemplares"
                    }
                }

                RowLayout {
                    spacing: 10

                    Text {
                        verticalAlignment: Text.AlignVCenter
                        Layout.preferredWidth: txNumeroChamada.width
                        font: styles.mainFont
                        text: "Observação"
                    }

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: "Insira uma observação"
                    }
                }

                RowLayout {
                    spacing: 10

                    CheckBox {
                        id: ckItemEmprestado
                        Layout.preferredWidth: txNumeroChamada.width
                        text: "Emprestado"
                    }

                    TextField {
                        id: edEmprestadoParaQuem
                        visible: ckItemEmprestado.checked
                        Layout.fillWidth: true
                        placeholderText: "Para quem?"
                    }
                }

                RowLayout {
                    spacing: 10

                    Item {
                        Layout.fillWidth: true
                    }

                    Button {
                        Layout.preferredWidth: 70
                        text: "Salvar"
                    }

                    Button {
                        Layout.preferredWidth: 70
                        text: "Cancelar"
                    }

                    Item {
                        Layout.fillWidth: true
                    }
                }
            }
        }
    }
}