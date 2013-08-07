// Room: /d/kunlun/lianwuchang.c
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���䳡");
	set ("long", @long
���������䳡�������ɵĺܶ������������ϰ�书�������䳡��һ
�ǣ���һ��ר�����������÷��׮(zhuang)�������Ӷ�Χ��������ϰ
�ȹ���
long);
	set("exits",([
		"west" : __DIR__"huayuan1",
	]));
	set("item_desc", ([
		"zhuang" : "����һƬ÷��׮������ȥ������ϰ�ȹ�������������������(zhama)��\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119980);
	set("coor/y", 40080);
	set("coor/z", 90);
	setup();
}
int init()
{
	add_action("do_zhama","zhama");
}

int do_zhama(string arg)
{
	object me;
	me = this_player();
	if ( !living(this_player()) || arg != "zhuang" )
		return notify_fail("��Ҫ��������\n");
	if ((int)me->query_skill("leg", 1) > 100)
		return notify_fail("����ȹ��Ѿ��ܸ���,������ϰ����ûʲô���á�\n");
	if ( (int)me->query("qi")<30)
	{
		me->receive_damage("qi", 10);
		write("������Ѿ�����,��������Ϣһ��ɣ�\n");
		return 1;
	}
	me->receive_damage("qi", random(25));
	message_vision("$N����÷��׮����������\n", me);
	write("��ȫ���ע����÷��׮������һ����ʱ��������о������ȷ��ֽ���һ����\n");
	me->improve_skill("leg", me->query_int());
	return 1;
} 