// Last Modified by winder on Apr. 25 2001
#include <ansi.h>

mixed names = ({
	({
	"��ȸ����","��������","�׻�����","��������","�찲��","�����","������",
	"Ȫ������","��������","�������","����¥","������","��ɽ����",
	"��������","ϲ�ݳ�","��³��","�����","ɽ����","����ͷ","�������",
	"��ɽ����","����Ժ","ӿȪ��","���Ϸ�","�Ͻ��","�ɷ��","����ɽ��",
	"������","���ɷ�","��Ӧ��","�����","������Ժ","������","������", 
	}),
	({
	"��ܽ","����ͨ","������","����ʦ̫","����ʦ̫","��Զ��","Ī����",
	"½�˷�","������","��ҩʦ","��׺�","��Ұ��","����ţ","��־ƽ","С��Ů",
	"���˷�","ŷ����","�������","����","������","������","������","����Ⱥ",
	"�����","�����ʦ","���Ʊ���","��������","ׯ����","˫��","������",
	"ľ����","��Զɽ","������","������","����","�ڰ���","������","�彣��",
	"��ص���","����","����","��ɽͯ��","ΤһЦ","лѷ","�μ�","½�˷�",
	"�Ŵ�ɽ","������","�������","ʯ����","���Ǻ�","��ң��","�쵤��",
	"����","�ⲻƽ",
	}),
});
// names need modify
string ask_job()
{ 
	object ob, me,gift,*team;
	int exp,position;
	string target,myfam,obfam,job_type;
	ob=this_player();
	me=this_object();
	exp=ob->query("combat_exp");
/*
	myfam = me->query("family/family_name");//ͬһ���ɵĲŸ���job,������
	obfam = ob->query("family/family_name");//��ȥ�����û����������
	if(!myfam ||!obfam||myfam != obfam) 
	return "�㲻�Ǳ��ŵ��ӣ��Ҳ��ܸ��㹤����";
*/
	if (interactive(ob) && ob->query_temp("zzz_job_target") &&
		(int)ob->query_condition("zzz_mission"))  
		return "����һ�ε�����û��ɣ�";
	if (interactive(ob) && !ob->query_temp("zzz_job_target") &&
		(int)ob->query_condition("zzz_mission"))  
		return "����²������ȵȻ�ɡ�";
	if (interactive(ob) && (int)ob->query_condition("zzz_busy"))  
		return "�����ҿ�û�и�������񣬵Ȼ������ɡ�\n";
	if(exp<=100000)	return "����书̫���ˣ�����ǿ�������ɡ�\n";
	job_type="����";
   	ob->set_temp("zzz_job_type",job_type);
	if(job_type=="����")
	{
		target = names[1][random(sizeof(names[1]))];
		ob->apply_condition("zzz_mission",30);    
		ob->set_temp("zzz_job_target", target);
		message_vision(CYN "$N���˵�ͷ����$n˵�����ɹ���������һ�����ְ��࣬����Ҫ��ɱ"+target+"����ȥ������һ�¡�\n"NOR , me,ob);
		call_out("begin_kill",30,ob,target);
		return "���С�ġ�";
	}
}
int accept_object(object who, object ob,object me)
{
	if ( ob->query("id") != "corpse")
	{
		command("say ������������");
		return 0;
	}
	if ( !who->query_temp("zzz_job_target") )
	{
		command("say �ð��������������������");
		return 0;
	}
/*
	if( who->query_temp("zzz_job_type")=="ɱ")
		if(ob->query("victim_name")!=who->query_temp("zzz_job_target")||
			ob->query("victim_user")||who->query_temp("zzz_given") )
		{
			command("shake");
			command("say ��ɱ�����ˡ�");
			return 0;
		}
*/
	if( who->query_temp("zzz_job_type")=="����")
		if (ob->query_temp("must_killby")!= who->query("id") ||
			ob->query("victim_user")||who->query_temp("zzz_given") )
		{
			command("shake");
			command("say ��ɱ�����ˡ�");
			return 0;
		} 
/*
	if ( ob->query("kill_by") != who)
	{
		command("say ��������ƺ��������Լ���ɵİɣ�");
		return 0;
	}
*/
	who->set_temp("zzz_given",1);
	call_out("destroying", 1, ob);
	call_out("ok", 1, who);
	return 1;
}
void ok(object who)
{
	int exp,pot,i;
	if (!who) return;
	command("pat" + who->query("id"));
	command("say �ɵĺã�����¸ɾ����䣬�����سɴ�����");
	if(!who->query("zzz_job_count")) who->set("zzz_job_count",1);
	else who->add("zzz_job_count",1);	
	i=who->query("zzz_job_count");
	i/=30;
	exp=200+random(20)+i;
	if(who->query_temp("zzz_job_super"))
	{
		exp+=100;
		who->delete_temp("zzz_job_super");
	}
	pot=exp/3+random(10);
//i=3+random(3)+exp/200;
	who->add("potential",pot);
	who->add("combat_exp",exp);
	who->delete_temp("zzz_job_target");
	who->delete_temp("zzz_given");
	who->delete_temp("zzz_job_type");
	who->clear_condition("zzz_mission");
	who->apply_condition("zzz_busy",3+random(6)+exp/50);	
	tell_object(who,HIW"�㱻�����ˣ�" + 
		chinese_number(exp) + "��ʵս���飬" +
		chinese_number(pot) + "��Ǳ�ܡ�\n"+ NOR);
	return;
}


void destroying(object obj)
{
	destruct(obj);
	return;
}
string ask_fangqi()
{
	object me;
	me = this_player();
	if(me->query_condition("zzz_mission")<=1)
		return "��û��������������Ϲ����ʲ�᣿";
	me->clear_condition("zzz_mission");
//	me->apply_condition("zzz_busy",4+random(10));
	me->delete_temp("zzz_job_target");
	me->delete_temp("zzz_job_type");
	return "û��ϵ���´μ���Ŭ����";
}
void begin_kill(object me,string target)
{
	object obj,*ob;
	int i,flag=0;
	if( !me->query_condition("zzz_mission")) return;
	if( me->query_temp("zzz_job_type")!="����" ||
		me->query_temp("zzz_job_target")!=target)
		return;
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i])||userp(ob[i])||ob[i]==me ) continue;
		if(ob[i]->query("name")==target)
		{
			flag=1;
			break;
		}
	}
	if (flag==0)
	{
		call_out("begin_kill",30,me,target);
		return;
	} 
	obj=new(__DIR__"killer");
	obj->move(environment(me));
	if(random(10)>7||me->query("id")=="zzz")
	{
		obj->do_copy(me,1);
		obj->set("title",HIR"���ְ���"NOR);
		me->set_temp("zzz_job_super",1);
	}
	else obj->do_copy(me,0);
	obj->set_temp("must_killby",me->query("id"));
	message_vision( GRN"\n$N����"+target+"����һ����Ц������"+target+"ȫ�����µĺ�ë�������𣬲���������\n"NOR,obj); 
	message_vision(HIY"$N��$n�ȵ����󵨿�ͽ������������Ұ����\n"NOR,me,obj);
	message_vision(HIY"$N����һЦ��Ҫ�������£�ȥ���ɣ���\n"NOR,obj);
	obj->kill_ob(me);
}

string ask_gonglao(object who)
{
	object me;
	int i;
  
	me = this_player();
	if(!me->query("zzz_job_count")) i=0;
	else i =(int)me->query("zzz_job_count"); 
	message_vision( CYN"$N��$n˵�������Ѿ������" + chinese_number(i) + "������\n"NOR,who,me);
	return "����Ŭ���ɣ�";
}
