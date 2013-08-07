// Room: /d/jueqinggu/gudi1.c
// Last Modified by winder on Feb. 17 2001
 
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����ȵ�");
	set("long", @LONG
ֻ���չ����ˣ����ܻ���ïʢ����Զ����һ��̶��̶ˮ�峺��̶��
���ڻ��У�������һ�ڴ�֮�ס�
LONG
	);
	set("no_clean_up", 0);
	set("coor/x", -530);
	set("coor/y", -330);
	set("coor/z", 0);
	set("outdoors","jueqinggu");
	setup();
 
}
void init()
{
	add_action("do_pa", "pa");
	add_action("do_jump", "jump");
}
int do_pa(string arg)
{
	object me = this_player();

	if( !arg || arg == "" || arg !=  "up") return 0;
	if((int)(me->query_encumbrance()*100/me->query_max_encumbrance())>= 20) 
		return notify_fail("�����ϸ���̫�࣬������ȥ��\n");
 
	if((int)me->query_skill("dodge",1) < 100 )  
	return notify_fail("����Ŀǰ���Ṧ��Ϊ����������ȥ��\n"); 
	message_vision("$N��ס��ʯ��С�ĵ�������ȥ��\n", me);
	me->move(__DIR__"qiaobi");
	tell_room(environment(me), me->name() + "�ӹȵ�����������\n", ({ me }));
	return 1;
	
}
int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "tan di" && arg != "han tan" && arg != "��̶") return 0;
	if ( !arg ) return 0;
	if (!living(me)) return 0;
	message_vision("$N������̶���˽�ȥ��\n", me);
	me->move(__DIR__"hantan1");
	tell_room(environment(me), me->name() + "�Ӱ������˽�����\n", ({ me }));
	return 1;
}
