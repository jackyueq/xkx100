// Room: /d/quanzhou/qianshouyan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ǧ����");
	set("long", @LONG
��ɽ·���ϣ�����ǧ���ҡ�����ÿ���ﶬ��ɽ��Ҷ����������ɷ
�Ǻÿ�������һ�£��ڹ���������һ����ǰ����ͦ�Σ��º��ʯ��ᾣ�
����һ�����¡����Ծ���������ɮ��һ��ʦ��Ĺͤ��Ĺͤ�ߵ���ʯ�Ͽ�
��������ʱд�ġ������������ĸ��֡�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"mituoyan",
		"northup"   : __DIR__"laojunyan",
	]));
	set("coor/x", 1820);
	set("coor/y", -6390);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
