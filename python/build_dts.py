#!/usr/bin/env python
import pygtk,time,os,threading,struct
import gtk,sys,gtk.glade,shutil

class Job:
	def __init(self):pass
	def writeln(self,fd,str):
			fd.write(str);
			fd.write('\n');
	def cp2dest(self,src,dst):
		print "CP File Now ..."
		if not os.path.exists(src):
			print "Dir Not Found"
			sys.exit(1);
		if not os.path.exists(dst):
			print "Dir Not Found"
			sys.exit(1);
		os.chdir(src);
		src_file=[os.path.join(src,file) for file in os.listdir(src)]
		for i in src_file:
			shutil.copy(i,dst);
		os.chdir(dst);
		src_file=[os.path.join(src,file) for file in os.listdir(dst)]
		for i in src_file:
			lines=open(i).readlines();
			fd=open(i,'w')
			for j in lines:
				//fd.write(j.replace('#include','/include/'));
			fd.close;
		pass
	def CreateTree(self):
		nPath=os.getcwd()
		if os.path.exists(nPath+'/out'):
			pass
		else:
			os.makedirs(nPath+'/out');
		if not os.path.exists(nPath+'/qcom'):
			print "please go to dts dir!";
			exit;
		self.cp2dest(nPath+'/qcom',nPath+'/out');
	# fd   =open(nPath+'/boot.img','rb');
	# fd.close();
if __name__ == '__main__':
	AppHandle=Job()
	AppHandle.CreateTree()

