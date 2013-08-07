// Room: /d/jueqinggu/duanchangya.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ϳ���");
	set("long", @LONG
�����Ǿ���Ⱥ�ɽ�嶥���˼�������վ����ǰ��������ȣ�������
��ãã��
LONG
	);
	set("exits", ([
		"southdown" : __DIR__"shanlu3",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -540);
	set("coor/y", -330);
	set("coor/z", 50);
	setup();
 
}
void init()
{
	add_action("do_look", "look");
	add_action("do_jump", "jump");
}
int do_look(string arg)
{
	if( !arg || arg == "" || (arg !=  "ya" && arg!="��")) return 0;
	write("����ϸ�������ܡ������ڲ�Զ����һ��ͻ�������ͱڣ�������ǿ����\n");
	this_player()->set_temp("jqg_look1", 1);
	return 1;
	
}
int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "qiaobi" && arg != "�ͱ�" ) return 0;
	if (!arg ) return 0;
	if (!me->query_temp("jqg_look1"))
		return notify_fail("��Ҫ����������\n");
	
	if (!living(me)) return 0;
	if ((int)(me->query_encumbrance()*100/me->query_max_encumbrance())>=50)
		return notify_fail("�����ϸ���̫�࣬�޷�����ȥ��\n");
 
	if((int)me->query_skill("dodge",1) < 100 )  
		return notify_fail("����Ŀǰ���Ṧ��Ϊ���޷�����ȥ��\n"); 
	message_vision("$N������ǰ����ͱ����˹�ȥ��\n", me);
	me->move(__DIR__"qiaobi");
	tell_room(environment(me), me->name()+"�Ӷϳ������˹�����\n", ({ me }));
	me->delete_temp("jqg_look1");
	return 1;
}
