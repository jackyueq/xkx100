// majiang.c �齫

#include <ansi.h>
inherit NPC;
#define MJ_DATA "/data/mj3_data.o"
#define END 286
#define START 0
void check_flower(mapping who);
int do_play();
int do_rule();
int do_check_Mj(string datastr,string str);
int do_check_eat(string num1,string num2,string LastDump);
int delete_last_dump(string whoId);
int do_check_win(string str);
int check_hu(string strW);
int set_mjdata(object me,int *winner);
int *get_mjdata(string id);
int get_tc(mapping who);

int get_attitudes(mapping who);		//���NPC�Ĵ���̬�ȣ�ֱ�Ӿ�������ƺͺ��Ƶ�����
void dump_what( object who );		//��������ʲô�Ƶĺ�����
string filt_mj(string strW, object me);	//**********************/
int filt_hu_color(string strW, object me);	//**********************/
string find_mj(string str, string mj);	//*********/

int npc_action( object me );		//******/
int get_times( mapping who );		//ר����̨��
int get_all_temps( mapping map, string str );
int dump_samecolor( string str_out, string str_mj, object me );//����һɫ
int dump_twocolor( string str_out, string str_mj, object me, mapping );//����һɫ
int dump_pinhu( mapping who, object me, mapping);			//��ƽ��
int dump_ponpon( mapping who, object me, mapping);			//��������

mixed next_data( string str, int i, string key );	//�ҳ���ǰ������(id == str)���� i ��Data�������������(key�ؼ���)��
							//������ǿ���һ������������������������
string next_mj( string mj, int i );			//�м�next_data ��˼�뿩��

int do_pause( object me );	//����ͣ��������ҿ����Ƿ����ƣ����Ƶȡ�
int undo_pause(object me);		//***********************
int do_continue(object me);	//��ֹ��Ϸ���ܽ��У�����Ϊʲô��ʱ�����ͣ��������ԭ����������ף������Ǻ�������̫���Ե��
				//��������øú������������Խ����������ˡ�
				
varargs int do_dump(string str,object me);
varargs int do_touch(string str,object me);
varargs int wash_mj(int amount);
varargs int do_win(string str,object me);
varargs int do_gon(string str,object me);
varargs int do_pon(string str,object me);
varargs int do_eat(string str, object me);
string check_id(string str,string kind);
string do_delete_Mj(string datastr,string str,int amount);
string show_mj(string str,int flag);
string sort_data(string str);
mixed do_check_num(string str,int flag);
//��ֻ����
string MjE= "1w2w3w4w5w6w7w8w9w1t2t3t4t5t6t7t8t9t1s2s3s4s5s6s7s8s9sdfnfxfbfhzfabah1h2h3h4h5h6h7h8";
string *MjC = ({"",
	"һ��","����","����","����","����","����","����","����","����",
	"һͲ","��Ͳ","��Ͳ","��Ͳ","��Ͳ","��Ͳ","��Ͳ","��Ͳ","��Ͳ",
	"һ��","����","����","����","����","����","����","����","����",
	"����","�Ϸ�","����","����","����","�෢","�װ�",
	"����","����","����","����","��÷","����","����","����","����","||||"
});
int K, B;		//�㷬�ģ��̺�ا
string Tc = "";
//����
int Auto;
int Auto_Tin;
int Auto_Gon;
int Auto_Pon;
int Count;
int count;
int end;
int Goned;
int HU_F;
int NO_HU;
int NO_GON;
int Playing;
int Play;
int Times;
int Touched;
int NowPlayer;
string List ="";
string LookP ="";
string *NowPlayerId = ({ "xishi","chenyuanyuan","hongniangzi","" });
string *NowPlayerName = ({ "��ʩ","��ԲԲ","������","" });
string LastDumpId="";
string LastDumpName="";
string LastDump="";
 
mapping P1Data = ([
"Show": "color","Id": "xishi","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": "",
"Attitude": "common", "Hu_type": "", "3Ps": "", "3Es":"", "2Ps": "", "2Es1": "", "2Es2": "", "1s": "",	//Ϊ�����жϳ�ʲô�ƶ�����
"Pause": "", "H2Ps": "", "H2Es1": "", "H2Es2": "", "H1s": ""		//Ϊ���ж����ͳԼ��ܶ���
]);
mapping P2Data = ([
"Show": "color","Id": "chenyuanyuan","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": "",
"Attitude": "common", "Hu_type": "", "3Ps": "", "3Es":"", "2Ps": "", "2Es1": "", "2Es2": "", "1s": "",	//Ϊ�����жϳ�ʲô�ƶ�����
"Pause": "", "H2Ps": "", "H2Es1": "", "H2Es2": "", "H1s": ""		//Ϊ���ж����ͳԼ��ܶ���
]);
mapping P3Data = ([
"Show": "color","Id": "hongniangzi","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": "",
"Attitude": "common", "Hu_type": "", "3Ps": "", "3Es":"", "2Ps": "", "2Es1": "", "2Es2": "", "1s": "",	//Ϊ�����жϳ�ʲô�ƶ�����
"Pause": "", "H2Ps": "", "H2Es1": "", "H2Es2": "", "H1s": ""		//Ϊ���ж����ͳԼ��ܶ���
]);
mapping P4Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": "",
"Pause": ""
]);

//����Ϊ�˻���ս����	       

int PAUSE = 0;			//�ж��Ƿ�����ͣ״̬;PAUSE==1��ΪNPC�е���ͣ���κ���Ҷ�������continue����ȡ����PAUSE==2
				//��Ϊ��ҽе���ͣ��ֻ�и���ſ���continue������
string destop="";		//������ม�
int DELAY =2;			//NPC���ƻ���Ƶ���ʱ
string TIMES = "";		//�������������


