// Room: /d/kunlun/shanlin1.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ɼ��");
	set("long",@long
����һƬ�����޾��Ĵ��̵����֣����ܵ���ɼ�����ľ�ɡ������
������֦Ѿ��ֻ©�°߰ߵ��ϸ�����Ӱ������ʮ���ľ�������ȸҲ��
������ֻż��������Զ���ļ���������
long);
	set("exits",([
		"west"  : __DIR__"shanlin2",
		"east"  : __DIR__"shanlin4",
		"south" : __DIR__"shanlin3",
		"north" : __DIR__"huayuan",
	]));
	set("objects",([
		__DIR__"obj/da-shugan" :  1,
		__DIR__"obj/xiao-shuzhi" :  1,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40140);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}