// Room: /d/taishan/baozang.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������̩ɽ����һ����ʤ��������һ��״��ʨ�ӵľ�ʯ����Ϊʨ��
�¡�������Ļ���Ҫ���ڶ�����Ķ�����Ҳ���������ǹŴ�������
�ط���������һ�������ڵļ�̩ɽ����
LONG );
	set("exits", ([
		"northwest" : __DIR__"bixia",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 760);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
