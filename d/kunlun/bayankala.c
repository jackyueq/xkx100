// Room: /d/kunlun/bayankala.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "���տ���ɽ");
	set("long",@long
����տ���ɽɽ�Ƶ�ƽ����������ɽ��ڣ�����ͨ���֧��������
��������鲼����ɽ�ŷ�����ȥ���洦�ɼ�һ��������ݵ飬���Ƿ���
��������ĺõط���Զ��ɢ����һ����������ɹŰ���
long);
	set("exits",([
		"west"      : __DIR__"kekexili",
		"southdown" : __DIR__"shanlu2",
		"northwest" : __DIR__"hmszroad1",
	]));

	set("objects",([
		__DIR__"obj/da-shitou.c" :  1,
	]));

	set("outdoors", "kunlun");
	set("coor/x", -90000);
	set("coor/y", 10000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
