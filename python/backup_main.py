#!/usr/bin/env python
import pygtk,time,os,threading,commands
import gtk,sys,gtk.glade

FileName=''
FlashCommand =''         #write to the flash?
PartitionName='boot'     #what is partition?
event1=threading.Event()
event2=threading.Event()

class DeviceTree:
	def __init(self):pass
	def CreateGui(self):
		fhandle=open('./gui.dat','w');
		fhandle.close();
	def CreateDtsFile(self):
		fd=open('./DeviceTree.dts','w');
		self.writeln(fd,'&mdss_mdp {');
		self.writeln(fd,'	dsi_truly_ips3p3097_e_r63315_1080p_video: qcom,mdss_dsi_truly_ips3p3097_e_r63315_1080p_video {');
		self.writeln(fd,'		qcom,mdss-dsi-panel-name = "r63315 1080p video mode dsi panel";');
		self.writeln(fd,'		qcom,mdss-dsi-panel-controller = <&mdss_dsi0>;');
		self.writeln(fd,'		qcom,mdss-dsi-panel-type = "dsi_video_mode";');
		self.writeln(fd,'		qcom,mdss-dsi-panel-destination = "display_1";');
		self.writeln(fd,'		qcom,mdss-dsi-panel-framerate = <60>;');
		self.writeln(fd,'		qcom,mdss-dsi-virtual-channel-id = <0>;');
		self.writeln(fd,'		qcom,mdss-dsi-stream = <0>;');
		self.writeln(fd,'		qcom,mdss-dsi-panel-width = <1080>;');
		self.writeln(fd,'		qcom,mdss-dsi-panel-height = <1920>;');
		self.writeln(fd,'		qcom,mdss-dsi-h-front-porch = <90>;');
		self.writeln(fd,'		qcom,mdss-dsi-h-back-porch = <60>;');
		self.writeln(fd,'		qcom,mdss-dsi-h-pulse-width = <20>;');
		self.writeln(fd,'		qcom,mdss-dsi-h-sync-skew = <0>;');
		self.writeln(fd,'		qcom,mdss-dsi-v-back-porch = <4>;');
		self.writeln(fd,'		qcom,mdss-dsi-v-front-porch = <8>;');
		self.writeln(fd,'		qcom,mdss-dsi-v-pulse-width = <2>;');
		self.writeln(fd,'		qcom,mdss-dsi-h-left-border = <0>;');
		self.writeln(fd,'		qcom,mdss-dsi-h-right-border = <0>;');
		self.writeln(fd,'		qcom,mdss-dsi-v-top-border = <0>;');
		self.writeln(fd,'		qcom,mdss-dsi-v-bottom-border = <0>;');
		self.writeln(fd,'		qcom,mdss-dsi-bpp = <24>;');
		self.writeln(fd,'		qcom,mdss-dsi-color-order = <0>;');
		self.writeln(fd,'		qcom,mdss-dsi-underflow-color = <0xff>;');
		self.writeln(fd,'		qcom,mdss-dsi-border-color = <0>;');
		self.writeln(fd,'		qcom,cont-splash-enabled = <1>;');
		self.writeln(fd,'		qcom,mdss-dsi-pixel-packing = "tight";');
		self.writeln(fd,'		qcom,mdss-dsi-on-command = [39 01 00 00 c8 00 02 11 00');
		self.writeln(fd,'		29 01 00 00 00 00 02 B0 04');
		self.writeln(fd,'		29 01 00 00 00 00 02 D6 01');
		self.writeln(fd,'		29 01 00 00 00 00 07 B3 14 00 00 00 00 00');
		self.writeln(fd,'		29 01 00 00 00 00 03 B6 3A C3');
		self.writeln(fd,'		29 01 00 00 00 00 02 C0 00');
		self.writeln(fd,'		29 01 00 00 00 00 23 C1 84 60 10 EB FF 6F CE FF FF 17 12 58 73 AE 31 20 C6 FF FF 1F F3 FF 5F 10 10 10 10 00 62 01 22 22 00 01');
		self.writeln(fd,'		29 01 00 00 00 00 08 C2 31 F7 80 06 08 80 00');
		self.writeln(fd,'		29 01 00 00 00 00 17 C4 70 00 00 00 00 00 00 00 00 0C 06 00 00 00 00 00 00 00 00 00 0C 06');
		self.writeln(fd,'		29 01 00 00 00 00 29 C6 C8 08 67 08 67 00 00 00 00 00 00 00 00 00 00 00 00 16 18 08 C8 08 67 08 67 00 00 00 00 00 00 00 00 00 00 00 00 16 18 08');
		self.writeln(fd,'		29 01 00 00 00 00 1F C7 00 10 1F 20 2C 38 42 50 34 3C 4C 5D 68 6D 71 00 10 1F 20 2C 38 42 50 34 3C 4C 5D 68 6D 71');
		self.writeln(fd,'		29 01 00 00 00 00 14 C8 00 00 00 00 00 FC 00 00 00 00 00 FC 00 00 00 00 00 FC 00');
		self.writeln(fd,'		29 01 00 00 00 00 09 CB 31 FC 3F 8C 00 00 00 00');
		self.writeln(fd,'		29 01 00 00 00 00 02 CC 0B');
		self.writeln(fd,'		29 01 00 00 00 00 0B D0 11 81 BB 19 99 4C 19 19 0C 00');
		self.writeln(fd,'		29 01 00 00 00 00 1A D3 1B 33 BB BB B3 33 33 33 01 01 00 A0 D8 A0 0D 48 48 44 3B 22 72 07 3D BF 33');
		self.writeln(fd,'		29 01 00 00 00 00 08 D5 06 00 00 01 42 01 42');
		self.writeln(fd,'		29 01 00 00 00 00 08 D5 06 00 00 01 42 01 42');
		self.writeln(fd,'		39 01 00 00 00 00 02 51 00');
		self.writeln(fd,'		39 01 00 00 00 00 02 53 2C');
		self.writeln(fd,'		39 01 00 00 00 00 02 55 01');
		self.writeln(fd,'		39 01 00 00 00 00 02 5E 80');
		self.writeln(fd,'		39 01 00 00 00 00 02 36 C0');
		self.writeln(fd,'		39 01 00 00 c8 00 02 29 00];');
		self.writeln(fd,'		qcom,mdss-dsi-off-command = [');
		self.writeln(fd,'		39 01 00 00 00 00 02 53 00');
		self.writeln(fd,'		39 01 00 00 00 00 02 53 00');
		self.writeln(fd,'		29 01 00 00 00 00 08 D5 06 00 00 00 48 00 48');
		self.writeln(fd,'		29 01 00 00 00 00 08 D5 06 00 00 00 48 00 48');
		self.writeln(fd,'		39 01 00 00 0A 00 02 28 00');
		self.writeln(fd,'		39 01 00 00 96 00 02 10 00];');
		self.writeln(fd,'		qcom,mdss-dsi-on-command-state = "dsi_lp_mode";');
		self.writeln(fd,'		qcom,mdss-dsi-off-command-state = "dsi_lp_mode";');
		self.writeln(fd,'		qcom,mdss-dsi-h-sync-pulse = <1>;');
		self.writeln(fd,'		qcom,mdss-dsi-traffic-mode = <2>;');
		self.writeln(fd,'		qcom,mdss-dsi-lane-map = <0>;');
		self.writeln(fd,'		qcom,mdss-dsi-bllp-eof-power-mode;');
		self.writeln(fd,'		qcom,mdss-dsi-bllp-power-mode;');
		self.writeln(fd,'		qcom,mdss-dsi-lane-0-state;');
		self.writeln(fd,'		qcom,mdss-dsi-lane-1-state;');
		self.writeln(fd,'		qcom,mdss-dsi-lane-2-state;');
		self.writeln(fd,'		qcom,mdss-dsi-lane-3-state;');
		self.writeln(fd,'		qcom,mdss-dsi-panel-timings = [5F 36 24 00 66 6A 2A 3A 2D 03 04 00];');
		self.writeln(fd,'		qcom,mdss-dsi-t-clk-post = <0x1e>;');
		self.writeln(fd,'		qcom,mdss-dsi-t-clk-pre = <0x38>;');
		self.writeln(fd,'		qcom,mdss-dsi-bl-min-level = <1>;');
		self.writeln(fd,'//[SIMT-szhaojun-20140610]Update lcd max backlight level from 255 to 200');
		self.writeln(fd,'		qcom,mdss-dsi-bl-max-level = <200>;');
		self.writeln(fd,'//[SIMT-szhaojun-20140610]');
		self.writeln(fd,'		qcom,mdss-dsi-dma-trigger = <4>;');
		self.writeln(fd,'		qcom,mdss-dsi-mdp-trigger = <0>;');
		self.writeln(fd,'		qcom,mdss-dsi-bl-pmic-control-type = "bl_ctrl_dcs";');
		self.writeln(fd,'		qcom,mdss-dsi-reset-sequence = <1 20>, <0 15>, <1 20>;');
		self.writeln(fd,'	};');
		self.writeln(fd,'};');
		fd.close()
	def ExecDownload(self):
		global PartitionName,FlashCommand
		print('Waitting Download...')
		i=0;
		CommandStr='';
		output    ='';
		while 1:
			if event1.wait(0.2):
				event1.clear()
				CommandStr='echo "123456"|sudo -S env PATH=$PATH adb reboot-bootloader'
				(status,output)=commands.getstatusoutput(CommandStr) 
				UserStr=output
				CommandStr='echo "123456"|sudo -S env PATH=$PATH fastboot '+FlashCommand+' '+PartitionName+' '+FileName
				(status,output)=commands.getstatusoutput(CommandStr) 
				UserStr=UserStr+output
				if 'flash'==FlashCommand:
					CommandStr='echo "123456"|sudo -S env PATH=$PATH fastboot reboot'
					(status,output)=commands.getstatusoutput(CommandStr) 
					UserStr=UserStr+output
					pass
				self.editbuffer.set_text(UserStr)
				i=i+1;
				print('Download...'+str(i))
			if event2.wait(0.1):
				event2.clear()
				break
	def on_filechooser_file_set(self, widget, data=None):
		global FileName
		FileName=self.filechooser.get_filename()
		if os.path.isfile('./Config.ini'):
			fd=open('./Config.ini','w')
			fd.write(FileName)
			fd.close()
			self.statusbar1.push(0,FileName)
	def on_down2RAM_clicked(self, widget, data=None):
		global even1,event2 
		self.editbuffer.set_text('Reboot The Phone Now...') #reflesh the gui?
		event1.set()
		time.sleep(8)
	def on_button_clear(self, widget, data=None):
		self.editbuffer.set_text('') #reflesh the gui?
		pass
	def on_checkbutton1_toggled(self, widget, data=None):
		global PartitionName
		if widget.get_active():
			self.s2.set_active(False)
			PartitionName='aboot'
			self.label1.set_text(PartitionName)
		else:
			self.s2.set_active(True)
		pass
	def on_checkbutton2_toggled(self, widget, data=None):
		global PartitionName
		if widget.get_active():
			self.s1.set_active(False)
			PartitionName='boot'
			self.label1.set_text(PartitionName)
		else:
			self.s1.set_active(True)
		pass
	def on_checkbutton3_toggled(self, widget, data=None):
		global FlashCommand
		if widget.get_active():
			self.s4.set_active(False)
			FlashCommand=''
			self.label2.set_text('NULL')
		else:
			self.s4.set_active(True)
		pass
	def on_checkbutton4_toggled(self, widget, data=None):
		global FlashCommand
		if widget.get_active():
			self.s3.set_active(False)
			FlashCommand='flash'
			self.label2.set_text(FlashCommand)
		else:
			self.s3.set_active(True)
		pass
	def on_combobox1_changed(self, widget, data=None):
		print 'Change1'
		pass
	def on_combobox2_changed(self, widget, data=None):
		print 'Change2'
		pass
	def destroy(self, widget, data=None): 
			global even1,event2 
			if os.path.isfile('./gui.dat'):
				os.remove('./gui.dat')
			event2.set()
			gtk.main_quit()
	def writeln(self,fd,str):
			fd.write(str);
			fd.write('\n');
	def CreateTree(self):
			global FileName
			self.CreateGui();
			if os.path.isfile('./Config.ini'):
				fd=open('./Config.ini','r')
				FileName=fd.read()
				fd.close()
			else:
				FileName='/home/fog/myandroid/out/target/product/s55/boot.img'
				fd=open('./Config.ini','w')
				fd.write(FileName)
				fd.close()
			self.thread1=threading.Thread(target=self.ExecDownload)
			self.thread1.start()
			self.CreateDtsFile()
			builder=gtk.Builder();
			#builder.add_from_file('./gui.dat')
			builder.add_from_file('./gui.glade')
			self.window = builder.get_object("window1")
			self.textview = builder.get_object('textview1')
			self.filechooser = builder.get_object('filechooser')
			self.statusbar1 = builder.get_object('statusbar1')
			self.select1    = builder.get_object('combobox1')
			self.select2    = builder.get_object('combobox2')
			self.s1         = builder.get_object('checkbutton1')
			self.s2         = builder.get_object('checkbutton2')
			self.s3         = builder.get_object('checkbutton3')
			self.s4         = builder.get_object('checkbutton4')
			self.label1         = builder.get_object('label1')
			self.label2         = builder.get_object('label2')
			builder.connect_signals(self);
			self.statusbar1.get_context_id('main')
			self.statusbar1.push(0,FileName)
			self.s2.set_active(True)
			self.s3.set_active(True)
			self.editbuffer=self.textview.get_buffer()
			self.window.show_all()
			gtk.main()
if __name__ == '__main__':
	AppHandle=DeviceTree()
	AppHandle.CreateTree()