void create()
{
	seteuid(getuid());
	set_name("СѾͷ",({"littlegirl", "girl"}));
	set_weight(1);
	set("gender", "Ů��");
	set("age", 18);
	set("long", "����һ��СѾͷ��\n");
	set("attitude", "friendly");

	set("per", 28);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);
	setup();
}
void init()
{
	add_action("do_rule","rule");
	add_action("do_play","play");
	add_action("do_addin","addin");
	add_action("do_addin","sit");
	add_action("do_addin","join");
	add_action("do_dump","dump");
	add_action("do_dump","da");
	add_action("do_eat","eat");
	add_action("do_eat","chi");
	add_action("do_pon","pon");
	add_action("do_pon","peng");
	add_action("do_gon","gon");
	add_action("do_gon","gang");
	add_action("do_win","hu");
//	add_action("do_help","help");
	add_action("do_look","look");
	add_action("do_look",".");
	add_action("do_look",".1");
	add_action("do_look",".2");
	add_action("do_look",".3");
	add_action("do_look",".4");
	add_action("do_look","..");
	add_action("do_touch","mo");
	add_action("do_touch","0");
	add_action("do_restart","restart");
	add_action("wash_mj","start");
	add_action("do_setmj","setmj");
	add_action("show_top","top");
	add_action("ch","ch");
	add_action("do_pause","pause");		//�������ͣ����
	add_action("do_continue","continue");	//�����ƾּ����������ֹ����ִ�й���ʱ�����ܼ�����   

/*East = present( "xishi" );
South = present( "chenyuanyuan" );
West = present( "hongniangzi" );*/

}
int do_addin()
{
	object me=this_player();
	if (me->query("id")==P1Data["Id"] ||  me->query("id")==P2Data["Id"] ||
		 me->query("id")==P3Data["Id"] || me->query("id")==P4Data["Id"])
	{
		if (!Playing)
			message_vision("$N��һ������Ҫ���齫������˭�ϣ�\n",me);
		else
			 message_vision("$N���Ŵ��˵����������"+chinese_number(random(12)+1)+"�ξͺá�\n",me);
		return 1;
	}
	if (Playing){
		if (random(1))
		message_vision(this_object()->name()+
		"����"+me->name()+"˵�����ƾ����ڽ������뵽�Ա���һ��...��\n",me);
		else  message_vision("$N���Ŵ��˵������ҲҪ������������ͣ�Ŀ޿�����.....��\n",me);
		return 1;
	}
	if (!P4Data["Id"] || P4Data["Id"]==""){
		 P4Data["Id"]=me->query("id");
		 message_vision("$N�������ⳡ�ƾ֡�\n",me);		 
		 NowPlayerId[3]=me->query("id");
		 NowPlayerName[3]=me->query("name");
		 Play = 4;
		 Times=0;
		 LookP+=me->name();
		 return 1;
	}else if ( P2Data["Id"]=="chenyuanyuan"){
	   P2Data["Id"]=me->query("id");
	   NowPlayerId[1]=me->query("id");
	   NowPlayerName[1]=me->query("name");
	   message_vision("$N�������ⳡ�ƾ֡�\n",me);
	   //Play++;
	   Times=0;
	   LookP+="��ǰ����"+me->name()+"��";
	   return 1;
	}else if ( P3Data["Id"]=="hongniangzi"){
		 P3Data["Id"]=me->query("id");
		 message_vision("$N�������ⳡ�ƾ֡�\n",me);
		 NowPlayerId[2]=me->query("id");
		 NowPlayerName[2]=me->query("name");
		 //Play++;
		 Times=0;
		 LookP+=me->name()+"��";
		 return 1;
	}else if ( P1Data["Id"]=="xishi"){
		 P1Data["Id"]=me->query("id");
		 message_vision("$N�������ⳡ�ƾ֡�\n",me);
		 NowPlayerId[0]=me->query("id");
		 NowPlayerName[0]=me->query("name");
		 //Play++;
		 Times=0;
		 LookP+=me->name()+"��";
		 return 1;
	}
	return notify_fail("�������㡣\n");
}
int do_dump(string str,object me)
{
	int check,i;
	int *winner=({0,0,0,0});
	string ponid;
	mapping who;
	object met;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else {
	   command("stare "+me->query("id"));
	   command("say ���ƾָ���û��ϵ��");
	   return 1;
	}
	if (!Playing){
	   command("kick "+me->query("id"));
	   command("say �ƾֻ�û��ʼ�������Ҷ���");
	   return 1;
	}
//	tell_object(me,"��˭����:"+NowPlayerId[NowPlayer]+"\n");
	tell_object(me,"��˭���ƣ�"+NowPlayerName[NowPlayer]+"\n");
	if (!str) return notify_fail("ָ�da <����>\n");
	if (me->query("id")!=NowPlayerId[NowPlayer]){
	   command("hammer "+me->query("id"));
	   command("say ��͵���ƣ����װ���");
	   return 1;
	}
	if (!Touched){
	   command("faint "+me->query("id"));
	   command("say �㻹û���ƣ�");
	   return 1;
	}
	if (Goned==5){
	   message_vision("$N˵�����˾���"+HIR+"��ܺ���"+NOR+"�������¿�ʼ start ��\n",this_object());
	   Playing=0;
	   Count++;
	   if (Play==4){
	      for (i=0;i<Play;i++){
		  met=present(NowPlayerId[i], environment(this_object()));
		  if (!met) met=find_player(NowPlayerId[i]);
		  if (!met);
		  else{
		     if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
		     winner[0]++;
		     set_mjdata(met,winner);
		  }
	      }
	   }
	   return 1;
	}
	NO_HU=0;
	HU_F=0;
	NO_GON=0;
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	check=do_check_Mj(MjE,str);
	if (check==0) return notify_fail("û��["+str+"]���ִ��롣\n");
	check=do_check_Mj(who["Mj"],str);
	if (check==0) return notify_fail("��û"+do_check_num(str,0)+"�����ơ�\n");
	tell_object(me,"��˵����"+do_check_num(str,0)+"\n");
	//tell_room(environment(this_object()),me->name()+"˵����"+do_check_num(str,0)+"\n",me);
	//tell_room(environment(this_object()),me->name()+"˵����"+do_check_num(str,0)+"\n"+show_mj(str, 6) + "\n",me);
	tell_room(environment(this_object()),me->name()+"˵����"+do_check_num(str,0)+"\n",me);
	//command("say "+me->name()+"�����һ��"+do_check_num(str,0));
	who["Mj"]=do_delete_Mj(who["Mj"],str,1);
	who["Mj"]=sort_data(who["Mj"]);		//����֮����������
	destop+=str;				//���Ƽӵ������ϣ���Ȼ��Ϊ�˼����ʲô�ƿ�
	LastDump=str;
	who["Dump"]=str+who["Dump"];
	
	tell_room(environment(this_object()),show_mj(who["Dump"]+"zz"+who["Out"]+who["OutPon"]+who["OutFlower"], 6));	//���㿴��
	LastDumpId=who["Id"];
	LastDumpName=who["Name"];
	Touched=0;
	NowPlayer++;
	NowPlayer%=Play;
	
	PAUSE = 0;
	
//	message_vision("$N˵���������ֵ�"+HIY+NowPlayerId[NowPlayer]+NOR+"���ơ�\n",this_object());û�б�Ҫ�������˿������ɣ���
	tell_object(present(NowPlayerId[NowPlayer]),name()+"����˵�������ֵ������ơ�\n");
	
	if (Auto_Tin){
	   ponid=check_id(str,"ting");
	   if (ponid!=""){
	      me=present(ponid, environment(this_object()));
	      if (!me) me=find_player(ponid);
	      if (!me) return 1;
	      return do_win(str,me);
	   }
	}
	if (Auto_Gon){
	   ponid=check_id(str,"gang");
	   if (ponid!=""){
	      me=present(ponid, environment(this_object()));
	      if (!me) me=find_player(ponid);
	      if (!me) return 1;
	      do_gon(str,me);
	   }
	}
	if (Auto_Pon){
	   ponid=check_id(str,"peng");
	   if (ponid!=""){
	      me=present(ponid, environment(this_object()));
	      if (!me) me=find_player(ponid);
	      if (!me) return 1;
	      do_pon(str,me);
	   }
	}
	if (count==(end-16-Goned)){
	   Playing=0;
	   Count++;
	   message_vision("$N˵�����˾�"+HIY+"����"+NOR+"�������¿�ʼ "+HIR+"start"+NOR+" ��\n",this_object());
	   str="��ʣ�µ���ֻ�У�"+show_mj(List[count..end],2)+"\n";
	   tell_room(environment(this_object()),str);
	   if (Play==4){
	      for (i=0;i<Play;i++){
		  met=present(NowPlayerId[i], environment(this_object()));
		  if (!met) met=find_player(NowPlayerId[i]);
		  if (!met);
		  else{
		     if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
		     winner[0]++;
		     set_mjdata(met,winner);
		  }
	      }
	   }
	   return 1;
	}
	if (Auto){
	   if (NowPlayerId[NowPlayer]==P1Data["Id"]) who=P1Data;
	   else if (NowPlayerId[NowPlayer]==P2Data["Id"]) who=P2Data;
	   else if (NowPlayerId[NowPlayer]==P3Data["Id"]) who=P3Data;
	   else if (NowPlayerId[NowPlayer]==P4Data["Id"]) who=P4Data;
	   if (who["Auto"]=="auto"){
	      me=present(NowPlayerId[NowPlayer], environment(this_object()));
	      if (!me) me=find_player(NowPlayerId[NowPlayer]);
	      if (!me) return 1;
	      do_touch("AUTO",me);
	   }
	}
	
//	if(set_eval_limit(-1) < 700000 ) reset_eval_cost();
       
	//if(npc_action(me)!=0) return 1;
	npc_action( present(NowPlayerId[NowPlayer]) );
	//else {	
	//�����һ�����Ƶ��ǵ��ԣ��Զ��������ƺ���		
	//str = me->query("id");
	//if( !userp(next_data(str, 1, "player")) ) 
		//do_touch( 0, next_data(str, 1, "player") );
	//}	
	return 1;
}
int do_eat(string str, object me)
{
	int LastDumpMan,i;
	string num1,num2;	
	mapping who, lastwho;
	if(!me) me=this_player();
 	 	
	if (!str || sscanf(str,"%s %s",num1,num2)!=2) return 0;
	if (check_id(me->query("id"),"player")!="");
	else {
	   command("stare "+me->query("id"));
	   command("say ���ƾָ���û��ϵ��");
	   return 1;
	}
	if (!Playing){
	   command("say �ƾֻ�û��ʼ��");
	   return 1;
	}
	tell_object(me,"��˭���ƣ�"+NowPlayerId[NowPlayer]+"\n");
	if (me->query("id")!=NowPlayerId[NowPlayer]){
	   command("hammer "+me->query("id"));
	   command("say ��û�ֵ��㡣");
	   return 1;
	}
	if (!LastDump || LastDump==""){
	   command("hammer "+me->query("id"));
	   command("say ���ưɡ�");
	   return 1;
	}
	if (Touched){
	   command("flop "+me->query("id"));
	   command("say ��������");
	   return 1;
	}
	if (do_check_eat(num1,num2,LastDump)==0){
	   command("flop "+me->name());
	   command("say ���۾�����ѽ������Ҳ�ܳԵ��£�");
	   return 1;
	}
	if (num1==num2){
	   command("flop "+me->name());
	   command("say ��ͬ���Ʋ��ܳԡ�");
	   return 1;
	}
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	LastDumpMan=do_check_Mj(MjE,num1);
	if (LastDumpMan==0) return notify_fail("û��["+num1+"]���ִ��롣\n");
	LastDumpMan=do_check_Mj(MjE,num2);
	if (LastDumpMan==0) return notify_fail("û��["+num2+"]���ִ��롣\n");
	LastDumpMan=do_check_Mj(who["Mj"],num1);
	if (LastDumpMan==0) return notify_fail("��û"+do_check_num(num1,0)+"�����ơ�\n");
	LastDumpMan=do_check_Mj(who["Mj"],num2);
	if (LastDumpMan==0) return notify_fail("��û"+do_check_num(num2,0)+"�����ơ�\n");
	message_vision("\n$N˵����"+do_check_num(LastDump,0)+"���ҡ�"+HIW+"���򡫡���"+NOR+"\n",me);
 	message_vision("$N�ó���һ��"+HIG+do_check_num(num1,0)+NOR+
		      "��һ��"+HIY+do_check_num(num2,0)+NOR+
		      "������"+HIR+do_check_num(LastDump,0)+NOR+"��\n",me);
	who["Out"]+=sort_data(num2+num1+LastDump);
	//who["Out"]+=LastDump;
	//who["Out"]+=num1;
	who["Mj"]=do_delete_Mj(who["Mj"],num1,1);
	who["Mj"]=do_delete_Mj(who["Mj"],num2,1);
	Touched=1;
	NO_HU=1;
	NO_GON=1;	
	//�Ѹܵ��ƴӳ�������ǰ�õ���
       	lastwho = next_data( LastDumpId, 0, "data");
       	lastwho["Dump"] = do_delete_Mj(lastwho["Dump"], str, 1);
	//����ʾ���е��ƣ��������Ը��õİ��գ���			   �������˰ɣ�
       	/*for(i=0; i<4; i++)
       		tell_room(environment(this_object()),next_data(LastDumpId , i, "id")+
       			"ǰ������ǣ�\n"+show_mj(next_data(LastDumpId, i, "allout"), 6));*/
       	tell_object(me,"����������ƣ�\n");
       	i=0;
	if (who["Show"]=="����") i=3;
	if (who["Show"]=="color") i=5;
	tell_object(me,show_mj(who["Mj"],i));
	
	if( !userp(me) )		
		call_out("dump_what", DELAY, me ); //����������ǵ��ԣ����ú��������ʲô�ơ�		
	
	return delete_last_dump(who["Id"]);
}
int do_gon(string str,object me)
{
	int i;
	mapping who, lastwho;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else {
	   command("stare "+me->query("id"));
	   command("say ���ƾָ���û��ϵ��");
	   return 1;
	}
	if (!Playing){
	   command("say �ƾֻ�û��ʼ��");
	   return 1;
	}
	if (LastDumpId==me->query("id")){
	   command("stare "+me->query("id"));
	   command("say �����������Լ����!��");
	   return 1;
	}
	if (Touched && NowPlayerId[NowPlayer]!=me->query("id")){
	   command("hammer "+me->query("id"));
	   command("say ����û��������ô�ܡ�");
	   return 1;
	}
	if (!str) str=LastDump;
 
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (who["Auto"]=="auto") return 1;
	i=do_check_Mj(who["Mj"],str);
	if (i==1){
	   if (!Touched) return notify_fail("�㻹û���ơ�\n");
	   i=do_check_Mj(who["OutPon"],str);
	   if (!i) return notify_fail("��ֻ��һ�Ų��ܸ�  ��\n");
	   if (NO_GON) return notify_fail("�����޷����ơ�\n");
	      message_vision("\n$N˵����"+HIB+"ľ��"+NOR+"������\n\n",me);
	      who["Mj"]=do_delete_Mj(who["Mj"],str,1);
	      destop+=str;		//�������Ƶ�ȻҪ������������
	      sort_data(who["OutPon"]+=str);
	      str=List[end..end+1];
	      end-=2;
	      Goned++;
	      message_vision("\n$N�Ӻ��油��һ���ơ�\n\n",me);
	      if(userp(me)) tell_object(me, "�㲹��һ��"+do_check_num(str,0)+"\n");
	      i=0;
	      if (who["Show"]=="����") i=3;
	      if (who["Show"]=="color") i=5;
	      who["Mj"]=str+who["Mj"];		//Ϊ��ϰ�߰��Ʒ����ұ�
	      check_flower(who);
	      tell_object(me,show_mj(who["Mj"],i));
	      Touched=1;
	      return 1;
	}
	if (i < 3) return notify_fail("������Ҫ������"+do_check_num(str,0)+"���ܸܡ�\n");
	if (!Touched){
	   if (str!=LastDump) return notify_fail("�����޷��ܡ�\n");
	}
	else if (i < 4) return notify_fail("������Ҫ������"+do_check_num(str,0)+"���ܰ��ܡ�\n");
	for (i=0;i<Play;i++) {
	    if (NowPlayerId[NowPlayer]==me->query("id")) break;
	    NowPlayer++;
	    NowPlayer%=Play;
	}
	who["Mj"]=do_delete_Mj(who["Mj"],str,3);
	if (Touched && NowPlayerId[NowPlayer]==me->query("id")){
	   NO_HU=0;
	   message_vision("\n$N����¶��а���Ц��˵����"+HIR"����ľ��������"+NOR"�ٺ�.....\n\n",me);
	   who["Mj"]=do_delete_Mj(who["Mj"],str,1);
	   for (i=0;i<4;i++) who["OutPon"]+="xx";
	   for (i=0;i<4;i++) who["OutGon"]+=str;
	}else{
	   //NO_HU=1;
	   message_vision("\n$N��У�"+do_check_num(str,0)+"��"+HIW+"ľ��������"+NOR+"\n\n",me);
	   for (i=0;i<4;i++) who["Out"]+=str;
	   //�Ѹܵ��ƴӳ�������ǰ�õ���
		lastwho = next_data( LastDumpId, 0, "data");
		lastwho["Dump"] = do_delete_Mj(lastwho["Dump"], str, 1);
	//����ʾ���е��ƣ��������Ը��õİ��գ���		�������˰ɣ�
	/*	for(i=0; i<4; i++)
			tell_room(environment(this_object()),next_data(LastDumpId , i, "id")+
				"ǰ������ǣ�\n"+show_mj(next_data(LastDumpId, i, "allout"), 6));			
	*/	
	   PAUSE = 0;	//ȡ����ͣ
	   if(userp(me)) who["Pause"] = "";//ȡ����ҵ���ͣ���
	   for (i=0; i<3; i++) destop+=str;
	}
	str=List[end..end+1];
	end-=2;
	Goned++;
	message_vision("$N�Ӻ��油��һ���ơ�\n",me);
	tell_object(me,"�㲹��һ��"+do_check_num(str,0)+"\n");
	who["Mj"]=str+who["Mj"];
	check_flower(who);
	i=0;
	if (who["Show"]=="����") i=3;
	if (who["Show"]=="color") i=5;
	tell_object(me,show_mj(who["Mj"],i));
	if (Touched) return 1;//���Ī������
	Touched=1;
	
	if(!userp(me)) {		
		call_out("dump_what", DELAY, me);//�����NPC�ͼ�������
	}
	return delete_last_dump(who["Id"]);
}
varargs int do_win(string str,object me)
{
	int i,j;
	int *winner=({0,0,0,0});
	string Mj="";
	mapping who;
	object met;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else {
	   command("stare "+me->query("id"));
	   command("say ���ƾָ���û��ϵ��");
	   return 1;
	}
	if (!Playing){
	   command("say �ƾֻ�û��ʼ...");
	   return 1;
	}
	
	if (NO_HU || LastDumpId==me->query("id")) return notify_fail("�������ܺ��ơ�\n");
	PAUSE = 0;		//ȡ����ͣ
	if (LastDump==""&&Touched) message_vision("\n$N��У�"+HIW+"�졫�������¡�����"+NOR+"\n\n",me);
	else{
	     tell_room(environment(this_object()),"\n"+me->name()+"��У�"+HIW+"�ҡ����¡�����"+NOR+"\n\n",me);
	     tell_object(me,"\n���У�"+HIW+"�ҡ����¡�����"+NOR+"\n\n");	     
	}
	if (Touched&&NowPlayerId[NowPlayer]==me->query("id"))
	   message_vision("$N˵��������"+me->name()+HIG+"����"+NOR+"��������������"+HIR+"�Ժ�"+NOR+"����������\n",this_object());
	else command("say "+me->name()+"����");
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (sizeof(who["OutFlower"]) ==16) i=1;
	else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) i=1;
	if (!HU_F) i=0;
	if (i){
	   Mj+="���ҵĻ����ǣ�\n";
	   Mj+=show_mj(who["OutFlower"],1);
	   if (NowPlayerId[NowPlayer]==who["Id"]) Mj+="���һ�������\n";
	   else{
	     if (sizeof(P1Data["OutFlower"])==2) LastDumpId=P1Data["Id"];
	     else if (sizeof(P2Data["OutFlower"])==2) LastDumpId=P2Data["Id"];
	     else if (sizeof(P3Data["OutFlower"])==2) LastDumpId=P3Data["Id"];
	     else if (sizeof(P4Data["OutFlower"])==2) LastDumpId=P4Data["Id"];
	     Mj+="\n���Ʒ�ǹ�ߣ�"+HIB+LastDumpId+NOR+"\n";
	   }
	}else{
	  Mj+="���ҵ����ǣ�\n";
	  if (who["OutGon"]!=""){
	     Mj+="���ܵ��У�\n";
	     Mj+=show_mj(who["OutGon"],0);
	  }
	  Mj+=show_mj(who["OutPon"]+who["Out"], 0);
	  //Mj+=who["Id"]+"�����е����У�\n";
	  if (!Touched){
	     who["Mj"]+=LastDump;
	     who["Mj"]=sort_data(who["Mj"]);
	     Mj+=show_mj(who["Mj"],0);
	     Mj+="���������ǣ�"+HIR+do_check_num(LastDump,0)+NOR;
	     Mj+="\n��ǹ�ߣ�"+HIB+LastDumpId+NOR+"\n";
	  }else{
	     Mj+=show_mj(who["Mj"],0);
	     if (str) Mj+="�����������ǣ�"+HIR+do_check_num(str,0)+NOR+"\n";
	  }
	}
	Playing=0;
	tell_room(environment(this_object()),Mj);
	Tc="";
	//if (do_check_win(who["Mj"])==1||i==1){
	if (do_check_win(sort_data(who["Mj"]))==1||i==1)
	{//Ϊ�˷����ұ߷��Ƶ�ϰ�ߡ�����������Ҫ����sort_data
//��̨///////////////////////////////////
	mixed MjT = ([
"@1" : ({ "ׯ��", 1 }),"@2" : ({ "����", 1 }),"@3" : ({ "����", 1 }),"@4" : ({ "����", 1 }),"@Z" : ({ "���۾�", 1 }),
"@5" : ({ "����", 1 }),"@6" : ({ "�Ϸ�", 1 }),"@7" : ({ "����", 1 }),"@8" : ({ "����", 1 }),
"@9" : ({ "����", 1 }),"@0" : ({ "�෢", 1 }),"@a" : ({ "�װ�", 1 }),"@G" : ({ "һا��", 1 }),
"@b" : ({ "��������", 1 }),"@c" : ({ "��������", 1 }),"@d" : ({ "ƽ��", 2 }),"@e" : ({ "���綫", 2 }),
"@f" : ({ "�Ϸ���", 2 }),"@g" : ({ "������", 2 }),"@h" : ({ "���籱", 2 }),"@i" : ({ "ȫ����", 2 }),
"@j" : ({ "������", 2 }),"@H" : ({ "��ا��", 2 }),"@k" : ({ "������", 2 }),"@B" : ({ "�����ﶬ", 2 }),
"@C" : ({ "÷������", 2 }),"@l" : ({ "��������", 3 }),"@m" : ({ "������", 4 }),"@n" : ({ "��һɫ", 4 }),
"@o" : ({ "С��Ԫ", 4 }),"@p" : ({ "�İ���", 6 }),"@q" : ({ "��һɫ", 8 }),"@r" : ({ "��һɫ", 8 }),
"@s" : ({ "�߶���", 8 }),"@t" : ({ "����Ԫ", 8 }),"@u" : ({ "�尵��", 8 }),"@F" : ({ "С��ϲ", 8 }),
"@D" : ({ "����һ", 8 }),"@E" : ({ "��һɫ", 16 }),"@v" : ({ "����ϲ", 16 }),"@w" : ({ "���", 16 }),
"@x" : ({ "�غ�", 16 }),"@y" : ({ "�˺�", 16 }),"@z" : ({ "��ʿ��˫", 16 }),"@A" : ({ "���ɹ���", 16 }),
"@J" : ({ "���۾�", 8 }),"@I" : ({ "���۾�", 4 }),
]);//H
	   get_tc(who);
////////////////
	   str="\t\t\t�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n";
	   for (i=0;i<sizeof(Tc);i+=2){
	      str+=sprintf("\t\t\t%-12s%8s ̨\n",MjT[Tc[i..i+1]][0],chinese_number(MjT[Tc[i..i+1]][1]));
	      j+=MjT[Tc[i..i+1]][1];
	   }
	   if (Count){
	      str+=sprintf("\t\t\t%-12s%8s ̨\n","��"+chinese_number(Count)+"��"+chinese_number(Count),chinese_number(Count*2));
	      j+=Count*2;
	   }
	   str+=sprintf("\t\t\t%20s\n","��̨����"+chinese_number(j+1)+" ̨");
	   str+="\t\t\t�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n";
	   tell_room(environment(this_player()),str);
/////////////
	   if (!Touched){
	      if (Play==4){
		 if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
		 winner[1]+=j;
		 set_mjdata(me,winner);
		 met=present(LastDumpId, environment(this_object()));
		 if (!met) met=find_player(LastDumpId);
		 if (!met);
		 else{
		    if (!winner=get_mjdata(LastDumpId)) winner=({0,0,0,0});
		    winner[1]-=j; //ս��
		    winner[3]++; //��ǹ
		    set_mjdata(met,winner);
		 }
		 for (i=0;i<Play;i++){
		     met=present(NowPlayerId[i], environment(this_object()));
		     if (!met) met=find_player(NowPlayerId[i]);
		     if (!met);
		     else{
			if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
			winner[0]++; //����
			set_mjdata(met,winner);
		     }
		 }
	      }
	   }else{
	      if (Play==4){
		 if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
		 winner[0]++;
		 winner[1]+=(j*3);
		 winner[2]++;
		 set_mjdata(me,winner);
		 for (i=0;i<Play;i++){
		     if (NowPlayerId[i]==me->query("id")) continue;
		     met=present(NowPlayerId[i], environment(this_object()));
		     if (!met) met=find_player(NowPlayerId[i]);
		     if (!met);
		     else{
			if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
			winner[0]++;
			winner[1]-=j;
			set_mjdata(met,winner);
		     }
		 }
	      }
	   }
	 if (NowPlayerId[0]==who["Id"]) Count++;
	 else{
	   Times++;
	   Count=0;
	 }
	}else{
	   command("sigh "+who["Id"]);
	   message_vision("$N˵������� ["+HIR+who["Id"]+HIG+"] ��է�� ���¡�����"+NOR+"��\n",this_object());
	   Times++;
	   Count=0;
	   if (Play==4){
	      if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
	      if (NowPlayerId[NowPlayer]==who["Id"]&&Touched){
		 if (who["Out"]==""&&who["OutPon"]==""){
		    winner[1]-=24;
		    j=-24;
		 }else {
		    winner[1]-=18;
		    j=-18;
		 }
	      }else{
		 if (who["Out"]==""&&who["OutPon"]==""){
		    winner[1]-=6;
		    j=-6;
		 }else{
		    winner[1]-=5;
		    j=-5;
		 }
	      }
////////////////
	      str="\t\t\t�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n";
	      str+=sprintf("\t\t\t%-12s%8s ̨\n","��է����",chinese_number(j));
	      str+=sprintf("\t\t\t%20s\n","��̨����"+chinese_number(j+5)+" ̨");
	      str+="\t\t\t�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n";
	      tell_room(environment(this_player()),str);
/////////////
	      set_mjdata(me,winner);
	      for (i=0;i<Play;i++){
		  met=present(NowPlayerId[i], environment(this_object()));
		  if (!met) met=find_player(NowPlayerId[i]);
		  if (!met);
		  else{
		     if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
		     winner[0]++;
		     set_mjdata(met,winner);
		  }
	      }
	   }
	}
	Mj="\n[0;1;36;46m  ";
	for (i=0; i<33; i++) Mj+="  ";
	Mj+="[1;36;46m  [0m\n";
	Mj+="[1;36;46m  [0;36m      "+HIW+"Ӣ[0m������      "+HIW+"��[0m������  [1m��[0m�����  [1m��[0mս��  [1m��[0m������  [1m��[0mǹ����[1;36;46m  [0m\n";
	for (i=0;i<4;i++){
	    if (Play==4) winner=get_mjdata(NowPlayerId[i]);
	    Mj+=sprintf("[1;36;46m  [0;36m  [1;37m%12s  [1;37m%12s  [33m%8d  [35m%6d  [32m%8d  [34m%8d[1;36;46m  [0m\n",
			 NowPlayerId[i],present(NowPlayerId[i])->query("name"),winner[0],winner[1],winner[2],winner[3]);
	}
	Mj+="[1;36;46m  ";
	for (i=0; i<33; i++) Mj+="  ";
	Mj+="[46m��[0m\n";
	if (Play==4) tell_room(environment(this_object()),Mj);
	call_out( "wash_mj", 3, Play);
	return 1;
}

