// /d/beihai/houmen.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǳ�����԰�ĺ��ţ����������ŵġ���ǰ��վ��������ʿ����
���߳���ïʢ��ֲ�һЩ�������Ŷ�����������������æµ��������
����һ���ٵ���
LONG
	);
	set("exits", ([
		"west"  : __DIR__"jingqing",
		"south" : __DIR__"huafang",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -160);
	set("coor/y", 4100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
