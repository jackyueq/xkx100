// Room: /d/taishan/dengxian.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ţ��׳ƶ������ӣ����������ұ��������ϱ�غ�ɳʯ������
ɳ�롣�ű������йŶ������������������ά�����顰Ъ���¡���
�ɴ����������ڴ�������ī��
LONG );
	set("exits", ([
		"south" : __DIR__"tianshen",
		"north" : __DIR__"baidong",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 620);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
