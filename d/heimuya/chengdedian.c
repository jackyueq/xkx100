// Room: /d/heimuya/chengdedian.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short","�ɵµ�");
	set("long", @LONG
�����������̽���ƽ�շ���ʩ��ĵط��������޴�����ڵ�����
�λε����򣬴��˶˸���һ��������һ��Ӣ���������ˣ���������
���Ķ������ܵ��ͷ����ͤ�ˣ� 
LONG );
	set("valid_startroom", 1);
	set("exits",([
		"north" : __DIR__"houting",
		"westdown":__DIR__"up4",
	]));
	set("objects",([
		CLASS_D("heimuya")+"/first" : 1,
		__DIR__"npc/dizi" : 2,
		__DIR__"npc/yang" : 1,
	]));
	set("coor/x", -3250);
	set("coor/y", 4200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
	"/clone/board/riyue_b"->foo();
}