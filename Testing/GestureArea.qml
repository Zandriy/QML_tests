import QtQuick 2.0

MultiPointTouchArea {
    anchors.fill: parent

    minimumTouchPoints: 1
    maximumTouchPoints: 5
    touchPoints: [
        TouchPoint { id: touch0 },
        TouchPoint { id: touch1 },
        TouchPoint { id: touch2 },
        TouchPoint { id: touch3 },
        TouchPoint { id: touch4 }
    ]

     onPressed: ponts_log("onPressed")
     onReleased: ponts_log("onReleased")

     function ponts_log(setName){
         console.log(setName);
         console.log("touch0 = " + touch0.x + ", " + touch0.y);
         console.log("touch1 = " + touch1.x + ", " + touch1.y);
         console.log("touch2 = " + touch2.x + ", " + touch2.y);
         console.log("touch3 = " + touch3.x + ", " + touch3.y);
         console.log("touch4 = " + touch4.x + ", " + touch4.y);
     }
}