int do_check_win(string str)
{	
	string str1;	
	int i, Sp, size = strlen(str);		
 	string Special="1w9w1s9s1t9tdfnfxfbfhzfaba";
 	
	K=0;
	if (size > 27){
		if (do_check_Mj(str,"df")&&do_check_Mj(str,"nf")&&do_check_Mj(str,"xf")&&do_check_Mj(str,"bf")&&
			do_check_Mj(str,"hz")&&do_check_Mj(str,"fa")&&do_check_Mj(str,"ba")&&
			do_check_Mj(str,"1w")&&do_check_Mj(str,"9w")&&do_check_Mj(str,"1s")&&
			do_check_Mj(str,"9s")&&do_check_Mj(str,"1t")&&do_check_Mj(str,"9t")){
		  //��ɾ��13ֻ
			for (i=0;i<sizeof(Special);i+=2) {
				if (do_check_Mj(str,Special[i..i+1]))
					str=do_delete_Mj(str,Special[i..i+1],1);				
			}
			for (i=0;i<sizeof(Special);i+=2) {
				if (do_check_Mj(str,Special[i..i+1])){
					Tc+="@z";
					return 1;
				}
			}
		}
	}
	if(size>27) {
		for(i=0; i<strlen(str); i+=4)
			if(str[i..i+1]==str[i+2..i+3]) Sp++;		
		if(Sp==7) {
			Tc+="@s";//7����
			return 1;
		}
	}	
	
	for(i=0; i<strlen(str); i+=2){
		if( str[i..i+1]==str[i+2..i+3]) str1 = do_delete_Mj(str, str[i..i+1], 2);
		//rite( str1+"\n");
		//i+=2;
		if(check_hu(str1)) {
			if( B>0 ) Tc+="@G";
			return 1;
		}	
	}
	//write("not hu\n");		
	return 0;
}

int check_hu(string str)	//ԭ��д��n�еĶ��������ʮ���и㶨���ٺ٣�̨���ͬ־������
{
	int i=strlen(str); 
	string str1, str2, str3, str4;
	K=0;
	for(i=0; i<strlen(str); i+=2){
	
		str1 =str[i..i+1];str2=str[i+2..i+3];str3=str[i+4..i+5];
		if( str1==str2 && str3==str2 ) { 
			K++;
			str = do_delete_Mj(str, str1, 3);
			i=-2;}
		str2 = next_mj(str1, 1); str3= next_mj(str1, 2);
		
		if( do_check_Mj( str, str3)>0 &&do_check_Mj( str, str2 )>0 ){		
			//write("the next is "+str2+" ");
			if( str1+str2+str3==str4 ) B++;
			str = do_delete_Mj(str, str1, 1);
			str = do_delete_Mj(str, str2, 1);
			str = do_delete_Mj(str, str3, 1);
			str4 = str1+str2+str3;
			i=-2;
		}		
	}
	if( str=="" ) return 1;	
	return 0;
}

