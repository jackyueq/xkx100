// Room: /d/nanshaolin/bianhou.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�Һ�");
    set("long", @LONG
��������޺����Ҷ�֮�󣬺������ʲô�����������
LONG );
	set("objects",([
		BOOK_DIR+"yijinjing" : 1,   
	]));
	set("coor/x", 1800);
	set("coor/y", -6240);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_jump","jump");
}
int do_jump(string arg)
{
	object me,room;
	me=this_player();  
	if (arg!="down") return 0;
		message("vision",me->name()+"һ����������ȥ��\n",this_object());
	if(room=find_object(__DIR__"lhtang"))
		message("vision",me->name()+"���Ҷ������˹�����\n",room);
	me->move(__DIR__"lhtang");
	return 1;
}

