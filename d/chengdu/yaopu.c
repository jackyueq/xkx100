// Room: yaodian.c
// Date: Feb.14 1998 by Java
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
������ҩ�����ܶ���ԭ�򲻵���ҩ�������ŵĸ�������һֱ���ܺá�
һ�߽����ҩ�꣬���ŵ�һ�ɹ�Ũ�Ҵ̱ǵ�ҩζ���������ҩ������
ô�����ܣ��Ϳ���ҩ���ﻹ��һЩ��������ֵ��۹⿴�㡣���ǵ�����
�Ĺ����ҵģ���Ȼ���Ǻ��ǵġ�
LONG	);
	set("objects", ([
		__DIR__"npc/huoji1" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"xijie1",
	]));
	set("coor/x", -8070);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
