//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ������ɽ������ʱ�ɼ��������˱��Ű��������ŵ���������
ȥ����������೵������ĺۼ���������һ����ׯ��
LONG );
	set("exits", ([
		"east"  : __DIR__"shandao2",
		"north" : __DIR__"longzhong",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}