int do_touch(string str,object me)
{
	int i,check;
	mapping who;	
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else {
	   command("stare "+me->query("id"));
	   command("say ���ƾָ���û��ϵ��");
	   return 1;
	}
	if (!Playing){
	   command("say �ƾֻ�û��ʼ��Ҫ����ȥ��������~~");
	   return 1;
	}
//	tell_object(me,"��˭���ƣ�"+NowPlayerId[NowPlayer]+"\n");
	if (me->query("id")!=NowPlayerId[NowPlayer]){
	   command("hammer "+me->query("id"));
	   command("say ��͵�ƣ�û��������~~");
	   return 1;
	}
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	
	if(NowPlayerId[NowPlayer]==me->query("id") && Touched==1&& userp(me) ){
		do_dump( who["Mj"][0..1], me);
		return 1;
	}
	if (Touched){
	   command("flop "+me->query("id"));
	   command("say ��������");
	   return 1;
	}
	if (PAUSE){
	   command("flop "+me->query("id"));
	   command("say �ȵȣ������ڿ��ƣ�");
	   return 1;
	}
	
	NO_HU=0;
	NO_GON=0;
	
	if (who["Auto"]=="auto"){
	   if (str=="AUTO");
	   else{
	     write("�趨�Զ����ƺ󡢲����Լ����ơ�\n");
	      return 1;
	    }
	}
	Touched=1;
	str=List[count..count+1];
	count+=2;	
	tell_room(environment(this_object()),me->name()+"����һ���ơ�",me);
	
	if(userp(me)) tell_object(me,"������һ���ơ�");
	//tell_object(me,"������һ��"+do_check_num(str,0)+"\n");
	if (who["Auto"]=="auto"){
	   if (do_check_num(str,1) > 34){
	      for (i=0;i<1;i++){
		   who["OutFlower"]+=str;
		   HU_F=1;
		   tell_room(environment(this_object()),me->name()+"˵����"+HIB+"����"+NOR+"������\n\n"+me->name()+"�����油��һ���ơ�\n",me);
		   tell_object(me,"��˵����"+HIB+"����"+NOR+"��������\n\n�������油��һ���ơ�\n");
		   str=List[end..end+1];
		   end-=2;
		   tell_object(me,"��������һ��"+do_check_num(str,0)+"\n");
		   if (do_check_num(str,1) > 34) i--;
	      }
	   }
	   check=do_check_Mj(who["AutoTin"],str);
	   if (check!=0){
	      who["Mj"]+=str;
	      who["Mj"]=sort_data(who["Mj"]);
	      return do_win(str,me);
	   }
	   do_dump(str,me);
	}
	who["Mj"]=str+who["Mj"];
	check_flower(who);
	if( !userp(me) ) 
		if(do_check_Mj(who["OutPon"],str)>1&&do_check_num(str, 1)>27&&do_check_num(str, 1)<35 )
			do_gon( str, me);
	i=0;
	if (who["Show"]=="����") i=3;
	if (who["Show"]=="color") i=5;
	if(userp(me)) tell_object(me,"����"+chinese_number((end-count-16-Goned)/2)+"���ƾ������ˡ�\n"+show_mj(who["Mj"],i));
	
	if( !userp(me) ){
		who["Mj"]=sort_data(who["Mj"]);
		dump_what( me ); //����������ǵ��ԣ����ú��������ʲô�ơ�		
	}
	return 1;
}
int do_pon(string str,object me)
{
	int i;
	mapping who, lastwho;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else {
	   command("stare "+me->query("id"));
	   command("say ���ƾָ���û��ϵ��");
	   return 1;
	}
	if (!Playing){
	   command("die "+me->query("id"));
	   command("say �ƾֻ�û��ʼ�������ͷ����");
	   return 1;
	}
	if (Touched){
	   command("hammer "+me->query("id"));
	   command("say ����û��������������");
	   return 1;
	}
	if (LastDumpId==me->query("id")){
	   command("stare "+me->query("id"));
	   command("say �����������Լ����!��");
	   return 1;
	}
	if (!str) str=LastDump;
	else if (str!=LastDump) return notify_fail("����"+do_check_num(str,0)+"�Ѿ������ˡ�\n");
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (who["Auto"]=="auto") return 1;
	i=do_check_Mj(who["Mj"],str);
	if (i==0) return notify_fail("��û"+do_check_num(str,0)+"������Ҫ��������\n");
	if (i < 2) return notify_fail("������Ҫ������"+do_check_num(str,0)+"��������\n");
	message_vision("\n$N��У�"+do_check_num(str,0)+"��"+HIW+"ʯ�K������"+NOR+"\n\n",me);	
	//remove_call_out("do_touch");//������NPC���ƣ��Դ���next_data����֮��������û���ÿ���:P��
	PAUSE = 0;		//ȡ����ͣ
	if(userp(me)) who["Pause"]="";//ȡ����ҵ���ͣ���
	destop+=str;		//�����˵���
	destop+=str;		//��������
	for (i=0;i<Play;i++) {
	    if (NowPlayerId[NowPlayer]==me->query("id")) break;
	    NowPlayer++;
	    NowPlayer%=Play;
	}
	for (i=0;i<3;i++) who["OutPon"]+=str;
	who["Mj"]=do_delete_Mj(who["Mj"],str,2);
	who["AutoPon"]=do_delete_Mj(who["AutoPon"],str,1);
	NO_HU=1;
	NO_GON=1;
	Touched=1;
	//�������ƴӳ�������ǰ�õ���
	lastwho = next_data( LastDumpId, 0, "data");
	lastwho["Dump"] = do_delete_Mj(lastwho["Dump"], str, 1);	
	//����ʾ���е��ƣ��������Ը��õİ��գ���		���ǲ�Ҫ�ɣ�
	/*for(i=0; i<4; i++)
		tell_room(environment(this_object()),next_data(LastDumpId , i, "id")+ "ǰ������ǣ�\n"+show_mj(next_data(LastDumpId, i, "allout"), 5));*/
	if(userp(me)) tell_object(me, "����������ƣ�\n");
	i=0;
	if (who["Show"]=="����") i=3;
	if (who["Show"]=="color") i=5;	
	tell_object(me,show_mj(who["Out"]+who["OutPon"],i));
	tell_object(me,show_mj(who["Mj"],i));
	
	//��������ǵ��ԣ��Զ����ó��ƺ���	 
	if( !userp(me) ) call_out( "dump_what", DELAY, me );	    
	
	return delete_last_dump(who["Id"]);
}
int do_restart(string str)
{
	object me=this_player();
	if (me->query("id")=="guest") return 0;
	if (str!="mj"){
	   if (check_id(me->query("id"),"player")!="");
	   else {
	      command("stare "+me->query("id"));
	      command("say ���ƾָ���û��ϵ��");
	      return 1;
	   }
	}
	message_vision("$N���ƾ������趨��\n",me);
	message_vision("$N˵�����ƾ������趨����"+HIR+" sit "+NOR+"�����ƾ֡�\n",this_object());
	NowPlayerId[0]="xishi";
	NowPlayerId[1]="chenyuanyuan";
	NowPlayerId[2]="hongniangzi";
	NowPlayerId[3]="";
	P1Data["Id"]="xishi";
	P2Data["Id"]="chenyuanyuan";
	P3Data["Id"]="hongniangzi";
	P4Data["Id"]="";
	P1Data["Pause"]="";
	P2Data["Pause"]="";
	P3Data["Pause"]="";
	P4Data["Pause"]="";
	Count=0;
	LookP ="";
	Play=START;
	Times=START;
	end=END;
	count=START;
	Playing=START;
	PAUSE = 0;
	return 1;
}
int wash_mj(int amount)
{
	int i,x;
	string str,countstr="";
	mapping who;
	object ob;
	mixed *X,MjE_Data = ([
"1w" : 0,"2w" : 0,"3w" : 0,"4w" : 0,"5w" : 0,"6w" : 0,"7w" : 0,"8w" : 0,"9w" :0,
"1s" : 0,"2s" : 0,"3s" : 0,"4s" : 0,"5s" : 0,"6s" : 0,"7s" : 0,"8s" : 0,"9s" :0,
"1t" : 0,"2t" : 0,"3t" : 0,"4t" : 0,"5t" : 0,"6t" : 0,"7t" : 0,"8t" : 0,"9t" :0,
"df" : 0,"nf" : 0,"xf" : 0,"bf" : 0,"hz" : 0,"fa" : 0,"ba" : 0,
"h1" : 0,"h2" : 0,"h3" : 0,"h4" : 0,"h5" : 0,"h6" : 0,"h7" : 0,"h8" : 0
			    ]);
	if (!Play){
	   command("say û�����Ҫ�Ұ�ϴ�ƣ��Ŷ�û�С�");
	   return 1;
	}
	if (Playing){
	   command("say �ƾ����ڽ����С�");
	   return 1;
	}
	command("say �Ұ�æϴ�ƣ��ȵ�˭��Ҫ�Ժ��..:)");
	if (Play<4) command("say ��Ҳ����������Բ��Ʒ֡�");
	for(i=0; i<4; i++){
		who = next_data( P1Data["id"], i, "data");
		
		who["Mj"]="";
		who["OutGon"]="";
		who["Out"]="";
		who["OutPon"]="";
		who["OutFlower"]="";
		who["Auto"]="";
		who["AutoTin"]="";
		who["AutoGon"]="";
		who["AutoPon"]="";
		who["Dump"]="";
	}
 
	end=END;
	NO_HU=START;
	NO_GON=START;
	count=START;
	Playing=START;
	List="";
	NowPlayer=START;
	Touched=START;
	Auto=START;
	Auto_Tin=START;
	Auto_Gon=START;
	Auto_Pon=START;
	Goned=START;
	LastDump="";
	LastDumpId="";
	X = keys(MjE_Data);
	for (i=0;i<144;i++){
	    x = random(sizeof(X));
	    
	    if (X[x]=="h1"||X[x]=="h2"||X[x]=="h3"||X[x]=="h4"||
		X[x]=="h5"||X[x]=="h6"||X[x]=="h7"||X[x]=="h8"){
		   List += X[x];
		   X -= ({X[x]});
	    }
	    else{	       
		  MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
		  List += X[x];
		  if(MjE_Data[X[x]] == 4) X -= ({X[x]});		  
	    }
	}
 
//	for (i=0;i<sizeof(X);i++) printf("%s=%d ",X[i],MjE_Data[X[i]]);
	PAUSE = 0;
	command("say �ţ����˿��Կ�ʼ�����ɣ�");
	if (Count) countstr="[��ׯ"+chinese_number(Count)+"]";
	if (!Times);
	else{
	  if (Count);
	  else {
	    str=NowPlayerId[0];
	    if (Play>1) NowPlayerId[0]=NowPlayerId[1];
	    if (Play>2) NowPlayerId[1]=NowPlayerId[2];
	    if (Play>3) NowPlayerId[2]=NowPlayerId[3];
	    NowPlayerId[Play-1]=str;
	  }
	}
	if (Times/Play == 4) Times=0;
	if (Times/Play == 3) str=HIW+"����"+NOR;
	if (Times/Play == 2) str=HIY+"����"+NOR;
	if (Times/Play == 1) str=HIR+"�Ϸ�"+NOR;
	if (Times/Play == 0) str=HIG+"����"+NOR;
	TIMES = str;
	i=Times;
	i%=Play;
	i++;
	message_vision("["+str+chinese_number(i)+"]�ƾֿ�ʼ��ׯ��"+HIY+NowPlayerName[0]+HIR+countstr+NOR+"��������"+" ["+HIR+chinese_number(i=3+random(16))+NOR+ "] �㡣\n",this_object());
	//���ȡ��һ��ȡ16ֻ:Q
	if (Play>0) P1Data["Mj"]=List[0..25];//"9t9t9tdfdf3t4t5t2s7s";P1Data["Out"]="2t3t4t";
	if (Play>1) P2Data["Mj"]=List[26..51];//"1s2s3s4s5s9s3t";P2Data["Out"]="1w2w3w4w5w6w";//
	if (Play>2) P3Data["Mj"]=List[52..77];
	if (Play>3) P4Data["Mj"]=List[78..103];//"1w1w2w2w3w3w5w5w6w6w7w7w8w";//"1t1t2t2t3t3t5w5w51s1s1s3t";//
	count=(Play*2*13);
	
	if (Play>0) check_flower(P1Data);
	if (Play>1) check_flower(P2Data);
	if (Play>2) check_flower(P3Data);
	if (Play>3) check_flower(P4Data);
	List[end..end+1]="2t";
	P1Data["Mj"] = sort_data(P1Data["Mj"]);
	P2Data["Mj"] = sort_data(P2Data["Mj"]);
	P3Data["Mj"] = sort_data(P3Data["Mj"]);
	P4Data["Mj"] = sort_data(P4Data["Mj"]);
	Playing=1;
	/*for( i=0; i<3; i++) {
		ob = next_data(NowPlayerId[0], i+1, "player");
		if(userp(ob)) tell_object( ob, "����������ƣ�\n" +show_mj(next_data(NowPlayerId[0], i+1, "Mj"), 5) );		
	}*/
	get_attitudes(P1Data);get_attitudes(P2Data);get_attitudes(P3Data); //����NPC�Ĵ���̬��
	message_vision("$N˵����ׯ��"+HIY+NowPlayerName[0]+NOR+"����ơ�\n",this_object());
	do_touch( 0, present(NowPlayerId[0]) );	//��ׯ�����ơ�	
	
	return 1;
}
int do_setmj(string str)
{
	int check;
	string numstr;
	mapping who;
	object me=this_player();
 
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	else return 1;
	if (!str){
	   numstr=this_object()->name()+"������˵���趨���У�\n";
	  if (who["AutoTin"]!="") numstr+="����"+HIB+show_mj(who["AutoTin"],2)+NOR+"���Զ�"+HIB+"[����]"+NOR+"��\n";
	  if (who["AutoGon"]!="") numstr+="����"+HIY+show_mj(who["AutoGon"],2)+NOR+"���Զ�"+HIY+"[����]"+NOR+"��\n";
	  if (who["AutoPon"]!="") numstr+="����"+HIG+show_mj(who["AutoPon"],2)+NOR+"���Զ�"+HIG+"[����]"+NOR+"��\n";
	  if (who["Show"]=="����")    numstr+="��ʾ��ʽΪ"+HIY+"[����]"+NOR+"��ʽ��\n";
	  if (who["Show"]=="color")   numstr+="��ʾ��ʽΪ"+HIG+"[��ɫ]"+NOR+"��\n";
	  if (who["Auto"]=="auto")    numstr+="���趨"+HIR+"[�Զ�����]"+NOR+"��\n";
	  if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") numstr+="��û���κ��趨��\n";
	   tell_room(environment(me),this_object()->name()+"��"+me->name()+"����˵��һЩ����\n",me);
	   tell_object(me,numstr);
	   return 1;
	}
	if (sscanf(str,"%s %s",str,numstr)!=2) return notify_fail("ָ�setmj <ting>&<gang>&<peng> <����>\n");
	if (str=="ting"){
	   if (numstr=="none"){
	      who["AutoTin"]="";
	      return notify_fail("��ȡ���Զ������趨��\n");
	   }
	   check=do_check_Mj(MjE,numstr);
	   if (check!=1) return notify_fail("û��["+numstr+"]�����ơ�\n");
	   check=do_check_Mj(who["AutoTin"],numstr);
	   if (check){
	      who["AutoTin"]=do_delete_Mj(who["AutoTin"],numstr,1);
	      return notify_fail("��"+HIR+"ɾ����"+NOR+"����"+do_check_num(numstr,0)+"���Զ����Ƶ��趨��\n");
	   }
	   who["AutoTin"]+=numstr;
	   Auto_Tin=1;
	   write("���趨����"+do_check_num(numstr,0)+"ʱ���Զ����ơ�\n");
	   return 1;
	}
	else if (str=="gang"){
	   if (numstr=="none"){
	      who["AutoGon"]="";
	      return notify_fail("��ȡ���Զ������趨��\n");
	   }
	   check=do_check_Mj(who["Mj"],numstr);
	   if (check==0) return notify_fail("��û"+do_check_num(numstr,0)+"�����ơ�\n");
	   if (check < 3) return notify_fail("������Ҫ������"+do_check_num(numstr,0)+"�����趨�ܴ��ơ�\n");
	   check=do_check_Mj(who["AutoGon"],numstr);
	   if (check){
	      who["AutoGon"]=do_delete_Mj(who["AutoGon"],numstr,1);
	      return notify_fail("��"+HIR+"ɾ����"+NOR+"����"+do_check_num(numstr,0)+"���Զ����Ƶ��趨��\n");
	   }
	   who["AutoGon"]+=numstr;
	   Auto_Gon=1;
	   write("���趨����"+do_check_num(numstr,0)+"ʱ���Զ����ơ�\n");
	   return 1;
	}
	else if (str=="peng"){
	   if (numstr=="none"){
	      who["AutoPon"]="";
	      return notify_fail("��ȡ���Զ������趨��\n");
	   }
	   check=do_check_Mj(who["Mj"],numstr);
	   if (check==0) return notify_fail("��û"+do_check_num(numstr,0)+"�����ơ�\n");
	   if (check < 2) return notify_fail("������Ҫ������"+do_check_num(numstr,0)+"�����趨�����ơ�\n");
	   check=do_check_Mj(who["AutoPon"],numstr);
	   if (check){
	      who["AutoPon"]=do_delete_Mj(who["AutoPon"],numstr,1);
	      return notify_fail("��"+HIR+"ɾ����"+NOR+"����"+do_check_num(numstr,0)+"���Զ����Ƶ��趨��\n");
	   }
	   who["AutoPon"]+=numstr;
	   Auto_Pon=1;
	   write("���趨����"+do_check_num(numstr,0)+"ʱ���Զ����ơ�\n");
	   return 1;
	}
	else if (str=="show"){
	   if (numstr=="none"||numstr=="1"){
	      who["Show"]="";
	      return notify_fail("��ȡ����ʾ�趨��\n");
	   }
 
	   if (numstr=="����"||numstr=="3"){
	      numstr="����";
	      write("���趨ֻ��ʾ���롣\n");
	   }
	   else if (numstr=="color"||numstr=="2"){
		numstr="color";
		 write("���趨��ɫ��ʾ��\n");
	   }
	   else return 1;
	   who["Show"]=numstr;
	   return 1;
	}
	else if (str=="auto"){
	   if (numstr=="none"){
	      return notify_fail("����ȡ���Զ����ƣ�Ҫ���趨�������թ���ɣ�:>��\n");
	   }
	   if (who["AutoTin"]=="") return notify_fail("�����趨Ҫ�����ơ�\n");
	   if (!Touched) return notify_fail("���������������趨��\n");
	   if (numstr=="ting") write("���趨�Զ����ơ�\n");
	   else return 1;
	   message_vision("\n$N���һ����"+HIW+"������������"+NOR+"\n\n",me);
	   Auto=1;
	   who["Auto"]="auto";
	   return 1;
	}
	else return notify_fail("û�������趨��\n");
}
int do_check_eat(string num1,string num2,string LastDump)
{
	int A,B,C;
	A=do_check_num(num1,1);
	B=do_check_num(num2,1);
	C=do_check_num(LastDump,1);
	if (A<10){
	   if (B>10||C>10) return 0;
	}
	else if (A<19&&A>10){
		if (B>19||C>19&&B<10||C<10) return 0;
	}
	else if (A<28&&A>19){
		if (B<19||C<19) return 0;
	}
	A=do_check_num(num1,2);
	B=do_check_num(num2,2);
	C=do_check_num(LastDump,2);
 
	if (A > 9 || B > 9 || C > 9) return 0;
	if ((A+B)%2!=0){
	   if (A > B){
	       if (C==(A+1) || C==(A-2)) return 1;
	   }else{
	       if (C==(B+1) || C==(B-2)) return 1;
	   }
	   return 0;
	}else{
	    if (A > B){
	      if (C==(A-1) || C==(B+1)) return 1;
	     }else{
	      if (C==(B-1) || C==(A+1)) return 1;
	     }
	    return 0;
	}
}
string show_mj(string str,int flag)
{
	string str1, str2;       
		
	string Mj="",Mj1="";
	int size=strlen(str)+2,a,b;
	
	if(sizeof(str)>60){		
		str1 = str[sizeof(str)-60..sizeof(str)-1];
		str2 = str[0..sizeof(str)-61];
		str = show_mj( str1, flag) + show_mj(str2, flag);
		return str;
	}
	
	if (!str||str=="") return "";
	if (flag!=3){
	   for(; size>=0; size-=2)
	     Mj+=do_check_num(str[size..size+1],0);

	   for(a=0; a<size; a+=2) 
	   	Mj+=do_check_num(str[a..a+1], 0);
	   if (flag==2) Mj1=Mj;
	   else{
 
	     size=strlen(Mj);
	     Mj1="��";
	     for (a=0;a<(size/2)-1;a++){
		 if (a%2==0) Mj1+="��";
		 else Mj1+="��";
	     }
	     Mj1+="��\n��";
 
	     for (a=0;a<size-1;a++){
		 if (flag==5 || flag==6){
		    if (Mj[a+2..a+3]=="��") Mj1+=HIR;
		    else if (Mj[a+2..a+3]=="Ͳ") Mj1+=HIC;
		    else if (Mj[a+2..a+3]=="��") Mj1+=HIG;
		    else if (Mj[a+2..a+3]=="��") Mj1+=HIM;
		    else if (Mj[a+2..a+3]=="��") Mj1+=HIR;
		    else if (Mj[a+2..a+3]=="��") Mj1+=HIG;
		    else if (Mj[a+2..a+3]=="��") Mj1+=HIW;
		    else if (Mj[a+2..a+3]=="��"
			 ||  Mj[a+2..a+3]=="��"
			 ||  Mj[a+2..a+3]=="��"
			 ||  Mj[a+2..a+3]=="��") Mj1+=HIR;
		    else if (Mj[a+2..a+3]=="÷"
			 ||  Mj[a+2..a+3]=="��"
			 ||  Mj[a+2..a+3]=="��"
			 ||  Mj[a+2..a+3]=="��") Mj1+="[1;30m";
		 }
		 Mj1+=Mj[a..a+1];
		 a+=3;
		 Mj1+=NOR+"��";
	     }
	     Mj1+="\n��";
	     for (a=2;a<size;a++){
		 if (flag==5 || flag==6){
			 if (Mj[a..a+1]=="��") Mj1+=HIR;
		    else if (Mj[a..a+1]=="��") Mj1+=HIG;
		    else if (Mj[a..a+1]=="Ͳ") Mj1+=HIC;
		    else if (Mj[a..a+1]=="��") Mj1+=HIM;
		    else if (Mj[a..a+1]=="��") Mj1+=HIR;
		    else if (Mj[a..a+1]=="��") Mj1+=HIG;
		    else if (Mj[a..a+1]=="��") Mj1+=HIW;
		    else if (Mj[a..a+1]=="��") Mj1+=HIG;
		    else if (Mj[a..a+1]=="��") Mj1+=HIB;
		    else if (Mj[a..a+1]=="��") Mj1+=HIY;
		    else if (Mj[a..a+1]=="��") Mj1+=HIW;
		    else if (Mj[a..a+1]=="÷") Mj1+=HIW;
		    else if (Mj[a..a+1]=="��") Mj1+=HIR;
		    else if (Mj[a..a+1]=="��") Mj1+=HIG;
		    else if (Mj[a..a+1]=="��") Mj1+=HIY;
		 }
		 Mj1+=Mj[a..a+1];
		 a+=3;
		 Mj1+=NOR+"��";
	     }
	     Mj1+="\n��";
	     for (a=(size/2)-1;a>0;a--){
		 if (a%2!=0){
		    if (flag==0 || flag==5) Mj1+=str[a-1..a];
		    else Mj1+="��";
		 }
		 else Mj1+="��";
	     }
	     Mj1+="��\n";
	   }
	   return Mj1;
	}else{
	    size*=2;
	    for (a=(size/2)-1;a>0;a--){
		if (a%2!=0) Mj1+=str[a-1..a];
		else Mj1+=" ";
	   }
	   Mj1+="\n";
	}
	return Mj1;
}
string check_id(string str,string kind)
{
	int check,i;
	if (!str) return "";
	if (kind=="ting")
	{
		check=NowPlayer;
		for (i=0;i<Play-1;i++)
		{
			if (NowPlayerId[check]==P1Data["Id"] && do_check_Mj(P1Data["AutoTin"],str)!=0) return P1Data["Id"];
			if (NowPlayerId[check]==P2Data["Id"] && do_check_Mj(P2Data["AutoTin"],str)!=0) return P2Data["Id"];
			if (NowPlayerId[check]==P3Data["Id"] && do_check_Mj(P3Data["AutoTin"],str)!=0) return P3Data["Id"];
			if (NowPlayerId[check]==P4Data["Id"] && do_check_Mj(P4Data["AutoTin"],str)!=0) return P4Data["Id"];
			check++;
			check%=Play;
		}
		return "";
	}
	if (kind=="gang")
	{
		check=do_check_Mj(P1Data["AutoGon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P1Data["Mj"],str);
			if (check < 3) return "";
			else return P1Data["Id"];
		}
		check=do_check_Mj(P2Data["AutoGon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P2Data["Mj"],str);
			if (check < 3) return "";
			else return P2Data["Id"];
		}
		check=do_check_Mj(P3Data["AutoGon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P3Data["Mj"],str);
			if (check < 3) return "";
			else return P3Data["Id"];
		}
		check=do_check_Mj(P4Data["AutoGon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P4Data["Mj"],str);
			if (check < 3) return "";
			else return P4Data["Id"];
		}
		return "";
	}
	if (kind=="peng")
	{
		check=do_check_Mj(P1Data["AutoPon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P1Data["Mj"],str);
			if (check < 2) return "";
			else return P1Data["Id"];
		}
		check=do_check_Mj(P2Data["AutoPon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P2Data["Mj"],str);
			if (check < 2) return "";
			else return P2Data["Id"];
		}
		check=do_check_Mj(P3Data["AutoPon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P3Data["Mj"],str);
			if (check < 2) return "";
			else return P3Data["Id"];
		}
		check=do_check_Mj(P4Data["AutoPon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P4Data["Mj"],str);
			if (check < 2) return "";
			else return P4Data["Id"];
		}
		return "";
	}
	if (kind=="player")
	{
		for (i=0;i<4;i++)
		{
			if (NowPlayerId[i]==str) check=1;
		}
		if (check) return "Y";
		return "";
	}
}
int delete_last_dump(string whoId)
{
	mapping who;
	if (LastDumpId==P1Data["Id"]) who=P1Data;
	else if (LastDumpId==P2Data["Id"]) who=P2Data;
	else if (LastDumpId==P3Data["Id"]) who=P3Data;
	else if (LastDumpId==P4Data["Id"]) who=P4Data;
	if (who["Dump"]!="") who["Dump"]=do_delete_Mj(who["Dump"],LastDump,1);
	return 1;
}
//��Ӣ����תΪ���� or ���� flag 1 ����תΪ���� flag 2 תΪ1..9
mixed do_check_num(string str,int flag)
{
	int number;
 
	if (!str) return MjC[0];
	sscanf(str,"%d%s",number,str);
	if (number == 0)
	{
		if (str=="df") number=28;
		else if (str=="nf") number=29;
		else if (str=="xf") number=30;
		else if (str=="bf") number=31;
		else if (str=="hz") number=32;
		else if (str=="fa") number=33;
		else if (str=="ba") number=34;
		else if (str=="h1") number=35;
		else if (str=="h2") number=36;
		else if (str=="h3") number=37;
		else if (str=="h4") number=38;
		else if (str=="h5") number=39;
		else if (str=="h6") number=40;
		else if (str=="h7") number=41;
		else if (str=="h8") number=42;
		else if (str=="xx") number=43;
		else if (str=="zz") number=44;
	}
	else
	{
		if (str=="w") number=0+number;
		else if (str=="t") number=9+number;
		else if (str=="s") number=18+number;
		if (flag==2)
		{
			number%=9;
			if (number==0) number=9;
		}
	}
	if (!flag) return MjC[number];
	else return number;
}

void check_flower(mapping who)
{
	string newstr = "",str=who["Mj"],temp,temp1;
	int i = strlen(str),j;
 
	for(; i>=0; i-=2){
	      //i--;	      
	   temp=str[i..i+1];
	   if (temp=="h1"||temp=="h2"||temp=="h3"||temp=="h4"||
	       temp=="h5"||temp=="h6"||temp=="h7"||temp=="h8"){
	      if (Playing && present(who["Id"])==this_player()){
		 tell_room(environment(this_object()),this_player()->name()+"˵����"+HIB+"����"+NOR+"������\n\n"+this_player()->name()+"�����油��һ���ơ�\n",this_player());
		 tell_object(this_player(),"��˵����"+HIB+"����"+NOR+"������\n\n�������油��һ���ơ�\n");
		 tell_object(this_player(),"��������һ��"+do_check_num(List[end..end+1],0)+"\n");
	      }	      
	      HU_F=1;
	      who["OutFlower"]+=temp;	      
	      str[i..i+1]=List[end..end+1];	      
	      end-=2;
	      i+=2;	      
	      continue;
	   }
	   else newstr=temp+newstr;
	}	
	who["Mj"]=newstr;
}
int do_check_Mj(string datastr,string str)
{
	int i,check=0;
 
	for(i=0; i<strlen(datastr); i+=2)	      
		if (datastr[i..i+1]==str) check++;

	return check;
}
string do_delete_Mj(string datastr,string str,int amount)//��ĳ��ȥ��
{
	int size=strlen(datastr),check;
	string temp="";
 
	for( ;size>=0; size-=2)
	{
//		size--;
		if (datastr[size..size+1]==str && amount!=0) amount--;
		else temp+=datastr[size..size+1];
	}
	size=strlen(temp);
	datastr=temp;
	temp="";
	for(; size>=0; size-=2)
	{
	      //size--;
		temp+=datastr[size..size+1];
	}
	return temp;
}
string sort_data(string str)
{
	int i = strlen(str),a,b,c,d;
 
	string newstr="",temp="";
	for (a=-1;a<i;a++){
	    a++;
	    for (b=a+2;b<i;b++){
		b++;
		c=do_check_num(str[a..a+1],1);
		d=do_check_num(str[b-1..b],1);
		if (c < d){
		   temp=str[a..a+1];
		   str[a..a+1]=str[b-1..b];
		   str[b-1..b]=temp;
		}
	    }
	}
	return str;
}
int do_look(string arg)
{
	int i,l;
	object me=this_player();
	string Mj="",p1o="",p2o="",p3o="",p4o="", str;
	mapping who;
 
	if (query_verb()==".")	arg="mj";
	if (query_verb()=="..") arg="chicken";
	if (query_verb()==".1") arg="1p";
	if (query_verb()==".2") arg="2p";
	if (query_verb()==".3") arg="3p";
	if (query_verb()==".4") arg="4p";
	if (query_verb()==".0") arg="all";
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	else return 0;
	if (who["Auto"]=="auto") l=1;
	if (arg=="1p"||arg=="2p"||arg=="3p"||arg=="4p"||arg=="all"||arg=="chicken"||arg=="end"||arg=="dump"||arg=="mj");
	else return 0;
	if (arg=="1p") who=P1Data;
	if (arg=="2p") who=P2Data;
	if (arg=="3p") who=P3Data;
	if (arg=="4p") who=P4Data;
	if (arg=="1p"||arg=="2p"||arg=="3p"||arg=="4p"){
	   i=0;
	   if (who["Show"]=="����") i=3;
	   if (who["Show"]=="color") i=5;
	   if (!Playing||check_id(me->query("id"),"player")==""||l==1){
	      if (who["OutGon"]!=""){
		 Mj+=who["Id"]+"�����ܵ����У�\n";
		 Mj+=show_mj(who["OutGon"],i+1);
	      }
	      Mj+=who["Id"]+"�����е����У�\n";
	      Mj+=show_mj(who["Mj"],i);
	   }
	   Mj+=who["Id"]+"����\����������У�\n";
	   Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
	   Mj+=who["Id"]+"��������ƣ�\n";
	   Mj+=show_mj(who["Dump"],2);
	}
	else if (arg=="mj") {
	   if (!Playing) return 0;
	   if (who["OutGon"]!=""){
	      Mj+="��İ��ܵ����У�\n";
	      Mj+=show_mj(who["OutGon"],1);
	   }
	   if (who["Show"]=="����") i=3;
	   if (who["Show"]=="color") i=5;
	   Mj+="�������������У�\n";
	   Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
	   Mj+="�����е����У�\n";
	   Mj+=show_mj(who["Mj"],i);
	   Mj+="����趨�У�";
	}else if (arg=="all") {
	      i=0;
	      if (who["Show"]=="����") i=3;
	      if (who["Show"]=="color") i=5;	      
	      tell_object(me, "������["+TIMES+"] ׯ�� "+HIY+present(NowPlayerId[0])->query("name")
	      	+"("+NowPlayerId[0]+")"+NOR+"\n" );
	      Mj+=HIG+"����  "+NOR+present(P1Data["Id"])->query("name")+"("+P1Data["Id"]+")"+"����\����������У�\n";	      
	      Mj+=show_mj(next_data(P1Data["Id"], 0, "allout"),i+1);	      
	      Mj+=HIG+"����  "+NOR+present(P2Data["Id"])->query("name")+"("+P2Data["Id"]+")"+"����\����������У�\n";
	      Mj+=show_mj(next_data(P2Data["Id"], 0, "allout"),i+1);	     
	      Mj+=HIG+"����  "+NOR+present(P3Data["Id"])->query("name")+"("+P3Data["Id"]+")"+"����\����������У�\n";
	      Mj+=show_mj(next_data(P3Data["Id"], 0, "allout"),i+1);					 
	      Mj+=HIG+"����  "+NOR+present(P4Data["Id"])->query("name")+"("+P4Data["Id"]+")"+"����\����������У�\n";
	      Mj+=show_mj(next_data(P4Data["Id"], 0, "allout"),i+1);	      
	}else if (arg=="chicken"){
		 if (Playing){
		    Mj=LookP+"��������ڴ���\n";
		    Mj+="��ʣ��"+sprintf("%d",(end-count-16-Goned)/2)+"ֻ�ƾ������ˡ�\n";
		    if (LastDump!="") Mj+=LastDumpId+"�ոմ����"+show_mj(LastDump,2)+"\n";
		    if (Count) Mj+=NowPlayerId[0]+"����ׯ"+chinese_number(Count)+"\n";
		    if (P1Data["Out"]=="" && P1Data["OutPon"]=="") p1o=HIY+"����"+NOR;
		    if (P2Data["Out"]=="" && P2Data["OutPon"]=="") p2o=HIY+"����"+NOR;
		    if (P3Data["Out"]=="" && P3Data["OutPon"]=="") p3o=HIY+"����"+NOR;
		    if (P4Data["Out"]=="" && P4Data["OutPon"]=="") p4o=HIY+"����"+NOR;
		    Mj+="1�������ǣ�"+NowPlayerId[0]+p1o+"\n2���ϼ��ǣ�"+NowPlayerId[1]+p2o+"\n";
		    Mj+="3�������ǣ�"+NowPlayerId[2]+p3o+"\n4�������ǣ�"+NowPlayerId[3]+p4o+"\n";
		 }
		 else if (NowPlayerId[0]!="") Mj=LookP+"���ڵ��˴���";
		 else Mj=LookP+"һֻ�齫�������˼���(addin)�ƾ֡�";
	}else if (arg=="end"){
	   Mj+="����"+chinese_number((end-count-16-Goned)/2)+"ֻ�ƾ�������\n";
	}else if (arg=="dump"){
	   Mj+=LastDumpId+"�ոմ����"+show_mj(LastDump,2)+"\n";
	}
	else return 0;
	if (arg=="mj"){
	  if (who["AutoTin"]!="") Mj+="����"+show_mj(who["AutoTin"],2)+"���Զ����ơ�";
	  if (who["AutoGon"]!="") Mj+="����"+show_mj(who["AutoGon"],2)+"���Զ�  �ơ�";
	  if (who["AutoPon"]!="") Mj+="����"+show_mj(who["AutoPon"],2)+"���Զ����ơ�";
	  if (who["Show"]=="����")    Mj+="��ʾ��ʽΪ���뷽ʽ��";
	  if (who["Show"]=="color")   Mj+="��ʾ��ʽΪ��ɫ��";
	  if (who["Auto"]=="auto")    Mj+="���趨�Զ����ơ�";
	  if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") Mj+="��û���κ��趨��\n";
	}
	printf("%s\n",Mj);
	return 1;
}
int do_help(string str)
{
	if (str=="setmj"){
write(@HELP
		       ��  ��  ��  ��
	    setmj ���õ����Զ�����  ������������ʽ������
--------------------------------------------------------------------
����1: setmj peng 1w    �趨���Զ���1w �����˴��һ��ʱ���Զ���һ��
       setmj gang 1w    �Զ���һ��
       setmj ting 1w    �Զ���һ��
����2: setmj show ����  �趨Ϊֻ��ʾ���롣
       setmj show color �趨Ϊ��ɫ��ʾ��
����3: setmj ting none  ȡ�����Զ������趨��
       setmj gang none
       setmj peng none
����4: setmj auto ting  �趨�Զ����ơ�
--------------------------------------------------------------------
HELP);
	return 1;
	}
	return 0;
}
int do_play()
{
write(@HELP
        ָ  ��        ��  ��                         ˵    ��
    ����������������������������������������������������������������
    �� sit       ----------                              �����ž� ��
    �� look      l mj��.���Լ���,l 1p��.1�����1����              ��
    �� l all��..��ȫ��,l end������l dump��               ����     ��
    �� mo        ���������Ͱ������������ƣ���������  ����     ��
    �� da        da <����>��                             ����     ��
    �� chi       chi <����1> <����2>��                   ����     ��
    �� peng      ----------                              ����     ��
    �� gang      gang �� gang <����>(������)��           ����     ��
    �� hu                                                ����     ��
    �� setmj     help setmj��                            �趨���� ��
    �� start     ----------                              �ƾֿ�ʼ ��
    �� restart   restart �� restart mj��                 ���¿�ʼ ��
    �� continue  ��NPC����ҳ��ƣ��������ʱ�ر����á�            ��
    �� top       top aip,top -p,top -w,top -h,top -d              ��
    �� top -l    ��ȫ��,-lw,-lh,-ld��                    ������   ��
    ����������������������������������������������������������������
HELP);
	return 1;
}
int do_rule()
{
write(@HELP
 
����ÿ�����е�̨�����ټ������õ�̨������̨��Ҫ�������ͣ�����
��ǹ������ս���ǿ۵���ʧ��̨�������������ȥ��
 
HELP);
	return 1;
}
int show_top(string str)
{
	int i,check,a,b,c,d,e;
	string *temp=({"","","","","",""});
	string show="";
	mixed *MjData;
 
	if (!str) str=this_player()->query("id");
	else if (str=="-lp"||str=="-pl"||str=="-l") str="all1";
	else if (str=="-lw"||str=="-wl") str="all2";
	else if (str=="-lh"||str=="-hl") str="all3";
	else if (str=="-ld"||str=="-dl") str="all4";
	if (file_size(MJ_DATA)==-1) return notify_fail("���ϵ�ûû���ҵ���\n");
	MjData=explode(read_file(MJ_DATA),",");
	if (str=="all1") e=2;
	else if (str=="all2") e=3;
	else if (str=="all3") e=4;
	else if (str=="all4") e=5;
	if (str=="all1"||str=="all2"||str=="all3"||str=="all4") str="all";
	if (str=="-p") e=2;
	else if (str=="-w") e=3;
	else if (str=="-h") e=4;
	else if (str=="-d") e=5;
	if (str=="all"||str=="-p"||str=="-w"||str=="-h"||str=="-d")
	{
		for (a=0;a<sizeof(MjData);a+=6)
		{
			for (b=a+6;b<sizeof(MjData);b+=6)
			{
				sscanf(MjData[a+e],"%d",c);
				sscanf(MjData[b+e],"%d",d);
				if (d > c)
				{
					for (i=0;i<6;i++)temp[i]=MjData[a+i];
					for (i=0;i<6;i++) MjData[a+i]=MjData[b+i];
					for (i=0;i<6;i++) MjData[b+i]=temp[i];
				}
			}
		}
	}
	show=HBWHT+"\n  ";
	for (i=0; i<34; i++) show+="[47m��";
	show+=HBWHT+"  \n";
	show+="  "+HBRED+"   Ӣ������   ��  ��������  ����������� ��ս�� ��������������ǹ����  "+HBWHT+"  \n";
	if (str=="all")
	{
		for (i=0; i<sizeof(MjData); i+=6)
		{
			show+="  "+HBRED;
			show+=sprintf("  %12s��%12s��%8s��%8s��%8s��%8s  ", MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
			show+=HBWHT+"  \n";
		}
	}
	else if (str=="-p"||str=="-w"||str=="-h"||str=="-d")
		{
			if (sizeof(MjData) < 60) d=sizeof(MjData);
			else d=60;
			for (i=0; i<d; i+=6)
			{
				show+="  "+HBRED;
				show+=sprintf("  %12s��%12s��%8s��%8s��%8s��%8s  ", MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
				show+=HBWHT+"  \n";
			}
		}
		else
		{
			for (i=0; i<sizeof(MjData); i+=6)
			{
				if (MjData[i]==str)
				{
					check=1;
					break;
				}
			}
			if (check==1)
			{
				show+="  "+HBRED;
				show+=sprintf("  %12s��%12s��%8s��%8s��%8s��%8s  ", MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
				show+=HBWHT+"  \n";
			}
			else return notify_fail("û������˵����ϡ�\n");
		}
	show+=HBWHT+"  ";
	for (i=0; i<34; i++) show+="[47m��";
	show+=HBWHT+"  "+NOR+"\n";
	printf("%s\n",show);
	return 1;
}
int set_mjdata(object me,int *winner)
{
	int i,check;
	string str="";
	mixed *MjData;
 
	if (!me||!winner) return 0;
	if (file_size(MJ_DATA)==-1);
	else
	{
		MjData=explode(read_file(MJ_DATA),",");
		for (i=0; i<sizeof(MjData); i+=6)
		{
			if (MjData[i]==me->query("id"))
			{
				check=1;
				break;
			}
		}
	}
	if (check==1)
	{
		MjData[i+2]=sprintf("%d",winner[0]);
		MjData[i+3]=sprintf("%d",winner[1]);
		MjData[i+4]=sprintf("%d",winner[2]);
		MjData[i+5]=sprintf("%d",winner[3]);
		for (i=0; i<sizeof(MjData); i++) str+=MjData[i]+",";
		write_file(MJ_DATA,str,1);
	}
	else
	{
		str=me->query("id")+",";
		str+=me->name()+",";
		str+=winner[0]+",";
		str+=winner[1]+",";
		str+=winner[2]+",";
		str+=winner[3]+",";
		write_file(MJ_DATA,str,0);
	}
	return 1;
}
int *get_mjdata(string Id)
{
	int i,check,*winner=({0,0,0,0});
	string str="";
	mixed *MjData;
 
	if (!Id) return 0;
	if (file_size(MJ_DATA)==-1) return 0;
	MjData=explode(read_file(MJ_DATA),",");
	for (i=0; i<sizeof(MjData); i+=6)
	{
		if (MjData[i]==Id)
		{
			check=1;
			break;
		}
	}
	if (check==1)
	{
		sscanf(MjData[i+2],"%d",winner[0]);
		sscanf(MjData[i+3],"%d",winner[1]);
		sscanf(MjData[i+4],"%d",winner[2]);
		sscanf(MjData[i+5],"%d",winner[3]);
	}
	return winner;
}
int get_tc(mapping who)
{
	int size,i,check;
	string str,tempW="",tempT="",tempS="",tempB="";
	str=who["Mj"]+who["Out"]+who["OutPon"]+who["OutGon"];
	//ׯ��
	if (NowPlayerId[0]==who["Id"]) Tc+="@1";
	//����&����
	if (who["Out"]==""&&who["OutPon"]==""&&Touched) Tc+="@l";
	else if (who["Out"]==""&&who["OutPon"]=="") Tc+="@4";
	else if (Touched) Tc+="@2";
	//ȫ����
	if (strlen(who["Mj"]) < 5) Tc+="@i";
	size=strlen(str);
	for(; size>=0; size-=2){
	      //size--;
	  if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
	  else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
	  else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
	  else tempB+=str[size..size+1];
	}
	//����
	if (Times/Play == 0 && NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"df")>2) Tc+="@e";
	else if (Times/Play == 0 && do_check_Mj(tempB,"df") > 2
	     ||  NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"df")>2) Tc+="@5";
	if (Times/Play == 1 &&NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"nf")>2) Tc+="@f";
	else if (Times/Play == 1 && do_check_Mj(tempB,"nf") > 2
	     ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"nf")>2) Tc+="@6";
	if (Times/Play == 2 &&NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"xf")>2) Tc+="@g";
	else if (Times/Play == 2 && do_check_Mj(tempB,"xf") > 2
	     ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"xf")>2) Tc+="@7";
	if (Times/Play == 3 && NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"bf")>2) Tc+="@h";
	else if (Times/Play == 3 && do_check_Mj(tempB,"bf") > 2
	     ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"bf")>2) Tc+="@8";
	//����
	if (sizeof(who["OutFlower"]) ==16) Tc+="@A";//���ɹ���
	else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) Tc+="@D";//����һ
	else if (do_check_Mj(who["OutFlower"],"h1")==1&&do_check_Mj(who["OutFlower"],"h2")==1
	&&  do_check_Mj(who["OutFlower"],"h3")==1&&do_check_Mj(who["OutFlower"],"h4")==1) Tc+="@B";//�����ﶬ
	else if (do_check_Mj(who["OutFlower"],"h5")==1&&do_check_Mj(who["OutFlower"],"h6")==1
	&&  do_check_Mj(who["OutFlower"],"h7")==1&&do_check_Mj(who["OutFlower"],"h8")==1) Tc+="@C";//÷������
	else if (NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"h1")==1
	||  NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"h5")==1
	||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"h2")==1
	||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"h6")==1
	||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"h3")==1
	||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"h7")==1
	||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"h4")==1
	||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"h8")==1) Tc+="@3";
	//��һɫ����һɫ
	if (tempW!=""&&tempT==""&&tempS==""&&tempB=="") Tc+="@q";
	else if (tempW==""&&tempT!=""&&tempS==""&&tempB=="") Tc+="@q";
	else if (tempW==""&&tempT==""&&tempS!=""&&tempB=="") Tc+="@q";
	else if (tempW==""&&tempT==""&&tempS==""&&tempB!="") Tc+="@r";
	//��һɫ
	if (tempW!=""&&tempT==""&&tempS==""&&tempB!="") Tc+="@n";
	else if (tempW==""&&tempT!=""&&tempS==""&&tempB!="") Tc+="@n";
	//��һɫ
	else if (tempW==""&&tempT==""&&tempS!=""&&tempB!=""){
	     if (do_check_Mj(tempB,"fa")==3&&sizeof(tempB)==6
	     ||  do_check_Mj(tempB,"fa")==2&&sizeof(tempB)==4
	     && do_check_Mj(tempS,"1s")==0&& do_check_Mj(tempS,"5s")==0
	     && do_check_Mj(tempS,"7s")==0&& do_check_Mj(tempS,"9s")==0) Tc+="@E";
	     else Tc+="@n";
	}
	//����Ԫ
	if (do_check_Mj(tempB,"hz") > 2
	&&  do_check_Mj(tempB,"fa") > 2
	&&  do_check_Mj(tempB,"ba") > 2) Tc+="@t";
	//С��Ԫ
	else if (do_check_Mj(tempB,"hz") > 1
	&&  do_check_Mj(tempB,"fa") > 1
	&&  do_check_Mj(tempB,"ba") > 1) Tc+="@o";
	else if (do_check_Mj(tempB,"hz") > 2) Tc+="@9";
	else if (do_check_Mj(tempB,"fa") > 2) Tc+="@0";
	else if (do_check_Mj(tempB,"ba") > 2) Tc+="@a";
	//����ϲ
	if (do_check_Mj(tempB,"df") > 2
	&&  do_check_Mj(tempB,"nf") > 2
	&&  do_check_Mj(tempB,"xf") > 2
	&&  do_check_Mj(tempB,"bf") > 2) Tc+="@v";
	//С��ϲ
	else if (do_check_Mj(tempB,"df") > 1
	&&  do_check_Mj(tempB,"nf") > 1
	&&  do_check_Mj(tempB,"xf") > 1
	&&  do_check_Mj(tempB,"bf") > 1) Tc+="@F";
 
	for (i=0;i<sizeof(str);i+=2){
	    if (str[i..i+1]=="xx") continue;
	    if (do_check_Mj(str,str[i..i+1])==3) check++;
	    else if (do_check_Mj(str,str[i..i+1])==4) check++;
	}
	//������
	
	if ( (sizeof(who["OutPon"])+K*6)>23){
	   if (who["Out"]==""&&who["OutPon"]==""&&do_check_Mj(Tc,"@p")==0) Tc+="@m@p";
	   else  Tc+="@m";
	}
	
	check=0;
	
	for (i=0;i<sizeof(str);i+=2)//�����û��һ��
		if (do_check_num(str[i..i+1],2)==1||do_check_num(str[i..i+1],2)==9) check++;
	
	//tell_object( present("wiman"), "check is"+check+" "+who["OutPon"]+" "+K+"\n");
	if (check!=0&&tempB!=""&&(check+strlen(tempB)/2>14)) Tc+="@I";//���۾�
	else if (tempB==""&&check==14) Tc+="@J";//���۾�
	
	//ƽ��
	
	//if (tempB==""&&who["OutFlower"]==""&&check==0&&sizeof(who["AutoTin"])>3) Tc+="@d";
	if (tempB==""&&who["OutPon"]==""&&K==0) Tc+="@d";//ƽ����Ҫ��û��ô���̰ɣ���
	
	//���۾�
	if( check==0 ) {//������һ��		
		for (i=0;i<sizeof(str);i+=2)
	    //if (do_check_num(str[i..i+1],1)!=1&&do_check_num(str[i..i+1],1)>8) check++;
			if (do_check_num(str[i..i+1],1)>27 && do_check_num(str[i..i+1],1)<35) check++;
		if(check==0) Tc+="@Z";
	}
	
	//�ӵ�����
	if (count==((end-13-(Goned*2))-2)&&Touched) Tc+="@b";
	//����
	if (count==((end-13-(Goned*2))-2)&&!Touched) Tc+="@c";
	//���
	if (LastDump==""&&count==(Play*2*13)+2) Tc+="@w";
	//�غ�&�˺�
	//printf("%d > %d\n",count,((Play*2*16)+(Play*2)));
	if (count < ((Play*2*13)+(Play*2))
	&&P1Data["Out"]==""&&P1Data["PonOut"]==""
	&&P2Data["Out"]==""&&P2Data["PonOut"]==""
	&&P3Data["Out"]==""&&P3Data["PonOut"]==""
	&&P4Data["Out"]==""&&P4Data["PonOut"]==""){
	   if (Touched) Tc+="@x";
	   else Tc+="@y";
	}
	return 1;
}
int ch(string str)
{
	object me=this_player();
	mapping who;
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (!str) return 0;
	write("�����"+who["Mj"]+"����"+str+" ok.\n");
	str=sort_data(str);
	who["Mj"]=str;
	return 1;
}

