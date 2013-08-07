// Room: /d/kunlun/kuhanlou1.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ຮ¥һ��");
	set("long", @LONG
�����ǿຮ¥�ĵײ㡣�ຮ¥�ṹ�򵥣�����ΪŨ�ܵ���ɼ��Χ��
ȡ���ԡ�÷�����Կຮ����֮�⣬����������ǰ��Ϊ�˼������������
���Ӷ����ģ����Ͽ���������ľ¥�����ƶ��ϣ��ƺ����޾�ͷ����ש��
�൱�ྻ�������������˴�ɨ������ǽ�ϵıڻ�(bihua) ����ǰ������
���书ͼ�ס�
LONG );
	set("item_desc",([
		"bihua" : "�ڻ����������ʽȫ�������з������಻��������ԣ�����������Ħ(chuaimo)��\n",
	]));
	set("exits", ([
		"up"  : __DIR__"kuhanlou2",
		"out" : __DIR__"kuhanlou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -119980);
	set("coor/y", 40130);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "up" ) me->set_temp("count", 1);
	else me->add_temp("count", -1);

	return ::valid_leave(me, dir);
}

int init()
{
	add_action("do_chuaimo","chuaimo");
}

int do_chuaimo(string arg)
{
	object me = this_player();
	if ( !living(this_player()) || arg != "parry" )
		return notify_fail("��Ҫ��Ħʲô�书��\n");
	if ((int)me->query_skill("parry", 1) > 40)
		return notify_fail("�ڻ������̵��书����ȫ������ˣ��������˷�ʱ���ˡ�\n");
	if ( me->query_skill("xuantian-wuji", 1)<30)
	{
		me->receive_damage("jing", 10);
		write("�㱾���ڹ�ʵ��̫���������Ϣһ��ɣ�\n");
		return 1;
	}
	if ( (int)me->query("jing")<30)
	{
		me->receive_damage("jing", 10);
		write("�����ĥ���Դ������ˣ���������Ϣһ��ɣ�\n");
		return 1;
	}
	me->receive_damage("jing", random(25));
	message_vision("$N���ڴ�Ħ�ڻ��ϵ��书��\n", me);
	write("��ר����־�Ĵ�Ħ�ڻ��ϵ���ʽ���о������м��ֽ���һ����\n");
	me->improve_skill("parry", me->query_int());
	return 1;
} 