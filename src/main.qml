/**
 * @file     main.qml
 * @encoding UTF-8
 * @date     18.4.18
 * @author   Jiří Čechák <xcecha04@stud.fit.vutbr.cz>
 */

import QtQuick 2.0
import QtQuick.Window 2.2
import cz.vutbr.fit.team22 1.0

import "constants.js" as C

Window {
    property string colorBackground: C.color_background;
    property string colorDisplay: C.color_display;
    property string colorDisplayBorder: C.color_display_border;
    property string colorDisplayText: C.color_display_text;
    property string colorButton: C.color_button;
    property string colorNumberButton: C.color_number_button;
    property string colorOperationButton: C.color_operation_button;
    property string spacingSize: C.spacing_size;

    visible: true
    id: window
    minimumWidth: 420
    minimumHeight: 420
    title: "Kalkulačka"

    ListModel {
        id: buttonsRowList1;

        ListElement { value: "H"; label: ""; buttonType: "normal"; iconSource: "help1.png"; iconSourceHover: "help2.png"; }
        ListElement { value: "BS"; label: ""; buttonType: "normal"; iconSource: "backspace1.png"; iconSourceHover: "backspace2.png"; }
        ListElement { value: "C"; label: "C"; buttonType: "normal"; iconSource: ""; iconSourceHover: ""; }
        ListElement { value: "i"; label: "i"; buttonType: "operation"; iconSource: ""; iconSourceHover: ""; }
        ListElement { value: "/"; label: "÷"; buttonType: "operation"; iconSource: ""; iconSourceHover: ""; }
    }

    ListModel {
        id: buttonsRowList2;

        ListElement { value: "%"; label: "%"; buttonType: "operation"; }
        ListElement { value: "7"; label: "7"; buttonType: "number"; }
        ListElement { value: "8"; label: "8"; buttonType: "number"; }
        ListElement { value: "9"; label: "9"; buttonType: "number"; }
        ListElement { value: "*"; label: "*"; buttonType: "operation"; }
    }

    ListModel {
        id: buttonsRowList3;

        ListElement { value: "!"; label: "!"; buttonType: "operation"; }
        ListElement { value: "4"; label: "4"; buttonType: "number"; }
        ListElement { value: "5"; label: "5"; buttonType: "number"; }
        ListElement { value: "6"; label: "6"; buttonType: "number"; }
        ListElement { value: "-"; label: "-"; buttonType: "operation"; }
    }

    ListModel {
        id: buttonsRowList4;

        ListElement { value: "ROOT"; label: "√"; buttonType: "operation"; }
        ListElement { value: "1"; label: "1"; buttonType: "number"; }
        ListElement { value: "2"; label: "2"; buttonType: "number"; }
        ListElement { value: "3"; label: "3"; buttonType: "number"; }
        ListElement { value: "+"; label: "+"; buttonType: "operation"; }
    }

    ListModel {
        id: buttonsRowList5;

        ListElement { value: "^"; label: "xʸ"; buttonType: "operation"; }
        ListElement { value: "NEG"; label: "±"; buttonType: "operation"; }
        ListElement { value: "0"; label: "0"; buttonType: "number"; }
        ListElement { value: "."; label: "."; buttonType: "operation"; }
        ListElement { value: "="; label: "="; buttonType: "operation";}
    }

    Rectangle {
        anchors.fill: parent;
        color: window.colorBackground;

        Rectangle {
            anchors.fill: parent;
            anchors.margins: window.spacingSize;
            color: window.colorBackground;

            Column {
                id: column;
                anchors.fill: parent;
                spacing: window.spacingSize;

                Rectangle {
                    id: display;
                    width: parent.width;
                    height: parent.height / 3 - column.spacing;
                    color: window.colorDisplay;
                    border.color: window.colorDisplayBorder;
                    border.width: window.spacingSize / 2;

                    Column {
                        anchors.fill: parent;
                        anchors.margins: window.spacingSize;

                        Rectangle {
                            width: parent.width;
                            height: 5 * (parent.height / 7);
                            color: display.color;

                            Text {
                                id: resultText;
                                anchors.fill: parent;
                                horizontalAlignment: TextInput.AlignRight;
                                verticalAlignment: TextInput.AlignVCenter;
                                font.pointSize: parent.height;
                                minimumPointSize: 8;
                                color: window.colorDisplayText;
                                fontSizeMode: Text.Fit;
                                clip: true;
                                text: signalManager.getResult();
                            }
                        }

                        Rectangle {
                            width: parent.width;
                            height: 2 * (parent.height / 7);
                            color: display.color;

                            Text {
                                id: equationText;
                                anchors.fill: parent;
                                horizontalAlignment: TextInput.AlignRight;
                                verticalAlignment: TextInput.AlignVCenter;
                                font.pointSize: parent.height * 0.7;
                                color: window.colorDisplayText;
                                clip: true;
                                text: signalManager.getEquation();
                            }
                        }
                    }
                }

                Column {
                    width: parent.width;
                    height: 2 * (parent.height / 3);
                    spacing: window.spacingSize;

                    Row {
                        id: buttonsRow1;
                        width: parent.width;
                        height: parent.height / 5 - 4 * window.spacingSize / 5;
                        spacing: window.spacingSize;

                        Repeater {
                            model: buttonsRowList1;

                            delegate: Button {
                                onClicked: {
                                    signalManager.onButtonClick(model.value);
                                    equationText.text = signalManager.getEquation();
                                    resultText.text = signalManager.getResult();
                                }
                                text: model.label;
                                buttonWidth: buttonsRow1.width / 5 - 4 * window.spacingSize / 5;
                                buttonHeight: buttonsRow1.height;
                                iconSource: model.iconSource;
                                iconSourceHover: model.iconSourceHover;
                                buttonColor: model.buttonType === "number" ? window.colorNumberButton : model.buttonType === "operation" ? window.colorOperationButton : window.colorButton;
                            }
                        }
                    }

                    Row {
                        id: buttonsRow2;
                        width: parent.width;
                        height: parent.height / 5 - 4 * window.spacingSize / 5;
                        spacing: window.spacingSize;

                        Repeater {
                            model: buttonsRowList2;

                            delegate: Button {
                                onClicked: {
                                    signalManager.onButtonClick(model.value);
                                    equationText.text = signalManager.getEquation();
                                    resultText.text = signalManager.getResult();
                                }
                                text: model.label;
                                buttonWidth: buttonsRow2.width / 5 - 4 * window.spacingSize / 5;
                                buttonHeight: buttonsRow2.height;
                                buttonColor: model.buttonType === "number" ? window.colorNumberButton : model.buttonType === "operation" ? window.colorOperationButton : window.colorButton;
                            }
                        }
                    }

                    Row {
                        id: buttonsRow3;
                        width: parent.width;
                        height: parent.height / 5 - 4 * window.spacingSize / 5;
                        spacing: window.spacingSize;

                        Repeater {
                            model: buttonsRowList3;

                            delegate: Button {
                                onClicked: {
                                    signalManager.onButtonClick(model.value);
                                    equationText.text = signalManager.getEquation();
                                    resultText.text = signalManager.getResult();
                                }
                                text: model.label;
                                buttonWidth: buttonsRow3.width / 5 - 4 * window.spacingSize / 5;
                                buttonHeight: buttonsRow3.height;
                                buttonColor: model.buttonType === "number" ? window.colorNumberButton : model.buttonType === "operation" ? window.colorOperationButton : window.colorButton;
                            }
                        }
                    }

                    Row {
                        id: buttonsRow4;
                        width: parent.width;
                        height: parent.height / 5 - 4 * window.spacingSize / 5;
                        spacing: window.spacingSize;

                        Repeater {
                            model: buttonsRowList4;

                            delegate: Button {
                                onClicked: {
                                    signalManager.onButtonClick(model.value);
                                    equationText.text = signalManager.getEquation();
                                    resultText.text = signalManager.getResult();
                                }
                                text: model.label;
                                buttonWidth: buttonsRow4.width / 5 - 4 * window.spacingSize / 5;
                                buttonHeight: buttonsRow4.height;
                                buttonColor: model.buttonType === "number" ? window.colorNumberButton : model.buttonType === "operation" ? window.colorOperationButton : window.colorButton;
                            }
                        }
                    }

                    Row {
                        id: buttonsRow5;
                        width: parent.width;
                        height: parent.height / 5 - 4 * window.spacingSize / 5;
                        spacing: window.spacingSize;

                        Repeater {
                            model: buttonsRowList5;

                            delegate: Button {
                                onClicked: {
                                    signalManager.onButtonClick(model.value);
                                    equationText.text = signalManager.getEquation();
                                    resultText.text = signalManager.getResult();
                                }
                                text: model.label;
                                buttonWidth: buttonsRow5.width / 5 - 4 * window.spacingSize / 5;
                                buttonHeight: buttonsRow5.height;
                                buttonColor: model.buttonType === "number" ? window.colorNumberButton : model.buttonType === "operation" ? window.colorOperationButton : window.colorButton;
                            }
                        }
                    }
                }
            }
        }
    }

    SignalManager {
        id: signalManager;
    }
}
