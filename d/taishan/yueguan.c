// Room: /d/taishan/yueguan.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�¹۷�");
	set("long", @LONG
�¹۷���λ�������������ɽ�룬���չ۷嶫�����Ŷ������˴���
ʯ�ܴأ���ߵĵط�һʯ׿������Ϊ���ӷ塣�����Կ��ڴ���Խ������
�ֳ�Խ�۷塣��������ʱ��ҹ��ɹۼ��ϸ�����ҵƻ��׳�����ɽ��
ɽ�����¹�ͤ�������߱���̩ɽ�������š�
LONG );
	set("exits", ([
		"east"    : __DIR__"nantian",
		"northup" : __DIR__"xitian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 350);
	set("coor/y", 770);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}