//�����ǻ�������ĺ���Ϊ��һ����Ϊ�����˻��Ծֶ��ӣ�����Ҳͨ����ѯ����ǵ����������һЩ���Ի��ĺ��������
//�����￪ʼ�����Ի��ĺ���
void dump_what( object me )
{
	mapping who;	
	int t,k,W,T,S,Sp;
	//string tempW="",tempT="",tempS="",tempB="", Mj;
	mapping Temp = ([ "tempW": "", "tempT": "", "tempS": "", "tempB": "" ]);	
	string Special="1w9w1s9s1t9tdfnfxfbfhzfaba"; 
	string str_out;
	int size,i;
		
	int pos;	//�ִ���λ��
	
	Temp["tempB"]="";
	Temp["tempW"]="";
	Temp["tempT"]="";
	Temp["tempS"]="";	
	
	who=next_data( me->query("id"), 0, "data");
	get_all_temps( Temp, who["Mj"] );
	str_out = Temp["tempW"]+Temp["tempT"]+Temp["tempS"];
	who["3Ps"] ="";
	who["3Es"] ="";
	who["2Ps"] ="";
	who["2Es1"] ="";
	who["2Es2"] ="";
	who["1s"] ="";
	
	who["H2Ps"] ="";
	who["H2Es1"] ="";
	who["H2Es2"] ="";
	who["H1s"] ="";
	
	switch( who["Attitude"] ) {		
//��������cheap�Ĵ򷨣��ܺ�����    
case "cheap" :    
//	tell_object( present("wiman"), "cheap�� "); //�����д����ʦ�������Ա���в��ԡ�
//	get_all_temps( Temp, who["Mj"] );
	if (Temp["tempB"]!="") filt_mj(Temp["tempB"], me);
	if (Temp["tempW"]!="") filt_mj(Temp["tempW"], me);
	if (Temp["tempT"]!="") filt_mj(Temp["tempT"], me);
	if (Temp["tempS"]!="") filt_mj(Temp["tempS"], me);
			break;
//������common�򷨣��е㽲��Ŷ��ƽ��������������һɫ���߶���
case "common" :	
	//tell_object( present("wiman"), "common�� ");
//ƽ��
	if( dump_pinhu( who, me, Temp ) ) break;	
//����������������
	if( dump_ponpon( who, me, Temp )) break;
//���������ǻ�һɫ
	if( dump_twocolor( (who["Out"]+who["OutGon"]+who["OutPon"]), (Temp["tempW"]+Temp["tempT"]+Temp["tempS"]), me, Temp ) ) {
		who["Hu_type"] = "twocolor";
		break;	
	}
	break;
case "goodboy" :
	//tell_object( present("wiman"), "goodboy�� ");//�����д����ʦ�������Ա���в��ԡ�
	//tell_object( present("wiman"), who["Out"]+who["OutGon"]+who["OutPon"]+"..." );
//��������һɫ
	if( dump_samecolor( (who["Out"]+who["OutGon"]+who["OutPon"]), who["Mj"], me) ) { 
		who["Hu_type"] = "samecolor";
		break;
	}
//���������ǻ�һɫ
	else if( dump_twocolor( (who["Out"]+who["OutGon"]+who["OutPon"]), str_out, me, Temp ) ) {
		who["Hu_type"] = "twocolor";
		break;	
	}
//����������������
	if( dump_ponpon( who, me, Temp)) break;
//ƽ��
	if( dump_pinhu( who, me, Temp ) ) break;
	
	
// ������Ĭ�ϵĴ�	
	default :
		//tell_object( present("wiman"), "default�� ");
		who["Hu_type"] = "";
		if (Temp["tempB"]!="") filt_mj(Temp["tempB"], me);
		if (Temp["tempW"]!="") filt_mj(Temp["tempW"], me);
		if (Temp["tempT"]!="") filt_mj(Temp["tempT"], me);
		if (Temp["tempS"]!="") filt_mj(Temp["tempS"], me);
	}
	
	//tell_object( present("wiman"), "������ ");	
	if( who["1s"]!="" ){//������ɢ�Ƶ����		      	
		
		do_dump( find_mj(who["1s"], who["Mj"]), me);
		return;
	}
	else if(who["2Es2"]!="" && who["Hu_type"]!="pinhu"){//�����Ǽ���Ƶ��������1w3w, 4t6t, 7s9s�ȣ�		
		do_dump( find_mj(who["2Es2"], who["Mj"]), me);
		return;
	}
	else if(who["2Es1"]!="" && who["Hu_type"]!="pinhu"){//���������������Ƶ��������1w2w, 4t5t, 7s8s�ȣ�
		do_dump( find_mj(who["2Es1"], who["Mj"]), me);
		return;
	}
	else if(who["2Ps"]!="" && who["Hu_type"]!="ponpon" 
		&& do_check_win(who["Mj"])!=1){//�����Ƕ��Ƶ��������1w1w, 4t4t, 7s7s��)
		//tell_object(present("wiman"), /*who["2Ps"]+*/"dump 2Ps?\n");
		do_dump( find_mj(who["2Ps"], who["Mj"]), me);
		return;
	}
	else if( who["3Es"]!="" && who["Hu_type"]!="pinhu" && do_check_win(who["Mj"])!=1) {
		//tell_object(present("wiman"), " 3Es!=0?\n");
		do_dump(find_mj( who["3Es"], who["Mj"]), me);return;
	}
	else if( who["3Ps"]!="" && sizeof(who["3Ps"])>5 && who["Hu_type"]!="ponpon" && do_check_win(who["Mj"])!=1) {
		do_dump(find_mj( who["3Ps"], who["Mj"]), me);return;
	}
	else if(do_check_win(who["Mj"])==1 && NO_HU!=1 ){//������������û�г��֣��Ƿ�Ӧ�ú������أ�����
		//tell_object(present("wiman"), NO_HU+" may i win?\n");
		call_out( "do_win", DELAY, List[count-2..count-1], me);
		return;
	}
 	//tell_object(present("wiman"), " dump random?\n");
 	do_dump(find_mj( who["Mj"], who["Mj"]), me);
	return;
}

