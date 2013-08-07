// Room: /d/taohua/taohua11.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;
#include <ansi.h>;
int do_look(string arg);

void create()
{
	int thd1, thd2, thd3, thd4;

	thd1 = random(12) + 1;
	thd2 = random(12) + 1;
	thd3 = random(12) + 1;
	thd4 = random(12) + 1;
	while (thd1 != 9 && thd2 != 9 && thd3 != 9 && thd4 != 9) {
		thd1 = random(12) + 1;
		thd2 = random(12) + 1;
		thd3 = random(12) + 1;
		thd4 = random(12) + 1;
	}
	set("short", "�һ���");
	set("long", @LONG
������һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢���
������Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С������в�����
����������������ȥ�ĺá�
LONG
	);

	set("exits", ([
		"east" : __DIR__"taohua" + thd1,
		"west" : __DIR__"taohua" + thd2,
		"south" : __DIR__"taohua" + thd3,
		"north" : __DIR__"taohua" + thd4,
	]));
	set("no_drop","1");
	set("coor/x", 9010);
	set("coor/y", -3090);
	set("coor/z", 0);
	setup();
}

void init()
{
	object ob=this_player();

	if (ob->query_temp("step_count") > 99) {
		ob->delete_temp("step_count");
		write("���������۵þ�ƣ����������������֧�����˹�ȥ��\n");
		write("���Ժ������ƺ����˰���̧�����󣬷·��и����ϵ������ȵ������ӵ�����ȥ����\n");
		ob->unconcious();
		ob->move(__DIR__"shore", 1);
		message("vision", "��Ȼһ����ӿ�˹�������һ����ˮ�ݵð����ļһ�嵽�˰��ߡ�\n", environment(ob), ob);
		return;
	}
	ob->add_temp("step_count", 1);
	add_action("do_look", "look");
	add_action("do_look", "l");
}

int do_look(string arg)
{
	object me = this_player();
	if (arg == "east" || arg == "west" || arg == "south" || arg == "north")
	{
		write(HIC"�һ���"NOR" -
    ������һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢���
������Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С������в�����
����������������ȥ�ĺá�
    �������Եĳ����� east��north��south �� west��\n");
		return 1;
	}
	return 0;
}

