// Room: /d/taishan/sihuaishu.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�Ļ���");
	set("long", @LONG
�ض������ȥ���йŻ��꣬�ߴ����ƣ�εȻ�д䣬��Ϊ�ƻ������
���ͽ��Ļ����������������ۣ����´��������������껱����������
���ٸġ�
LONG );
	set("exits", ([
		"northup"   : __DIR__"hutiange",
		"southdown" : __DIR__"baidong",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 640);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
