// Room: /d/lingxiao/qianyuan.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
	set("short","ǰԺ");
	set("long",@LONG 
�����������ǵ�ǰԺ���������Ӵ󶼾�ס�ڴ˺���������һ����
�˺�Χ�ֵ�ī÷��������ڣ���ζ�ҷ�������Ĵ�Ժ���ɽ����͸��
ī÷�Ļ������£���ѩ����ӳ��һ������ߡ�һֻѩ���������������裬
�ڰ���ӳ��������Ȥ�� 
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"huajing", 
		"south" : __DIR__"dadian",
		"north" : __DIR__"zhongting",
	]));
	set("objects", ([
		__DIR__"npc/xuehe" : 1,
		__DIR__"obj/ban" : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8880);
	set("coor/z", 140);
	setup();
}

void init()
{
	add_action("do_pick","pick");
}
int do_pick(string arg)
{
	object ob, me = this_player();

	if (!arg || arg!="hua" && arg!="flower")
		return notify_fail("��Ҫժʲô��\n");
	ob=new(__DIR__"obj/mei");
	ob->move(me);
	message_vision("$N��·�Ե�����ժ��һ��"+ob->query("name")+"��\n"NOR,me);
	return 1;
}

