//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ������ɽ������ʱ�ɼ��������˱��Ű��������ŵ���������
ȥ����������೵������ĺۼ���
LONG );
	set("exits", ([
		"east"  : __DIR__"shandao1",
		"west"  : __DIR__"shandao3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangling");
	set("coor/x", -1500);
	set("coor/y", -2050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}