int get_attitudes(mapping who)
{	//�ӡ�ƽ��������ͷ���߶��ӡ�����������һɫ������ͷ��С��ϲ��С��Ԫ����һɫ����һɫ������Ԫ������ϲ��
	//��һɫ��ʮ���ۡ���ѡ��������ʱֻ������
	int i;
	i = random(100);
	if( i<40 ) { who["Attitude"] = "cheap"; who["Hu_type"] = ""; }
	else if( i<80 ) { who["Attitude"] = "common"; who["Hu_type"] = ""; }
	else if( i<100 ) { who["Attitude"] = "goodboy"; who["Hu_type"] = ""; }
	//else if( i<100 ) who["Attitude"] = "crazy";
	return 1;
}

int do_pause( object me )
{
	if(!me) me = this_player();
	if(!PAUSE) {
		PAUSE = 1;		//��ͣ
		//remove_call_out( "do_touch");		
		//tell_object(me," "+HIY+"���ж�ʮ���ʱ�俼�ǡ���"+NOR+"\n");	
		//tell_room( environment(me), me->query("id")+"��У�����һ�ȣ�����\n", me );		
		call_out( "undo_pause", 20, me);
	}
		
	return 1;
}

int undo_pause(object me)
{
	//string str;
	if(PAUSE == 0) return 1;
	else PAUSE = 0;		//ȡ����ͣ
	
	tell_room( environment(this_object()), this_object()->query("name")+"˵��������Ҿ�������һЩ��\n" );
	
	//str = NowPlayerId[NowPlayer];
	if( !userp(next_data(me->query("id"), 1, "player")) )
		do_touch( 0, next_data( me->query("id"), 1, "player") );
		//do_touch( 0, next_data(str, 0, "player") );
	return 1;
}

