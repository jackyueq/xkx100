// Room: /d/baihuagu/shanpo4.c
// Last Modified by Winder on Mar. 5 2001

#include <ansi.h>;
#include "yangfeng.h";
inherit ROOM;
void create()
{
	set("short", GRN"ɽ����"NOR);
	set("long", 
HIY"����һ��ɽ�ȡ�����ɽ�����ϣ���ס��ɽ�磬��֮���¿��
�ḻ�����Ե�����ů���ٻ��ȷš��˴����ż���ľ�ܣ������߰�
���䳲������Ⱥ�����裬���������������������׵�ɽ�ȴ�����
����������ɽ���и������������кܶ��ľ����������������࣬
ż���ɼ�һ�����ھ��ҩ��ũ�ˡ�\n"NOR);
	set("outdoors", "baihuagu");
	set("count", 10);
	set("exits", ([
		"westup" : __DIR__"baihuagu2",
	]));
	set("objects", ([
		__DIR__"npc/yubee": 2
	]));
	set("item_desc", ([
		"�䳲" : "����һ���޴�ķ䳲������ܶ��ܷ���æ�����ۡ�\n",
	]));
	set("coor/x", -400);
	set("coor/y", -360);
	set("coor/z", -10);
	setup();
}
void init()
{
	add_action("do_dig","dig");
	add_action("do_full","full");
	add_action("do_yang","yang");
	add_action("do_getmi","getmi");
}
int do_dig(string arg)
{
	object me;
	object food;
	me=this_player();
	if( (int)me->query("food") >= (int)me->max_food_capacity() )
	{
		message_vision( HIC"$N��Ҫ��ʲô��ͻȻ����ͯ���˹�����а���Ц��һ�£���Ȼ�����ȡ��һ֧���ߣ���$N���й��ȥ�����не����ҽ���ԣ�����$N���ͷ���ۻ����ԵĶ����˳���������ͯ�����Ц�ˣ���һ���̵����ˡ�\n"NOR,me);
		return 1;
	}
	else
	{
		if (query("count") > 0)
		{
			message_vision("$N����һ������ڵ�һ�����ڡ��������£��Խ�������\n",me);
			me->add("food", 30);
			add("count", -1);
		}
		else message_vision("$N����һ�����ɶ��û�С�\n",me);
		return 1;
	}
}
int do_full(string arg)
{
	object me;
	me=this_player();
	if( (int)me->query("water") >= (int)me->max_water_capacity() )
	{
		message_vision( HIY"$N����δ���������Ķ��ӣ�������䳲����ͻȻ�ҽ�һ���������˶�����������ֻ����ֻ�ֶ�����������\n"NOR,me);
		return 1;
	}
	else
	{
		if (query("count") > 0)
		{
			message_vision("$N�ӷ䳲��ȡ��Щ�佬������������\n",me);
			me->add("water", 30);
			add("count", -1);
		}
		else message_vision("$N����һ�����ɶ��û�С�\n",me);
		return 1;
	}
}

int do_getmi(string arg)
{
	object me;
	me=this_player();
	if (me->query_temp("marks/getmi"))
	{
		message_vision(HIY"$N����һ�����ӷ䳲��ȡ��һ���ۡ�\n"NOR,me);
		new("/d/baihuagu/obj/mi")->move(me);
		me->set_temp("marks/getmi",0);
		return 1;
	}
	else
	{
		message_vision( HIR"$N�ٺ�һЦ����߯�������䳲��ȥ����Ҫ�����ж���ͻ���˵ļ�������ֻ��������彫��������$N�ص���ͷ�����\n"NOR,me);
		return 1;
	}
}
