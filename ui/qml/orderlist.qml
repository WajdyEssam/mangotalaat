import QtQuick 1.0

Rectangle {
    color: "lightblue"

    ListModel {
        id: orderModel

        ListElement {
            order_id: 1
            order_name: "item_1"
            order_cost: 16
            order_category: "category_1"
        }

        ListElement {
            order_id: 2
            order_name: "item_2"
            order_cost: 8
            order_category: "category_2"
        }

        ListElement {
            order_id: 4
            order_name: "item_4"
            order_cost: 23
            order_category: "category_4"
        }

        ListElement {
            order_id: 5
            order_name: "item_5"
            order_cost: 12
            order_category: "category_5"
        }
    }

    Component {
        id: orderDelegate

        Item {

            id: orderItem
            width: 400
            height: 50

            BorderImage {
                id: name
                source: "qrc:/images/disable_button.png"
                width: 400
                height: 40
                border.left: 5; border.top: 5
                border.right: 5; border.bottom: 5
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.debug("item: " + order_id + " is clicked")
                }
            }

            Row {
                Column {
                    width: 300
                    Text { text: order_name }
                    Text { text: order_cost + " SR" }
                }
                Column {
                    width: 100
                    Image {
                        width: 32
                        height: 32
                        source: "qrc:/images/juices/" + order_category + ".png"
                    }
                }
            }
        }

    }

    ListView {
        id: orderView
        anchors.fill: parent
        anchors.margins: 10
        model: orderModel
        delegate: orderDelegate
    }
}
