// Room: /d/nanshaolin/yaowang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"ҩ��Ժ"NOR);
	set("long", @LONG
һ��ҩ��Ժ���˱Ƕ�������Ũ����ҩ�㡣������������װ������ҩ
�ĵĴ�ҩ��ÿ��ҩ�����ϰٸ�װҩ�ĳ��������˸���ҩ����������
һ���޴��ɼľ�񣬹������ŷ���ӡ�ķ�����һλ����ɮ��������æµ
��ָ����ִ��ɮ����ҩƷ����ҩ������
LONG );
	set("exits", ([
		"west" : __DIR__ "songshu1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangji" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

