// Room: /d/wuxi/road14.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "�����");
	set("long", @LONG
����һ�������Ĵ��������������в�Զ��·�������ֳ�Ƭ����
��䣬����ϰϰ�������һ����ƥ�������ͷ����Ƭ�Ļҳ�����ò�
��ɢ����·�ϵ����˴����ɫ�Ҵҡ��򶫿���ԶԶ�ؿ��������ǵĳ�
ͷ�ˡ����������������µڶ�Ȫ����ɽȪ��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"   : __DIR__"road16",
		"east"   : __DIR__"kuaxiqiao",
		"north"  : __DIR__"huishanquan",
	]));
	set("coor/x", 260);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}