sudo adb remount
sudo adb push /home/fog/Q39/out/target/product/q39/system/lib/libaudiopolicymanagerdefault.so /system/lib/ 
sudo adb push /home/fog/Q39/out/target/product/q39/system/lib/libaudiopolicymanager.so	     /system/lib/	
sudo adb push /home/fog/Q39/out/target/product/q39/system/lib/libaudiopolicyservice.so       /system/lib/
sudo adb reboot
