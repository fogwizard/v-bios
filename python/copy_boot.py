#!/usr/bin/env python
import pygtk,time,os,threading,struct,shutil
import gtk,sys,gtk.glade

class Job:
	def __init(self):pass
	def writeln(self,fd,str):
			fd.write(str);
			fd.write('\n');
	def CreateTree(self):
		nPath=os.getcwd()
		print nPath
		Top=nPath
		if not os.path.exists(nPath+'/out/'):
			print "please cd in project dir"
			return
			pass
		temp =nPath.split('/')
		str1=temp[-1];
		str2=str1.lower() 
		if not os.path.exists(nPath+'/out/target/product/'+str1):
			if not os.path.exists(nPath+'/out/target/product/'+str2):
				print 'palse the out dir error'
				return;
			else:
				str1=str2;
			pass
		nPath=nPath+'/out/target/product/'+str1;
		dest =nPath
		print nPath
		if not os.path.exists(nPath):
			print "out dir error..."
			return
			pass
		print "out dir exist,ok..."
		print "copy file now"
		sbl1=Top+'/Non-HLOS/boot_images/build/ms/bin/8936/sbl1.mbn';
		rpm =Top+'/Non-HLOS/rpm_proc/build/ms/bin/8936/rpm.mbn'
		tz  =Top+'/Non-HLOS/trustzone_images/build/ms/bin/MAXAANAA/tz.mbn'
		pyp =Top+'/Non-HLOS/trustzone_images/build/ms/bin/MAXAANAA/hyp.mbn'

		files=[]
		names=[]
		files.append(sbl1)
		files.append(rpm)
		files.append(tz)
		files.append(pyp)
		names.append('/sbl1.mbn')
		names.append('/rpm.mbn')
		names.append('/tz.mbn')
		names.append('/hyp.mbn')
		i=0;
		_error=0
		for f in files:
			if  os.path.exists(f):
				shutil.copyfile(f,dest+names[i])
				print 'cp ',f
				print 'to ',dest+names[i]
				if not os.path.exists(dest+names[i]):
					print "Copy Error"
			else:
				print "Coun't not find: ",f
				_error=_error+1;
			i=i+1;
			pass
		pass
		print 'copy complete,',i,' files,',_error,"Error"
if __name__ == '__main__':
	AppHandle=Job()
	AppHandle.CreateTree()

