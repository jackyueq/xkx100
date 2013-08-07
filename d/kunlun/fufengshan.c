// Room: /d/kunlun/fufengshan.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_climb();

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����ɽ������ʮ�ֶ��ͣ�ɽ�����Ͼ�û��ãã�ƺ��У��嶥�����
ѩ��ɽ������ȴ�������Բԣ���ľï�ܣ����Ž��أ�����������
LONG );
	set("outdoors", "kunlun");
	set("exits", ([
		"northeast" : __DIR__"bainiuling",
                "enter" : __DIR__"houyuan", 
	]));
/*	set("objects",([
		"/kungfu/class/kunlun/gaozecheng.c" :   1,
		"/kungfu/class/kunlun/jiangtao.c" :   1,
	]));
*/
	set("no_clean_up",0);
	create_door("enter", "С��", "out", DOOR_CLOSED);
	set("coor/x", -119980);
	set("coor/y", 40170);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}
int do_climb()
{
	object me= this_player();

	if( random((int)me->query_skill("dodge",1))<=30)
	{
		me->receive_damage("qi", 50);
		me->receive_wound("qi", 50);
		message_vision(HIR"$Nһ��С�Ľ���̤�˸���... ��...��\n"NOR, me);
		me->move(__DIR__"fufengshan.c");
		tell_object(me,
		HIR"���ɽ�Ϲ���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
		message("vision",HIR"ֻ��" + me->query("name") +
		"��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), ({me}));
		return 1;
	}
	message("vision",
	me->name() + "��һ������������������£�������ɽ�ϱ�ȥ��\n",
		environment(me), ({me}) );
	me->move(__DIR__"sanshengao");
	return 1;
}