//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "��԰");
	set ("long", @LONG
������ҵĺ�԰��������ɸ�ӡ���ͷ��ʯ�ʡ�����֮�������һ
��С������һ����¯����¯�в�����֦��ȼ�˵����㡣��ǰ�и��˹���
�����ͷ����֪����ʲôԸ�ġ�
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west"  : __DIR__"ketang",
		"south" : __DIR__"citang",
	]));
	set("objects", ([
		__DIR__"npc/kongxincai"    : 1,
	]));
  
	set("coor/x", -1486);
	set("coor/y", 2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
