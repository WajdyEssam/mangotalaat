import QtQuick 1.0

Rectangle {
    id: order_window
    //color: mycolor
    signal itemClick(string item_id)

    Image {
        id: itemImage
        source: "qrc:/images/backgrounds/bg1.png"
        anchors.fill: parent
        smooth: true;
        //fillMode: Image.PreserveAspectCrop
    }

    ListView {
        id: orderView
        anchors.fill: parent
        anchors.margins: 10
        spacing: 5
        model: ordersModel
        delegate: orderDelegate
    }

//    ListModel {
//        id: orderModel

//        ListElement {
//            order_id: 1
//            order_name: "item_1"
//            order_cost: 16
//            order_category: "category_1"
//        }

//        ListElement {
//            order_id: 2
//            order_name: "item_2"
//            order_cost: 8
//            order_category: "category_2"
//        }

//        ListElement {
//            order_id: 4
//            order_name: "item_4"
//            order_cost: 23
//            order_category: "category_4"
//        }

//        ListElement {
//            order_id: 5
//            order_name: "item_5"
//            order_cost: 12
//            order_category: "category_5"
//        }
//    }

    Component {
        id: orderDelegate

        Item {

            id: orderItem
            width: 380
            height: 50

            BorderImage {
                id: itemImage
                source: "qrc:/images/normal_button.png"
                anchors.fill: parent
                border.left: 2; border.top: 2
                border.right: 2; border.bottom: 2

                states: State {
                    name: "pressed"
                    PropertyChanges {
                        target: itemImage
                        source: "qrc:/images/pressed_button.png"
                    }
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.debug("item: " + model.modelData.orderId + " is clicked");
                    order_window.itemClick(orderIndexId);

                }
                onPressed: {
                    console.debug("item: " + model.modelData.orderId + " is pressed");
                    itemImage.state = "pressed"
                }
                onReleased: {
                    itemImage.state = ""
                }
            }

            Item {
                anchors.fill: parent
                anchors.top: parent.top
                anchors.topMargin: 10

                Image {
                    id: iconImage
                    width: 32; height: 32
                    anchors.left: parent.left
                    source: "qrc:/images/juices/category_" + model.modelData.orderCategory + ".png"
                    smooth: true
                }

                Item {
                    height: parent.height
                    width: 300
                    anchors.left: iconImage.right
                    anchors.leftMargin: 20

                    Text {
                        id: orderLabel
                        text: orderName;
                        font.bold: true;
                        font.pointSize: 14;
                    }

                    Text {
                        text: orderCost + " SR"
                        font.pointSize: 14;
                        anchors.right: parent.right
                        anchors.top: parent.top
                        anchors.topMargin: 3
                        color: "blue"
                    }

                    Text {
                        text: model.modelData.orderName + " -- " + model.modelData.orderDescription
                        anchors.top: orderLabel.bottom
                        anchors.topMargin: 2
                    }
                }
            }
        }

    }

}
