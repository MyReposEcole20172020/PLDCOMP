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
	folderO=str(root)+"/results/"+str(filename)
	obj0=subprocess.Popen(["make", "FrontEnd","folderC="+str(root),"file="+str(filename),"folderO="+str(folderO),"folderOutput=null"],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,
universal_newlines=True)
	error0=obj0.communicate()[0]	
	obj1=subprocess.Popen(["make","FrontEndAS","file="+str(filename),"folderO="+str(folderO)],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,universal_newlines=True)
	fileO=str(root)+"/results/"+str(filename)+"/"+str(filename)+".o"
	fileOut=str(root)+"/results/"+str(filename)+"/"+str(filename)+".out"
	obj2=subprocess.Popen(["gcc", "-w", str(fileO),"-o",str(fileOut)],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,universal_newlines=True)
	if not(str(error0)==""):	
		print(error0)	
	return error0
listFile=[]
listResult=[]
listError=[]
for root,dirs,files in os.walk("./tests/testsFrontEnd",topdown=False):
	for name in sorted(files):
		if name[-2:] == '.c':
			l=len(name)
			file=name[0:l-2]
			error=execution(file,root)
			listFile.append(file)
			if not (error==""):
			
			#if("err" in error.lower()):
				listResult.append("failed")
				listError.append(error)
			else:
				listResult.append("success")
				listError.append("")
		else:
			pass
tab=printDict(listFile,listResult,listError)
writeIn("./testFrontEnd.html",tab)		