//NPC���ж�
int npc_action( object me )
{
	string str, str1, str2, str3;
	int i, num1, num2, num3;
	object ob;
	mapping who;
	
	for(i=0; i<3; i++) {
		//�Ժ�
		who = next_data(me->query("id"), i, "data");
		str = next_data(me->query("id"), i, "Mj");		
		who["Mj"] += LastDump;
		who["Mj"] = sort_data(who["Mj"]);
		ob = next_data(me->query("id"), i, "player");
		//tell_object(present("wiman"), ob->query("name")+ "����");	
				
		if( do_check_win(who["Mj"]) ) {			
			if( !userp(ob) ){
				if(who["Attitude"]=="cheap") {
					PAUSE = 1;
					who["Mj"] = str;
					do_win( 0, ob );
					return 1; }
				else if(who["Attitude"]=="common") {
					if(get_times(who)>2) {						
						//PAUSE = 1;
						who["Mj"] = str;
						do_win( 0, ob );
						return 1; }
					else if( random((end-count-16-Goned)/2)<30 ) {						
						who["Mj"] = str;
						do_win( 0, ob );
						return 1; }
				}
				else if(who["Attitude"]=="goodboy"){
					if(get_times(who)>3) {						
						//PAUSE = 1;
						who["Mj"] = str;
						do_win( 0, ob );
						return 1; }
					else if( random((end-count-16-Goned)/2)<20 ) {
						who["Mj"] = str;
						do_win( 0, ob );
						return 1; }
				}
			}
			else {				
				tell_object(ob, show_mj(LastDump, 6) );
				tell_object(ob, show_mj(str, 6) );
				tell_object(ob, "�Ƿ���������"+ do_check_num(LastDump, 0)+"����������ǣ������룺hu/peng/gang��\n�����������continue\n");
				PAUSE = 2;	//��ʱ��Ūͣ����ֹ��Ҷ�սʱ��������
				who["Pause"] = "yes";
				who["Mj"] = str;				
				return 1;
			}
		}
		who["Mj"] = str;
		//����
		//tell_object(present("wiman"), "���� ");
		str = who["2Ps"];
		if( !userp(ob) ) {
			/*if( do_check_Mj(str, LastDump)>1 ) {
				//PAUSE = 1;
				if( do_pon( LastDump, ob ) )
				return 1;
			}*/
			if( who["Hu_type"]=="twocolor" || who["Hu_type"]=="samecolor" ) {
				str = who["H2Ps"];
				if( do_check_Mj(str, LastDump)>1 ){
					//PAUSE = 1;
					if(do_pon( LastDump, ob )) return 1;
				}
			}
			else if( who["Hu_type"]!="pinhu") {
				if( do_check_Mj(str, LastDump)>1 ){
					//PAUSE = 1;
					if(do_pon( LastDump, ob )) return 1;
				}			
			}      		
		}
		else {	//��ҵ����Ӧ�ð����˸��Ƶġ�
			if( do_check_Mj(next_data(me->query("id"), i, "Mj"), LastDump)>2 ){
				tell_object(ob, "����������ƣ�\n"+show_mj(next_data(me->query("id"), i, "Mj"), 6) );
				PAUSE = 2;	//��ʱ��Ūͣ����ֹ��Ҷ�սʱ��������
				tell_object(ob, "�Ƿ������"+ do_check_num(LastDump, 0)+"����������ǣ������룺peng/gang��\n�����������continue\n");
				who["Pause"] = "yes";				
				return 1;
			}
			else if( do_check_Mj(next_data(me->query("id"), i, "Mj"), LastDump)>1 ){
				tell_object(ob, "����������ƣ�\n"+show_mj(next_data(me->query("id"), i, "Mj"), 6) );
				PAUSE = 2;	//��ʱ��Ūͣ����ֹ��Ҷ�սʱ��������
				tell_object(ob, "�Ƿ���"+ do_check_num(LastDump, 0)+"����������ǣ������룺peng��\n�����������continue\n");
				who["Pause"] = "yes";				
				return 1;
			}
       		}
	//}
	
		//NPC��ʱֻ��ܱ��ƣ���Ϊ�����������׶��˺�·����
		//tell_object(present("wiman"), "���� ");	
		if( !userp(ob) ) {
			str = who["3Ps"];
			if( do_check_Mj(str, LastDump)==3 && do_check_num(LastDump, 1)>27 && strlen(who["Mj"])<26){
				//����ֱ�͸�
				//PAUSE = 1;
				if( do_gon( LastDump, ob ) ) return 1;
			}			
		}		
	}
	
	//����
	who = next_data(me->query("id"), 0, "data"); 
	//str = "";
	
       	if(!userp(me) /*&& str!="" */ && who["Hu_type"]!="ponpon" ){
       		if( who["Hu_type"]!="samecolor"||who["Hu_type"]!="twocolor" ) str = who["2Es1"];
		else str = who["H2Es1"];
		i = sizeof(str);		
		//tell_object(present("wiman"), me->query("name")+"����1 ");
		if( do_check_Mj(str, next_mj(LastDump, 1))>0&&do_check_Mj(str, next_mj(LastDump, 2))>0 )  //|| 
			if( do_eat( next_mj(LastDump, 1)+" "+next_mj(LastDump, 2), me) ) return 1;
		if(do_check_Mj(str, next_mj(LastDump, -2))>0&&do_check_Mj(str, next_mj(LastDump, -1))>0 )
			if( do_eat( next_mj(LastDump, -1)+" "+next_mj(LastDump, -2), me) ) return 1;
		/*while(i>0) {
			i-=4;
			sscanf(str[i..i+1],"%d%s",num1,str1);			
			sscanf( LastDump, "%d%s", num3, str3);
			if( str1 == str3){				
				if( num3 == num1-1 || num3==num1+2){					
					do_eat( str[i..i+1]+" "+str[i+2..i+3], me );
					return 1;
				}
			}
		}*/
		//tell_object(present("wiman"), "����2 ");
		if( who["Hu_type"]!="samecolor"||who["Hu_type"]!="twocolor" ) str = who["2Es2"];
		else str = who["H2Es2"];
		//tell_object(present("wiman"), str+" ");
		if( do_check_Mj(str, next_mj(LastDump, 1))>0&&do_check_Mj(str, next_mj(LastDump, -1))>0 ) //|| 
			if( do_eat( next_mj(LastDump, 1)+" "+next_mj(LastDump, -1), me) ) return 1;
		//i = sizeof(str); 	
		/*while(i>0) {
			i-=4;
			sscanf(str[i..i+1],"%d%s",num1,str1);			
			sscanf( LastDump, "%d%s", num3, str3);
			if( str1 == str3){				
				if( num3 == num1+1 ){					
					do_eat( str[i..i+1]+" "+str[i+2..i+3], me );
					return 1;
				}
			}
		}*/
	}
	
	
	if( userp(me) ) {
		str = next_data(me->query("id"), 0, "Mj");
		if( (do_check_Mj(str, next_mj(LastDump, 1))>0&&do_check_Mj(str, next_mj(LastDump, 2))>0) || 
			(do_check_Mj(str, next_mj(LastDump, 1))>0&&do_check_Mj(str, next_mj(LastDump, -1))>0) || 
			 	(do_check_Mj(str, next_mj(LastDump, -1))>0&&do_check_Mj(str, next_mj(LastDump, -2))>0) )
		{
			tell_object( me, "�������"+HIR+"chi"+NOR+"�����ƣ���\n");
			tell_object(me, "����������ƣ�\n" +show_mj( str, 6) );
		}
	//		return 1;
	}
	//tell_object(present("wiman"), "no action\n");
	if(!userp(me)) do_touch(0, me);
	return 1;
}

int do_continue(object me)
{
	object ob;
	mapping who;
	if(!me) me = this_player();
	who = next_data( me->query("id"), 0, "data");
	ob = present(NowPlayerId[NowPlayer]);
	//tell_object( present("wiman"), NowPlayerId[NowPlayer]+"-->��ǰ�����ߡ�\n");	
	//if(!Touched) {
		if( !userp(ob)&&PAUSE!=2 ) {
			//PAUSE = 0;do_touch( 0, ob );return 1;
			PAUSE = 0;
			//if( npc_action(ob) ) return 1;
			do_touch( 0, ob );return 1;
		}
		if( who["Pause"]=="yes" ) { 
			PAUSE =0; who["Pause"] = "";
			if(!userp(ob)) do_touch( 0, ob );
			else tell_room( environment(me), me->query("id")+"��"+ob->query("id")+"˵����������������\n");
		}
		if( me==present(NowPlayerId[NowPlayer])&&PAUSE!=2 ) { 
			PAUSE =0; 
			if(!Touched) do_touch(0, me);
			else tell_room( environment(me), me->query("id")+"˵�����𼱱𼱣�\n");
		}
		else tell_room( environment(me), me->query("id")+"��"+ob->query("id")+"˵����������������\n");
	//}
	//else {
	//	if( !userp(ob) ) dump_what( present(ob) );
	//	else tell_room( environment(me), me->query("id")+"��"+ob->query("id")+"˵���������������\n");
	//}
	return 1;
}

//�����Ƕ��齫���нṹ������ĺ���
string filt_mj(string strW, object me)
{
	int i,j,check;
	int k,t;
	int A,B,C,D,E,F;
	mapping who;
	
	who = next_data( me->query("id"), 0, "data" );
		
	if (do_check_num(strW[0..1],1) > 27){
	   for (i=0;i<strlen(strW);i+=2){//
	       check=do_check_Mj(strW,strW[i..i+1]);
	       if (check==1){
	       		who["1s"]+= strW[i..i+1];
	       		strW=do_delete_Mj(strW,strW[i..i+1],1);
	       		i=-2;
	       }
	       else if (check==2){
		       who["2Ps"]+= strW[i..i+1];
		       who["2Ps"]+= strW[i..i+1];
		       strW=do_delete_Mj(strW,strW[i..i+1],2);
		       //t++;
		       i=-2;
	       }else if (check==3){
			who["3Ps"]+= strW[i..i+1];
			who["3Ps"]+= strW[i..i+1];
			who["3Ps"]+= strW[i..i+1];
			strW=do_delete_Mj(strW,strW[i..i+1],3);
			//K++;
			i=-2;
	       }
	       else if(check == 4 ){
	       		do_gon( strW[i..i+1], me);
	       		return "";
	       }
	   }
	   return "";
	}

	for (i=0;i<sizeof(strW);i+=2) {//��˳��ɾ��
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		C=do_check_num(strW[i+4..i+5],2);
		D=do_check_num(strW[i+6..i+7],2);
		E=do_check_num(strW[i+8..i+9],2);
		F=do_check_num(strW[i+10..i+11],2);       	

		if (sizeof(strW) > 11 &&do_check_num(strW[i-2..i-1],2)!=A&&A+1==B&&B==C&&C+1==D&&D==E&&E+1==F
	   	||do_check_num(strW[i-2..i-1],2)!=A&&A==B&&B+1==C&&C==D&&D+1==E&&E==F){
	   		
	      		for (j=0;j<6;j++) {  //ɾ��˳��1 22 33 4 && 22 33 44
		  		strW=do_delete_Mj(strW,strW[i..i+1],1);
		  		who["3Es"] += strW[i..i+1];
	      		}
	   	i=-2;
		}
		else if (A+1==B&&B==C&&C==D&&D==E&&E+1==F){
	      		for (j=0;j<2;j++) {  //ɾ��˳��1 2 2 2 2 3
	      		who["3Es"] += strW[i..i+1];
		  	strW=do_delete_Mj(strW,strW[i..i+1],1);
	      		}
	      		who["3Es"] += strW[i+6..i+7];
	      		strW=do_delete_Mj(strW,strW[i+6..i+7],1);
	   		i=-2;
	   	}
		else if (sizeof(strW) > 9 && A+1==B&&B==C&&C==D&&D+1==E){
	      				//ɾ��˳��12223�е�1 2 3
		  	who["3Es"] += strW[i..i+1];
		  	who["3Es"] += strW[i..i+1];
		  	who["3Es"] += strW[i+4..i+5];
		  	strW=do_delete_Mj(strW,strW[i..i+1],1);
		  	strW=do_delete_Mj(strW,strW[i..i+1],1);
		  	strW=do_delete_Mj(strW,strW[i+4..i+5],1);
	   		i=-2;
		}
		else if (sizeof(strW) > 9 && A==B&&B+1==C&&C+1==D&&D+1==E){
	     		for (j=0;j<3;j++) {   //ɾ��˳��11234�е�2 3 4
	     			who["3Es"] += strW[i+4..i+5];
		 		strW=do_delete_Mj(strW,strW[i+4..i+5],1);
	     		}
	   		i=-2;
		}
		else if (sizeof(strW) > 5 && A+1==B&&B+1==C){
	     		for (j=0;j<3;j++) {   //ɾ��˳��123�е�1 2 3
		 		who["3Es"] += strW[i..i+1];
		 		strW=do_delete_Mj(strW,strW[i..i+1],1);
	     		}
	   		i=-2;
		}		
	}	
	if (sizeof(strW) > 5){
		for (i=0;i<sizeof(strW);i+=2) {//�ٰѿ�ɾ��
			check=do_check_Mj(strW,strW[i..i+1]);
			if (check==3){
				//K++;
				who["3Ps"] += strW[i..i+1];
				who["3Ps"] += strW[i..i+1];
				who["3Ps"] += strW[i..i+1];
				strW=do_delete_Mj(strW,strW[i..i+1],3);				
				i=-2;
			}
		}
	}
	for (i=0;i<sizeof(strW);i+=2) {//�ٰѶ�ɾ��
		check=do_check_Mj(strW,strW[i..i+1]);
		if (check==2){
			t++;
			who["2Ps"] += strW[i..i+1];
			who["2Ps"] += strW[i..i+1];
			strW=do_delete_Mj(strW,strW[i..i+1],2);
			i=-2;
		}
	}
	for (i=0;i<sizeof(strW);i+=2) {//�ٰ�2������˳��ɾ��
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		if( A==B-1 ){
			if( do_check_Mj(destop+who["Mj"], next_mj(strW[i..i+1], -1) )!=4 || 
				do_check_Mj(destop+who["Mj"], next_mj(strW[i+2..i+3], 1) )!=4 ) {
				who["2Es1"]+=strW[i..i+1];			
				who["2Es1"]+=strW[i+2..i+3];
			} else {				//������ߵĶ��Ѿ�������
				who["1s"]+=strW[i..i+1];	//��Ҳ�ͱ��ɢ�ƿ�
				who["1s"]+=strW[i+2..i+3];
			}			
			strW=do_delete_Mj(strW, strW[i..i+1], 1);
			strW=do_delete_Mj(strW, strW[i..i+1], 1);			
			i=-2;
		}
	}
	for (i=0;i<sizeof(strW);i+=2) {//�ٰ�2�����˳��ɾ��
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		if( A==B-2 ){
			if( do_check_Mj(destop+who["Mj"], next_mj(strW[i..i+1], 1) )!=4 ) {//����м���Ѿ�������
				who["2Es2"]+=strW[i..i+1];			//��Ҳ�ͱ��ɢ�ƿ�
				who["2Es2"]+=strW[i+2..i+3];
			} else {
				who["1s"]+=strW[i..i+1];
				who["1s"]+=strW[i+2..i+3];
			}
			strW=do_delete_Mj(strW, strW[i..i+1], 1);
			strW=do_delete_Mj(strW, strW[i..i+1], 1);
			i=-2;
		}
	}
	who["1s"] += strW;

	   //tell_object( present("wiman"), who["1s"]+" "+who["2Ps"]+" "+who["2Es1"]+" "+"filt���\n");
	   
	   if (strW!="") return strW;
	   return "";
}

int filt_hu_color(string strW, object me)
{
	int i,j,check;
	int k,t;
	int A,B,C,D,E,F;
	mapping who;
	
	who = next_data( me->query("id"), 0, "data" );
		
	if (do_check_num(strW[0..1],1) > 27){
	   for (i=0;i<strlen(strW);i+=2){//
	       check=do_check_Mj(strW,strW[i..i+1]);
	       if (check==1){
	       		who["H1s"]+= strW[i..i+1];
	       		strW=do_delete_Mj(strW,strW[i..i+1],1);
	       		i=-2;
	       }
	       else if (check==2){
		       who["H2Ps"]+= strW[i..i+1];
		       who["H2Ps"]+= strW[i..i+1];
		       strW=do_delete_Mj(strW,strW[i..i+1],2);
		       //t++;
		       i=-2;
	       }else if (check==3){
			//who["3Ps"]+= strW[i..i+1];
			//who["3Ps"]+= strW[i..i+1];
			//who["3Ps"]+= strW[i..i+1];
			strW=do_delete_Mj(strW,strW[i..i+1],3);
			//K++;
			i=-2;
	       }
	       else if(check == 4 ){
	       		do_gon( strW[i..i+1], me);
	       		return 1;
	       }
	   }
	   return 1;
	}

	for (i=0;i<sizeof(strW);i+=2) {//��˳��ɾ��
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		C=do_check_num(strW[i+4..i+5],2);
		D=do_check_num(strW[i+6..i+7],2);
		E=do_check_num(strW[i+8..i+9],2);
		F=do_check_num(strW[i+10..i+11],2);       	

		if (sizeof(strW) > 11 &&do_check_num(strW[i-2..i-1],2)!=A&&A+1==B&&B==C&&C+1==D&&D==E&&E+1==F
	   	||do_check_num(strW[i-2..i-1],2)!=A&&A==B&&B+1==C&&C==D&&D+1==E&&E==F){
	   		
	      		for (j=0;j<6;j++) {  //ɾ��˳��1 22 33 4 && 22 33 44
		  		strW=do_delete_Mj(strW,strW[i..i+1],1);
		  		//who["3Es"] += strW[i..i+1];
	      		}
	   	i=-2;
		}
		else if (A+1==B&&B==C&&C==D&&D==E&&E+1==F){
	      		for (j=0;j<2;j++) {  //ɾ��˳��1 2 2 2 2 3
	      		//who["3Es"] += strW[i..i+1];
		  	strW=do_delete_Mj(strW,strW[i..i+1],1);
	      		}
	      		//who["3Es"] += strW[i+6..i+7];
	      		strW=do_delete_Mj(strW,strW[i+6..i+7],1);
	   		i=-2;
	   	}
		else if (sizeof(strW) > 9 && A+1==B&&B==C&&C==D&&D+1==E){
	      				//ɾ��˳��12223�е�1 2 3
		  	//who["3Es"] += strW[i..i+1];
		  	//who["3Es"] += strW[i..i+1];
		  	//who["3Es"] += strW[i+4..i+5];
		  	strW=do_delete_Mj(strW,strW[i..i+1],1);
		  	strW=do_delete_Mj(strW,strW[i..i+1],1);
		  	strW=do_delete_Mj(strW,strW[i+4..i+5],1);
	   		i=-2;
		}
		else if (sizeof(strW) > 9 && A==B&&B+1==C&&C+1==D&&D+1==E){
	     		for (j=0;j<3;j++) {   //ɾ��˳��11234�е�2 3 4
	     			//who["3Es"] += strW[i+4..i+5];
		 		strW=do_delete_Mj(strW,strW[i+4..i+5],1);
	     		}
	   		i=-2;
		}
		else if (sizeof(strW) > 5 && A+1==B&&B+1==C){
	     		for (j=0;j<3;j++) {   //ɾ��˳��123�е�1 2 3
		 		//who["3Es"] += strW[i..i+1];
		 		strW=do_delete_Mj(strW,strW[i..i+1],1);
	     		}
	   		i=-2;
		}		
	}	
	if (sizeof(strW) > 5){
		for (i=0;i<sizeof(strW);i+=2) {//�ٰѿ�ɾ��
			check=do_check_Mj(strW,strW[i..i+1]);
			if (check==3){
				//K++;
				//who["3Ps"] += strW[i..i+1];
				//who["3Ps"] += strW[i..i+1];
				//who["3Ps"] += strW[i..i+1];
				strW=do_delete_Mj(strW,strW[i..i+1],3);				
				i=-2;
			}
		}
	}
	for (i=0;i<sizeof(strW);i+=2) {//�ٰѶ�ɾ��
		check=do_check_Mj(strW,strW[i..i+1]);
		if (check==2){
			t++;
			who["H2Ps"] += strW[i..i+1];
			who["H2Ps"] += strW[i..i+1];
			strW=do_delete_Mj(strW,strW[i..i+1],2);
			i=-2;
		}
	}
	for (i=0;i<sizeof(strW);i+=2) {//�ٰ�2������˳��ɾ��
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		if( A==B-1 ){
			if( do_check_Mj(destop+who["Mj"], next_mj(strW[i..i+1], -1) )!=4 || 
				do_check_Mj(destop+who["Mj"], next_mj(strW[i+2..i+3], 1) )!=4 ) {
				who["H2Es1"]+=strW[i..i+1];			
				who["H2Es1"]+=strW[i+2..i+3];
			} else {				//������ߵĶ��Ѿ�������
				who["H1s"]+=strW[i..i+1];	//��Ҳ�ͱ��ɢ�ƿ�
				who["H1s"]+=strW[i+2..i+3];
			}			
			strW=do_delete_Mj(strW, strW[i..i+1], 1);
			strW=do_delete_Mj(strW, strW[i..i+1], 1);			
			i=-2;
		}
	}
	for (i=0;i<sizeof(strW);i+=2) {//�ٰ�2�����˳��ɾ��
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		if( A==B-2 ){
			if( do_check_Mj(destop+who["Mj"], next_mj(strW[i..i+1], 1) )!=4 ) {//����м���Ѿ�������
				who["H2Es2"]+=strW[i..i+1];			//��Ҳ�ͱ��ɢ�ƿ�
				who["H2Es2"]+=strW[i+2..i+3];
			} else {
				who["H1s"]+=strW[i..i+1];
				who["H1s"]+=strW[i+2..i+3];
			}
			strW=do_delete_Mj(strW, strW[i..i+1], 1);
			strW=do_delete_Mj(strW, strW[i..i+1], 1);
			i=-2;
		}
	}
	who["H1s"] += strW;

	   //tell_object( present("wiman"), "filt���\n");
	   
	   if (strW!="") return 1;
	   return 0;
}


