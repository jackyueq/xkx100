// Room: /d/taishan/chaoyang.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ����ȻʯѨ���Լ����ޣ���������ݣ��ϱ�����������ӭ
����������������߿�Ԫ���񡣶���ԭ��Ǭ¡פ��ͤ������Ԫ�����
���ϴ��������ɸ�ʯ����֮���Ͻ���������������������կ����
����Ȼ�Ӷ���ϵԪ����ʿ����Ȼ���洦��������Ϊ���ڣ��������ҡ�
LONG );
	set("exits", ([
		"southeast" : __DIR__"wudafu",
		"northup"   : __DIR__"duisong",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 690);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
