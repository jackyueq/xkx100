// /d/meizhuang/neitang.c
// Last Modified by winder on Apr. 10 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ƫ��"); 
	set("long", @LONG
����һ��û���κζ����ķ��ӣ��ıڿյ����ģ�������һ����޺�
�ģ���û�����ü�����װ�εķ��䣬���е�ǽ�ƺ���ʯ�ҽ���û��ͿĨ
�ã��������˼��Ų�֪��˭�Ļ��塣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"senlin1",
	]));

	set("no_clean_up", 0);
	set("item_desc", ([
		"wall": "һ����ǽ��\n"
	]) ); 
	set("coor/x", 3490);
	set("coor/y", -1400);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_push", "push");
}
int do_push(string arg)
{
	string dir;
	object me=this_player();

	if( !arg || arg=="" ) {write("������ʲô��\n");return 1;}

	if( arg=="wall" || arg=="ǽ" )
	{
		write("��ʹ������һ���Ƕ���ǽ��ǽ�ھ�Ȼ��Ȼ������\n");
		if((int)me->query_skill("force",1)>=100)
		{
			write("˳��ǽ�������ļз죬�������������ҡ�\n");
			me->move(__DIR__"mishi");
			return 1;
		}
		write("����������һ��ǽ�ڣ���ʲô��û�з�����\n");

		me->add("jing",-10);
		me->add("qi",-10);
		return 1;

	}
}
