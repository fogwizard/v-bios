#!/usr/bin/env python
import pygtk,time,os,threading,struct
import gtk,sys,gtk.glade

class Job:
	def __init(self):pass
	def writeln(self,fd,str):
			fd.write(str);
			fd.write('\n');
	def CreateTree(self):
		nPath=os.getcwd()
		fd   =open(nPath+'/boot.img','rb');
		nByte=fd.read(8);
		print 'Boot  Magic ='+nByte;
		nByte=struct.unpack('I',fd.read(4));
		KSize=nByte[0];
		print 'Kernel size ='+hex(nByte[0]);
		nByte=struct.unpack('I',fd.read(4));
		print 'Kernel addr ='+hex(nByte[0]);
		nByte=struct.unpack('I',fd.read(4));
		RSize=nByte[0];
		print 'Ramdisk size='+hex(nByte[0]);
		nByte=struct.unpack('I',fd.read(4));
		print 'Ramdisk addr='+hex(nByte[0]);
		nByte=struct.unpack('I',fd.read(4));
		print 'S2ndary size='+hex(nByte[0]);
		nByte=struct.unpack('I',fd.read(4));
		print 'S2ndary addr='+hex(nByte[0]);
		nByte=struct.unpack('I',fd.read(4));
		print 'Tags addr   ='+hex(nByte[0]);
		nByte=struct.unpack('I',fd.read(4));
		print 'Page size   ='+hex(nByte[0]);
		nByte=struct.unpack('I',fd.read(4));
		print 'unused #1(zero in Android)='+hex(nByte[0]);
		nByte=struct.unpack('I',fd.read(4));
		print 'unused #2(zero in Android)='+hex(nByte[0]);  	
	 	nByte=fd.read(16);
		print 'Prouct name='+nByte;
	 	nByte=fd.read(512);
		print 'Commandline='+nByte;
	  	nByte=struct.unpack('L',fd.read(8));
		print 'Vid(Like 0)='+hex(nByte[0]);
		fd.close();
		Qc_Addr=(KSize&(~2047))+(RSize&(~2047))+2048*(1+bool(KSize&2047)+bool(KSize&2047));
		fd   =open(nPath+'/boot.img','rb');
		nByte=fd.read(Qc_Addr);
		nByte=fd.read(4);
		print 'Magic  ='+nByte;
		nByte=struct.unpack('I',fd.read(4));
		dts_version=nByte[0];
		print 'Version='+hex(nByte[0]);
		nByte=struct.unpack('I',fd.read(4));
		NumberOfEntry=nByte[0];
		print 'All dtb='+hex(nByte[0]) +','+str(nByte[0]);
		for i in range(NumberOfEntry):
			print "Entry="+str(i+1)
			nByte=struct.unpack('I',fd.read(4));
			print 'chipset id='+str(nByte[0]);
			nByte=struct.unpack('I',fd.read(4));
			print 'variant id='+str(nByte[0]);
			nByte=struct.unpack('I',fd.read(4));
			print 'subtype id='+str(nByte[0]);
			nByte=struct.unpack('I',fd.read(4));
			print 'soc rev='+str(nByte[0]);
			nByte=struct.unpack('I',fd.read(4));
			print 'offset ='+str(nByte[0]);
			nByte=struct.unpack('I',fd.read(4));
			print 'size   ='+str(nByte[0]);
			if(3==dts_version):
				fd.read(16);
		fd.close();
if __name__ == '__main__':
	AppHandle=Job()
	AppHandle.CreateTree()

