// Room: /d/shaolin/xiaojing2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�﹡��");
	set("long", @LONG
ת��ɽ��ֻ�����ù�ʵ���۵Ĵ�����������������﹡�ߣ���
������˺�������ӣ�ʹ���̲�ס��ժ�¼��ų������������Ű���
�������������������ª�����ݡ�
LONG );
	set("exits", ([
		"southdown" : __DIR__"xiaojing1",
		"west" : __DIR__"houshan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	set("coor/x", -20);
	set("coor/y", 710);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}