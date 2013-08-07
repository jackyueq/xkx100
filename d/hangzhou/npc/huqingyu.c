// huqingyu.c
#include <ansi.h>
#include <command.h>
inherit F_CLEAN_UP;
inherit NPC;

void create()
{
	set_name("������",({ "hu qingyu","hu" }));
	set("gender", "����" );
	set("age", 63);
	set("long",
"�������ǵ���һ����ҽ�����ı��������ޱȡ������������֮����\n");
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("inquiry", ([
		"����": "������ƽ𣬸����ͷ���棬������û�˻�֪����ģ�",
	]) );
	set("chat_chance", 30);
	set("chat_msg",({
		"�����൭��˵�������ĸ��������������ˡ���\n",
	}));
	setup();
}
void init()
{
	object ob,me;
	add_action("do_name","name");
//	add_action("do_betrayer","betrayer");
//	add_action("do_age","age");
}
int accept_object(object me, object ob)
{
	if (userp(me))
	{
		if( ob->query("money_id") && ob->value() >= 5000000)
		{
			if(me->query("class") == "bonze" || me->query("class") == "quanzhen")
			{
				say("�������ڿڰ�Ц���������ǲ��ܸ����ֵġ��һ�����������ʦ���������ҵ�С���ء�\n");
				return 0;
			}
			command("nod");
			command("say �ðɣ�"+me->query("name")+"����˵���³̣�\n");
			me->set_temp("marks/huqingyu",1);
			return 1;
		}
	} else return 1;
}
int do_name(string arg,object me)
{
	string *banned_name = ({
		"��", "��", "��", "��", "��", "��", "��", "��", "��",
		"����ү", "������", "����", "ʱ��", "��",
		"ľ��", "��������", "����", "ΤС��",
		"����", "�����п�", "����", "���", "�������", "����",
		"����ѩ", "����", "��־��","Ϻ�����"
	});
	int i;

	me = this_player();
	if(me->query("class") == "bonze" || me->query("class") == "quanzhen")
		return notify_fail("�������ڿڰ�Ц���������ǲ��ܸ����ֵġ��һ�����������ʦ���������ҵ�С���ء�\n");
	if(!(int)me->query_temp("marks/huqingyu"))
	{
		return notify_fail("�����෭�źڰ��ۣ�Ǯ�أ�û��Ǯ��ռ���ˣ�\n");
	}
	if( !arg ) return notify_fail("������Ц���������ܸ�дȫ�ɡ�\n");
	if( strlen(arg) > 10 )
	return notify_fail("�����ྪ��������������ô�������֣�\n");
	if( strlen(arg) < 4 )
	return notify_fail("���������һ������ô����ɶ���֣�\n");
        i=strlen(arg);
	while(i--)
	{
		if( arg[i]<=' ' ) {
			write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
			return 1;
		}
		if( (strsrch(arg, "��") >= 0) ||
		    (strsrch(arg, "��") >= 0)) {
			write("�Բ�������������ֲ������������ĵ��֡�\n");
			return 1;
		}
		if( i%2==0 && !is_chinese(arg[i..<0]) ) {
			write("�Բ��������á����ġ�ȡ���֡�\n");
			return 1;
		}
	}
	if( member_array(arg, banned_name)!=-1 ) {
		write("�Բ����������ֻ���������˵����š�\n");
		return 1;
	}
	if( (strlen(arg) < 2) || (strlen(arg) > 10 ) ) {
		write("�Բ�������������ֱ����� 1 �� 5 �������֡�\n");
		return 1;
	}

	me->delete_temp("marks/huqingyu");
	if (me->query("gender")=="Ů��")
		message_vision(CYN"�������һ�Ӿ͸���$N�ķ�������ˬ����....\n"NOR,me);
	else message_vision(CYN"�������һ�Ӿ͸���$N�Ĵ���...����\n"NOR,me);
	me->set("name",arg);

	return 1;
}

/*
int do_betrayer(object me)
{
	me = this_player();
	if(!(int)me->query_temp("marks/huqingyu"))
	{
		return notify_fail("�����෭�źڰ��ۣ�Ǯ�أ�û��Ǯ��ռ���ˣ�\n");
	}

	me->delete_temp("marks/huqingyu");
	if (me->query("combat_exp")<10000)
		return notify_fail("��ԩ������ľ��黹���������ʦ�ģ�\n");

	me->set("betrayer", me->query("betrayer")+1);
	me->set("title","��ͨ����");
	me->set("class","0");
	me->delete("family");
	message_vision(CYN"�����Ц���������Ϻ�����գ�����$N������ˣ������������ʦ��¼Ҳ����һ�Σ�\n"NOR,me);
	command("sigh");
	return 1;
}

int do_age(object me)
{
	object obj;
	me = this_player();

	return notify_fail("�����෭�źڰ��ۣ�������������Ҳ��̫�����ˣ�\n");
	if(!(int)me->query_temp("marks/huqingyu"))
	{
		return notify_fail("�����෭�źڰ��ۣ�Ǯ�أ�û��Ǯ��ռ���ˣ�\n");
	}
	me->delete_temp("marks/huqingyu");

	if (me->query("age") < 21)
	{
//		obj=new("/clone/money/gold");
//		obj->set_amount(100);
//		obj->move(me);
		return notify_fail("���������㻹������ģ���һ�����ƽ�����Ϸ�׻��ˣ�\n");
	}

	me->add("mud_age", -86400);
	me->add("age", -1);
	me->delete("last_slp");
	me->delete("jingzuo_time");
	log_file( "CHANGEAGE", sprintf("%s at %s: %d\n", me->query("id"), ctime(time()), me->query("age") ) );
	message_vision(CYN"����������Ȼ��Ǯ��ʹ����ĥ��$N���ڿ���������ˣ�\n"NOR,me);
	return 1;
}
*/
