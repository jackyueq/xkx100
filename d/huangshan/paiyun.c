// Room: /d/huangshan/paiyun.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "����ͤ");
	set("long", @LONG
�������Ƶ���Ѵ�����ɽ�ƺ�������֣������ϱ������캣������
�����ƶ�Ϊ��״���������ε��ˣ�����ͤ��Ϊ���ƶ�����Ҳ���ƶ�����
��������Ծ�����ɽ����֮�ƺ������
LONG
	);
	set("exits", ([ 
		"northup" : __DIR__"shizi",
		"south"   : __DIR__"feilai",
		"east"    : __DIR__"sanhua",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
