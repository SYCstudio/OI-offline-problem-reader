#include <bits/stdc++.h>

using namespace std;

#define Exist(p) ((p)!=string::npos)

const string id_begin="<a href='statistic.php?pid=";
const string id_end="'>Statistic";
const string titlematch="<h1 style='color:#1A5CC8'>";
const string description_begin="Problem Description</div> <div class=panel_content>";
const string description_end="</div><div class=panel_bottom>";
const string input_format_begin="<div class=panel_title align=left>Input</div> <div class=panel_content>";
const string input_format_end="</div><div class=panel_bottom>";
const string output_format_begin="<div class=panel_title align=left>Output</div> <div class=panel_content>";
const string output_format_end="</div><div class=panel_bottom>";
const string sample_input_begin="<div class=panel_title align=left>Sample Input</div><div class=panel_content><pre><div style=\"font-family:Courier New,Courier,monospace;\">";
const string sample_input_end="</div></pre></div><div class=panel_bottom>";
const string sample_output_begin="<div class=panel_title align=left>Sample Output</div><div class=panel_content><pre><div style=\"font-family:Courier New,Courier,monospace;\">";
const string sample_output_end="</pre></div><div class=panel_bottom>";
const string source_begin="<div class=panel_title align=left>Source</div> <div class=panel_content>";
const string source_end="</div> <div class=panel_bottom>";
const string time_begin="Time Limit: ";
const string time_end="(Java/Others)";
const string memory_begin="Memory Limit: ";
const string memory_end="(Java/Others)";

string mstr, id, title, description, input_format, output_format;

string sample_input, sample_output, hint, time_limit, memory_limit;

