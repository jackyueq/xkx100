// Room: /d/jueqinggu/hantan1.c
// Last Modified by winder on Feb. 17 2001
 
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��̶");
	set("long", @LONG
������ɭɭ�Ķ��������������̶ˮ�����˸е�͸�ǵĺ��䡣Զ��
��һ˿�����⡣
LONG
	);
	set("no_clean_up", 0);
	set("coor/x", -530);
	set("coor/y", -330);
	set("coor/z", -50);
	setup();
}
void init()
{
	add_action("do_fu", "fu");
	add_action("do_qian", "qian");
}
int do_fu(string arg)
{
	object me = this_player();

	if( !arg || arg == "" || arg !=  "up") return 0;
  
	message_vision("$Nһ�����٣�������ȥ��\n", me);
	me->move(__DIR__"gudi1");
	tell_room(environment(me),me->name()+"ʪ���ܵش�̶�����˳�����\n",({me}));
	return 1;
	
}
int do_qian(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "liang guang" && arg != "����") return 0;
	if ( !arg ) return 0;
	if (!living(me)) return 0;
	message_vision("$N�����������˹�ȥ��ԽǱԽ�������ʱ����������һ�죬�����ˮ�档\n", me);
	me->move(__DIR__"gudi2");
	tell_room(environment(me), me->name()+"��̶ˮ��ð�˳�����\n", ({ me }));
	return 1;
}
