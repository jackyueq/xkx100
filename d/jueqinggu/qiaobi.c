// Room: /d/jueqinggu/qiaobi.c
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>;
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�ͱ�");
	set("long", @LONG
������һ���ƽ̹����ʯ��ֻ��һ�����������ұ���ģģ������
������(zi)���ƺ�������������ȥ�ģ��������Ϊʱ���Զ��ֻ����ǿ
�ϵá�������������������ȹȵס�
LONG
	);
	set("item_desc", ([
		"zi" : HIW "ʮ������ڴ���ᣬ���������ʧ��Լ��
С��Ů����������ɣ�������ǧ��������ۡ�\n"NOR,]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -530);
	set("coor/y", -330);
	set("coor/z", 50);
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

	if( !arg || arg == "" || (arg != "gudi" && arg != "�ȵ�") ) return 0;
	if((int)(me->query_encumbrance()*100/me->query_max_encumbrance())>=20)
		return notify_fail("�����ϸ���̫�࣬������ȥ��\n");
 
	if((int)me->query_skill("dodge",1) < 100 )  
	return notify_fail("����Ŀǰ���Ṧ��Ϊ����������ȥ��\n"); 
	message_vision("$N��ס��ʯ��С�ĵ�������ȥ��\n", me);
	me->move(__DIR__"gudi1");
	tell_room(environment(me), me->name() + "����������������\n", ({ me }));
	return 1;
	
}
int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "duanchang ya" && arg != "�ϳ���" && arg != "ya") return 0;
	if ( !arg ) return 0;
 
	
	if (!living(me)) return 0;
	if((int)(me->query_encumbrance()*100/me->query_max_encumbrance())>=20) 
	return notify_fail("�����ϸ���̫�࣬�޷�����ȥ��\n");
 
	if((int)me->query_skill("dodge",1) < 100 )  
		return notify_fail("����Ŀǰ���Ṧ��Ϊ���޷�����ȥ��\n"); 
	message_vision("$N����������Ķϳ�������ȥ��\n", me);
	me->move(__DIR__"duanchangya");
	tell_room(environment(me), me->name() + "���ͱ����˹�����\n", ({ me }));
	return 1;
}
