// Room: /d/suzhou/erxianting.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����ͤ��ǧ��ʯ���࣬���ڱ��Ρ�ͤ��Ƕ����ʯ�����ֱ�������
�γ��������ƴ�������������ͤ����������ʯ�������������˵��ԭ
���Σ�Ԫ����Ԫ����Ԫ�����������������Լ����񳯻��������١���
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"qianrenshi",
		"north" : __DIR__"bailianchi",
	]));
	set("coor/x", 810);
	set("coor/y", -1020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
