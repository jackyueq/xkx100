// Room: /d/taishan/beitian.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����λ��ʯ��ɽ�ı�´����᷶��ı�����ڣ�·����һʯ��������
д�š����䡹���֡�
LONG );
	set("exits", ([
		"southdown" : __DIR__"zhangren",
	]));
	set("objects", ([
		CLASS_D("taishan")+"/yujizi" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 350);
	set("coor/y", 800);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
