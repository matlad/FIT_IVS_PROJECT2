import QtQuick 2.0

import "constants.js" as C

Rectangle {
    id: button;

    property double buttonWidth: 100;
    property double buttonHeight: 100;
    property color buttonColor: C.color_button;
    property color buttonHoverColor: C.color_button_hover;
    property color buttonBorderColor: C.color_background;
    property double buttonFontSize: 22;
    property alias text: buttonText.text;

    width: buttonWidth;
    height: buttonHeight;
    color: buttonMouseArea.containsMouse ? buttonHoverColor : buttonColor;
    border.color: buttonBorderColor;
    border.width: 3;
    anchors.margins: 0;

    signal clicked();

    MouseArea {
        id: buttonMouseArea;
        anchors.fill: parent;
        hoverEnabled: true;

        onClicked: {
            button.clicked();
        }
    }

    Text {
        id: buttonText;
        anchors.fill: parent;
        font.bold: true;
        font.pointSize: parent.buttonFontSize;
        horizontalAlignment: Text.AlignHCenter;
        verticalAlignment: Text.AlignVCenter;
        color: buttonMouseArea.containsMouse ? C.color_button_text_hover : C.color_button_text;
    }
}
