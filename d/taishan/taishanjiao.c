// Room: /d/taishan/taishanjiao.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "̩ɽ����");
	set("long", @LONG
̩ɽ�ų��ɽ��Ϊ�����Ķ�����Ϊ���̵ڶ�С���죬���С�������
��֮�������ԡ�̩ɽ�����ۡ��������ڡ������͵�������ڷ���ǰͥ
ң��ͤ�ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"yaocan",
		"south" : __DIR__"yidao3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
