import QtQuick 2.0

import "constants.js" as C

Rectangle {
    id: button;

    property double buttonWidth: 100;
    property double buttonHeight: 100;
    property color buttonColor: C.color_button;
    property color buttonHoverColor: C.color_button_hover;
    property double buttonFontSize: 22;
    property alias text: buttonText.text;
    property string iconSource: "";
    property string iconSourceHover: "";

    width: buttonWidth;
    height: buttonHeight;
    color: buttonMouseArea.containsMouse ? buttonHoverColor : buttonColor;

    signal clicked();

    MouseArea {
        id: buttonMouseArea;
        anchors.fill: parent;
        hoverEnabled: true;
        cursorShape: Qt.PointingHandCursor;

        onClicked: {
            button.clicked();
        }
    }

    Image {
        anchors.fill: parent;
        anchors.margins: button.buttonWidth < button.buttonHeight ? button.buttonWidth / 10 : button.buttonHeight / 10;
        fillMode: Image.PreserveAspectFit;
        horizontalAlignment: Image.AlignHCenter;
        verticalAlignment: Image.AlignVCenter;
        source: buttonMouseArea.containsMouse ? button.iconSourceHover : button.iconSource;
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
