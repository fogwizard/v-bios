adb shell sendevent /dev/input/event2 1 116 1
adb shell sendevent /dev/input/event2 0 0 0 
sleep 0.2
adb shell sendevent /dev/input/event2 1 116 0
adb shell sendevent /dev/input/event2 0 0 0