// pingxinshi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "ƽ��ʯ");
	set("long", @LONG
�ٳ�Ͽ��ͷ����������������ϣ��м������ʯ��ǰ��һ����С�
����ʯ�����֡����˻�����ʯ�Ͽ��С�ƽ��ʯ�����֣�ʾ�������վ���
����ȥ���ѽ���ƽ��֮;�ˡ���ʱ��������һ�档
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"eastup"   : __DIR__"laojun",
		"westdown" : __DIR__"baichi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -880);
	set("coor/y", 230);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
