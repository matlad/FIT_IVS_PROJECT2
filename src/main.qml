import QtQuick 2.0
import QtQuick.Window 2.0

import "constants.js" as C

Window {
    visible: true
    id: window
    minimumWidth: 420
    minimumHeight: 420
    title: "Kalkulačka"

   ListModel {
       id: buttonsRowList1;

       ListElement { label: "i"; }
       ListElement { label: "SETT"; }
       ListElement { label: "DEL"; }
       ListElement { label: "C"; }
       ListElement { label: "÷"; }
   }

   ListModel {
       id: buttonsRowList2;

       ListElement { label: "%"; }
       ListElement { label: "7"; }
       ListElement { label: "8"; }
       ListElement { label: "9"; }
       ListElement { label: "*"; }
   }

   ListModel {
       id: buttonsRowList3;

       ListElement { label: "!"; }
       ListElement { label: "4"; }
       ListElement { label: "5"; }
       ListElement { label: "6"; }
       ListElement { label: "-"; }
   }

   ListModel {
       id: buttonsRowList4;

       ListElement { label: "√"; }
       ListElement { label: "1"; }
       ListElement { label: "2"; }
       ListElement { label: "3"; }
       ListElement { label: "+"; }
   }

   ListModel {
       id: buttonsRowList5;

       ListElement { label: "xʸ"; }
       ListElement { label: "±"; }
       ListElement { label: "0"; }
       ListElement { label: ","; }
       ListElement { label: "="; }
   }

    Column {
        width: parent.width;
        height: parent.height;

        Column {
            width: parent.width;
            height: parent.height / 3;

            Rectangle {
                width: parent.width;
                height: 3 * (parent.height / 4);
                color: C.color_background;

                Text {
                    anchors.fill: parent;
                    anchors.margins: 5;
                    horizontalAlignment: TextInput.AlignRight;
                    verticalAlignment: TextInput.AlignVCenter;
                    font.pointSize: parent.height * 0.7;
                    text: "0";
                }
            }

            Rectangle {
                width: parent.width;
                height: parent.height / 4;
                color: C.color_background;

                Text {
                    anchors.fill: parent;
                    anchors.margins: 5;
                    horizontalAlignment: TextInput.AlignRight;
                    verticalAlignment: TextInput.AlignVCenter;
                    font.pointSize: parent.height * 0.7;
                    text: "0";
                }
            }
        }

        Column {
            width: parent.width;
            height: 2 * (parent.height / 3);

            Row {
                id: buttonsRow1;
                width: parent.width;
                height: parent.height / 5;

                Repeater {
                    model: buttonsRowList1;

                    delegate: Button {
                        text: model.label;
                        buttonWidth: buttonsRow1.width / 5;
                        buttonHeight: buttonsRow1.height;
                        onClicked: {

                        }
                    }
                }
            }

            Row {
                id: buttonsRow2;
                width: parent.width;
                height: parent.height / 5;

                Repeater {
                    model: buttonsRowList2;

                    delegate: Button {
                        text: model.label;
                        buttonWidth: buttonsRow1.width / 5;
                        buttonHeight: buttonsRow1.height;
                        onClicked: {

                        }
                    }
                }
            }

            Row {
                id: buttonsRow3;
                width: parent.width;
                height: parent.height / 5;

                Repeater {
                    model: buttonsRowList3;

                    delegate: Button {
                        text: model.label;
                        buttonWidth: buttonsRow1.width / 5;
                        buttonHeight: buttonsRow1.height;
                        onClicked: {

                        }
                    }
                }
            }

            Row {
                id: buttonsRow4;
                width: parent.width;
                height: parent.height / 5;

                Repeater {
                    model: buttonsRowList4;

                    delegate: Button {
                        text: model.label;
                        buttonWidth: buttonsRow1.width / 5;
                        buttonHeight: buttonsRow1.height;
                        onClicked: {

                        }
                    }
                }
            }

            Row {
                id: buttonsRow5;
                width: parent.width;
                height: parent.height / 5;

                Repeater {
                    model: buttonsRowList5;

                    delegate: Button {
                        text: model.label;
                        buttonWidth: buttonsRow1.width / 5;
                        buttonHeight: buttonsRow1.height;
                        onClicked: {

                        }
                    }
                }
            }
        }
    }
}
