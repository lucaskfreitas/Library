import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import org.database 1.0

Item {
    RecordDb {
        id: record
    }

    Rectangle {
        id: mainRectangle
        color: "#ccbae7"
        anchors.fill: parent

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 30

            RowLayout {
                spacing: 10

                Text {
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
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
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Autor"
                }

                CustomTextField {
                    Layout.fillWidth: true
                    placeholderText: "Insira o autor (SOBRENOME, Nome) - separar com ponto e vírgula caso houver mais do que um"
                }
            }

            RowLayout {
                spacing: 10

                Text {
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Título"
                }

                CustomTextField {
                    id: edTitle
                    Layout.fillWidth: true
                    placeholderText: "Insira o título completo"
                    onTextChanged: record.title = edTitle.text
                }
            }

            RowLayout {
                spacing: 10

                Text {
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Cidade"
                }

                CustomTextField {
                    Layout.fillWidth: true
                    placeholderText: "Insira a cidade da editora ou instituição"
                }
            }

            RowLayout {
                spacing: 10

                Text {
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Editora"
                }

                CustomTextField {
                    Layout.fillWidth: true
                    placeholderText: "Insira a editora ou instituição - separar com ponto e vírgula caso houver mais do que uma"
                }
            }

            RowLayout {
                spacing: 10

                Text {
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Data"
                }

                CustomTextField {
                    id: edDay
                    Layout.preferredWidth: 40
                    validator: IntValidator{}
                    maximumLength: 2
                    onTextChanged: record.day = edDay.text
                }

                CustomTextField {
                    id: edMonth
                    Layout.preferredWidth: 40
                    validator: IntValidator{}
                    maximumLength: 2
                    onTextChanged: record.month = edMonth.text
                }

                CustomTextField {
                    id: edYear
                    Layout.preferredWidth: 60
                    validator: IntValidator{}
                    maximumLength: 4
                    onTextChanged: record.year = edYear.text
                }

                Item {
                    Layout.fillWidth: true
                }

                Text {
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Nº de páginas"
                }

                CustomTextField {
                    id: edNumPages
                    Layout.preferredWidth: edNumber.width
                    validator: IntValidator{}
                    placeholderText: "Insira o número total de páginas"
                    onTextChanged: record.numPages = edNumPages.text
                }
            }

            RowLayout {
                spacing: 10

                Text {
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Volume"

                }

                CustomTextField {
                    id: edVolume
                    Layout.fillWidth: true
                    placeholderText: "Insira o volume (para publicações periódicas)"
                    onTextChanged: record.volume = edVolume.text
                }

                Text {
                    Layout.leftMargin: 50
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Número"
                }

                CustomTextField {
                    id: edNumber
                    Layout.fillWidth: true
                    validator: IntValidator{}
                    placeholderText: "Insira o número (para publicações periódicas)"
                    onTextChanged: record.number = edNumber.text
                }
            }

            RowLayout {
                spacing: 10

                Text {
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Coleção ou série"
                }

                CustomTextField {
                    Layout.fillWidth: true
                    placeholderText: "Insira o título da coleção ou série, se for o caso"
                }
            }

            RowLayout {
                spacing: 10

                Text {
                    id: txtReferenceNumber
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: 120
                    font: styles.mainFont
                    text: "Número de chamada"
                }

                CustomTextField {
                    id: edReferenceNumber
                    Layout.fillWidth: true
                    placeholderText: "Insira o número de chamada (para catálogo sistemático)"
                    onTextChanged: record.referenceNumber = edReferenceNumber.text
                }
            }

            RowLayout {
                spacing: 10

                Text {
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Assuntos"
                }

                CustomTextField {
                    Layout.fillWidth: true
                    placeholderText: "Insira os assuntos, separados por ponto e vírgula"
                }
            }

            RowLayout {
                spacing: 10

                Text {
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Língua"
                }

                ComboBox {
                    Layout.preferredWidth: edVolume.width
                    model: [ "Português", "Inglês", "Espanhol", "Francês", "Outros" ]
                }

                Text {
                    Layout.leftMargin: 50
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Exemplares"
                }

                CustomTextField {
                    id: edCopies
                    Layout.fillWidth: true
                    validator: IntValidator{}
                    placeholderText: "Insira o número de exemplares"
                    onTextChanged: record.copies = edCopies.text
                }
            }

            RowLayout {
                spacing: 10

                Text {
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: txtReferenceNumber.width
                    font: styles.mainFont
                    text: "Observação"
                }

                CustomTextField {
                    id: edObs
                    Layout.fillWidth: true
                    placeholderText: "Insira uma observação"
                    onTextChanged: record.obs = edObs.text
                }
            }

            RowLayout {
                spacing: 10

                CheckBox {
                    id: ckBorrowedItem
                    Layout.preferredWidth: txtReferenceNumber.width
                    text: "Emprestado"
                    onToggled: {
                        if (!ckBorrowedItem.checked)
                            edBorrowedToWhom.text = ""
                        record.borrowed = ckBorrowedItem.checked
                    }
                }

                CustomTextField {
                    id: edBorrowedToWhom
                    visible: ckBorrowedItem.checked
                    Layout.fillWidth: true
                    placeholderText: "Para quem?"
                    onFocusChanged: record.borrowedTo = edBorrowedToWhom.text
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
                    onClicked: record.save()
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
