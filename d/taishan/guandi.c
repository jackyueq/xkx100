// Room: /d/taishan/guandi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�ص���");
	set("long", @LONG
һ���ŷ�ǰ·���ǹص���������ʱ��������������ʱɽ����
�̳��ڴ˾ۻ���룬��񣬹�����ɽ����ݡ���Ժ�йŰ�һ�꣬ǽ
�����顰���ص�һ����
LONG );
	set("exits", ([
		"northeast" : __DIR__"yitian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 390);
	set("coor/y", 550);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