int main()
{
	string pid;
	ifstream inid("input");
	inid>>pid;
	inid.close();
	
	ifstream in(("./html/HDU"+pid+".txt").c_str());
	getline(in,mstr,(char)EOF);
	in.close();
	
	size_t pos=mstr.find("\t"),pos2;
	while (pos!=string::npos)
	{
		mstr.replace(pos,1,"");
		pos=mstr.find("\t");
	}

	//if 404
	string s404="No such problem";
	pos=mstr.find(s404);
	if (pos!=string::npos)
	{
		cout<<"No such problem"<<endl;
		ofstream fileout((pid+".html").c_str());
		fileout<<"No such problem"<<endl;
		fileout.close();
		fileout.open(("./html/HDU"+pid+"-title.txt").c_str(),ios::out);
		fileout<<"(Empty)"<<endl;
		fileout.close();
		return 0;
	}
	
	//GetImageUrl
	cout<<"get images "<<flush;
	pos=mstr.find("/data/images/");
	string filename;
	while (pos!=string::npos)
	{
		cout<<"."<<flush;
		while ((mstr[pos-1]!='=')&&(mstr[pos-1]!='\'')) mstr.erase(pos-1,1),pos--;
		mstr.insert(mstr.begin()+pos,'.');pos++;//替换成本地路径
		filename.clear();pos+=13;
		while ((mstr[pos]!='>')&&(mstr[pos]!='\'')) filename.push_back(mstr[pos++]);
		//cerr<<filename<<endl;
		ofstream out("imagename");
		out<<filename<<endl;
		out.close();

		system("python3 image.py <imagename");
		pos=mstr.find("/data/images/",pos);
	}
	cout<<"down"<<endl;

	cout<<"match"<<flush;
	//Id
	pos=mstr.find(id_begin);
	if (Exist(pos))
	{
		pos+=id_begin.size();
		pos2=mstr.find(id_end,pos);
		if (Exist(pos)&&Exist(pos2)) while (pos<pos2) id.push_back(mstr[pos++]);
	}
	else pos=0;
	cout<<"."<<flush;
	//Title
	pos=mstr.find(titlematch);
	if (Exist(pos)){pos+=titlematch.size();while (mstr[pos]!='<') title.push_back(mstr[pos]), pos++;}
	else pos=0;
	cout<<"."<<flush;
	//cerr<<"Title"<<endl;
	//Description
	pos=mstr.find(description_begin);
	if (Exist(pos))
	{
		pos+=description_begin.size(),pos2=mstr.find(description_end,pos);
		if (Exist(pos)&&Exist(pos2)) while (pos<pos2) description.push_back(mstr[pos++]);
	}
	else pos=0;
	
	cout<<"."<<flush;
	//cerr<<"Description"<<endl;
	//Input_Format
	pos=mstr.find(input_format_begin,pos);
	if (Exist(pos))
	{
		pos+=input_format_begin.size();
		pos2=mstr.find(input_format_end,pos);
		if (Exist(pos)&&Exist(pos2)) while (pos<pos2) input_format.push_back(mstr[pos++]);
	}
	else pos=0;
	cout<<"."<<flush;
	//cerr<<"Inputformat"<<endl;
	//Output_Format
	pos=mstr.find(output_format_begin,pos);
	if (Exist(pos))
	{
		pos+=output_format_begin.size();
		pos2=mstr.find(output_format_end,pos);
		if (Exist(pos)&&Exist(pos2)) while (pos<pos2) output_format.push_back(mstr[pos++]);
	}
	else pos=0;
	cout<<"."<<flush;
	//cerr<<"OutputFormat"<<endl;
	//Sample_Input
	pos=mstr.find(sample_input_begin,pos);
	if (Exist(pos))
	{
		pos+=sample_input_begin.size();
		pos2=mstr.find(sample_input_end,pos);
		if (Exist(pos)&&Exist(pos2)) while (pos<pos2) sample_input.push_back(mstr[pos++]);
	}
	else pos=0;
	cout<<"."<<flush;
	//cerr<<"SampleInput"<<endl;
	//Sample_Output
	pos=mstr.find(sample_output_begin,pos);
	if (Exist(pos))
	{
		pos+=sample_output_begin.size();
		pos2=mstr.find(sample_output_end,pos);
		if (Exist(pos)&&Exist(pos2)) while (pos<pos2) sample_output.push_back(mstr[pos++]);
	}
	else pos=0;
	cout<<"."<<flush;
	//cerr<<"SampleOutput"<<endl;
	//Source
	pos=mstr.find(source_begin,pos);
	if (Exist(pos))
	{
		pos+=source_begin.size();
		pos2=mstr.find(source_end,pos);
		if (Exist(pos)&&Exist(pos2)) while (pos<pos2) hint.push_back(mstr[pos++]);
	}
	else pos=0;
	cout<<"."<<flush;
	//cerr<<"Source"<<endl;
	//TimeLimit
	pos=mstr.find(time_begin)+time_begin.size();
	if (Exist(pos)) pos2=mstr.find(time_end,pos)+time_end.size();
	if (Exist(pos)&&Exist(pos2)) while (pos<pos2) memory_limit.push_back(mstr[pos++]);
	cout<<"."<<flush;
	//cerr<<"TimeLimit"<<endl;
	//MemoryLimit
	pos=mstr.find(memory_begin)+memory_begin.size();
	if (Exist(pos)) pos2=mstr.find(memory_end,pos)+memory_end.size();
	while (pos<pos2) time_limit.push_back(mstr[pos++]);
	cout<<"down"<<endl;
	//cerr<<"MemoryLimit"<<endl;
	
	ofstream out((pid+".html").c_str());
	out << "<html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"../Semantic/semantic.min.css\"><script src=\"../Semantic/jquery.min.js\" type=\"text/javascript\"></script><script src=\"../Semantic/semantic.min.js\" type=\"text/javascript\"></script><title>" << title << "</title></head><body><div class=\"ui main container\"><div class=\"ui center aligned grid\"><div class=\"row\"><h1 class=\"ui header\">HDU" << id << ". " << title << "</h1></div><div class=\"row\" style=\"margin-top: -15px\"><span class=\"ui label\">内存限制：" << memory_limit << "</span> <span class=\"ui label\">时间限制：" << time_limit << "</span></div></div></br><div class=\"row\"><div class=\"column\"><h4 class=\"ui top attached block header\">题目描述</h4><div class=\"ui bottom attached segment font-content\"><div style=\"position: relative; overflow: hidden;\">" << description << "</div></div></div></div><div class=\"row\"><div class=\"column\"><h4 class=\"ui top attached block header\">输入格式</h4><div class=\"ui bottom attached segment font-content\"><div style=\"position: relative; overflow: hidden;\">" << input_format << "</div></div></div></div><div class=\"row\"><div class=\"column\"><h4 class=\"ui top attached block header\">输出格式</h4><div class=\"ui bottom attached segment font-content\"><div style=\"position: relative; overflow: hidden;\">" << output_format << "</div></div></div></div><div class=\"row\"><div class=\"column\"><h4 class=\"ui top attached block header\">样例</h4><div class=\"ui bottom attached segment font-content\"><div style=\"position: relative; overflow: hidden;\"><h4>样例输入</h4><div class=\"ui existing segment\"><pre style=\"margin-top:0; margin-bottom:0;\"><code class=\"lang-plain\">" << sample_input << "</code></pre></div><h4>样例输出</h4><div class=\"ui existing segment\"><pre style=\"margin-top:0; margin-bottom:0;\"><code class=\"lang-plain\">" << sample_output << "</code></pre></div></div></div></div><div class=\"row\"><div class=\"column\"><h4 class=\"ui top attached block header\">数据范围与提示</h4><div class=\"ui bottom attached segment font-content\"><div style=\"position: relative; overflow: hidden;\">" << hint << "</div></div></div></div></div></div><div class=\"ui vertical footer segment\"><div class=\"ui center aligned container\"><span style=\"color: #999;\">OI-offline-problem-reader Powered by <a href=\"http://www.sycstudio.com\">SYCstudio</a>.</span></div></div></div></body></html>";
	out.close();

	out.open(("./html/HDU"+id+"-title.txt").c_str(),ios::out);
	out<<title<<endl;
	out.close();
	return 0;
}

