// Room: /d/kunlun/jiashan.c
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��ɽ");
	set("long", @LONG
�����˾����Ⱦ͵��������ɫ��ɽ�εض���ɽ�忡�Σ�ɽ���
�أ�ɽ��Сͤ��ɽ�л���СԺ��ʯ�š�ʯ�ҵȣ����ư��硣Ϊ����ɽʯ
�����ټ���
LONG );
	set("exits",([
		"east"      : __DIR__"qishi",
		"west"      : __DIR__"houting",
		"southwest" : __DIR__"jiuqulang5",
		"northwest" : __DIR__"huayuan",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119980);
	set("coor/y", 40120);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}