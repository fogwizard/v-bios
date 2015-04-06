#!/usr/bin/env python
import pygtk,time,os,threading,struct
import gtk,sys,gtk.glade

class Job:
	def __init(self):pass
	def writeln(self,fd,str):
			fd.write(str);
			fd.write('\n');
	def parse_file(self,nPath,fname,file_append,dep):
		fd   =open(nPath+'/'+fname,'r');
		lines=fd.readlines();
		for line in lines:
			deal=line[0:9]
			if '/include/'==deal:
				deal= line.split('"')	
				file_append.append(deal[1]);
		fd.close();
		str=''
		for j in range(dep):
			str=str+'++';
		for i in file_append:
			print str,i;
	def CreateTree(self):
		nPath=os.getcwd()
		if 2!=len(sys.argv):
			print "input file name please"
			return;
		pass
		FileName1=[];
		FileName2=[];
		FileName3=[];
		FileName4=[];
		FileName5=[];
		FileName6=[];
		FileName7=[];
		FileName8=[];
		FileName9=[];		
		self.parse_file(nPath,sys.argv[1],FileName1,0);
		for f in FileName1:
			self.parse_file(nPath,f,FileName2,1);
		for f in FileName2:
			self.parse_file(nPath,f,FileName3,2);
		for f in FileName3:
			self.parse_file(nPath,f,FileName4,3);
		for f in FileName4:
			self.parse_file(nPath,f,FileName5,4);
		for f in FileName5:
			self.parse_file(nPath,f,FileName6,5);
		for f in FileName6:
			self.parse_file(nPath,f,FileName7,6);
		for f in FileName7:
			self.parse_file(nPath,f,FileName8,7);
		for f in FileName8:
			self.parse_file(nPath,f,FileName9,8);
if __name__ == '__main__':
	AppHandle=Job()
	AppHandle.CreateTree()

