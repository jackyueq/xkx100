// Room: /d/kunlun/keting1.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�Ͳ���");
	set("long",@long
�����Ǵ��Ͳ���������򵥣�ֻ��һЩ���Ӻ����ӣ������ϰ���Щ
��͵��Ĺ�����ʳ�á����ٽ�����ʿ��Զǧ��������������ȵ�����
ЪϢƬ�̣��ָ�һ�¡�
long);
	set("exits",([
		"west" : __DIR__"elang02",
	]));
	set("objects",([
		__DIR__"obj/rice" : 2,
		__DIR__"obj/xiangcha" : 1,
	]));
	set("coor/x", -119960);
	set("coor/y", 40060);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}