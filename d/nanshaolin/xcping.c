// Room: /d/nanshaolin/xcping.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
	set("short",HIG"����ƺ"NOR);
	set("long", @LONG
������һƬ�ּ�յأ����滷����ǧ������������������дкò�
ïʢ��������һ����������ʯ��������ʯ����Ϊ���࣬��������������
��֪ǰ��ɮ����������������������á�ʯƺ��ɨ����Ϊ�ྻ��ֻ����
�ֱ���һ��С��ʯ����Ϊ��Ŀ��������һ��ʯ���������������������֡�
һλ��ɮб����ʯ�����ƺ����ΰ��ѡ�
LONG );
	set("exits", ([
		"north" : __DIR__"xctang",
		"west"  : __DIR__"huilang8",
	]));
	set("outdoors", "nanshaolin");
	set("objects",([
		__DIR__"npc/zsseng1" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6100);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_huadi", "huadi");
}       
int do_huadi()
{
	object me = this_player();
	if (((int)me->query("max_neili",1)>1000) &&
		((int)me->query("neili",1)>500))
	{
		message("vision", "\nֻ��"+me->query("name")+"������·�Լ���һ���ʯ��\n����ʯ���ϻ�������������ʱ�㻭����һ���ݺ�ʮ�ŵ��Ĵ�Χ���̣�����\n��ƽ��ֱ���˵�������似��\n", environment(me), ({me}) );
		write("������ʯ���ϻ�����һ�������̡�\n");
		me->add("neili", -500);
		me->set_temp("huadi",1);
	}
	else
	{
		message("vision",me->query("name")+"ſ�ڵ��ϻ����ֶ����ˣ���ʯ�ʼ�Ӳ����һ���ƶ�û�С�\n", environment(me), ({me}) );
		write("�㻮�˰������������������޷������κ�ӡ�ǡ�\n");
	}    
	return 1;
}
int valid_leave(object me, string dir)
{
	if (dir == "north" && !me->query("pass_xin") &&
		objectp(present("zhishi seng", environment(me))))
		return notify_fail("ִ��ɮ������ס�㣬�����ò������롣\n");
	return ::valid_leave(me, dir);
}

