// Room: /d/taishan/bailuo.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "����ڣ");
	set("long", @LONG
���Ź�������Ϫ�����ǰ���ڣ���������ڵ�̩ɽʱ�˰��⣬�����
ɽ���ˣ�����������⡰���⽫��������������ʯΪڣ����ڣ�޴棬��
��ʯ������Ϊ����ڣ����
LONG );
	set("exits", ([
		"northwest" : __DIR__"mileyuan",
	]));
	set("resource/water",1);
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 420);
	set("coor/y", 540);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
