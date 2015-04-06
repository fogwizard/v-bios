#!/usr/bin/env python
import pygtk,time,os,threading,commands
import gtk,sys,gtk.glade

class Job:
	def __init(self):pass
	def writeln(self,fd,str):
			fd.write(str);
			fd.write('\n');
	def write_headinfo(self,fout,pnl,i):
			self.writeln(fout,'static char '+pnl+'_video_on_cmd'+str(i)+'[] = {');
			self.writeln(fout,'    0x02, 0x00, 0x29, 0xC0,');
	def write_data(self,fd,str):
		s=str.replace('\n','');
		s=s.replace(']','');
		s=s.replace(';','');
		s=s.split(' ');
		fd.write('    ');
		fd.write('0x'+s[0]+', ')
		fd.write('0x'+s[1]+', ')
		fd.write('0xFF, 0xFF,'+'\n')
		self.writeln(fd,'};');
		self.writeln(fd,'');
		pass
	def write_oncommand(self,fout,pnl,t_lstCmd2):
		i=0;
		for l in t_lstCmd2:
			self.write_headinfo(fout,pnl,i);
			self.write_data(fout,l);
			i=i+1;
	def write_pannel_info(self,fout,pnl):
		struct_list=[];
		self.writeln(fout,'/*---------------------------------------------------------------------------*/');
		self.writeln(fout,'/* HEADER files                                                              */');
		self.writeln(fout,'/*---------------------------------------------------------------------------*/');
		self.writeln(fout,'#include "panel.h"');
		self.writeln(fout,'');
		self.writeln(fout,'/*---------------------------------------------------------------------------*/');
		self.writeln(fout,'/* Panel configuration                                                       */');
		self.writeln(fout,'/*---------------------------------------------------------------------------*/');
		self.writeln(fout,'');
		struct_list.append('.panel_node_id   ='+'"qcom,mdss_dsi_'+pnl+'_video",');
		struct_list.append('.panel_controller='+'"dsi:0:",');
		struct_list.append('.panel_compatible='+'"qcom,mdss-dsi-panel",');
		struct_list.append('.panel_interface =10,');
		struct_list.append('.panel_type            =0,');
		struct_list.append('.panel_destination     ="DISPLAY_1",');
		struct_list.append('.panel_orientation     =0,');
		struct_list.append('.panel_clockrate       =0,');
		struct_list.append('.panel_framerate       =60,');
		struct_list.append('.panel_channelid       =0,');
		struct_list.append('.dsi_virtualchannel_id =0,');
		struct_list.append('.panel_broadcast_mode  =0,');
		struct_list.append('.panel_lp11_init       =0,');
		struct_list.append('.panel_init_delay      =0,');
		struct_list.append('.dsi_stream            =0,');
		struct_list.append('.interleave_mode       =0,');
		struct_list.append('.panel_bitclock_freq   =0,');
		struct_list.append('.panel_operating_mode  =0,');
		struct_list.append('.panel_with_enable_gpio=0,');
		struct_list.append('.mode_gpio_state       =0,');
		struct_list.append('.slave_panel_node_id   =0,');
		self.writeln(fout,'static struct panel_config '+pnl+'_video_panel_data = {');
		for one in struct_list:
			self.writeln(fout,one);
		self.writeln(fout,'};');
		self.writeln(fout,'');
		self.writeln(fout,'/*---------------------------------------------------------------------------*/');
		self.writeln(fout,'/* Panel resolution                                                          */');
		self.writeln(fout,'/*---------------------------------------------------------------------------*/');
		self.writeln(fout,'static struct panel_resolution '+pnl+'_video_panel_res = {');
		struct_list=[]
		struct_list.append('.panel_width   =1080,');
		struct_list.append('.panel_height  =1920,');
		struct_list.append('.hfront_porch  =32,');
		struct_list.append('.hback_porch   =32,');
		struct_list.append('.hpulse_width  =8,');
		struct_list.append('.hsync_skew    =0,');
		struct_list.append('.vfront_porch  =2,');
		struct_list.append('.vback_porch   =18,');
		struct_list.append('.vpulse_width  =2,');
		struct_list.append('.hleft_border  =0,');
		struct_list.append('.hright_border =0,');
		struct_list.append('.vtop_border   =0,');
		struct_list.append('.vbottom_border=0,');
		struct_list.append('.hactive_res   =0,');
		struct_list.append('.vactive_res   =0,');
		struct_list.append('.invert_data_polarity =0,');
		struct_list.append('.invert_vsync_polarity=0,');
		struct_list.append('.invert_hsync_polarity=0,');
		for one in struct_list:
			self.writeln(fout,one);
		self.writeln(fout,'};');
		self.writeln(fout,'');
		self.writeln(fout,'/*---------------------------------------------------------------------------*/');
		self.writeln(fout,'/* Panel Color Information                                                   */');
		self.writeln(fout,'/*---------------------------------------------------------------------------*/');
		self.writeln(fout,'static struct color_info '+pnl+'_video_color = {');
		struct_list=[];
		struct_list.append('.color_format   =24,');
		struct_list.append('.color_order    =0,');
		struct_list.append('.underflow_color=0xff,');
		struct_list.append('.border_color   =0,');
		struct_list.append('.pixel_packing  =0,');
		struct_list.append('.pixel_alignment=0,');
		for one in struct_list:
			self.writeln(fout,one);
		self.writeln(fout,'};');
		pass
	def write_oncommand_array(self,fout,pnl,n):
		i=0;
		self.writeln(fout,'static struct mipi_dsi_cmd '+pnl+'_video_on_command[] = {');
		for i in range(0,n):
			self.writeln(fout,'{ 0x8 , '+pnl+'_video_on_cmd'+str(i)+',0x00'+'},');
		self.writeln(fout,'};');
		self.writeln(fout,'');
		self.writeln(fout,'#define '+pnl.upper()+'_VIDEO_ON_COMMAND '+str(n));
		self.writeln(fout,'');
		pass
	def write_other_info(self,fout,pnl):
		struct_list=[];
		self.writeln(fout,'static struct command_state '+pnl+'_video_state = {');
		self.writeln(fout,'  0, 1');
		self.writeln(fout,'};');
		self.writeln(fout,'');
		self.writeln(fout,'static struct commandpanel_info '+pnl+'_video_command_panel = {');
		struct_list.append('.techeck_enable           =0,');
		struct_list.append('.tepin_select             =0,');
		struct_list.append('.teusing_tepin            =0,');
		struct_list.append('.autorefresh_enable       =0,');
		struct_list.append('.autorefresh_framenumdiv  =0,');
		struct_list.append('.tevsync_rdptr_irqline    =0,');
		struct_list.append('.tevsync_continue_lines   =0,');
		struct_list.append('.tevsync_startline_divisor=0,');
		struct_list.append('.tepercent_variance       =0,');
		struct_list.append('.tedcs_command            =0,');
		struct_list.append('.disable_eotafter_hsxfer  =0,');
		struct_list.append('.cmdmode_idletime         =0,');
		for one in struct_list:
			self.writeln(fout,one);
		self.writeln(fout,'};');
		self.writeln(fout,'');
		self.writeln(fout,'static struct videopanel_info '+pnl+'_video_video_panel = {');
		struct_list=[];
		struct_list.append('.hsync_pulse         =1,');
		struct_list.append('.hfp_power_mode      =0,');
		struct_list.append('.hbp_power_mode      =0,');
		struct_list.append('.hsa_power_mode      =0,');
		struct_list.append('.bllp_eof_power_mode =1,');
		struct_list.append('.bllp_power_mode     =1,');
		struct_list.append('.traffic_mode        =2,');
		struct_list.append('.dma_delayafter_vsync=0,');
		struct_list.append('.bllp_eof_power      =0x09,');
		for one in struct_list:
			self.writeln(fout,one);
		self.writeln(fout,'};');
		self.writeln(fout,'');
		self.writeln(fout,'static struct lane_configuration '+pnl+'_video_lane_config = {');
		struct_list=[];
		struct_list.append('.dsi_lanes=4,');
		struct_list.append('.dsi_lanemap=0,');
		struct_list.append('.lane0_state=1,');
		struct_list.append('.lane1_state=2,');
		struct_list.append('.lane2_state=3,');
		struct_list.append('.lane3_state=4,');
		for one in struct_list:
			self.writeln(fout,one);
		self.writeln(fout,'};');
		self.writeln(fout,'');
		self.writeln(fout,'const uint32_t '+pnl+'_video_timings[] = {');
		self.writeln(fout,'  0xf9, 0x3d, 0x34, 0x00, 0x58, 0x4d, 0x36, 0x3f, 0x53, 0x03, 0x04, 0x00');
		self.writeln(fout,'};');
		self.writeln(fout,'');
		self.writeln(fout,'static struct panel_timing '+pnl+'_video_timing_info = {');
		struct_list=[];
		struct_list.append('.dsi_mdp_trigger=0x00,');
		struct_list.append('.dsi_dma_trigger=0x04,');
		struct_list.append('.tclk_post      =0x1E,');
		struct_list.append('.tclk_pre       =0x38,');
		for one in struct_list:
			self.writeln(fout,one);
		self.writeln(fout,'};');
		self.writeln(fout,'');
		self.writeln(fout,'static struct panel_reset_sequence '+pnl+'_video_panel_reset_seq = {');
		struct_list=[];
		struct_list.append('.pin_state    ={ 1, 0, 1 },');
		struct_list.append('.sleep        ={ 20, 20, 20},');
		struct_list.append('.pin_direction=2,');
		for one in struct_list:
			self.writeln(fout,one);
		self.writeln(fout,'};');
		self.writeln(fout,'static struct backlight '+pnl+'_video_backlight = {');
		struct_list=[];
		struct_list.append('.bl_interface_type  =1,');
		struct_list.append('.bl_min_level       =1,');
		struct_list.append('.bl_max_level       =4095,');
		struct_list.append('.bl_step            =100,');
		struct_list.append('.bl_pmic_controltype=1,');
		struct_list.append('.bl_pmic_model      ="PMIC_8941",');
		for one in struct_list:
			self.writeln(fout,one);
		self.writeln(fout,'};');
		pass
	def write_ifdef(self,fout,pnl):
		self.writeln(fout,'#ifndef _PANEL_'+pnl.upper()+'_VIDEO_H_');
		self.writeln(fout,'#define _PANEL_'+pnl.upper()+'_VIDEO_H_');
	def write_endifdef(self,fout,pnl):
		self.writeln(fout,'#endif')
	def write_dts_file(self,fout,line):
		fout.write(line);
	def CreateTree(self):
		pnl='';
		for arg in sys.argv:
			if -1!=arg.find('pnl='):
				arg=arg.split('=');
				pnl=arg[-1];
			pass
		pass
		if pnl=='':
			print "Please input command like this:\n\tkernel2lk pnl=PanelName"
			exit;
		fout=open('./fout.dtsi','w');
		fsrc=open('./from.c','r');
		all_line=fsrc.readlines();
		fsrc.close()
		t_lstCmd1=[];
		t_lstCmd2=[];
		i=0;
		j=0;
		s='';
		bGet=False;
		for line in all_line:
			j=j+1;
			if -1!=line.find('qcom,mdss-dsi-on-command '): 
				bGet=True;
			pass
			if -1!=line.find('qcom,mdss-dsi-off-command '): 
				bGet=False;
			pass
			if True==bGet:
				t_lstCmd1.append(line);
			pass
		pass
		for l in t_lstCmd1:
			s=l.split(' 00 02 ');
			t_lstCmd2.append(s[-1]);
		pass
		self.write_ifdef(fout,pnl);
		self.write_pannel_info(fout,pnl);
		self.write_oncommand(fout,pnl,t_lstCmd2);
		self.write_oncommand_array(fout,pnl,len(t_lstCmd2));
		self.write_other_info(fout,pnl);
		self.write_endifdef(fout,pnl);
		fout.close();
if __name__ == '__main__':
	AppHandle=Job()
	AppHandle.CreateTree()




