// /kaifeng/road5.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǻ�Ὺ�����Ҫ�ֵ���Ҳ�ǻ��ϳ�Ѳ��Ҫ�����ֵ����ߵ���
̨ͤ���ϣ�С����������������������������һ�ɷ������ϱߵĸ��ž�
�����ţ���������ͤ�¡�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west"    : __DIR__"tingyuan",
		"north"   : __DIR__"road6",
		"southup" : __DIR__"road4",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