//��������Լ�����������������
string find_mj(string str, string mj)
{
	string str4="", str3="", str2="", str1="", str0="";
	int i, num, pos;
	
	for(i=0; i<sizeof(str); i+=2){
		
		num = do_check_Mj(destop ,str[i..i+1])+ do_check_Mj(mj ,str[i..i+1]);
		switch (num) {
			case 4 : str4+=str[i..i+1];break;
			case 3 : str3+=str[i..i+1];break;
			case 2 : str2+=str[i..i+1];break;
			case 1 : str1+=str[i..i+1];break;
			default : str0+=str[i..i+1];
		}
	}
	//tell_object(present("wiman"), str1+str2+str3+str4+" find_mj here?\n");
	if(str4!="") str0 = str4;
	else if(str3!="") str0 = str3;
	else if(str2!="") str0 = str2;
	else if(str1!="") str0 = str1;
	
	for(i=0; i<sizeof(str0); i+=2){			
			if(do_check_num(str0[i..i+1],1)>27){				
				pos=i;break;
			} else if(do_check_num(str0[i..i+1], 2)==1||do_check_num(str0[i..i+1],2)==9){
				pos=i;break;
			} else pos = 2*random(sizeof(str0)/2);
		}
	//tell_object(present("wiman"), " find" +" the "+str0[pos..pos+1]+"  ");
	return str0[pos..pos+1];
}

mixed next_data( string str, int i, string key )
{
	int num, j;
	mapping who;
	
	if( i<0 ) i=4+i;
	for(j=0; j<4; j++) if(NowPlayerId[j]==str) num = j;
	num+=i;
	num%=4;
	if( P1Data["Id"]==NowPlayerId[num] ) who = P1Data;
	if( P2Data["Id"]==NowPlayerId[num] ) who = P2Data;
	if( P3Data["Id"]==NowPlayerId[num] ) who = P3Data;
	if( P4Data["Id"]==NowPlayerId[num] ) who = P4Data;
	
	switch( key ) {		
		case "data" :	return who;break;			
		case "id" :	return who["Id"];break;
		case "Mj" :	return who["Mj"];break;
		case "player" :	return present(who["Id"]);break;
		case "2Ps" :	return who["2Ps"];break;
		case "2Es1" :	return who["2Es1"];break;
		case "2Es2" :	return who["2Es2"];break;
		case "allout" :	return who["Dump"]+"zz"+who["Out"]+who["OutPon"]+who["OutFlower"];
	}
	return 0;		
}

string next_mj( string mj, int i )//�����Ȼ����next_data������Ҳ����next_mj
{
	string str;
	int num;
	
	if(sizeof(mj)>2) return "XX";	
	if( sscanf( mj, "%d%s", num, str )!=2 ) return "XX";
	num += i;
	if( num>9 || num<1 ) return "XX";
	else return sprintf( "%d%s", num, str );
}

int get_times( mapping who )
{
	int i, j = 0;
//��̨///////////////////////////////////
	mixed MjT = ([
"@1" : ({ "ׯ��", 1 }),"@2" : ({ "����", 1 }),"@3" : ({ "����", 1 }),"@4" : ({ "����", 1 }),"@Z" : ({ "���۾�", 1 }),
"@5" : ({ "����", 1 }),"@6" : ({ "�Ϸ�", 1 }),"@7" : ({ "����", 1 }),"@8" : ({ "����", 1 }),
"@9" : ({ "����", 1 }),"@0" : ({ "�෢", 1 }),"@a" : ({ "�װ�", 1 }),"@G" : ({ "һا��", 1 }),
"@b" : ({ "��������", 1 }),"@c" : ({ "��������", 1 }),"@d" : ({ "ƽ��", 2 }),"@e" : ({ "���綫", 2 }),
"@f" : ({ "�Ϸ���", 2 }),"@g" : ({ "������", 2 }),"@h" : ({ "���籱", 2 }),"@i" : ({ "ȫ����", 2 }),
"@j" : ({ "������", 2 }),"@H" : ({ "��ا��", 2 }),"@k" : ({ "������", 2 }),"@B" : ({ "�����ﶬ", 2 }),
"@C" : ({ "÷������", 2 }),"@l" : ({ "��������", 3 }),"@m" : ({ "������", 4 }),"@n" : ({ "��һɫ", 4 }),
"@o" : ({ "С��Ԫ", 4 }),"@p" : ({ "�İ���", 6 }),"@q" : ({ "��һɫ", 8 }),"@r" : ({ "��һɫ", 8 }),
"@s" : ({ "�߶���", 8 }),"@t" : ({ "����Ԫ", 8 }),"@u" : ({ "�尵��", 8 }),"@F" : ({ "С��ϲ", 8 }),
"@D" : ({ "����һ", 8 }),"@E" : ({ "��һɫ", 16 }),"@v" : ({ "����ϲ", 16 }),"@w" : ({ "���", 16 }),
"@x" : ({ "�غ�", 16 }),"@y" : ({ "�˺�", 16 }),"@z" : ({ "��ʿ��˫", 16 }),"@A" : ({ "���ɹ���", 16 }),
"@J" : ({ "����ͷ", 8 }),"@I" : ({ "����ͷ", 4 }),
]);//H
	   do_check_win(who["Mj"]);
	   Tc="";
	   get_tc(who);
////////////////	   
	   for (i=0;i<sizeof(Tc);i+=2){	      
	      j+=MjT[Tc[i..i+1]][1];
	   }
	   if (Count){	      
	      j+=Count*2;
	   }
	return j;
}

//��һɫ��
int dump_samecolor( string str_out, string str_mj, object me)//, mapping Temps )
{
			
	mapping Temps = ([ "tempW": "", "tempT": "", "tempS": "", "tempB": "" ]);
	
	int size;
	if( str_out!="" ) get_all_temps( Temps, str_out );
	if( strlen(Temps["tempT"]+Temps["tempB"]+Temps["tempS"])==0 || str_out=="" ) {     	
		size = strlen(Temps["tempW"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempW"])>sizeof(str_mj)/2 || size>12) {		
		//tell_object( present("wiman"), "����� ");
			if (Temps["tempT"]!="") filt_mj(Temps["tempT"], me);
			if (Temps["tempS"]!="") { //tell_object( present("wiman"), "hxhxhxhxhx\n");
				filt_mj(Temps["tempS"], me); }
			if (Temps["tempB"]!="") filt_mj(Temps["tempB"], me);
			if( Temps["tempT"]==""&&Temps["tempS"]==""&&Temps["tempB"]=="")
				filt_mj(Temps["tempW"], me);
			filt_hu_color(Temps["tempW"], me);
			return 1;
		}
	}	
	if( strlen(Temps["tempW"]+Temps["tempB"]+Temps["tempS"])==0 || str_out=="") {
		size = strlen(Temps["tempT"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempT"])>sizeof(str_mj)/2 || size>12) {		
		//tell_object( present("wiman"), "��Ͳ�� ");
			if (Temps["tempW"]!="") filt_mj(Temps["tempT"], me);
			if (Temps["tempS"]!="") filt_mj(Temps["tempS"], me);
			if (Temps["tempB"]!="") filt_mj(Temps["tempB"], me);
			if( Temps["tempW"]==""&&Temps["tempS"]==""&&Temps["tempB"]=="")
				filt_mj(Temps["tempT"], me);
			filt_hu_color(Temps["tempT"], me);
			return 1;
		}
	}	
	if(strlen(Temps["tempW"]+Temps["tempB"]+Temps["tempT"])==0 || str_out=="") {
		size = strlen(Temps["tempS"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempS"])>sizeof(str_mj)/2 || size>12) {		
		//tell_object( present("wiman"), "��S�� ");
			if (Temps["tempT"]!="") filt_mj(Temps["tempT"], me);
			if (Temps["tempW"]!="") filt_mj(Temps["tempS"], me);
			if (Temps["tempB"]!="") filt_mj(Temps["tempB"], me);
			if( Temps["tempT"]==""&&Temps["tempW"]==""&&Temps["tempB"]=="")
				 filt_mj(Temps["tempS"], me);
			filt_hu_color(Temps["tempS"], me);
			return 1;
		}
	}	
	if(strlen(Temps["tempW"]+Temps["tempT"]+Temps["tempS"])==0 || str_out=="") {
		size = strlen(Temps["tempB"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempB"])>sizeof(str_mj)/2 || size > 12) {		
		//tell_object( present("wiman"), "���ִ� ");
			if (Temps["tempT"]!="") filt_mj(Temps["tempT"], me);
			if (Temps["tempS"]!="") filt_mj(Temps["tempS"], me);
			if (Temps["tempW"]!="") filt_mj(Temps["tempW"], me);
			if( Temps["tempT"]==""&&Temps["tempS"]==""&&Temps["tempW"]=="")
				filt_mj(Temps["tempB"], me);
			filt_hu_color(Temps["tempB"], me);
			return 1;
		}
	}
	
	return 0;
}

//��һɫ��
int dump_twocolor( string str_out, string str_mj, object me, mapping Temps )
{
			
	//mapping Temps = ([ "tempW": "", "tempT": "", "tempS": "", "tempB": "" ]);
	int size;	
	//tell_object( present("wiman"), str_mj +" ");
	//tell_object( present("wiman"), "& the str_out "+str_out +" ");
	get_all_temps( Temps, str_out );
	
	if( Temps["tempT"]==""&&Temps["tempS"]=="" ) {     	
		size = strlen(Temps["tempW"]+Temps["tempB"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempW"])>sizeof(str_mj)/2 || size>16) {		
			//tell_object( present("wiman"), "����� ");
			if (Temps["tempT"]!="") filt_mj(Temps["tempT"], me);
			if (Temps["tempS"]!="") filt_mj(Temps["tempS"], me);			
			if( Temps["tempT"]==""&&Temps["tempS"]=="") {
				filt_mj(Temps["tempB"], me);filt_mj(Temps["tempW"], me);
			}
			filt_hu_color(Temps["tempB"], me);filt_hu_color(Temps["tempW"], me);
			return 1;
		}
	}	
	if( Temps["tempW"]==""&&Temps["tempS"]=="" ) {
		size = strlen(Temps["tempT"]+Temps["tempB"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempT"])>sizeof(str_mj)/2 || size>16) {		
		//tell_object( present("wiman"), "��Ͳ�� ");
			if (Temps["tempW"]!="") filt_mj(Temps["tempW"], me);
			if (Temps["tempS"]!="") filt_mj(Temps["tempS"], me);			
			if( Temps["tempS"]==""&&Temps["tempW"]=="") {
				filt_mj(Temps["tempB"], me);filt_mj(Temps["tempT"], me);
			}
			filt_hu_color(Temps["tempB"], me);filt_hu_color(Temps["tempT"], me);
			return 1;
		}
	}	
	if(Temps["tempW"]==""&&Temps["tempT"]=="") {
		size = strlen(Temps["tempS"]+Temps["tempB"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempS"])>sizeof(str_mj)/2 || size>16) {		
		//tell_object( present("wiman"), "��S�� ");
			if (Temps["tempT"]!="") filt_mj(Temps["tempT"], me);
			if (Temps["tempW"]!="") filt_mj(Temps["tempW"], me);			
			if( Temps["tempT"]==""&&Temps["tempW"]=="") {
				filt_mj(Temps["tempB"], me);filt_mj(Temps["tempS"], me);
			}
			filt_hu_color(Temps["tempB"], me);filt_hu_color(Temps["tempS"], me);
			return 1;
		}
	}	
	return 0;
}

int dump_pinhu( mapping who, object me, mapping Temp )
{
	string str;
	int i;
	int check=0, check0=0;	
	get_all_temps( Temp, who["Mj"] );
	//filt
	for (i=0;i<sizeof(str);i+=2)
	  		if (do_check_num(str[i..i+1],1)>27) check0++;
	str = who["Out"]+who["OutPon"]+who["OutGon"];
	for (i=0;i<sizeof(str);i+=2)
		if (do_check_num(str[i..i+1],1)>27) check=1;
	//����������ƽ��
	//if(who["OutFlower"]=="" && check<5 && !check0) {
	if( !check && who["OutPon"]=="" && check0<5 ) {
		//�Ȱ������ӵ�
		//tell_object( present("wiman"), "ƽ���� ");
		who["Hu_type"] = "pinhu";
		if( Temp["tempB"]!="" ) {
			filt_mj( Temp["tempB"], me);
			return 1;
		}
		if (Temp["tempW"]!="") filt_mj(Temp["tempW"], me);
		if (Temp["tempT"]!="") filt_mj(Temp["tempT"], me);
		if (Temp["tempS"]!="") filt_mj(Temp["tempS"], me);
		return 1;		
	}
	return 0;
}

int dump_ponpon( mapping who, object me, mapping Temp )
{
	//mapping Temp = ([ "tempW": "", "tempT": "", "tempS": "", "tempB": "" ]);
	get_all_temps( Temp, who["Mj"] );
	if( who["Out"]=="" ) {
		if (Temp["tempB"]!="") filt_mj(Temp["tempB"], me);
		if (Temp["tempW"]!="") filt_mj(Temp["tempW"], me);
		if (Temp["tempT"]!="") filt_mj(Temp["tempT"], me);
		if (Temp["tempS"]!="") filt_mj(Temp["tempS"], me);
		if(sizeof(who["OutPon"]+ who["3Ps"])>10 || sizeof(who["OutPon"]+ who["3Ps"]+ who["2Ps"])>12) {
			//tell_object( present("wiman"), "������ ");		
			who["Hu_type"] = "ponpon";//break;
			if( who["1s"]!="") return 1;
			if( who["2Es1"]!="") return 1;
			if( who["2Es2"]!="") return 1;
			if( who["3Es"]!="") return 1;//{ tell_object(present("wiman"), NO_HU+who["3Es"]+find_mj(who["3Es"], who["Mj"])+"\n");do_dump(find_mj( who["3Es"], who["Mj"]), me);return;}
		}
		else {
			//tell_object( present("wiman"), "cancle������ ");
			who["3Ps"] ="";
			who["3Es"] ="";
			who["2Ps"] ="";
			who["2Es1"] ="";
			who["2Es2"] ="";
			who["1s"] ="";
		}	
	}
	return 0;
}
	
int get_all_temps( mapping map, string str )
{
	int size;
	size = strlen(str);
	map["tempW"]="";map["tempT"]="";map["tempS"]="";map["tempB"]="";
	for(; size>=0; size-=2){
	      //size--;
	  if (do_check_num(str[size..size+1],1) < 10) map["tempW"]+=str[size..size+1];
	  else if (do_check_num(str[size..size+1],1) < 19) map["tempT"]+=str[size..size+1];
	  else if (do_check_num(str[size..size+1],1) < 28) map["tempS"]+=str[size..size+1];
	  else if( do_check_num(str[size..size+1],1) < 35) map["tempB"]+=str[size..size+1];
	}
}
