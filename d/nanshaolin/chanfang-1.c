// Room: /d/nanshaolin/chanfang-1.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������о���������������һ��С��¯�����������̴���ɢ������
�������䷿�ڡ�����͸������������ʯ���ϣ����������γɸ���ҫ�۵�
���������еĵ���ɢ���ż������ţ����������ɮ������Ŀ���������ϡ�
LONG
	);
	set("exits", ([
		"north" : __DIR__"chanfang-2",
		"south" : __DIR__"chanfang-3",
		"east"  : __DIR__"zdyuan",
	]));
	set("objects", ([
		CLASS_D("nanshaolin") + "/dafeng" : 1,
	]));
	set("no_fight", 1);
	set("coor/x", 1790);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
//	replace_program(ROOM);
}
void init()
{
	  add_action("do_ask", "chanwu");
}
int do_ask()
{
	object me;
	me = this_player();
	if ((int)me->query("jing")<35)
	{
		write(RED"��̫���˾����޷����С�\n"NOR);
		return 1;
	} 
	if ((int)me->query_skill("buddhism",1)<50 &&
		present("moheseng dilu", me) )
	{
		write("���������Ϊ�������޷��ڴ���������\n");
		return 1;
	}
	if ((int)me->query_skill("buddhism",1)>101
		&& present("moheseng dilu", me) )    
	{
		write("����ʦ����˵����"+ RANK_D->query_respect(this_player()) +"�ķ�����ΪԨ��Ѳ�������ָ�㡣\n");
		return 1;
	}
	if ((int)me->query_skill("buddhism", 1) >= 50 &&
		(int)me->query_skill("buddhism", 1) <= 101 &&
		present("moheseng dilu", me) )
	{
		me->receive_damage("jing", 35);
		me->improve_skill("buddhism", me->query("int"));
		if ( random(5) == 0 )
			tell_object(me, RED"�����˴���ʦ��������Ľ��⣬��ʱ���������ķ�������ߡ�\n"NOR);
	}
	return 1;
} 
