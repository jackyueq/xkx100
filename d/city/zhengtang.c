// Room: zhengtang.c
#include <ansi.h>
inherit ROOM;
void bt_same(object who,object me);

void create()
{
	set("short", "����");
	set("long", @LONG
���������ݸ��Ĵ��ã��������۷ְ�վ��������ѻȵ�������ÿڰ�
���Ż������͵�����ͭա���̴��˸��������ϣ���ɫ������΢��ŭɫ��
������������׽���˷����������и���һ�ң�
	       ��      ��      ��      ��
LONG
	);
	set("no_fight", "1");
	set("exits", ([
		"east"      : __DIR__"dongting",
		"west"      : __DIR__"xiting",
		"north"     : __DIR__"neizhai",
		"southdown" : __DIR__"yamenyuan",
	]));
	set("objects", ([
		__DIR__"task3/cheng": 1,
		__DIR__"npc/yayi": 4,
	]));
	set("coor/x", -20);
	set("coor/y", 2);
	set("coor/z", 10);
	setup();
//	replace_program(ROOM);
}

void init ()
{
	add_action("do_work","work");
	add_action("do_finish","finish");
}

int do_work (string arg)
{
	object ob,ob1,me = this_player();
	int bt_npc,bt_whatnpc,worked_num,officerlvl;
	string bt_name,bt_name1,bt_where;

	if (!(int)me->query("officerlvl"))
		return notify_fail("�������۴����ȵ����󵨵��񣬲����������ã�\n");
	if (!objectp(present("cheng yaofa", environment(me))))
		return notify_fail("����Ц�����̴����Ѿ������ˣ�Ҫ��������������������\n");
	if (time()<me->query("bt/time")+2*(me->query("bt/work")-me->query("bt/worked")))
		return notify_fail("�̴��˴�ŭ�������������Ž����������ɻ���ù���ٺ»�ˣ�\n");
	if (present("huo qian",me) || me->query_condition("bt_busy"))
		return notify_fail("�̴�����ɫһ����������ǰ�ս�����Ĳ�����ȥ���������������أ�\n");
	bt_npc = 1 + random(30);
	bt_whatnpc =1+random(6);
	me->set("bt/whatnpc",bt_whatnpc);
	me->set("bt/time",time());
	me->apply_condition("bt_busy",5+random(5));
	ob = new(__DIR__"task3/huoqian");	//50
	if(bt_whatnpc==1){ob1 = new(__DIR__"task3/tufei1");}
	if(bt_whatnpc==2){ob1 = new(__DIR__"task3/tufei2");}
	if(bt_whatnpc==3){ob1 = new(__DIR__"task3/tufei3");}
	if(bt_whatnpc==4){ob1 = new(__DIR__"task3/tufei4");}
	if(bt_whatnpc==5){ob1 = new(__DIR__"task3/tufei5");}
	if(bt_whatnpc==6){ob1 = new(__DIR__"task3/tufei6");}
	bt_same(ob1,me);
	ob1->move(ob);
	ob ->move(me);
	me->set_temp("bt/npc",bt_npc);
	me->add("bt/work",1);
	if(bt_npc<280) bt_where = "����ĳ��С����";
	if(bt_npc<160) bt_where = "�����Ա�";
	if(bt_npc<130) bt_where = "�����Զ�";
	if(bt_npc<100) bt_where = "��������";
	if(bt_npc<91) bt_where = "����һ��";
	if(bt_npc<41) bt_where = "���ݸ���";

	if(bt_whatnpc==1){bt_name="������";bt_name1="��·����,ɱ������";}
	if(bt_whatnpc==2){bt_name="��Ӱ��͵";bt_name1="�Ĵ����Բ���";}
	if(bt_whatnpc==3){bt_name="�������к�";bt_name1="��������Ů���޶���";}
	if(bt_whatnpc==4){bt_name="����ϸ��";bt_name1="�Ĵ��";}
	if(bt_whatnpc==5){bt_name="���ɼ�ϸ";bt_name1="�Ĵ���ҥ�ƻ�";}
	if(bt_whatnpc==6){bt_name="������";bt_name1="��ɱ��͢����";}

	me->set_temp("bt/whatnpc",bt_whatnpc);
	me->set_temp("bt/name",bt_name);
	me->set_temp("bt/where",bt_where);
	message_vision("�̴���һ�ľ���ľŭ�������ݲ����"+bt_name+"��"+bt_where+bt_name1+"��\n$N��ȥ�ư����������󡣡�˵����һ�����һ����ǩ��$Næ�����\n���������������\n",me);
	me->set_temp("bt/working",1);

	officerlvl = me->query("officerlvl");
	worked_num=me->query("bt/worked");
	if (worked_num>=3200 && officerlvl == 8)
		me->set("officerlvl",9);
	if (worked_num>=1600 && worked_num < 3200 && officerlvl == 7)
		me->set("officerlvl",8);
	if (worked_num>=800 && worked_num < 1600 && officerlvl == 6)
		me->set("officerlvl",7);
	if (worked_num>=400 && worked_num < 800  && officerlvl == 5)
		me->set("officerlvl",6);
	if (worked_num>=200 && worked_num < 400 && officerlvl == 4)
		me->set("officerlvl",5);
	if (worked_num>=100 && worked_num < 200 && officerlvl == 3)
		me->set("officerlvl",4);
	if (worked_num>=50 && worked_num < 100 && officerlvl == 2)
		me->set("officerlvl",3);
	if (worked_num>=20 && worked_num < 100 && officerlvl == 1)
		me->set("officerlvl",2);
//	me->set_temp("btwork/time",1);
	me->save();
	return 1;
}
int do_finish (string arg)
{
	object ob;
	int bt_npc,bt_whatnpc,bt_exp,bt_qn;
	string bt_name,bt_name1,bt_where;
	object me = this_player();
	ob= present("huo qian",me);
	bt_name = me->query_temp("bt/name");
	bt_where = me->query_temp("bt/where");
	if (!(int)me->query("officerlvl"))
		return notify_fail("�������۴����ȵ����󵨵��񣬲����������ã�\n");
	if (!objectp(present("cheng yaofa", environment(me))))
		return notify_fail("����Ц�����̴����Ѿ������ˣ�Ҫ�뽻ǩ��������������\n");
	if (!me->query_temp("bt/working"))
		return notify_fail("�̴�����ɫһ����������ʲôʱ���ɹ�����°���\n");
	if (!(int)me->query_temp("bt/finish"))
		return notify_fail("�̴�����ɫһ��������������Ĳ�ʹ����δ���ף��㻹����Ŀ�����ң�\n");
	if (present("huo qian",me))
	{
		tell_object(me, "�㹧�������Ľ��ϻ�ǩ��\n" NOR );
		destruct(present("huo qian",me));
	}
	message_vision ("�̴���΢΢һЦ����"+me->query("name")+"��"+bt_where+"�ƻ�"+bt_name+"һ�����Ϳ๦�ߣ��Ͽ���ȥ��Ϣ�ɣ�\n",me);
	bt_exp = 600+random(200);
//	bt_qn = 100+random(48);
	bt_qn = 150+random(50);
	me->add("combat_exp",bt_exp);
	me->add("potential",bt_qn);
	me->set_temp("prize_reason","����");
	me->set_temp("can_give_prize",1);
	me->set_temp("prize_exp",bt_exp);
	me->set_temp("prize_pot",bt_qn);
	me->add("bt/worked",1);
	me->delete_temp("bt/finish");
	me->delete_temp("bt/working");
	me->clear_condition("bt_busy");
	tell_object(me, "������" + chinese_number(bt_exp)+ "�㾭�顣" NOR );
	tell_object(me, "��" + chinese_number(bt_qn)+ "��Ǳ�ܡ�\n" NOR );
	if (me->query("bt/worked")==3200)
	{
		me->set("officerlvl",9);
		me->add("weiwang",20);
		message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,me);
		tell_object(me, "�����ڵĽ���������" + chinese_number((string)(me->query("weiwang")))+"��\n"NOR);
		message_vision (WHT"�̴���΢Ц��˵����"+me->query("name")+"���ƴ󰸣����������������Ѿ�����ʥ�ϡ�\n���ճ�ּ���£����������ʥ���������������ȥ�ٻء�"NOR,me);
		me->set("bt/jiangli",1);
	}
	if (me->query("bt/worked")==1600)
	{
		me->set("officerlvl",8);
		me->add("weiwang",20);
		message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,me);
		tell_object(me, "�����ڵĽ���������" + chinese_number((string)(me->query("weiwang")))+"��\n"NOR);
		message_vision (WHT"�̴���΢Ц��˵����"+me->query("name")+"���ƴ󰸣����������������Ѿ�����ʥ�ϡ�\n���ճ�ּ���£����������ʥ���������������ȥ�ٻء�"NOR,me);
	}
	if (me->query("bt/worked")==800)
	{
		me->set("officerlvl",7);
		me->add("weiwang",20);
		message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,me);
		tell_object(me, "�����ڵĽ���������" + chinese_number((string)(me->query("weiwang")))+"��\n"NOR);
		message_vision (WHT"�̴���΢Ц��˵����"+me->query("name")+"���ƴ󰸣����������������Ѿ�����ʥ�ϡ�\n���ճ�ּ���£����������ʥ���������������ȥ�ٻء�"NOR,me);
	}
	if (me->query("bt/worked")==400)
	{
		me->set("officerlvl",6);
		me->add("weiwang",20);
		message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,me);
		tell_object(me, "�����ڵĽ���������" + chinese_number((string)(me->query("weiwang")))+"��\n"NOR);
		message_vision (WHT"�̴���΢Ц��˵����"+me->query("name")+"���ƴ󰸣����������������Ѿ�����ʥ�ϡ�\n���ճ�ּ���£����������ʥ���������������ȥ�ٻء�"NOR,me);
	}
	if (me->query("bt/worked")==200)
	{
		me->set("officerlvl",5);
		me->add("weiwang",20);
		message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,me);
		tell_object(me, "�����ڵĽ���������" + chinese_number((string)(me->query("weiwang")))+"��\n"NOR);
		message_vision (WHT"�̴���΢Ц��˵����"+me->query("name")+"���ƴ󰸣����������������Ѿ�����ʥ�ϡ�\n���ճ�ּ���£����������ʥ���������������ȥ�ٻء�"NOR,me);
	}
	if (me->query("bt/worked")==100)
	{
		me->set("officerlvl",4);
		me->add("weiwang",20);
		message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,me);
		tell_object(me, "�����ڵĽ���������" + chinese_number((string)(me->query("weiwang")))+"��\n"NOR);
		message_vision (WHT"�̴���΢Ц��˵����"+me->query("name")+"���ƴ󰸣����������������Ѿ�����ʥ�ϡ�\n���ճ�ּ���£����������ʥ���������������ȥ�ٻء�"NOR,me);
	}
	if (me->query("bt/worked")==50)
	{
		me->set("officerlvl",3);
		me->add("weiwang",20);
		message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,me);
		tell_object(me, "�����ڵĽ���������" + chinese_number((string)(me->query("weiwang")))+"��\n"NOR);
		message_vision (WHT"�̴���΢Ц��˵����"+me->query("name")+"���ƴ󰸣����������������Ѿ�����ʥ�ϡ�\n���ճ�ּ���£����������ʥ���������������ȥ�ٻء�"NOR,me);
	}
	if (me->query("bt/worked")==20)
	{
		me->set("officerlvl",2);
	}
	me->save();
	return 1;
}
void bt_same(object who,object me)
{
	mapping myscore;
	int maxskill;
	myscore = me->query_entire_dbase();
	who->set("combat_exp", (int)me->query("combat_exp")*9/10);

	who->set("max_qi", (int)myscore["max_qi"]);
	who->set("eff_qi", (int)myscore["eff_qi"]);
	who->set("qi", (int)myscore["max_qi"]);
	who->set("max_jing", (int)myscore["max_jing"]);
	who->set("eff_jing", (int)myscore["eff_jing"]);
	who->set("jing", (int)myscore["max_jing"]);
	who->set("max_neili", (int)myscore["max_neili"]);
	who->set("neili", (int)myscore["max_neili"]);
	who->set("jiali", 0);
	maxskill = me->query_skill("force",1);
	if(maxskill<me->query_skill("parry",1)) maxskill=me->query_skill("parry",1);
	if(maxskill<me->query_skill("dodge",1)) maxskill=me->query_skill("dodge",1);
	if(maxskill<me->query_skill("sword",1)) maxskill=me->query_skill("sword",1);
	if(maxskill<me->query_skill("blade",1)) maxskill=me->query_skill("blade",1);
	if(maxskill<me->query_skill("unarmed",1)) maxskill=me->query_skill("unarmed",1);
	if(maxskill==0) maxskill=20;
	who->set("maxskill",maxskill*11/10);
}
int valid_leave (object who, string dir)
{
	if(who->query_condition("bt_stop")<1)
	{
		return ::valid_leave(who, dir);
	}
	else
	{
		message_vision ("$N���������������ܡ�\n",who);
		return notify_fail(WHT"�����������㰴�ڵ��Ϻȵ�����ʵ�㣡\n"NOR);
		return 1;
	}
}
