// huoqian.c
//modefied by sega 1/15/99 �ĳɲ�����no_fight�ĵط�catch

#include <ansi.h>;
inherit ITEM;
//inherit F_CLEAN_UP;
void setup()
{}

void init()
{
	add_action("do_watch","guancha");
	add_action("do_watch","watch");
	add_action("do_catch","daibu");
	add_action("do_catch","catch");
	add_action("do_catch","kill");
	add_action("do_catch","hit");
}
int is_container() { return 1; }

void create()
{
	set_name(HIR"��ǩ"NOR, ({"huo qian","hq" }));
	set_max_encumbrance(10);
	set("unit", "��");
	set("long", "����һ�����Ļ�ǩ�����ִ��죬����֤���ٸ���ʿ����ݡ�\n�����������Ȩ��Ѱ�ﷸ(guancha/watch)���������ɷ�(daibu/catch)��\n");
	set("value", 0);
	set("no_drop", "�������������뿪�㡣\n");
	set("no_get", "���ǹٸ��Ķ�����ƽ�������˻����鷳�ġ�\n");
	set("no_get_from", "���ǹٸ��Ķ�����ƽ�������˻����鷳�ġ�\n");
	set("no_put", "���ǹٸ��Ķ������𵽴��ҷš�\n");
	set_weight(200);
	set("place","on");

	setup();
}
int do_watch(string arg)
{
	object obj,new_obj;
	object me = this_player();
	object ob = this_object();
	string targ;

	if (!me->query("officerlvl"))
		return notify_fail("�㲢�ǳ�͢��Ա���αز�������ģ�\n");

	if (!ob=present("huo qian",me))
		return notify_fail("ʲô��\n");
	if (me->query_temp("bt/finish"))
		return notify_fail("�̴��˵��Żػ��ģ��㻹��ĥ��ʲô��\n");
	if (!arg||!obj=present(arg,environment(me)))
		return notify_fail("��Ҫ�۲�˭��\n");
	if (!obj->is_character() || obj->is_corpse() )
		return notify_fail("��ֻ�ܹ۲�һ��������塣\n");
	if (!present("picture",ob))
		return notify_fail("�����Ѿ����������ɷ�����ĥ��ʲô��\n");
	if (me->is_busy() )
		return notify_fail("����æ�š�\n");

	targ=obj->query("name");
	tell_object(me,"����������������"+targ+"��\n\n");
	me->start_busy(1);
	if (obj->query("bt_tufei")==me->query_temp("bt/npc") &&
		random(me->query("kar")+15)>20 &&
		!environment(me)->query("no_fight") )
	{
		switch(random(5))
		{
			case 0:
tell_object(me,WHT"�㷢��"+targ+"��Ȼ��ͷһ�ͣ��ƺ���ܿ����Ŀ�⡣\n\n"NOR);
				break;
			case 1:
tell_object(me,WHT"�㷢��"+targ+"��Ȼ���˸����£�������ɫ��\n\n"NOR);
				break;
			case 2:
tell_object(me,WHT"�㷢��"+targ+"̫��Ѩ�߸߷����ƺ��Ǹ�������ˡ�\n\n"NOR);
				break;
			case 3:
tell_object(me,WHT"�㷢��"+targ+"����Ĺ����ҵģ���������һ�����С�\n\n"NOR);
				break;
			case 4:
tell_object(me,WHT"�㷢��"+targ+"�����о���һ���������ֱ��һ��ãȻ��\n\n"NOR);
				break;
		}
		me->set_temp("bt/faxian",1);
		obj->set_temp("bt_faxianed",me->query("id"));
	}
	else
	{
		switch(random(11))
		{
			case 0:
tell_object(me,"ֻ��"+targ+"����üŪ�ۣ�ɫ���ԵĶ���������\n\n");
				break;
			case 1:
tell_object(me,"ֻ��"+targ+"������Ƽ��ݣ��������\n\n");
				break;
			case 2:
tell_object(me,"ֻ��"+targ+"���΢�죬һ�����ߵ�ģ����\n\n");
				break;
			case 3:
tell_object(me,"ֻ��"+targ+"�������⣬�������硣\n\n");
				break;
			case 4:
tell_object(me,"ֻ��"+targ+"��ʹ�������޵���������Ƶġ�\n\n");
				break;
			case 5:
tell_object(me,"ֻ��"+targ+"���㽩Ӳ������ɢ���Ž�������\n\n");
				break;
			case 6:
tell_object(me,"ֻ��"+targ+"���ޱ��飬����ľ����\n\n");
				break;
			case 7:
tell_object(me,"ֻ��"+targ+"���ü��������Ŀ���թ��\n\n");
				break;
			case 8:
tell_object(me,"ֻ��"+targ+"��Ц���������ϼ���һ˿��Ц��\n\n");
				break;
			case 9:
tell_object(me,"ֻ��"+targ+"ͦ�ص��ǣ�һ����������ɫ��\n\n");
				break;
			case 10:
tell_object(me,"ֻ��"+targ+"���������ݣ�һ���������ɫ��\n\n");
				break;
		}
	}
	return 1;
}
int do_catch(string arg)
{
	object obj,new_obj;
	object me = this_player();
	object ob = this_object();			//100
	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if (!ob=present("huo qian",me))
		return notify_fail("ʲô��\n");
	if (!me->query("officerlvl"))
		return notify_fail("�㲢�ǳ�͢��Ա���αز�������ģ�\n");
	if (me->query_temp("bt/finish"))
		return notify_fail("�̴��˵��Żػ��ģ��㻹��ĥ��ʲô��\n");
	if (!arg||!obj=present(arg,environment(me)))
		return notify_fail("��Ҫ����˭��\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("��ֻ�ܴ���һ�����ˡ�\n");
	if( !me->query_temp("bt/faxian")
		|| obj->query_temp("bt_faxianed")!=me->query("id") )
		return notify_fail("���ݼ���������û��֤���������ˣ�\n");
	message_vision ("$N����$n��Цһ���������µİ��ӷ��ˣ�����ʵʵ������
��һ�ˡ�\n\n",me,obj);
	message_vision (RED"$n���һ���ҿ�αװ��¶��������Ŀ��\n$n��ȵ������Ӻ���ƴ�ˣ�\n\n"NOR,me,obj);
	obj->delete_temp("bt_faxianed");
	destruct(obj);
	new_obj = present("picture",ob);
	new_obj->move(environment(me));
	new_obj->kill_ob(me);
	me->kill_ob(new_obj);
	new_obj->set_leader(me);
	new_obj->set_temp("bt_npc",me->query_temp("bt/npc"));
	new_obj->set_temp("bt_ownname",me->query("id"));
	new_obj->delete("no_see");
	new_obj->start_busy(1);
	me->delete_temp("bt/faxian");
	return 1;
}

