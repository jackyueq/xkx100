// Room: /d/kunlun/klshanlu.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����ɽ´");
	set("long",@long
��������ɽ��ѩɽ���࣬���Ӵ�����Զ�����أ���������Ʋʼ��
��ɫ������ÿ�괺���Ժ󣬱�ѩ�ڻ��������һ�ɹ��峺Ϫ�������볤
�����ƺӡ�
long);
	set("exits",([
		"northup" : __DIR__"shanmen",
		"east"    : __DIR__"shankou",
//		"west"    : "/d/fairyland/shanlu1",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -120000);
	set("coor/y", 30000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}