// Room: /d/suzhou/yanyutang.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ȫ԰��������ʱϵ԰����ʹ���������Ϊ���ŷ�������ȡ
�ڡ�ʫ��������ʽ���������ö����䡱���˴�����Ϊԧ������״���߳�
���������ڳ��踻�����¡�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"shizilin",
		"southeast" : __DIR__"zhenquting",
	]));
	set("objects", ([
		__DIR__"npc/lady3" : 2,
	]));
	set("coor/x", 870);
	set("coor/y", -1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
