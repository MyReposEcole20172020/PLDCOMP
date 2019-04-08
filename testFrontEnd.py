import os
import subprocess
def generate_tr(filename,result,error):
	if result=="failed":
		return'<tr><td>%s</td><td style="color:red">%s</td><td style="color:red">%s</td></tr>'%(filename,result,error)
	return'<tr><td>%s</td><td style="color:green">%s</td><td style="color:green">%s</td></tr>'%(filename,result,error)
def printDict(list1,list2,list3):
	tab='<table border="1">'
	tab=tab+'<tr><th>File</th><th>Result</th><th>Error</th><tr>'
	length=len(list1)
	i=0
	while i<length:
		tab=tab+generate_tr(list1[i],list2[i],list3[i])
		i+=1
	tab=tab+'</table>'
	return tab
def writeIn(filename,contents):
	f=open(filename,"w+")
	f.write(str(contents))
	f.close()
	pass
def execution(filename,root):
	os.system("make testsFrontEnd folderC="+str(root)+" file="+str(filename))
	obj=subprocess.Popen(["gcc", "-w", str(root)+"/results/"+str(filename)+"/"+str(filename)+".o","-o",str(root)+"/results/"+str(filename)+"/"+str(filename)+".out"],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,universal_newlines=True)
	out_error_list=obj.communicate()[0]
	return out_error_list
listFile=[]
listResult=[]
listError=[]
for root,dirs,files in os.walk("./tests/testsFrontEnd",topdown=False):
	for name in sorted(files):
		if name[-2:] == '.c':
			l=len(name)
			file=name[0:l-2]
			print(file)
			out_error_list=execution(file,root)
			listFile.append(file)
			if(len(out_error_list)!=0):
				listResult.append("failed")
			else:
				listResult.append("success")
			listError.append(out_error_list)
			#os.system("make testsFrontEndClean file="+str(file))
		else:
			pass
tab=printDict(listFile,listResult,listError)
writeIn("./testFrontEnd.html",tab)		
