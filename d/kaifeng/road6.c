// /kaifeng/road6.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǻ�Ὺ�����Ҫ�ֵ���Ҳ�ǻ��ϳ�Ѳ��Ҫ�����ֵ����ߵ���
̨ͤ���ϣ�С����������������������������һ�ɷ���������һ���ߵ�
�������������Ŀ���������
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"jieyin",
		"south" : __DIR__"road5",
		"north" : __DIR__"xuandemen",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
